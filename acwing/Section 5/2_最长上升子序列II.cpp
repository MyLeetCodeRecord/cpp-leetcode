#include <cstdio>
#include <iostream>
using namespace std;

/* 朴素做法需要O(n^2)的复杂度
 * [3 1 2 1 8 5 6]
 * 能够以3结尾的一定可以以1结尾, 所以3不需要存
 * 即, 长度为len=1,2,...的递增子序列, 只需要存一个结尾数字最小的
 */
