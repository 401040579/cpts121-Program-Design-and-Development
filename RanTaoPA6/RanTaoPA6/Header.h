/*******************************************************************************************
* Programmer: Ran Tao                                                                       
* Class: CptS 121, Fall  2015																
* Programming Assignment: PA 6                                                              
* Date: Nov 13, 2015                                                                         
* Description:Write a program that simulates the game of Battleship. The game will be 
completely text-based (see Sample Execution). Battleship is a two player Navy game. The 
objective of the game is to sink all ships in your enemy's fleet. The Player to sink his/her
enemy's fleet first wins. Both players' fleets consist of 5 ships that are hidden from the 
enemy. Each ship may be differentiated by its "size" (besides the Cruiser and Submarine) or 
number of cells it expands on the game board. The Carrier has 5 cells, Battleship has 4 
cells, Cruiser has 3 cells, Submarine has 3 cells, and the Destroyer has 2 cells.												
*******************************************************************************************/
#ifndef BATTLESHIP_PA6_RANTAO
#define BATTLESHIP_PA6_RANTAO


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Stats
{
	int hits;
	int misses;
	int shots;
	double hit_miss_ratio;
	int win_loses;
}stats;

int welcome_screen(int *difficulty);

void initialize_game_board (char board[][10], int rows, int cols);

int select_who_starts_first(void);

void manually_place_ships_on_board(char board[][10]);

void manually_place_ships_on_board2(char board[][10]);

void randomly_place_ships_on_board(char board[][10]);

int check_shot(char board[][10], int row, int col, int *hit_or_miss, int *m_count, int *c_count, int *b_count, int *r_count, int *s_count, int *d_count);

void output_current_move(FILE *infile, int row, int col, int player, int *hit_or_miss, int *m_count, int *c_count, 
						 int *b_count, int *r_count, int *s_count, int *d_count, int *c1, int *b1, int *r1,int *s1,int *d1,int *c2, int *b2, int *r2,int *s2,int *d2);

void output_stats(FILE *infile, int player, int m_count, int c_count, int b_count, int r_count, int s_count, int d_count, stats players);

void print_board (char board[][10], int rows, int cols);

void print_player2_board (char board[][10], int rows, int cols);

int gen_direction (void);

void gen_start_pt (int length, int dir, int *row_start_ptr, int *col_start_ptr);

void easy_computer (char board[][10], int *target_row, int *target_col);

void normal_computer (char board[][10], int *target_row, int *target_col, int *used_row, int *used_col,
					  int *c,int *b,int *r,int *s,int *d,
					  int *run_c, int *run_b, int *run_r, int *run_s, int *run_d);

void hard_computer (char board[][10], int *target_row, int *target_col);

#endif