// implementation of circular queue
// WARNING: 0 is used as error code for function return value
// if 0 is enqueued it will cause ambiguity
#include <stdio.h>
#define MAX 100

typedef struct q{
    int head;
    int tail;
    int size;
    int q[MAX];
}queue;
void initQ(queue *q,int size){
    q->size = size+1;
    q->head = q->tail = 0;
}
int size(queue* q){
    if (q->tail - q->head >= 0)
        return q->tail - q->head;
    return q->tail - q->head + q->size-1;
}
int enqueue(queue *q, int item){
    if (size(q) == q->size -1)
        return 0;
    q->q[q->tail] = item;
    q->tail = q->tail + 1;
    if (q->tail == q->size) q->tail = 0;
}
int dequeue(queue *q){
    if (size(q) == 0)
        return 0;
    int temp = q->q[q->head];
    q->head = q->head +1;
    if (q->head == q->size) q->head = 0;
    return temp;
}
int peek(queue *q){
    if (size(q) == 0)
        return 0;
    return q->q[q->head];
}
// void display(queue *q){

// }
void show_menu(){
    puts(" ");
    puts("\t\t\t|____________Menu____________|");
    puts("\t\t\t|1. Initailize               |");
    puts("\t\t\t|2. Enqueue                  |");
    puts("\t\t\t|3. Dequeue                  |");
    puts("\t\t\t|4. Peek                     |");
    // puts("\t\t\t|5. Display                  |");
    puts("\t\t\t|6. Exit                     |");
    puts(" ");
}
int main(){
    queue q;
    int choice;
    int temp;
    show_menu();
    while(1){
        printf("Choice no.: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: // initialize the queue
            printf("Max size: ");
            scanf("%d",&temp);
            initQ(&q,temp);
            break;
        case 2: // enqueue
            printf("Element: ");
            scanf("%d",&temp);
            temp = enqueue(&q,temp);
            temp == 0? printf("Queue overflow\n"): printf("Enqueued\n",temp);
            // display(&q);
            break;
        case 3: // dequeue
            temp = dequeue(&q);
            temp == 0? printf("Queue underflow\n"): printf("Dequeued %d\n",temp);
            // display(&q);
            break;
        case 4: // peek
            temp = peek(&q);
            temp == 0? printf("Queue empty!\n"): printf("%d\n",temp);
            break;
        case 5: // display whole queue
            // display(&q);
            break;
        case 6:
            puts("Exiting!");
            return 0;
        default:
            printf("Invalid choice!\n");
            show_menu();
            break;
        }
    }
    return 0;
}