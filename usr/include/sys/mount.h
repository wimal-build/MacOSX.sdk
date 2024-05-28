/*
 * Copyright (c) 2000-2005 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * The contents of this file constitute Original Code as defined in and
 * are subject to the Apple Public Source License Version 1.1 (the
 * "License").  You may not use this file except in compliance with the
 * License.  Please obtain a copy of the License at
 * http://www.apple.com/publicsource and read it before using this file.
 * 
 * This Original Code and all software distributed under the License are
 * distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT.  Please see the
 * License for the specific language governing rights and limitations
 * under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
/* Copyright (c) 1995 NeXT Computer, Inc. All Rights Reserved */
/*
 * Copyright (c) 1989, 1991, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)mount.h	8.21 (Berkeley) 5/20/95
 */

#ifndef _SYS_MOUNT_H_
#define	_SYS_MOUNT_H_

#include <sys/appleapiopts.h>
#include <sys/cdefs.h>
#include <sys/attr.h>		/* needed for vol_capabilities_attr_t */

#include <stdint.h>
#include <sys/ucred.h>
#include <sys/queue.h>		/* XXX needed for user builds */

typedef struct fsid { int32_t val[2]; } fsid_t;	/* file system id type */

/*
 * file system statistics
 */

#define	MFSNAMELEN	15	/* length of fs type name, not inc. null */
#define	MNAMELEN	90	/* length of buffer for returned name */

/*
 * LP64 - WARNING - must be kept in sync with struct user_statfs in mount_internal.h.
 */
struct statfs {
	short	f_otype;		/* TEMPORARY SHADOW COPY OF f_type */
	short	f_oflags;		/* TEMPORARY SHADOW COPY OF f_flags */
	long	f_bsize;		/* fundamental file system block size */
	long	f_iosize;		/* optimal transfer block size */
	long	f_blocks;		/* total data blocks in file system */
	long	f_bfree;		/* free blocks in fs */
	long	f_bavail;		/* free blocks avail to non-superuser */
	long	f_files;		/* total file nodes in file system */
	long	f_ffree;		/* free file nodes in fs */
	fsid_t	f_fsid;			/* file system id */
	uid_t	f_owner;		/* user that mounted the filesystem */
	short	f_reserved1;	/* spare for later */
	short	f_type;			/* type of filesystem */
    long	f_flags;		/* copy of mount exported flags */
	long    f_reserved2[2];	/* reserved for future use */
	char	f_fstypename[MFSNAMELEN]; /* fs type name */
	char	f_mntonname[MNAMELEN];	/* directory on which mounted */
	char	f_mntfromname[MNAMELEN];/* mounted filesystem */
#if COMPAT_GETFSSTAT
	char	f_reserved3[0];	/* For alignment */
	long	f_reserved4[0];	/* For future use */
#else
	char	f_reserved3;	/* For alignment */
	long	f_reserved4[4];	/* For future use */
#endif
};


#define	MFSTYPENAMELEN	16	/* length of fs type name including null */

#if __DARWIN_ALIGN_POWER
#pragma options align=power
#endif

struct vfsstatfs {
	uint32_t	f_bsize;	/* fundamental file system block size */
	size_t		f_iosize;	/* optimal transfer block size */
	uint64_t	f_blocks;	/* total data blocks in file system */
	uint64_t	f_bfree;	/* free blocks in fs */
	uint64_t	f_bavail;	/* free blocks avail to non-superuser */
	uint64_t	f_bused;	/* free blocks avail to non-superuser */
	uint64_t	f_files;	/* total file nodes in file system */
	uint64_t	f_ffree;	/* free file nodes in fs */
	fsid_t		f_fsid;		/* file system id */
	uid_t		f_owner;	/* user that mounted the filesystem */
	uint64_t	f_flags;	/* copy of mount exported flags */ 
	char		f_fstypename[MFSTYPENAMELEN];/* fs type name inclus */
	char		f_mntonname[MAXPATHLEN];/* directory on which mounted */
	char		f_mntfromname[MAXPATHLEN];/* mounted filesystem */
	uint32_t	f_fssubtype;     /* fs sub-type (flavor) */
	void		*f_reserved[2];		/* For future use == 0 */
};

