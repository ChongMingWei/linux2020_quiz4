#ifndef FIZZBUZZ_H
#define FIZZBUZZ_H
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#define MSG_LEN 8
static inline bool is_divisible(uint32_t n, uint64_t M) {
    return n * M <= M - 1;
}

static uint64_t M3 = UINT64_C(0xFFFFFFFFFFFFFFFF) / 3 + 1;

static uint64_t M5 = UINT64_C(0xFFFFFFFFFFFFFFFF) / 5 + 1;

void branch(size_t i);

void bitwise(size_t i);

#endif
