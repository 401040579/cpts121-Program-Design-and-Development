/*******************************************************************************************
* Programmer: Ran Tao                                                                       *
* Class: CptS 121, Fall  2015																*
* Programming Assignment: PA 4                                                              *
* Date: OCT 3, 2015                                                                         *
* Description:The following description has been adopted from Deitel & Deitel. One of the	*
most popular games of chance is a dice game called "craps," which is played in casinos and	*
back alleys throughout the world. 															*
*******************************************************************************************/
#include "Header.h"
/*************************************************************
 * Function: print_game_rules (void) *
 * Date Created:10/3/2015		                             *
 * Date Last Modified:  10/3/2015                            *
 * Description:print game rules                              *
 * Input parameters:NONE				                     *
 * Returns:	craps game rules			                     *
 *************************************************************/
void print_game_rules (void){
	printf("****************************Game Rules****************************\n");
	printf("If the sum is 7 or 11 on the first throw, the player wins.\nIf the sum is 2, 3, or 12 on the first throw (called ""craps""),\nthe player loses (i.e. the ""house"" wins).\nIf the sum is 4, 5, 6, 8, 9, or 10 on the first throw,\nthen the sum becomes the player's ""point."" To win,\nyou must continue rolling the dice until you ""make your point.""\nThe player loses by rolling a 7 before making the point.\n");
	printf("******************************************************************\n");
}// ¡ª Prints out the rules of the game of "craps".
/*************************************************************
 * Function: get_bank_balance (void)						 *
 * Date Created:10/3/2015		                             *
 * Date Last Modified:  10/3/2015                            *
 * Description:get bank balance                              *
 * Input parameters:NONE				                     *
 * Returns:	banBalance										 *
 *************************************************************/
double get_bank_balance (void){
	double bankBalance = 0.0;
	printf("set your bank balance: ");
	scanf("%lf", &bankBalance);
	return bankBalance;
}// - Prompts the player for an initial bank balance from which wagering will be added or subtracted. The player entered bank balance (in dollars, i.e. $100.00) is returned.
/*************************************************************
 * Function: get_wager_amount (void)						 *
 * Date Created:10/3/2015		                             *
 * Date Last Modified:  10/3/2015                            *
 * Description:get wager balance                             *
 * Input parameters:NONE				                     *
 * Returns:	wagerAmount										 *
 *************************************************************/
double get_wager_amount (void){
	double wagerAmount = 0.0;
	printf("set your wager: ");
	scanf("%lf", &wagerAmount);
	return wagerAmount;
}// - Prompts the player for a wager on a particular roll. The wager is returned.
/*************************************************************
 * Function:check_wager_amount(double wager, double balance) *
 * Date Created:10/3/2015		                             *
 * Date Last Modified:  10/3/2015                            *
 * Description:Checks to see if the wager is within			 *
 * the limits of the player's available balance.             *
 * Input parameters:wager and balance			             *
 * Returns:	0 or 1											 *
 *************************************************************/
int check_wager_amount (double wager, double balance){
	if(wager>balance){
		return 0;
	}else{
		return 1;
	}
}// - Checks to see if the wager is within the limits of the player's available balance. If the wager exceeds the player's allowable balance, then 0 is returned; otherwise 1 is returned.
/*************************************************************
 * Function: roll_die (void)								 *
 * Date Created:10/3/2015		                             *
 * Date Last Modified:  10/3/2015                            *
 * Description:Rolls one die	                             *
 * Input parameters:NONE				                     *
 * Returns:	die_value										 *
 *************************************************************/
int roll_die (void){
	int die_value = 0;
	die_value = rand() %6 + 1;
	return die_value;
}// - Rolls one die. This function should randomly generate a value between 1 and 6, inclusively. Returns the value of the die.
/*************************************************************
 * Function:calculate_sum_dice (int die1_value, int die2_value)*
 * Date Created:10/3/2015		                             *
 * Date Last Modified:  10/3/2015                            *
 * Description:Sums together the values of the two dice and  *
 * returns the result.										 *
 * Input parameters:die_value and die2_value	             *
 * Returns:	sum of them										 *
 *************************************************************/
int calculate_sum_dice (int die1_value, int die2_value){
	return die1_value + die2_value;
}// - Sums together the values of the two dice and returns the result. Note: this result may become the player's point in future rolls.
/*************************************************************
 * Function:is_win_loss_or_point (int sum_dice)				 *
 * Date Created:10/3/2015		                             *
 * Date Last Modified:  10/3/2015                            *
 * Description:Determines the result of the first dice roll. *
 * returns the result.										 *
 * Input parameters:sum_dice					             *
 * Returns:	1 or 0 or -1									 *
 *************************************************************/
int is_win_loss_or_point (int sum_dice){
	if (sum_dice == 7 || sum_dice == 11){
		return 1;
	}else if (sum_dice == 2 ||sum_dice == 3 ||sum_dice == 12){
		return 0;
	}else{
		return -1;
	}
}// - Determines the result of the first dice roll. If the sum is 7 or 11 on the roll, the player wins and 1 is returned. If the sum is 2, 3, or 12 on the first throw (called "craps"), the player loses (i.e. the "house" wins) and 0 is returned. If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's "point" and -1 is returned.
/*************************************************************
 * Function:is_point_loss_or_neither (int sum_dice, int point_value)*
 * Date Created:10/3/2015		                             *
 * Date Last Modified:  10/3/2015                            *
 * Description: Determines the result of any successive roll *
 * after the first roll.									 *
 * Input parameters:sum_dice and point_value	             *
 * Returns:	1 or 0 or -1									 *
 *************************************************************/
