/*
*  File: intarr.c
*  --------------------------------
*  A source (c) file for the library header file intarr.h which constists of several functions which process integer based arrays.
*/

#include <stdio.h>
#include <ctype.h>
#include "simpio.h"
#include "strlib.h"
#include "intarr.h"
/*
*  Static variables int uniqueness, int sortOrder, int turn.
*  --------------------------------
*  The static int variable uniqueness is either set to either 1 or 2, is used by the function setUniqueness().
*  The static int variable sortOrder is either set to either 1 or 2, is used by the function setSortOrder().
*  The static int variable turn shows the user how many times the function getIntArray have been exceeded. It's set to 0 from start.
*/

static int uniqueness;
static int sortOrder;
static int turn = 0;

/* Function: printIntArray
*  Usage: printIntArray(intArrayT);
*  --------------------------------
*  This function prints out a given array and stops printing out when it reach sentinel in the array.
*/

void printIntArray(intArrayT a) {

	int i;
	printf("[ ");
	for (i = 0; i <= MAXLEN; i++)
	{
		if (a[i] == SENTINEL) {
			printf("]");
			getchar();
			break;
		}
		else {
			printf("%d ", a[i]);
		}
	}
}

/* Function: getIntArray
*  Usage: getIntArray(intArrayT);
*  --------------------------------
*  The functions starts by looking if the user input string is in correct format by calling for the function
*  checkStringArray(). Step 1 If its correct then it continues to look if there is a comma in the string, if not 
*  and the string is at its last index it sets the index = SENTINEL. Else if the strings not at index one, it sets the 
*  index to the last value (by convert the substring to an integer) after the last comma or empty space and a SENTINEL after the index. 
*  Step 2, if there is a comma,
*  then the function will make a substring of the space between the two commas (or the empty space). It will also look
*  if the elements in the substring consists of integers by calling the functions checkSubStringArray(), if not it will break.
*  Otherwise it will convert the substring to an integer and continues with the next index at step 1.
*  If something in the string is incorrect, then the loop will break and prompts the user to enter a new array.
*/

bool getIntArray(intArrayT a)
{
	string userArray, stringSubArray, stringArray;
	bool checkArray, checkSubArray;
	int i, j, k, length, lengthStringArray, comma, intArray, stringToInt;
	turn++;

	while (TRUE)
	{
		while (TRUE)
		{
			printf("%d. Enter a comma-separated list of numbers: ", turn);
			userArray = GetLine();
			length = StringLength(userArray);

			checkArray = checkStringArray(userArray, length);
			if (checkArray == FALSE)
			{
				break;
			}
			else
			{
				break;
			}

		}

		stringArray = "";
		i = 0;
		j = 0;

		while (checkArray == TRUE)
		{
			comma = FindChar(',', userArray, i);
			if (comma == -1 || j == MAXLEN)
			{
				if (j == MAXLEN) 
				{
					a[j] = SENTINEL;
					return(TRUE);
				}
				else
				{
					stringSubArray = SubString(userArray, i, length - 1);
					lengthStringArray = StringLength(stringSubArray);
					checkSubArray = checkSubStringArray(stringSubArray, lengthStringArray);
					if (checkSubArray == FALSE)
					{
						break;
					}
					else
					{
						intArray = StringToInteger(stringSubArray);
						a[j] = intArray;
						a[j + 1] = SENTINEL;
						return(TRUE);
					}
				}
			}
			else
			{
				stringSubArray = SubString(userArray, i, comma - 1);
				lengthStringArray = StringLength(stringSubArray);
				checkSubArray = checkSubStringArray(stringSubArray, lengthStringArray);

				if (checkSubArray == FALSE)
				{
					break;
				}
				else
				{
					intArray = StringToInteger(stringSubArray);
					a[j] = intArray;
					j++;
					i = comma + 1;
				}
			}
		}
	}
}

/* Function: checkStringArray
*  Usage: checkStringArray(string userArray, int length);
*  --------------------------------
*  The functions gets the user input string array and the length of the array.
*  It looks if there is two comma following each other. If thats the case then it returns FALSE.
*  It also looks if there is a comma at the first and last index. If thats the case then it returns FALSE.
*  If every condition is correct, then the function returns TRUE.
*/

