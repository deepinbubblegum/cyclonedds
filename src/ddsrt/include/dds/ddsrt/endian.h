/*
 * Copyright(c) 2006 to 2018 ADLINK Technology Limited and others
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License v. 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0, or the Eclipse Distribution License
 * v. 1.0 which is available at
 * http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * SPDX-License-Identifier: EPL-2.0 OR BSD-3-Clause
 */
#ifndef DDSRT_ENDIAN_H
#define DDSRT_ENDIAN_H

#if defined(__cplusplus)
extern "C" {
#endif

#define DDSRT_LITTLE_ENDIAN 1
#define DDSRT_BIG_ENDIAN 2

#if _WIN32
# if defined(__BIG_ENDIAN)
#   define DDSRT_ENDIAN DDSRT_BIG_ENDIAN
# else
#   define DDSRT_ENDIAN DDSRT_LITTLE_ENDIAN
# endif
#else /* _WIN32 */
# if defined(__BYTE_ORDER__)
#   if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#     define DDSRT_ENDIAN DDSRT_BIG_ENDIAN
#   elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#     define DDSRT_ENDIAN DDSRT_LITTLE_ENDIAN
#   endif
# endif
#endif /* _WIN32 */

#if (DDSRT_ENDIAN != DDSRT_LITTLE_ENDIAN) && \
    (DDSRT_ENDIAN != DDSRT_BIG_ENDIAN)
# error "Endianness cannot be determined"
#endif

#if defined(__cplusplus)
}
#endif

#endif /* DDSRT_ENDIAN_H */
