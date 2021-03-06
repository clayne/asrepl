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
#ifndef __REGISTRATION_H
#define __REGISTRATION_H

#include "../asrepl_types.h"

/* A registration is a routine that each engine type provides.
 * The registration populates an engine_desc and returns that struct.
 */
typedef const engine_desc_t *(*registration_cb)(void);

/* Forward declarations */
extern const engine_desc_t *native_x8664_registration(void);
#ifdef HAVE_LIBUNICORN
extern const engine_desc_t *unicorn_x8632_registration(void);
extern const engine_desc_t *unicorn_x8664_registration(void);
extern const engine_desc_t *unicorn_arm_registration(void);
extern const engine_desc_t *unicorn_mips32_registration(void);
#endif

/* List of all registrations */
static const registration_cb engine_registrations[] = {
    native_x8664_registration,
#ifdef HAVE_LIBUNICORN
    unicorn_x8664_registration,
    unicorn_arm_registration,
    unicorn_mips32_registration
#endif
};

#endif /* __REGISTRATION_H */
