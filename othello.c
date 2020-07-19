#include <stdio.h>
#include <stdlib.h>

#define COLUMN_SIZE 8
#define ROW_SIZE 8
#define BLACK -1
#define WHITE 1
#define EMPTY 0


// ***** Do not change the array or you will have problems *****

char OthelloArray[ROW_SIZE][COLUMN_SIZE] =
        {
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', 'B', ' '},
                {' ', ' ', ' ', 'W', 'W', 'B', 'B', ' '},
                {' ', ' ', 'B', 'B', 'W', 'W', ' ', ' '},
                {' ', ' ', ' ', 'B', 'W', 'W', ' ', ' '},
                {' ', ' ', ' ', 'B', 'W', 'W', ' ', ' '},
                {' ', ' ', ' ', 'B', 'W', 'B', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', 'B', ' '},

        };

//***** This array contains the counts in the following order 'B', 'W', ' ' *****

int counts[3] = {0, 0, 0}; //3 for the 1D array parameter because counts[0] = black,counts[1] = white,counts[2] = empty (3 spaces in all)

//******* Function prototypes for the functions that YOU MUST COMPLETE !!!!

void DecodeGrid(char OthelloArray[][COLUMN_SIZE], int counts[]);

int DecodeElement(char element);

//Function prototype for provided utility functions *** This function is done ***

void PrintOthello(char OthelloArray[][COLUMN_SIZE], int counts[]);

// main
int main(int argc, char *argv[]) {
    //Declare all the variables you will need here

    //1.       Call the DecodeGrid function and put the results in counts

    DecodeGrid(OthelloArray, counts);

    printf("Othello Square Array and Results:\n\n");

    //2.       Call the PrintOthello function with the actual parameters

    PrintOthello(OthelloArray, counts);

    printf("\n\n");
    system("PAUSE");
    return 0;

}//Main


///////////////////////////////////////////////////////////////////////////////
//
// Function: DecodeGrid 
//
// Author: YOU 
//
// Description: This function must call the function DecodeElement for each
//              element in each column in each row.
//
///////////////////////////////////////////////////////////////////////////////

void DecodeGrid(char OthelloArray[][COLUMN_SIZE], int counts[]) {
    int row, column, value;
    //for every row of the initial Othello square
    // for every element in each row, call DecodeElement
    //and update the results in the appropriate counts array index

    int atLocation;
    for(row = 0; row < ROW_SIZE; row++){
        for(column = 0; column < COLUMN_SIZE; column++){
            atLocation = DecodeElement(OthelloArray[row][column]);
            switch(atLocation){
                case -1:
                    counts[0]++;
                    break;
                case 1:
                    counts[1]++;
                    break;
                case 0:
                    counts[2]++;
                    break;
            }
        }

    }


}

///////////////////////////////////////////////////////////////////////////////
//
// Function: DecodeElement 
//
// Author: YOU
//
// Description: This function must decode each element and return BLACK, WHITE or EMPTY.
//
//           
//
///////////////////////////////////////////////////////////////////////////////

int DecodeElement(char element) {
    // Decode each character and return the appropriate in constant BLACK, WHITE OR EMPTY
    if (element == 'B') {
        return BLACK;
    } else if (element == 'W') {
        return WHITE;
    } else if (element == ' ') {
        return EMPTY;
    }

}

///////////////////////////////////////////////////////////////////////////////
//
// Function: PrintOthello 
//
// Author: not you
//
// Description: This function prints the Oritinal Othello Square and the results
//
//
//
///////////////////////////////////////////////////////////////////////////////
void PrintOthello(char OthelloArray[][COLUMN_SIZE], int counts[]) {
    int row, column, i;

    printf("Original Othello Square: \n\n");
    //for each row of the Othello Square 

    for (row = 0; row < ROW_SIZE; row++) {
        //for every element in each row print the character

        for (column = 0; column < COLUMN_SIZE; column++) {
            printf("'%c'  ", OthelloArray[row][column]);


        }//end for column

        printf("\n");

    }//for row
    printf("\n\n Results of the Game: \n\n");

    printf("\n\nBlacks : %d", counts[0]);
    printf("\nWhites : %d", counts[1]);
    printf("\nEmpties: %d", counts[2]);
}//end PrintOthello
