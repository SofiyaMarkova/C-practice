#include <stdio.h>
#include <stdbool.h>

#define SIZE 9


bool verify_row(int row[]);

bool verify_col(int matrix[][SIZE], int col);

bool verify_square(int matrix[][SIZE], int row, int col);

bool verify_matrix(int matrix[][SIZE]);


void main(void) {

    int sudokuMatrix[SIZE][SIZE] =
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
            
            
            int badSudokuMatrix[SIZE][SIZE] =
        {
                {9,3,1, 6,2,8, 5,4,7},
                {7,1,2, 9,1,5, 6,3,8},
                {6,5,8, 4,7,3, 2,9,1},
                {3,2,9, 5,8,4, 1,7,6},
                {8,1,6, 2,9,7, 4,5,3},
                {4,7,5, 1,3,6, 8,2,9},
                {2,6,3, 8,5,9, 7,1,4},
                {5,8,7, 3,4,1, 9,6,2},
                {1,9,4, 7,6,2, 3,8,5}
        };
            
if(verify_matrix(badSudokuMatrix)){
   printf("works matrix");
}
else{
    printf("nope matrix");
}

    //verify_matrix();
//checks row,col,square (calls from inside it)


}

bool verify_row(int row[]) {

    //make array of all zeros
    int check[9] = {0};

    //fill up based on what number sees
    for (int i = 0; i < SIZE; i++) {
        if (++check[row[i] - 1] == 2) {
            return false;
        }
    }

    return true;

}

bool verify_col(int matrix[][SIZE], int col){
    //make array of all zeros
    int check[9] = {0};

    //fill up based on what number sees
    for (int i = 0; i < SIZE; i++) {
        if (++check[matrix[i][col] - 1] == 2) {
            return false;
        }
    }

    return true;
    
}


bool verify_square(int matrix[][SIZE], int row, int col){
        //make array of all zeros
    int check[9] = {0};

    //fill up based on what number sees
    
    //row
    for(int i = row; i < 3; i++){
       
       //col
        for (int j = col; j < 3; j++) {
        if (++check[matrix[i][j] - 1] == 2) {
            return false;
        }
    }

        
    }
   
    return true;
    
}


bool verify_matrix(int matrix[][SIZE]){
    //check all rows
    //starts from 0 row. calls function on each row passed as i. going until all rows done
    for(int i = 0; i < SIZE; i++){
        
        //if find a row that false ==> return false on this function
       if(verify_row(matrix[i]) == false || verify_col(matrix, i) == false){
           return false;
       } 
    }

    
   //check if all squares
    for(int k = 0; k < SIZE; k+=3){
        
        for(int m = 0; m < SIZE; m+=3){
             if(verify_square(matrix, k, m) == false){
                 return false;
             }
        }
       
    }
    
    
    return true;
    
    
}