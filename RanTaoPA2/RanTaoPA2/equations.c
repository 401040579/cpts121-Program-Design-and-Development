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
/*************************************************************
 * Function: calculate_newtons_2nd_law (double mass, double acceleration) *
 * Date Created:9/14/2015		                             *
 * Date Last Modified:  9/14/2015                            *
 * Description:Newton¡¯s Second Law of Motion:				 *
 * force = mass * acceleration                               *
 * Input parameters:mass and acceleration                    *
 * Returns:	force		                                     *
 * Preconditions: The mass and acceleration had to have been *
 * read in already.                                          *
 * Postconditions: The force is returned.                    *
 *************************************************************/
double calculate_newtons_2nd_law (double mass, double acceleration)
{
	//Newton¡¯s Second Law of Motion: force = mass * acceleration
	double force = mass * acceleration;
	return force;
}
/*************************************************************
 * Function: calculate_volume_cylinder (double radius, double height)                                
 * Date Created:9/14/2015		                             *
 * Date Last Modified:  9/14/2015                            *
 * Description:Volume of a cylinder			             	 *
 *  volume_cylinder = PI * radius2 * height                  *
 * Input parameters: radius and height				         *
 * Returns:volume_cylinder		                             *
 * Preconditions: The radius and height had to have been	 *
 * read in already.                                          *
 * Postconditions: The volume of cylinder is returned.       *
 *************************************************************/
double calculate_volume_cylinder (double radius, double height)
{
	//Volume of a cylinder: volume_cylinder = PI * radius2 * height
	double volume_cylinder =  PI * radius * radius * height;
	return volume_cylinder;
}
/*************************************************************
 * Function: perform_character_encoding (char plaintext_character, int shift)   *                            
 * Date Created:9/14/2015														*
 * Date Last Modified:  9/14/2015												*
 * Description: Character encoding												*
 *  encoded_character = (plaintext_character - 'A') + 'a' + shift               *
 * Input parameters: plaintext_character and shift								*
 * Returns:encoded_character													*		                                        
 * Preconditions: The plaintext_character and shift had to have been			*
 * read in already.																*
 * Postconditions: The encoded_character is returned.							*
 *************************************************************/
char perform_character_encoding (char plaintext_character, int shift)
{
	//Character encoding: encoded_character = (plaintext_character - 'A') + 'a' + shift; 
	//shift is an integer (note: what happens if plaintext_character is uppercase? What 
	//happens with various shift keys?)
	char encoded_character = (plaintext_character - 'A') + 'a' + shift;
	return encoded_character;
}
/*************************************************************
 * Function: calculate_distance_between_2pts (double x1, double x2, double y1, double y2)                        *
 * Date Created:9/14/2015		                             *
 * Date Last Modified:  9/14/2015                            *
 * Description: Distance between two points					 *
 *   distance = square root of ((x1 - x2)2 + (y1 - y2)2)     *
 * Input parameters: x1,x2,y1,y2							 *
 * Returns:distance		                                     *
 * Preconditions: The x1,x2,y1,y2 had to have been			 *
 * read in already.                                          *
 * Postconditions: The distance is returned.                 *
 *************************************************************/
double calculate_distance_between_2pts (double x1, double x2, double y1, double y2)
{
	//Distance between two points: distance = square root of ((x1 - x2)2 + (y1 - y2)2)
	//(note: you will need to use sqrt ( ) out of <math.h>)
	double distance = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	return distance;
}
/*************************************************************
 * Function: calculate_tangent_theta (double theta)          *
 * Date Created:9/14/2015		                             *
 * Date Last Modified:  9/14/2015                            *
 * Description: Tangent										 *
 *  tan_theta = sin (theta) / cos (theta)                    *
 * Input parameters: theta									 *
 * Returns:tan		                                         *
 * Preconditions: The theta had to have been				 *
 * read in already.                                          *
 * Postconditions: The tan is returned.						 *
 *************************************************************/
double calculate_tangent_theta (double theta)
{
	//Tangent: tan_theta = sin (theta) / cos (theta) (recall: find the appropriate functions in <math.h>)
	double tan = sin(theta * PI / ANGLE)/cos(theta * PI / ANGLE);
	return tan;
}
/*************************************************************
 * Function: calculate_parallel_resistance (int r1, int r2, int r3)                       
 * Date Created:9/14/2015		                             *
 * Date Last Modified:  9/14/2015                            *
 * Description: Equivalent parallel resistance				 *
 *  parallel_resistance = 1 / (1 / R1 + 1 / R2 + 1 / R3), for 3 resistors.                       
 * Input parameters: r1,r2,r3								 *
 * Returns:parallel_resistance		                         *
 * Preconditions: The r1,r2 and r3 had to have been			 *
 * read in already.                                          *
 * Postconditions: The parallel_resistance is returned.      *
 *************************************************************/
double calculate_parallel_resistance (int r1, int r2, int r3)
{
	//Equivalent parallel resistance: parallel_resistance = 1 / (1 / R1 + 1 / R2 + 1 / R3), for 3 resistors. 
	//R1, R2, and R3 are integers.
	double parallel_resistance = ONE / (ONE / (double)r1 + ONE / (double)r2 + ONE / (double)r3);
	return parallel_resistance;
}
/*************************************************************
 * Function: calculate_general_equation (int a, double b, double x, double z)                      
 * Date Created:9/14/2015		                             *
 * Date Last Modified:  9/14/2015                            *
 * Description: General equation							 *
 * y = (3 / 5) + b * z - x / (a % 2) + PI                    *
 * Input parameters: a,b,x,z							     *
 * Returns:engEquation		                                 *
 * Preconditions: The a,b,x,z had to have been				 *
 * read in already.                                          *
 * Postconditions: The engEquation is returned.              *
 *************************************************************/
double calculate_general_equation (int a, double b, double x, double z)
{
	//General equation: y = (3 / 5) + b * z - x / (a % 2) + PI (recall: 
	//a is an integer; the 3 and 5 constants in the equation should be left as integers initially, 
	//but explicitly type-casted as floating-point values)
	double engEquation =  ((double)THREE / (double)FIVE) + b * z - x / (a % TWO) + PI;
	return engEquation;
}