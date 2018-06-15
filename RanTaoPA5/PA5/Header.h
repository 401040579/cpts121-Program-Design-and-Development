/*******************************************************************************************
* Programmer: Ran Tao                                                                       
* Class: CptS 121, Fall  2015																
* Programming Assignment: PA 5                                                              
* Date: OCT 19, 2015                                                                         
* Description:Develop and implement an interactive two-player Yahtzee game. Yahtzee is a dice 
game that was invented by Milton Bradley and Edwin S. Lowe in 1956. The challenge of the game 
is to outduel the other player by scoring the most points. Points are obtained by rolling five 
6-sided die across thirteen rounds. During each round, each player may roll the dice up to three 
times to make one of the possible scoring combinations. Once a combination has been achieved by 
the player, it may not be used again in future rounds, except for the Yahtzee combination may be
used as many times as the player makes the combination. Each scoring combination has different
point totals. Some of these totals are achieved through the accumulation of points across rolls
and some are obtained as fixed sequences of values.															*
*******************************************************************************************/
#ifndef PA5
#define PA5

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Print a game menu for Yahtzee with the following options:
1. Print game rules
2. Start a game of Yahtzee
3. Exit*/
void print_Yahtzee_rules();

/*roll dice, display dice, and reroll dice*/
void roll_dice (int dice_values[5], int num_items);
void display_dice (int dice_values[5], int num_items);
// void roll_dice (int *dice_values, int num_items);
void reroll_dice (int dice_values[5], int num_items);
//get combination and select 
/*
1. Sum of 1's        7. Three-of-a-kind
2. Sum of 2's        8. Four-of-a-kind
3. Sum of 3's        9. Full house
4. Sum of 4's        10. Small straight
5. Sum of 5's        11. Large straight
6. Sum of 6's        12. Yahtzee
13. Chance*/
void select_combination (int dice_values[5], int scores[13], int comb_used[13]);
//e.g. you got 1 2 2 3 4 4
//set will be {1,2,1,2,0,0} count the number of the numbers.
void populate_num_dice (int dice_values[5], int num_values[6]);
/*show total score and If the sum of the scores in the upper section is 
greater than or equal to 63, then 35 more points are added to the players
overall score as a bonus.*/
int total_score (int scores[13]);
#endif