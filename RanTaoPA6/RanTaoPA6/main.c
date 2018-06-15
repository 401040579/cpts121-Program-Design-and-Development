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
#include "Header.h"

int main (void)
{
	//statement variables
	FILE *infile = NULL;
	char p1_board[10][10],p2_board[10][10];
	int m_count1 = 0, c_count1 = 0, b_count1 = 0, r_count1 = 0, s_count1 = 0, d_count1 = 0;
	int m_count2 = 0, c_count2 = 0, b_count2 = 0, r_count2 = 0, s_count2 = 0, d_count2 = 0;
	int c1=0,b1=0,r1=0,s1=0,d1=0,c2=0,b2=0,r2=0,s2=0,d2=0;
	int option = 0, num = 0, first_play = 0, target_row = 0, target_col = 0, used_row = 0, used_col = 0,
		c=0,b=0,r=0,s=0,d=0,run_c=0,run_b=0,run_r=0,run_s=0,run_d=0, target_row_1 = 0, target_col_1 = 0,
		hit_or_miss = 0, difficulty = 0;
	stats player1_stats = {0, 0, 0, 0.0, 0},
		player2_stats = {0, 0, 0, 0.0, 0};
	//randrom time
	srand((unsigned)time(NULL));
	//write file
	infile = fopen("battleship.log","w");
	//goin to function
	while(option != 3){
		option = welcome_screen(&difficulty);
		if(option == 2)
		{
			//initaialize the player1 and player2's boards
			initialize_game_board (p1_board, 10, 10);
			initialize_game_board (p2_board, 10, 10);
			do{
				printf("Please select from the following menu:\n1. Enter positions of ships manually(using direction and starting point).\n2. Enter positions of ships manually(using multiple cells)\n3. Allow the program to randomly select positions of ships.\n");
				scanf("%d", &num);
				if(num<1 || num>3){
					printf("wrong number, plz re-type\n");
					system("pause");
					system("cls");
				}
			}while(num<1 || num>3);

			system("cls");

			if(num == 1){
				//manually place ship(using starting point)
				manually_place_ships_on_board2(p1_board);
			}else if(num == 2){
				// using multiple cells
				manually_place_ships_on_board(p1_board);
			}else{
				//randomly
				randomly_place_ships_on_board(p1_board);
			}

			system("cls");

			randomly_place_ships_on_board(p2_board);
			printf("Player2(Computer's)board has been generated.\n");

			first_play = rand()%2 + 1;
			printf("Player%d has been randomly selected to go first.\n", first_play);

			system("pause");
			system("cls");

			do{
				if(first_play == 1){
					//when player1 be selected
					do{
						printf("Player1's Board:\n");
						print_board (p1_board, 10, 10);
						printf("Player2's Board:\n");
						print_player2_board (p2_board, 10, 10);
						printf("Enter a target: \n");
						scanf("%d%d", &target_row_1, &target_col_1);
						//check enter nums
						if(!((target_row_1>=0 && target_row_1 <=9)&&(target_col_1 >= 0 && target_col_1 <= 9))){
							printf("wrong enter, plz re-enter\n");		
							system("pause");
							system("cls");

						}
					}while(!((target_row_1>=0 && target_row_1 <=9)&&(target_col_1 >= 0 && target_col_1 <= 9)));//check enter nums
					// check_shot will return 1 if the shot is not valid
					first_play = check_shot(p2_board, target_row_1, target_col_1, &hit_or_miss, &m_count1, &c_count1, &b_count1, &r_count1, &s_count1, &d_count1);
					if(first_play != 1){//when check shot is valid, run output_current_move
						output_current_move(infile, target_row_1, target_col_1, 1, &hit_or_miss, &m_count1, &c_count1, &b_count1, &r_count1, &s_count1, &d_count1,
							&c1,&b1,&r1,&s1,&d1,&c2,&b2,&r2,&s2,&d2);
					}

					system("cls");
				}else{
					//choose difficulty
					if(difficulty == 1){
						easy_computer(p1_board, &target_row, &target_col);
					}else if(difficulty == 3){
						hard_computer(p1_board, &target_row, &target_col);
					}else{
						normal_computer(p1_board, &target_row, &target_col, &used_row, &used_col,
					  &c, &b, &r, &s, &d, &run_c,&run_b,&run_r,&run_s,&run_d);
					}
					printf("Player1's Board:\n");
					print_board (p1_board, 10, 10);
					printf("Player2's Board:\n");
					print_player2_board (p2_board, 10, 10);
					printf("Player2 selects: %d %d\n", target_row, target_col);
					//because player2 is computer we dont need to return check shot.
					check_shot(p1_board, target_row, target_col, &hit_or_miss, &m_count2, &c_count2, &b_count2, &r_count2, &s_count2, &d_count2);
					first_play = 1;//switch player to player1
					output_current_move(infile, target_row, target_col, 2, &hit_or_miss, &m_count2, &c_count2, &b_count2, &r_count2, &s_count2, &d_count2,
						&c1,&b1,&r1,&s1,&d1,&c2,&b2,&r2,&s2,&d2);
					system("cls");
				}
			}while(((c_count1 + b_count1 + r_count1 + s_count1 + d_count1) != 17) && ((c_count2 + b_count2 + r_count2 + s_count2 + d_count2) != 17));
			//when total count = 17 end game and print out the winner
			if((c_count1 + b_count1 + r_count1 + s_count1 + d_count1) == 17)
			{
				printf("Player%d Wins!\n", 1);
			}else{
				printf("Player%d Wins!\n", 2);
			}
			//output the stats using structure
			output_stats(infile, 1, m_count1, c_count1, b_count1, r_count1, s_count1, d_count1,player1_stats);
			output_stats(infile, 2, m_count2, c_count2, b_count2, r_count2, s_count2, d_count2,player2_stats);
			printf("Statistics outputted to logfile successfully!\n");
			system("pause");
			system("cls");
		}
	}

	fclose(infile);
	return 0;
}