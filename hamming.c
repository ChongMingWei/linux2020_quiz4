#include "hamming.h"

int hammingDistance(int x, int y)
{
    return __builtin_popcount(x ^ y);
}

int hammingDistance_noextension(int x, int y)
{
    int a = x^y;
    int b = 0;
    while (a){
        int t = a & (-a);
        b++;
        a ^= t;      
    return b;
}

int totalHammingDistance(int* nums, int numsSize)
{
    int sum=0;
    for (int i = 0;i < numsSize - 1; ++i){
        for (int j = i + 1; j < numsSize; ++j){
            sum += __builtin_popcount(nums[i]^nums[j]);
        }
    }
    return sum;
}

int totalHammingDistance_constant(int* nums, int numsSize)
{
    int sum=0;
    for (int i = 0;i < numsSize - 1; ++i){
        for (int j = i + 1; j < numsSize; ++j){
            int a = nums[i]^nums[j];
            unsigned n;
            unsigned v = (unsigned)a;
            n = (v >> 1) & 0x77777777;
            v -= n;
            n = (n >> 1) & 0x77777777;
            v -= n;
            n = (n >> 1) & 0x77777777;
            v -= n;

            v += v >> 4;
            v &= 0x0F0F0F0F;
            v *= 0x01010101; 
            v >>= 24;
            sum +=v;
        }
    }
    return sum;
}

int totalHammingDistance_bit(int* nums, int numsSize)
{
    int sum=0;
    for(int i = 0; i < 32;++i){
        int count1=0;
        for (int j = 0;j < numsSize;++j)
            count1 += (nums[j]&(1u<<i))>>i;//if bit i of nums[j] is 1, count1++
        sum += count1*(numsSize-count1);//compute hamming distance of bit i
    }
    return sum;
}
