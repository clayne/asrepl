/*******************************************************************************
 * BSD 3-Clause License
 *
 * Copyright (c) 2017, Matt Davis (enferex) https://github.com/enferex
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/
#include "config.h"
#ifndef __TUI_H
#define __TUI_H

typedef enum _tui_window_e
{
    TUI_WIN_REPL,        /* REPL input/output window   */
    TUI_WIN_STATUS,      /* Miscelaneous window        */
    TUI_WIN_REG,         /* Register window            */
    TUI_WIN_REPLFRAME,   /* Do not use, only a border  */
    TUI_WIN_STATUSFRAME, /* Do not use, only a border  */
    TUI_WIN_REGFRAME,    /* Do not use, only a border  */
    TUI_WIN_MAX          /* Max max count of this enum */
} tui_window_e;

#ifdef HAVE_LIBNCURSES
/* Text User Interface (requires ncurses support) */
extern void tui_init(void);
extern void tui_update(void);
extern void tui_exit(void); /* Stop/shutdown the TUI */
extern void tui_write(tui_window_e windex, const char *fmt, ...);

/* The returned string is from strdup, call free() when done. */
extern char *tui_readline(const char *prompt);

/* Set the output to be at the start of the window (to overwrite 
 * previous text).
 */
extern void tui_reset(tui_window_e windex);

#endif /* HAVE_LIBNCURSES */
#endif /* __TUI_H         */
