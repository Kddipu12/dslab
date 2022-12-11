#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * link;
};
int count=0;
int insertatend(struct node * head,int data){
    struct node * new,*ptr;
    ptr=head;
    new=malloc(sizeof(struct node));
    new->data=data;
    new->link=NULL;
    while(ptr!=NULL){
        ptr=ptr->link;
    }
    
    ptr->link=new;
    count++;
    printf("element inseted successfully");
    
return 0;
}
int insertatfront(struct node *head,int data){
    struct node * new;
    new =malloc(sizeof(struct node));
    new->data=data;
    new->link=head;
    head=new;
return 0;
}
int delete(struct node *head,int pos){
    struct node * prev,*current;
    int data;
    prev=head;
    current=head;
    if(pos==1){
        data=current->data;
        head=head->link;
        free(current);
        current=NULL;
        
    }
    else if(head==NULL){
        printf("the list is empty");

    }
    else{
        while (pos!=1)
        {
            prev=current;
            current=current->link;
            pos--;
            
        }
        prev->link=current->link;
        data=current->data;
        free(current);
        current =NULL;
        
    }

    return data;
    count--;

    



}
void print(struct node *head){
    
    if(head==NULL){
        printf("empty");


    }
    else{
        struct node * tmp=head;
        while(tmp!=NULL){
            
          printf("%.1d\t",tmp->data);
               

            }
    }
}
void main(){
    struct node *head=NULL;
    insertatend(head,5);
    printf("hello");
    insertatfront(head,10);
     insertatend(head,8);
     insertatend(head,3);
     print(head);
     int t=delete(head,2);
      print(head);



}
