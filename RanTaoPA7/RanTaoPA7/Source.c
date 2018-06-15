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
#include "Header.h"
/*************************************************************
* Function: welcome_info(char str[], int *score, FILE *outfile, char record[][4])
* Date Created: 11/23/2015
* Date Last Modified:  12/1/2015
* Description: print out welcome_screen
*************************************************************/
void welcome_info(char str[], int *score, FILE *outfile, char record[][4]){
	int input, level = 1, i = 0;
	do{
		printf("your initial: %s current level: %d score: %d\n", str, level, *score);
		printf("1. Learn about how to use the program\n"
			"2. Enter your initials (3 individual characters...)\n"
			"3. Difficulty selection\n"
			"4. Start a new sequence of problems\n"
			"5. Save score\n"
			"6. Load previous progress\n"
			"7. Help\n"
			"8. Quit\n"
			"9. funny questions\n");
		scanf("%d", &input);getchar();
		if(input);
		switch (input)
		{
		case 1:
			how_to_use_program();
			break;
		case 2:
			your_initials(str);
			break;
		case 3:
			level = difficulty_selection();
			break;
		case 4:
			new_seqience_of_problems(level, score);
			break;
		case 5:
			save(str, score, outfile, record, &i);
			break;
		case 6:
			load_previous_progress(record, &i, str, score);
			break;
		case 7:
			help();
			break;
		case 9:
			others_fun_questions();
			break;
		default:
			break;
		}

		if(input < 1 || input > 9){
			printf("wrong enter!\n");
			system("pause");
			system("cls");
		}

	}while(input != 8);

}
/*************************************************************
* Function: how_to_use_program ()
* Date Created: 11/23/2015
* Date Last Modified:  12/1/2015
* Description: let users know how to use the program
*************************************************************/
void how_to_use_program (){
	system("cls");
	printf("level 1: get 1 point for correct answer\n"
		"level 2: get 2 point for correct answer\n"
		"level 3: get 3 point for correct answer\n"
		"level 4: get 4 point for correct answer\n"
		"level 5: get 5 point for correct answer\n"
		"lose 1 point for wrong answer\n"
		"\n"
		"1. you should enter your initial first\n"
		"2. default difficulty is level 1\n"
		"3. this program is not autosave, you should save when you want\n");
	system("pause");
	system("cls");
}
/*************************************************************
* Function: your_initials(char str[])
* Date Created: 11/23/2015
* Date Last Modified:  12/1/2015
* Description: let user enter his/her 3 char
*************************************************************/
void your_initials(char str[]){
	do{
		printf("3 individual characters: ");
		scanf("%s", str);
		if(strlen(str) != 3) {
			printf("plz, enter 3 individual characters\n");
			system("pause");
		}
	}while(strlen(str) != 3);
	system("cls");

}
/*************************************************************
* Function: difficulty_selection()
* Date Created: 11/23/2015
* Date Last Modified:  12/1/2015
* Description: let user choose difficulty 1-5
*************************************************************/
int difficulty_selection(){
	int num;
	do{
		printf("what level do you want?\nlevel: ");
		scanf("%d", &num);getchar();
		if(num < 1 || num > 5) printf("number should between 1 and 5\n");
	}while(num < 1 || num > 5);
	system("cls");
	return num;
}
/*************************************************************
* Function: new_seqience_of_problems(int level, int *score)
* Date Created: 11/23/2015
* Date Last Modified:  12/1/2015
* Description: let user choose difficulty 1-5
*************************************************************/
void new_seqience_of_problems(int level, int *score){
	switch (level)
	{
	case 1:
		Level_1(score);
		break;
	case 2:
		Level_2(score);
		break;
	case 3:
		Level_3(score);
		break;
	case 4:
		Level_4(score);
		break;
	case 5:
		Level_5(score);
		break;
	default:
		break;
	}
	system("cls");
}
/*************************************************************
* Function: addition_oneTerm(int *num1, int *num2, int *correct, int *incorrect)
* Date Created: 11/23/2015
* Date Last Modified:  12/1/2015
* Description: random addition equation
*************************************************************/
void addition_oneTerm(int *num1, int *num2, int *correct, int *incorrect){
	int answer;
	printf("%d + %d = ", *num1, *num2);
	scanf("%d", &answer);getchar();
	if(answer == *num1 + *num2){
		printf("correct!\n");
		*correct = *correct + 1;
	}else{
		printf("sorry, incorrect. :(\nanswer should be %d\n", *num1 + *num2);
		*incorrect= *incorrect + 1;	
	}
}
/*************************************************************
* Function: subtraction_oneTerm(int *num1, int *num2, int *correct, int *incorrect)
* Date Created: 11/23/2015
* Date Last Modified:  12/1/2015
* Description: random subtraction equation
*************************************************************/
void subtraction_oneTerm(int *num1, int *num2, int *correct, int *incorrect){
	int answer;
	printf("%d - %d = ", *num1, *num2);
	scanf("%d", &answer);getchar();
	if(answer == *num1 - *num2){
		printf("correct!\n");
		*correct = *correct + 1;
	}else{
		printf("sorry, incorrect. :(\nanswer should be %d\n", *num1 - *num2);
		*incorrect= *incorrect + 1;	
	}
}
/*************************************************************
* Function: addition_and_subtraction_twoTerms(int *num1, int *num2, int *num3, int *correct, int *incorrect)
* Date Created: 11/23/2015
* Date Last Modified:  12/1/2015
* Description: random subtraction and addition equation
*************************************************************/
void addition_and_subtraction_twoTerms(int *num1, int *num2, int *num3, int *correct, int *incorrect){
	int answer;
	int sign = rand()%4;
	if(sign == 0){
		printf("%d + %d + %d = ",*num1,*num2,*num3);
		scanf("%d", &answer);getchar();
		if(answer == *num1 + *num2 + *num3){
			printf("correct!\n");
			*correct = *correct + 1;
		}else{
			printf("sorry, incorrect. :(\nanswer should be %d\n", *num1 + *num2 + *num3);
			*incorrect = *incorrect + 1;
		}
	}else if(sign == 1){	
		printf("%d - %d - %d = ",*num1,*num2,*num3);
		scanf("%d", &answer);getchar();
		if(answer == *num1 - *num2 - *num3){
			printf("correct!\n");
			*correct = *correct + 1;
		}else{
			printf("sorry, incorrect. :(\nanswer should be %d\n", *num1 - *num2 - *num3);
			*incorrect = *incorrect + 1;	
		}
	}else if(sign == 2){
		printf("%d + %d - %d = ",*num1,*num2,*num3);
		scanf("%d", &answer);getchar();
		if(answer == *num1 + *num2 - *num3){
			printf("correct!\n");
			*correct = *correct + 1;
		}else{
			printf("sorry, incorrect. :(\nanswer should be %d\n", *num1 + *num2 - *num3);
			*incorrect = *incorrect + 1;
		}
	}else{
		printf("%d - %d + %d = ",*num1,*num2,*num3);
		scanf("%d", &answer);getchar();
		if(answer == *num1 - *num2 + *num3){
			printf("correct!\n");
			*correct = *correct + 1;
		}else{
			printf("sorry, incorrect. :(\nanswer should be %d\n", *num1 - *num2 + *num3);
			*incorrect = *incorrect + 1;	
		}
	}

}
/*************************************************************
* Function: multiplication_oneTerm(int *num1, int *num2, int *correct, int *incorrect)
* Date Created: 11/23/2015
* Date Last Modified:  12/1/2015
* Description: random multiplication equation
*************************************************************/
void multiplication_oneTerm(int *num1, int *num2, int *correct, int *incorrect){
	int answer;
	printf("%d x %d = ", *num1, *num2);
	scanf("%d", &answer);getchar();
	if(answer == *num1 * *num2){
		printf("correct!\n");
		*correct = *correct + 1;
	}else{
		printf("sorry, incorrect. :(\nanswer should be %d\n", *num1 * *num2);
		*incorrect= *incorrect + 1;	
	}
}
/*************************************************************
* Function: division_oneTerm(int *num1, int *num2, int *correct, int *incorrect)
* Date Created: 11/23/2015
* Date Last Modified:  12/1/2015
* Description: random division equation
*************************************************************/
void division_oneTerm(int *num1, int *num2, int *correct, int *incorrect){
	char str[100] = "";

	do{
		printf("%d / %d = ", *num1, *num2);
		gets(str);
		if(!(str[0]-'0' >= 0 && str[0]-'0' <= 9 && str[2] == 'R' && str[4]-'0' >= 0 && str[4]-'0' <= 9)) 
			printf("enter should be x R y\n");
	}while(!(str[0]-'0' >= 0 && str[0]-'0' <= 9 && str[2] == 'R' && str[4]-'0' >= 0 && str[4]-'0' <= 9));

	if(((str[0]-'0') == *num1 / *num2) && (((str[4]-'0') == *num1 % *num2))){
		printf("correct!\n");
		*correct = *correct + 1;
	}else{
		printf("sorry, incorrect. :(\nanswer should be %d R %d\n", *num1 / *num2, *num1 % *num2);
		*incorrect= *incorrect + 1;	
	}
}
/*************************************************************
* Function: mix_single_digit(int *num1, int *num2, int *num3, int *correct, int *incorrect)
* Date Created: 11/23/2015
* Date Last Modified:  12/1/2015
* Description:  Includes a mix of addition, subtraction, 
multiplication, and division problems, with positive and 
negative single digit operands and up to three terms only
(i.e. d1 + -d2 / d3 = )
*************************************************************/
void mix_single_digit(int *num1, int *num2, int *num3, int *correct, int *incorrect){
	char str[100] = "";
	char first_sign, second_sign;
	int i,j, answer,
		result, remainder;

	do{
		*num1 = rand() % 19 - 9;
		*num2 = rand() % 19 - 9;
		*num3 = rand() % 19 - 9;
	}while(*num1 == 0 ||*num2 == 0 ||*num3 == 0);


	i = rand()%2;
	if(i == 0) first_sign = '+';
	else first_sign = '-';

	j = rand()%2;
	if(j == 0) second_sign = 'x';
	else second_sign = '/';

	printf("%d %c %d %c %d = ", *num1, first_sign, *num2, second_sign, *num3);

	if(first_sign == '+' && second_sign == 'x'){
		scanf("%d", &answer);getchar();
		if(answer == *num1 + *num2 * *num3){
			printf("correct!\n");
			*correct = *correct + 1;
		}else{
			printf("sorry, incorrect. :(\nanswer should be %d\n", *num1 + *num2 * *num3);
			*incorrect = *incorrect + 1;
		}

	}else if(first_sign == '-' && second_sign == 'x'){
		scanf("%d", &answer);getchar();
		if(answer == *num1 - *num2 * *num3){
			printf("correct!\n");
			*correct = *correct + 1;
		}else{
			printf("sorry, incorrect. :(\nanswer should be %d\n", *num1 - *num2 * *num3);
			*incorrect = *incorrect + 1;
		}
	}else if(first_sign == '+' && second_sign == '/'){

		do{
			gets(str);
			if(str[1] == ' '){
				result = str[0]-'0';
				remainder = str[4]-'0';
				if(str[2] != 'R') printf("enter should be x R y\n");
			}else{
				result = str[0]-'0';
				remainder = str[5]-'0';
				if(str[3] != 'R') printf("enter should be x R y\n");
			}

		}while(str[2] != 'R' && str[3] != 'R');

		if(result == (*num1 + *num2 / *num3) && remainder == (*num2 % *num3)){
			printf("correct!\n");
			*correct = *correct + 1;
		}else{
			printf("sorry, incorrect. :(\nanswer should be %d R %d\n", *num1 + *num2 / *num3, *num2 % *num3);
			*incorrect = *incorrect + 1;
		}

	}else{
		do{
			gets(str);
			if(str[2] != 'R') 
				printf("enter should be x R y\n");
		}while(str[2] != 'R');
		result = str[0]-'0';
		remainder = str[4]-'0';
		if(result == (*num1 - *num2 / *num3) && remainder == (*num2 % *num3)){
			printf("correct!\n");
			*correct = *correct + 1;
		}else{
			printf("sorry, incorrect. :(\nanswer should be %d R %d\n", *num1 - *num2 / *num3, *num2 % *num3);
			*incorrect = *incorrect + 1;
		}
	}
}

