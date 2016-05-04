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

#include <stdio.h>
#include <stdlib.h>
#include "msgpack.h"

char *pack8(char *b, int8_t i) {
	b[0] = MSGPACK_INT8;
	b[1] = (char)i;
	return (b+2);
}
char *unpack8(char *b, int8_t *i) {
	if((uint8_t)MSGPACK_TYPE(b) == MSGPACK_INT8) {
		*i = (int8_t)b[1];
		return (b+2);
	} else
		return NULL;
}
char *pack16(char *b, int16_t i) {
	b[0] = MSGPACK_INT16;
	b[2] = (char)(i>>8)&0xFF;
	b[1] = (char)i&0xFF;
	return (b+3);
}
char *unpack16(char *b, int16_t *i) {
	if((uint8_t)MSGPACK_TYPE(b) == MSGPACK_INT16) {
		*i = (int16_t) (((uint8_t)b[2]<<8) + (uint8_t)b[1]);
		return (b+3);	
	} else
		return NULL;
}
char *pack32(char *b, int32_t i) {
	b[0] = MSGPACK_INT32;
	b[4] = (char)(i>>24)&0xFF;
	b[3] = (char)(i>>16)&0xFF;
	b[2] = (char)(i>>8)&0xFF;
	b[1] = (char)i&0xFF;
	return (b+5);
}
char *unpack32(char *b, int32_t *i) {
	if((uint8_t)MSGPACK_TYPE(b) == MSGPACK_INT32) {
		*i = (int32_t) (((uint8_t)b[4]<<24) + ((uint8_t)b[3]<<16) + ((uint8_t)b[2]<<8) + (uint8_t)b[1]);
		return (b+5);	
	} else
		return NULL;
}
char *pack64(char *b, int64_t i) {
	b[0] = MSGPACK_INT64;
	b[8] = (char)(i>>56)&0xFF;
	b[7] = (char)(i>>48)&0xFF;
	b[6] = (char)(i>>40)&0xFF;
	b[5] = (char)(i>>32)&0xFF;
	b[4] = (char)(i>>24)&0xFF;
	b[3] = (char)(i>>16)&0xFF;
	b[2] = (char)(i>>8)&0xFF;
	b[1] = (char)i&0xFF;
	return (b+9);
}
char *unpack64(char *b, int64_t *i) {
	if((uint8_t)MSGPACK_TYPE(b) == MSGPACK_INT64) {
		*i = (int64_t) (((uint8_t)b[8]<<56) + ((uint8_t)b[7]<<48) + ((uint8_t)b[6]<<40) + ((uint8_t)b[5]<<32) + ((uint8_t)b[4]<<24) + ((uint8_t)b[3]<<16) + ((uint8_t)b[2]<<8) + (uint8_t)b[1]);
		return (b+9);
	} else
		return NULL;
}
char *pack8u(char *b, uint8_t i) {
	b[0] = MSGPACK_UINT8;
	b[1] = (char)i;
	return (b+2);
}
char *unpack8u(char *b, uint8_t *i) {
	if((uint8_t)MSGPACK_TYPE(b) == MSGPACK_UINT8) {
		*i = (uint8_t)b[1];
		return (b+2);
	} else
		return NULL;
}
char *pack16u(char *b, uint16_t i) {
	b[0] = MSGPACK_UINT16;
	b[2] = (char)(i>>8)&0xFF;
	b[1] = (char)i&0xFF;
	return (b+3);
}
char *unpack16u(char *b, uint16_t *i) {
	if((uint8_t)MSGPACK_TYPE(b) == MSGPACK_UINT16) {
		*i = (uint16_t) (((uint8_t)b[2]<<8) + (uint8_t)b[1]);
		return (b+3);	
	} else
		return NULL;
}
char *pack32u(char *b, uint32_t i) {
	b[0] = MSGPACK_UINT32;
	b[4] = (char)(i>>24)&0xFF;
	b[3] = (char)(i>>16)&0xFF;
	b[2] = (char)(i>>8)&0xFF;
	b[1] = (char)i&0xFF;
	return (b+5);
}
char *unpack32u(char *b, uint32_t *i) {
	if((uint8_t)MSGPACK_TYPE(b) == MSGPACK_UINT32) {
		*i = (uint32_t) (((uint8_t)b[4]<<24) + ((uint8_t)b[3]<<16) + ((uint8_t)b[2]<<8) + (uint8_t)b[1]);
		return (b+5);	
	} else
		return NULL;
}
char *pack64u(char *b, uint64_t i) {
	b[0] = MSGPACK_UINT64;
	b[8] = (char)(i>>56)&0xFF;
	b[7] = (char)(i>>48)&0xFF;
	b[6] = (char)(i>>40)&0xFF;
	b[5] = (char)(i>>32)&0xFF;
	b[4] = (char)(i>>24)&0xFF;
	b[3] = (char)(i>>16)&0xFF;
	b[2] = (char)(i>>8)&0xFF;
	b[1] = (char)i&0xFF;
	return (b+9);
}
char *unpack64u(char *b, uint64_t *i) {
	if((uint8_t)MSGPACK_TYPE(b) == MSGPACK_UINT64) {
		*i = (uint64_t) (((uint8_t)b[8]<<56) + ((uint8_t)b[7]<<48) + ((uint8_t)b[6]<<40) + ((uint8_t)b[5]<<32) + ((uint8_t)b[4]<<24) + ((uint8_t)b[3]<<16) + ((uint8_t)b[2]<<8) + (uint8_t)b[1]);
		return (b+9);
	} else
		return NULL;
}
char *packnil(char *b) {
	b[0] = MSGPACK_NIL;
	return (b+1);
}
char *unpacknil(char *b) {
	if((uint8_t)MSGPACK_TYPE(b) == MSGPACK_NIL)
		return (b+1);
	else
		return NULL;
}
char *packtrue(char *b) {
	b[0] = MSGPACK_TRUE;
	return (b+1);
}
char *packfalse(char *b) {
	b[1] = MSGPACK_FALSE;
	return (b+1);
}
char *unpackbool(char *b, uint8_t *i) {
	if((uint8_t)MSGPACK_TYPE(b) == MSGPACK_TRUE) {
		*i = 1;
		return (b+1);
	} else if((uint8_t)MSGPACK_TYPE(b) == MSGPACK_FALSE) {
		*i = 0;
		return (b+1);
	} else
		return NULL;
}
char *packfloat(char *b, float f) {
	uint32_t i = (uint32_t)f;
	b[0] = MSGPACK_FLOAT;
	b[4] = (char)(i>>24)&0xFF;
	b[3] = (char)(i>>16)&0xFF;
	b[2] = (char)(i>>8)&0xFF;
	b[1] = (char)i&0xFF;
	return (b+5);
}
char *unpackfloat(char *b, float *f) {
	if((uint8_t)MSGPACK_TYPE(b) == MSGPACK_FLOAT) {
		*f = (float) (((uint8_t)b[4]<<24) + ((uint8_t)b[3]<<16) + ((uint8_t)b[2]<<8) + (uint8_t)b[1]);
		return (b+5);	
	} else
		return NULL;
}
char *packdouble(char *b, double d) {
	uint64_t i = (uint64_t)d;
	b[0] = MSGPACK_DOUBLE;
	b[8] = (char)(i>>56)&0xFF;
	b[7] = (char)(i>>48)&0xFF;
	b[6] = (char)(i>>40)&0xFF;
	b[5] = (char)(i>>32)&0xFF;
	b[4] = (char)(i>>24)&0xFF;
	b[3] = (char)(i>>16)&0xFF;
	b[2] = (char)(i>>8)&0xFF;
	b[1] = (char)i&0xFF;
	return (b+9);
}
char *unpackdouble(char *b, double *d) {
	if((uint8_t)MSGPACK_TYPE(b) == MSGPACK_DOUBLE) {
		*d = (double) (((uint8_t)b[8]<<56) + ((uint8_t)b[7]<<48) + ((uint8_t)b[6]<<40) + ((uint8_t)b[5]<<32) + ((uint8_t)b[4]<<24) + ((uint8_t)b[3]<<16) + ((uint8_t)b[2]<<8) + (uint8_t)b[1]);
		return (b+9);
	} else
		return NULL;
}
char *packraw16(char *b, char *d, uint16_t l) {
	b[0] = MSGPACK_RAW16;
	b[2] = (char)(l>>8)&0xFF;
	b[1] = (char)l&0xFF;
	memcpy((b+3), d, l);
	return (b+3+l);
}
char *unpackraw16(char *b, char *d, uint16_t *l) {
	if((uint8_t)MSGPACK_TYPE(b) == MSGPACK_RAW16) {
		uint16_t pl = (uint16_t) (((uint8_t)b[2]<<8) + (uint8_t)b[1]);
		if((*l)>=pl) {
			memcpy(d, (b+3), pl);
			*l = pl;
			return (b+3+pl);
		} else {
			*l = pl-(*l);
			return NULL;
		}
	} else {
		*l = 0;
		return NULL;
	}
}
char *packraw32(char *b, char *d, uint32_t l) {
	b[0] = MSGPACK_RAW32;
	b[4] = (char)(l>>24)&0xFF;
	b[3] = (char)(l>>16)&0xFF;
	b[2] = (char)(l>>8)&0xFF;
	b[1] = (char)l&0xFF;
	memcpy((b+5), d, l);
	return (b+5+l);
}
char *unpackraw32(char *b, char *d, uint32_t *l) {
	if((uint8_t)MSGPACK_TYPE(b) == MSGPACK_RAW32) {
		uint32_t pl = (uint32_t) (((uint8_t)b[4]<<24) + ((uint8_t)b[3]<<16) + ((uint8_t)b[2]<<8) + (uint8_t)b[1]);
		if((*l)>=pl) {
			memcpy(d, (b+5), pl);
			*l = pl;
			return (b+5+pl);
		} else {
			*l = pl-(*l);
			return NULL;
		}
	} else {
		*l = 0;
		return NULL;
	}
}

