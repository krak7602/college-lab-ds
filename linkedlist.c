#include <stdio.h>  
#include <stdlib.h>  
void push();  
void pop();  
void display1();  
void insert();  
void delete();  
void display2(); 
struct node   
{  
int val;  
struct node *next;  
};  
struct node *head;  
struct node *front;  
struct node *rear;   
 
  
void main ()  
{  
    while(1) 
    {
        printf("1. Stack\n");
        printf("2. Queue\n");
        printf("3. Exit\n");
        int opt;
        printf("Enter your choice: ");
        scanf("%d",&opt);
        if(opt==1)
        {
            int choice=0;  
            printf("\nStack Operations:\n");
            while(1)  
            {  
                printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");  
                printf("\n Enter your choice \n");        
                scanf("%d",&choice);  
                if(choice==1)
                    push();
                else if(choice==2)
                    pop();
                else if(choice==3)
                    display1();
                else if(choice==4)
                    break;
                else
                    printf("\nInvalid choice\n");
                  
            }
        }  
        else if(opt==2) 
        {
            int choice;   
            printf("\nQueue Operations:\n");
            while(1)   
            {     
                printf("\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");  
                printf("\nEnter your choice ?");  
                scanf("%d",& choice);  
                if(choice==1)
                    insert();
                else if(choice==2)
                    delete();
                else if(choice==3)
                    display2();
                else if(choice==4)
                    break;
                else
                    printf("\nInvalid choice\n");  
            } 
        }
        else if(opt==3)
        {
            exit(0);
        }
        else
        {
            printf("Enter valid choice");
        }
    }
}    
void push ()  
{  
    int val;  
    struct node *ptr = (struct node*)malloc(sizeof(struct node));   
    if(ptr == NULL)  
    {  
        printf("not able to push the element");   
    }  
    else   
    {  
        printf("Enter the value:");  
        scanf("%d",&val);  
        if(head==NULL)  
        {         
            ptr->val = val;  
            ptr -> next = NULL;  
            head=ptr;  
        }   
        else   
        {  
            ptr->val = val;  
            ptr->next = head;  
            head=ptr;  
               
        }  
        printf("Item pushed");  
          
    }  
}  
  
void pop()  
{  
    int item;  
    struct node *ptr;  
    if (head == NULL)  
    {  
        printf("Underflow");  
    }  
    else  
    {  
        item = head->val;  
        ptr = head;  
        head = head->next;  
        free(ptr);  
        printf("Item popped");  
          
    }  
}  
void display1()  
{  
    int i;  
    struct node *ptr;  
    ptr=head;  
    if(ptr == NULL)  
    {  
        printf("Stack is empty\n");  
    }  
    else  
    {  
        printf("Printing Stack elements: \n");  
        while(ptr!=NULL)  
        {  
            printf("%d\n",ptr->val);  
            ptr = ptr->next;  
        }  
    }  
} 
void insert()  
{  
    struct node *ptr;  
    int item;   
      
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW\n");  
        return;  
    }  
    else  
    {   
        printf("\nEnter value:");  
        scanf("%d",&item);  
        ptr -> val = item;  
        if(front == NULL)  
        {  
            front = ptr;  
            rear = ptr;   
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else   
        {  
            rear -> next = ptr;  
            rear = ptr;  
            rear->next = NULL;  
        }  
    }  
}     
void delete ()  
{  
    struct node *ptr;  
    if(front == NULL)  
    {  
        printf("\nUNDERFLOW\n");  
        return;  
    }  
    else   
    {  
        ptr = front;  
        front = front -> next;  
        free(ptr);  
    }  
}  
void display2()  
{  
    struct node *ptr;  
    ptr = front;      
    if(front == NULL)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nPrinting values:\n");  
        while(ptr != NULL)   
        {  
            printf("%d\n",ptr -> val);  
            ptr = ptr -> next;  
        }  
    }  
}