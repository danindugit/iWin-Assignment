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

/*********************************************************
Compiling the program
The program should be compiled using the following flags: -std=c99 -Wall
compiling:
gcc givenA2.c marasingheDaninduA2.c -std=c99 -Wall
OR
gcc givenA2.c marasingheDaninduA2.c -std=c99 -Wall -o assn2
Running the Program
Running: ./a.out
 OR
 Running: ./assn2
*********************************************************/
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

/******
 isBoardFull: Checks if the board is full
 In: char 2d array for board
 Out: true or false int
*******/
int isBoardFull(char board[N][N]){
    int i, j;

    //looping through each character on the board to see if any are untaken
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if(board[i][j] == '?'){
                return 0;
            }
        }
        
    }
    return 1;
}

/******
 readUserMove: reads user move and increments user's stepsWon if the input is valid
 In: variables for user's choice for row and column and number of steps
 Out: None
 Post: Scans for user's row and column
*******/
void readUserMove(int * userRow, int * userCol, int * stepsWon){
    int rowIn, colIn; //variables for input

    printf("Your move - enter numbers between 1 and 3\n");
    //get row input
    printf("Enter row number: \n");
    scanf("%d", &rowIn);
    //get column input
    printf("Enter column number: \n");
    scanf("%d", &colIn);
    //set userRow and userCol variables to corresponding inputs
    *userRow = rowIn;
    *userCol = colIn;
    //if input is valid, increment stepsWon
    if(isInputValid(rowIn, 1, N) && isInputValid(colIn, 1, N)){
        *stepsWon += 1;
    }
}

/******
 isInputValid: checks if user input is within minimum and maximum limits
 In: user's entered value, the min and max values
 Out: Boolean int
*******/
int isInputValid(int entered, int minimum, int maximum){
    if((entered >= minimum) && (entered <= maximum)){
        //if entered input is within minimum and maxiumum, return true
        return 1;
    }
    else{
        //otherwise, return false
        return 0;
    }
}

/******
 gameWon: Checks if we have a winner
 In: char 2d array for board and symbol to determine whether we are checking for user win or cpu win
 Out: boolean int
*******/
int gameWon(char board[N][N], char symbol){
    int i;
    int rowScores[N];  //scores for rows
    int colScores[N];  //scores for columns
    int sumLD, sumRD;  //scores for the diagonals
    int winningScore;

    //initialize diagonals scores
    sumLD = 0;
    sumRD = 0;

    //set winning score based on symbol input
    if(symbol == 'X'){
        winningScore = 3;
    }
    else if(symbol == 'O'){
        winningScore = 12;
    }

    for (i = 0; i < N; i++)
    {
        //initialize each element in rowScores and colScores to 0
        rowScores[i] = 0;
        colScores[i] = 0;
    }
    
    all_sums(board, rowScores, colScores, &sumLD, &sumRD);
    
    for (i = 0; i < N; i++)
    {
        //loop through each column and row score and check if they have winning scores
        if(rowScores[i] == winningScore || colScores[i] == winningScore){
            //we have a winner by row or column
            return 1;
        }
    }
    //check if the diagonals have winning scores
    if(sumRD == winningScore || sumLD == winningScore){
        //we have a winner by left or right diagonal
        return 1;
    }

    return 0; //no winner    
}

/******
 all_sums: calculates sums of scores for each row, column, and diagonal
 In: board array, arrays for row and column scores, integers for left diagonal score and right diagonal score
 Out: None
*******/
void all_sums(char board[N][N], int sumR[N], int sumC[N], int * sumLD, int * sumRD){
    int i, j;

    //loop through each element of board
    for (i = 0; i < N; i++)
    {
        if(board[i][i] == 'X'){
            //if element on the right diagonal is X, add 1 to right diagonal score
            *sumRD += 1;
        }
        else if(board[i][i] == 'O'){
            //if element on the right diagonal is O, add 4 to right diagonal score
            *sumRD += 4;
        }

        if(board[i][N-i-1] == 'X'){
            //if element on the left diagonal is X, add 1 to left diagonal score
            *sumLD += 1;
        }
        else if(board[i][N-i-1] == 'O'){
            //if element on the left diagonal is O, add 4 to left diagonal score
            *sumLD += 4;
        }
        
        for (j = 0; j < N; j++)
        {
            if(board[i][j] == 'X'){
                //if element is an X, add 1 to corresponding row and column
                sumR[i] += 1;
                sumC[j] += 1;
            }
            else if(board[i][j] == 'O'){
                //if element is an O, add 4 to corresponding row and column
                sumR[i] += 4;
                sumC[j] += 4;
            }
        }
        
    }
}

