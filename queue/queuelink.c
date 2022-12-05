#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node *link;
}*front=NULL,*rear=NULL;

int isEmpty(){
    if(front==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

 

void enqueue(int data){
    struct node * newNode;
    newNode = malloc(sizeof(newNode));
    
    newNode->data= data;
    newNode->link=NULL;
    if (rear==NULL)
       front=rear=newNode;
    
    else{
        rear->link  =newNode;
        rear=newNode;
    }
   
}
void dequeue(){
    struct node* temp;
    temp=front;
    int t=isEmpty();
    if(t==1)
    {
        printf("Stack Underflow");
        exit(1);
    }
    else{
    int val = temp ->data;
    front=front->link;
    free(temp);
    temp=NULL;
    printf("the poped element is %d",val);
    }

}
void peek(){
    int t;
    t=isEmpty();
    if(t==1){
        printf("Queue is empty");
        exit(1);

    }printf("The element at the front is %d",front->data);

}


void display(){
    struct node* temp;
    temp = front;
    int t=isEmpty();
    if(t==1)
    {
        printf("Stack Underflow");
        exit(1);
    }
    printf("Queue elemets are ");
    while (temp!=NULL){
        printf("%d\t\t",temp->data);
        temp =temp->link;
    }
    printf("\n");
    
}


 
void main()
{
    int no, ch, e;
 
    printf("\n 1 - Enqueue");
    printf("\n 2 - Dequeue");
    printf("\n 3 - Peek");
    printf("\n 3 - Dipslay");
    printf("\n 4 - Exit");
   
    
    
    
 
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
 
        switch (ch)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &no);
           enqueue(no);
            break;
        case 2:
           dequeue();
            break;
        
        case 3:
           peek();
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
 