/*Array Operations*/
#include<stdio.h>
#define SIZE 10
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
        printf("\n4. Deletion Of Last Element");
        printf("\n5. Deletion Of First Element");
        printf("\n6. Deletion At Specific Location");
        printf("\n7. Display List");
        printf("\n8. Exit");
        printf("\n Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1://code for insertion at first
                if(totalElement==SIZE)
                {
                    printf("\nSorry! List is already full.");
                    break;
                }
                //accept new data
                printf("\nEnter new data:");
                scanf("%d",&newData);
                //empty the oth element of list
                for(i=totalElement-1;i>=0;i-=1)
                {
                    list[i+1]=list[i];
                }
                //put newdta at oth element
                list[0]=newData;
                //increase totalElement by 1
                totalElement+=1;
                printf("\n %d inserted successfully at the begning of list.",newData);
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
                printf("\nEnter valid position for insertion.");
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
                    printf("\nList is Already Empty!");
                }
                else
                {
                    totalElement--;
                    printf("\nLast Element Deleted succesfully");
                }
            case 5://code for first element delete
                if(totalElement == 0)
                {
                    printf("\nList is Empty!");
                    break;
                }
                else
                {
                    for(i=1;i<totalElement;i++)
                    list[i-1]=list[i];
                    i=i+1;
                    totalElement--;
                    printf("Deletion successfully at the begning of list.");
                }
            case 6://code for deletion of specific location
                if(totalElement==0)
                {
                    printf("\n list is empty");
                    break;
                }
                else
                {
                    printf("Enter valid position:");
                    scanf("%d",&pos);
                    if(pos<1||pos>totalElement+1)
                    {
                        printf("Not a valid position for deletion in Array");
                    }
                    else
                    {
                        for(i=pos-1;i<totalElement;i++)
                        list[i]=list[i+1];
                        totalElement--;
                        printf("\nElement is succesfully deleted to their position");
                    }
                }
            case 7://code to print list
                if(totalElement==0)
                {
                    printf("\n List is Empty!");
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