/******
 computerPlaysToWin: Looks for a spot on the board where computer can win, if so, places an O there
 In: char 2d array for board, cpu choice of row and column
 Out: boolean int for whether the cpu can win or not
*******/
int computerPlaysToWin(char board [N][N], int * cRow, int * cCol){
    int i, j;
    int rowScores[N];  //scores for rows
    int colScores[N];  //scores for columns
    int sumLD, sumRD;  //scores for the diagonals
    int winableScore;

    //initialize diagonals scores
    sumLD = 0;
    sumRD = 0;

    //set winning score
    winableScore = 8;

    for (i = 0; i < N; i++)
    {
        //initialize each element in rowScores and colScores to 0
        rowScores[i] = 0;
        colScores[i] = 0;
    }

    all_sums(board, rowScores, colScores, &sumLD, &sumRD);

    //check if the diagonals have winning scores
    if(sumRD == winableScore){
        //cpu can win by right diagonal
        //loop to find empty spot
        for (i = 0; i < N; i++)
        {
            if(board[i][i] == '?'){
                //set cpu's winning spot
                *cRow = i;
                *cCol = i;
                //makes the move
                board[i][i] = 'O';
            }
        }
        return 1;    
    }
    else if (sumLD == winableScore){
        //cpu can win by left diagonal
        //loop to find empty spot
        for (i = 0; i < N; i++)
        {
            if(board[i][N - i - 1] == '?'){
                //set cpu's winning spot
                *cRow = i;
                *cCol = N - i - 1;
                //makes the move
                board[i][N - i - 1] = 'O';
            }
        }
        return 1;
    }

    //loop through each column and row score and check if they have winnable scores
    for (i = 0; i < N; i++)
    {       
        if(rowScores[i] == winableScore){
            //cpu can win by row
            //loop to find empty spot
            for(j = 0; j < N; j++){
                if(board[i][j] == '?'){
                    //set cpu's winning spot
                    *cRow = i;
                    *cCol = j;
                    //makes the move
                    board[i][j] = 'O';
                }
            }

            return 1;
        } 
        else if (colScores[i] == winableScore){
            //cpu can win by column
            //loop to find empty spot
            for(j = 0; j < N; j++){
                if(board[j][i] == '?'){
                    //set cpu's winning spot
                    *cRow = j;
                    *cCol = i;
                    //makes the move
                    board[j][i] = 'O';
                }
            }

            return 1;
        }
    }

    return 0;
}

/******
 computerPlaysToBlock: Looks for a spot on the board where computer can block, if so, places an O there
 In: char 2d array for board, cpu choice of row and column
 Out: boolean int for whether the cpu can block or not
*******/
int computerPlaysToBlock(char board[N][N], int * cRow, int * cCol){
    int i, j;
    int rowScores[N];  //scores for rows
    int colScores[N];  //scores for columns
    int sumLD, sumRD;  //scores for the diagonals
    int blockableScore;

    //initialize diagonals scores
    sumLD = 0;
    sumRD = 0;

    //set blockable score
    blockableScore = 2;

    for (i = 0; i < N; i++)
    {
        //initialize each element in rowScores and colScores to 0
        rowScores[i] = 0;
        colScores[i] = 0;
    }

    all_sums(board, rowScores, colScores, &sumLD, &sumRD);

    //check if the diagonals have blockable scores
    if(sumRD == blockableScore){
        //cpu can block by right diagonal
        //loop to find empty spot
        for (i = 0; i < N; i++)
        {
            if(board[i][i] == '?'){
                //set cpu's blocking spot
                *cRow = i;
                *cCol = i;
                //makes the move
                board[i][i] = 'O';
            }
        }
        return 1;    
    }
    else if (sumLD == blockableScore){
        //cpu can block by left diagonal
        //loop to find empty spot
        for (i = 0; i < N; i++)
        {
            if(board[i][N - i - 1] == '?'){
                //set cpu's blocking spot
                *cRow = i;
                *cCol = N - i - 1;
                //makes the move
                board[i][N - i - 1] = 'O';
            }
        }
        return 1;
    }

    //loop through each column and row score and check if they have blockable scores
    for (i = 0; i < N; i++)
    {       
        if(rowScores[i] == blockableScore){
            //cpu can block by row
            //loop to find empty spot
            for(j = 0; j < N; j++){
                if(board[i][j] == '?'){
                    //set cpu's blocking spot
                    *cRow = i;
                    *cCol = j;
                    //makes the move
                    board[i][j] = 'O';
                }
            }

            return 1;
        } 
        else if (colScores[i] == blockableScore){
            //cpu can block by column
            //loop to find empty spot
            for(j = 0; j < N; j++){
                if(board[j][i] == '?'){
                    //set cpu's blocking spot
                    *cRow = j;
                    *cCol = i;
                    //makes the move
                    board[j][i] = 'O';
                }
            }

            return 1;
        }
    }

    return 0;
}

/******
 computerPlaysRandom: generates a random position for the cpu to play
 In: cpu row and column
 Out: None
*******/
void computerPlaysRandom(int * cRow, int * cCol){
    //select 2 random integers between 0 and 2 to set for cpu row and column
    *cRow = rand() % 3;
    *cCol = rand() % 3;
}

/******
 printCurrentBoard: Prints the current board
 In: char 2d array for board
 Out: None
 Post: Board gets printed
*******/
void printCurrentBoard(char board[N][N]){
    int i, j;

    printf("Current board now is: \n");

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

/******
 memberOf: Looks for a value in an array
 In: the value and the array
 Out: boolean int for whether the value is found or not
*******/
int memberOf(int value, int someArray[N]){
    int i; 

    for (i = 0; i < N; i++)
    {
        if(someArray[i] == value){
            //if the value is found in the array, return 1
            return 1;
        }
    }
    //if not, return 0
    return 0;
}