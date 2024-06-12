#include "stdint.h"
#include "stdio.h"

void course1(uint8_t* src,int32_t data, uint8_t *ptr,size_t length,uint32_t base);
void test_data1(int32_t data, uint8_t *ptr,uint32_t base);
void test_data2(int32_t data, uint8_t *ptr,uint32_t base);
void test_memmove1(uint8_t *src,uint8_t *dst, size_t length);
void test_memmove2(uint8_t *src,uint8_t *dst, size_t length);
void test_memmove3(uint8_t *src,uint8_t *dst, size_t length);
void test_memcopy(uint8_t * src, uint8_t * dst, size_t length);
void test_memset(uint8_t * src, size_t length, uint8_t value);
void test_reverse(uint8_t * src, size_t length);
