#include <stdio.h>
#include <stdlib.h>

struct Element {
    int row;
    int col;
    int value;
};

struct SparseMatrix {
    int rows;       
    int cols;       
    int numNonZero; 
    struct Element *elements; 
};

struct SparseMatrix createSparseMatrix(int matrix[][MAX_COLS], int rows, int cols) {
    struct SparseMatrix sparse;
    sparse.rows = rows;
    sparse.cols = cols;
    sparse.numNonZero = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse.numNonZero++;
            }
        }
    }
    sparse.elements = (struct Element *)malloc(sparse.numNonZero * sizeof(struct Element));

    int k = 0;     for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse.elements[k].row = i;
                sparse.elements[k].col = j;
                sparse.elements[k].value = matrix[i][j];
                k++;
            }
        }
    }

    return sparse;
}