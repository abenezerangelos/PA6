#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#define MAX_ROWS 10
#define MAX_COLS 10
#define MAX 5000
#define size_for_carriers 20
#define size_for_battleship 16
#define size_for_cruiser 12
#define size_for_submarine 12
#define size_for_destroyer 8


typedef enum dir
{
	HORIZ, VERT
} Dir;

typedef struct board {
	char board_array[MAX_ROWS][MAX_COLS];
	int identifier;
	int ship_position_memory[50];
	int user_input_memory[201];
	
}Board;
typedef struct game {
	Board one;
	Board two;
}Game;
typedef struct stats {
	char player1_stat[1000];
	char player2_stat[1000];
	

};

//void init_board(char board[][MAX_COLS], int num_rows, int num_cols);
//void print_board(char board[][MAX_COLS], int num_rows, int num_cols);
//
//Dir gen_direction(void);
//void gen_start_pt(Dir direction, int ship_length, int* start_row_ptr,
//	int* start_col_ptr);

static int size_array[5] = { size_for_carriers, size_for_battleship, size_for_cruiser, size_for_submarine, size_for_destroyer };
static char strings[][12] = { "Carrier", "Battleship","Cruiser","Submarine","Destroyer" };
static char character[5] = { 'c','b','r','s','d' };

int welcome_screen();
Game print_game_board();
int select_who_starts_first();
Board manually_place_ships_on_board(Board player1);
Board randomly_place_ships_on_board(Board players);
Board check_shot(Board player);
int is_winner();
void update_board();
void display_board(Board player_board);
void output_current_move();
void check_if_sunk_ship(Board player);
void output_stats();