/*Array Operations*/
#include<stdio.h>
#define SIZE 10

int insertAtFirst(int *list,int cap,int *totalElement,int newData)
{
    int i;
    if(cap==*totalElement)
    return 0;
    //shift all value from last to first by 1 element right to empty 1st element
    for(i=*totalElement-1;i>=0;i--)
    list[i+1]=list[i];

    //put new data at 0th element
    list[0]=newData;

    //increase total record by 1
    (*totalElement)++;
    return 1;
}
int insertAtLast(int *list, int cap, int *totalElement, int newData)
{
    if(cap==*totalElement)
    return 0;

    //put new data at last element
    list[*totalElement]=newData;

    //increase total record by 1
    (*totalElement)++;
    return 1;
}
int insertAtSpecificLocation(int *list, int cap, int *totalElement, int newData, int pos)
{ 
    int i;
    printf("Capicity is %d and totalelement is %d\n", cap,*totalElement);
    if(cap==*totalElement)
    {
    printf("list is full");
    return 0;
    }
    //check given position is valid or not
    printf("printf pass 1 ");
    if(pos<=0||pos>*totalElement+1)
    return 0;
    printf("pass 2");
    //shift all value from last to first by 1 element right to empty 1st element
    for(i=*totalElement-1;i>=pos-1;i--)
    list[i+1]=list[i];
    //put new data at given position
    list[pos-1]=newData; 
    //increase total record by 1
    (*totalElement)++;
    return 1;
}
int DeletionAtLast(int *totalElement)
{
    if(*totalElement==0)
    return 0;
    //Delete the value from last Element
    //Decrease totalElement by 1
    (*totalElement)--;
    return 1;
}
int DeletionAtFirst(int *list, int *totalElement)
{
    int i;
    if(*totalElement==0)
    return 0;
    //Delete the value from the firstElement & Shift all value from first to last by 1 element left
    for(i=1;i<=*totalElement-1;i++)
    list[i-1]=list[i];
    //decrease totalElement by 1
    (*totalElement)--;
    return 1;
}
int DeletionAtSpecificLocation(int *list, int *totalElement, int pos)
{
    int i;
    if(*totalElement==0)
    return 0;
    //Delete the value from the (pos)th Element & Shift value from (pos)th to last by 1 element left
    for(i=pos;i<=*totalElement-1;i++)
    list[i-1]=list[i];
    //decrease totalElement by 1
    (*totalElement)--;
    return 1;
}
int DisplayAllData(int *list,int totalElement)
{
    int i;
    if(totalElement==0)
    {
	    printf("\nList is Empty!");
        return 0;
    }
    printf("\nList Data=");
    for(i=0;i<totalElement;i++)
    {
        printf("%d",list[i]);
        //print seperator
        if(i<totalElement-1)
            printf(", ");
    }
    return 1;
}   

int main()
{
    int list[SIZE],totalElement=0;
    int i,choice,newData,pos;
    do
    {
        system("cls");
        printf("\nOptions\n================");
        printf("\n1. Insert New Data At First");
        printf("\n2. Insert New data At Last");
        printf("\n3. Insert At Specific Location");
        printf("\n4. Delete Of Last Element");
        printf("\n5. Delete Of First Element");
        printf("\n6. Delete At Specific Location");
        printf("\n7. Display List");
        printf("\n8. Exit");
        printf("\n Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1://code for insertion at first               
                //accept new data
                printf("\nEnter new data:");
                scanf("%d",&newData);
                if(insertAtFirst(list,SIZE,&totalElement,newData))
                printf("\n %d inserted successfully at the begning of list.",newData);
                else
                printf("\nInsertion Fail! (List is already full).");
            break;
            case 2://code for insertion at last
                
                //accept new data
                printf("\nEnter new data:");
                scanf("%d",&newData);
                if(insertAtLast(list,SIZE,&totalElement,newData))
                printf("\n %d inserted successfully at the last element of list.",newData);
                else
                printf("\nInsertion Fail! (List is already full).");

            break;
            case 3: //code for insert at specific location
                
                printf("\nEnter valid position for insertion:");
                scanf("%d",&pos);
                if(pos<=0||pos>totalElement+1)
                {
                printf("Sorry you have invalid position");
                break;
                }
                printf("\nEnter New Data:");
                scanf("%d",&newData);
                if(insertAtSpecificLocation(list,SIZE, &totalElement, newData ,pos))
                    printf("\n %d inserted successfully at the %d position of list.",newData,pos);
                else
                    printf("\nInsertion Fail! (List is already full).");
                
                
                
            break;
            case 4: //code for deletion of last element.
                if(DeletionAtLast(&totalElement))
                printf("\nLast Element Data Deleted Successfully.");
                else
                printf("\nList Is Already Empty!");
            break;              
            case 5: //code for deletion of first element.
                if(DeletionAtFirst(list , &totalElement))
                printf("\nFrist Element Data Deleted Successfully.");
                else
                printf("\nList Is Already Empty!");
            break;
            
            case 6: // code for deletion at specific location.
                printf("\nEnter valid position for insertion:");
                scanf("%d",&pos);
                if(pos<=0||pos>totalElement)
                printf("Sorry you have invalid position");
                else if(DeletionAtSpecificLocation(list,&totalElement,pos))
                printf("\n%d Position Data Deleted Successfully.",pos);
                else
                printf("\nList Is Already Empty!");
            break;
            case 7://code to print list
                /*if(*totalElement==0)
                {
                    printf("\nList is Empty!");
                    return 0;
                }
                printf("\nList Data=");
                for(i=0;i<*totalElement;i++)
                {
                    printf("%d",list[i]);
                    //print seperator
                    if(i<*totalElement-1)
                        printf(", ");
                }*/
                //if(DisplayAllData(int *list, int *totalElement))
                DisplayAllData(list,totalElement);
                break;
            break;
            case 8://code for exit from progam
            return 0;
            default:
            printf("\n OOPs! You have entered invalid choice");
        }
        //pause code to move on next iteration
        printf("\n");
        system("pause");
    } while (1);
}