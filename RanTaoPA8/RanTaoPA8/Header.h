/*******************************************************************************************
* Programmer: Ran Tao                                                                       
* Class: CptS 121, Fall  2015																
* Programming Assignment: PA 8
* Date: Dec 7, 2015                                                                         
* Description:For this assignment you will be required to write functions which solve each
of the following problems. You must place all of your functions in one project. If you use 
any code that you find online, you must reference it in comments.								
*******************************************************************************************/
#ifndef RANTAOPA8
#define RANTAOPA8

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define _CRT_SECURE_NO_WARNINGS
#define nu 10

typedef struct occurrences
{
	int num_occurrences;
	double frequency;
} Occurrences;

int binary_search(int arr_sorted_int[], int target);

void bubble_sort(char *arr, int numbers);
void bubble_sort1(char * arr, int num, int order);

int is_palindrome(char *string, int length, int num);

void maximum_occurences (Occurrences *list, char *string, int *n, char *c);

void max_consecutive_intergers(int arr[][5], int row, int col, int *ptr, int *ptr2);

#endif