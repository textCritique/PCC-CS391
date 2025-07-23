#include <stdio.h>

int main(){
    int arr[5] = {2,5,78,2,7};
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