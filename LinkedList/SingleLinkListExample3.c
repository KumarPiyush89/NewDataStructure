/* Single Linked List Operations*/
#include<stdio.h>
#include<malloc.h>
struct Node
{
    float data;
    struct Node *next;
};
int main()
{
    struct Node *start=NULL;
    struct Node *nnode,*tnode,*pnode,*temp;
    float newData;
    int choice;
    int pos;
    int c;
    int i;
    do
    {
        //print menu
        system("cls");
        printf("\nSingle Linked List Operations\n===============================================");
        printf("\n1. Insert At last in list\n2. Insert at first in list\n3. Insert at specefic position in list\n4. Delete at last\n5. Delete at first\n6. Delete at Specefic Location\n7. Display List\n8. Exit\n========================================\n");
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
                scanf("%f",&newData);
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
            case 2://insert at first
                    //Code for insert new node first
                    nnode=(struct Node*)malloc(sizeof(struct Node));
                    //check for node
                    if(nnode==NULL)
                    {
                        printf("\n\t Unabel TO Create New Node");
                        break;
                    }
                    printf("\n Enter New Data:");
                    scanf("%f",&newData);
                    nnode->data=newData;
                    nnode->next=NULL;
                    nnode->next=start;
                    start=nnode;
                    nnode=NULL;
                    printf("\n New Node inserted successfully at first");
                    break;
            
                case 3://code for insert Node in speceficec position
                nnode=(struct Node*)malloc(sizeof(struct Node));
                if(nnode==NULL)
                {
                    printf("\n\t Unable to create a new node");
                    break;
                }
                    printf("\n Enter position you want to insert:");
                    scanf("%d",&pos);
                    printf("\n Enter New Data:");
                    scanf("%f",&newData);
                    nnode->data = newData;
                    nnode->next=NULL;
                    if(pos==1)
                    {
                        nnode->next=start;
                        start=nnode;
                        nnode=NULL;
                        printf("%d Inserted successfully at begning of list\n",newData);
                        break;
                    }
                    // 
                    pnode=start;
                    i=1;
                    while(i<pos-1&&pnode!=NULL)
                    {
                        pnode=pnode->next;
                        i=i+1;
                    }
                    if(pnode==NULL)
                    {
                        printf("\n Sorry invalid Position");
                        free(nnode);
                        break;
                    }
                    //
                    nnode->next=pnode->next;

                    pnode->next=nnode;
                    printf("\nyour given position  inserted successfully\n");
                    break;
                
            case 4://code for delete node at last
                if(start==NULL)
                {
                    printf("\n List is empty");
                    break;
                }
                tnode=start;
                if(tnode->next==NULL)
                {
                    free(start);
                    start=NULL;
                    printf("\n Deleted successfully\n");
                    break;
                }
                while(tnode->next->next!=NULL)
                {
                    tnode=tnode->next;
                }
                free(tnode->next);
                tnode->next=NULL;
                printf("\n Deleted successfully at the end of list\n");
                break;
            case 5://Code for delete at first
                    if(start==NULL)
                    {
                        printf("\n List is Already Empty");
                        break;
                    }
                    else
                    {
                        temp=start;
                        start=temp->next;
                        free(temp);
                        printf("\n First Node Deleted successfully at list\n");
                        break;
                    }
            case 6://Code for delete at specific position
                    if(start==NULL)
                    {
                        printf("\n List Is Empty\n");
                        break;
                    }
                    // Accept position
                    
                    printf("Enter position");
                    scanf("%d",&pos);
                    if(pos<1)
                    {
                        printf("\n Not Valid Number");
                        break;
                    }
                        if(pos==1)
                        {
                            tnode=start;
                            start=start->next;
                            free(tnode);
                            tnode=NULL;
                            printf("\n Deleted Successfully\n");
                            break;
                        }
                        pnode=start;
                        c=1;
                        while(c<pos-1&&pnode->next!=NULL)
                        {
                            pnode=pnode->next;
                            c++;
                        }
                        if(pnode->next==NULL)
                        {
                            printf("\n Invalid Position\n");
                            break;
                        }
                        tnode=pnode->next;
                        pnode->next=pnode->next->next;
                        free(pnode);
                        printf("\n Node Deleted Successfully\n");
                        break;
                         

                    
            case 7://code for display list
            //system("color 1f");
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
                    printf("%.2f,", tnode->data);
                    tnode=tnode->next;
                }
            }
            break;

           
            case 8://code for exit
                return 0;
            default:
            printf("\n Sorry! you have entered invalid option");
        }
        printf("\n");
        system("pause");
    } while (1);
    
}

