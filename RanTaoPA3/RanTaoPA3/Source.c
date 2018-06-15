/*******************************************************************************************
* Programmer: Ran Tao                                                                       *
* Class: CptS 121, Fall  2015																*
* Programming Assignment: PA 3                                                              *
* Date: Sep 18, 2015                                                                        *
* Description:Write a program that processes numbers, corresponding to student records read *
in from a file, and writes the required results to an output file (see main ( )). 			*														*
*******************************************************************************************/

#include "Header.h"

double read_double (FILE *infile){
	double number_double = 0.0;
	fscanf(infile, "%lf", &number_double);
	return number_double;
}// ！ Reads one double precision number from the input file. Note: You may assume that the file only contains real numbers.
int read_integer (FILE *infile){
	int number_integer = 0;
	fscanf(infile, "%d", &number_integer);
	return number_integer;
}// - Reads one integer number from the input file.

double calculate_sum (double number1, double number2, double number3, double number4, double number5){\
	double sum = number1 + number2 + number3 + number4 + number5;
return sum;
}//Finds the sum of number1, number2, number3, number4, and number5 and returns the result.
double calculate_mean (double sum, int number){
	if(number == 0){
		return -1.0;
		printf("number is 0, so return is -1.0.\n");
	}else{
		return sum/number;
	}
} //Determines the mean through the calculation sum / number and returns the result. 
//You need to check to make sure that number is not 0. If it is 0 the function returns -1.0 
//(we will assume that we are calculating the mean of positive numbers), otherwise it returns the mean.
double calculate_deviation (double number, double mean){
	return number - mean;
}// - Determines the deviation of number from the mean and returns the result. The deviation may be calculated as number - mean.
double calculate_variance (double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number){
	return (deviation1*deviation1 + deviation2*deviation2 + deviation3*deviation3 + deviation4*deviation4 + deviation5*deviation5) / number;
}// - Determines the variance through the calculation:
// ((deviation1)^2 + (deviation2)^2 + (deviation3)^2 + (deviation4)^2 + (deviation5)^2) / number
//and returns the result. Hint: you may call your calculate_mean ( ) function to determine the result!
double calculate_standard_deviation (double variance){
	return sqrt(variance);
}// - Calculates the standard deviation as sqrt (variance) and returns the result
//Recall that you may use the sqrt ( ) function that is found in math.h.

double find_max (double number1, double number2, double number3, double number4, double number5){
	/*double buffer = 0.0;

	if(number1>number2){
		buffer = number1;
		number1 =  number2;
		number2 = buffer;
	}
	else if(number2>number3){
		buffer = number2;
		number2 =  number3;
		number3 = buffer;
	}
	else if(number3>number4){
		buffer = number3;
		number3 =  number4;
		number4 = buffer;
	}
	else if(number4>number5){
		buffer = number4;
		number4 =  number5;
		number5 = buffer;
	}
	else{
		printf ("errors!");
	}
	return number4;*/

	double max = 0.0, max1 = 0.0, max2 = 0.0;

	if(number1 > number2){
		max1 = number1;
	}else{
		max1 = number2;
	}

	if(number3>number4){
		max2 = number3;
	}else{
		max2 = number4;
	}

	if(max1>max2){
		max = max1;
	}else{
		max = max2;
	}

	if(max>number5){
		return max;
	}else{
		return number5;
	}

}// ！ Determines the maximum number out of the five input parameters passed into the function, returning the max.
double find_min (double number1, double number2, double number3, double number4, double number5){
	/*double buffer = 0.0;

	if(number1<number2){
		buffer = number1;
		number1 =  number2;
		number2 = buffer;
	}
	else if(number2<number3){
		buffer = number2;
		number2 =  number3;
		number3 = buffer;
	}
	else if(number3<number4){
		buffer = number3;
		number3 =  number4;
		number4 = buffer;
	}
	else if(number4<number5){
		buffer = number4;
		number4 =  number5;
		number5 = buffer;
	}
	else{
		printf ("errors!");
	}
	return number5;*/
	//
	/*
	double min = min1;

	if(num1 < min)
	{
	}
	*/

	double min = 0.0, min1 = 0.0, min2 = 0.0;

	if(number1<number2){
		min1 = number1;
	}else{
		min1 = number2;
	}

	if(number3<number4){
		min2 = number3;
	}else{
		min2 = number4;
	}

	if(min1<min2){
		min = min1;
	}else{
		min = min2;
	}

	if(min<number5){
		return min;
	}else{
		return number5;
	}

}// ！ Determines the minimum number out of the five input parameters passed into the function, returning the min.
void print_double (FILE *outfile, double number){// ！ Prints a double precision number (to the hundredths place) to an output file.
	fprintf(outfile, "%.2lf\n", number);
}