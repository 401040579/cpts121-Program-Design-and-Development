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

int main(){
	int score = 0;
	char str[10] = "NUL", record[100][4];
	FILE *outfile = NULL;
	outfile = fopen("score.txt","w");
	srand((unsigned)time(NULL));
	
	welcome_info(str, &score, outfile, record);

	fclose(outfile);
	return 0;
}