#if __DARWIN_ALIGN_POWER
#pragma options align=reset
#endif

#define VFSATTR_INIT(s)			((s)->f_supported = (s)->f_active = 0LL)
#define VFSATTR_SET_SUPPORTED(s, a)	((s)->f_supported |= VFSATTR_ ## a)
#define VFSATTR_IS_SUPPORTED(s, a)	((s)->f_supported & VFSATTR_ ## a)
#define VFSATTR_CLEAR_ACTIVE(s, a)	((s)->f_active &= ~VFSATTR_ ## a)
#define VFSATTR_IS_ACTIVE(s, a)		((s)->f_active & VFSATTR_ ## a)
#define VFSATTR_ALL_SUPPORTED(s)	(((s)->f_active & (s)->f_supported) == (s)->f_active)
#define VFSATTR_WANTED(s, a)		((s)->f_active |= VFSATTR_ ## a)
#define VFSATTR_RETURN(s, a, x)		do { (s)-> a = (x); VFSATTR_SET_SUPPORTED(s, a);} while(0)

#define VFSATTR_f_objcount		(1LL<<  0)
#define VFSATTR_f_filecount		(1LL<<  1)
#define VFSATTR_f_dircount		(1LL<<  2)
#define VFSATTR_f_maxobjcount		(1LL<<  3)
#define VFSATTR_f_bsize			(1LL<< 4)
#define VFSATTR_f_iosize		(1LL<<  5)
#define VFSATTR_f_blocks		(1LL<<  6)
#define VFSATTR_f_bfree			(1LL<<  7)
#define VFSATTR_f_bavail		(1LL<<  8)
#define VFSATTR_f_bused			(1LL<<  9)
#define VFSATTR_f_files			(1LL<< 10)
#define VFSATTR_f_ffree			(1LL<< 11)
#define VFSATTR_f_fsid			(1LL<< 12)
#define VFSATTR_f_owner			(1LL<< 13)
#define VFSATTR_f_capabilities		(1LL<< 14)
#define VFSATTR_f_attributes		(1LL<< 15)
#define VFSATTR_f_create_time		(1LL<< 16)
#define VFSATTR_f_modify_time		(1LL<< 17)
#define VFSATTR_f_access_time		(1LL<< 18)
#define VFSATTR_f_backup_time		(1LL<< 19)
#define VFSATTR_f_fssubtype		(1LL<< 20)
#define VFSATTR_f_vol_name		(1LL<< 21)
#define VFSATTR_f_signature		(1LL<< 22)
#define VFSATTR_f_carbon_fsid		(1LL<< 23)

/*
 * New VFS_STAT argument structure.
 */
#if __DARWIN_ALIGN_POWER
#pragma options align=power
#endif

struct vfs_attr {
	uint64_t	f_supported;
	uint64_t	f_active;

	uint64_t	f_objcount;	/* number of filesystem objects in volume */
	uint64_t	f_filecount;	/* ... files */
	uint64_t	f_dircount;	/* ... directories */
	uint64_t	f_maxobjcount;	/* maximum number of filesystem objects */
	
	uint32_t	f_bsize;	/* block size for the below size values */
	size_t		f_iosize;	/* optimal transfer block size */
	uint64_t	f_blocks;	/* total data blocks in file system */
	uint64_t	f_bfree;	/* free blocks in fs */
	uint64_t	f_bavail;	/* free blocks avail to non-superuser */
	uint64_t	f_bused;	/* blocks in use */
	uint64_t	f_files;	/* total file nodes in file system */
	uint64_t	f_ffree;	/* free file nodes in fs */
	fsid_t		f_fsid;		/* file system id */
	uid_t		f_owner;	/* user that mounted the filesystem */

 	vol_capabilities_attr_t f_capabilities;
	vol_attributes_attr_t f_attributes;

	struct timespec	f_create_time;	/* creation time */
	struct timespec	f_modify_time;	/* last modification time */
	struct timespec f_access_time;	/* time of last access */
	struct timespec	f_backup_time;	/* last backup time */

	uint32_t	f_fssubtype;	/* filesystem subtype */

	char		*f_vol_name;	/* volume name */

