#include <stdio.h>
#include <stdlib.h>

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    
    int aux, col_start, col_end;
    aux = 0;
    
    for(int i = 0; i < matrixSize; i++)
    {
        for(int j = i+1; j < *matrixColSize; j++)
        {
            aux = matrix[j][i];
            matrix[j][i] = matrix[i][j];
            matrix[i][j] = aux;
            
        }
    }
    
    for(int line = 0; line < matrixSize; line++)
    {
        col_start = 0;
        col_end = *matrixColSize-1;
        
        while(col_start < col_end)
        {
            aux = matrix[line][col_end];
            matrix[line][col_end] = matrix[line][col_start];
            matrix[line][col_start] = aux; 
            col_start++;
            col_end--;
        }
        
    }
    
}