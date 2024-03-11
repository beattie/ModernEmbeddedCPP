/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2014 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

// Do not include on semihosting and when freestanding
#if !defined(OS_USE_SEMIHOSTING) && !(__STDC_HOSTED__ == 0)

// ----------------------------------------------------------------------------

#include <errno.h>
#include "diag/trace.h"
#include "uart.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"
// ----------------------------------------------------------------------------


ssize_t
_write(int fd, const char *buf, size_t nbyte);

ssize_t _write(int fd __attribute__((unused)),
		const char *buf __attribute__((unused)),
		size_t nbyte __attribute__((unused)))
{
#if defined(TRACE)
	// STDOUT and STDERR are routed to the trace device
	if (fd == 1 || fd == 2) {
		return trace_write(buf, nbyte);
	}
	if (fd == 0 || fd == 3) {
		uart2_write(buf, nbyte);
	}
#else
	if (fd <= 3) {
		uart2_write(buf, nbyte);
	}
#endif // TRACE

	errno = ENOSYS;
	return -1;
}

// ----------------------------------------------------------------------------
int _getc(int fd)
{
	return uart2_getc();
}

ssize_t _read(int fd, char *buf, size_t nbyte)
{
	return -1;
}
// ----------------------------------------------------------------------------
#pragma GCC diagnostic pop

#endif // !defined(OS_USE_SEMIHOSTING) && !(__STDC_HOSTED__ == 0)
