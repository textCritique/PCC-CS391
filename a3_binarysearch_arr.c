#include <stdio.h>

void bin_recur(int start, int stop, int* arr, int element,int array_size ) {
    int index = start + (stop-start)/2;
    if (index >= array_size || index < 0){
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
void bin_iter(int size,int* arr,int element){
    int stop = size-1;
    int start = 0;
    int index = start + (stop-start)/2;

    while (index >= 0 && index < size){
        if (element == arr[index]){
            printf("Found at %d\n",index);
            return;
        }
        else if (element < arr[index]){
            start 
        }
        else {
            index = index + (size-1 - index)/2;
        }
    }
    return;
    
}
int main(){
    int sorted_arr[] = {6,7,8,9,11,15};
    int size = sizeof(sorted_arr)/sizeof(int);
    //bin_recur(0,size,sorted_arr,10,size);
    bin_iter(size,sorted_arr,15);
}