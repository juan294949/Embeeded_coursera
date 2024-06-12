/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"
#include "stdlib.h"
#include "stdio.h"
#include "platform.h"

#define MAX 32
static int check_overlap(uint8_t *src, uint8_t *dst, size_t length);
uint8_t store_value[MAX]={0};

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

/* Move data from one memory location to another memory location. Does not preserved the data from the source */ 
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){

 uint8_t *Pdst = dst;
 uint8_t *Psrc = src;
 uint8_t *Pend = src + length;

 /*check for overlapping region*/ 
 int overlap_status = check_overlap(src,dst,length);
 if(overlap_status == 1){
  dst = NULL;
  return dst; 
 }

  while(Psrc < Pend){

    *Pdst = *Psrc;
    *Psrc =0;
     Pdst++;
     Psrc++;
  }

 return dst;

}

/*Copy the data from memory location to another one preserving the data */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){

 uint8_t *Pdst = dst;
 uint8_t *Psrc = src;
 uint8_t *Pend = src + length;

 /*check for overlapping region*/ 
 int overlap_status = check_overlap(src,dst,length);
 if(overlap_status == 1){
  dst = NULL;
  return dst;
  }
      
 while(Psrc < Pend){
  *Pdst = *Psrc;
  Pdst++;
  Psrc++;
 }
 Pdst = dst;
 return Pdst;
}

/* set memory locations to an specific value */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){

  uint8_t *Psrc = src;
  uint8_t *Pend = src + length;

  while(Psrc < Pend){
   
   *Psrc =  value;
   Psrc++;
  }
  
  return src;

}

/* Zero out memory locations */
uint8_t * my_memzero(uint8_t * src, size_t length){
 
 uint8_t *Psrc = src;
 uint8_t *Pend = src + length;
	       
 while(Psrc < Pend){

  *Psrc =  0;
  Psrc++;
 }
 return src;
}

/* reverse the order of all bytes */
uint8_t * my_reverse(uint8_t * src, size_t length){
  
  uint8_t * Psrc = src;     	
  my_memcopy(src,store_value,length);
  uint8_t * sv_final_data = store_value+ (length -1);

  while(store_value<=sv_final_data)
  {
   *Psrc = *sv_final_data;
   sv_final_data--;
   Psrc++;
 }
  
  return src;
}

/* reserve N words of memory using dynamic memory allocation */ 
int32_t * reserve_words(size_t length){

int32_t* Pdst = (int32_t*)malloc(length*sizeof(int));

 return Pdst;
}

void free_words(int32_t * src){

 free(src);

}

/* Other functions created to support the required functions for the final assestment */ 

static int check_overlap(uint8_t *src, uint8_t *dst, size_t length){
  
  int overlap_status =0; 
  uint8_t *Pend = src +length;

  while(src < Pend){
   src++;
   if(src == dst){
    
    overlap_status = 1;
    break;   
   }
  }

 return overlap_status;
}
