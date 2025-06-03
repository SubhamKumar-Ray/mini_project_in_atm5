#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

#define   size 5
int stack[size],top=-1;
int queue[size], front=-1,rear=-1;
char ch;

		//STACK OPERATION

void push()
{
    clrscr();
    int n,i;
    printf("\n\t\t PUSH OPERATION \n");
    printf("you want to push element in stack press Y(yes) or N(no)\n\t\t(Max limit 5 elements) \n");
   // scanf("%c",&ch);
    cin>>ch;
    while(ch=='Y'||ch=='y')
   {
    if(top==size-1)
    {
     printf("\n\t STACK OVERFLOW\t NO space available \n");
     break;
    }
   else
     {
      printf("Enter %d  element in stack\t:  ",(top+1)+1);
      scanf("%d",&n);
      top=top+1;
      stack[top]=n;
      fflush(stdin);
     }
      printf("\nDo you want to push more element in stack press Y(yes) or N(no)\n\t\t(Max limit 5 elements)\n");
      scanf("%c",&ch);
 }
 }
void pop()
{
printf("\n\t\tPOP OPERATION\n");
printf("\nDo you want to POP element from stack press Y(yes) or N(no)\n");
//scanf("%d",&ch);
cin>>ch;
while(ch=='y'|| ch=='Y')
{
	if(top==-1)
	{
	printf("STACK UNDERFLOW (**Stack is Empty**)\n");
	break;
	}
	else
	{
	printf("\nElement %d deleted from stack ",stack[top]);
	top=top-1;
	fflush(stdin) ;
	}
	printf("\nDo you want to POP element from stack press Y(yes) or N(no)\n");
	//scanf("%c",&ch);
	cin>>ch;
}
}


void displaystack()
{
    if(top==-1)
    {
    printf("Stack is Empty\n");
    }
    else
    {
      printf("Your Ready STACK is: \n");
      for(int i=top;i>=0;i--)
      {
      printf("\n%d",stack[i]);
      }
    }

}

		//QUEUE OPERATION

void insert()
 {      int item;
	printf("\n\t\tINSERTION OPERATION\n");
	printf("Do you want to insert element in QUEUE press Y(yes) or N(No)\n");
       //	scanf("%c",&ch);
	cin>>ch;
	while(ch=='Y'||ch=='y')
	 {
	 if(rear==size-1)
	 {
	 printf("\n!!!SORRY, not enough space QUEUE OVERFLOW\n");
	 break;
	 }
	 else
	 if(rear==-1)
	   {
	   front=rear=0;
	   printf("Enter item in QUEUE\n");
	   scanf("%d",&item);
	   queue[rear]=item;
	   fflush(stdin);
	   }
else
{
rear=rear+1;
printf("Enter item in QUEUE\n");
scanf("%d",&item);
queue[rear]=item;
fflush(stdin);
}
printf("Do ypu want to insert element in QUEUE press Y(yes) or N(No)\n");
scanf("%c",&ch);
fflush(stdin);
}
} //Insert close
void delete1()
{
printf("\n\tDELETION In QUEUE\n");
printf("Do you want to delete item from QUEUE press Y(yes) or N(No)\n");
//scanf("%c",&ch);
cin>>ch;
while(ch=='Y'||ch=='y')
{
 if(rear==-1)
 {
 printf("No item left(QUEUE UNDERFLOW)\n");
 break;
 }
 else
 if(front==rear)
 {
 printf("\nItem %d deleted",queue[front]);
 front=-1;
 rear=-1;
 fflush(stdin);
 }
 else{
 printf("\nItem %d deleted",queue[front]);
 front=front+1;
 fflush(stdin);
 }
 printf("\nDo you want to delete more item press y(yes) or n(no)\n");
 scanf("%c",&ch);
 fflush(stdin);
 }
}//Deletion close
void displayqueue()
{
    if(rear==-1)
    {
    printf("QUEUE is Empty\n");
    }
    else
    {
      printf("Your Ready QUEUE is: \n");
      for(int i=front;i<=rear;i++)
      {
      printf("\t%d",queue[i]);
      }
    }
}
void main()
{
clrscr();
int choice,op;
do
{
printf("\n\Choose Data Structure:\n");
printf("1. Stack\n 2. Queue\n 3. Exit\n");
printf("Enter Your Choice: \n");
scanf("%d",&choice);
switch(choice)
{
case 1: printf("\n*****STACK MENU*****\n");
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Display\n");
	printf("Enter Your Choice:- \n");
	scanf("%d",&op);
	switch(op)
	{
	case 1: clrscr();
		push();
		break;
	case 2: clrscr();
		pop();
		break;
	case 3: clrscr();
		displaystack();
		break;
	default: printf("Invalid Choice !! Please Try Again\n");
	}
	break;
case 2: printf("\n*****QUEUE MENU*****\n");
	printf("1. INSERTION\n");
	printf("2. DELETION\n");
	printf("3. Display\n");
	printf("Enter Your Choice:- \n");
	scanf("%d",&op);
	switch(op)
	{
	case 1: clrscr();
		insert();
		break;
	case 2: clrscr();
		delete1();
		break;
	case 3: clrscr();
		displayqueue();
		break;
	default: printf("Invalid Choice !! Please Try Again\n");
	}
	break;
case 3: printf("Exiting Program......\n");
	exit(0);
	default: printf("Invalid Choice..\n");
}
}
while(choice !=4);
getch();
}