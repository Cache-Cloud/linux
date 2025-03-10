/* SPDX-License-Identifier: GPL-2.0 */
/*
 *	include/linux/vt_buffer.h -- Access to VT screen buffer
 *
 *	(c) 1998 Martin Mares <mj@ucw.cz>
 *
 *	This is a set of macros and functions which are used in the
 *	console driver and related code to access the screen buffer.
 *	In most cases the console works with simple in-memory buffer,
 *	but when handling hardware text mode consoles, we store
 *	the foreground console directly in video memory.
 */

#ifndef _LINUX_VT_BUFFER_H_
#define _LINUX_VT_BUFFER_H_

#include <linux/string.h>

#if IS_ENABLED(CONFIG_VGA_CONSOLE) || IS_ENABLED(CONFIG_MDA_CONSOLE)
#include <asm/vga.h>
#endif

#ifndef VT_BUF_HAVE_RW
#define scr_writew(val, addr) (*(addr) = (val))
#define scr_readw(addr) (*(addr))
#endif

#ifndef VT_BUF_HAVE_MEMSETW
static inline void scr_memsetw(u16 *s, u16 c, unsigned int count)
{
	memset16(s, c, count / 2);
}
#endif

#ifndef VT_BUF_HAVE_MEMCPYW
static inline void scr_memcpyw(u16 *d, const u16 *s, unsigned int count)
{
	memcpy(d, s, count);
}
#endif

#ifndef VT_BUF_HAVE_MEMMOVEW
static inline void scr_memmovew(u16 *d, const u16 *s, unsigned int count)
{
	memmove(d, s, count);
}
#endif

#endif
