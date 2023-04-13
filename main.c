#include "Header.h"

//TODO: hide the second board 
//starting logging
//tell the winner
int main(void) {
	/*Note that ships cannot be placed
		diagonally on the board, they can only be placed vertically or horizontally.
		You program must check to see if the user tries to place a ship outside the
		boundaries of the board or on top of a ship that has already been placed.*/
	int random_choice;
	random_choice = welcome_screen();
	Game boards = print_game_board();
	srand((unsigned int)time(NULL));
	Board player1 = boards.one;
	Board player2 = boards.two;
	if (random_choice == 1) {

		player1 = manually_place_ships_on_board(player1);
	}
	else player1 = randomly_place_ships_on_board(player1);
	player2 = randomly_place_ships_on_board(player2);
	printf("Player2 (Computer's) board has been generated\n");
	for (int i = 0; player1.ship_position_memory[i] != 11; i++) {
		printf("Value: %d\nsize:%d\nother size:%d\n", player1.ship_position_memory[i],i,sizeof(player1.ship_position_memory));
	}
	//this will happen in a loop until the whole board is cleared out
	//player1 goes 
	//possibly the whole mechanism in a loop.
	int game_counter = 0;
	int are_any_ships_left_on_board1 = 0;
	int are_any_ships_left_on_board2 = 0;
	int counter = 1;
	if (rand() % 2) {
		printf("Player1 has been randomly selected to go first.\n");
		getchar();
		do {
			are_any_ships_left_on_board1 = 0;
			are_any_ships_left_on_board2 = 0;
			for (int i = 0; i < MAX_ROWS; i++) {
				for (int j = 0; j < MAX_COLS; j++) {
					for (int counter = 0; counter < 5; counter++) {
						if (player1.board_array[i][j] == character[counter]) are_any_ships_left_on_board1= 1;
						if  (player2.board_array[i][j] == character[counter]) are_any_ships_left_on_board2= 1 ;
					}
				}
			}
			printf("Are any ships left on board1: %d", are_any_ships_left_on_board1);
			printf("Are any ships left on board2: %d", are_any_ships_left_on_board2);
			if (are_any_ships_left_on_board1 && are_any_ships_left_on_board2) {
				printf("Player1 is now going!\n");
				player2 = check_shot(player2);
				
				display_board(player1);
				display_board(player2);
				check_if_sunk_ship(player2);
				printf("Alternating player...Player2(Computer) is now going!\n\n. . .Computer's shooting . . .\n");
				player1 = check_shot(player1);
				printf("Hit enter to continue!");
				char enter = getchar();
				while (enter != '\n') {
					getchar();
					printf("Please only hit enter and nothing else\nHit enter to continue!");
					enter = getchar();
				}
				system("cls||clear");
				display_board(player1);
				display_board(player2);
				check_if_sunk_ship(player1);
				
				
			}
		} while (are_any_ships_left_on_board1&&are_any_ships_left_on_board2);
		






	}
	//player2 goes
	else {
		printf("Player2 has been randomly selected to go first.\n\n. . .Computer's shooting . . .\n");
		getchar();
		do {
			are_any_ships_left_on_board1 = 0;
			are_any_ships_left_on_board2 = 0;
			for (int i = 0; i < MAX_ROWS; i++) {
				for (int j = 0; j < MAX_COLS; j++) {
					for (int counter = 0; counter < 5; counter++) {
						if (player1.board_array[i][j] == character[counter])are_any_ships_left_on_board1 = 1;
						if (player2.board_array[i][j] == character[counter])are_any_ships_left_on_board2 = 1;
					}
				}
			}
			if (are_any_ships_left_on_board1 && are_any_ships_left_on_board2) {
				
				player1 = check_shot(player1);
				
				printf("Hit enter to continue!");

				char enter = getchar();
				while (enter != '\n') {
					getchar();
					printf("Please only hit enter and nothing else\nHit enter to continue!");
					enter = getchar();
				}
				system("cls||clear");
				display_board(player1);
				display_board(player2);
				check_if_sunk_ship(player1);
				printf("Alternating player...Player1 is now going!\n");
				player2 = check_shot(player2);
				display_board(player1);
				display_board(player2);
				check_if_sunk_ship(player2);
				printf("Alternating player...Player2(Computer) is now going!\n\n. . .Computer's shooting . . .\n");
			}

			
		} while (are_any_ships_left_on_board1&&are_any_ships_left_on_board2);









	}
	//player winner
	if (!are_any_ships_left_on_board1 && !are_any_ships_left_on_board2)printf("Better start debugging, because no one has won!");
	else if (!are_any_ships_left_on_board1)printf("The computer(Player 2) has won! ");
	else if (!are_any_ships_left_on_board2)printf("Player1(You) has won! Congratulations");
	
}
/*Dir ship_direction = HORIZ;

	int row_start = 0, col_start = 0;

	char p1_board[MAX_ROWS][MAX_COLS] = { {'~', '~'}, {'~'} };

	

	init_board(p1_board, MAX_ROWS, MAX_COLS);
	print_board(p1_board, MAX_ROWS, MAX_COLS);

	ship_direction = gen_direction();

	gen_start_pt(ship_direction, 3, &row_start, &col_start);*/