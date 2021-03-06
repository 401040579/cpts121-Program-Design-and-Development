/*******************************************************************************************
* Programmer: Ran Tao                                                                       *
* Class: CptS 121, Fall  2015																*
* Programming Assignment: PA 3                                                              *
* Date: Sep 18, 2015                                                                        *
* Description:Write a program that processes numbers, corresponding to student records read *
in from a file, and writes the required results to an output file (see main ( )). 			*														*
*******************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double read_double (FILE *infile);// �� Reads one double precision number from the input file. Note: You may assume that the file only contains real numbers.
int read_integer (FILE *infile);// - Reads one integer number from the input file.
 
double calculate_sum (double number1, double number2, double number3, double number4, double number5);//Finds the sum of number1, number2, number3, number4, and number5 and returns the result.
double calculate_mean (double sum, int number); //Determines the mean through the calculation sum / number and returns the result. You need to check to make sure that number is not 0. If it is 0 the function returns -1.0 (we will assume that we are calculating the mean of positive numbers), otherwise it returns the mean.
double calculate_deviation (double number, double mean);// - Determines the deviation of number from the mean and returns the result. The deviation may be calculated as number - mean.
double calculate_variance (double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number);// - Determines the variance through the calculation:
												// ((deviation1)^2 + (deviation2)^2 + (deviation3)^2 + (deviation4)^2 + (deviation5)^2) / number
												//and returns the result. Hint: you may call your calculate_mean ( ) function to determine the result!
double calculate_standard_deviation (double variance);// - Calculates the standard deviation as sqrt (variance) and returns the result. Recall that you may use the sqrt ( ) function that is found in math.h.
 
double find_max (double number1, double number2, double number3, double number4, double number5);// �� Determines the maximum number out of the five input parameters passed into the function, returning the max.
double find_min (double number1, double number2, double number3, double number4, double number5);// �� Determines the minimum number out of the five input parameters passed into the function, returning the min.
 
void print_double (FILE *outfile, double number);// �� Prints a double precision number (to the hundredths place) to an output file.