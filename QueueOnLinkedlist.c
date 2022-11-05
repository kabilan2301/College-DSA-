#include<stdio.h>
#include<stdlib.h>
void enQueue(void);
void deQueue();
void display();
void peek();
void searching();
int item,key;
struct node
{
 int data;
 struct node *next;
};
struct node *head=NULL;
struct node *p,*n,*prev;
void main()
{
 int choice;
 printf("\n 1.ENQUEUE \n 2.DISPLAY \n 3.DEQUEUE \n 4.PEEK \n 5.SEARCH \n 6.Exit \n");
 do
 {
  printf("\n Enter the choice:");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:
    {
     enQueue();
     break;
    }
   case 2:
    {
     display();
     break;
    }
   case 3:
    {
     deQueue();
     break;
    }
    case 4:
    {
     peek();
     break;
    }
    case 5:
    {
     searching();
     break;
    }
    case 6:
    printf("EXIT POINT");
    break;
    default:
       {
        printf("Enter the vaild choice");
    }
  }
 }while(choice!=6);
}

void enQueue()
{
 int item;
   n = (struct node*) malloc(sizeof(struct node));
 printf("Enter the data to be inserted");
 scanf("%d",&item);
 n->data=item;
 n->next=NULL;
 if(head==NULL)
 {
  head=n;
 }
 else
 {
  p=head;
  while(p->next!=NULL)
  {
  p=p->next;
  }
  p->next=n;
 }
  printf("Element EnQueued is %d", n->data);

}
void display()
{
p=head;
  if(head==NULL)
  {
  printf("List is empty");
  }
  else
  {
  printf("\nNodes of singly linked list: \n");  
  while(p!=NULL)
  {
   printf(" \t%d\t",p->data);
   p=p->next;
  }
}
}

void deQueue()
{
if(head==NULL)
{
printf("\nList is Empty");
}
else
{
p=head;
head=p->next;
printf("The Element DeQueued is %d",p->data);
free(p);
}
}

void peek()
{
p=head;
printf("The Front Value is %d",p->data);
}    

void searching()
{
 int x,flag=0,key;
 if(head==NULL)
 {
  printf("List is Empty\n");
 }
 else
 {
  printf("\nEnter the value you want to check\n");\
  scanf("%d",&key);
  p=head;
  while(p!=NULL)
  {
   if(p->data==key)
   {
    flag=1;
    x=p->data;
   }
   p=p->next;
  }
  if(flag!=0)
  {
   printf("\nThe value %d is present",key);
  }
  else
  {
   printf("\nThe value %d is not present",key);
  }
 }

}
