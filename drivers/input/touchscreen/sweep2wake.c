/*
 * drivers/input/touchscreen/sweep2wake.c
 *
 *
 * Copyright (c) 2013, Dennis Rassmann <showp1984@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/delay.h>
#include <linux/init.h>
#include <linux/err.h>
#include <linux/input/sweep2wake.h>
#include <linux/slab.h>
#include <linux/workqueue.h>
#include <linux/input.h>
#include <linux/hrtimer.h>

/* uncomment since no touchscreen defines android touch, do that here */
//#define ANDROID_TOUCH_DECLARED

/* Version, author, desc, etc */
#define DRIVER_AUTHOR "Dennis Rassmann <showp1984@gmail.com>"
#define DRIVER_DESCRIPTION "Sweep2wake for almost any device"
#define DRIVER_VERSION "1.5"
#define LOGTAG "[sweep2wake]: "

MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESCRIPTION);
MODULE_VERSION(DRIVER_VERSION);
MODULE_LICENSE("GPLv2");

/* Tuneables */
#define S2W_DEFAULT		1
#define S2W_PWRKEY_DUR          60

/* defaults */
#define S2W_Y_MAX               1280
#define S2W_X_MAX               800
#define S2W_X_B1                200
#define S2W_X_B2                600
#define S2W_X_FINAL             300


/* Resources */
int s2w_switch = S2W_DEFAULT;
static int touch_x = 0, touch_y = 0;
static bool touch_x_called = false, touch_y_called = false;
static bool exec_count = true;
static bool barrier[2] = {false, false};
static struct input_dev * sweep2wake_pwrdev;
static DEFINE_MUTEX(pwrkeyworklock);
static struct workqueue_struct *s2w_input_wq;
static struct work_struct s2w_input_work;

/* Read cmdline for s2w */
static int __init read_s2w_cmdline(char *s2w)
{
	if (strcmp(s2w, "1") == 0) {
		pr_info("[cmdline_s2w]: Sweep2Wake enabled. | s2w='%s'\n", s2w);
		s2w_switch = 1;
	} else if (strcmp(s2w, "0") == 0) {
		pr_info("[cmdline_s2w]: Sweep2Wake disabled. | s2w='%s'\n", s2w);
		s2w_switch = 0;
	} else {
		pr_info("[cmdline_s2w]: No valid input found. Going with default: | s2w='%u'\n", s2w_switch);
	}
	return 1;
}
__setup("s2w=", read_s2w_cmdline);

/* PowerKey work func */
static void sweep2wake_presspwr(struct work_struct * sweep2wake_presspwr_work) {
    mutex_lock(&pwrkeyworklock);
	input_event(sweep2wake_pwrdev, EV_KEY, KEY_POWER, 1);
	input_event(sweep2wake_pwrdev, EV_SYN, 0, 0);
	msleep(S2W_PWRKEY_DUR);
	input_event(sweep2wake_pwrdev, EV_KEY, KEY_POWER, 0);
	input_event(sweep2wake_pwrdev, EV_SYN, 0, 0);
	msleep(S2W_PWRKEY_DUR);
    mutex_unlock(&pwrkeyworklock);
}
static DECLARE_WORK(sweep2wake_presspwr_work, sweep2wake_presspwr);

/* PowerKey trigger */
static void sweep2wake_pwrtrigger(void) {
	schedule_work(&sweep2wake_presspwr_work);
}

/* reset on finger release */
static void sweep2wake_reset(void) {
	exec_count = true;
	barrier[0] = false;
	barrier[1] = false;
}

/* Sweep2wake main function */
static void detect_sweep2wake(int x, int y, bool st)
{
    int prevx = 0, nextx = 0;

    pr_info(LOGTAG"TEST1\n");

	//left->right
	if (s2w_switch > 0) {
		prevx = 0;
		nextx = S2W_X_B1;
		if ((barrier[0] == true) ||
		   ((x > prevx) &&
		    (x < nextx) &&
		    (y > 0))) {
			prevx = nextx;
			nextx = S2W_X_B2;
			barrier[0] = true;
			if ((barrier[1] == true) ||
			   ((x > prevx) &&
			    (x < nextx) &&
			    (y > 0))) {
				prevx = nextx;
				barrier[1] = true;
				if ((x > prevx) &&
				    (y > 0)) {
					if (x > (S2W_X_MAX - S2W_X_FINAL)) {
						if (exec_count) {
							pr_info(LOGTAG"ON\n");
							sweep2wake_pwrtrigger();
							exec_count = false;
						}
					}
				}
			}
		}
    pr_info(LOGTAG"TEST2\n");
	//right->left
	} else if (s2w_switch > 0) {
		prevx = (S2W_X_MAX - S2W_X_FINAL);
		nextx = S2W_X_B2;
		if ((barrier[0] == true) ||
		   ((x < prevx) &&
		    (x > nextx))) {
			prevx = nextx;
			nextx = S2W_X_B1;
			barrier[0] = true;
			if ((barrier[1] == true) ||
			   ((x < prevx) &&
			    (x > nextx))) {
				prevx = nextx;
				barrier[1] = true;
				if (x < prevx) {
					if (x < S2W_X_FINAL) {
						if (exec_count) {
							pr_info(LOGTAG"OFF\n");
							sweep2wake_pwrtrigger();
							exec_count = false;
						}
					}
				}
			}
		}
	}
}

static void s2w_input_callback(struct work_struct *unused) {

	detect_sweep2wake(touch_x, touch_y, true);

	return;
}

