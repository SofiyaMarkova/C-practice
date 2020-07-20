#include <stdio.h>
#include <stdlib.h>

#define SUDOKU_SIZE 9
#define SQUARE_SIZE 3


typedef enum {
    false, true
} bool; //Provided to you because the C library
//for DevC++ does not support bool (originally was meant to be done in DevC++)

// ***** Do not change this matrix or you will have problems *****

int goodSudokuMatrix[SUDOKU_SIZE][SUDOKU_SIZE] =
        {
                {9, 3, 1, 6, 2, 8, 5, 4, 7},
                {7, 4, 2, 9, 1, 5, 6, 3, 8},
                {6, 5, 8, 4, 7, 3, 2, 9, 1},
                {3, 2, 9, 5, 8, 4, 1, 7, 6},
                {8, 1, 6, 2, 9, 7, 4, 5, 3},
                {4, 7, 5, 1, 3, 6, 8, 2, 9},
                {2, 6, 3, 8, 5, 9, 7, 1, 4},
                {5, 8, 7, 3, 4, 1, 9, 6, 2},
                {1, 9, 4, 7, 6, 2, 3, 8, 5}

        };
//The brokenSudokuMatrix should return false for all three categories of check

int badSudokuMatrix[SUDOKU_SIZE][SUDOKU_SIZE] =
        {
                {9, 3, 1, 6, 2, 8, 5, 4, 7},
                {7, 1, 2, 9, 1, 5, 6, 3, 8},
                {6, 5, 8, 4, 7, 3, 2, 9, 1},
                {3, 2, 9, 5, 8, 4, 1, 7, 6},
                {8, 1, 6, 2, 9, 7, 4, 5, 3},
                {4, 7, 5, 1, 3, 6, 8, 2, 9},
                {2, 6, 3, 8, 5, 9, 7, 1, 4},
                {5, 8, 7, 3, 4, 1, 9, 6, 2},
                {1, 9, 4, 7, 6, 2, 3, 8, 5}

        };

//******* Function prototypes for the functions that YOU MUST IMPLEMENET !!!!

bool VerifySudokuRows(int matrix[][SUDOKU_SIZE]);

bool VerifySudokuColumns(int matrix[][SUDOKU_SIZE]);

//Function prototype for provided utility functions

void PrintSudokuMatrix(int matrix[][SUDOKU_SIZE]);

bool VerifySudokuSquares(int matrix[][SUDOKU_SIZE]);

bool Check3X3Square(int matrix[][SUDOKU_SIZE], int rowStart, int columnStart);

// main
int main(int argc, char *argv[]) {
    //Declare all the variables you will need here
    bool goodSquares = false;
    bool goodRows = false;
    bool goodColumns = false;

    PrintSudokuMatrix(goodSudokuMatrix);
    printf("\n\n");

    //checking for 3x3 good sqaure
    goodSquares = VerifySudokuSquares(goodSudokuMatrix);
    if (goodSquares)
        printf("\ntrue");
    else
        printf("\nfalse");

    //1.       Call the VerifySudokuRows function for initialSudokuMatrix
    goodRows = VerifySudokuRows(goodSudokuMatrix);
    if (goodRows)
        printf("\ntrue");
    else
        printf("\nfalse");

    //2.       Call the VerifySudokuColumns function for initialSudokuMatrix
    goodColumns = VerifySudokuColumns(goodSudokuMatrix);
    if (goodColumns)
        printf("\ntrue");
    else
        printf("\nfalse");
    //3.       Print true on the screen if all three functions return true else print false
    if (goodSquares && goodRows && goodColumns)
        printf("\ntrue");
    else
        printf("\nfalse");

    printf("\n\n");
    system("PAUSE");
    return 0;
}//Main

///////////////////////////////////////////////////////////////////////////////
//
// Function: VerifySudokuRows
//
// Author: YOU
//
// Description: This function must check all the rows in the matrix for single 
//              occurence of each number from 1-9 in a Sudoku row. The function
//              returns true if the numbers only appear once per row else it returns false.
//
///////////////////////////////////////////////////////////////////////////////

bool VerifySudokuRows(int matrix[][SUDOKU_SIZE]) {
    //make array so keep track of what numbers already seen. all start with 0 when not seen. when seen it changes to 1
    //so at end to know if had repeating/missing numbers need to check that all vals in made array == 1
    int numSawCheck[9] = { 0 }; // all elements 0;//makes array: sets aside 9 * sizeof(int) bytes on the stack for that array, but doesn't initialize them. with the {0} does initialize

    for (int i = 0; i < SUDOKU_SIZE; i++) {
        for (int j = 0; j < SUDOKU_SIZE; j++) {
            numSawCheck[matrix[i][j] - 1] = numSawCheck[matrix[i][j] - 1] + 1; //at location that 1 less than number seen. because if see number 1, it is actually at array position [0]. do ++ the number there of array
        }
        //check in this row if all the number were seen => all value in array need be == 1
        for (int k = 0; k < sizeof(numSawCheck) / sizeof(numSawCheck[0]); k++) {
            if (numSawCheck[k] != 1) {
                return false;
            }
            //reset array used for checking, so that it can check again from scratch. doing here because traversing array anyways
            numSawCheck[k] = 0; //maybe not need actually
        }
    }

    return true; //because if managed to go through all rows and now catch a row where made the numSawCheck have 1 that not 1, then it means all rows good
}