	uint16_t	f_signature;	/* used for ATTR_VOL_SIGNATURE, Carbon's FSVolumeInfo.signature */
	uint16_t	f_carbon_fsid;	/* same as Carbon's FSVolumeInfo.filesystemID */
};

#if __DARWIN_ALIGN_POWER
#pragma options align=reset
#endif

/*
 * User specifiable flags.
 *
 * Unmount uses MNT_FORCE flag.
 */
#define	MNT_RDONLY	0x00000001	/* read only filesystem */
#define	MNT_SYNCHRONOUS	0x00000002	/* file system written synchronously */
#define	MNT_NOEXEC	0x00000004	/* can't exec from filesystem */
#define	MNT_NOSUID	0x00000008	/* don't honor setuid bits on fs */
#define	MNT_NODEV	0x00000010	/* don't interpret special files */
#define	MNT_UNION	0x00000020	/* union with underlying filesystem */
#define	MNT_ASYNC	0x00000040	/* file system written asynchronously */
#define MNT_DONTBROWSE	0x00100000	/* file system is not appropriate path to user data */
#define MNT_IGNORE_OWNERSHIP 0x00200000 /* VFS will ignore ownership information on filesystem
					 * objects */
#define MNT_AUTOMOUNTED 0x00400000	/* filesystem was mounted by automounter */
#define MNT_JOURNALED   0x00800000  /* filesystem is journaled */
#define MNT_NOUSERXATTR	0x01000000	/* Don't allow user extended attributes */
#define MNT_DEFWRITE	0x02000000	/* filesystem should defer writes */

/* backwards compatibility only */
#define MNT_UNKNOWNPERMISSIONS MNT_IGNORE_OWNERSHIP

/*
 * NFS export related mount flags.
 */
#define	MNT_EXPORTED	0x00000100	/* file system is exported */

/*
 * Flags set by internal operations.
 */
#define	MNT_LOCAL	0x00001000	/* filesystem is stored locally */
#define	MNT_QUOTA	0x00002000	/* quotas are enabled on filesystem */
#define	MNT_ROOTFS	0x00004000	/* identifies the root filesystem */
#define	MNT_DOVOLFS	0x00008000	/* FS supports volfs */

/*
 * XXX I think that this could now become (~(MNT_CMDFLAGS))
 * but the 'mount' program may need changing to handle this.
 */
#define	MNT_VISFLAGMASK	(MNT_RDONLY	| MNT_SYNCHRONOUS | MNT_NOEXEC	| \
			MNT_NOSUID	| MNT_NODEV	| MNT_UNION	| \
			MNT_ASYNC	| MNT_EXPORTED	| \
			MNT_LOCAL	|		MNT_QUOTA	| \
			MNT_ROOTFS	| MNT_DOVOLFS	| MNT_DONTBROWSE | \
			MNT_UNKNOWNPERMISSIONS | MNT_AUTOMOUNTED | MNT_JOURNALED | \
			MNT_DEFWRITE)
/*
 * External filesystem command modifier flags.
 * Unmount can use the MNT_FORCE flag.
 * XXX These are not STATES and really should be somewhere else.
 * External filesystem control flags.
 */
#define	MNT_UPDATE	0x00010000	/* not a real mount, just an update */
#define	MNT_RELOAD	0x00040000	/* reload filesystem data */
#define	MNT_FORCE	0x00080000	/* force unmount or readonly change */
#define MNT_CMDFLAGS	(MNT_UPDATE|MNT_RELOAD|MNT_FORCE)



/*
 * Sysctl CTL_VFS definitions.
 *
 * Second level identifier specifies which filesystem. Second level
 * identifier VFS_GENERIC returns information about all filesystems.
 */
#define	VFS_GENERIC		0	/* generic filesystem information */
#define VFS_NUMMNTOPS		1	/* int: total num of vfs mount/unmount operations */
/*
 * Third level identifiers for VFS_GENERIC are given below; third
 * level identifiers for specific filesystems are given in their
 * mount specific header files.
 */
#define VFS_MAXTYPENUM	1	/* int: highest defined filesystem type */
#define VFS_CONF	2	/* struct: vfsconf for filesystem given
				   as next argument */