static void s2w_input_event(struct input_handle *handle, unsigned int type,
				unsigned int code, int value) {
	if (code == ABS_MT_SLOT) {
		sweep2wake_reset();
		return;
	}

	if ((code == ABS_MT_TRACKING_ID && value == -1) || (code == 2 && value == 0)) {
		sweep2wake_reset();
		return;
	}

	if (code == ABS_MT_POSITION_X) {
		touch_x = value;
		touch_x_called = true;
	}

	if (code == ABS_MT_POSITION_Y) {
		touch_y = value;
		touch_y_called = true;
	}

	if (touch_x_called && touch_y_called) {
		touch_x_called = false;
		touch_y_called = false;
		queue_work_on(0, s2w_input_wq, &s2w_input_work);
	}
}

static int s2w_input_connect(struct input_handler *handler,
				struct input_dev *dev, const struct input_device_id *id) {
	struct input_handle *handle;
	int error;

	handle = kzalloc(sizeof(struct input_handle), GFP_KERNEL);
	if (!handle)
		return -ENOMEM;

	handle->dev = dev;
	handle->handler = handler;
	handle->name = "s2w";

	error = input_register_handle(handle);
	if (error)
		goto err2;

	error = input_open_device(handle);
	if (error)
		goto err1;

	return 0;
err1:
	input_unregister_handle(handle);
err2:
	kfree(handle);
	return error;
}

static void s2w_input_disconnect(struct input_handle *handle) {
	input_close_device(handle);
	input_unregister_handle(handle);
	kfree(handle);
}

static const struct input_device_id s2w_ids[] = {
	{ .driver_info = 1 },
	{ },
};

static struct input_handler s2w_input_handler = {
	.event		= s2w_input_event,
	.connect	= s2w_input_connect,
	.disconnect	= s2w_input_disconnect,
	.name		= "s2w_inputreq",
	.id_table	= s2w_ids,
};

/*
 * SYSFS stuff below here
 */
static ssize_t s2w_sweep2wake_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	size_t count = 0;

	count += sprintf(buf, "%d\n", s2w_switch);

	return count;
}

static ssize_t s2w_sweep2wake_dump(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count)
{
	if (buf[0] >= '0' && buf[0] <= '1' && buf[1] == '\n')
                if (s2w_switch != buf[0] - '0')
		        s2w_switch = buf[0] - '0';

	return count;
}

static DEVICE_ATTR(sweep2wake, (S_IWUSR|S_IRUGO),
	s2w_sweep2wake_show, s2w_sweep2wake_dump);

static ssize_t s2w_version_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	size_t count = 0;

	count += sprintf(buf, "%s\n", DRIVER_VERSION);

	return count;
}

static ssize_t s2w_version_dump(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count)
{
	return count;
}

static DEVICE_ATTR(sweep2wake_version, (S_IWUSR|S_IRUGO),
	s2w_version_show, s2w_version_dump);

/*
 * INIT / EXIT stuff below here
 */
#ifdef ANDROID_TOUCH_DECLARED
extern struct kobject *android_touch_kobj;
#else
struct kobject *android_touch_kobj;
EXPORT_SYMBOL_GPL(android_touch_kobj);
#endif
static int __init sweep2wake_init(void)
{
	int rc = 0;

	sweep2wake_pwrdev = input_allocate_device();
	if (!sweep2wake_pwrdev) {
		pr_err("Can't allocate suspend autotest power button\n");
		goto err_alloc_dev;
	}

	input_set_capability(sweep2wake_pwrdev, EV_KEY, KEY_POWER);
	sweep2wake_pwrdev->name = "s2w_pwrkey";
	sweep2wake_pwrdev->phys = "s2w_pwrkey/input0";

	rc = input_register_device(sweep2wake_pwrdev);
	if (rc) {
		pr_err("%s: input_register_device err=%d\n", __func__, rc);
		goto err_input_dev;
	}

	s2w_input_wq = create_workqueue("s2wiwq");
	if (!s2w_input_wq) {
		pr_err("%s: Failed to create s2wiwq workqueue\n", __func__);
		return -EFAULT;
	}
	INIT_WORK(&s2w_input_work, s2w_input_callback);
	rc = input_register_handler(&s2w_input_handler);
	if (rc)
		pr_err("%s: Failed to register s2w_input_handler\n", __func__);

#ifndef ANDROID_TOUCH_DECLARED
	android_touch_kobj = kobject_create_and_add("android_touch", NULL) ;
	if (android_touch_kobj == NULL) {
		pr_warn("%s: android_touch_kobj create_and_add failed\n", __func__);
	}
#endif
	rc = sysfs_create_file(android_touch_kobj, &dev_attr_sweep2wake.attr);
	if (rc) {
		pr_warn("%s: sysfs_create_file failed for sweep2wake\n", __func__);
	}
	rc = sysfs_create_file(android_touch_kobj, &dev_attr_sweep2wake_version.attr);
	if (rc) {
		pr_warn("%s: sysfs_create_file failed for sweep2wake_version\n", __func__);
	}

err_input_dev:
	input_free_device(sweep2wake_pwrdev);
err_alloc_dev:
	pr_info(LOGTAG"%s done\n", __func__);

	return 0;
}

static void __exit sweep2wake_exit(void)
{
#ifndef ANDROID_TOUCH_DECLARED
	kobject_del(android_touch_kobj);
#endif
	input_unregister_handler(&s2w_input_handler);
	destroy_workqueue(s2w_input_wq);
	input_unregister_device(sweep2wake_pwrdev);
	input_free_device(sweep2wake_pwrdev);
	return;
}

module_init(sweep2wake_init);
module_exit(sweep2wake_exit);