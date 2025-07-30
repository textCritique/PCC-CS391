#include <stdio.h>

void bin_recur(int start, int stop, int* arr, int array_size ,int element) {
    int index = start + (stop-start)/2;
    if (start > stop){
        printf("Not found\n");
        return;
    }
    if (element == arr[index]){
        printf("Found at %d\n",index);
        return;
    }
    else if (element < arr[index]){
        bin_recur(start,index,arr,element,array_size);
    }
    else {
        bin_recur(index,stop,arr,element,array_size);
    }
}
int main(){
    int sorted_arr[] = {6,7,8,9,11,15};
    int size = sizeof(sorted_arr)/sizeof(int);
    bin_recur(0,size,sorted_arr,size,7);
    //bin_iter(size,sorted_arr,15);
}