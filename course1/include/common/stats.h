/******************************************************************************
 * Copyright (C) 2024 by Juan Isaza
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright.
 *
 *****************************************************************************/
/**
 * @file stats.h
 *
 * @brief: Provides understanding of the function definitions from stats.c.
 *         Provides documentation about its parameters , and returned values. 
 *
 * @author: Juan Isaza
 * @date: 5/27/2024
 *
 */

#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/*********************************************************************************************
 * @brief:A function that prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * @param: 
 *        1). unsigned char * pData : Pointer to the array that will be analyzed. 
 *
 * @return: void
 *
 *********************************************************************************************/
void print_statistics(unsigned char * pData);
/**********************************************************************************************
 * @brief: Given an array of data and a length, prints the array to the screen.
 *
 * @param:
 *        1). unsigned char * pData : Pointer to the array that will be analyzed.
 *
 * @return: void
 *
 **********************************************************************************************/
void print_array(unsigned char * pData);
/**********************************************************************************************
 * @brief: Given an array of data and a length, returns the median value.
 *
 * @param: 
 *        1). unsigned char * pData : Pointer to the array that will be analyzed. 
 *
 * @return: float
 *
 **********************************************************************************************/
float find_median(unsigned char * pData);
/**********************************************************************************************
 * @brief: Given an array of data and a length, returns the mean.
 *
 * @param:
 *        1). unsigned char * pData : Pointer to the array that will be analyzed. 
 *
 * @return: float
 *
 **********************************************************************************************/
float find_mean(unsigned char * pData);
/**********************************************************************************************
 * @brief: Given an array of data and a length, returns the maximum.
 *
 * @param:
 *        1). unsigned char * pData : Pointer to the array that will be analyzed. 
 *
 * @return: unsigned char
 *
 **********************************************************************************************/
unsigned char find_maximum(unsigned char * pData);
/**********************************************************************************************
 * @brief: Given an array of data and a length, returns the minimum
 *
 * @param:
 *        1). unsigned char * pData : Pointer to the array that will be analyzed. 
 *
 * @return: unsigned char
 *
 **********************************************************************************************/
unsigned char find_minimum(unsigned char * pData);
/**********************************************************************************************
 * @brief: Given an array of data and a length, sorts the array from largest to smallest.  (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. ).
 *
 * @param: unsigned char *pData
 *        1). unsigned char * pData : Pointer to the array that will be analyzed.
 *        2). unsigned char * buff : Pointer to the array that will contain the array data from largest to smallest.
 *
 * @return: void
 *
 **********************************************************************************************/
void sort_array(unsigned char * pData, unsigned char * buff);
/**********************************************************************************************
 * @brief: Used as a parameter to the sort()  function. 
 *
 * @param:
 *       1). const void *x used by the sort() function. 
 *       2). const void *y used by the sort() function.
 *
 * @return: int
 *
 **********************************************************************************************/
int compare(const void* x ,const void* y);
/**********************************************************************************************
 * @brief: Used to round up the data.
 *
 * @param:
 *       1).float data.
 *
 * @return: unsigned char
 *
 **********************************************************************************************/
unsigned char round_data(float data);

#endif /* __STATS_H__ */
