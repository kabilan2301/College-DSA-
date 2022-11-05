#include<stdio.h>
#include<stdlib.h>
void push(void);
void pop(void);
void display(void);
void peek(void);
void searching(void);
int item,key,choice;
struct node
{
 int data;
 struct node *next;
};
struct node *head=NULL;
struct node *p,*n,*prev;
void main()
{
	printf("Enter the choice\n 1.PUSH\n 2.POP\n 3.DISPLAY\n 4.PEEK\n 5.SEARCH\n 6.EXIT\n");
	do
	{
	  	printf("\n Enter the choice:");
	  	scanf("%d",&choice);
	  	switch(choice)
	  	{
	   		case 1:
	   		{
	     		push();
	    		break;
	    	}
	   		case 2:
	    	{
	     		pop();
	     		break;
	    	}
	   		case 3:
	   		{
	    		display();
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
	   		{
	   			printf("\nEXIT  POINT\n");
	    		break;
	    	} 
	    	default:
	     	{
	      		printf("Enter the vaild choice");
	    	}
		}
	}while(choice!=6);

}
void push()
{
n=(struct node*) malloc(sizeof(struct node));
 int item;
 printf("Enter the data to be Pushed");
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
 printf("Element pushed is %d", n->data);
}
void pop()
{
if(head==NULL)
{
printf("\nList is Empty");
}
else
{
p=head;
head=p->next;
printf("The Element popped is %d",p->data);
free(p);
}
}
void display()
{
p=head;
  if(head==NULL)
  {
  printf("List is empty");
  }
  printf("Nodes of STACK are: \n");  
  while(p!=NULL)
  {
   printf(" \n %d\n",p->data);
   p=p->next;
  }
}
void peek()
{
	p=head;
	printf("The top value is %d",p->data);
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

