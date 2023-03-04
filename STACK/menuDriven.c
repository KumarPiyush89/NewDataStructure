/*
//write C program for following menu
Menu
------------
1. push to stack1
2. push to stack2
3.pop from stack1
4.pop from stack2
5. display stack1
6.display stack2
7.exit
*/
#include<stdio.h>
#include<string.h>
int menu()
{
	
    char m[][30]={"Addition","Subtraction","Multiplication","Division","Exit"};
    char heading[]="               Menu";
    int choice,i;
    system("cls");
    printf("\n%s",heading);
    /*line('=',strlen(heading)*2);
    for(i=0;i<5;i++)
    printf("\n %2d. %s",i+1,m[i]);
    line('=',strlen(heading)*2);*/
    do
    {
    printf("\nEnter valid Choice:");
    scanf("%d",&choice);
    if(choice>0&&choice<=5)
    return choice;
    } while (1); 
}

int main()
	{
        int st1[5];
    int st1Capacity=5;
    int st1Tos=-1;

	int poppedValue;
		do
		{
			switch(menu())
			{
				case 1:
				//push1(st1,st1Capacity,&st1Tos,10);
				break;
				case 2:
				//push2(st1,st1Capacity,&st1Tos,20);
				break;
				
                case 5:
				return 0;
			}
			printf("\n");
			system("pause");
			
		}while (1);
}