/*void mix_single_digit2(int *num1, int *num2, int *num3, int *correct, int *incorrect){
char str[100] = "";
char first_sign, second_sign;
int i,j, answer,
result, remainder;
*num1 = rand() % 19 - 9;
*num2 = rand() % 19 - 9;
*num3 = rand() % 19 - 9;

i = rand()%3;
if(i == 0) first_sign = '+';
else if(i == 1) first_sign = '-';
else first_sign = '*';

j = rand()%4;
if(j == 0) first_sign = '+';
else if(j == 1) first_sign = '-';
else if(j == 2)first_sign = '*';
else first_sign = '/';

printf("%d %c %d %c %d = ", *num1, first_sign, *num2, second_sign, *num3);

if(first_sign == '+' && second_sign == '+'){
scanf("%d", &answer);getchar();
if(answer == *num1 + *num2 + *num3){
printf("correct!\n");
*correct = *correct + 1;
}else{
printf("sorry, incorrect. :(\nanswer should be %d\n", *num1 + *num2 + *num3);
*incorrect = *incorrect + 1;
}
}else if(first_sign == '+' && second_sign == '-'){
scanf("%d", &answer);getchar();
if(answer == *num1 + *num2 - *num3){
printf("correct!\n");
*correct = *correct + 1;
}else{
printf("sorry, incorrect. :(\nanswer should be %d\n", *num1 + *num2 - *num3);
*incorrect = *incorrect + 1;
}
}else if(first_sign == '+' && second_sign == '*'){
scanf("%d", &answer);getchar();
if(answer == *num1 + *num2 * *num3){
printf("correct!\n");
*correct = *correct + 1;
}else{
printf("sorry, incorrect. :(\nanswer should be %d\n", *num1 + *num2 * *num3);
*incorrect = *incorrect + 1;
}
}else if(first_sign == '+' && second_sign == '/'){
scanf("%d", &answer);getchar();
if(answer == *num1 + *num2 + *num3){
printf("correct!\n");
*correct = *correct + 1;
}else{
printf("sorry, incorrect. :(\nanswer should be %d\n", *num1 + *num2 + *num3);
*incorrect = *incorrect + 1;
}
}else if(first_sign == '-' && second_sign == '+'){
scanf("%d", &answer);getchar();
if(answer == *num1 + *num2 + *num3){
printf("correct!\n");
*correct = *correct + 1;
}else{
printf("sorry, incorrect. :(\nanswer should be %d\n", *num1 + *num2 + *num3);
*incorrect = *incorrect + 1;
}
}else if(first_sign == '-' && second_sign == '-'){
scanf("%d", &answer);getchar();
if(answer == *num1 + *num2 + *num3){
printf("correct!\n");
*correct = *correct + 1;
}else{
printf("sorry, incorrect. :(\nanswer should be %d\n", *num1 + *num2 + *num3);
*incorrect = *incorrect + 1;
}
}else if(first_sign == '-' && second_sign == '*'){
scanf("%d", &answer);getchar();
if(answer == *num1 + *num2 + *num3){
printf("correct!\n");
*correct = *correct + 1;
}else{
printf("sorry, incorrect. :(\nanswer should be %d\n", *num1 + *num2 + *num3);
*incorrect = *incorrect + 1;
}
}else if(first_sign == '-' && second_sign == '/'){
scanf("%d", &answer);getchar();
if(answer == *num1 + *num2 + *num3){
printf("correct!\n");
*correct = *correct + 1;
}else{
printf("sorry, incorrect. :(\nanswer should be %d\n", *num1 + *num2 + *num3);
*incorrect = *incorrect + 1;
}
}else if(first_sign == '*' && second_sign == '+'){
scanf("%d", &answer);getchar();
if(answer == *num1 + *num2 + *num3){
printf("correct!\n");
*correct = *correct + 1;
}else{
printf("sorry, incorrect. :(\nanswer should be %d\n", *num1 + *num2 + *num3);
*incorrect = *incorrect + 1;
}
}else if(first_sign == '*' && second_sign == '-'){
scanf("%d", &answer);getchar();
if(answer == *num1 + *num2 + *num3){
printf("correct!\n");
*correct = *correct + 1;
}else{
printf("sorry, incorrect. :(\nanswer should be %d\n", *num1 + *num2 + *num3);
*incorrect = *incorrect + 1;
}
}else if(first_sign == '*' && second_sign == '*'){
scanf("%d", &answer);getchar();
if(answer == *num1 + *num2 + *num3){
printf("correct!\n");
*correct = *correct + 1;
}else{
printf("sorry, incorrect. :(\nanswer should be %d\n", *num1 + *num2 + *num3);
*incorrect = *incorrect + 1;
}
}else if(first_sign == '*' && second_sign == '/'){
scanf("%d", &answer);getchar();
if(answer == *num1 + *num2 + *num3){
printf("correct!\n");
*correct = *correct + 1;
}else{
printf("sorry, incorrect. :(\nanswer should be %d\n", *num1 + *num2 + *num3);
*incorrect = *incorrect + 1;
}
}else if(first_sign == '/' && second_sign == '+'){
scanf("%d", &answer);getchar();
if(answer == *num1 + *num2 + *num3){
printf("correct!\n");
*correct = *correct + 1;
}else{
printf("sorry, incorrect. :(\nanswer should be %d\n", *num1 + *num2 + *num3);
*incorrect = *incorrect + 1;
}
}else if(first_sign == '/' && second_sign == '-'){
scanf("%d", &answer);getchar();
if(answer == *num1 + *num2 + *num3){
printf("correct!\n");
*correct = *correct + 1;
}else{
printf("sorry, incorrect. :(\nanswer should be %d\n", *num1 + *num2 + *num3);
*incorrect = *incorrect + 1;
}
}else if(first_sign == '/' && second_sign == '*'){
scanf("%d", &answer);getchar();
if(answer == *num1 + *num2 + *num3){
printf("correct!\n");
*correct = *correct + 1;
}else{
printf("sorry, incorrect. :(\nanswer should be %d\n", *num1 + *num2 + *num3);
*incorrect = *incorrect + 1;
}
}




}*/
/*************************************************************
* Function: mix_multiple_digit(int *num1, int *num2, int *num3, int *num4, int *correct, int *incorrect)
* Date Created: 11/23/2015
* Date Last Modified:  12/1/2015
* Description:Includes a mix of addition, subtraction, multiplication,
and division problems, with positive and negative two and three digit
operands and up to four terms only (i.e. dd1 + -ddd2 x ddd3 / dd4 = );
*************************************************************/
void mix_multiple_digit(int *num1, int *num2, int *num3, int *num4, int *correct, int *incorrect){
	char str[100] = "";
	char first_sign, second_sign, third_sign;
	int i,j,k, answer,
		result, remainder;

	i = rand()%2;
	if(i == 0) first_sign = '+';
	else first_sign = '-';

	second_sign = 'x';

	k = rand()%2;
	if(k == 0) third_sign = 'x';
	else third_sign = '/';

	do{
		*num1 = rand() % 1999 - 999;
		*num2 = rand() % 1999 - 999;
		*num3 = rand() % 1999 - 999;
		*num4 = rand() % 1999 - 999;
	}while(*num1 == 0 ||*num2 == 0 ||*num3 == 0||*num4 == 0);

	printf("%d %c %d %c %d %c %d = ",*num1,first_sign,*num2,second_sign,*num3,third_sign,*num4);

	if(first_sign == '+' && third_sign == 'x'){
		scanf("%d", &answer);getchar();
		if(answer == *num1 + *num2 * *num3 * *num4){
			printf("correct!\n");
			*correct = *correct + 1;
		}else{
			printf("sorry, incorrect. :(\nanswer should be %d\n", *num1 + *num2 * *num3 * *num4);
			*incorrect = *incorrect + 1;
		}
	}else if(first_sign == '-' && third_sign == 'x'){
		scanf("%d", &answer);getchar();
		if(answer == *num1 - *num2 * *num3 * *num4){
			printf("correct!\n");
			*correct = *correct + 1;
		}else{
			printf("sorry, incorrect. :(\nanswer should be %d\n", *num1 - *num2 * *num3 * *num4);
			*incorrect = *incorrect + 1;
		}
	}else if(first_sign == '+' && third_sign == '/'){

		printf("result and remainder(xx yy): ");
		scanf("%d%d", &result, &remainder);getchar();

		if(result == (*num1 + *num2 * *num3 / *num4) && remainder == (*num3 % *num4)){
			printf("correct!\n");
			*correct = *correct + 1;
		}else{
			printf("sorry, incorrect. :(\nanswer should be %d R %d\n", *num1 + *num2 * *num3 / *num4, *num3 % *num4);
			*incorrect = *incorrect + 1;
		}

	}else{
		printf("result and remainder(xx yy): ");
		scanf("%d%d", &result, &remainder);getchar();

		if(result == (*num1 - *num2 * *num3 / *num4) && remainder == (*num3 % *num4)){
			printf("correct!\n");
			*correct = *correct + 1;
		}else{
			printf("sorry, incorrect. :(\nanswer should be %d R %d\n", *num1 - *num2 * *num3 / *num4, *num3 % *num4);
			*incorrect = *incorrect + 1;
		}
	}
}
/*************************************************************
* Function: Level_1(int *score)
* Date Created: 11/23/2015
* Date Last Modified:  12/1/2015
* Description: level 1 difficulty
*************************************************************/
void Level_1(int *score){
	int i = 0, correct = 0, incorrect = 0;
	int num1,num2,num3;
	for(;i<10;i++){
		num1 = rand() % 9 + 1;
		num2 = rand() % 9 + 1;
		num3 = rand() % 9 + 1;
		if(correct >= 0 && correct<=2){
			addition_oneTerm(&num1, &num2, &correct, &incorrect);
		}
		else if(correct >= 3 && correct<=5){
			subtraction_oneTerm(&num1, &num2, &correct, &incorrect);
		}else{
			addition_and_subtraction_twoTerms(&num1, &num2, &num3, &correct, &incorrect);
		}
	}
	*score = correct - incorrect + *score;
	printf("level 1: correct %d and incorrect %d => get score %d\n", correct, incorrect, correct - incorrect);
	system("pause");
	system("cls");

}
/*************************************************************
* Function: Level_2(int *score)
* Date Created: 11/23/2015
* Date Last Modified:  12/1/2015
* Description: level 2 difficulty
*************************************************************/
void Level_2(int *score){
	int i = 0, correct = 0, incorrect = 0;
	int num1,num2,num3;
	for(;i<10;i++){
		num1 = rand() % 9 + 1;
		num2 = rand() % 9 + 1;
		num3 = rand() % 9 + 1;
		if(correct >= 0 && correct<=1){
			addition_oneTerm(&num1, &num2, &correct, &incorrect);
		}
		else if(correct >= 2 && correct<=3){
			subtraction_oneTerm(&num1, &num2, &correct, &incorrect);
		}else if(correct >= 4 && correct<=6){
			addition_and_subtraction_twoTerms(&num1, &num2, &num3, &correct, &incorrect);
		}else{
			multiplication_oneTerm(&num1, &num2, &correct, &incorrect);
		}
	}
	*score = 2*correct - incorrect + *score;
	printf("level 2: correct %d and incorrect %d => get score %d\n", correct, incorrect, 2*correct - incorrect);
	system("pause");
	system("cls");
}
/*************************************************************
* Function: Level_3(int *score)
* Date Created: 11/23/2015
* Date Last Modified:  12/1/2015
* Description: level 3 difficulty
*************************************************************/
void Level_3(int *score){
	int i = 0, correct = 0, incorrect = 0;
	int num1,num2,num3,answer;
	for(;i<10;i++){
		num1 = rand() % 9 + 1;
		num2 = rand() % 9 + 1;
		num3 = rand() % 9 + 1;
		if(correct >= 0 && correct<=1){
			addition_oneTerm(&num1, &num2, &correct, &incorrect);
		}
		else if(correct >= 2 && correct<=3){
			subtraction_oneTerm(&num1, &num2, &correct, &incorrect);
		}else if(correct >= 4 && correct<=5){
			addition_and_subtraction_twoTerms(&num1, &num2, &num3, &correct, &incorrect);
		}else if(correct >= 6 && correct<=7){
			multiplication_oneTerm(&num1, &num2, &correct, &incorrect);
		}else{
			division_oneTerm(&num1, &num2, &correct, &incorrect);
		}
	}
	*score = 3*correct - incorrect + *score;
	printf("level 3: correct %d and incorrect %d => get score %d\n", correct, incorrect, 3 * correct - incorrect);
	system("pause");
	system("cls");
}
/*************************************************************
* Function: Level_4(int *score)
* Date Created: 11/23/2015
* Date Last Modified:  12/1/2015
* Description: level 4 difficulty
*************************************************************/
void Level_4(int *score){
	int i = 0, correct = 0, incorrect = 0;
	int num1,num2,num3,answer;
	for(;i<10;i++){
		num1 = rand() % 9 + 1;
		num2 = rand() % 9 + 1;
		num3 = rand() % 9 + 1;
		if(correct == 0){
			addition_oneTerm(&num1, &num2, &correct, &incorrect);
		}
		else if(correct == 1){
			subtraction_oneTerm(&num1, &num2, &correct, &incorrect);
		}else if(correct >= 2 && correct <= 3){
			addition_and_subtraction_twoTerms(&num1, &num2, &num3, &correct, &incorrect);
		}else if(correct >= 4 && correct <= 5){
			multiplication_oneTerm(&num1, &num2, &correct, &incorrect);
		}else if(correct >= 6 && correct <= 7){
			division_oneTerm(&num1, &num2, &correct, &incorrect);
		}else{
			mix_single_digit(&num1, &num2, &num3, &correct, &incorrect);
		}
	}
	*score = 4*correct - incorrect + *score;
	printf("level 4: correct %d and incorrect %d => get score %d\n", correct, incorrect, 4 * correct - incorrect);
	system("pause");
	system("cls");
}
/*************************************************************
* Function: Level_5(int *score)
* Date Created: 11/23/2015
* Date Last Modified:  12/1/2015
* Description: level 5 difficulty
*************************************************************/
void Level_5(int *score){
	int i = 0, correct = 0, incorrect = 0;
	int num1,num2,num3,num4,answer;
	for(;i<10;i++){
		num1 = rand() % 9 + 1;
		num2 = rand() % 9 + 1;
		num3 = rand() % 9 + 1;
		if(correct == 0){
			addition_oneTerm(&num1, &num2, &correct, &incorrect);
		}
		else if(correct == 1){
			subtraction_oneTerm(&num1, &num2, &correct, &incorrect);
		}else if(correct == 2){
			addition_and_subtraction_twoTerms(&num1, &num2, &num3, &correct, &incorrect);
		}else if(correct == 3){
			multiplication_oneTerm(&num1, &num2, &correct, &incorrect);
		}else if(correct == 4){
			division_oneTerm(&num1, &num2, &correct, &incorrect);
		}else if(correct == 5){
			mix_single_digit(&num1, &num2, &num3, &correct, &incorrect);
		}else{
			mix_multiple_digit(&num1, &num2, &num3, &num4, &correct, &incorrect);
		}
	}
	*score = 5*correct - incorrect + *score;
	printf("level 5: correct %d and incorrect %d => get score %d\n", correct, incorrect, 5*correct - incorrect);
	system("pause");
	system("cls");
}
/*************************************************************
* Function: save(char str[], int *score, FILE *outfile, char record[][4], int *i)
* Date Created: 11/23/2015
* Date Last Modified:  12/1/2015
* Description: save progress
*************************************************************/
void save(char str[], int *score, FILE *outfile, char record[][4], int *i){
	fprintf(outfile, "user's initial: %s\nscore: %d\n\n", str, *score);
	printf("%s score saved\n", str);
	record[*i][0] = str[0];
	record[*i][1] = str[1];
	record[*i][2] = str[2];
	record[*i][3] = *score;
	*i = *i + 1;
	system("pause");
	system("cls");
}

