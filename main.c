#include "Header.h"
int main(void) {
	#ifdef _WIN32
		char os[] = "windows";
		printf("Windows\n");
	#elif __linux__
		char os[] = "";
		printf("Linux\n");
	#elif __unix__
		printf("Other unix OS\n");
	#else
		printf("Unidentified OS\n");
	#endif
		/*Note that ships cannot be placed
			diagonally on the board, they can only be placed vertically or horizontally.
			You program must check to see if the user tries to place a ship outside the
			boundaries of the board or on top of a ship that has already been placed.*/
	int random_choice;
	random_choice = welcome_screen();
	Game boards=print_game_board();
	srand((unsigned int)time(NULL));
	Board player1 = boards.one;
	Board player2 = boards.two;
	if (random_choice == 1) {

		manually_place_ships_on_board(player1);
	}
	else randomly_place_ships_on_board(player1);
	randomly_place_ships_on_board(player2);




	



}
/*Dir ship_direction = HORIZ;

	int row_start = 0, col_start = 0;

	char p1_board[MAX_ROWS][MAX_COLS] = { {'~', '~'}, {'~'} };

	

	init_board(p1_board, MAX_ROWS, MAX_COLS);
	print_board(p1_board, MAX_ROWS, MAX_COLS);

	ship_direction = gen_direction();

	gen_start_pt(ship_direction, 3, &row_start, &col_start);*/