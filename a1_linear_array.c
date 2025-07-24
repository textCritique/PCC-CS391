/* 0 is reserved for denoting index is unoccupied */
#include <stdio.h>

void show_menu() {
    puts("_________Menu__________");
    puts("A. Insertion");
    puts("B. Removal");
    puts("C. Display");
    puts("D. Exit");
    puts("_______________________");

}
// check if left of position is unoccupied
int freeLeft(int* array,int pos){
    for (int  i = pos; i >= 0; i--) {
        if (array[i] == 0) return i;
    }
    return -1;
}
// check if right of position is unoccupied
int freeRight(int* array,int pos, int size){
    for (int  i = pos; i < size; i++) {
        if (array[i] == 0) return i;
    }
    return -1;
}
void insert(int* array, int size, int position, int element){
    if (array[position] == 0) {
        array[position] = element;
        return;
    }
    int index = position;
    int fl = freeLeft(array,position); // unoccupied index from the left
    int fr = freeRight(array,position,size); // unoccupied index from the right

    if (fl != -1){
        for (int i = fl; i < position; i++) {
            array[i] = array[i+1];
        }
    }
    else if (fr != -1){
        for (int i = fr; i > position; i--) {
            array[i] = array[i-1];
        }
    }
    else {
        puts("Array is full");
        return;
    }
    array[position] = element;
    return;
}
int delete(int* array,int size,int pos){
    if (array[pos] == 0) {
            puts("Nothing to delete!");
            return 0; // means nothing deleted
    }
    else {
        array[pos] = 0;
        return 1; //deletion successful
    }
}
void display(int* array, int size){
    for (int i = 0; i < size; i++) {
        if (array[i] == 0) {
            printf("array[%d] -> nil    ",i);
        }
        else {
            printf("array[%d] -> %d    ",i,array[i]);
        }
    }
    puts("");
}
int main(){
    puts("Enter the size of the array: ");
    int size, current_size = 0;
    int pos, element;
    scanf("%d",&size);
    int array[size];
    // intialize array with zero
    for (int i = 0; i < size; i++) array[i] = 0;
    char choice;
    while(1){
        show_menu();
        puts("Enter your choice as letter: ");
        scanf(" %c",&choice);
        switch (choice)
        {
        case 'A':
            if (current_size >= size){
                puts("Cannot insert! Array already full.");
            }
            else {
                printf("Enter the position: ");
                scanf("%d",&pos);
                if (pos < size && pos >= 0){
                    printf("Enter the element to insert: ");
                    scanf("%d",&element);
                    insert(array,size,pos,element);
                    current_size++;
                }
                else{
                    puts("Invalid index!");
                }
            }
            break;
        
        case 'B':
            puts("Enter the index of deleted element: ");
            scanf("%d",&pos);
            if (pos < size && pos >= 0){
                    current_size = current_size - delete(array,size,pos);
                }
                else{
                    puts("Invalid index!");
                }
            break;
        case 'C':
            display(array,size);
            break;
        case 'D':
            puts("Exiting...");
            return 0;
        default:
            puts("Invalid choice! ");
            break;
        }
    }
    return 0;
}