//bouns
/*************************************************************
* Function: load_previous_progress(char record[][4], int *count, char str[], int *score)
* Date Created: 11/23/2015
* Date Last Modified:  12/1/2015
* Description: loading progress
*************************************************************/
void load_previous_progress(char record[][4], int *count, char str[], int *score){
	int i = 0;
	int input = 0;
	for(;i<*count;i++){
		printf("record %d: %c%c%c %d\n", i+1, record[i][0],record[i][1],record[i][2],record[i][3]);
	}
	do{
		printf("which record do you want to load? ");
		scanf("%d", &input);
		if(input < 1 || input > *count) {
			printf("wrong enter!\n");
			system("pause");
		}
	}while(input<1 || input>*count);

	str[0] = record[input-1][0];
	str[1] = record[input-1][1];
	str[2] = record[input-1][2];
	*score = record[input-1][3];
	printf("record %d loaded!\n", input);
	system("pause");
	system("cls");
}
/*
void load_previous_progress2(FILE *infile, char str[], char record){
char line[100];
infile = fopen("score.txt","r");
while (!feof (infile)){
//	read_line (infile, line, 100);
fgets (line, 100, infile);
printf("%s", line);
fgets (line, 100, infile);
strtok ("user's initial: ", " ");
strtok (NULL, " ");
strcpy (str, strtok (NULL, "\n"));
printf("what: %s\n", str);
}
fclose(infile);
}
void read_line (FILE *infile, char *line, int size)
{
fgets (line, size, infile);
}
*/

