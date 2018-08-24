/*
 a. Create a linked list that stores names
 b. And splite this linked list in two parts in such that one list contains nmaes starting with 'A' or 'a' and other list containing remaining names
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
	char name[20];
	struct Node *next;
};
struct Node *new_Node,*a_List,*rem_List,*a_List_Head=NULL,*rem_List_Head=NULL;
char name[20];

void create_Node();
void add_Name(struct Node**);
void split_List(struct Node**);
void show_Original_List(struct Node**);
void show_Splited_List(struct Node**);
void add_In_A();
void add_In_Rem();

int main()
{
	int choice;
	struct Node *Head=NULL;
	while(1)
	{
		printf("\n================================================\n 1. Add name \n 2. Split list\n 3. Display Original List\n 4. Display splited list\n 5. Exit\n==================================================\n");
		printf("\nEnter choice:- ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:add_Name(&Head);
				break;
			case 2:split_List(&Head);
				break;
			case 3:show_Original_List(&Head);
				break;
			
			case 4:show_Splited_List(&Head);
				break;

			case 5:exit(0);
			
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

void add_Name(struct Node** head)
{
	printf("Enter Name:- ");
	scanf("%s",name);
	create_Node();
	strcpy(new_Node->name,name);
	//new_Node->next=NULL;
	if(*head==NULL)
	{
		*head=new_Node;
	}
	else
	{
		struct Node *temp;
		temp=*head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new_Node;
	}
	printf("name added in list...........");
}


void split_List(struct Node** head)
{
	struct Node *temp;
	a_List_Head=NULL;
	rem_List_Head=NULL;
	char temp_Name[20];
	temp=*head;
	if(*head==NULL)
			printf("\nList is empty");
	else
	{
		while(temp->next!=NULL)
		{
			strcpy(temp_Name,temp->name);
			if(temp_Name[0]=='a'||temp_Name[0]=='A')
			{
				add_In_A(temp->name);
			}
			else
			{
				add_In_Rem(temp->name);
			}
			temp=temp->next;
		}
		strcpy(temp_Name,temp->name);
		if(temp_Name[0]=='a'||temp_Name[0]=='A')
		{
			add_In_A(temp->name);
		}
		else
		{
			add_In_Rem(temp->name);
		}
		
	}
}
void add_In_A(char name[20])
{
	struct Node *temp;
	create_Node();
	strcpy(new_Node->name,name);
	if(a_List_Head==NULL)
		a_List_Head=new_Node;
	else
	{
		temp=a_List_Head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new_Node;
	}
}

void add_In_Rem(char name[20])
{
	struct Node *temp;
	create_Node();
	strcpy(new_Node->name,name);
	if(rem_List_Head==NULL)
		rem_List_Head=new_Node;
	else
	{
		temp=rem_List_Head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new_Node;
	}
}

void show_Original_List(struct Node** head)
{
	struct Node *temp;
	if(*head==NULL)
		printf("\nList is empty.............");
	else
	{
		printf("\n================================================\n");
		temp=*head;
		while(temp->next!=NULL)
		{
			printf("\t%s",temp->name);
			temp=temp->next;
		}
		printf("\t%s",temp->name);
	}
}

void show_Splited_List(struct Node** head)
{
	struct Node *temp;
	if(a_List_Head==NULL)
		printf("\nList which hold names start with 'a' is empty.............");
	else
	{
		printf("\n================================================\nList 1:- ");
		temp=a_List_Head;
		while(temp->next!=NULL)
		{
			printf("\t%s",temp->name);
			temp=temp->next;
		}
		printf("\t%s",temp->name);
	}
	if(rem_List_Head==NULL)
		printf("\nList which hold names start with except 'a' is empty.............");
	else
	{
		printf("\n=====================================\nList 2:- ");
		temp=rem_List_Head;
		while(temp->next!=NULL)
		{
			printf("\t%s",temp->name);
			temp=temp->next;
		}
		printf("\t%s",temp->name);
	}
	

}
