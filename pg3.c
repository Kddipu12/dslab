#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node *link;
}*top=NULL;

int isEmpty(){
    if(top==NULL)
       return 1;
    else
       return 0;
}
 
int topelement(){
     int t=isEmpty();
    if(t==1)
    {
        printf("Stack Underflow");
        exit(1);
    }
    printf("%d",top->data);
}
void push(int data){
    struct node * newNode;
    newNode = malloc(sizeof(newNode));
    
    newNode->data= data;
    newNode->link=NULL;
    newNode->link =top;
    top= newNode;

}
void pop(){
    struct node* temp;
    temp=top;
    int t=isEmpty();
    if(t==1)
    {
        printf("Stack Underflow");
        exit(1);
    }
    int val = temp ->data;
    top =top->link;
    free(temp);
    temp=NULL;
    printf("the poped element is %d",val);

}

void display(){
    struct node* temp;
    temp = top;
    int t=isEmpty();
    if(t==1)
    {
        printf("Stack Underflow");
        exit(1);
    }
    printf("Stack elemets are ");
    while (temp!=NULL){
        printf("%d\t",temp->data);
        temp =temp->link;
    }
    printf("\n");
    
}

int count = 0;
 
void main()
{
    int no, ch, e;
 
    printf("\n 1 - Push");
    printf("\n 2 - Pop");
    printf("\n 3 - Top");
    printf("\n 4 - Dipslay");
    printf("\n 5 - Exit");
    
    
    
 
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
 
        switch (ch)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &no);
            push(no);
            break;
        case 2:
            pop();
            break;
        case 3:
            topelement();
                
            break;
        case 4:
             display();
            break;
       
        case 5:
            exit(0);
        
        default :
            printf(" Wrong choice, Please enter correct choice  ");
            break;
        }
    }
}

