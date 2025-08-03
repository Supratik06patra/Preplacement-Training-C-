#include <stdbool.h>

bool isIdentityMatrix(int matrix[][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                if (matrix[i][j] != 1) {
                    return false;
                }
            } else {
                if (matrix[i][j] != 0) {
                    return false;
                }
            }
        }
    }
    return true;
}
