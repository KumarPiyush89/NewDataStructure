/*Write a C program that will mentain the record of teacher and student in list. Menu will be:
 1. Add new teacher
 2. Add new student 
 3. View teachers
 4. View students
 5. Exit.
 Use Array to mentain list
 All insertion will be at end of list.
 Teacher's field: name,father's name, gender, subject, salary
 Student's field: name, father's name,gender, class, roll
*/
//Array Operations:-
#include<stdio.h>
#include<malloc.h>
#define SIZE 10
#define ITLLF "\nInserted teacher list in last successfully.\n"
#define ISLLF "\nInserted student list in last successfully.\n"
#define OYHEIC "\n OOPs! You have entered invalid choice.\n"

struct Teacher
{
    char tname[30];
    char fname[30];
    char gender[10];
    char subject[10];
    int salary;
};

struct Student
{
    char sname[30];
    char fname[30];
    char gender[10];
    char clas[5];
    int roll;
};

struct Teacher inputTeacher()
{
    struct Teacher teacher;
    printf("Enter Teacher Name:- ");
    fflush(stdin);
    gets(teacher.tname);
    printf("Enter name of father:- ");
    gets(teacher.fname);
    printf("Enter the gender:- ");
    gets(teacher.gender);
    printf("Enter the Subject:- ");
    gets(teacher.subject);
    printf("Enter the Salary:- ");
    scanf("%d",&teacher.salary);
    return teacher;
}

void printTeacher(int srno,struct Teacher teacher,int printHeading)
{
    if(srno>0&&printHeading)
    printf("\n%5s ","SrNo.");
    else
    printf("\n");
    if(printHeading)
    {
    printf("\n%30s %30s %10s %15s %6s","Name","Father's Name","Gender","Subject","Salary");
    printf("\n\t\t--------------------------------------------------------------------------------------------\n");
    }
    if(srno>0)
    {
        printf("\n%5d",srno);
    }
    else
    printf("\n");
    printf("\n%30s %30s %10s %15s %6d",teacher.tname,teacher.fname,teacher.gender,teacher.subject,teacher.salary);
    printf("\n\t\t--------------------------------------------------------------------------------------------\n");
}   

struct Student inputStudent()
{
    struct Student student;
    printf("Enter student name:- ") ;
    fflush(stdin);
    gets(student.sname);
    printf("Enter name of father:- ");
    gets(student.fname);
    printf("Enter the class:- ");
    gets(student.clas);
    printf("Enter the gender:- ");
    gets(student.gender);
    printf("Enter the roll no:- ");
    scanf("%d",&student.roll);
    return student;
}

void printStudent(int srno,struct Student student,int printHeading)
{
    if(srno>0&&printHeading)
    printf("\n%5s ","SrNo.");
    else
    printf("\n");

    if(printHeading)
    {
    printf("%30s %30s %10s %8s %5s","Name","Father's Name","Gender","Class","Roll");
    printf("\n\t\t-------------------------------------------------------------------------------------------\n");
    }
    if(srno>0)
    {
        printf("\n%5d",srno);
    }
    else
        printf("\n");
    printf("%30s %30s %10s %8s %5d",student.sname,student.fname,student.gender,student.clas,student.roll);
    printf("\n\t\t--------------------------------------------------------------------------------------------\n");
}

int main()
{
    int choice,i;
    struct Teacher teacherList[SIZE];
    int totalteacher=0;
    struct Student studentList[SIZE];
    int totalstudent=0;
    do
    {
        system("cls");
        printf("\n\tInsertion at last in list (Array)\n==========================================");
        printf("\n1. Add new teacher\n2. Add new student\n3. View teachers record\n4. View students record\n5. Exit\n========================================");
        printf("\nEnter your choice :- ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:/*Code for add new Teacher*/
            if(SIZE==totalteacher)
            {
                printf("\nList is full.");
                break;
            }
            teacherList[totalteacher]=inputTeacher();
            totalteacher++;
            
            //printf("\nInserted teacher list in last successfully.");
            printf(ITLLF);
            break;

            case 2:/*Code for add new Student*/
            if(SIZE==totalstudent)
            {
                printf("\nList is full.");
                break;
            }
            studentList[totalstudent]=inputStudent();
            totalstudent++;
            //printf("\nInserted student list in last successfully.");
            printf(ISLLF);
            break;

            case 3://Code for display teacher record
            if(totalteacher==0)
            {
                printf("\n List is Empty!");
                break;
            }
            printf("\n\t\tTeacher(s) Data:-\n");
            for(i=0;i<totalteacher;i++)
            {   
                if(i%4==0)
                printTeacher(i+1,teacherList[i],1);              
                else
                printTeacher(i+1,teacherList[i],0);              

            }
            break;

            case 4://Code for display student record
            if(totalstudent==0)
            {
                printf("\n List is Empty!");
                break;
            }
            printf("\nStudent Data:-\n");
            for(i=0;i<totalstudent;i++)
            {
                if(i%5==0)
                    printStudent(i+1,studentList[i],1);
                else
                    printStudent(i+1,studentList[i],0);
            }
            break;
            case 5://code for exit
            return 0;
            default:
            printf(OYHEIC);
        }
        printf("\n");
        system("pause");
    } while (1);
    
}