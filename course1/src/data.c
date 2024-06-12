
#define BASE_2 (2)
#define BASE_16 (16)

#define MAX_DIGITS (32)  /* maximun number is a_32 bit integer */


#include "data.h" 
#include "stdio.h"
#include "platform.h"
#include "memory.h"

static uint8_t my_conversion_itoa(int32_t data ,uint8_t * ptr, uint32_t base);
static int32_t my_conversion_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);
uint8_t my_pow(double base,uint8_t remainder,int exponent);



uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){

 uint8_t *str =ptr ;
 uint8_t length = my_conversion_itoa(data,ptr,base);
 my_reverse(ptr,length);
 PRINTF("ASCII string data base_%d = ",base);
 while(*str){
  PRINTF("%c",*str);
  str++;
 }
 PRINTF("\n");
 return length;
}

uint8_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
 uint8_t *str =ptr;
 my_reverse(ptr,digits);
 int32_t number = my_conversion_atoi(str,digits,base);
 return number; 
}

/* functions create  for the assignament */

static int32_t my_conversion_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
 
 uint8_t loop = digits;
 uint8_t exponent = 0; 
 uint8_t *str=ptr;
 int32_t num =0;
 int32_t total =0;
 
 while(exponent < loop){

  if(*str>='0' && *str <= '9'){

   num = (*str - '0');
   uint8_t result=  my_pow((double)base,(uint8_t)num,exponent);
   total = total + result;
  }

  else if(*str>= 'A' && *str <= 'F'){

   num = (*str - 'A');
   uint8_t result=  my_pow((double)base,(uint8_t)num,exponent);
   total = total + result;
  }

  str++;
  exponent++;

 }
  return total;
}

static uint8_t my_conversion_itoa(int32_t data ,uint8_t * ptr, uint32_t base){

 uint8_t *Pstore = ptr ;	
 uint8_t remainder = 0; 
 uint8_t array_lenght = 0;
 int flag =0;
 if((base >= BASE_2) && (base <= BASE_16)){
  if(data < 0){
   data = (-1)*(data);
   flag =1;
   }
 /* covert to the corresponding base */
   while(data!=0){
    remainder = data % base;
    if(remainder>=10 && remainder<=15){
     *Pstore = remainder - 10 + 'A';
    } 
    else{
     *Pstore = remainder + '0';
    }

    data = data/base;
    Pstore++;
    array_lenght ++;
   }
 
 }
  else
  {
   return (-1);
  }

  if(flag ==1){
   *Pstore = '-'; /* prepend negative */
   Pstore++;
   array_lenght ++;
  }
 return array_lenght;
}

uint8_t my_pow(double base,uint8_t remainder,int exponent){
 
 double result =0;
 
 if((exponent==0)&&(remainder!=0)){
  result = 1;
 }

 else{
   result = remainder*base;
  while(exponent >1){
   
   result = result*base;
   exponent--;

  }
  
 }
 return result;
}
