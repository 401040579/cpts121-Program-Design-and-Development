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
and some are obtained as fixed sequences of values.
(1) (5 pts) Print a game menu for Yahtzee with the following options:
            1. Print game rules
            2. Start a game of Yahtzee
            3. Exit
(2) (5 pts) Get a menu option from the user; clear the screen
(3) (10 pts) If option 1 is entered, then print the game rules stated above and repeat step (1)
     otherwise if option 2 is entered, then continue on to step (4); player 1 starts the game
     otherwise if option 3 is entered, then print a goodbye message and quit the program
     otherwise repeat step (1)
(4) (5 pts) Ask the player to hit any key to continue on to roll the five dice
(5) (10 pts) Roll the five dice and display the face values of each die; enumerate each die with
     a number 1 - 5; add 1 to the total number of rolls for this round
(6) (10 pts) If the total number of rolls for this round is less than three,
         then ask the player (Y/N) if he/she wants to use the roll for one of the game combinations
     otherwise a combination must be selected
            1. Sum of 1's        7. Three-of-a-kind
            2. Sum of 2's        8. Four-of-a-kind
            3. Sum of 3's        9. Full house
            4. Sum of 4's        10. Small straight
            5. Sum of 5's        11. Large straight
            6. Sum of 6's        12. Yahtzee
                        13. Chance
(7) (10 pts) If the number of rolls is three or "yes" is entered, then save the combination and it may not be selected again in the future;
         continue on to step (8); clear the screen
     otherwise if "no" is entered, ask the user which dice to re-roll (1 - 5); re-roll the selected die or dice; clear the screen;
         repeat step (6)
     otherwise repeat step (6)
(8) (5 pts) Alternate players
(9) (10 pts) If each player has rolled for the round, then increment the round number
         if the round number is equal to 14, then continue on to step (10)
         otherwise repeat step (4)
     otherwise repeat step (4)
(10) (5 pts) If the total score in the upper section is greater than or equal to 63 for a player, then add 35 points to the total score
(11) (5 pts) Print the scores for both players and print the winner
(12) (5 pts) Repeat step (1)
*******************************************************************************************/
#include "Header.h"

int main(){
	// definition some variable and four sets for player1 and player2
	int option = 0, count = 0, winner = 0;
	int dice[5] = {0};
	// -1 for easy to see which one you did not choose
	int combinations_scores_1[13] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	int combinations_used_1[13] = {0}; 
	int combinations_scores_2[13] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	int combinations_used_2[13] = {0}; 
	// get rand number
	srand ((unsigned int) time (NULL));
	//using do while loop.
	do{
		// print the menu.
		printf("1. Print game rules\n2. Start a game of Yahtzee\n3. Exit\n");
		scanf("%d", &option);
		system("cls");
		/* If option 1 is entered, then print the game rules stated above and repeat step (1)
     otherwise if option 2 is entered, then continue on to step (4); player 1 starts the game
     otherwise if option 3 is entered, then print a goodbye message and quit the program
     otherwise repeat step (1)*/
		switch (option)
		{
		case 1: {//print rules.
			print_Yahtzee_rules();
			system ("pause");
			system ("cls");
				}
				break;
			
		case 2: // main part!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

			do{  // set two player to play the game.
				printf("hit any key to continue on to roll the five dice\n");
				/*Ask the player to hit any key to continue on to roll the five dice*/
				system ("pause");
				roll_dice (dice, 5);
				display_dice (dice, 5);
				printf("-----player 1!!!-----\n");
				reroll_dice (dice, 5);
				printf("-----player 1!!!-----\n");
				select_combination(dice, combinations_scores_1, combinations_used_1);
				system ("cls");

				//Alternate players
				printf("hit any key to continue on to roll the five dice\n");
				/*Ask the player to hit any key to continue on to roll the five dice*/
				system ("pause");
				roll_dice (dice, 5);
				display_dice (dice, 5);
				printf("-----player 2!!!-----\n");
				reroll_dice (dice, 5);
				printf("-----player 2!!!-----\n");
				select_combination(dice, combinations_scores_2, combinations_used_2);
				system ("cls");
				count++; //If each player has rolled for the round, then increment the round number
			}while(count < 13);// run 13 times and end the loop
				if(total_score(combinations_scores_1) > total_score(combinations_scores_2)) winner = 1;
				else winner = 2;
				/*Print the scores for both players and print the winner*/
				printf("player1: %d\nplayer2: %d\nwinner: %d\n\n",total_score(combinations_scores_1),
					total_score(combinations_scores_2), winner);
				system ("pause");
				system ("cls");
				break;
		default: 
			break;
		}
		if(!(option == 1||option == 2||option == 3)) printf("Plz, enter num in rang 1-3\n");
	}while(option != 3);
	printf("bye! Happy to see you again!\n");
	system ("pause");
	return 0;
}
