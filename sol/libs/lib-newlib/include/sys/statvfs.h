/* SPDX-License-Identifier: MIT */
/* ----------------------------------------------------------------------
 * Copyright © 2005-2014 Rich Felker, et al.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 * ----------------------------------------------------------------------
 */
/* Taken from musl */

#ifndef _SYS_STATVFS_H
#define _SYS_STATVFS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <endian.h>
#include <sys/_types.h>

#ifndef _FSBLKCNT_T_DECLARED
typedef __fsblkcnt_t fsblkcnt_t;
#define _FSBLKCNT_T_DECLARED
#endif

#ifndef _FSFILCNT_T_DECLARED
typedef __fsfilcnt_t fsfilcnt_t;
#define _FSFILCNT_T_DECLARED
#endif

struct statvfs {
	unsigned long f_bsize, f_frsize;
	fsblkcnt_t f_blocks, f_bfree, f_bavail;
	fsfilcnt_t f_files, f_ffree, f_favail;
#if __BYTE_ORDER == __LITTLE_ENDIAN
	unsigned long f_fsid;
	unsigned:8*(2*sizeof(int)-sizeof(long));
#else
	unsigned:8*(2*sizeof(int)-sizeof(long));
	unsigned long f_fsid;
#endif
	unsigned long f_flag, f_namemax;
	int __reserved[6];
};

int statvfs(const char *__restrict__ path, struct statvfs *__restrict__ buf);
int fstatvfs(int fd, struct statvfs *buf);

#define ST_RDONLY      1
#define ST_NOSUID      2
#define ST_NODEV       4
#define ST_NOEXEC      8
#define ST_SYNCHRONOUS 16
#define ST_MANDLOCK    64
#define ST_WRITE       128
#define ST_APPEND      256
#define ST_IMMUTABLE   512
#define ST_NOATIME     1024
#define ST_NODIRATIME  2048

#if defined(_LARGEFILE64_SOURCE) || defined(_GNU_SOURCE)
#define statvfs64 statvfs
#define fstatvfs64 fstatvfs
#define fsblkcnt64_t fsblkcnt_t
#define fsfilcnt64_t fsfilcnt_t
#endif

#ifdef __cplusplus
}
#endif

#endif
