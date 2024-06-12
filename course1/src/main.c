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
 * @file main.c
 * @brief Main entry point to the C1M2 Assessment
 *
 * This file contains the main code for the C1M2 assesment. Students
 * are not to change any of the code, they are instead supposed to compile
 * these files with their makefile.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */

#include "course1.h"
#include "memory.h"
#include "platform.h"

#define MAX_LENGTH  (5)
#define NUMBER_TO_CONVERT (35)
#define BASE (2)

uint8_t source[MAX_LENGTH] ={0};
uint8_t destination[MAX_LENGTH] = {0};

int main(void) {
uint8_t* Psource = source;
uint8_t* Pdesti = destination;

PRINTF("Pdesti = %p\n",Pdesti);
PRINTF("Psource = %p\n",Psource);
#ifdef COURSE1
 course1(Psource,NUMBER_TO_CONVERT,Pdesti,MAX_LENGTH,BASE);
#endif

 return 0;
}
