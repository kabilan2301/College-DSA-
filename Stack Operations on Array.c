#include<stdio.h>
int stack[100],choice,n,top,x,i,ind,val,search;
void push(void);
void pop(void);
void display(void);
void peek(void);
void peep(void);
void update(void);
void searching(void);
int main()
{
 
    top=-1;
    printf("\n Enter the size of STACK[MAX=100]:");
    scanf("%d",&n);
    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.PEEK\n\t 5.PEEP \n\t 6.UPDATE \n\t 7.SEARCH \n\t 8.EXIT");
    do
    {
        printf("\n Enter the Choice:");
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
    }
    while(choice!=8);
    return 0;
}
void push()
{
    if(top>=n-1)
    {
        printf("\n\tSTACK is over flow");
       
    }
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\n\t Stack is under flow");
    }
    else
    {
        printf("\n\t The popped elements is %d",stack[top]);
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        printf("\n The elements in STACK \n");
        for(i=top; i>=0; i--)
            printf("\n%d",stack[i]);
        printf("\n Press Next Choice");
    }
    else
    {
        printf("\n The STACK is empty");
    }
   
}
void peek()
{
	printf("The TOP Value is %d",stack[top]);
}
void peep()
{
	
	if(top<0)
	{
		printf("\nThe STACK is Underflow");
	}
	else
	{
		printf("\nEnter the position:");
		scanf("%d",&ind);
		if(stack[ind]>=0)
		{

			if(ind<=n)
			{
				printf("\nThe element in the position is: %d",stack[ind]);
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
	if(top<0)
	{
		printf("STACK is Underflow");
	}
	else
	{
		printf("\nEnter the position you want to update:");
		scanf("%d",&ind);
		if(ind<n && ind>-1)
		{
			printf("\n Enter the value you want to update in %d\n",ind);
			scanf("%d",&val);
			stack[ind]=val;
			display();
		}
	}

}
void searching()
{
	if(top<0)
	{
		printf("STACK is Underflow");
	}
	else
	{
		int count=0;
		printf("Enter the value to search\n");
		scanf("%d",&search);
		for(i=0;i<=top;i++)
		{
		if(search==stack[i])
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
	
