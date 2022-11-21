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

void delElemAtPos(int pos)
{
    if(pos<1)
    {
        printf("INVALID, Index should start from 1\n");
    }
    else if(pos == 1)
    {
        if(first == NULL)
        {
            printf("Sorry, List Empty, cannot delete position %d",pos);
        }
        else
        {
            struct node *del = first;
            first = first->next;
            free(del);
            printf("Element at position %d Deleted. \n",pos);
        }
    }
    else
    {
        // There must be atleast pos-1 elements in the list
        int elemNum = 1;
        struct node *temp = first;

        // on exiting temp should point to pos-1 if that pos-1 exist
        // However element at pos might or might not exist, ie temp->next can be null
        // or temp will be null
        while(temp!=NULL && elemNum<pos-1)
        {
            temp = temp->next;
            elemNum++;
        }
        // Index correction for two different kind of loop termination
        // if temp == null, it means elemNum++ has run one extra time
        if(temp==NULL){elemNum--;}
        else {;}

        if(temp == NULL || temp->next == NULL)
            printf("Sorry, There are only %d nodes in the list", elemNum);
        else
        {   
            struct node *del = temp->next;
            temp->next = temp->next->next;
            free(del);
            printf("Element Deleted at position %d. \n",pos);
        }
    }
   
    
}


void addElemAfter(int data, int nodeBeforeData)
{
    struct node *newNode = createNode(data);

    if(first == NULL)
    {
        printf("List Empty");
    }
    else
    {
        struct node *temp = first;
        while(temp!=NULL && temp->data != nodeBeforeData)
        {
            temp = temp->next;
        }
        if(temp == NULL)
            printf("%d Not found in list",nodeBeforeData);
        else
        {
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Element Inserted");
        }
    }
    
}

void delete(int data)
{
    if(first == NULL)
    {
        printf("\nList Empty");
    }
    else
    {
        struct node *temp = first, *del = NULL;
        if(first->data == data)
        {
            del = first;
            first = first->next;
            free(del);
            printf("\nElement Deleted! \n");
        }
        else
        {
            while(temp != NULL)
            {
                if(temp->next!=NULL && temp->next->data == data)
                {
                    del = temp->next;
                    temp->next = temp->next->next;
                    free(del); 
                    printf("\nElement Deleted! \n");
                    break;
                }
                temp = temp->next;
            }
        }
        if(del == NULL)
            printf("\nElement not found! \n");
    }
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