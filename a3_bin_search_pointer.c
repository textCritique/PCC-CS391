// binary search using pointer
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
int bin(int start,int stop,int* pointer,int target){
    int index = start + (stop-start)/2;
    if (start > stop)
        return -1;
    if (*(pointer+index) == target)
        return index;
    else if (*(pointer+index) > target)
        return bin(start,index-1,pointer,target);
    else 
        return bin(index+1,stop,pointer,target);
    return -1;
}
int binarySearch(int* pointer,int size, int target){
    return bin(0,size-1,pointer,target);
}
int main() {
    int size;
    puts("Enter the size of the array: ");
    scanf("%d",&size);
    int* arr = init_array(size);
    puts("Enter the number to search: ");
    int n;
    scanf("%d",&n);
    printf("%d is at %d\n",n, binarySearch(arr,size,n));
    return 0;
}