bool checkStringArray(string userArray, int length)
{
	int i, comma, twoComma;

	twoComma = FindString(",,", userArray, 0);

	if (twoComma != -1)
	{
		return(FALSE);
	}
	else if (twoComma == -1)
	{
		for (i = 0; i < length; i++)
		{

			if (userArray[0] == ',')
			{
				return(FALSE);
			}
			else if (userArray[length - 1] == ',')
			{
				return(FALSE);
			}
		}
	}
	return (TRUE);
}

/* Function: checkSubStringArray
*  Usage: checkSubStringArray(string stringSubArray, int lengthStringArray);
*  --------------------------------
*  The functions gets the substringarray and the length of the array from the function getIntArray.
*  It looks if element/elements in the string are numbers between 0-9. It returns FALSE if not.
*/

bool checkSubStringArray(string stringSubArray, int lengthStringArray)
{
	int i;

	for (i = 0; i < lengthStringArray; i++)
	{
		if (stringSubArray[i] < '0' || stringSubArray[i] > '9')
		{
			return (FALSE);
		}
	}
	return TRUE;
}

/* Function: appendIntArray
*  Usage: appendIntArray(intArrayT a, intArrayT b, intArrayT c);
*  --------------------------------
*  The function gets three arrays, two arrays from the user (a and b) and one empty (c).
*  Step 1: It adds all integers from array a and stops when the value of the index = SENTINEL or when MAXLEN = index.
*  Step 2: If index not equal to MAXLEN and array c has been filled by array a then it start the same procedure as step 1
*  but with the array b.
*/

int appendIntArray(intArrayT a, intArrayT b, intArrayT c)
{
	printf("AppendIntArray\n");

	int i, j, k;
	j = 0;
	k = 0;

	for (i = 0; i < MAXLEN + 1; i++)
	{
		if (a[j] != SENTINEL)
		{
			if (j == MAXLEN)
			{
				c[i] = a[j];
				c[i] = SENTINEL;
			}
			else
			{
				c[i] = a[j];
				j++;
			}
		}
		else
		{
			if (b[k] != SENTINEL)
			{
				c[i] = b[k];
				c[i + 1] = SENTINEL;
				k++;
			}
			else
			{
				c[i] = SENTINEL;
				break;
			}
		}
	}
	c[MAXLEN] = SENTINEL;
}

/* Function: interLeaveIntArray
*  Usage: interLeaveIntArray(intArrayT a, intArrayT b, intArrayT c);
*  --------------------------------
*  The function gets three arrays, two arrays from the user (a and b) and one empty (c).
*  Step 1: It adds the first index of array a to array c and then continues with first index of array b.
*  If the value of index at array a reach -1 the array c will be filled with the rest element of array b until the value of index at
*  array b reach -1 and vice versa if b reach -1 first. If the index of array c equals MAXLEN the array will stopped be filled and truncate.
*/

int interleaveIntArray(intArrayT a, intArrayT b, intArrayT c)
{
	printf("interleaveIntArray\n");
	int i, j, k;

	i = 0;
	j = 0;
	k = 0;

	while (i < MAXLEN + 1)
	{

		if (a[j] == SENTINEL)
		{
			if (b[k] != SENTINEL)
			{
				c[i] = b[k];
				c[i + 1] = SENTINEL;
				j++;
				i++;
			}
			else
			{
				c[i] = SENTINEL;
				break;
			}
		}
		else if (b[k] == SENTINEL)
		{
			if (a[j] != SENTINEL)
			{
				c[i] = a[j];
				c[i + 1] = SENTINEL;
				j++;
				i++;
			}
			else
			{
				c[i] = SENTINEL;
				break;
			}
		}
		else
		{
			c[i] = a[j];
			c[i + 1] = b[k];
			k++;
			j++;
			i += 2;
		}
	}
	c[MAXLEN] = SENTINEL;
}

/* Function: sortIntArray
*  Usage: sortIntArray(intArrayT c);
*  --------------------------------
*  This function has four methods for sorting, it depends on what the global static int variables uniqueness and sortOrder
*  values is.
*  It sorts with ununique numbers and in ascending order if uniqueness = ununique (1) and sortOrder = ascending (1).
*  It sorts with ununique numbers and in descending order if uniqueness = ununique (1) and sortOrder = descending (2).
*  It sorts with unique numbers and in descending order if uniqueness = unique (2) and sortOrder = descending (2).
*  It sorts with unique numbers and in ascending order if uniqueness = unique (2) and sortOrder = ascending (1).
*  The sorting method used is bubblesort.
*/

