#ifndef _bcrypt_
#define _bcrypt_

#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include "portable_endian.h"

#if defined(_WIN32)
typedef unsigned char uint8_t;
typedef uint8_t u_int8_t;
typedef unsigned short uint16_t;
typedef uint16_t u_int16_t;
typedef unsigned uint32_t;
typedef uint32_t u_int32_t;
typedef unsigned long long uint64_t;
typedef uint64_t u_int64_t;
#define snprintf _snprintf
#define __attribute__(unused)
#elif defined(__sun)
typedef uint8_t u_int8_t;
typedef uint16_t u_int16_t;
typedef uint32_t u_int32_t;
typedef uint64_t u_int64_t;
#else
#include <stdint.h>
#endif

#define explicit_bzero(s,n) memset(s, 0, n)
#define DEF_WEAK(f)

char *bcrypt_pass(const char *pass, const char *salt);
char *bcrypt_gensalt(u_int8_t log_rounds);
int bcrypt_checkpass(const char *pass, const char *goodhash);

//int bcrypt_hashpass(const char *key, const char *salt, char *encrypted, size_t encryptedlen);
//int timingsafe_bcmp(const void *b1, const void *b2, size_t n);
//int bcrypt_pbkdf(const char *pass, size_t passlen, const uint8_t *salt, size_t saltlen, uint8_t *key, size_t keylen, unsigned int rounds);

#endif

