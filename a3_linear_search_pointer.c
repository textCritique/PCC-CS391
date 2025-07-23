// linear search using pointer
#include <stdio.h>
#include <stdlib.h>

int* init_array(int size) {
    int* array = malloc(size*sizeof(int));
    for (int i = 0; i < size; i++) {
        printf("Enter the element: ");
        scanf("%d",&array[i]);
    }
    return array;
}
int main() {
    int size;
    puts("Enter the size of the array: ");
    scanf("%d",&size);
    int* arr = init_array(size);
    puts("Enter the number to search: ");
    int n;
    scanf("%d",&n);
    for (int i = 0; i < 10; i++) {
        if (arr[i] == n) {
            printf("Found at index: %d",i);
            return 0;
        }
    }
    printf("Not Found!");
}