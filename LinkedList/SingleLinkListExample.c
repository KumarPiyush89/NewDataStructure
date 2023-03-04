/* Single Linked List Operations*/
#include<stdio.h>
#include<malloc.h>
struct Node
{
    int data;
    struct Node *next;
};
int main()
{
    struct Node *start=NULL;
    struct Node *nnode,*tnode;
    int newData;
    int choice;
    do
    {
        //print menu
        system("cls");
        printf("\nSingle Linked List Operations\n===============================================");
        printf("\n1. Insert At last in list\n2. Display List\n3. Exit\n========================================\n");
        printf("Enter your choice:");;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1://code for insert new node at last
                //1. create new node
                nnode=(struct Node*)malloc(sizeof(struct Node));
                //2. check for node
                if(nnode==NULL)
                {
                    printf("\nUnable to create new node.");
                    break;
                }
                //3. accept ne data and put it in data part of new node
                printf("\nEnter new data:");
                scanf("%d",&newData);
                nnode->data=newData;
                nnode->next=NULL;

                //4. make new node first if list is empty
                if(start==NULL)
                {
                    start=nnode;
                    nnode=NULL;
                    printf("New node inserted successfully at the end of list");
                    break;
                }

                //5. find the address of last node of list
                    tnode=start;
                    while(tnode->next!=NULL)
                    {
                        tnode=tnode->next;
                    }

                //6. put address of new node in address part of last node
                tnode->next=nnode;
                nnode=NULL;
                printf("new node inserted successfully at the end of list");

            break;
            case 2://code for display list
            if(start==NULL)
            {
                printf("\n List is empty!");
            }
            else
            {
                printf("Contents of list:");
                tnode=start;
                while(tnode!=NULL)
                {
                    printf("%d,", tnode->data);
                    tnode=tnode->next;
                }
            }
            break;
            case 3://code for exit
                return 0;
            default:
            printf("\n Sorry! you have entered invalid option");
        }
        printf("\n");
        system("pause");
    } while (1);
    
}

