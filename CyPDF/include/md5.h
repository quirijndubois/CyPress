#ifndef MD5_H
#define MD5_H

#include <stdint.h>


#define BYTES_TO_UINT32(a, b, c, d) ((((uint32_t)(a) << 24) | ((uint32_t)(b) << 16) | ((uint32_t)(c) << 8) | (uint32_t)(d)))
#define LROT_UINT32(x, n) (((x) << (n)) | ((x) >> (32 - (n))))


char* md5_string(char* initial_msg);

#endif
