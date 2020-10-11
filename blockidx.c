#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#define ffs32(x)  ((__builtin_ffs(x)) - 1)

size_t compute_index(size_t PAGE_QUEUES, size_t offset)
{
    size_t blockidx;
    size_t divident = PAGE_QUEUES;
    blockidx = offset >> ffs32(divident);
    divident >>= ffs32(divident);
    switch (divident) {
        case 3: blockidx /= 3; 
            break;
        case 5: blockidx /= 5; 
            break;
        case 7: blockidx /= 7; 
            break;
    }
    return blockidx;
}

int main()
{
    size_t a = 30000;
    size_t pq = 56;
    printf("%lu\n",compute_index(pq, a));
    return 0;
}
