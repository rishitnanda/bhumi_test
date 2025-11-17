#include <stdio.h>
#include "pegboard.h"

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    setup_board(board);
    
    char player = '0';
    int a,b;
    int moves =0;

    while(moves<20){
        display_board(board);
        printf("Player %c : ",player);
        int scan_flag;
        do {
             if (scanf("%d %d",&a,&b)!=2)
            {
            int temp = getchar();
            while (temp != '\n' && temp!= EOF)
            {
                temp = getchar();
            }
            scan_flag = 0;
            printf("Please enter valid data type : ");

            }
            else
            {
                scan_flag = 1;
            }
        }while (scan_flag != 1);
        
        if(position_peg(board,a,b,player)){
            moves++;
            if(player == '0'){
                player = 'X';
            }
            else if(player == 'X'){ 
                 player = '0';
            } 
        }
        else{
            printf("Invalid position\n");
        }
        }
    display_board(board);
    return 0;
}