#define VFS_SET_PACKAGE_EXTS 3	/* set package extension list */

/*
 * Flags for various system call interfaces.
 *
 * waitfor flags to vfs_sync() and getfsstat()
 */
#define MNT_WAIT	1	/* synchronously wait for I/O to complete */
#define MNT_NOWAIT	2	/* start all I/O, but do not wait for it */


struct mount;
typedef struct mount * mount_t;
struct vnode;
typedef struct vnode * vnode_t;

struct vfsconf {
	struct	vfsops *vfc_vfsops;	/* filesystem operations vector */
	char	vfc_name[MFSNAMELEN];	/* filesystem type name */
	int	vfc_typenum;		/* historic filesystem type number */
	int	vfc_refcount;		/* number mounted of this type */
	int	vfc_flags;		/* permanent flags */
	int	(*vfc_mountroot)(mount_t, vnode_t);	/* if != NULL, routine to mount root */
	struct	vfsconf *vfc_next;	/* next in list */
};

struct vfsidctl {
	int		vc_vers;	/* should be VFSIDCTL_VERS1 (below) */
	fsid_t		vc_fsid;	/* fsid to operate on. */
	void		*vc_ptr;	/* pointer to data structure. */
	size_t		vc_len;		/* sizeof said structure. */
	u_int32_t	vc_spare[12];	/* spare (must be zero). */
};


/* vfsidctl API version. */
#define VFS_CTL_VERS1	0x01


/*
 * New style VFS sysctls, do not reuse/conflict with the namespace for
 * private sysctls.
 */
#define VFS_CTL_STATFS	0x00010001	/* statfs */
#define VFS_CTL_UMOUNT	0x00010002	/* unmount */
#define VFS_CTL_QUERY	0x00010003	/* anything wrong? (vfsquery) */
#define VFS_CTL_NEWADDR	0x00010004	/* reconnect to new address */
#define VFS_CTL_TIMEO	0x00010005	/* set timeout for vfs notification */
#define VFS_CTL_NOLOCKS	0x00010006	/* disable file locking */

struct vfsquery {
	u_int32_t	vq_flags;
	u_int32_t	vq_spare[31];
};

/* vfsquery flags */
#define VQ_NOTRESP	0x0001	/* server down */
#define VQ_NEEDAUTH	0x0002	/* server bad auth */
#define VQ_LOWDISK	0x0004	/* we're low on space */
#define VQ_MOUNT	0x0008	/* new filesystem arrived */
#define VQ_UNMOUNT	0x0010	/* filesystem has left */
#define VQ_DEAD		0x0020	/* filesystem is dead, needs force unmount */
#define VQ_ASSIST	0x0040	/* filesystem needs assistance from external program */
#define VQ_NOTRESPLOCK	0x0080	/* server lockd down */
#define VQ_UPDATE	0x0100	/* filesystem information has changed */
#define VQ_FLAG0200	0x0200	/* placeholder */
#define VQ_FLAG0400	0x0400	/* placeholder */
#define VQ_FLAG0800	0x0800	/* placeholder */
#define VQ_FLAG1000	0x1000	/* placeholder */
#define VQ_FLAG2000	0x2000	/* placeholder */
#define VQ_FLAG4000	0x4000	/* placeholder */
#define VQ_FLAG8000	0x8000	/* placeholder */




/*
 * Generic file handle
 */
#define	NFS_MAX_FH_SIZE		64
#define	NFSV2_MAX_FH_SIZE	32
struct fhandle {
	int		fh_len;				/* length of file handle */
	unsigned char	fh_data[NFS_MAX_FH_SIZE];	/* file handle value */
};
typedef struct fhandle	fhandle_t;


__BEGIN_DECLS
int	fhopen(const struct fhandle *, int);
int	fstatfs(int, struct statfs *);
int	getfh(const char *, fhandle_t *);
int	getfsstat(struct statfs *, int, int);
int	getmntinfo(struct statfs **, int);
int	mount(const char *, const char *, int, void *);
int	statfs(const char *, struct statfs *);
int	unmount(const char *, int);
int	getvfsbyname(const char *, struct vfsconf *);
__END_DECLS

#endif /* !_SYS_MOUNT_H_ */