int sortIntArray(intArrayT c)
{
	int i, j, length, tmp;

	length = arrayLength(c);
	printf("sortIntArray\n");

	if (uniqueness == 1 && sortOrder == 1)
	{
		bubbleSortAscending(c, length);
		return 1;
	}
	else if (uniqueness == 1 && sortOrder == 2)
	{
		bubbleSortDescending(c, length);
		return 1;
	}
	else if (uniqueness == 2 && sortOrder == 2)
	{
		removeDuplicates(c, length);
		bubbleSortDescending(c, length);
		return 1;
	}
	else
	{
		bubbleSortAscending(c, length);
		removeDuplicates(c, length);
		return 1;
	}
}

/* Function: bubbleSortAscending
*  Usage: bubbleSortAscending(intArrayT c, int length);
*  --------------------------------
*  This function sorts via the bubble sort method in ascending order.
*/

int bubbleSortAscending(intArrayT c, int length) 
{
	int i, j, tmp;

	for (i = 1; i < length; i++)
	{
		for (j = 0; j < length - i; j++)
		{
			if (c[j] > c[j + 1])
			{
				tmp = c[j];
				c[j] = c[j + 1];
				c[j + 1] = tmp;
			}
		}
	}
	return c;
}

/* Function: bubbleSortDescending
*  Usage: bubbleSortDescending(intArrayT c, int length);
*  --------------------------------
*  This function sorts via the bubble sort method in descending order.
*/

int bubbleSortDescending(intArrayT c, int length) 
{
	int i, j, tmp;

	for (i = 1; i <= length; i++)
	{
		for (j = 0; j < length - 1; j++)
		{
			if (c[j + 1] > c[j])
			{
				tmp = c[j];
				c[j] = c[j + 1];
				c[j + 1] = tmp;
			}
		}
	}
	return c;
}

/* Function: removeDuplicates
*  Usage: removeDuplicates(intArrayT c, int length);
*  --------------------------------
*  This function returns a list with unique numbers.
*/

int removeDuplicates(intArrayT c, int length) 
{
	for (int i = 0; i < length; i++)
	{
		for (int j = i + 1; j < length; )
		{
			if (c[j] == c[i])
			{
				for (int k = j; k < length; k++)
				{
					c[k] = c[k + 1];
				}
				length--;
			}
			else
			{
				j++;
			}
		}
	}
	return c;
}

/* Function: arrayLength
*  Usage: arrayLength(intArrayT c);
*  --------------------------------
*  This function measures the length of a given array of type intArrayT.
*/

int arrayLength(intArrayT c)
{
	int i;

	for (i = 0; i < MAXLEN; i++)
	{
		if (c[i] == SENTINEL)
		{
			return(i);
		}
	}
}

/* Function: setUniqueness
*  Usage: setUniqueness();
*  --------------------------------
*  Prompts the user with two choices, asks the user if the array should be sorted with only unique numbers or not.
*  It treats the choice via a switch statement, the default (if the user enter something else then 1 that is unique or 2 (not unique))
*/

int setUniqueness()
{
	int userChoice;

	printf("Do you want to sort with ununique or unique numbers?\n");
	printf("Enter 1 to sort with ununique numbers.\n");
	printf("Enter 2 to sort with unique numbers.\n");

	userChoice = GetInteger();

	switch (userChoice)
	{
	case 1:
		uniqueness = 1;
		break;
	case 2:
		uniqueness = 2;
		break;
	default:
		uniqueness = 1;
		break;
	}
}

/* Function: setSortOrder
*  Usage: setSortOrder();
*  --------------------------------
*  Prompts the user with two choices, asks the user if the array should be sorted in ascending or descending order.
*  It treats the choice via a switch statement, the default (if the user enter something else then 1 (ascending) or 2 (descending))
*/

int setSortOrder()
{
	int userChoice;

	printf("Do you want to sort the array in ascending or descending order?\n");
	printf("Enter 1 to sort in ascending order.\n");
	printf("Enter 2 to sort in descending order.\n");

	userChoice = GetInteger();

	switch (userChoice)
	{
	case 1:
		sortOrder = 1;
		break;
	case 2:
		sortOrder = 2;
		break;
	default:
		sortOrder = 1;
		break;
	}
}