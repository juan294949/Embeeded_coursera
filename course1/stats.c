/******************************************************************************
 * Copyright (C) 2024 by Juan Isaza
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright.
 *
 *****************************************************************************/
/**
 * @file: stats.c
 * @brief: Contains the definition of each of the functions declared in the stats.h header file.
 *
 * @author: Juan Pablo Isaza.
 *
 * @date: 5/27/2024
 *
 */

#include <stdio.h>
#include "stats.h"
#include "stdlib.h"

/* Size of the Data Set */

#define SIZE (40)

int main() {

 unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

 /* Other Variable Declarations Go Here */

 unsigned char buff[SIZE] = {0};

 /* Statistics and Printing Functions Go Here */
 
  sort_array(test,buff);
  print_array(buff);
  print_statistics(buff);
 
 return 0;

}

/* Add other Implementation File Code Here */
void print_statistics(unsigned char *pData){

 /* print the mean */
 printf("\n mean = %d",round_data(find_mean(pData)));
 /* print the median */
 printf("\n median = %d",round_data(find_median(pData)));
 /* print the maximum */ 
 printf("\n maximum = %d",find_maximum(pData));
 /* print the minimum */ 
 printf("\n minimum = %d\n",find_minimum(pData));

}

/* print array */ 
void print_array(unsigned char* pData){
  printf("\n array = ");
  unsigned char* pData_end = pData+SIZE;
  while(pData < pData_end)
  {
   printf("%d ",*pData);
   pData++;
  }

}

/* find the median */
float find_median(unsigned char* pData){

 float  median =0;

 median = (( (float) pData[19] + (float)pData[20])/2);

 return median;
}

/* finds the mean of the array*/
float find_mean(unsigned char* pData){

  float sum =0;

  for(int i=0;i<SIZE;i++){
    sum += (float) *pData;
    pData++;
  }

  sum = (sum/SIZE);

 return sum;
}

/* find_maximum function definition */
unsigned char find_maximum(unsigned char *pData ){

 unsigned char* pData_start = pData;
 unsigned int size = (sizeof(pData))/(sizeof(*pData));
 int  j =0;         
 unsigned char maximum =0; 

 for(int i = 0; i < (SIZE-1); i++){

  j =0;

  while(j < (SIZE-1)){
   /* check for the smallest value in the array */

   if((*pData_start >  *(pData + j))&&(*pData_start > maximum)){
    /*store the value as the minimun*/
    maximum = *pData_start;
   }              				        
    j++;
  }			  
  pData_start++;
 }
 return maximum;
}


/* find_minimum function definition */ 
unsigned char find_minimum(unsigned char *pData ){

 unsigned char* pData_start = pData;
 unsigned int size = (sizeof(pData))/(sizeof(*pData));
 int  j =0; 
 unsigned char minimum =0;

 for(int i = 0; i <(SIZE-1); i++){

  j =0;

  while(j < (SIZE-1)){

   /* check for the smallest value in the array */
   if(*pData_start < *(pData + j)){

   /*store the value as the minimun*/
     minimum = *pData_start ;
   }
    j++;
  }

  pData_start++;

 }
 
 return minimum;
}

/* sort_array function definition */ 
void sort_array(unsigned char* pData,unsigned char* buff_sorted){

 qsort((void*)pData,SIZE,sizeof(*pData),compare);

 /* sort the array from large to small */
  for(int i = (SIZE-1) ; i >=0 ; --i){
    *buff_sorted = pData[i];
     buff_sorted++;
  }
}

/* compare function definition */ 
int compare(const void* x,const void* y){

 return (*(unsigned char*)x - *(unsigned char*)y);

}

/* round to the value to the nearest integer */ 
unsigned char round_data(float data){

 data = (int)(data+ 0.5);

 return data;

}
