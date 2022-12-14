#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
struct node* first=NULL;
struct node* createNode(int  data)
{
    struct node* newNode=(struct node*)malloc((sizeof(struct node)));
    if(newNode==NULL)
    {
        printf("Sorry there was an error\nAborting\n");
        exit(0);
    }
    newNode->next=NULL;
    newNode->data=data;
    return(newNode);
}

void addElemEnd(int data)
{
    struct node *newNode=createNode(data);
    if(first==NULL)
        first=newNode;
    else
    {
        struct node *temp=first;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newNode;
    }
}

void display()
{
    if(first == NULL)
        printf("\nList Empty");
    else
    {
        struct node *temp = first;
        printf("Head");
        while(temp != NULL)
        {
            printf(" -> %d", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}





int main()
{
    int choice;
    do
    {
        int data, nodeAfterData;
        printf("\n");
        printf("1: Add element at end\n");
        printf("2: Display Elements\n");
        printf("3: Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&data);
                addElemEnd(data);
                break;
            case 2:
                display();
                break;
            default:
               break;
        }
    }while(choice != 3);
}