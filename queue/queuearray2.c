#include <stdio.h>
#include<stdlib.h>
#define MAX 10
int qarray[MAX];
int front=-1,rear=-1;

int isEmpty(){
    if(front ==rear+1||front==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(){
    if (rear== MAX-1)
       return 1;
    else
       return 0;
}
void enqueue(int data){
     int t; 
    t=isFull();
    if(t==1){
        printf("Cannot add the queue is full");
        exit(1);
    }
    if (front==-1)
        front=0;
   
    
        qarray[++rear]=data;
   
    
}
int dequeue(){
    int t;
    t=isEmpty();
    if(t==1){
        printf("Queue is empty");
        exit(1);

    }
    
        int data;
        data=qarray[front ];
        front++;
       return data;

   
}

int peek(){
    int t;
    t=isEmpty();
    if(t==1){
        printf("Queue is empty");
        exit(1);

    }return qarray[front];

}

void display(){
    int t;
    t=isEmpty();
    if(t==1){
        printf("Queue is empty");
        exit(1);
    

    }
    
        
        printf("Queue is");
        printf("\n");
        for(int i=front;i<=rear;i++)
        {
            printf("%d\n",qarray[i]);
        }
    

   

}

int main(){
    int ch,element,top,temp;
    do{
        printf("\nChoose operation");
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Display Queue");
        printf("\n4.Peek");
        printf("\n5.Exit");
        printf("\nEnter an option\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
             printf("\nEnter the element to insert\n");
                scanf("%d",&element);
                enqueue(element);
                break;
            case 2:
            
            temp=dequeue();
            printf("The dequeued element is %d",temp);
            break;    
            case 3:
                display();
                break;  
            case 4:
               
               top=peek();
               printf("The element at the top is %d",top);
               break;
            
        }
    }while(ch<5);
     return 0;
}
