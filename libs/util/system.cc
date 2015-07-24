/*
 * Copyright (C) 2015, Simon Fuhrmann
 * TU Darmstadt - Graphics, Capture and Massively Parallel Computing
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD 3-Clause license. See the LICENSE.txt file for details.
 */

#include <iostream>
#include <cstdlib>
#include <csignal>
#ifdef __GNUC__
#   include <execinfo.h> // ::backtrace
#endif

#include "util/system.h"

UTIL_NAMESPACE_BEGIN
UTIL_SYSTEM_NAMESPACE_BEGIN

void
signal_segfault_handler (int code)
{
    if (code != SIGSEGV)
        return;
    std::cerr << "Received signal SIGSEGV (segmentation fault)" << std::endl;
    print_stack_trace();
}

/* ---------------------------------------------------------------- */

void
print_stack_trace (void)
{
#ifdef __GNUC__
    /* Get stack pointers for all frames on the stack. */
    void *array[32];
    std::size_t size = ::backtrace(array, 32);

    /* Print out all the addresses to stderr. */
    std::cerr << "Obtained " << size << " stack frames:";
    for (std::size_t i = 0; i < size; ++i)
        std::cerr << " " << array[i];
    std::cerr << std::endl;

    /* Print out human readable representation to stderr. */
    ::backtrace_symbols_fd(array, size, 2); // 2 = stderr
#endif
    std::cerr << "Segmentation fault" << std::endl;
    ::exit(1);
}

UTIL_SYSTEM_NAMESPACE_END
UTIL_NAMESPACE_END
