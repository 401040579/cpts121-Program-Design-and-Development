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
#include "Header.h"
/*************************************************************
 * Function:  print_Yahtzee_rules() *
 * Date Created:10/19/2015		                             *
 * Date Last Modified:  10/20/2015                            *
 * Description:print game rules                              *
 * Input parameters:NONE				                     *
 * Returns:	Yahtzee game rules			                     *
 *************************************************************/
void print_Yahtzee_rules()
{
	printf("--------------------------------------Yahtzee rules---------------------------------------\n");
	printf("The scorecard used for Yahtzee is composed of two sections. A upper section and a lower section. A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections. The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box. If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12. Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds. If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus. The lower section contains a number of poker like combinations.\n");
	printf("\nThree-of-a-kind: Three dice with the same face->Sum of all face values on the 5 dice\n");
	printf("Four-of-a-kind: Four dice with the same face->Sum of all face values on the 5 dice\n");
	printf("Full house: One pair and a three-of-a-kind->25\n");
	printf("Small straight: A sequence of four dice->30\n");
	printf("Large straight: A sequence of five dice->40\n");
	printf("Yahtzee (think five-of-a-kind): Five dice with the same face->50\n");
	printf("Chance: May be used for any sequence of dice; this is the catch all combination->Sum of all face values on the 5 dice\n");
	printf("--------------------------------------Yahtzee rules---------------------------------------\n");
}
/*************************************************************
 * Function:  roll_dice(int dice_values[5], int num_items) 
 * Date Created:10/19/2015		                             
 * Date Last Modified:  10/20/2015                            
 * Description:roll the dice                            
 * Input parameters:dice_values[5] num_items		                     
 *************************************************************/
void roll_dice (int dice_values[5], int num_items)//Roll the five dice and display the face values of each die; enumerate each die with a number 1 - 5
{
	int index = 0;

	for (index = 0; index < num_items; ++index)
	{
		dice_values[index] = rand () % 6 + 1;
	}
}
/*************************************************************
 * Function:  display_dice (int dice_values[5], int num_items) 
 * Date Created:10/19/2015		                             
 * Date Last Modified:  10/20/2015                            
 * Description:display the dice                            
 * Input parameters:dice_values[5] num_items	            
 *************************************************************/
void display_dice (int dice_values[5], int num_items)
{
	int index = 0;

	while (index < num_items)
	{
		printf ("dice[%d]: %d\n",
			index+1, dice_values[index]);

		index++;
	}
}
/*************************************************************
 * Function:  reroll_dice (int dice_values[5], int num_items) 
 * Date Created:10/19/2015		                             
 * Date Last Modified:  10/20/2015                            
 * Description:reroll 5 dices                           
 * Input parameters:dice_values[5] num_items			            
 *************************************************************/
void reroll_dice (int dice_values[5], int num_items)
{
	int num_reroll = 0, position = 0, count = 0, count_less_than_3 = 0;
	do{
		do{//must in range 0 - 5 (only have 5 dice)(0 for no reroll)
			// then ask the player (Y/N) if he/she wants to use the roll for one of the game combinations
			printf ("How many dice would you like to reroll?(0 for using the roll for one of the game combinations): ");
			scanf ("%d", &num_reroll);
			if(!(num_reroll == 0||num_reroll == 1||num_reroll == 2||num_reroll == 3||num_reroll == 4||num_reroll == 5)) printf("must be in range 0 - 5\n");
		}while(!(num_reroll == 0||num_reroll == 1||num_reroll == 2||num_reroll == 3||num_reroll == 4||num_reroll == 5));

		for (count = 0; count < num_reroll; count++)
		{
			do{
				printf ("Which die would you like to reroll (position number): ");
				scanf ("%d", &position);
				if((!(position == 1||position == 2||position == 3||position == 4||position == 5))) printf("must be in range 1-5\n");
			}while(!(position == 1||position == 2||position == 3||position == 4||position == 5));
			dice_values[position - 1] = rand () % 6 + 1; // opportunity call roll_die () function
		}
		system ("cls");
		display_dice(dice_values, num_items);
		count_less_than_3++;/*add 1 to the total number of rolls for this round*/
	}while(count_less_than_3 < 2 && num_reroll != 0);
}
/*************************************************************
 * Function:  select_combination (int dice_values[5], int scores[13],
						 int comb_used[13]) 
 * Date Created:10/19/2015		                             
 * Date Last Modified:  10/20/2015                            
 * Description:select the 1-13 combinations
1. Sum of 1's        7. Three-of-a-kind
2. Sum of 2's        8. Four-of-a-kind
3. Sum of 3's        9. Full house
4. Sum of 4's        10. Small straight
5. Sum of 5's        11. Large straight
6. Sum of 6's        12. Yahtzee
13. Chance
 * Input parameters: int dice_values[5], int scores[13],
						 int comb_used[13]		         			            
 *************************************************************/
