#include "Header.h"
int welcome_screen() {
	printf(" _           _   _   _           _     _       \n"
		"| |         | | | | | |         | |   (_)      \n"
		"| |__   __ _| |_| |_| | ___  ___| |__  _ _ __  \n"
		"| '_ \\ / _` | __| __| |/ _ \\/ __| '_ \\| | '_ \\ \n"
		"| |_) | (_| | |_| |_| |  __/\\__ \\ | | | | |_) |\n"
		"|_.__/ \\__,_|\\__|\\__|_|\\___||___/_| |_|_| .__/ \n"
		"                                        | |    \n"
		"                                        |_|    \n");
	printf("                    __    __    __               \n"
		"                   |==|  |==|  |==|              \n"
		"                 __|__|__|__|__|__|_             \n"
		"              __|___________________|___         \n"
		"           __|__[]__[]__[]__[]__[]__[]__|___     \n"
		"          |............................o.../     \n"
		"          \\.............................../     \n"
		"        ,~')_,~')_,~')_,~')_,~')_,~')_,~')/,~')_ \n");
	printf("***** Welcome to Battleship! *****                                                                                                       \n"
		"Rules of the Game:                                                                                                                       \n"
		"1. This is a two player game.                                                                                                            \n"
		"2. Player1 is you and Player2 is the computer.                                                                                           \n"
		"3. You and your oppenent will alternate turns, calling out one shot per turn to try and hit each other's ships.                          \n"
		"4. On your turn, pick a target hole on your upright target grid and call out its location by letter and number.                          \n"
		"5. Each target hole has a letter-number coordingate that correspods with the same coordinate on your opponent's ocean grid.              \n"
		"6. To determine each coordinate, find its corresponding letter on the left side of the target grid and its number on the top of the grid.\n"
		"7. When you call a shot, your opponent then tells you whether your shot is a hit or a miss                                               \n"
		"8. If you call out a shot location that is occupied by a ship on your opponent's ocean grid, your shot is a hit!                         \n"
		"9. Your opponent then tells you which ship you have hit. So, recrd your hit by placing * symbol in the corresponding target on your grid.\n"
		"10. Your opponenet places a crossed out symbol in the corresponding hole of the ship you have hit on their ocean grid.                   \n"
		"11. If you call out a shot location not occupied by a ship on your opponent's ocean grid, it's a miss.                                   \n"
		"12. Record your miss by placing a 'm' symbol in the corresponding target hole on your target grid so you won't call this shot again.     \n"
		"13. It's not necessary for player to record each other's misses with 'm' on their ocean grids. After a hit or miss your turn is over.    \n"
		"14. Play continues in this manner, with you and the computer/your opponent calling one shot per turn.                                    \n"
		"15. Once all the cells that belong to a ship are filled with '*' symbol, it has been sunk.                                               \n"
		"16. The owner of the ship must announce which ship was sunk.                                                                             \n"
		"17. Keep track of how many of your opponent's ships you sunk.                                                                            \n"
		"18. If you're the first player to sink your opponent's entire fleet of 5 ships, you win the game!                                        \n");
	printf("Hit enter to start the game!");
	getchar();
	system("cls||clear");
	printf("Please select from the following menu:\n");
	printf("1. Enter positions of ships manually.\n");
	printf("2. Allow the program to randomly select positions of ships.\n");
	int choice;
	do {
		printf("Enter 1 or 2\n");
		scanf("%d", &choice);
	} while (choice != 1 && choice != 2);
	return choice;




}
Game initialize_game_board(void) {
	Board player1_board, player2_board;
	int row_index = 0, col_index = 0;
	for (; row_index < MAX_ROWS; ++row_index) // controls the row that we're visiting
	{
		for (col_index = 0; col_index < MAX_COLS; ++col_index) // controls the column that we're visiting
		{
			player1_board.board_array[row_index][col_index] = '-';
			player2_board.board_array[row_index][col_index] = '-';

		}
	}
	Game container = { player1_board,player2_board };
	return container;
}
Game print_game_board() {

	Game two_boards = initialize_game_board();
	Board player1 = two_boards.one;
	Board player2 = two_boards.two;
	printf("Player 1's board:\n");
	printf("%3d%2d%2d%2d%2d%2d%2d%2d%2d%2d\n",
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
	for (int row_index = 0; row_index < MAX_ROWS; row_index++) {
		printf("%-2d", row_index);
		for (int column_index = 0; column_index < MAX_COLS; column_index++) {
			printf("% -2c", player1.board_array[row_index][column_index]);
		}
		putchar('\n');
	}
	printf("Player 2's board:\n");
	printf("%3d%2d%2d%2d%2d%2d%2d%2d%2d%2d\n",
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
	for (int row_index = 0; row_index < MAX_ROWS; row_index++) {
		printf("%-2d", row_index);
		for (int column_index = 0; column_index < MAX_COLS; column_index++) {
			printf("% -2c", player2.board_array[row_index][column_index]);
		}
		putchar('\n');
	}
	Game players = { player1,player2 };
	return players;





}

int select_who_starts_first(void) {
	if (rand() % 2)printf("Player2 has been randomly selected to go first!\n");
	else printf("Player1 has been randomly selected to go first!\n");


}
int compare_input_board(char input[],Board player1_board,int comparer) {
	int row, column;
	int space;
	int status=0;
	
	for (int i = 0; i < comparer; i += 4) {
		row = input[i] - '0';
		space = input[i + 1];
		column = input[i + 2] - '0';
		/*printf("Value of space:%d and is '-':%c\n", space, player1_board.board_array[row][column]);
		printf("Row: %d,Col: %d\n", row, column);
		printf("WTF:%d\n", i);*/
		if (player1_board.board_array[row][column] != '-'||space!=32)status = 1;




	}
	return status;
}
int manually_place_ships_on_board(Game boards) {
	printf("Please enter the five cells (row then column, each cell, separated by spaces in one line) to place the Carrier across:\n");
	
	char input1[MAX];
	
	int row, column;
	getchar();
	gets(input1);	
	printf("size: %d\n", size_for_carriers);
	for (int i = 0; i <size_for_carriers; i++)printf("%c", input1[i]);
	putchar('\n');
	
	Board player1_board=boards.one;
	for (int i = 0; i < size_for_carriers; i += 4) {
		row = input1[i] - '0';
		column = input1[i + 2] - '0';
		printf("%d%d\n", row, column);
		player1_board.board_array[row][column] = 'c';



	}
	//to check print it
	
	display_board(player1_board);
	char input2[MAX];
	printf("Please enter the 4 cells (row then column, each cell, separated by spaces in one line) to place the Battleship across:\n");
	gets(input2);	
	while (compare_input_board(input2, player1_board,size_for_battleship)) {
		printf("One of the cells you have entered is already occupied, please try inputting a different combination of row and column again. Or, you haven't entered spaces correctly!\nPlease enter the 4 cells (row then column, each cell, separated by spaces in one line) to place the Battleship across:\n");
		gets(input2);
	}
	printf("size: %d\n", size_for_battleship);
	for (int i = 0; i < size_for_battleship; i++)printf("%c", input2[i]);
	putchar('\n');

	

	//to check print it
	display_board(player1_board);
	for (int i = 0; i < size_for_battleship; i += 4) {
		row = input2[i] - '0';
		column = input2[i + 2] - '0';
		printf("%d%d\n", row, column);
		player1_board.board_array[row][column] = 'b';



	}








	
	//check if it has changed
	display_board(player1_board);


}
int randomly_place_ships_on_board(void) {

}
int check_shot() {

}
int is_winner() {

}


void update_board() {}
void display_board(Board player1_board) {
	printf("Player 1's board:\n");
	printf("%3d%2d%2d%2d%2d%2d%2d%2d%2d%2d\n",
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
	for (int row = 0; row < MAX_ROWS; row++) {
		printf("%-2d", row);
		for (int col = 0; col < MAX_COLS; col++)
		{
			printf("%c ", player1_board.board_array[row][col]);
		}putchar('\n');
	}
}
void output_current_move() {
}
void check_if_sunk_ship() {

}
void output_stats() {

}
//void init_board(char board[][MAX_COLS], int num_rows, int num_cols)
//{
//    int row_index = 0, col_index = 0;
//
//    for (; row_index < num_rows; ++row_index) // controls the row that we're visiting
//    {
//        for (col_index = 0; col_index < num_cols; ++col_index) // controls the column that we're visiting
//        {
//            board[row_index][col_index] = '~';
//        }
//    }
//}
//void print_board(char board[][MAX_COLS], int num_rows, int num_cols)
//{
//    int row_index = 0, col_index = 0;
//
//    printf("%3d%2d%2d%2d%2d%2d%2d%2d%2d%2d\n",
//        0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
//
//    for (; row_index < num_rows; ++row_index) // controls the row that we're visiting
//    {
//        printf("%-2d", row_index);
//        for (col_index = 0; col_index < num_cols; ++col_index) // controls the column that we're visiting
//        {
//            printf("%-2c", board[row_index][col_index]);
//        }
//
//        putchar('\n');
//    }
//
//}
//
//Dir gen_direction(void)
//{
//    return ((Dir)(rand() % 2));
//}
//void gen_start_pt(Dir direction, int ship_length, int* start_row_ptr,
//    int* start_col_ptr)
//{
//    if (direction == HORIZ)
//    {
//        *start_row_ptr = rand() % MAX_ROWS;
//        *start_col_ptr = rand() % (MAX_COLS - ship_length + 1);
//    }
//    else
//    {
//        *start_col_ptr = rand() % MAX_COLS;
//        *start_row_ptr = rand() % (MAX_ROWS - ship_length + 1);
//
//    }
//}