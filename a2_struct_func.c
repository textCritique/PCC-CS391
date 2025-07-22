#include <stdio.h>

typedef struct marks {
    int em;
    int math;
    int dbms;
}marks;

typedef struct student {
    char name[100];
    int age;
    marks mark;  
}stud;
void highest_mark(int no_students, stud student[no_students]){
    stud current_best;
    int highest_marks = 0, total;
    for (int i = 0; i < no_students; i++){
        total = student[i].mark.em + student[i].mark.math + student[i].mark.dbms;
        if (highest_marks < total){
            highest_marks = total;
            current_best = student[i];
        }
    }
    puts("Student with highest marks is ");
    printf("Name: %s\nAge: %d\nTotal marks: %d",current_best.name,current_best.age,highest_marks);
}
int main() {
    const int no_students = 10;
    stud student[no_students];
    for (int i = 0; i < no_students; i++) {
        puts("Enter the name: ");
        scanf("%s",&student[i].name);
        puts("Enter the age: ");
        scanf("%d",&student[i].age);
        puts("Enter the marks of em: ");
        scanf("%d",&student[i].mark.em);
        puts("Enter the marks of math: ");
        scanf("%d",&student[i].mark.math);
        puts("Enter the marks of dbms: ");
        scanf("%d",&student[i].mark.dbms);
    }
    highest_mark(no_students,student);
    return 0;
}