/*************************************************************
* Function: help()
* Date Created: 11/23/2015
* Date Last Modified:  12/1/2015
* Description: illustrates step-by-step how to solve various addition, 
subtraction, multiplication, and division problems
*************************************************************/
void help(){
	int input = 0;
	int num1,num2,num3,num4;
	system("cls");
	printf("1. addition\n"
		"2. subtraction\n"
		"3. multiplication\n"
		"4. division\n"
		"5. complicated\n"
		"which one do you want for help? ");
	do{
		scanf("%d", &input);
		if(input < 1 || input > 5) {
			printf("wrong enter!\n");
			system("pause");
		}
	}while(input<1 || input>5);

	if(input == 1){
		num1 = rand() % 9 + 1;
		num2 = rand() % 9 + 1;

		printf("for the equation: %d + %d = \n", num1, num2);
		printf("we write down the equation like that\n");
		system("pause");
		if(num1+num2>=10){
			printf("   %d\n",num1);
			printf("+  %d\n",num2);
			printf("-----\n");
			printf("then get the answer\n");
			system("pause");system("cls");
			printf("   %d\n",num1);
			printf("+  %d\n",num2);
			printf("-----\n");
			printf("  %d\n",num1+num2);
			system("pause");
		}else{
			printf("   %d\n",num1);
			printf("+  %d\n",num2);
			printf("-----\n");
			printf("then get the answer\n");
			system("pause");system("cls");
			printf("   %d\n",num1);
			printf("+  %d\n",num2);
			printf("-----\n");
			printf("   %d\n",num1+num2);
			system("pause");
		}

	}else if(input == 2){
		num1 = rand() % 9 + 1;
		num2 = rand() % 9 + 1;

		printf("for the equation: %d - %d = \n", num1, num2);
		printf("we write down the equation like that\n");
		system("pause");
		if(num1-num2<0){
			printf("   %d\n",num1);
			printf("-  %d\n",num2);
			printf("-----\n");
			printf("then get the answer\n");
			system("pause");system("cls");
			printf("   %d\n",num1);
			printf("-  %d\n",num2);
			printf("-----\n");
			printf("  %d\n",num1-num2);
			system("pause");
		}else{
			printf("   %d\n",num1);
			printf("-  %d\n",num2);
			printf("-----\n");
			printf("then get the answer\n");
			system("pause");system("cls");
			printf("   %d\n",num1);
			printf("-  %d\n",num2);
			printf("-----\n");
			printf("   %d\n",num1-num2);
			system("pause");
		}

	}else if(input == 3){
		num1 = rand() % 9 + 1;
		num2 = rand() % 9 + 1;

		printf("for the equation: %d * %d = \n", num1, num2);
		printf("we write down the equation like that\n");
		system("pause");
		if(num1*num2>10){
			printf("   %d\n",num1);
			printf("*  %d\n",num2);
			printf("-----\n");
			printf("then get the answer\n");
			system("pause");system("cls");
			printf("   %d\n",num1);
			printf("*  %d\n",num2);
			printf("-----\n");
			printf("  %d\n",num1*num2);
			system("pause");
		}else{
			printf("   %d\n",num1);
			printf("*  %d\n",num2);
			printf("-----\n");
			printf("then get the answer\n");
			system("pause");system("cls");
			printf("   %d\n",num1);
			printf("*  %d\n",num2);
			printf("-----\n");
			printf("   %d\n",num1*num2);
			system("pause");
		}

	}else if(input == 4){
		num1 = rand() % 9 + 1;
		num2 = rand() % 9 + 1;

		printf("for the equation: %d / %d = \n", num1, num2);
		printf("we write down the equation like that\n");
		system("pause");
		printf("  __\n");
		printf("%d/ %d\n",num2,num1);
		printf("then get: \n");
		system("pause");system("cls");

		printf("  _%d-----> result\n",num1/num2);
		printf("%d/ %d\n",num2,num1);
		printf("   %d-----> remainder\n",num1%num2);
		printf("and answer: %d R %d\n", num1/num2, num1%num2);
		system("pause");
	}else{
		printf("if there are have addition, subtraction, multiplication, and division, do multiplication, and division first\n");
		system("pause");
	}


	system("cls");
}


