/*******************************************************************************************
* Programmer: Ran Tao                                                                       
* Class: CptS 121, Fall  2015																
* Programming Assignment: PA 7
* Date: Nov 30, 2015                                                                         
* Description:Mathematics is one of the most important, yet most difficult, subjects to teach
and learn. We have all heard of the saying "Practice makes perfect". Well I'm a huge believer
in this saying and would like a software program which can generate various arithmetic 
problems and evaluate answers supplied by the user.									
*******************************************************************************************/
#ifndef RANTAOPA7
#define RANTAOPA7

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS

void welcome_info(char str[], int *score, FILE *outfile, char record[][4]);
	void how_to_use_program ();
	void your_initials(char str[]);
	int difficulty_selection();
	void new_seqience_of_problems(int level, int *score);
	void save(char str[], int *score, FILE *outfile, char record[][4], int *i);
void Level_1(int *score);
void Level_2(int *score);
void Level_3(int *score);
void Level_4(int *score);
void Level_5(int *score);

void addition_oneTerm(int *num1, int *num2, int *correct, int *incorrect);
void subtraction_oneTerm(int *num1, int *num2, int *correct, int *incorrect);
void addition_and_subtraction_twoTerms(int *num1, int *num2, int *num3, int *correct, int *incorrect);
void multiplication_oneTerm(int *num1, int *num2, int *correct, int *incorrect);
void division_oneTerm(int *num1, int *num2, int *correct, int *incorrect);
void mix_single_digit(int *num1, int *num2, int *num3, int *correct, int *incorrect);
void mix_multiple_digit(int *num1, int *num2, int *num3, int *num4, int *correct, int *incorrect);

//bouns
void load_previous_progress(char record[][4], int *count, char str[], int *score); //void read_line (FILE *infile, char *line, int size);
void help();
void others_fun_questions();

#endif