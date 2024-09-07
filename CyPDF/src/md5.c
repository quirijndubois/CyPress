// https://datatracker.ietf.org/doc/html/rfc1321

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"


#define F(X, Y, Z) ((X & Y) | (~X & Z))
#define G(X, Y, Z) ((X & Z) | (Y & ~Z))
#define H(X, Y, Z) (X ^ Y ^ Z)
#define I(X, Y, Z) (Y ^ (X | ~Z))

#define A 0x67452301U
#define B 0xefcdab89U
#define C 0x98badcfeU
#define D 0x10325476U


static void md5_step(uint32_t* buffer, uint32_t* input, const uint32_t* K, const uint32_t* S) {
    uint32_t AA = buffer[0];
    uint32_t BB = buffer[1];
    uint32_t CC = buffer[2];
    uint32_t DD = buffer[3];
    uint32_t E;
    size_t j;
    for(size_t i = 0; i < 64; ++i) {
        // Apply round function.
        if (i < 16) {
            // Round 1.
            E = F(BB, CC, DD);
            j = i;
        } else if (i < 32) {
            // Round 2.
            E = G(BB, CC, DD);
            j = ((i * 5) + 1) % 16;
        } else if (i < 48) {
            // Round 3.
            E = H(BB, CC, DD);
            j = ((i * 3) + 5) % 16;
        } else {
            // Round 4
            E = I(BB, CC, DD);
            j = (i * 7) % 16;
        }

        // Shift values.
        uint32_t temp = DD;
        DD = CC;
        CC = BB;
        BB += LROT_UINT32(AA + E + K[i] + input[j], S[i]);
        AA = temp;
    }

    // Update buffer;
    buffer[0] += AA;
    buffer[1] += BB;
    buffer[2] += CC;
    buffer[3] += DD;
}

char* md5_string(char* initial_msg) {
    // Calculates the amount of 512-bit blocks needed for the hash calculations.
    uint64_t initial_len = strlen(initial_msg);
    size_t block_count = 8 * initial_len % 512 < 448 ? (8 * initial_len + 512) / 512 : (8 * initial_len + 512) / 512 + 1;
    size_t padded_len = 64 * block_count; // 64 bytes per block.
    uint8_t* padded_msg = calloc(padded_len, sizeof(uint8_t)); // All 512-bit blocks are stored in a single array. 8 * 64 = 512.

    // Add padding.
    memcpy(padded_msg, (uint8_t*)initial_msg, initial_len);
    padded_msg[initial_len] = 128; // This adds the '1'-bit, 128 = 10000000_2.

    initial_len *= 8; // Length in bits.
    memcpy(padded_msg + padded_len - sizeof(uint64_t), &initial_len, sizeof(uint64_t)); // Copies the length of initial_msg int bits to the last 64 bits of padded_msg.

    // Table generated with the formula K[i] = abs(sin(i + 1)) * 2^32 in radians.
    const uint32_t K[] = {
        0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
        0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
        0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
        0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
        0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
        0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
        0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
        0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
        0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
        0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
        0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
        0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
        0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
        0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
        0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
        0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
    };
    
    // S specifies the per round shifts.
    const uint32_t S[] = {
        7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
        5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
        4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
        6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
    };

    // Initialize buffer;
    uint32_t buffer[4] = { A, B, C, D };

    // Perform main md5 algorithm on each block of 512 bits.
    uint32_t block[16];
    for(size_t i = 0; i < block_count; ++i) {
        // Create 32-bit words.
        for(size_t j = 0; j < 16; ++j) {
            block[j] = BYTES_TO_UINT32(padded_msg[64 * i + 4 * j + 3], padded_msg[64 * i + 4 * j + 2], padded_msg[64 * i + 4 * j + 1], padded_msg[64 * i + 4 * j]);
        }

        md5_step(buffer, block, K, S);
    }
    free(padded_msg);

    char* hash = malloc(33 * sizeof(char)); // The hash is 32 characters long.
    sprintf(hash, "%08x%08x%08x%08x", __builtin_bswap32(buffer[0]), __builtin_bswap32(buffer[1]), __builtin_bswap32(buffer[2]), __builtin_bswap32(buffer[3])); // __builtin_bswap32() transforms a 32 bit integer between big and little endian representations.

    return hash;
}
