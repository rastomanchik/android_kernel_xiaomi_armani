#
# Makefile for the Linux filesystems.
#
# 14 Sep 2000, Christoph Hellwig <hch@infradead.org>
# Rewritten to use lists instead of if-statements.
#

obj-y :=	open.o read_write.o file_table.o super.o \
		char_dev.o stat.o exec.o pipe.o namei.o fcntl.o \
		ioctl.o readdir.o select.o fifo.o dcache.o inode.o \
		attr.o bad_inode.o file.o filesystems.o namespace.o \
		seq_file.o xattr.o libfs.o fs-writeback.o \
		pnode.o drop_caches.o splice.o sync.o utimes.o \
		stack.o fs_struct.o statfs.o

ifeq ($(CONFIG_BLOCK),y)
obj-y +=	buffer.o bio.o block_dev.o direct-io.o mpage.o ioprio.o
else
obj-y +=	no-block.o
endif

obj-$(CONFIG_PROC_FS)       += proc_namespace.o

obj-y				        += notify/
obj-$(CONFIG_EPOLL)		    += eventpoll.o
obj-$(CONFIG_ANON_INODES)	+= anon_inodes.o
obj-$(CONFIG_SIGNALFD)		+= signalfd.o
obj-$(CONFIG_TIMERFD)		+= timerfd.o
obj-$(CONFIG_EVENTFD)		+= eventfd.o
obj-$(CONFIG_AIO)           += aio.o
obj-$(CONFIG_FS_ENCRYPTION) += crypto/
obj-$(CONFIG_FILE_LOCKING)  += locks.o
obj-$(CONFIG_COMPAT)		+= compat.o compat_ioctl.o
obj-$(CONFIG_BINFMT_AOUT)	+= binfmt_aout.o
obj-$(CONFIG_BINFMT_EM86)	+= binfmt_em86.o
obj-$(CONFIG_BINFMT_MISC)	+= binfmt_misc.o

# binfmt_script is always there
obj-y				        += binfmt_script.o

obj-$(CONFIG_BINFMT_ELF)	+= binfmt_elf.o
obj-$(CONFIG_COMPAT_BINFMT_ELF)	+= compat_binfmt_elf.o
obj-$(CONFIG_BINFMT_ELF_FDPIC)	+= binfmt_elf_fdpic.o
obj-$(CONFIG_BINFMT_SOM)	+= binfmt_som.o
obj-$(CONFIG_BINFMT_FLAT)	+= binfmt_flat.o

obj-$(CONFIG_FS_MBCACHE)	+= mbcache.o
obj-$(CONFIG_FS_POSIX_ACL)	+= posix_acl.o xattr_acl.o
obj-$(CONFIG_GENERIC_ACL)	+= generic_acl.o

obj-$(CONFIG_FHANDLE)		+= fhandle.o

obj-y				        += quota/

obj-$(CONFIG_PROC_FS)		+= proc/
obj-$(CONFIG_SYSFS)		    += sysfs/
obj-$(CONFIG_CONFIGFS_FS)	+= configfs/
obj-y				        += devpts/

obj-$(CONFIG_PROFILING)		+= dcookies.o

# We place ext4 after ext2 so plain ext2 root fs's are mounted using ext2
# unless explicitly requested by rootfstype
obj-$(CONFIG_EXT4_FS)		+= ext4/
obj-$(CONFIG_JBD2)		    += jbd2/
obj-y				        += ramfs/
obj-$(CONFIG_FAT_FS)		+= fat/
obj-$(CONFIG_ECRYPT_FS)		+= ecryptfs/
obj-$(CONFIG_SDCARD_FS)		+= sdcardfs/
obj-$(CONFIG_NLS)		    += nls/
obj-$(CONFIG_SYSV_FS)		+= sysv/
obj-$(CONFIG_CIFS)		    += cifs/
obj-$(CONFIG_HPFS_FS)		+= hpfs/
obj-$(CONFIG_NTFS_FS)		+= ntfs/
obj-$(CONFIG_EFS_FS)		+= efs/
obj-$(CONFIG_JFFS2_FS)		+= jffs2/
obj-$(CONFIG_LOGFS)		    += logfs/
obj-$(CONFIG_ROMFS_FS)		+= romfs/
obj-$(CONFIG_QNX4FS_FS)		+= qnx4/
obj-$(CONFIG_QNX6FS_FS)		+= qnx6/
obj-$(CONFIG_ADFS_FS)		+= adfs/
obj-$(CONFIG_FUSE_FS)		+= fuse/
obj-$(CONFIG_UDF_FS)		+= udf/
obj-$(CONFIG_JFS_FS)		+= jfs/
obj-$(CONFIG_XFS_FS)		+= xfs/
obj-$(CONFIG_AFS_FS)		+= afs/
obj-$(CONFIG_NILFS2_FS)		+= nilfs2/
obj-$(CONFIG_BEFS_FS)		+= befs/
obj-$(CONFIG_HOSTFS)		+= hostfs/
obj-$(CONFIG_HPPFS)		    += hppfs/
obj-$(CONFIG_CACHEFILES)	+= cachefiles/
obj-$(CONFIG_DEBUG_FS)		+= debugfs/
obj-$(CONFIG_BTRFS_FS)		+= btrfs/
obj-$(CONFIG_GFS2_FS)       += gfs2/
obj-$(CONFIG_F2FS_FS)		+= f2fs/
obj-y				+= exofs/ # Multiple modules
obj-$(CONFIG_PSTORE)		+= pstore/
