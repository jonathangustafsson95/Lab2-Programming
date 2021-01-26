/*
*  File: intarr.h
*  --------------------------------
*  A library header file for c which constists of several functions which process integer based arrays.
*/

#ifndef _intarr_h
#define _intarr_h

#include "strlib.h"

/* 
*  #define MAXLEN and SENTINEL
*  --------------------------------
*  MAXLEN is the maximum length of all arrays of data type intArrayT that is used. It's set to 5.
*  SENTINEL shows the end of an array of type intArrayT that is used. It's set to -1.
*/

#define MAXLEN 5
#define SENTINEL -1

/*
*  Data type int intArraT[]
*  --------------------------------
*  Enumeration type for integers.
*/

typedef int intArrayT[MAXLEN + 2];

/* Function: printIntArray
*  Usage: printIntArray(intArrayT);
*  --------------------------------
*  This function prints out a given array of type int intArrayT.
*/

void printIntArray(intArrayT a);

/* Function: getIntArray
*  Usage: getIntArray(intArrayT a);
*  --------------------------------
*  This function gets an empty array of type int intArrayT, and prompts the user to enter an
*  array of integers with commas between each integers.
*/

bool getIntArray(intArrayT a);

/* Function: appendIntArray
*  Usage: appendIntArray(intArrayT a, intArrayT b, intArrayT c);
*  --------------------------------
*  This function combines two given arrays of type int intArrayT to a new array of the same type.
*  It fills the new array with the first given array, and continues with the second array
*  until there is no more space. The function truncates the array in that case.
*/

int appendIntArray(intArrayT a, intArrayT b, intArrayT c);

/* Function: interLeaveIntArray
*  Usage: interLeaveIntArray(intArrayT a, intArrayT b, intArrayT c);
*  --------------------------------
*  This function combines two given arrays of type int intArrayT to a new array of the same type.
*  It fills the new array with the first index in the first given array, and continues with the first
*  index in the second array. This procedure continues until there is no more space in the new array
*  and truncates the rest.
*/

int interleaveIntArray(intArrayT a, intArrayT b, intArrayT c);

/* Function: sortIntArray
*  Usage: sortIntArray(intArrayT c);
*  --------------------------------
*  This function sorts a given array of type int intArrayT.
*  The function contains of four different sorting methods and it depends on the global static integer variables.
*  int userChoiceOne and userChoiceTwo which method that will be used.
*  if userChoiceOne = 1 and userChoiceTwo = 1 the array will be sorted with duplicate integers and in ascending order.
*  if userChoiceOne = 1 and userChoiceTwo = 2 the array will be sorted with duplicate integers and in descending order.
*  if userChoiceOne = 2 and userChoiceTwo = 2 the array will be sorted with unique integers and in descending order.
*  if userChoiceOne = 2 and userChoiceTwo = 1 the array will be sorted with unique integers and in ascending order.
*/

int sortIntArray(intArrayT c);

/* Function: setUniqueness
*  Usage: setUniqueness();
*  --------------------------------
*  This function prompts the user to choose either to sort the array with unique integers or not
*  It change the global static varible int userChoiceTwo to either 1 (not unique) or 2 (unique).
*/


int setUniqueness();

/* Function: setSortOrder
*  Usage: setSortOrder();
*  --------------------------------
*  This function prompts the user to choose either to sort the array in ascending or descending order.
*  It change the global static varible int userChoiceTwo to either 1 (ascending) or 2 (descending).
*/

int setSortOrder();

#endif /* _intarr_h */