int is_point_loss_or_neither (int sum_dice, int point_value){
	if(sum_dice == point_value){
		return 1;
	}else if(sum_dice == 7){
		return 0;
	}else{
		return -1;
	}
}// - Determines the result of any successive roll after the first roll. If the sum of the roll is the point_value, then 1 is returned. If the sum of the roll is a 7, then 0 is returned. Otherwise, -1 is returned.
/*************************************************************
 * Function:adjust_bank_balance (double bank_balance, double wager_amount, int add_or_subtract)*
 * Date Created:10/3/2015		                             *
 * Date Last Modified:  10/3/2015                            *
 * Description: Determines the result of any successive roll *
 * after the first roll.									 *
 * Input parameters:bank_balance, wager_amount and			 *
 * add_or_subtract											 *
 * Returns:	changed bank_balance							 *
 *************************************************************/
double adjust_bank_balance (double bank_balance, double wager_amount, int add_or_subtract){
	if(add_or_subtract == 1){
		return bank_balance = bank_balance + wager_amount;
	}else if(add_or_subtract == 0){
		return bank_balance = bank_balance - wager_amount;
	}else{
		return bank_balance;
	}
}// - If add_or_subtract is 1, then the wager amount is added to the bank_balance. If add_or_subtract is 0, then the wager amount is subtracted from the bank_balance. Otherwise, the bank_balance remains the same. The bank_balance result is returned.
/*************************************************************
 * Function:chatter_messages (int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance)*
 * Date Created:10/3/2015		                             *
 * Date Last Modified:  10/3/2015                            *
 * Description: Prints an appropriate message dependent on   *
 * the number of rolls taken so far							 *
 * Input parameters:number_rolls, win_loss_neither,			 *
 * initial_bank_balance	and current_bank_balance			 *
 * Returns:	sentence										 *
 *************************************************************/
void chatter_messages (int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance){
	if(number_rolls == 10) printf("you rolled 10 times!!\n");
	else if(number_rolls == 20) printf("time to rest!!\n");
	else if(number_rolls == 40) printf("still have money? you are rich!!\n");
	if(win_loss_neither == 1){
		printf("Win!\n");
	}else if(win_loss_neither == 0){
		printf("craps\n");
	}else{
		printf("Aw cmon, take a chance!");
	}
	if(current_bank_balance == 0){
		printf("Sorry, you busted!\n");
	}else if(current_bank_balance <= initial_bank_balance / 10){
		printf("Oh, you're going for broke, huh?\n");
	}
	if(initial_bank_balance <= current_bank_balance / 2){
		printf("You're up big, now's the time to cash in your chips!\n");
		//printf("initial_bank_balance: %.lf.current_bank_balance: %.lf", initial_bank_balance, current_bank_balance);
	}

	/*if(number_rolls == 2){
		printf("Ha, got 2\n");
	}else if(number_rolls == 3){
		printf("3, :(\n");
	}else if(number_rolls == 4){
		printf("4 =.=\n");
	}else if(number_rolls == 5){
		printf("5 -.-\n");
	}else if(number_rolls == 6){
		printf("sixxxx\n");
	}else if(number_rolls == 7){
		printf("7 is here\n");
	}else if(number_rolls == 8){
		printf("got 8!\n");
	}else if(number_rolls == 9){
		printf("9!!!\n");
	}else if(number_rolls == 10){
		printf("Hi, 10\n");
	}else if(number_rolls == 11){
		printf("11!\n");
	}else{
		printf("12, :(\n");
	}*/

}// - Prints an appropriate message dependent on the number of rolls taken so far by the player, the current balance, and whether or not the player just won his roll. The parameter win_loss_neither indicates the result of the previous roll.
/*************************************************************
 * Function:others_buy_something (double current_bank_balance)*
 * Date Created:10/3/2015		                             *
 * Date Last Modified:  10/3/2015                            *
 * Description:  ask user to buy something after gamble		 *
 * Input parameters: current_bank_balance					 *
 * print out: items											 *
 *************************************************************/
void others_buy_something (double current_bank_balance){// others for 10pt. ask user to buy something after gamble.
	int something = 0, Lamborghini = 0, Chevrolet = 0, helicopter = 0, ice_cream = 0;
	printf("wanna buy something before you leave?\n1, Lamborghini: $500,000.00\n2, Chevrolet: $400,000.00\n3, helicopter: $5,000,000.00\n4, ice cream: $2\n5, just go\n");
	do{
		printf("buy: ");
		scanf("%d", &something);
		switch (something)
		{
		case 1: if(current_bank_balance>500000){
				current_bank_balance = current_bank_balance-500000;
				Lamborghini++;
				}else{
					printf("Money Not Enough\n");
				}break;
		case 2: if(current_bank_balance>400000){
					current_bank_balance = current_bank_balance-400000;
					Chevrolet++;
				}else{
					printf("Money Not Enough\n");
				}break;
		case 3: if(current_bank_balance>5000000){
					current_bank_balance = current_bank_balance-5000000;
					helicopter++;
				}else{
					printf("Money Not Enough\n");
				}break;
		case 4: if(current_bank_balance>2){
					current_bank_balance = current_bank_balance-2;
					ice_cream++;
				}else{
					printf("Money Not Enough\n");
				}break;
		//case 5: printf("bye!\n");
		default:
			break;
		}
		printf("current bank balance: %.2lf\nAnd you have %d Lamborghini, %d Chevrolet, %d helicopter, and %d ice_cream\n", current_bank_balance, Lamborghini, Chevrolet, helicopter, ice_cream);
	}while(something != 5);
	printf("Bye! Have a good day!\n");
}