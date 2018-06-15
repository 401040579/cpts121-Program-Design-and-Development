/*******************************************************************************************
* Programmer: Ran Tao                                                                       *
* Class: CptS 121, Fall  2015																*
* Programming Assignment: PA 2                                                              *
* Date: Sep 14, 2015                                                                         *
* Description:Write a C program that evaluates the equations provided below. The program	*
must prompt the user for inputs to the equations and evaluate them based on the inputs.		*
Error checking is not required for your program. You do not need to check for faulty user	*
input or dividing by zero.																	*
*******************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define THREE (int)3
#define FIVE (int)5
#define ANGLE 180
#define TWO 2
#define ONE 1

double calculate_newtons_2nd_law (double mass, double acceleration);
double calculate_volume_cylinder (double radius, double height);
char perform_character_encoding (char plaintext_character, int shift);
double calculate_distance_between_2pts (double x1, double x2, double y1, double y2);
double calculate_tangent_theta (double theta);
double calculate_parallel_resistance (int r1, int r2, int r3);
double calculate_general_equation (int a, double b, double x, double z);