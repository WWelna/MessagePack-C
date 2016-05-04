/*
* Copyright (C) 2013,2016 William H. Welna All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in the
*       documentation and/or other materials provided with the distribution.
*
* THIS SOFTWARE IS PROVIDED BY William H. Welna ''AS IS'' AND ANY
* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL William H. Welna BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef __MSGPACK__
#define __MSGPACK__

#include <pstdint.h>

#define MSGPACK_UINT8   0xCC
#define MSGPACK_UINT16  0xCD
#define MSGPACK_UINT32  0xCE
#define MSGPACK_UINT64  0xCF
#define MSGPACK_INT8    0xD0
#define MSGPACK_INT16   0xD1
#define MSGPACK_INT32   0xD2
#define MSGPACK_INT64   0xD3
#define MSGPACK_NIL     0xC0
#define MSGPACK_TRUE    0xC3
#define MSGPACK_FALSE   0xC2
#define MSGPACK_FLOAT   0xCA
#define MSGPACK_DOUBLE  0xCB
#define MSGPACK_RAW16   0xDA
#define MSGPACK_RAW32   0xDB
#define MSGPACK_ARR16   0xDC
#define MSGPACK_ARR32   0xDD
#define MSGPACK_MAP16   0xDE
#define MSGPACK_MAP32   0xDF

#define MSGPACK_TYPE(x) x[0]

typedef struct {
	uint8_t key_type;
	uint32_t key_size; // for RAW 
	void *key;
	uint8_t value_type;
	uint32_t value_size;
	void *value;
	void *n;
} msgpack_map;

typedef struct {
	uint8_t type;
	uint32_t size;
	void *value;
	void *n;
} msgpack_array;

char *pack8(char *, int8_t);
char *pack16(char *, int16_t);
char *pack32(char *, int32_t);
char *pack64(char *, int64_t);
char *pack8u(char *, uint8_t);
char *pack16u(char *, uint16_t);
char *pack32u(char *, uint32_t);
char *pack64u(char *, uint64_t);
char *packfloat(char *, float);
char *packdouble(char *, double);
char *packnil(char *);
char *packtrue(char *);
char *packfalse(char *);
char *packraw16(char *, char *, uint16_t);
char *packraw32(char *, char *, uint32_t);

char *unpack8(char *, int8_t *);
char *unpack16(char *, int16_t *);
char *unpack32(char *, int32_t *);
char *unpack64(char *, int64_t *);
char *unpack8u(char *, uint8_t *);
char *unpack16u(char *, uint16_t *);
char *unpack32u(char *, uint32_t *);
char *unpack64u(char *, uint64_t *);
char *unpackfloat(char *, float *);
char *unpackdouble(char *, double *);
char *unpacknil(char *);
char *unpackbool(char *, uint8_t *);
char *unpackraw16(char *, char *, uint16_t *);
char *unpackraw32(char *, char *, uint32_t *);

/* Simple and Dirty Parsing
 *
 * Pack number of elements in array/map or gets number of elements
 * and leaves it up to callee to parse accordingly
*/ 

char *packarray16(char *, uint16_t);
char *unpackarray16(char *, uint16_t *);
char *packarray32(char *, uint32_t);
char *unpackarray32(char *, uint32_t *);

char *packmap16(char *, uint16_t);
char *unpackmap16(char *, uint16_t *);
char *packmap32(char *, uint32_t);
char *unpackmap32(char *, uint32_t *);

/* Intelligent Unpacker, returns linked list.
 * End of + start of more data, offset stored in end_offset
 * to add to b.
*/

msgpack_map *unpackmap_s(char *, uint32_t *);
msgpack_array *unpackarray_s(char *, uint32_t *);

#endif
