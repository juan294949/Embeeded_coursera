

#include "course1.h"
#include "memory.h" 
#include "data.h"
#include "platform.h" 

#define NEW_BASE (16)
#define NEW_DATA (-3500)
#define ARRAY_MAX (32)
#define NEM_MOVE_DATA (55)
#define NEM_MOVE_DATA2 (120)
#define NEM_MOVE_DATA3 (69)
#define NEW_MEM_COPY (55)
#define MEMSET_DATA (10)



void course1(uint8_t *src,int32_t data, uint8_t *ptr,size_t length,uint32_t base){
 
 uint8_t* Psrc =src ; 
 uint8_t* Pptr =ptr;

 PRINTF("Input test_data1 = %d\n",data);
 test_data1(data,Pptr,base);

 data = NEW_DATA;
 base = NEW_BASE;

 PRINTF("Input test_data2 = %d\n",data);
 test_data2(data,Pptr,base);

/*store data in the source pointer to be manipulated with test_memmove1 */
 
 PRINTF("\n\ntest_memmove1:\n\n");

 test_memmove1(Psrc,Pptr,length);

/*store data in the source pointer to be manipulated with test_memmove2 */

 PRINTF("\n\ntest_memmove2:\n\n");

 test_memmove2(Psrc,Pptr,length);

/*store data in the source pointer to be manipulated with test_memmove3 */

 PRINTF("\n\ntest_memmove3:\n\n");

 test_memmove3(Psrc,Pptr,length);

 /*store data in the source pointer to be manipulated with test_memcopy */
 
 PRINTF("\n\ntest_memcopy:\n\n");

 test_memcopy(Pptr,Psrc,length);

 /* testing memset */
 
 PRINTF("\n\ntest_memcopy:\n\n");

 test_memset(Psrc,length,MEMSET_DATA);

 /* testing mem_reverse */

 PRINTF("\n\ntest_reverse:\n\n");

 test_reverse(Psrc,length);
 
}

/*This function will test to atoi and itoa conversions for you.*/
void test_data1(int32_t data, uint8_t *ptr,uint32_t base){
 
 uint8_t digits = my_itoa(data, ptr, base);
 my_atoi(ptr,digits,base);
 my_memzero(ptr,digits);

}

/*This function will test to atoi and itoa conversions for you.*/
void test_data2(int32_t data, uint8_t *ptr,uint32_t base){

 uint8_t digits = my_itoa(data,ptr, base);
 my_atoi(ptr,digits,base);
 my_memzero(ptr,digits);
}

/*This function will test non-overlapped memmove.*/
void test_memmove1(uint8_t *src,uint8_t *dst, size_t length){
 
 size_t Length =length;
 uint8_t*Psrc = src;

 while(Length!=0){
  *Psrc = NEM_MOVE_DATA;
  Psrc++;
  Length--;
 }

 Psrc = src;
 my_memmove(Psrc,dst,length);
 Length = length;

 while(Length!=0){
  PRINTF("data stored in new mem location = %p\ndata alocated = %d\n",Psrc,*Psrc);
  Psrc++;
  Length--;
 }
}

/*This function will test overlapped memmove where there is overlap of the end of destination and start of the source regions.*/

void test_memmove2(uint8_t *src,uint8_t *dst, size_t length){
 
 size_t Length =length;
 uint8_t*Psrc = src;

 while(Length!=0){
  *Psrc = NEM_MOVE_DATA2;
  Psrc++;
  Length--;
 }

 Psrc = src;
 my_memmove(Psrc,dst,length);
 Length = length;

 while(Length!=0){
  PRINTF("data stored in new mem location = %p\ndata alocated = %d\n",Psrc,*Psrc);
  Psrc++;
  Length--;
 }

}
/*This function will test overlapped memmove where there is overlap of the start of destination and end of the source regions.*/
void test_memmove3(uint8_t *src,uint8_t *dst, size_t length){

 size_t Length =length;
 uint8_t*Psrc = src;

 while(Length!=0){
  *Psrc = NEM_MOVE_DATA3;
  Psrc++;
  Length--;
 }

 Psrc = src;
 my_memmove(Psrc,dst,length);
 Length = length;

 while(Length!=0){
  PRINTF("data stored in new mem location = %p\ndata alocated = %d\n",Psrc,*Psrc);
  Psrc++;
  Length--;
 }

}
/*This function will test memcopy.*/
void test_memcopy(uint8_t * src, uint8_t * dst, size_t length){

 uint8_t* Psrc = src;
 uint8_t* Pdst = dst;
 size_t Length =length;

 while(Length!=0){
  *Psrc = NEW_MEM_COPY;
  Psrc++;
  Length--;
 }

 Psrc = src;
 Pdst = my_memcopy(Psrc,Pdst,length);
 Length = length;
 while(Length!=0){
  PRINTF("location to copy data from = %p, data to copy = %d\n",Psrc ,*Psrc);
  PRINTF("location to store the data copied = %p, data copied  = %d\n",Pdst,*Pdst);
  Psrc++;
//  Pdst++;
  Length--;
 }
}

/*This function will test memset and memzero.*/
void test_memset(uint8_t * src, size_t length, uint8_t value){
 
 size_t Length = length;	
 uint8_t*Psrc= my_memset(src,length,value);
 while(Length!=0){
 PRINTF("memory location %p, data stored  = %d\n",Psrc,*Psrc);
 Psrc++;
 Length--;
 }
 Psrc = src;
 Psrc = my_memzero(Psrc,length);
 Length = length; 
 PRINTF("\n");
 while(Length!=0){
  PRINTF("memory location %p, data stored after beign erased  = %d\n",Psrc,*Psrc);
  Psrc++;
  Length--;
 }
}

/*This function will test reverse.*/
void test_reverse(uint8_t * src, size_t length){
  
 uint8_t* Psrc = src; 
 size_t Length = length;

 uint8_t counter =1; 
 while(Length!=0){
  *Psrc= counter;
  Psrc++;
  Length--;
  counter++;
 }

 Psrc = src;
 Length = length;
 while(Length!=0){
  PRINTF("memory location %p, data stored  = %d\n",Psrc,*Psrc);
  Psrc++;
  Length--;
 }
 Length = length;
 Psrc=src;
 Psrc= my_reverse(Psrc,length);
 PRINTF("\n");
 while(Length!=0){
  PRINTF("memory location %p, data reversed  = %d\n",Psrc,*Psrc);
  Psrc++;
  Length--;
 }
 
}
