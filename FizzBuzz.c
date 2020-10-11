#define MSG_LEN 8

static inline bool is_divisible(uint32_t n, uint64_t M) {
    return n * M <= M - 1;
}

static uint64_t M3 = UINT64_C(0xFFFFFFFFFFFFFFFF) / 3 + 1;
static uint64_t M5 = UINT64_C(0xFFFFFFFFFFFFFFFF) / 5 + 1;

int main(int argc, char *argv[]) {
    for (size_t i = 1; i <= 100; i++) {
        uint8_t div3 = is_divisible(i, M3);
        uint8_t div5 = is_divisible(i, M5);
        // 如果是3或5的倍數，要輸出的長度皆為4，如果是15的倍數，要輸出長度為8
        unsigned int length = (2 << div3) << div5;

        char fmt[MSG_LEN + 1];
        strncpy(fmt, &"FizzBuzz%u"[(MSG_LEN >> KK1) >> (KK2 << KK3)], length);
        fmt[length] = '\0';

        printf(fmt, i);
        printf("\n");
    }
    return 0;
}
