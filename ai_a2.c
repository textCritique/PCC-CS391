#include <stdio.h>
#include <stdlib.h>

int** alloc_mem(int rows, int cols) {
    int** array = malloc(rows * sizeof(int*));
    if (!array) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < rows; i++) {
        array[i] = malloc(cols * sizeof(int));
        if (!array[i]) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
    }
    return array;
}

void input_matrix(int** m, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

void display_matrix(int** m, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", m[i][j]);
        }
        putchar('\n');
    }
}

void mult_matrix(int** res, int** a, int** b,
                 int rows_a, int cols_a, int cols_b) {
    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols_b; j++) {
            res[i][j] = 0;
            for (int k = 0; k < cols_a; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main(void) {
    int r, c;
    printf("Enter number of rows: ");
    scanf("%d", &r);
    printf("Enter number of columns: ");
    scanf("%d", &c);

    int** m1 = alloc_mem(r, c);
    int** m2 = alloc_mem(r, c);

    input_matrix(m1, r, c);
    input_matrix(m2, r, c);

    // Addition
    int** sum = alloc_mem(r, c);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            sum[i][j] = m1[i][j] + m2[i][j];

    puts("\nSum:");
    display_matrix(sum, r, c);

    // Subtraction
    int** diff = alloc_mem(r, c);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            diff[i][j] = m1[i][j] - m2[i][j];

    puts("\nDifference:");
    display_matrix(diff, r, c);

    // Multiplication (requires square or cols of m1 == rows of m2)
    int** prod = alloc_mem(r, c);
    mult_matrix(prod, m1, m2, r, c, c);

    puts("\nProduct:");
    display_matrix(prod, r, c);

    // Cleanup
    for (int i = 0; i < r; i++) {
        free(m1[i]); free(m2[i]);
        free(sum[i]); free(diff[i]); free(prod[i]);
    }
    free(m1); free(m2);
    free(sum); free(diff); free(prod);

    return 0;
}