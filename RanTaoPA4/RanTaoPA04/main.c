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

int main(void){
	/* defined all variable*/
	int die1_value = 0, die2_value = 0 , sum_dice = 0, count = 0, number_rolls = 0, check_wag_amo = 1, win_loss_neither = 0, point_value = 0, add_or_subtract = 0;
	double initial_bank_balance = 0.0, current_bank_balance = 0.0, wager_amount = 0.0;
	char letter = '/0', wanna_play = '/0';
	srand ((unsigned int) time (NULL));
	print_game_rules ();//print game rules
	initial_bank_balance = get_bank_balance();//get a initial bank balance
	current_bank_balance = initial_bank_balance;//set current bank balance
	
	do{// using do while to check if money is enough to gamble.
	wager_amount = get_wager_amount();// let user to enter their wager
	check_wag_amo = check_wager_amount(wager_amount, current_bank_balance);// Checks to see if the wager is within the limits of the player's available balance.
		if(check_wag_amo == 1){//if money is enough.
			printf("------------------------------Game Started------------------------------\n");
			printf("Enter 'r' to roll: ");
			getchar();// remove last return key if it has.
			scanf("%c", &letter);
			die1_value = roll_die();// roll!!
			die2_value = roll_die();// roll!!
			sum_dice = calculate_sum_dice(die1_value,die2_value);//calculate the sum of dices
			point_value = sum_dice;//record the point value
			printf("you got: %d\n", sum_dice);
			win_loss_neither = is_win_loss_or_point(sum_dice);//judge you win or loss or neither
			current_bank_balance = adjust_bank_balance(current_bank_balance, wager_amount, win_loss_neither);// add or deduct money
			count++;//count = count + 1
			chatter_messages(count, win_loss_neither, initial_bank_balance, current_bank_balance);// print out some chatter messages
			while(win_loss_neither == -1){// when you don't win or loss
				printf("->your point value: %d\n", point_value);
				//printf("-----------------------------\n");
				printf("Enter 'r' to roll: ");
				getchar();// remove last return key if it has.
				scanf("%c", &letter);
				die1_value = roll_die();
				die2_value = roll_die();
				sum_dice = calculate_sum_dice(die1_value,die2_value);
				printf("you got: %d\n", sum_dice);
				win_loss_neither = is_point_loss_or_neither(sum_dice, point_value);
				current_bank_balance = adjust_bank_balance(current_bank_balance, wager_amount, win_loss_neither);
				count++;
				chatter_messages(count, win_loss_neither, initial_bank_balance, current_bank_balance);
			}
			printf("curren bank balance: %.2lf\n\n", current_bank_balance);
		}
		if(check_wag_amo == 0) printf("don't have enough money, plz re-type the wager or quit the game.\n");//check if you have enough money to continue
		printf("------------------------------Game Ended--------------------------------\n");
		printf("wanna play again? enter 'y' to play again, 'n' to quit: ");// ask user quit or play.
		getchar();// remove last return key if it has.
		scanf("%c", &wanna_play);
		if(wanna_play == 'n') printf("Happy to see you again!\n");//when user quit, print out this message
		if(current_bank_balance == 0 && wanna_play == 'y'){
			printf("your bank balance is 0, please re");// when user's bank balance is 0, but still want to play. reset the bank balance
			initial_bank_balance = get_bank_balance();
			current_bank_balance = initial_bank_balance;
		}
	}while(wanna_play == 'y');
	others_buy_something (current_bank_balance);
	return 0;
}