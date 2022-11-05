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
void sort(void);
int item,i,key,flag=0,count=1;
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
 printf("\n 1.Insert in Begginning \n 2.Insert in End \n 3.Insert in middle \n 4.Delete Begining \n 5.Delete End \n 6.Delete Specific \n 7.Display \n 8.Search \n 9.Sort \n Exit \n");
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
    sort();
    break;
    }
    case 10:
   {
    printf("\nEXIT  POINT\n");
    break;
    }
   default:
       {
        printf("Enter the vaild choice");
    }
  }
 }while(choice!=10);
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
 printf("Enter the position to be inserted\n The Positions of the list starts from \'0\' \n");
 scanf("%d",&key);
 if(key==0&&head==NULL)
 {
 printf("Enter the data to be inserted");
 scanf("%d",&item);
 n->data=item;
 n->next=NULL;
head=n;
return;
 }
 if(head==NULL&&key!=0)
 {
  printf("The list is empty\n Enter data at the First Position(Try 0)");
 }
 else{
 printf("Enter the data to be inserted");
 scanf("%d",&item);
 n->data=item;
 
 p=head;
 if(key==0)
 {
 	n->data=item;
 	n->next=p;
	head=n;
	return;
 }
 for(i=1;i<key;i++)
 {
  p=p->next;
  if(p==NULL)
  {
  printf("\nInvalid Position");
  return;
}
 }
  n->next=p->next;
  p->next=n;
  printf("Element inserted at position %d is => %d",key, n->data);
}
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
   		printf(" \t %d\t",p->data);
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
printf("Enter the position element to be deleted\n The Positions of the list starts from \'0\' \n");
scanf("%d",&key);
p=head;
prev=head;
if(key==0)
{
	p=head;
	head=p->next;
	printf("The Element Deleted is %d",p->data);
	free(p);
}
else
{
for(i=1;i<=key;i++)
{
	prev=p;
	p=p->next;
	if(p->next==NULL)
 	{
 		printf("\nInvalid Position");
 		return;
	 }
}
prev->next=p->next;
printf("The Element Deleted is %d",p->data);
free(p);
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
void sort()
{
	struct node  *q;
	int temp;
	if(head==NULL)
	{
		printf("List is Empty :\(");
	}
	else
	{
	for(p=head;p!=NULL;p=p->next)
	{
		for(q=p;q!=NULL;q=q->next)
		{
			if(p->data > q->data)
			{
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
		}
	}
	printf("The Ascending order of the Nodes is:\n");
	display();
	}
}
