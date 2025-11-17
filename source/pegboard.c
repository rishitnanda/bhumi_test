#include<stdio.h>
#include "pegboard.h"

void setup_board(char board[BOARD_SIZE][BOARD_SIZE]){
    for( int i=0; i<BOARD_SIZE; i++){
       for( int j=0; j<BOARD_SIZE; j++){
            board[i][j] = '.';
        }
    }
    board[0][0] = ' ';
    board[0][BOARD_SIZE-1] = ' ';
    board[BOARD_SIZE-1][0] = ' ';
    board[BOARD_SIZE-1][BOARD_SIZE-1] = ' ';
}


void display_board(char board[BOARD_SIZE][BOARD_SIZE]){
    printf("   ");
    for( int i=0; i< BOARD_SIZE; i++){
        printf("%2d ",i);
    }
    printf("\n");
        for( int i=0; i<BOARD_SIZE; i++){
            printf("%2d ",i);
            
              for( int j=0; j<BOARD_SIZE; j++){
            char x= board[i][j];
            if( x == '.'){
                printf(" . ");
            }
            else if(x == 'X'){
             printf(" X ");
             }
            else if(x == '0'){
            printf(" 0 ");
         }
            else {
                printf("   ");
            }
        }
        printf("\n");
    }
}

int box_empty(char board[BOARD_SIZE][BOARD_SIZE],int a, int b){
    
    if( board[a][b] == '.'){
        return 1;
    }
    else{
        return 0;
    }
}
int correct_position(int a, int b){
    if(a<BOARD_SIZE && a>=0 && b>=0 && b<BOARD_SIZE){
        return 1;
    }
    else{
        return 0;
    }
}
int position_peg(char board[BOARD_SIZE][BOARD_SIZE],int a,int b,char player){
    if(correct_position(a, b) !=1 ){
        printf("Invalid Position\n");
        return 0;
    }
    
    if(board[a][b] == ' '){
        printf("Position disabled\n");
        return 0;
    }

    if(player == 'X' && (b == 0 || b == BOARD_SIZE-1)){
        printf("Player X cannot place in columns 0 or %d\n", BOARD_SIZE-1);
        return 0;
    }
    
    if(player == '0' && (a == 0 || a == BOARD_SIZE-1)){
        printf("Player 0 cannot place in rows 0 or %d\n", BOARD_SIZE-1);
        return 0;
    }
    if(box_empty(board,a,b) != 1){
        printf("Box already occupied\n");
        return 0;
    }
    board[a][b] = player;
    return 1;
}
// int path(char board[BOARD_SIZE][BOARD_SIZE],int a, int b,int marked[BOARD_SIZE][BOARD_SIZE],char player){
//     if(b<0 || a<0 || b>=BOARD_SIZE || a>=BOARD_SIZE){
//         return 0;
//     }
//     if(board[a][b] != player){
//         return 0;
//     }
//     if(marked[a][b] == 1){
//         return 0;
//     }
    
//     marked[a][b] = 1;
//     if((player == 'X' && a == BOARD_SIZE-1) || (player == '0' && b == BOARD_SIZE-1)){
//         return 1;
//     }
//     int arr_a[] ={-2,-1,1,2};
//     int arr_b[] ={-1,-2,2,1};
//     for(int j=0; j<4;j++){
//         if(path(board,a+arr_a[j],b+arr_b[j],marked,player) == 1){
//             return 1;
//         }
//     }
//     return 0;
//}
    // int win(char board[BOARD_SIZE][BOARD_SIZE],char player){
    //     int marked[BOARD_SIZE][BOARD_SIZE] = {0};
    //     if(player == 'X'){
    //         for(int i=0; i<BOARD_SIZE; i++){
    //             if(board[0][i] == player && path(board,0,i,marked,player)){
    //                 return 1;
    //             }
    //         }
    //     }
    //     else{
    //         for(int i=0; i<BOARD_SIZE; i++){
    //             if(board[i][0] == player && path(board,i,0,marked,player)){
    //                 return 1;
    //             }
    //         }
    //     }
    //return 0;
//}





