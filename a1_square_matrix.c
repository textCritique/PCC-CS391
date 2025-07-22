#include <stdio.h>

void display_matrix(int size, int array[size][size]){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++) {
            printf("%d ",array[i][j]);
        }
    puts("");
    }
}
int main() {
    // ask for order of the matrix
    int order;
    puts("Enter the order of square matrix: ");
    scanf("%d",&order);
    // take in the matrix
    int element;
    int matrix[order][order];
    for (int i = 0; i < order; i++){
        for (int j = 0; j < order; j++) {
            printf("%d , %d element: ",i,j);
            scanf("%d",&element);
            matrix[i][j] = element;
        }    
    }
    puts("Entered matrix is:\n");
    display_matrix(order,matrix);
    // sum the element of the matrix
    int sum = 0;
    for (int i = 0; i < order; i++){
        for (int j = 0; j < order; j++) {
            sum += matrix[i][j];
        }    
    }
    printf("The sum of the matrix's element is %d. ",sum);
}