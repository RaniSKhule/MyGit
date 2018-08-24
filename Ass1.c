/*
Program to create a singly linked list.
*/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};
struct Node *new_Node;
int choice,element,position,counter=0,flag=0;

void create_Node();
void add_At_Begining(struct Node**);
void add_At_End(struct Node**);
void add_At_Position(struct Node**);
void delete_At_Begining(struct Node**);
void delete_At_End(struct Node**);
void delete_At_Position(struct Node**);
void show(struct Node**);
int main()
{
	struct Node *Head=NULL;
	while(1)
	{
		printf("\n===============================================\n 1. Add node at begining \n 2. Add node at end\n 3. Add a node at a given position\n 4. Delete a node at begining\n 5. Delete a node at end\n 6. Delete a node at given position\n 7. Display \n 8. Exit\n===============================================\n");
		printf("\nEnter choice:- ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:add_At_Begining(&Head);
				break;

			case 2:add_At_End(&Head);
				break;
			case 3:add_At_Position(&Head);
				break;
			case 4: delete_At_Begining(&Head);
				break;
			case 5:delete_At_End(&Head);
				break;
			case 6:delete_At_Position(&Head);
				break;
			case 7:show(&Head);
				break;
			case 8:exit(0);
			
			default:printf("\nInvalid choice............");
		}
	}
	return 0;
}

void create_Node()
{
	new_Node=(struct Node*)malloc(sizeof(struct Node));
	new_Node->next=NULL;
}

void add_At_Begining(struct Node** head)
{
	printf("\nEnter element:- ");
	scanf("%d",&element);
	create_Node();
	new_Node->data=element;
	if(*head==NULL)
	{
		new_Node->next=NULL;
	}
	else
	{
		new_Node->next=*head;
	}
	*head=new_Node;
	printf("\n%d is inserted at begining.......",element);
				
}

void add_At_End(struct Node** Head)
{
	struct Node *temp=NULL;
	create_Node();
	printf("\nEnter element:- ");
	scanf("%d",&element);
	new_Node->data=element;
	new_Node->next=NULL;

	if(*Head==NULL)
	{
		*Head=new_Node;
	}
	else
	{
		temp=*Head;
		while(temp->next!=NULL)
			temp=temp->next;

		temp->next=new_Node;
	}				
	printf("\%d is inserted at end.......",element);
}


void add_At_Position(struct Node** Head)
{
	struct Node *temp=NULL;
	flag=0;
	create_Node();
	printf("\nEnter position:- ");
	scanf("%d",&position);

	if(*Head!=NULL)
	{
		counter=1;
		printf("\nEnter element:- ");
		scanf("%d",&element);
		new_Node->data=element;	
		temp=*Head;
		if(position==1)
		{
			new_Node->next=temp;
			*Head=new_Node;
		}
		else
		{
			while(counter<position-1)
			{
				counter++;
				if(temp->next!=NULL)
				temp=temp->next;
				else
				{
					printf("\nElements are less than specified position");
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				new_Node->next=temp->next;
				temp->next=new_Node;
			}
		}
		if(flag==0)
		printf("\%d is inserted at position %d.......",element,position);
	}
	else
	printf("\nLinked list is empty so we can not add element at specified position........");
}

void delete_At_Begining(struct Node** Head)
{
	struct Node *temp=NULL;
	if(*Head==NULL)
	printf("\nLinked List is empty............");
	else
	{	
		temp=*Head;
		printf("\n%d is deleted.......",temp->data);
		*Head=temp->next;
		free(temp);
	}
}

void delete_At_End(struct Node** Head)
{
	struct Node *temp=NULL,*temp1=NULL;
	if(*Head==NULL)
	printf("\nLinked List is empty............");
	else
	{
		temp=*Head;
		if(temp->next!=NULL)
		{
			while(temp->next!=NULL)
			{	
				temp1=temp;	
				temp=temp->next;
			}
			temp1->next=NULL;
			printf("\n%d is deleted.......",temp->data);
			free(temp);
		}
		else
		{
			*Head=NULL;
			printf("\n%d is deleted.......",temp->data);
			free(temp);
		}		
	}
}
void delete_At_Position(struct Node** Head)
{
	struct Node *temp=NULL,*temp1=NULL;
	flag=0;
	printf("\nEnter position:- ");
	scanf("%d",&position);
	if(*Head!=NULL)
	{
		counter=1;
		temp=*Head;
		if(position==1)
		{
			*Head=temp->next;
		}
		else
		{
			while(counter<position)
			{
				counter++;
				if(temp->next!=NULL)
				{
					temp1=temp;
					temp=temp->next;
				}
				else
				{
					printf("\nElement is not at specified position");
					flag=1;
					break;
				}
			}	
		}
		if(flag==0)
		{
			printf("%d is deleted............",temp->data);
			temp1->next=temp->next;
			free(temp);
		}
	}
	else
	printf("\nLinked List is empty............");
		
}

void show(struct Node** head)
{
	struct Node *temp=NULL;
	if(*head==NULL)
	printf("\nLinked List is empty............");
	else
	{	
		printf("\n===============================================\n");
		temp=*head;
		while(temp->next!=NULL)
		{		
			printf("\t%d",temp->data);
			temp=temp->next;
		}
		printf("\t%d",temp->data);
	}
}
