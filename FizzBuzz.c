#include <stdio.h>
#include <time.h>
#include "FizzBuzz.h"
/*
#define MSG_LEN 8

static inline bool is_divisible(uint32_t n, uint64_t M) {
    return n * M <= M - 1;
}

static uint64_t M3 = UINT64_C(0xFFFFFFFFFFFFFFFF) / 3 + 1;
static uint64_t M5 = UINT64_C(0xFFFFFFFFFFFFFFFF) / 5 + 1;
*/
void branch(size_t i)
{
    char buf[10];
    if (i % 3 == 0) sprintf(buf, "Fizz");
    if (i % 5 == 0) sprintf(buf, "Buzz");
    if (i % 15 == 0) sprintf(buf, "FizzBuzz");
    if ((i % 3) && (i % 5)) sprintf(buf, "%lu", i);
}
void bitwise(size_t i)
{
    char buf[10];
    uint8_t div3 = is_divisible(i, M3);
    uint8_t div5 = is_divisible(i, M5);
    // 如果是3或5的倍數，要輸出的長度皆為4，如果是15的倍數，要輸出長度為8
    unsigned int length = (2 << div3) << div5;
    char fmt[MSG_LEN + 1];
    strncpy(fmt, &"FizzBuzz%u"[(MSG_LEN >> div5) >> (div3 << 2)], length);
    fmt[length] = '\0';
    sprintf(buf, fmt, i);
}

int main(int argc, char *argv[]) {
    long diff1 = 0, diff2 = 0;
    struct timespec time1 = {0, 0}, time2 = {0, 0};
    clock_gettime(CLOCK_REALTIME, &time1);
    for (size_t i = 1; i <= 100; i++) {
        clock_gettime(CLOCK_REALTIME, &time1);
        branch(i);
        clock_gettime(CLOCK_REALTIME, &time2);
        diff1 += (time2.tv_sec - time1.tv_sec)*1000000000 + time2.tv_nsec-time1.tv_nsec;
        
        clock_gettime(CLOCK_REALTIME, &time1);
        bitwise(i);
        clock_gettime(CLOCK_REALTIME, &time2);
        diff2 += (time2.tv_sec - time1.tv_sec)*1000000000 + time2.tv_nsec-time1.tv_nsec;
    }
    printf("Time:\nBranch: %ld ns, Bitwise: %ld ns\n", diff1/100, diff2/100);
    return 0;
}
