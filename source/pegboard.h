#ifndef PEGBOARD_H
#define PEGBOARD_H
#define BOARD_SIZE 24

void setup_board(char board[BOARD_SIZE][BOARD_SIZE]);
void display_board(char board[BOARD_SIZE][BOARD_SIZE]);
int position_peg(char board[BOARD_SIZE][BOARD_SIZE],int a,int b,char player);
int correct_position(int a, int b);
int box_empty(char board[BOARD_SIZE][BOARD_SIZE],int a, int b);
// int path(char board[BOARD_SIZE][BOARD_SIZE],int a, int b,int marked[BOARD_SIZE][BOARD_SIZE],char player);
// int win(char board[BOARD_SIZE][BOARD_SIZE],char player);
#endif
