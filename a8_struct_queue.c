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
    q->size = size;
    q->head = q->tail = 0;
}
int enqueue(queue *q, int item){
    if (q->head == q->tail +1) // queue is full
        return 0;
    if (q->head == 0 && q->tail == q->size)
        return 0;
    q->q[q->tail] = item;
    if (q->size -1 == q->tail ) // for wrapping around the first
        q->tail = 0;
    else
        q->tail = q->tail +1;
    return 1;
}
int dequeue(queue *q){
    if (q->head == q->tail) //queue is empty
        return 0;
    int temp = q->q[q->head];
    if (q->head == q->size -1)
        q->head = 0;
    else
        q->head = q->head +1;
    return temp;
}
int peek(queue *q){
    if (q->head == q->tail) //queue is empty
        return 0;
    return q->q[q->head];
}
void display(queue *q){
    if (q->head == q->tail){ //queue is empty
        printf("Empty\n");
        return;
    }
    for (int i = q->head; i != q->tail+1 ; i++){
        if (i == q->tail-1){
            printf("%d\n",q->q[i]);
            break;
        }
        else
            printf("%d <- ",q->q[i]);
        if (i == q->size -1 && q->head > q->tail) 
            i = 0;

    }
}
void show_menu(){
    puts(" ");
    puts("\t\t\t|____________Menu____________|");
    puts("\t\t\t|1. Initailize               |");
    puts("\t\t\t|2. Enqueue                  |");
    puts("\t\t\t|3. Dequeue                  |");
    puts("\t\t\t|4. Peek                     |");
    puts("\t\t\t|5. Display                  |");
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
            printf("Size: ");
            scanf("%d",&temp);
            initQ(&q,temp);
            break;
        case 2: // enqueue
            printf("Element: ");
            scanf("%d",&temp);
            temp = enqueue(&q,temp);
            temp == 0? printf("Queue overflow\n"): printf("Enqueued\n",temp);
            display(&q);
            break;
        case 3: // dequeue
            temp = dequeue(&q);
            temp == 0? printf("Queue underflow\n"): printf("Dequeued %d\n",temp);
            display(&q);
            break;
        case 4: // peek
            temp = peek(&q);
            temp == 0? printf("Queue empty!\n"): printf("%d\n",temp);
            break;
        case 5: // display whole queue
            display(&q);
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