void select_combination (int dice_values[5], int scores[13],
						 int comb_used[13])
{
	int option = 0, check_flag = 0, num_values[6] = {0};
	printf("The number -1 is unused\n"
		"1. Sum of 1's: %d. 7. Three-of-a-kind: %d. \n"
		"2. Sum of 2's: %d. 8. Four-of-a-kind:  %d. \n"
		"3. Sum of 3's: %d. 9. Full house:      %d. \n"
		"4. Sum of 4's: %d. 10. Small straight: %d. \n"
		"5. Sum of 5's: %d. 11. Large straight: %d. \n"
		"6. Sum of 6's: %d. 12. Yahtzee:        %d. \n"
		"13. Chance:    %d. \n", scores[0], scores[6], scores[1], scores[7], scores[2],
		scores[8], scores[3], scores[9], scores[4], scores[10],
		scores[5], scores[11], scores[12]);
	//populate_num_dice (dice_values, num_values);
	do
	{
		check_flag = 0;
		do{//must in range 1-13
			printf ("Enter the combination you would like to use: ");
			scanf ("%d", &option); // option 1 - 13
			if(!(option == 1||option == 2||option == 3||option == 4||option == 5||
				option == 6||option == 7||option == 8||option == 9||option == 10||
				option == 11||option == 12||option == 13)) 
				printf("must be in range 1-13\n");

			/*if(option == 7)
			{
			int index = 0;
			int t_or_f = 0;
			for( ; index < 6; index++)
			{
			if(num_values[index] >= 3)
			t_or_f = 1;
			}
			if(t_or_f != 1)
			{
			printf("wrong combination!\n");
			option = 0;
			}
			}
			if(option == 8)
			{
			int index = 0;
			int t_or_f = 0;
			for( ; index < 6; index++)
			{
			if(num_values[index] >= 4)
			t_or_f = 1;
			}
			if(t_or_f != 1)
			{
			printf("wrong combination!\n");
			option = 0;
			}
			}
			if(option == 9)
			{
			int index = 0, t_or_f_2 = 0, t_or_f_3 = 0;
			for( ; index < 6; index++)
			{
			if(num_values[index] == 3)
			t_or_f_3 = 1;
			if(num_values[index] == 2)
			t_or_f_2 = 1;
			}
			if(!(t_or_f_3 == 1 && t_or_f_2 == 1))
			{
			printf("wrong combination!\n");
			option = 0;
			}
			}
			if(option == 10)
			{
			int index = 0, count = 0;
			for(; index < 6; index++)
			{
			if(num_values[index] >= 1)
			{
			count++;
			}

			}
			if(count<4)
			{
			printf("wrong combination!\n");
			option = 0;
			}	
			}
			if(option == 11)
			{
			int index = 0, count = 0;
			for(; index < 6; index++)
			{
			if(num_values[index] >= 1)
			{
			count++;
			}

			}
			if(count<5)
			{
			printf("wrong combination!\n");
			option = 0;
			}	
			}
			if(option == 12)
			{
			int index = 0;
			int t_or_f = 0;
			for( ; index < 6; index++)
			{
			if(num_values[index] == 5)
			t_or_f = 1;
			}
			if(t_or_f != 1)
			{
			printf("wrong combination!\n");
			option = 0;
			}
			}*/
		}while(!(option == 1||option == 2||option == 3||option == 4||option == 5||option == 6||option == 7||option == 8||option == 9||option == 10||option == 11||option == 12||option == 13));
		if (comb_used[option - 1] == 1)//If the number of rolls is three or "yes" is entered, then save the combination and it may not be selected again in the future
		{
			// combination has been used before
			check_flag = 1;
			printf("Combination has been used before.\n");
		}
	} while (check_flag);

	// selected a valid combination to use
	comb_used[option - 1] = 1; // now combination has been used
	populate_num_dice (dice_values, num_values);

	switch (option)	
	{
	case 1: scores[0] = num_values[0]; // contains the number of ones
		break;
	case 2: scores[1] = num_values[1]*2; // contains the number of ones
		break;
	case 3: scores[2] = num_values[2]*3; // contains the number of ones
		break;
	case 4: scores[3] = num_values[3]*4; // contains the number of ones
		break;
	case 5: scores[4] = num_values[4]*5; // contains the number of ones
		break;
	case 6: scores[5] = num_values[5]*6; // contains the number of ones
		break;
	case 7:
		/* to decide the the set have more than three same value*/
		{
			int index = 0;
			int t_or_f = 0;
			for( ; index < 6; index++)
			{
				if(num_values[index] >= 3)
					t_or_f = 1;
			}
			if(t_or_f != 1)
			{
				printf("wrong combination!\nGot 0 Point!\n");
				system("pause");
				scores[6] = 0;
			}else
			{
				scores[6] = num_values[0] + num_values[1]*2 + num_values[2]*3 + num_values[3]*4 + num_values[4]*5 + num_values[5]*6; // contains the number of ones
			}
		}
		break;
	case 8:
		/* to decide the the set have more than four same value*/
		{int index = 0;
		int t_or_f = 0;
		for( ; index < 6; index++)
		{
			if(num_values[index] >= 4)
				t_or_f = 1;
		}

		if(t_or_f != 1)
		{
			printf("wrong combination!\nGot 0 Point!\n");
			system("pause");
			scores[7] = 0;
		}
		else
		{
			scores[7] = num_values[0] + num_values[1]*2 + num_values[2]*3 + num_values[3]*4 + num_values[4]*5 + num_values[5]*6; // contains the number of ones
		}
		}
		break;
	case 9: {
		/* to decide the the set have One pair and a three-of-a-kind*/
		int index = 0, t_or_f_2 = 0, t_or_f_3 = 0;
		for( ; index < 6; index++)
		{
			if(num_values[index] == 3)
				t_or_f_3 = 1;
			if(num_values[index] == 2)
				t_or_f_2 = 1;
		}
		if(!(t_or_f_3 == 1 && t_or_f_2 == 1))
		{
			printf("wrong combination!\nGot 0 Point!\n");
			system("pause");
			scores[8] = 0;
		}else{
			scores[8] = 25; // contains the number of ones}
		}
			}
			break;
	case 10: {
		/* to decide the the set have A sequence of four*/
		int index = 0, t_or_f = 0;
		for(; index < 3; index++)
		{
			if(num_values[index] >= 1)
			{
				if(num_values[index+1] >= 1)
				{
					if(num_values[index+2] >= 1)
					{
						if(num_values[index+3] >= 1)
						{
							t_or_f = 1;
						}
					}

				}
			}
		}
		if(t_or_f == 0)
		{
			printf("wrong combination!\nGot 0 Point!\n");
			system("pause");
			scores[9] = 0;
		}else
		{
			scores[9] = 30;
		} // contains the number of ones
			 }
			 break;
	case 11:{
		/* to decide the the set have A sequence of five*/
		int index = 0, t_or_f = 0;
		for(; index < 2; index++)
		{
			if(num_values[index] >= 1)
			{
				if(num_values[index+1] >= 1)
				{
					if(num_values[index+2] >= 1)
					{
						if(num_values[index+3] >= 1)
						{
							if(num_values[index+4] >= 1)
							{
								t_or_f = 1;
							}
						}
					}

				}
			}
		}
		if(t_or_f == 0)
		{
			printf("wrong combination!\nGot 0 Point!\n");
			system("pause");
			scores[10] = 0;
		}else
		{
			scores[10] = 40;
		}
		// contains the number of ones
			}break;
	case 12: {
		/* to decide the the set have Five dice with the same face*/
		int index = 0;
		int t_or_f = 0;
		for( ; index < 6; index++)
		{
			if(num_values[index] == 5)
				t_or_f = 1;
		}
		if(t_or_f != 1)
		{printf("wrong combination!\nGot 0 Point!\n");
		system("pause");
		scores[11] = 0;
		}else
		{
			scores[11] = 50;
		}// contains the number of ones
			 }break;
	case 13: scores[12] = num_values[0] + num_values[1]*2 + num_values[2]*3 + num_values[3]*4 + num_values[4]*5 + num_values[5]*6; // contains the number of ones
		break;/*May be used for any sequence of dice; this is the catch all combination*/
	default:
		break;
	}
}