///////////////////////////////////////////////////////////////////////////////
//
// Function: VerifySudokuColumns
//
// Author: YOU
//
// Description: This function must check all the columns in the matrix for single 
//              occurence of each number from 1-9 in a Sudoku column. The function
//              returns true if the numbers only appear once per column else it returns false.
//
///////////////////////////////////////////////////////////////////////////////

bool VerifySudokuColumns(int matrix[][SUDOKU_SIZE]) {
//same logic with check, just for loop done in way so traverse by col

//make array so keep track of what numbers already seen. all start with 0 when not seen. when seen it changes to 1
    //so at end to know if had repeating/missing numbers need to check that all vals in made array == 1
    int numSawCheck[9] = { 0 };
    for (int col = 0; col < SUDOKU_SIZE; col++) {
        for (int row = 0; row < SUDOKU_SIZE; row++) {
            numSawCheck[matrix[row][col] - 1] = numSawCheck[matrix[row][col] - 1] + 1; //at location that 1 less than number seen. because if see number 1, it is actually at array position [0]. do ++ the number there of array
        }
        //check in this row if all the number were seen => all value in array need be == 1
        for (int k = 0; k < sizeof(numSawCheck) / sizeof(numSawCheck[0]); k++) {
            if (numSawCheck[k] != 1) {
                return false;
            }
            //reset array used for checking, so that it can check again from scratch. doing here because traversing array anyways
            numSawCheck[k] = 0; //maybe not need actually
        }
    }
    return true; //because if managed to go through all rows and now catch a row where made the numSawCheck have 1 that not 1, then it means all rows good
}

///////////////////////////////////////////////////////////////////////////////
//
// Function: PrintSudokuMatrix
//
// Author: not you
//
// Description: This function prints a matrix to the standard IO
//
///////////////////////////////////////////////////////////////////////////////

void PrintSudokuMatrix(int matrix[][SUDOKU_SIZE]) {
    int row;
    int col;
    printf("\n");

    for (row = 0; row < SUDOKU_SIZE; row++) {
        if (row % 3 == 0)                           //seperate every 3 rows
            printf(" --------------------------\n");
        for (col = 0; col < SUDOKU_SIZE; col++) {
            if (col % 3 == 0) //separate every 3 coloumns
                printf(" | ");

            printf("%2d", matrix[row][col]);
        }
        printf("\n");
    }
    printf("\n");
    return;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function: Verify3X3Squares
//
// Author: not you
//
// Description: This function verifies each 3X3 block in a 9X9 Sudoku puzzle
//
///////////////////////////////////////////////////////////////////////////////
bool VerifySudokuSquares(int matrix[][SUDOKU_SIZE]) {

    int square;

    //for each 3X3 matrix inside the Sudoku grid check that each number appears only once
    for (square = 0; square < 9; square++) {
        //for each 3X3 square check if numbers do not repeat by calling Check3X3Square

        switch (square) {
            case 0: //The top left corner 3X3 matrix
                if (Check3X3Square(matrix, 0, 0))
                    continue;
                else
                    return false;
            case 1:
                if (Check3X3Square(matrix, 0, 3))
                    continue;
                else
                    return false;
            case 2:
                if (Check3X3Square(matrix, 0, 6))
                    continue;
                else
                    return false;
            case 3:
                if (Check3X3Square(matrix, 3, 0))
                    continue;
                else
                    return false;
            case 4: //centered 3X3 matrix
                if (Check3X3Square(matrix, 3, 3))
                    continue;
                else
                    return false;
            case 5:
                if (Check3X3Square(matrix, 3, 6))
                    continue;
                else
                    return false;
            case 6:
                if (Check3X3Square(matrix, 6, 0))
                    continue;
                else
                    return false;
            case 7:
                if (Check3X3Square(matrix, 6, 3))
                    continue;
                else
                    return false;
            case 8: //Bottom right 3X3 matrix
                if (Check3X3Square(matrix, 6, 6))
                    continue;
                else
                    return false;
            default:
                return false;


        }// switch
    } //for i
    return true;

}

///////////////////////////////////////////////////////////////////////////////
//
// Function: Verify3X3Squares
//
// Author: not you
//
// Description: This function verifies that each number only appears once in a 
//              Sudoku square 3X3. Returns false if repeats true otherwise.
//
///////////////////////////////////////////////////////////////////////////////

bool Check3X3Square(int matrix[][SUDOKU_SIZE], int rowStart, int columnStart) {

    int j, k; //loop counters for rows and columns of Squares

    /*Init verificationVector values to false to identify that no number has yet been reported.
      *** During execution of the function: If a number is found in a square its relative position
      is set to true in the verificationVector;. If the value at the index was already true;
      meaning the number was already found in the square the function returns false. */

    bool verificationVector[9] = {false, false, false, false, false, false, false, false, false};

    /*the verificationIndex variable below is used as an index to identify the relative
      position of numbers that were found in a square.
      *** REMEMBER C is zero index based but Sudoku goes from 1-9 */


    int verificationIndex;

    //check three rows by three columns at a time
    for (j = rowStart; j < (rowStart + 3); j++) {
        for (k = columnStart; k < (columnStart + 3); k++) {

            //calculate relative position of the number in verificationVector
            verificationIndex = matrix[j][k] - 1;

            if (verificationIndex < 0 || verificationIndex > 8)
                return false;

            //check for first report of number if yes set flag else return error
            if (verificationVector[verificationIndex] == false)
                verificationVector[verificationIndex] = true;
            else
                return false;

        }// for k

    }// for j

    return true;
}
