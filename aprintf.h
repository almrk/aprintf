/*===============================================================================
 *
 * aprintf.h - An independent printf implementation for C.
 * 
 * LICENSE : MIT License
 *
 * Copyright (c) 2025 almrk
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *===============================================================================*/

#ifndef APRINTF_H
#define APRINTF_H

#include <stdarg.h>

/* aprintf defenition
 */
void aprintf(const char* fmt, ...);

/* aprintf implementation
 */
#ifdef APRINTF_IMPLEMENTATION

/* The only function used from stdio is putchar to make the code more cross platform
 */
#include <stdio.h>

static unsigned long aprintf_ultoa(unsigned long n, char* buffer, unsigned long bufferSize) {
    unsigned long i;
    /* Convert the unsigned long to an ASCII string 
     */
    for (i = 0; i < bufferSize && n != 0; i++) {
        buffer[i] = '0' + (n % 10);
        n /= 10;
    }
    /* Return the number of digits converted
     */
    return i;
}

static unsigned long aprintf_ltoa(long n, char* buffer, unsigned long bufferSize) {
    unsigned long nd = 0;
    /* Convert the integer using the unsigned long to ASCII function
     */
    if (n < 0) {
        nd = aprintf_ultoa(n * -1, buffer, bufferSize);
        /* Add the '-' to the end
         */
        if (nd < bufferSize)
            buffer[nd] = '-';
    } else {
        nd = aprintf_ultoa(n, buffer, bufferSize);
    }
    /* Return number of digits counted
     */
    return nd;
}

void aprintf(const char* fmt, ...)  {
    va_list args;
    va_start(args, fmt);
    va_end(args);
}

#endif

#endif