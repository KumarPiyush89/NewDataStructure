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
                printf("Insertion Fail! (List is already full).");
            break;
            case 2://code for insertion at last
                if(totalElement==SIZE)
                {
                    printf("\nSorry! List is already full.");
                    break;
                }
                //accept new data
                printf("\nEnter new data:");
                scanf("%d",&newData);
                //put new data at end of list
                list[totalElement]=newData;
                //increase totalElement by 1
                totalElement+=1;
                printf("\n %d added successfully at the end of list",newData);

            break;
            case 3: //code for insert at specific location
                if(totalElement==SIZE)
                {
                    printf("\nSorry! List is already full.");
                    break;
                }
                printf("\nEnter valid position for insertion:");
                scanf("%d",&pos);
                if(pos<=0||pos>totalElement+1)
                {
                    printf("\nNot a valid position.");
                }
                else
                {
                    printf("\nEnter New Data:");
                    scanf("%d",&newData);
                        //empty the (pos)th element of list
                    for(i=totalElement-1;i>=pos-1;i-=1)
                    {
                        list[i+1]=list[i];
                    }
                    //put newdta at (pos)th element
                    list[pos-1]=newData;
                    //increase totalElement by 1
                    totalElement+=1;
                    printf("\n %d inserted successfully at the %d position of list.",newData,pos);
                }
            break;
            case 4: //code for deletion of last element.
                if(totalElement==0)
                {
                    printf("\nList is already Empty!");
                    break;
                }
                else
                {
                    totalElement-=1;
                    printf("\nLast Element Data is Deleted Successful.");
                }
            break;                
            case 5: //code for deletion of first element.
                if(totalElement==0)
                {
                    printf("\nList is Already Empty.");
                    break;
                }
                else
                {
                    for(i=1;i<=totalElement-1;i+=1)
                    {
                        list[i-1]=list[i];
                    }
                    printf("\nFirst Element Data is Deleted Successful.");
                    //decrease totalElement by 1
                    totalElement-=1;
                }
            break;
            case 6: // code for deletion at specific location.
                if(totalElement==0)
                {
                    printf("\nList is Already Empty.");
                    break;
                }
                else
                {
                    printf("Enter A Valid Position For Deletion:");
                    scanf("%d",&pos);
                    if(pos<=0||pos>totalElement+1)
                    {
                        printf("\nNot a Valid Position.");;
                        break;
                    }
                    else
                    {   
                        i=pos;  
                        for(i;i<totalElement;i+=1)
                        {
                            list[i-1]=list[i];
                        }
                        printf("\n%d Position Data is Deleted Successful.",pos);
                        totalElement-=1;
                    }
                }
            break;
            case 7://code to print list
                if(totalElement==0)
                {
                    printf("\nList is Empty!");
                    break;
                }
                printf("\nList Data=");
                for(i=0;i<totalElement;i++)
                {
                    printf("%d",list[i]);
                    //print seperator
                    if(i<totalElement-1)
                        printf(", ");
                }
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