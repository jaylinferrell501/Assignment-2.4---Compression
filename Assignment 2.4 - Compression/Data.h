// Data.h
#pragma once

const int g_dataC[] =
{
    50, 50, 50, 12, 12, 10, 10, 10, 10, 10, 10,	10, 19, 19, 17, 17, 17, 16, 16,  0,  0,  0,  0,
};
constexpr size_t kDataCSize = sizeof(g_dataC) / sizeof(g_dataC[0]);



const int g_dataB[] =
{
    99, 12, 14, 12, 10, 10, 10, 50, 50, 50, 12, 12, 12,
};
constexpr size_t kDataBSize = sizeof(g_dataB) / sizeof(g_dataB[0]);



const int g_dataA[] =
{
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
};
constexpr size_t kDataASize = sizeof(g_dataA) / sizeof(g_dataA[0]);

int* Deflate(const int* data, const size_t& k_size);
int* Inflate(const int* data, const size_t& k_size);