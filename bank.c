#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "bank.h"

struct user *head=NULL;   //  for point to first node in linked list
struct user *check=NULL; // to loop for all nodes in the linked list


static int id_initial=10000;        // for data set of id 




/**************************************************************************************************************************************/
void new_account()
{
	
	struct user* pnew=NULL;  // initial it as null avoiding wild pointer
	if(head==NULL)
	{
		pnew=(struct user *)malloc(sizeof(struct user)); 
		head=pnew;
		pnew->next=NULL;
		
	}
	else
	{
		check=head;
		while(check->next!=NULL)
			{
                    check=check->next;
			}

		pnew=(struct user *)malloc(sizeof(struct user));
		check->next=pnew;
		pnew->next=NULL;
	}
	fflush(stdin);
	printf("ENTER THE USER NAME: ");
	gets(pnew->name);
	fflush(stdin);
	
	fflush(stdin);
	printf("ENTER THE PASSWORD: ");
	gets(pnew->password);
	fflush(stdin);
	
	
	fflush(stdin);
	printf("ENTER THE ADDRESS: ");
	gets(pnew->address);
	fflush(stdin);
	
	printf("ENTER THE AGE: ");
	scanf("%d",&pnew->age);
	
	if(pnew->age <=20)
	{
		char flag=1;
		char counter=0;   //for the id digits check
		while(flag)
		{
			counter=0;   
			fflush(stdin);
			printf("ENTER THE GUARDIAN NATIONAL ID: ");
			gets(pnew->national_id);
			fflush(stdin);
			while(pnew->national_id[counter]!='\0')
			{
				
				counter++;
			}
			if(counter==14)
			{
				flag=0;
			}
			else{
				printf("digits is less or more than '14'\n");
				
			}
		}
	}
	else
	{
		char flag=1;
		char counter=0;   //for the id digits check
		unsigned long long int id_op;
		while(flag)
		{
			counter=0;   
			fflush(stdin);
			printf("ENTER THE NATIONAL ID: ");
			gets(pnew->national_id);
			fflush(stdin);
			while(pnew->national_id[counter]!='\0')
			{
				counter++;
			}
			if(counter==14)
			{
				flag=0;
			}
			else{
				printf("digits is less or more than '14'\n");
				
			}
		}
	}
	
	printf("ENTER THE BALANCE: ");
	scanf("%lld",&pnew->currency);
	
	pnew->id=id_initial++;
	strcpy(pnew->activation,"Active State");
	printf("DONE\n");
	printf("The ID Of The Account Is %d\n",pnew->id);
	refresh();
	
	
}
/**************************************************************************************************************************************/
struct user * found_user()
{
	//depend on linear search node by node
	check=head;
	int id;
	char flag=0;
	printf("ENTER THE ID TO FIND THE ACCOUNT\n");
	scanf("%d",&id);
	
	while(check!=NULL)
	{
		if(check->id==id)
		{
			return check;
			break;
		}
		else
		{
			check=check->next;
		}
	}
	if(flag ==0)
		{
			printf("DOSEN'T EXIST\n");
			refresh();
			return NULL;
		}
	
}
/**************************************************************************************************************************************/
void edit_account_state(struct user *ptr)
{
	unsigned char choice;
	unsigned char flag=1;
	
	while(flag)
	{
		printf("1- SET ACCOUNT TO ACTIVE STATE\n2- SET ACCOUNT TO RESTRICTED STATE\n3- SET ACCOUNT TO CLOSED\n");
		printf("**enter the option number\n");
		scanf("%d",&choice);
			switch(choice)
		{
		case 1: strcpy(ptr->activation,"Active State");flag=0; break;
		case 2: strcpy(ptr->activation,"Restricted State");flag=0;break;
		case 3: strcpy(ptr->activation,"Closed");flag=0;break;
		default: printf("<<<<<<<<<<<<<<<<<<<<<<<<<< Invalid Choice >>>>>>>>>>>>>>>>>>>>>>>>>>>>> \n");
				printf("<<<<<<<<<<<<<<<<<<<<<<<<<< Please Choose The Valid Choice >>>>>>>>>>>>>>>>>>>>>>>>>>>>> \n"); refresh();flag=1;break;
		}
	}
		
	printf("DONE");
	refresh();
}
/**************************************************************************************************************************************/
void view_account_data(struct user *ptr)
{
	printf("name: %s\n",ptr->name);
	printf("password: %s\n",ptr->password);
	printf("id: %d\n",ptr->id);
	printf("national id: %s\n",ptr->national_id);
	printf("address: %s\n",ptr->address);
	printf("age: %d\n",ptr->age);
	printf("activation state: %s\n",ptr->activation);
	printf("balance: %d\n",ptr->currency);
	refresh();
}
/**************************************************************************************************************************************/
void deposit_amount(struct user *ptr)
{
	unsigned long long int money;
	
	
	if( strcmp(ptr->activation,"Active State")==0)
	{
		printf("ENTER THE AMOUNT OF MONEY U WANT TO ADD\n");
		scanf("%d",&money);
		ptr->currency +=money;
		printf("DONE");
		refresh();
		
	}
	else
	{
		printf("ACCOUNT NOT ACTIVE TRY AGAIN LATER\n");
		refresh();
	}
	
}
/**************************************************************************************************************************************/
void transfer_amount(struct user *ptr1,struct user *ptr2)
{
	unsigned long long int money=0;
	unsigned char flag =1;
	
	if(strcmp(ptr1->activation,"Active State")==0 && strcmp(ptr2->activation,"Active State")==0)
	{
		printf("ENTER THE AMOUNT OF MONEY YOU WANT TO TRANSFER\n");
		scanf("%d",&money);
		if(ptr1->currency>=money)
		{
			ptr1->currency-=money;
			ptr2->currency+=money;
			printf("DONE\n");
			refresh();
		}
		else{
			printf("SOME THING WRONG THE MONEY DOSEN'T ENOUGH \n");
			refresh();
		}
	}
	else
	{
		printf("SOME THING WRONG EITHER THE FIRST OR THE SECOND ACCOUNT DOSEN'T ACTIVE \n");
		refresh();
	}
}
/**************************************************************************************************************************************/
void withdraw_amount(struct user *ptr)
{
	unsigned long long int money=0;

	if( strcmp(ptr->activation,"Active State")==0)
	{
		printf("ENTER THE AMOUNT OF MONEY :");
		scanf("%d",&money);
		if(ptr->currency >= money )
		{
			ptr->currency-=money;
			printf("DONE\n");
			refresh();
		}
		else{
			printf("MONEY DOSEN'T ENOUGH TRY AGAIN LATER\n");
			refresh();
		}
	}
	else
	{
		printf("ACCOUNT NOT ACTIVE TRY AGAIN LATER\n");
		refresh();
	}
}
/**************************************************************************************************************************************/
void edit_account_password(struct user *ptr)
{

	if(strcmp(ptr->activation,"Active State")==0)
	{
		printf("ENTER THE NEW PASSWORD :");
		fflush(stdin);
		gets(ptr->password);
		fflush(stdin);
	}
	else
	{
		printf("ACCOUNT NOT ACTIVE TRY AGAIN LATER\n");
		refresh();
	}
	
	
}
/**************************************************************************************************************************************/