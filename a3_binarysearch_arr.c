#include <stdio.h>

int bin_recur(int start, int stop, int* arr,int element) {
    int index = start + (stop-start)/2;
    if (start > stop){
        // Not found
        return -1;
    }
    if (element == arr[index]){
        // Found
        return index;
    }
    else if (element < arr[index]){
        return (start,index-1,arr,element);
    }
    else {
        return bin_recur(index+1,stop,arr,element);
    }
}
int bin_iter(int * arr,int size,int target){
    int start = 0;
    int stop = size- 1;
    int index;
    while (start <= stop){
        index = start+ (stop - start)/2;
        if (arr[index] == target){
            return index;
        }
        else if(arr[index] > target){
            stop = index-1;
        }
        else {
            start = index+1;
        }
    }
    return -1;
}
int main(){
    int sorted_arr[] = {6,7,8,9,11,15};
    int size = sizeof(sorted_arr)/sizeof(int);
    printf("11 is found at %d\n",bin_iter(sorted_arr,size,11));
    printf("11 is found at %d\n",bin_iter(sorted_arr,size,11));
    return 0;
}