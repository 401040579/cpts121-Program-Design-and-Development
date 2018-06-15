/*******************************************************************************************
* Programmer: Ran Tao                                                                       *
* Class: CptS 121, Fall  2015																*
* Programming Assignment: PA 3                                                              *
* Date: Sep 18, 2015                                                                        *
* Description:Write a program that processes numbers, corresponding to student records read *
in from a file, and writes the required results to an output file (see main ( )). 			*														*
*******************************************************************************************/
#include "Header.h"

int main(){

	FILE *infile = NULL;
	FILE *outfile = NULL;
	int sid1 = 0, sid2 = 0, sid3 = 0, sid4 = 0, sid5 = 0;
	double	gpa1 = 0.0, gpa2 = 0.0, gpa3 = 0.0, gpa4 = 0.0, gpa5 = 0.0;
	int	class1 = 0, class2 = 0, class3 = 0, class4 = 0, class5 = 0;
	double	ages1 = 0.0, ages2 = 0.0, ages3 = 0.0, ages4 = 0.0, ages5 = 0.0;
	double sum_gpa = 0.0, sum_class = 0.0, sum_age = 0.0,
		mean_gpa = 0.0, mean_class = 0.0, mean_age = 0.0,
		max_gpa = 0.0, min_gpa = 0.0;
	int numbers = 0;
	double deviation1 = 0.0, deviation2 = 0.0, deviation3 = 0.0, deviation4 = 0.0, deviation5 = 0.0,
		variance = 0.0, standard_deviation = 0.0;

	/*Opens an input file "input.dat" for reading;
	Opens an output file "output.dat" for writing;*/
	infile = fopen ("input.dat", "r");
	outfile = fopen ("output.dat", "w");

	/*Reads five records from the input file (input.dat);
	You will need to use a combination of read_double ( ) and read_integer ( ) function calls here!*/
	sid1 = read_integer(infile);
	gpa1 = read_double(infile);
	class1 = read_integer(infile);
	ages1 = read_double(infile);
	sid2 = read_integer(infile);
	gpa2 = read_double(infile);
	class2 = read_integer(infile);
	ages2 = read_double(infile);
	sid3 = read_integer(infile);
	gpa3 = read_double(infile);
	class3 = read_integer(infile);
	ages3 = read_double(infile);
	sid4 = read_integer(infile);
	gpa4 = read_double(infile);
	class4 = read_integer(infile);
	ages4 = read_double(infile);
	sid5 = read_integer(infile);
	gpa5 = read_double(infile);
	class5 = read_integer(infile);
	ages5 = read_double(infile);
	
	/*Calculates the sum of the GPAs;
	Calculates the sum of the class standings;
	Calculates the sum of the ages;*/

	sum_gpa = calculate_sum(gpa1,gpa2,gpa3,gpa4,gpa5);
	printf("the sum of the GPAs: %.2lf\n", sum_gpa);
	sum_class = calculate_sum(class1,class2,class3,class4,class5);
	printf("the sum of the class standings: %.2lf\n", sum_class);
	sum_age = calculate_sum(ages1,ages2,ages3,ages4,ages5);
	printf("the sum of the ages: %.2lf\n", sum_age);

	/*Calculates the mean of the GPAs, writing the result to the output file (output.dat);
	Calculates the mean of the class standings, writing the result to the output file (output.dat);
	Calculates the mean of the ages, writing the result to the output file (output.dat);*/

//	printf("type 5 that you want to calculate the mean (if 0, it's will return -1.0): ");
//	scanf("%d", &numbers);
	
	numbers = 5;
	mean_gpa = calculate_mean(sum_gpa,numbers);
	printf("mean gpa: %.2lf\n",mean_gpa);
	print_double(outfile, mean_gpa);

	mean_class = calculate_mean(sum_class,numbers);
	printf("mean class standing: %.2lf\n",mean_class);
	print_double(outfile, mean_class);
	
	mean_age = calculate_mean(sum_age,numbers);
	printf("mean ages: %.2lf\n",mean_age);
	print_double(outfile, mean_age);

	//Calculates the deviation of each GPA from the mean (Hint: need to call calculate_deviation ( ) 5 times)
	deviation1 = calculate_deviation(gpa1,mean_gpa);
	deviation2 = calculate_deviation(gpa2,mean_gpa);
	deviation3 = calculate_deviation(gpa3,mean_gpa);
	deviation4 = calculate_deviation(gpa4,mean_gpa);
	deviation5 = calculate_deviation(gpa5,mean_gpa);
	printf("all deviations 1:%.2lf 2:%.2lf 3:%.2lf 4:%.2lf 5:%.2lf\n",deviation1,deviation2,deviation3,deviation4,deviation5);

	//Calculates the variance of the GPAs
	variance = calculate_variance(deviation1,deviation2,deviation3,deviation4,deviation5,5);
	printf("variance: %.2lf\n",variance);

	//Calculates the standard deviation of the GPAs, writing the result to the output file (output.dat);
	standard_deviation = calculate_standard_deviation(variance);
	printf("standard deviation: %.2lf\n",standard_deviation);
	print_double(outfile, standard_deviation);
	
	//Determines the min of the GPAs, writing the result to the output file (output.dat);
	min_gpa = find_min(gpa1,gpa2,gpa3,gpa4,gpa5);
	printf("min gpa: %.2lf\n",min_gpa);
	print_double(outfile, min_gpa);

	//Determines the max of the GPAs, writing the result to the output file (output.dat);
	max_gpa = find_max(gpa1,gpa2,gpa3,gpa4,gpa5);
	printf("max gpa: %.2lf\n",max_gpa);
	print_double(outfile, max_gpa);

	printf("check output.dat file :)\n");

	//Closes the input and output files (i.e. input.dat and output.dat)
	fclose(infile);
	fclose(outfile);
	
	return 0;
}