/*************************************************************
 * Function:  populate_num_dice (int dice_values[5], int num_items) 
 * Date Created:10/19/2015		                             
 * Date Last Modified:  10/20/2015                            
 * Description: show total score and If the sum of the scores in the upper section is 
greater than or equal to 63, then 35 more points are added to the players
overall score as a bonus.                         
 * Input parameters:dice_values[5] num_items			            
 *************************************************************/
void populate_num_dice (int dice_values[5], int num_values[6])
{
	int index = 0;

	for (; index < 5; index++)
	{
		num_values[dice_values[index] - 1]++;
	}
}
/*************************************************************
 * Function:  total_score (int scores[13])
 * Date Created:10/19/2015		                             
 * Date Last Modified:  10/20/2015                            
 * Description: cal the total score!                 
 * Input parameters: scores[13]	
 * return total scores.
 *************************************************************/
int total_score (int scores[13])
{
	int total_scores = 0;
	if((scores[0] + scores[1] + scores[2] + scores[3] + scores[4] + scores[5])>=63)
	{
		total_scores = 35 + total_scores;
	}
	total_scores = scores[0] + scores[1] + scores[2] + scores[3] + scores[4] + scores[5] + 
		scores[6] + scores[7] + scores[8] + scores[9] + scores[10] + scores[11] + scores[12] +
		total_scores;
	return total_scores;

}