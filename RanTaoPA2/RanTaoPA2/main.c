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
#include "equations.h"

int main(void){
	int r1 = 0, r2 = 0, r3 = 0, a = 0, shift = 0;
	double mass = 0.0, acceleration = 0.0, force = 0.0, 
		radius = 0.0, height = 0.0, volume_cylinder = 0.0, 
		x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0, distance = 0.0, 
		theta = 0.0, tan = 0.0, 
		parallel_resistance = 0.0, 
		b = 0.0, z = 0.0, x = 0.0, engEquation = 0.0;
	char plaintext_character = '\0', encoded_character = '\0';

	printf("----------------------------------------Equation 1-------------------------------------------------------\n");
	/*
	Newton¡¯s Second Law of Motion: force = mass * acceleration
	*/

	printf("Please enter the mass and acceleration <both floating-point values> for use in Newton's Second Law\n");
	printf("mass: ");//  or using	scanf("%lf%lf", &mass, &acceleration);
	scanf("%lf", &mass);
	printf("acceleration: ");
	scanf("%lf", &acceleration);
	printf("Newton's Second Law: force = mass * acceleration = %f * %f = %.2f\n", mass, acceleration, calculate_newtons_2nd_law (mass, acceleration));
	
	printf("----------------------------------------Equation 2-------------------------------------------------------\n");
	/*
	Volume of a cylinder: volume_cylinder = PI * radius2 * height
	*/
	printf("Please enter the radius and height <both floating-point values> for use in a volume of cylinder equation\n");
	printf("radius: ");
	scanf("%lf", &radius);
	printf("height: ");
	scanf("%lf", &height);
	printf("Volume of a cylinder: volume_cylinder = PI * radius^2 * height = %f * %f^2 * %f = %.2f\n", PI, radius, height, calculate_volume_cylinder (radius, height));
	
	printf("----------------------------------------Equation 3-------------------------------------------------------\n");
	/*
	Character encoding: encoded_character = (plaintext_character - 'A') + 'a' + shift; shift is an integer (note: what happens
	if plaintext_character is uppercase? What happens with various shift keys?)
	*/
	printf("Please enter a plaintext <as a char> and shift <integer values> for use in Character encoding equation\n");
	printf("plaintext: ");
	scanf(" %c",&plaintext_character);
	printf("shift: ");
	scanf("%d", &shift);
	printf("Character encoding: encoded_character = (plaintext_character - 'A') + 'a' + shift = ('%c' - 'A') + 'a' + %d = '%c'\n", plaintext_character, shift, perform_character_encoding (plaintext_character, shift));

	printf("----------------------------------------Equation 4-------------------------------------------------------\n");
	/*
	Distance between two points: distance = square root of ((x1 - x2)2 + (y1 - y2)2) (note: you will need to use sqrt ( ) out
	of <math.h>)
	*/
	printf("Please enter two points (x1, y1) (x2, y2) <all floating-point values>> for use in a distance between two points equation\n");
	printf("x1: ");
	scanf("%lf",&x1);
	printf("y1: ");
	scanf("%lf",&y1);
	printf("x2: ");
	scanf("%lf",&x2);
	printf("y2: ");
	scanf("%lf",&y2);
	printf("Distance between two points: distence = square root of ((x1 - x2)^2 + (y1 - y2)^2) = sqrt(((%f - %f)^2 + (%f - %f)^2)) = %.2f\n",x1, x2, y1, y2, calculate_distance_between_2pts (x1, x2, y1, y2));

	
	printf("----------------------------------------Equation 5-------------------------------------------------------\n");
	/*
	Tangent: tan_theta = sin (theta) / cos (theta) (recall: find the appropriate functions in <math.h>)
	*/
	printf("Please enter a theta (degree) <floating-point values> for use in Trigonometric functions\n");
	printf("theta <degree> : ");
	scanf("%lf", &theta);
	printf("Tangent: tan_theta = sin (theta) / cos (theta) = %f / %f = %.2f\n", sin(theta * PI / 180), cos(theta * PI / 180), calculate_tangent_theta (theta));
	
	
	printf("----------------------------------------Equation 6-------------------------------------------------------\n");
	/*
	Equivalent parallel resistance: parallel_resistance = 1 / (1 / R1 + 1 / R2 + 1 / R3), for 3 resistors. R1, R2, and R3 
	are integers.
	*/
	printf("Please enter three resistance <all integers> for use in Equivalent parallel resistance\n");
	printf("R1: ");
	scanf("%d", &r1);
	printf("R2: ");
	scanf("%d", &r2);
	printf("R3: ");
	scanf("%d", &r3);
	printf("parallel_resistance = 1 / (1 / R1 + 1 / R2 + 1 / R3) = 1 / (1 / %d + 1 / %d + 1 / %d) = %.2f\n", r1, r2, r3, calculate_parallel_resistance (r1, r2, r3));

	
	printf("----------------------------------------Equation 7-------------------------------------------------------\n");
	/*
	General equation: y = (3 / 5) + b * z - x / (a % 2) + PI (recall: a is an integer; the 7 and 10 constants in the equation
	should be left as integers initially, but explicitly type-casted as floating-point values)
	*/
	printf("Please enter a <integer value>, b, x, and z <floating-point values> for use in general equation\n");
	printf("a: ");
	scanf("%d", &a);
	printf("b: ");
	scanf("%lf", &b);
	printf("x: ");
	scanf("%lf", &x);
	printf("z: ");
	scanf("%lf", &z);
	printf("General equation: y = (3 / 5) + b * z - x / (a % 2) + PI = (3 / 5) + %f * %f - %f / (%d %% 2) + %f = %.2f\n", b, z, x, a, PI, calculate_general_equation (a, b, x, z));

	return 0;
}