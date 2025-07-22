#include <stdio.h>
#include <stdlib.h>

void display_matrix(int row,int col,int array[row][col]){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++) {
            printf("%d ",array[i][j]);
        }
    puts("");
    }
}
void mult_matrix(int** matrix1,int row,int col,int** matrix2,int row2, int col2,int result[row][col2]) {
    if (row2 != col) {
        // not compatible for multiplication 
        return;
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < col; k++) {
                result[i][j] += matrix1[i][k]*matrix2[k][j];
            }
        }
    }
}

int** init_matrix(int rows,int cols){
    int **matrix = malloc(rows*sizeof(int*));
    if (!matrix) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols*sizeof(int));
        if (!matrix[i]) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        for (int j = 0; j < cols; j++) {
            printf("Enter the %d,%d element: ",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
    return matrix;
}
int main(){
    int rowsize, colsize;
    puts("Enter the no of rows:");
    scanf("%d",&rowsize);
    puts("Enter the no of columns:");
    scanf("%d",&colsize);

    int** matrix1 = init_matrix(rowsize,colsize);
    int** matrix2 = init_matrix(rowsize,colsize);

    // addition 
    int sum_matrix[rowsize][colsize];
    for (int i = 0; i < rowsize; i++) {
        for (int j = 0; j < colsize; j++) {
            sum_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }  
    }
    puts("Addition of given matrices is ");
    display_matrix(rowsize,colsize,sum_matrix);

    // subtraction
    int difference_matrix[rowsize][colsize];
    for (int i = 0; i < rowsize; i++) {
        for (int j = 0; j < colsize; j++) {
            difference_matrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }      
    }
    puts("Substraction of given matrices is");
    display_matrix(rowsize,colsize,difference_matrix);
    // multiplication
    int product_matrix[rowsize][colsize];
    mult_matrix(matrix1,rowsize,colsize,matrix2,rowsize,colsize,product_matrix);
    puts("Prooduct of given matrices are: ");
    display_matrix(rowsize,colsize,product_matrix);

    //reversing the 1d char array
    puts("Enter the length of string: ");
    int len;
    scanf("%d",&len);
    char* string = malloc((len+1)*sizeof(char));
    puts("Enter the string: ");
    scanf("%s",string);
    char temp;
    for (int i = 0; i < len/2; i++) {
        temp = string[i];
        string[i] = string[len-i-1];
        string[len-i-1] = temp;
    }
    puts("Reversed string: ");
    puts(string);
    free(string);

    // linear search column wise 
    puts("Enter the no of rows:");
    scanf("%d",&rowsize);
    puts("Enter the no of columns:");
    scanf("%d",&colsize);
    int** array = init_matrix(rowsize,colsize);
    puts("Enter the element to search: ");
    int element;
    scanf("%d",&element);
    for (int i = 0; i < rowsize; i++) {
        for (int j = 0; j < colsize; j++) {
            if (array[i][j] == element){
                printf("Found at array[%d][%d]\n",i,j);
                exit(EXIT_SUCCESS);
            }
        }
    }
    printf("Not found\n");
    return 0;
}