#include <stdio.h>
#include <stdlib.h>

typedef struct employee {
    int id;
    char name[100];
    int salary;
}employee;

int main(){
    int no_employee = 10;
    employee* emps = malloc(no_employee*sizeof(employee));
    for (int i = 0; i < no_employee; i++){
        printf("\nEnter the id: ");
        scanf("%d",&emps[i].id);
        printf("\nEnter the name: ");
        scanf("%s",emps[i].name);
        printf("\nEnter the salary: ");
        scanf("%d",&emps[i].salary);
    }
    puts("Details of employees having salary greater than $50000:");
    for (int i = 0; i < no_employee; i++){
        if (emps[i].salary > 50000) {
            printf("Name: %s\n",emps[i].name);
            printf("Id: %d\n",emps[i].id);
            printf("Salary: %d\n\n",emps[i].salary);
        }
    }
    return 0;
}