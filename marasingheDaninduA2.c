/************************lastnameFirstnameA2.c**************
 Student Name: Danindu Marasinghe   Email Id: dmarasin@uoguelph.ca
Due Date: November 11th Course Name: CIS 1300
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic
integrity;
2) I have completed the Computing with Integrity Tutorial on Moodle; and
3) I have achieved at least 80% in the Computing with Integrity Self
Test.
I assert that this work is my own. I have appropriately acknowledged any
and all material that I have used, whether directly quoted or
paraphrased. Furthermore, I certify that this assignment was prepared by
me specifically for this course.
 ********************************************************/
#include "givenA2.h"

/******
 createInitialBoard: Creates the initial board array
 In: char 2d array for board
 Out: None
*******/
void createInitialBoard(char board[N][N]){
    int i, j;

    //initializing each element in the 2d array to a question mark
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            board[i][j] = '?';
        }
        
    }
    
}
int isBoardFull(char board[N][N]){
    printf("FIXME: is board full\n");
    return 0;
}
void readUserMove(int * userRow, int * userCol, int * stepsWon){
    printf("FIXME: Read User Move\n");
}

/******
 printCurrentBoard: Prints the current board
 In: char 2d array for board
 Out: None
 Post: Board gets printed
*******/
void printCurrentBoard(char board[N][N]){
    int i, j;

    //looping through each element of the board and printing it in tic-tac-toe format
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if(j < 2){
                //if not the last element in the row, print with the | character
                printf("%c | ", board[i][j]);
            }
            else{
                printf("%c", board[i][j]);
            }
        }
        //unless looping through last row, print the seperater dashes
        if(i < 2){
            printf("\n----------\n");
        }
        else{
            printf("\n");
        }
    }
    
}
void computerPlaysRandom(int * cRow, int * cCol){
    printf("FIXME: Computer plays random\n");
}
int computerPlaysToWin(char board [N][N], int * cRow, int * cCol){
    printf("FIXME: Computer plays to win\n");
    return 1;
}
int gameWon(char board[N][N], char symbol){
    printf("FIXME: Games won\n");
    return 1;
}
int isInputValid(int entered, int minimum, int maximum){
    printf("FIXME: Is input valid\n");
    return 1;
}
void all_sums(char board[N][N], int sumR[N], int sumC[N], int * sumLD, int * sumRD){
    printf("FIXME: all sums\n");
}
int memberOf(int value, int someArray[N]){
    printf("FIXME: member of\n");
    return 1;
}
int computerPlaysToBlock(char board[N][N], int * cRow, int * cCol){
    printf("FIXME: computer plays to block\n");
    return 1;
}