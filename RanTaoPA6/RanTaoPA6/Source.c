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
/*************************************************************
* Function: welcome_screen(int *difficulty)
* Date Created: 11/13/2015
* Date Last Modified:  11/13/2015
* Description: print out welcome_screen
* Input parameters:int*difficulty
* Returns: int
*************************************************************/
int welcome_screen(int *difficulty)
{
	int num = 0;

	do{
		printf("***** Welcome to Battleship! *****\n");
		printf("1: print the rules\n");
		printf("2: start the game\n");
		printf("3: exit\n");
		scanf("%d", &num);
		if(num < 1 || num > 3){
			printf("wrong number, plz re-type\n");
			system("pause");
			system("cls");
		}
	}while(num < 1 || num > 3);
	if(num == 1)
	{
		system("cls");
		//printf("Rules of the Game: \nBattleship (or Battleships) is a game for two players where you try to guess the location of five ships your opponent has hidden on a grid."
		//	"Players take turns calling out a row and column, attempting to name a square containing enemy ships. Originally published as Broadsides by Milton Bradley in 1931, "
		//	"the game was eventually reprinted as Battleship.\nPlayers: 2 players\nTwo boards exist within the game. Hint: each board should be implemented as a 2-dimensional array. "
		//	"Each 2-dimensional array should be 10 X 10. One represents Player1's board and one represents Player2's board. At the beginning of the game each Players' "
		//	"game board should be initialized to all '-' indicating that no ships have been placed on either board. Before the game starts, Player1 should have the option to "
		//	"either manually place each of the 5 ships in his/her fleet or to have them randomly placed on the board. If Player1 decides to place the ships manually, then he/she "
		//	"should be prompted to place the Carrier first, Battleship second, Cruiser third, Submarine fourth, and the Destroyer last. Note that ships cannot be placed diagonally"
		//	" on the board, they can only be placed vertically or horizontally. You program must check to see if the user tries to place a ship outside the boundaries of the board"
		//	" or on top of a ship that has already been placed. Each cell on the board that contains part of the ship must be indicated by 'c' for Carrier, 'b' for Battleship, 'r' "
		//	"for Cruiser, 's' for Submarine, or 'd' for Destroyer. For example, if the Carrier was placed then the board should contain 5 'c' s for each cell on the board that has a"
		//	" piece of the Carrier, etc. Once Player1's ships have been placed, Player2's ships must be randomly placed. Note that the placement of Player2's ships must be unknown. "
		//	"Thus, Player2's board will only display '-' in each cell after the placement of each ship. The program should randomly select Player1 or Player2 to go first. Once it has"
		//	" been decided on which player goes first, the game starts. Whenever it's Player1's turn, a prompt should be displayed asking for a position to target (specifying where to"
		//	" ""shoot"") on the enemy's (Player2's) board (2-dimensional array). The position should be specified in terms of a row and a column on the board. The row and column should"
		//	" always be displayed along with the board. If the position specified happens to hit a ship, then a '*' should replace the '-' on Player2's board. If the positioned specified "
		//	"misses any one of the ships in the fleet, then a 'm' should replace the '-' on Player2's board. Note that from turn-to-turn each player should NOT be allowed to enter the "
		//	"same position. Also, between turns clear the screen (system(""cls"")). In one turn, a player can only take one shot at the enemy's (other player's) fleet. When Player2 takes "
		//	"a shot at Player1's board, each hit should be specified with a '*' and each miss with a 'm' on Player1's board. The game is over win Player1 or Player2 has sunk all of the "
		//	"ships in the fleet of the enemy.\n");
		printf("**********Rules of the Game:**********\n");
		printf("Battleship is a game of strategy and chance involving two playing boards. Players strategically");
		printf("puplace their own ships on an ocean grid while attempting to sink their opponent's ships. On the  ");
		printf("playing board, ships are placed on a horizontal ocean grid while attempts to hit an opponent's ");
		printf("ships are tracked on a vertical target grid using red pegs to designate a hit and white ones for ");
		printf("misses. The boards are designed with grids of rows and columns, each having a letter or number ");
		printf("assigned to it. These are used as coordinates to identify target positions\n");

		printf("**********Basic Play:**********\n");
		printf("The first player calls out a coordinate. His opponent tells him whether he has hit or missed. If");
		printf("there is no enemy ship on this coordinate, he has missed and a white peg is placed at that hole");
		printf("on his board to track where he has already tried. If he hits a ship at that coordinate, he marks");
		printf("grid with a red peg and the opponent places a red peg into the ship and must state which ship");
		printf("his target has been hit. Play passes to the next player. Tracking your shots is important for a");
		printf("successful attack. Repeating coordinates wastes valuable time and may give the other player an edge.\n");

		printf("**********Sinking Ships:**********\n");
		printf("Each player has five ships, each covering a specific number of coordinates. A carrier covers five");
		printf("oordinates, a battleship four, a cruiser and submarine three each and a destroyer two. When a player");
		printf("has made enough correct hits to fill all the holes on a ship with red pegs, the ship is sunk and");
		printf("removed from the grid. Turns continue until one player has successfully located and sunk all five");
		printf("opponent ships and is declared the winner.\n");

		system("pause");
		system("cls");
		return num;
	}else if(num == 2)
	{
		system("cls");
		do{
			printf("how difficulty do you want?\n");
			printf("1. easy\n2. normal\n3. hard(you can not win, ha!)\n");
			scanf("%d", &*difficulty);
			if(*difficulty<1 || *difficulty>3){
				printf("wrong number, plz re-type\n");
				system("pause");
				system("cls");
			}
		}while(*difficulty<1 || *difficulty>3);
		system("cls");
		return num;
	}else{
		system("cls");
		printf("bye\n");
		return num = 3;
	}

}
/*************************************************************
* Function: select_who_starts_first()
* Date Created: 11/13/2015
* Date Last Modified:  11/13/2015
* Description: select_who_starts_first
* Input parameters:void
* Returns: int
*************************************************************/
int select_who_starts_first(void)
{
	int result = 0;

	result = rand () % 2 + 1; // 1 - player1, 2 - player2

	return result;
}
/*************************************************************
* Function: initialize_game_board (char board[][10], int rows, int cols)
* Date Created: 11/13/2015
* Date Last Modified:  11/13/2015
* Description: initialize the game board
* Input parameters:char board[][10], int rows, int cols
* Returns: NONE
*************************************************************/
void initialize_game_board (char board[][10], int rows, int cols)
{
	int row_index = 0, col_index = 0;

	// rows
	for (row_index = 0; row_index < rows; row_index++)
	{
		// columns
		for (col_index = 0; col_index < cols; col_index++)
		{
			board[row_index][col_index] = '-';
		}
	}
}
/*************************************************************
* Function: print_board (char board[][10], int rows, int cols)
* Date Created: 11/13/2015
* Date Last Modified:  11/13/2015
* Description: print out the board
* Input parameters:char board[][10], int rows, int cols
* Returns: NONE
*************************************************************/
void print_board (char board[][10], int rows, int cols)
{
	int row_index = 0, col_index = 0;
	printf("    0  1  2  3  4  5  6  7  8  9  \n");
	// rows
	for (row_index = 0; row_index < rows; row_index++)
	{
		// columns
		printf(" %d ", row_index);
		for (col_index = 0; col_index < cols; col_index++)
		{
			printf (" %c ", board[row_index][col_index]);
		}
		putchar ('\n');
	}
}
/*************************************************************
* Function: print_player2_board (char board[][10], int rows, int cols)
* Date Created: 11/13/2015
* Date Last Modified:  11/13/2015
* Description: print out the board of player2
* Input parameters:char board[][10], int rows, int cols
* Returns: NONE
*************************************************************/
void print_player2_board (char board[][10], int rows, int cols)
{
	int row_index = 0, col_index = 0;
	printf("    0  1  2  3  4  5  6  7  8  9  \n");
	// rows
	for (row_index = 0; row_index < rows; row_index++)
	{
		// columns
		printf(" %d ", row_index);
		for (col_index = 0; col_index < cols; col_index++)
		{
			if (board[row_index][col_index] == '*')
			{
				printf (" %c ", board[row_index][col_index]);
			}
			else if (board[row_index][col_index] == 'm')
			{
				printf (" %c ", board[row_index][col_index]);
			}
			else
			{
				printf (" - ");
			}

		}
		putchar ('\n');
	}
}
/*************************************************************
* Function: manually_place_ships_on_board(char board[][10])
* Date Created: 11/13/2015
* Date Last Modified:  11/13/2015
* Description: manually place ships as 5 1 5 2 5 3 5 4 5 5
* Input parameters:char board[][10]
* Returns: NONE
*************************************************************/
void manually_place_ships_on_board(char board[][10])
{
	int true_or_false = 0, i = 0, j = 0;
	int carrier[5][2], Battleship[4][2],Sunmarine[3][2], Cruiser[3][2], Destroyer[2][2];
	//place c
	do{
		print_board (board, 10, 10);
		printf("Please enter the FIVE cells to place the Carrier accross(must be in order(low to high) e.g. 1 2 2 2 3 2 4 2 5 2):\n");

		for(i=0; i<5; i++){
				for(j=0; j<2; j++){
					scanf("%d", &carrier[i][j]);
				}
		}
		if(carrier[0][0] == carrier[1][0] && carrier[1][0] == carrier[2][0] && carrier[2][0] == carrier[3][0] && carrier[3][0] == carrier[4][0]){
				if(carrier[0][1] == carrier[1][1]-1 && carrier[1][1] == carrier[2][1]-1 && carrier[2][1] == carrier[3][1]-1 && carrier[3][1] == carrier[4][1]-1){
					true_or_false = 1;
				}

		}else if(carrier[0][1] == carrier[1][1] && carrier[1][1] == carrier[2][1] && carrier[2][1] == carrier[3][1] && carrier[3][1] == carrier[4][1]){
			if(carrier[0][0] == carrier[1][0]-1 && carrier[1][0] == carrier[2][0]-1 && carrier[2][0] == carrier[3][0]-1 && carrier[3][0] == carrier[4][0]-1){
				true_or_false = 1;
			}

		}else{
			true_or_false = 0;
		}

		for(i=0; i<5; i++){
				for(j=0; j<2; j++){
					if(carrier[i][j] > 9 || carrier[i][j] < 0){
						true_or_false = 0;
					}
				}
		}

		if(true_or_false == 0) {
			printf("wrong enter, plz re-enter\n");
			system("pause");
			system("cls");
		}
	}while(true_or_false == 0);
	for(i=0,j=0; i<5; i++){
		board[carrier[i][j]][carrier[i][j+1]] = 'c';
				}
	system("cls");

	//place b
	do{
		true_or_false = 0;
		print_board (board, 10, 10);
		printf("Please enter the FOUR cells to place the Battleships accross(must be in order(low to high) e.g. 1 2 2 2 3 2 4 2):\n");

		for(i=0; i<4; i++){
				for(j=0; j<2; j++){
					scanf("%d", &Battleship[i][j]);
				}
		}
		
		if(Battleship[0][0] == Battleship[1][0] && Battleship[1][0] == Battleship[2][0] && Battleship[2][0] == Battleship[3][0]){
				if(Battleship[0][1] == Battleship[1][1]-1 && Battleship[1][1] == Battleship[2][1]-1 && Battleship[2][1] == Battleship[3][1]-1){
					if(board[Battleship[0][0]][Battleship[0][1]] == '-' && board[Battleship[1][0]][Battleship[1][1]] == '-'&&
						board[Battleship[2][0]][Battleship[2][1]] == '-' && board[Battleship[3][0]][Battleship[3][1]] == '-'){
						true_or_false = 1;
					}
				}

		}else if(Battleship[0][1] == Battleship[1][1] && Battleship[1][1] == Battleship[2][1] && Battleship[2][1] == Battleship[3][1]){
			if(Battleship[0][0] == Battleship[1][0]-1 && Battleship[1][0] == Battleship[2][0]-1 && Battleship[2][0] == Battleship[3][0]-1){
					if(board[Battleship[0][0]][Battleship[0][1]] == '-' && board[Battleship[1][0]][Battleship[1][1]] == '-'&&
						board[Battleship[2][0]][Battleship[2][1]] == '-'&&board[Battleship[3][0]][Battleship[3][1]] == '-'){
						true_or_false = 1;
					}
			}
		}else{
			true_or_false = 0;
		}

		for(i=0; i<4; i++){
				for(j=0; j<2; j++){
					if(Battleship[i][j] > 9 || Battleship[i][j] < 0){
						true_or_false = 0;
					}
				}
		}

		if(true_or_false == 0) {
			printf("wrong enter, plz re-enter\n");
			system("pause");
			system("cls");
		}
	}while(true_or_false == 0);
	for(i=0,j=0; i<4; i++){
		board[Battleship[i][j]][Battleship[i][j+1]] = 'b';
	}
	system("cls");
	//place s
	do{
		true_or_false = 0;
		print_board (board, 10, 10);
		printf("Please enter the THREE cells to place the Sunmarines accross(must be in order(low to high) e.g. 1 2 2 2 3 2):\n");

		for(i=0; i<3; i++){
				for(j=0; j<2; j++){
					scanf("%d", &Sunmarine[i][j]);
				}
		}
		
		if(Sunmarine[0][0] == Sunmarine[1][0] && Sunmarine[1][0] == Sunmarine[2][0]){
				if(Sunmarine[0][1] == Sunmarine[1][1]-1 && Sunmarine[1][1] == Sunmarine[2][1]-1){
					if(board[Sunmarine[0][0]][Sunmarine[0][1]] == '-' && board[Sunmarine[1][0]][Sunmarine[1][1]] == '-' &&
						board[Sunmarine[2][0]][Sunmarine[2][1]] == '-'){
						true_or_false = 1;
					}
				}

		}else if(Sunmarine[0][1] == Sunmarine[1][1] && Sunmarine[1][1] == Sunmarine[2][1] ){
			if(Sunmarine[0][0] == Sunmarine[1][0]-1 && Sunmarine[1][0] == Sunmarine[2][0]-1){
					if(board[Sunmarine[0][0]][Sunmarine[0][1]] == '-' && board[Sunmarine[1][0]][Sunmarine[1][1]] == '-'&&
						board[Sunmarine[2][0]][Sunmarine[2][1]] == '-'){
						true_or_false = 1;
					}
			}
		}else{
			true_or_false = 0;
		}
		for(i=0; i<3; i++){
				for(j=0; j<2; j++){
					if(Sunmarine[i][j] > 9 || Sunmarine[i][j] < 0){
						true_or_false = 0;
					}
				}
		}

		if(true_or_false == 0) {
			printf("wrong enter, plz re-enter\n");
			system("pause");
			system("cls");
		}
	}while(true_or_false == 0);
	for(i=0,j=0; i<3; i++){
		board[Sunmarine[i][j]][Sunmarine[i][j+1]] = 's';
	}
	system("cls");
	//place r
	do{
		true_or_false = 0;
		print_board (board, 10, 10);
		printf("Please enter the THREE cells to place the Cruisers accross(must be in order(low to high) e.g. 1 2 2 2 3 2):\n");

		for(i=0; i<3; i++){
				for(j=0; j<2; j++){
					scanf("%d", &Cruiser[i][j]);
				}
		}
		
		if(Cruiser[0][0] == Cruiser[1][0] && Cruiser[1][0] == Cruiser[2][0]){
				if(Cruiser[0][1] == Cruiser[1][1]-1 && Cruiser[1][1] == Cruiser[2][1]-1){
					if(board[Cruiser[0][0]][Cruiser[0][1]] == '-' && board[Cruiser[1][0]][Cruiser[1][1]] == '-'&&
						board[Cruiser[2][0]][Cruiser[2][1]] == '-'){
						true_or_false = 1;
					}
				}

		}else if(Cruiser[0][1] == Cruiser[1][1] && Cruiser[1][1] == Cruiser[2][1] ){
			if(Cruiser[0][0] == Cruiser[1][0]-1 && Cruiser[1][0] == Cruiser[2][0]-1){
					if(board[Cruiser[0][0]][Cruiser[0][1]] == '-' && board[Cruiser[1][0]][Cruiser[1][1]] == '-'&&
						board[Cruiser[2][0]][Cruiser[2][1]] == '-'){
						true_or_false = 1;
					}
			}
		}else{
			true_or_false = 0;
		}
		for(i=0; i<3; i++){
				for(j=0; j<2; j++){
					if(Cruiser[i][j] > 9 || Cruiser[i][j] < 0){
						true_or_false = 0;
					}
				}
		}

		if(true_or_false == 0) {
			printf("wrong enter, plz re-enter\n");
			system("pause");
			system("cls");
		}
	}while(true_or_false == 0);
	for(i=0,j=0; i<3; i++){
		board[Cruiser[i][j]][Cruiser[i][j+1]] = 'r';
	}
	system("cls");
	//place d
	do{
		true_or_false = 0;
		print_board (board, 10, 10);
		printf("Please enter the TWO cells to place the Destroyers accross(must be in order(low to high) e.g. 1 2 2 2):\n");

		for(i=0; i<2; i++){
				for(j=0; j<2; j++){
					scanf("%d", &Destroyer[i][j]);
				}
		}
		
		if(Destroyer[0][0] == Destroyer[1][0]){
				if(Destroyer[0][1] == Destroyer[1][1]-1){
					if(board[Destroyer[0][0]][Destroyer[0][1]] == '-' && board[Destroyer[1][0]][Destroyer[1][1]] == '-'){
						true_or_false = 1;
					}
				}

		}else if(Destroyer[0][1] == Destroyer[1][1]){
			if(Destroyer[0][0] == Destroyer[1][0]-1){
					if(board[Destroyer[0][0]][Destroyer[0][1]] == '-' && board[Destroyer[1][0]][Destroyer[1][1]] == '-'){
						true_or_false = 1;
					}
			}
		}else{
			true_or_false = 0;
		}
		for(i=0; i<2; i++){
				for(j=0; j<2; j++){
					if(Destroyer[i][j] > 9 || Destroyer[i][j] < 0){
						true_or_false = 0;
					}
				}
		}

		if(true_or_false == 0) {
			printf("wrong enter, plz re-enter\n");
			system("pause");
			system("cls");
		}
	}while(true_or_false == 0);
	for(i=0,j=0; i<2; i++){
		board[Destroyer[i][j]][Destroyer[i][j+1]] = 'd';
	}
	system("cls");

	
}
/*************************************************************
* Function: manually_place_ships_on_board2(char board[][10])
* Date Created: 11/13/2015
* Date Last Modified:  11/19/2015
* Description: manually place ships by using starting point
* Input parameters:char board[][10]
* Returns: NONE
*************************************************************/
void manually_place_ships_on_board2(char board[][10])
{
	int i = 0;
	int c = 5, c_dir,c_row,c_col,
		b = 4, b_dir,b_row,b_col,
		s = 3, s_dir,s_row,s_col,
		r = 3, r_dir,r_row,r_col,
		d = 2, d_dir,d_row,d_col;
	// place C
	//printf("Please enter the direction to place the Carrier (0 for vertical and 1 for horizontal):\n");
	//scanf("%d", &c_dir);
	//while(!(c_dir == 0 || c_dir == 1)) {
	//	printf("number should between 0 and 1\n");
	//	scanf("%d", &c_dir);
	//}
	//printf("Please enter the starting point to place the Carrier (e.g. x y)\n");
	//scanf("%d%d", &c_row, &c_col);
	//if(c_dir == 0){
	//	for(i=0;i<5;i++){
	//		board[c_row+i][c_col] = 'c';
	//	}
	//}else{
	//	for(i=0;i<5;i++){
	//		board[c_row][c_col+i] = 'c';
	//	}
	//}
	//system("cls");
	//print_board (board, 10, 10);
	do{
		do{
			print_board (board, 10, 10);
			printf("Please enter the direction to place the Carrier (0 for vertical and 1 for horizontal):\n");
			scanf("%d", &c_dir);
			//check valid numbers
			if(!(c_dir == 0 || c_dir == 1)){
				printf("number should between 0 and 1\n");
				system("pause");
				system("cls");
			}
		}while(!(c_dir == 0 || c_dir == 1));
		if(c_dir == 0){
			do{
				system("cls");
				print_board (board, 10, 10);
				printf("Please enter the starting point to place the Carrier (e.g. x y)\n");
				scanf("%d%d", &c_row, &c_col);
				//check valid numbers, next all same
				if(!((c_row >= 0 && c_row <= 5 ) && (c_col >= 0 && c_col <= 9))) {
					printf("row should less than 6, col should less than 10\n");
					system("pause");
					system("cls");}
			}while(!((c_row >= 0 && c_row <= 5 ) && (c_col >= 0 && c_col <= 9)));
		}else{
			do{
				system("cls");
				print_board (board, 10, 10);
				printf("Please enter the starting point to place the Carrier (e.g. x y)\n");
				scanf("%d%d", &c_row, &c_col);
				if(!((c_col >= 0 && c_col <= 5 ) && (c_row >= 0 && c_row <= 9))){
					printf("col should less than 6, row should less than 10\n");
					system("pause");
					system("cls");}
			}while(!((c_col >= 0 && c_col <= 5 ) && (c_row >= 0 && c_row <= 9)));
		}
		//place ships
		if(c_dir == 0){
			for(i=0;i<5;i++){
				board[c_row+i][c_col] = 'c';
			}
		}else{
			for(i=0;i<5;i++){
				board[c_row][c_col+i] = 'c';
			}
		}
		system("cls");
	}while(board[c_row][c_col] != 'c');

	// Place b
	do{
		do{
			print_board (board, 10, 10);
			printf("Please enter the direction to place the Battleships (0 for vertical and 1 for horizontal):\n");
			scanf("%d", &b_dir);
			if(!(b_dir == 0 || b_dir == 1)){
				printf("number should between 0 and 1\n");
				system("pause");
				system("cls");
			}
		}while(!(b_dir == 0 || b_dir == 1));
		if(b_dir == 0){
			do{
				system("cls");
				print_board (board, 10, 10);
				printf("Please enter the starting point to place the Battleships (e.g. x y)\n");
				scanf("%d%d", &b_row, &b_col);
				if(!((b_row >= 0 && b_row <= 6 ) && (b_col >= 0 && b_col <= 9))) {
					printf("row should less than 7, col should less than 10\n");
					system("pause");
					system("cls");}
			}while(!((b_row >= 0 && b_row <= 6 ) && (b_col >= 0 && b_col <= 9)));
		}else{
			do{
				system("cls");
				print_board (board, 10, 10);
				printf("Please enter the starting point to place the Battleships (e.g. x y)\n");
				scanf("%d%d", &b_row, &b_col);
				if(!((b_col >= 0 && b_col <= 6 ) && (b_row >= 0 && b_row <= 9))){
					printf("col should less than 7, row should less than 10\n");
					system("pause");
					system("cls");}
			}while(!((b_col >= 0 && b_col <= 6 ) && (b_row >= 0 && b_row <= 9)));
		}
		//place ships and check if overlap
		if(b_dir == 0){
			if(board[b_row][b_col] == '-' && board[b_row+1][b_col] == '-' && board[b_row+2][b_col] == '-' && board[b_row+3][b_col] == '-'){
				for(i=0;i<4;i++){
					board[b_row+i][b_col] = 'b';
				}
			}
		}else{
			if(board[b_row][b_col] == '-' && board[b_row][b_col+1] == '-'&& board[b_row][b_col+2] == '-'&& board[b_row][b_col+3] == '-'){
				for(i=0;i<4;i++){
					board[b_row][b_col+i] = 'b';
				}
			}
		}
		if(board[b_row][b_col] != 'b'){ printf("Wrong starting point or direction, please re-enter.\n");
		system("pause");}
		system("cls");
		//if ships does not place succeeful, replace it. same idea on next.
	}while(board[b_row][b_col] != 'b');
	/*
	do{
	printf("Please enter the direction to place the Battleships (0 for vertical and 1 for horizontal):\n");
	scanf("%d", &b_dir);
	while(!(b_dir == 0 || b_dir == 1)) {
	printf("number should between 0 and 1\n");
	scanf("%d", &b_dir);
	}
	printf("Please enter the starting point to place the Battleships (e.g. x y)\n");
	scanf("%d%d", &b_row, &b_col);
	if(b_dir == 0){
	if(b_row >= 7){
	printf("row should less than 7 and col should less than 10\n");
	printf("Please enter the starting point to place the Battleships (e.g. x y)\n");
	scanf("%d%d", &b_row, &b_col);
	}
	}else{
	if(b_col >= 7){
	printf("col should less than 7 and row should less then 10\n");
	printf("Please enter the starting point to place the Battleships (e.g. x y)\n");
	scanf("%d%d", &b_row, &b_col);
	}
	}

	if(b_dir == 0){
	if(board[b_row][b_col] == '-' && board[b_row+1][b_col] == '-' && board[b_row+2][b_col] == '-' && board[b_row+3][b_col] == '-'){
	for(i=0;i<4;i++){
	board[b_row+i][b_col] = 'b';
	}
	}
	}else{
	if(board[b_row][b_col] == '-' && board[b_row][b_col+1] == '-'&& board[b_row][b_col+2] == '-'&& board[b_row][b_col+3] == '-'){
	for(i=0;i<4;i++){
	board[b_row][b_col+i] = 'b';
	}
	}
	}
	if(board[b_row][b_col] != 'b') printf("Wrong starting point or direction, please re-enter.\n");
	}while(board[b_row][b_col] != 'b');
	system("cls");
	print_board (board, 10, 10);*/
	// Place s

	do{
		do{
			print_board (board, 10, 10);
			printf("Please enter the direction to place the Sunmarine (0 for vertical and 1 for horizontal):\n");
			scanf("%d", &s_dir);
			if(!(s_dir == 0 || s_dir == 1)){
				printf("number should between 0 and 1\n");
				system("pause");
				system("cls");
			}
		}while(!(s_dir == 0 || s_dir == 1));
		if(s_dir == 0){
			do{
				system("cls");
				print_board (board, 10, 10);
				printf("Please enter the starting point to place the Sunmarine (e.g. x y)\n");
				scanf("%d%d", &s_row, &s_col);
				if(!((s_row >= 0 && s_row <= 7 ) && (s_col >= 0 && s_col <= 9))) {
					printf("row should less than 8, col should less than 10\n");
					system("pause");
					system("cls");}
			}while(!((s_row >= 0 && s_row <= 7 ) && (s_col >= 0 && s_col <= 9)));
		}else{
			do{
				system("cls");
				print_board (board, 10, 10);
				printf("Please enter the starting point to place the Sunmarine (e.g. x y)\n");
				scanf("%d%d", &s_row, &s_col);
				if(!((s_col >= 0 && s_col <= 7 ) && (s_row >= 0 && s_row <= 9))){
					printf("col should less than 8, row should less than 10\n");
					system("pause");
					system("cls");}
			}while(!((s_col >= 0 && s_col <= 7 ) && (s_row >= 0 && s_row <= 9)));
		}

		if(s_dir == 0){
			if(board[s_row][s_col] == '-' && board[s_row+1][s_col] == '-' && board[s_row+2][s_col] == '-'){
				for(i=0;i<3;i++){
					board[s_row+i][s_col] = 's';
				}
			}
		}else{
			if(board[s_row][s_col] == '-' && board[s_row][s_col+1] == '-' && board[s_row][s_col+2] == '-'){
				for(i=0;i<3;i++){
					board[s_row][s_col+i] = 's';
				}
			}
		}
		if(board[s_row][s_col] != 's'){printf("Wrong starting point or direction, please re-enter.\n");
		system("pause");}
		system("cls");
	}while(board[s_row][s_col] != 's');

	// place r

	do{
		do{
			print_board (board, 10, 10);
			printf("Please enter the direction to place the Cruiser (0 for vertical and 1 for horizontal):\n");
			scanf("%d", &r_dir);
			if(!(r_dir == 0 || r_dir == 1)){
				printf("number should between 0 and 1\n");
				system("pause");
				system("cls");
			}
		}while(!(r_dir == 0 || r_dir == 1));
		if(r_dir == 0){
			do{
				system("cls");
				print_board (board, 10, 10);
				printf("Please enter the starting point to place the Cruiser (e.g. x y)\n");
				scanf("%d%d", &r_row, &r_col);
				if(!((r_row >= 0 && r_row <= 7 ) && (r_col >= 0 && r_col <= 9))) {
					printf("row should less than 8, col should less than 10\n");
					system("pause");
					system("cls");}
			}while(!((r_row >= 0 && r_row <= 7 ) && (r_col >= 0 && r_col <= 9)));
		}else{
			do{
				system("cls");
				print_board (board, 10, 10);
				printf("Please enter the starting point to place the Cruiser (e.g. x y)\n");
				scanf("%d%d", &r_row, &r_col);
				if(!((r_col >= 0 && r_col <= 7 ) && (r_row >= 0 && r_row <= 9))){
					printf("col should less than 8, row should less than 10\n");
					system("pause");
					system("cls");}
			}while(!((r_col >= 0 && r_col <= 7 ) && (r_row >= 0 && r_row <= 9)));
		}

		if(r_dir == 0){
			if(board[r_row][r_col] == '-' && board[r_row+1][r_col] == '-' && board[r_row+2][r_col] == '-'){
				for(i=0;i<3;i++){
					board[r_row+i][r_col] = 'r';
				}
			}
		}else{
			if(board[r_row][r_col] == '-' && board[r_row][r_col+1] == '-' && board[r_row][r_col+2] == '-'){
				for(i=0;i<3;i++){
					board[r_row][r_col+i] = 'r';
				}
			}
		}
		if(board[r_row][r_col] != 'r'){printf("Wrong starting point or direction, please re-enter.\n");
		system("pause");}
		system("cls");
	}while(board[r_row][r_col] != 'r');

	//place d
	do{
		do{
			print_board (board, 10, 10);
			printf("Please enter the direction to place the Destroyer (0 for vertical and 1 for horizontal):\n");
			scanf("%d", &d_dir);
			if(!(d_dir == 0 || d_dir == 1)){
				printf("number should between 0 and 1\n");
				system("pause");
				system("cls");
			}
		}while(!(d_dir == 0 || d_dir == 1));
		if(d_dir == 0){
			do{
				system("cls");
				print_board (board, 10, 10);
				printf("Please enter the starting point to place the Destroyer (e.g. x y)\n");
				scanf("%d%d", &d_row, &d_col);
				if(!((d_row >= 0 && d_row <= 8 ) && (d_col >= 0 && d_col <= 9))) {
					printf("row should less than 9, col should less than 10\n");
					system("pause");
					system("cls");}
			}while(!((d_row >= 0 && d_row <= 8 ) && (d_col >= 0 && d_col <= 9)));
		}else{
			do{
				system("cls");
				print_board (board, 10, 10);
				printf("Please enter the starting point to place the Destroyer (e.g. x y)\n");
				scanf("%d%d", &d_row, &d_col);
				if(!((d_col >= 0 && d_col <= 8 ) && (d_row >= 0 && d_row <= 9))){
					printf("col should less than 9, row should less than 10\n");
					system("pause");
					system("cls");}
			}while(!((d_col >= 0 && d_col <= 8 ) && (d_row >= 0 && d_row <= 9)));
		}

		if(d_dir == 0){
			if(board[d_row][d_col] == '-' && board[d_row+1][d_col] == '-' ){
				for(i=0;i<2;i++){
					board[d_row+i][d_col] = 'd';
				}
			}
		}else{
			if(board[d_row][d_col] == '-' && board[d_row][d_col+1] == '-' ){
				for(i=0;i<2;i++){
					board[d_row][d_col+i] = 'd';
				}
			}
		}
		if(board[d_row][d_col] != 'd'){printf("Wrong starting point or direction, please re-enter.\n");
		system("pause");
		system("cls");
		}
	}while(board[d_row][d_col] != 'd');
}
/*************************************************************
* Function: randomly_place_ships_on_board(char board[][10])
* Date Created: 11/13/2015
* Date Last Modified:  11/13/2015
* Description: randomly place ships
* Input parameters:char board[][10]
* Returns: NONE
*************************************************************/
void randomly_place_ships_on_board(char board[][10])
{
	int i = 0;
	int c = 5, c_dir,c_row,c_col,
		b = 4, b_dir,b_row,b_col,
		s = 3, s_dir,s_row,s_col,
		r = 3, r_dir,r_row,r_col,
		d = 2, d_dir,d_row,d_col;
	// Place C
	//same idea with manually place
	c_dir = gen_direction();
	gen_start_pt(c,c_dir,&c_row,&c_col);
	if(c_dir == 0){
		for(i=0;i<5;i++){
			board[c_row+i][c_col] = 'c';
		}
	}else{
		for(i=0;i<5;i++){
			board[c_row][c_col+i] = 'c';
		}
	}
	// Place b
	do{
		b_dir = gen_direction();
		gen_start_pt(b,b_dir,&b_row,&b_col);
		//check the random place if it's blank, same idea on next
		if(b_dir == 0){
			if(board[b_row][b_col] == '-' && board[b_row+1][b_col] == '-' && board[b_row+2][b_col] == '-' && board[b_row+3][b_col] == '-'){
				for(i=0;i<4;i++){
					board[b_row+i][b_col] = 'b';
				}
			}
		}else{
			if(board[b_row][b_col] == '-' && board[b_row][b_col+1] == '-'&& board[b_row][b_col+2] == '-'&& board[b_row][b_col+3] == '-'){
				for(i=0;i<4;i++){
					board[b_row][b_col+i] = 'b';
				}
			}
		}
	}while(board[b_row][b_col] != 'b');
	// Place s
	do{
		s_dir = gen_direction();
		gen_start_pt(s,s_dir,&s_row,&s_col);
		if(s_dir == 0){
			if(board[s_row][s_col] == '-' && board[s_row+1][s_col] == '-' && board[s_row+2][s_col] == '-'){
				for(i=0;i<3;i++){
					board[s_row+i][s_col] = 's';
				}
			}
		}else{
			if(board[s_row][s_col] == '-' && board[s_row][s_col+1] == '-'&& board[s_row][s_col+2] == '-'){
				for(i=0;i<3;i++){
					board[s_row][s_col+i] = 's';
				}
			}
		}
	}while(board[s_row][s_col] != 's');
	// Place r
	do{
		r_dir = gen_direction();
		gen_start_pt(r,r_dir,&r_row,&r_col);
		if(r_dir == 0){
			if(board[r_row][r_col] == '-' && board[r_row+1][r_col] == '-' && board[r_row+2][r_col] == '-'){
				for(i=0;i<3;i++){
					board[r_row+i][r_col] = 'r';
				}
			}
		}else{
			if(board[r_row][r_col] == '-' && board[r_row][r_col+1] == '-'&& board[r_row][r_col+2] == '-'){
				for(i=0;i<3;i++){
					board[r_row][r_col+i] = 'r';
				}
			}
		}
	}while(board[r_row][r_col] != 'r');
	// Place d
	do{
		d_dir = gen_direction();
		gen_start_pt(d,d_dir,&d_row,&d_col);
		if(d_dir == 0){
			if(board[d_row][d_col] == '-' && board[d_row+1][d_col] == '-'){
				for(i=0;i<2;i++){
					board[d_row+i][d_col] = 'd';
				}
			}
		}else{
			if(board[d_row][d_col] == '-' && board[d_row][d_col+1] == '-'){
				for(i=0;i<2;i++){
					board[d_row][d_col+i] = 'd';
				}
			}
		}
	}while(board[d_row][d_col] != 'd');

}
/*************************************************************
* Function: check_shot(char board[][10], int row, int col, int *hit_or_miss,
int *m_count, int *c_count, int *b_count, int *r_count, int *s_count, int *d_count)
* Date Created: 11/13/2015
* Date Last Modified:  11/13/2015
* Description: check if shot, then return int
* Input parameters:char board[][10], int row, int col, int *hit_or_miss,
int *m_count, int *c_count, int *b_count, int *r_count, int *s_count, int *d_count
* Returns: int
*************************************************************/
int check_shot(char board[][10], int row, int col, int *hit_or_miss,
			   int *m_count, int *c_count, int *b_count, int *r_count, int *s_count, int *d_count)
{
	//check shot and add the counts
	*hit_or_miss = 0;
	if(board[row][col] == '-'){
		board[row][col] = 'm';
		*m_count = *m_count + 1;
	}else if(board[row][col] == 'c'){
		*hit_or_miss = 1;
		board[row][col] = '*';
		*c_count = *c_count + 1;
	}else if(board[row][col] == 'b'){
		*hit_or_miss = 1;
		board[row][col] = '*';
		*b_count = *b_count + 1;
	}else if(board[row][col] == 'r'){
		*hit_or_miss = 1;
		board[row][col] = '*';
		*r_count = *r_count + 1;
	}else if(board[row][col] == 's'){
		*hit_or_miss = 1;
		board[row][col] = '*';
		*s_count = *s_count + 1;
	}else if(board[row][col] == 'd'){
		*hit_or_miss = 1;
		board[row][col] = '*';
		*d_count = *d_count + 1;
	}else{
		printf("wrong enter, plz re-enter\n");
		system("pause");
		return 1;
	}
	return 0;
}
/*************************************************************
* Function: output_current_move(FILE *infile, int row, int col, int player, int *hit_or_miss,
int *m_count, int *c_count, int *b_count, int *r_count, int *s_count, int *d_count, 
int *c1, int *b1, int *r1,int *s1,int *d1,
int *c2, int *b2, int *r2,int *s2,int *d2)
* Date Created: 11/13/2015
* Date Last Modified:  11/13/2015
* Description: output the current moving of ships
* Input parameters:FILE *infile, int row, int col, int player, int *hit_or_miss,
int *m_count, int *c_count, int *b_count, int *r_count, int *s_count, int *d_count, 
int *c1, int *b1, int *r1,int *s1,int *d1,
int *c2, int *b2, int *r2,int *s2,int *d2
* Returns: NONE
*************************************************************/
void output_current_move(FILE *infile, int row, int col, int player, int *hit_or_miss,
						 int *m_count, int *c_count, int *b_count, int *r_count, int *s_count, int *d_count, 
						 int *c1, int *b1, int *r1,int *s1,int *d1,
						 int *c2, int *b2, int *r2,int *s2,int *d2)
{
	char hit_or_mis[5] = "";
	char sunk[20] = "";

	if(*hit_or_miss == 0){
		strcpy(hit_or_mis, "miss"); 
	}else{
		strcpy(hit_or_mis, "hit"); 
	}
	if(player == 1){//if carrier sunked, it should not run again
		if(*c_count == 5 && *c1 == 0){
			strcpy(sunk, "sunk Carrier!");
			*c1 = 1;
		}
		if(*b_count == 4 && *b1 == 0){
			strcpy(sunk, "sunk Battleship!");
			*b1 = 1;
		}
		if(*r_count == 3 && *r1 == 0){
			strcpy(sunk, "sunk Cruiser!");
			*r1 = 1;
		}
		if(*s_count == 3 && *s1 == 0){
			strcpy(sunk, "sunk Submarine!");
			*s1 = 1;
		}
		if(*d_count == 2 && *d1 == 0){
			strcpy(sunk, "sunk Destroyer!");
			*d1 = 1;
		}
	}else{
		if(*c_count == 5 && *c2 == 0){
			strcpy(sunk, "sunk Carrier!");
			*c2 = 1;
		}
		if(*b_count == 4 && *b2 == 0){
			strcpy(sunk, "sunk Battleship!");
			*b2 = 1;
		}
		if(*r_count == 3 && *r2 == 0){
			strcpy(sunk, "sunk Cruiser!");
			*r2 = 1;
		}
		if(*s_count == 3 && *s2 == 0){
			strcpy(sunk, "sunk Submarine!");
			*s2 = 1;
		}
		if(*d_count == 2 && *d2 == 0){
			strcpy(sunk, "sunk Destroyer!");
			*d2 = 1;
		}
	}
	printf("%d,%d is a \"%s\" %s\n", row, col, hit_or_mis, sunk);
	fprintf(infile, "Player%d: %d,%d \"%s\" %s\n", player, row, col, hit_or_mis, sunk);
	system("pause");
}
/*************************************************************
* Function: output_stats(FILE *infile, int player, int m_count, 
int c_count, int b_count, int r_count, int s_count, int d_count, stats players)
* Date Created: 11/13/2015
* Date Last Modified:  11/13/2015
* Description: output stats
* Input parameters:FILE *infile, int player, int m_count, 
int c_count, int b_count, int r_count, int s_count, int d_count, stats players
* Returns: NONE
*************************************************************/
void output_stats(FILE *infile, int player, int m_count, 
				  int c_count, int b_count, int r_count, int s_count, int d_count, stats players)
{
	//using structure to output the stats
	int total_hits;
	total_hits = c_count + b_count + r_count + s_count + d_count;
	players.hits = total_hits;
	players.misses = m_count;
	players.shots = total_hits + m_count;
	if(total_hits == 17 && player == 1)//when total hits = 17 and palyer is 1.
	{
		players.win_loses = 1;
		fprintf(infile, "\nPlayer%d wins, Player%d loses\n", players.win_loses, players.win_loses + 1);
	}else if(total_hits == 17 && player == 2){
		players.win_loses = 2;
		fprintf(infile, "\nPlayer%d wins, Player%d loses\n", players.win_loses, players.win_loses - 1);
	}
	if(m_count == 0){
		players.hit_miss_ratio = 100; // when m_count == 0, rate should be infinity.
	}else{
		players.hit_miss_ratio = (total_hits *100 / m_count);
	}
	fprintf(infile,"\n***Player%d Stats***\n", player);
	fprintf(infile,"Number Hits: %d\n", players.hits);
	fprintf(infile,"Number Misses: %d\n", players.misses);
	fprintf(infile,"Total Shots: %d\n", players.shots);
	fprintf(infile,"Hit/Miss Ratio: %.2lf%% \n\n", players.hit_miss_ratio);

}
/*************************************************************
* Function: gen_direction (void)
* Date Created: 11/13/2015
* Date Last Modified:  11/13/2015
* Description: random a direction
* Input parameters:NONE
* Returns: int
*************************************************************/
int gen_direction (void)
{
	int result = 0;

	result = rand () % 2; // 0 - vertical, 1 - horizontal

	return result;
}
/*************************************************************
* Function: gen_start_pt (int length, int dir, int *row_start_ptr,
int *col_start_ptr)
* Date Created: 11/13/2015
* Date Last Modified:  11/13/2015
* Description: random a start point
* Input parameters:int length, int dir, int *row_start_ptr,
int *col_start_ptr
* Returns: NONE
*************************************************************/
void gen_start_pt (int length, int dir, int *row_start_ptr,
				   int *col_start_ptr)
{
	// Note: the way we are generating starting points/coordinates
	// uses the length of the ship to restrict the random
	// values generated. This way we don't need extra logic
	// to determine if we are placing a ship outside
	// the bounds of our board/2-D array.
	if (dir == 0) // vertical
	{
		*col_start_ptr = rand () % 10;
		*row_start_ptr = rand () % (10 - length + 1); // down from the start point
	}
	else // horizontal
	{
		*col_start_ptr = rand () % (10 - length + 1);
		*row_start_ptr = rand () % 10;
	}
}
/*************************************************************
* Function: easy_computer (char board[][10], int *target_row, int *target_col)
* Date Created: 11/13/2015
* Date Last Modified:  11/13/2015
* Description: set conputer's difficulty
* Input parameters:char board[][10], int *target_row, int *target_col
* Returns: NONE
*************************************************************/
void easy_computer (char board[][10], int *target_row, int *target_col)
{
	do{
		*target_row = rand() % 10;
		*target_col = rand() % 10;
	}while(board[*target_row][*target_col] == '*' || board[*target_row][*target_col] == 'm');
}
/*************************************************************
* Function: normal_computer(char board[][10], int *target_row, int *target_col, 
					  int *used_row, int *used_col,
					  int *c,int *b,int *r,int *s,int *d,
					  int *run_c, int *run_b, int *run_r, int *run_s, int *run_d)
* Date Created: 11/13/2015
* Date Last Modified:  11/13/2015
* Description: set conputer's difficulty as a human's thinking
* Input parameters: char board[][10], int *target_row, int *target_col, 
					  int *used_row, int *used_col,
					  int *c,int *b,int *r,int *s,int *d,
					  int *run_c, int *run_b, int *run_r, int *run_s, int *run_d
* Returns: NONE
*************************************************************/
void normal_computer (char board[][10], int *target_row, int *target_col, 
					  int *used_row, int *used_col,
					  int *c,int *b,int *r,int *s,int *d,
					  int *run_c, int *run_b, int *run_r, int *run_s, int *run_d)
{
	int num = 0;
	// when computer shoot on a ship, this will not dispose until the ship sunk.
	if(*run_c == 0 && *run_b == 0 && *run_r == 0 && *run_s == 0 && *run_d == 0){ 
		do{
			*target_row = rand() % 10;
			*target_col = rand() % 10;
	
		}while(board[*target_row][*target_col] == '*' || board[*target_row][*target_col] == 'm');
	}	

		*used_row = *target_row;
		*used_col = *target_col;
	//when shot on c and c have 5 cells, same thing below.
	if(board[*used_row][*used_col] == 'c' || (*c > 0 && *c < 5)){
		*run_c = 1;

	/*	num = rand() % 4;

		switch (num)
		{
		case 0: // up
			*target_row = *used_row-1;
			*target_col = *used_col;
			if(board[*target_row][*target_col] == 'c'){

			}

			break;
		case 1: // left
			break;
		case 2: // donw
			break;
		case 3: // right
			break;
		default:
			break;
		}*/
		
		if(board[*used_row-1][*used_col] == 'c'){
			*target_row = *used_row-1;
			*target_col = *used_col;
		}else if(board[*used_row][*used_col-1] == 'c'){
			*target_row = *used_row;
			*target_col = *used_col-1;
		}else if(board[*used_row+1][*used_col] == 'c'){
			*target_row = *used_row+1;
			*target_col = *used_col;
		}else if(board[*used_row][*used_col+1] == 'c'){
			*target_row = *used_row;
			*target_col = *used_col+1;
		}else if(board[*used_row][*used_col+*c] == 'c'){
			*target_row = *used_row;
			*target_col = *used_col+*c;
		}else if(board[*used_row+*c][*used_col] == 'c'){
			*target_row = *used_row+*c;
			*target_col = *used_col;
		}

		*c = *c + 1;
		if(*c == 5){
			*run_c = 0;
		}
	}
	
	if(board[*used_row][*used_col] == 'b' || (*b > 0 && *b < 4)){
		*run_b = 1;
		
		if(board[*used_row-1][*used_col] == 'b'){
			*target_row = *used_row-1;
			*target_col = *used_col;
		}else if(board[*used_row][*used_col-1] == 'b'){
			*target_row = *used_row;
			*target_col = *used_col-1;
		}else if(board[*used_row+1][*used_col] == 'b'){
			*target_row = *used_row+1;
			*target_col = *used_col;
		}else if(board[*used_row][*used_col+1] == 'b'){
			*target_row = *used_row;
			*target_col = *used_col+1;
		}else if(board[*used_row][*used_col+*b] == 'b'){
			*target_row = *used_row;
			*target_col = *used_col+*b;
		}else if(board[*used_row+*b][*used_col] == 'b'){
			*target_row = *used_row+*b;
			*target_col = *used_col;
		}

		*b = *b + 1;
		if(*b == 4){
			*run_b = 0;
		}
	}
	
	if(board[*used_row][*used_col] == 'r' || (*r > 0 && *r < 3)){
		*run_r = 1;
		
		if(board[*used_row-1][*used_col] == 'r'){
			*target_row = *used_row-1;
			*target_col = *used_col;
		}else if(board[*used_row][*used_col-1] == 'r'){
			*target_row = *used_row;
			*target_col = *used_col-1;
		}else if(board[*used_row+1][*used_col] == 'r'){
			*target_row = *used_row+1;
			*target_col = *used_col;
		}else if(board[*used_row][*used_col+1] == 'r'){
			*target_row = *used_row;
			*target_col = *used_col+1;
		}else if(board[*used_row][*used_col+*r] == 'r'){
			*target_row = *used_row;
			*target_col = *used_col+*r;
		}else if(board[*used_row+*r][*used_col] == 'r'){
			*target_row = *used_row+*r;
			*target_col = *used_col;
		}

		*r = *r + 1;
		if(*r == 3){
			*run_r = 0;
		}
	}

	
	if(board[*used_row][*used_col] == 's' || (*s > 0 && *s < 3)){
		*run_s = 1;
		
		if(board[*used_row-1][*used_col] == 's'){
			*target_row = *used_row-1;
			*target_col = *used_col;
		}else if(board[*used_row][*used_col-1] == 's'){
			*target_row = *used_row;
			*target_col = *used_col-1;
		}else if(board[*used_row+1][*used_col] == 's'){
			*target_row = *used_row+1;
			*target_col = *used_col;
		}else if(board[*used_row][*used_col+1] == 's'){
			*target_row = *used_row;
			*target_col = *used_col+1;
		}else if(board[*used_row][*used_col+*s] == 's'){
			*target_row = *used_row;
			*target_col = *used_col+*s;
		}else if(board[*used_row+*s][*used_col] == 's'){
			*target_row = *used_row+*s;
			*target_col = *used_col;
		}

		*s = *s + 1;
		if(*s == 3){
			*run_s = 0;
		}
	}

	
	if(board[*used_row][*used_col] == 'd' || (*d > 0 && *d < 2)){
		*run_d = 1;
		
		if(board[*used_row-1][*used_col] == 'd'){
			*target_row = *used_row-1;
			*target_col = *used_col;
		}else if(board[*used_row][*used_col-1] == 'd'){
			*target_row = *used_row;
			*target_col = *used_col-1;
		}else if(board[*used_row+1][*used_col] == 'd'){
			*target_row = *used_row+1;
			*target_col = *used_col;
		}else if(board[*used_row][*used_col+1] == 'd'){
			*target_row = *used_row;
			*target_col = *used_col+1;
		}else if(board[*used_row][*used_col+*d] == 'd'){
			*target_row = *used_row;
			*target_col = *used_col+*d;
		}else if(board[*used_row+*d][*used_col] == 'd'){
			*target_row = *used_row+*d;
			*target_col = *used_col;
		}

		*d = *d + 1;
		if(*d == 2){
			*run_d = 0;
		}
	}




}
/*************************************************************
* Function: hard_computer (char board[][10], int *target_row, int *target_col)
* Date Created: 11/13/2015
* Date Last Modified:  11/13/2015
* Description: set conputer's difficulty
* Input parameters:char board[][10], int *target_row, int *target_col
* Returns: NONE
*************************************************************/
void hard_computer (char board[][10], int *target_row, int *target_col){

	do{
		*target_row = rand() % 10;
		*target_col = rand() % 10;
	}while(board[*target_row][*target_col] == '*' || board[*target_row][*target_col] == 'm' || board[*target_row][*target_col] == '-');
}
