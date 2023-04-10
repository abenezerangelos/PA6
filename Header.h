#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <time.h>
#include <string.h>
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



int welcome_screen();
Game print_game_board();
int select_who_starts_first();
int manually_place_ships_on_board(Game boards);
int randomly_place_ships_on_board();
int check_shot();
int is_winner();
void update_board();
void display_board(Board player_board);
void output_current_move();
void check_if_sunk_ship();
void output_stats();