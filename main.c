/*
*  File: main.c
*  --------------------------------
*  Runs the main program.
*/

#include "intarr.h"

main() {
	intArrayT a, b, c;
	setUniqueness();
	setSortOrder();
	getIntArray(a);
	printIntArray(a);
	getIntArray(b);
	printIntArray(b);
	appendIntArray(a, b, c);
	printIntArray(c);
	interleaveIntArray(a, b, c);
	printIntArray(c);
	sortIntArray(c);
	printIntArray(c);
}