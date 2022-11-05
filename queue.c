#include<stdio.h>
int front=-1,rear=-1,q[10],n,x,i,choice,ind,val,search,item;
void display(void);
void enqueue(void);
void dequeue(void);
void peek(void);
void peep(void);
void update(void);
void searching(void);
void main()
{
	printf("\n Enter the size of q[MAX=100]:");
    scanf("%d",&n);
    printf("\n\t QUEUE OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.ENQUEUE\n\t 2.DEQUEUE\n\t 3.DISPLAY\n\t 4.PEEK\n\t 5.PEEP \n\t 6.UPDATE \n\t 7.SEARCH \n\t 8.EXIT");
    do
    {
    	printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            	{
                	enqueue();
                	break;
            	}
			case 2:
            	{
                	dequeue();
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
				peep();
				break;
			}
            case 6:
            {
				update();
				break;
			}
			case 7:
			{
				searching();
				break;
			}	
			case 8:
            	{
            		printf("\n\t EXIT POINT ");
                	break;	
				}	
			default:
        		{
              		printf ("\n\t Please Enter a Valid Choice(1/2/3/4/5/6)");
            	}	
        }
	}while(choice!=8);
}

void enqueue()
{
	if(rear>=n-1)
	{
		printf("Queue Overflow\n");
	}
	else
	{
		printf("\n Enter the value to be Enqueued: ");
		scanf("%d",&x);
		if(front==-1)
		{
			front++;
			rear++;
			q[rear]=x;
		}
		else
		{
			rear++;
			q[rear]=x;
		}
		
	}
}

void dequeue()
{
    if(front==-1)
    {
        printf("\n\t QUEUE Underflow");
    }
    else
{
item = q[front];
if (front == rear)

front = rear = -1;

else

front = front + 1;

printf("Item dequeued %d",item);
}
}
void display()
{
    if(rear>=0)
    {
        printf("\n The elements in QUEUE \n");
        for(i=front; i<n; i++)
            printf("\t%d",q[i]);
        printf("\n Press Next Choice");
    }
    else
    {
        printf("\n The QUEUE is empty");
    }
   
}
void peek()
{
	printf("The FRONT Value is %d",q[front]);
}
void peep()
{
	
	if(rear<0)
	{
		printf("\nThe QUEUE is Underflow");
	}
	else
	{
		printf("\nEnter the position:");
		scanf("%d",&ind);
		if(q[ind]>=0)
		{

			if(ind<=n)
			{
				printf("\nThe element in the position is: %d",q[ind]);
			}
			else
			{
				printf("Position is Invalid");
			}
		}
	}

}
void update()
{
	if(rear<0)
	{
		printf("QUEUE is Underflow\n");
	}
	else
	{
		printf("\nEnter the position you want to update:");
		scanf("%d",&ind);
		if(ind<n)
		{
			printf("\n Enter the value you want to update in %d\n",ind);
			scanf("%d",&val);
			q[ind]=val;
			display();
		}
		else
		{
			printf("\nInvalid Position");
		}
	}

}
void searching()
{
	if(rear<0)
	{
		printf("QUEUE is Underflow");
	}
	else
	{
		int count=0;
		printf("Enter the value to search\n");
		scanf("%d",&search);
		for(i=0;i<=rear;i++)
		{
		if(search==q[i])
		{
			count++;
		}

	}
	if(count==1)
	{
		printf("The value %d is present",search);
	}
	else
	{
		printf("The value is not present");
	}
	}
}
