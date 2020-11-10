#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3

void createInitialBoard(char[N][N]);  //done
void readUserMove(int *, int *, int *);  //done
void printCurrentBoard(char[N][N]);  //done
void computerPlaysRandom(int * , int *);
int computerPlaysToWin(char [N][N], int * , int * );
int getComputerMove(char board[N][N], int *, int *, int, int);
int gameWon(char [N][N], char);
int isInputValid(int, int, int);  //done
void all_sums(char board[N][N], int [N], int [N], int *, int *);
int memberOf(int value, int someArray[N]);
int isBoardFull(char board[N][N]);  //done
// you need the below prototype only if you attempt the additional functionality part
int computerPlaysToBlock(char [N][N], int * , int * );