void others_fun_questions(){
	char input;
	int num = 0;

	system("cls");
	printf("this model is for fun and won't effect your score\n");
	system("pause");
	do{
		switch (num)
		{
		case 0:
			printf("I am an odd number. Take away one letter and I become even. What number am I? \n");
			printf("hit enter to get answer\n");
			system("pause");
			printf("Answer: Seven (take away the ¡®s¡¯ and it becomes ¡®even¡¯)\n");
			break;
		case 1:
			printf("Using only addition, how do you add eight 8¡¯s and get the number 1000? \n");
			printf("hit enter to get answer\n");
			system("pause");
			printf("Answer: 888 + 88 + 8 + 8 + 8 = 1000\n");
			break;
		case 2:
			printf("Sally is 54 years old and her mother is 80, how many years ago was Sally¡¯s mother three times her age? \n");
			printf("hit enter to get answer\n");
			system("pause");
			printf("Answer: 41 years ago, when Sally was 13 and her mother was 39.\n");
			break;
		case 3:
			printf("Which 3 numbers have the same answer whether they¡¯re added or multiplied together? \n");
			printf("hit enter to get answer\n");
			system("pause");
			printf("Answer: 1, 2 and 3.\n");
			break;
		case 4:
			printf("There is a basket containing 5 apples, how do you divide the apples among 5 children so that each child has 1 apple while 1 apple remains in the basket?  \n");
			printf("hit enter to get answer\n");
			system("pause");
			printf("Answer: 4 children get 1 apple each while the fifth child gets the basket with the remaining apple still in it.\n");
			break;
		case 5:
			printf("There is a three digit number. The second digit is four times as big as the third digit, while the first digit is three less than the second digit. What is the number?   \n");
			printf("hit enter to get answer\n");
			system("pause");
			printf("Answer: 141\n");
			break;
		case 6:
			printf("What word looks the same backwards and upside down? \n");
			printf("hit enter to get answer\n");
			system("pause");
			printf("Answer: SWIMS\n");
			break;
		case 7:
			printf("Two girls were born to the same mother, at the same time, on the same day, in the same month and in the same year and yet somehow they¡¯re not twins. Why not?  \n");
			printf("hit enter to get answer\n");
			system("pause");
			printf("Answer: Because there was a third girl, which makes them triplets!\n");
			break;
		case 8:
			printf("A ship anchored in a port has a ladder which hangs over the side. The length of the ladder is 200cm, the distance between each rung in 20cm and the bottom rung touches the water. The tide rises at a rate of 10cm an hour. When will the water reach the fifth rung? \n");
			printf("hit enter to get answer\n");
			system("pause");
			printf("Answer: The tide raises both the water and the boat so the water will never reach the fifth rung.\n");
			break;
		default:
			break;
		}


		do{
			printf("wanna one more? y/n \n");
			scanf("%c", &input); getchar();
			if(input != 'y' && input != 'Y' && input != 'n' && input != 'N') {
				printf("wrong enter, plz re-enter\n");
				system("pause");
			}

		}while(input != 'y' && input != 'Y' && input != 'n' && input != 'N');
		num++;
	}while(num <= 8 && (input == 'y' || input == 'Y'));
	if(num == 9) printf("sorry, no more\n");
	system("pause");
	system("cls");
}
