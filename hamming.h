#ifndef HAMMING_H
#define HAMMING_H
/* Use __builtin_popcount */
int hammingDistance(int x, int y);
/* Not use __builtin_popcount */
int hammingDistance_noextension(int x, int y);
/* Use __builtin_popcount */
int totalHammingDistance(int* nums, int numsSize);
/* Use constant time implementation of __builtin_popcount */
int totalHammingDistance_constant(int* nums, int numsSize);
/* Use bit operation  */
int totalHammingDistance_bit(int* nums, int numsSize);
#endif