char *packarray16(char *b, uint16_t n) {
	b[0] = MSGPACK_ARR16;
	b[2] = (char)(n>>8)&0xFF;
	b[1] = (char)n&0xFF;
	return (b+3);
}

char *unpackarray16(char *b, uint16_t *n) {
	if((uint8_t)MSGPACK_TYPE(b) == MSGPACK_ARR16) {
		*n = (uint16_t) (((uint8_t)b[2]<<8) + (uint8_t)b[1]);
		return (b+3);	
	} else
		return NULL;
}

char *packarray32(char *b, uint32_t n) {
	b[0] = MSGPACK_ARR32;
	b[4] = (char)(n>>24)&0xFF;
	b[3] = (char)(n>>16)&0xFF;
	b[2] = (char)(n>>8)&0xFF;
	b[1] = (char)n&0xFF;
	return (b+5);
}

char *unpackarray32(char *b, uint32_t *n) {
	if((uint8_t)MSGPACK_TYPE(b) == MSGPACK_ARR32) {
		*n = (uint32_t) (((uint8_t)b[4]<<24) + ((uint8_t)b[3]<<16) + ((uint8_t)b[2]<<8) + (uint8_t)b[1]);
		return (b+5);	
	} else
		return NULL;
}

char *packmap16(char *b, uint16_t n) {
	b[0] = MSGPACK_MAP16;
	b[2] = (char)(n>>8)&0xFF;
	b[1] = (char)n&0xFF;
	return (b+3);
}

char *unpackmap16(char *b, uint16_t *n) {
	if((uint8_t)MSGPACK_TYPE(b) == MSGPACK_MAP16) {
		*n = (uint16_t) (((uint8_t)b[2]<<8) + (uint8_t)b[1]);
		return (b+3);	
	} else
		return NULL;
}

char *packmap32(char *b, uint32_t n) {
	b[0] = MSGPACK_MAP32;
	b[4] = (char)(n>>24)&0xFF;
	b[3] = (char)(n>>16)&0xFF;
	b[2] = (char)(n>>8)&0xFF;
	b[1] = (char)n&0xFF;
	return (b+5);
}

char *unpackmap32(char *b, uint32_t *n) {
	if((uint8_t)MSGPACK_TYPE(b) == MSGPACK_MAP32) {
		*n = (uint32_t) (((uint8_t)b[4]<<24) + ((uint8_t)b[3]<<16) + ((uint8_t)b[2]<<8) + (uint8_t)b[1]);
		return (b+5);	
	} else
		return NULL;
}

msgpack_map *unpackmap_s(char *b, uint32_t *end_offset) {

}

msgpack_array *unpackarray_s(char *b, uint32_t *end_offset) {

}
