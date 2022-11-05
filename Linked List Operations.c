#include<stdio.h>
#include<stdlib.h>
void insert_begin(void);
void insert_end(void);
void insert_middle(void);
void display(void);
void dlt_begining(void);
void dlt_end(void);
void dlt_specific(void);
void searching(void);
int item,key;
struct node
{
 int data;
 char cdata;
 struct node *next;
};
struct node *head=NULL;
struct node *p,*n,*prev;
void main()
{
 int choice;
 printf("\n 1.Insert in Begginning \n 2.Insert in End \n 3.Insert in middle \n 4.Delete Begining \n 5.Delete End \n 6.Delete Specific \n 7.Display \n 8.Search \n 9.Exit \n");
 do
 {
  printf("\n Enter the choice:");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:
    {
     insert_begin();
     break;
    }
   case 2:
    {
     insert_end();
     break;
    }
   case 3:
    {
     insert_middle();
     break;
    }
   case 4:
   {
    dlt_begining();
    break;
    }
    case 5:
   {
    dlt_end();
    break;
    }
    case 6:
   {
    dlt_specific();
    break;
    }
    case 7:
   {
    display();
    break;
    }
    case 8:
   {
    searching();
    break;
    }
    case 9:
   {
    printf("\nEXIT  POINT\n");
    break;
    }
   default:
       {
        printf("Enter the vaild choice");
    }
  }
 }while(choice!=9);
}

void insert_begin()
{
n=(struct node*) malloc(sizeof(struct node));
 int item;
 printf("Enter the data to be inserted");
 scanf("%d",&item);
 n->data=item;
 if(head==NULL)
 {
  n->next=NULL;
  head=n;
 }
 else
 {
  n->next=head;
  head=n;
 }
 printf("Element inserted at the first node is %d", n->data);
}

void insert_end()
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
  printf("Element to be inserted in end is %d", n->data);

}

void insert_middle()
{

 n = (struct node*) malloc(sizeof(struct node));
 printf("Enter the data to be inserted");
 scanf("%d",&item);
 printf("Enter the where to be inserted");
 scanf("%d",&key);
 n->data=item;
 if(head==NULL)
 {
  printf("The list is empty");
 }
 p=head;
 while(p->next!=NULL)
 {
  if(p->data==key)
  {
   n->next=p->next;
   p->next=n;
   break;
  }
  else
  {
   p=p->next;
  }
 }
  printf("Element inserted at the middle node is %d", n->data);
}

void display()
{
p=head;
  if(head==NULL)
  {
  printf("List is empty");
  }
  printf("Nodes of singly linked list: \n");  
  while(p!=NULL)
  {
   printf(" \n %d\n",p->data);
   p=p->next;
  }
}

void dlt_begining()
{
if(head==NULL)
{
printf("\nList is Empty");
}
else
{
p=head;
head=p->next;
printf("The Element Deleted is %d",p->data);
free(p);
}
}

void dlt_end()
{
p=head;
while(p->next!=NULL)
{
prev=p;
p=p->next;
}
prev->next=p->next;
printf("The element Deleted is %d",p->data);
free(p);

}

void dlt_specific()
{
int flag=0,key;
if(head==NULL)
{
printf("The List is Empty");
}
printf("Enter the element to be deleted\n");
scanf("%d",&key);
p=head;
prev=NULL;
while(p!=NULL)
{
if(p->data==key)
{
if(p->data==NULL)
{
head=prev->data;
break;
}
else
{
prev->next=p->next;
}
printf("The Element Deleted is %d",p->data);
free(p);
break;
}
prev=p;
p=p->next;
flag=1;
}
if(flag==0)
{
printf("The value is Not Present");
}
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
