/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/*
 * XSEC
 *
 * Configuration file for Windows platform
 *
 * Needs to be modified by hand
 *
 * Author(s): Berin Lautenbach
 *
 * $Id$
 *
 */


/*
 * The following defines whether Xalan integration is required.
 *
 * Xalan is used for XSLT and complex XPath processing.
 * Activate this #define if Xalan is not required (or desired)
 */

// #define XSEC_HAVE_XALAN 1


/*
 * Define presence of cryptographic providers.
 *
 * WARNING: Neither WinCAPI nor NSS are officially supported by the sole remanining
 * maintainer of this library. Use at your own risk, or contact the project if you're
 * interested in assisting with maintenance and support of that code.
 */

#define XSEC_HAVE_OPENSSL 1
// #define XSEC_HAVE_WINCAPI 1
// #define XSEC_HAVE_NSS 1

/*
 * Define if XKMS support is enabled.
 */
// #define XSEC_XKMS_ENABLED 1

/*
 * Some settings for OpenSSL if we have it
 *
 */

#if defined (XSEC_HAVE_OPENSSL)

#	include <openssl/opensslv.h>
#	if (OPENSSL_VERSION_NUMBER >= 0x00907000)
#		define XSEC_OPENSSL_CONST_BUFFERS
#		define XSEC_OPENSSL_HAVE_AES
#       define XSEC_OPENSSL_HAVE_EC
#		define XSEC_OPENSSL_CANSET_PADDING
#		define XSEC_OPENSSL_HAVE_CRYPTO_CLEANUP_ALL_EX_DATA
#	endif
#	if (OPENSSL_VERSION_NUMBER >= 0x00908000)
#		define XSEC_OPENSSL_D2IX509_CONST_BUFFER
#       define XSEC_OPENSSL_HAVE_SHA2
#       define XSEC_OPENSSL_HAVE_MGF1
#       define XSEC_OPENSSL_HAVE_EVP_PKEY_ID
#	endif
#	if (OPENSSL_VERSION_NUMBER >= 0x10001000)
#		define XSEC_OPENSSL_HAVE_GCM
#	endif

#endif

/*
 * Macros used to determine what header files exist on this
 * system
 */

/* Posix unistd.h */
/* #define HAVE_UNISTD_H */

/* Windows direct.h */
#define HAVE_DIRECT_H 1

/* Define to 1 if getcwd(NULL, 0) works. */
#define XSEC_HAVE_GETCWD_DYN 1

#include <xsec/framework/XSECVersion.hpp>
