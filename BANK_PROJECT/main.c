/*
*
 * bank project
 *
 * Created: 20/8/2023 12:52:29 AM
 *
 * Author : Abdallah Nabil Elsaied
 *
 */ 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "bank.h"




int main()
{
	/* admin data */

	char username_admin1[40]={"admin"}; //we can change it for login to admin window
	char password_admin1[20]={"admin"}; //we can change it for login to admin window
	
	
	/**********/
	
	
	struct user *ptr=NULL; 		// for the find user functions
	struct user *ptr2=NULL;		// for the find user functions
	unsigned int choice; 		// for switch statments
	unsigned char flag=1;		// for the while loops
	char username_admin[40]; 	// to scan the admin username
	char password_admin[20];	// to scan the admin password
	while(1)
	{
		system("cls");
		printf("\n<<<<<<<<<<<<<<<<<<   Welcome To ANS Bank   >>>>>>>>>>>>>>>>>>\n\n");
		printf("1- Admin Window.\n2- Client Window.\n3-Exit.\n");
		printf("\n**enter the option number\n");
		scanf("%d",&choice);
		fflush(stdin);
		system("cls");
		flag=1;
		switch(choice)
		{
			case 1:
						printf("enter the username: \n");
						gets(username_admin);
						fflush(stdin);
						printf("enter the password: \n");
						gets(password_admin);
						fflush(stdin);
						system("cls");
					while(flag)
					{
						if(strcmp(username_admin1,username_admin)==0 && strcmp(password_admin1,password_admin)==0)
						{
							printf("\n<<<<<<<<<<<<<<<<<<   WELCOME TO ADMIN WINDOW   >>>>>>>>>>>>>>>>>>\n\n");
							printf("1-CREAT NEW ACCOUNT\n2-OPEN EXISTING ACCOUNT\n3-BACK\n");
							printf("\n**enter the option number\n");
							scanf("%d",&choice);
							system("cls");
							switch(choice)
							{
								case 1:
									printf("** creating new account \n\n");
									new_account();
									break;
								case 2: 
									ptr=found_user();
									system("cls");
								while( ptr)
								{
									printf("** opinning..account id : %d\n\n",ptr->id);
									printf("1-EDIT_ACCOUNT_STATE\n2-TRANSFER_AMOUNT\n3-DEPOSIT_AMOUNT\n4-WITHDRAW_AMOUNT\n5-VIEW ACCOUNT DATA\n6-BACK\n");
									printf("\n**enter the option number\n");
									scanf("%d",&choice);
									system("cls");
									switch(choice)
									{
										case 1:edit_account_state(ptr);
											break;	
										case 2:
											printf("ACCOUNT U WANT TO TRANSFER CASH INTO\n");
											ptr2=found_user();
											if(ptr2)transfer_amount(ptr,ptr2);
											break;
										case 3:deposit_amount(ptr);
											break;
										case 4:withdraw_amount(ptr);
											break;
										case 5:view_account_data(ptr);
											break;
										case 6: ptr=NULL;
											break;
										default:
											printf("<<<<<<<<<<<<<<<<<<<<<<<<<< Invalid Choice >>>>>>>>>>>>>>>>>>>>>>>>>>>>> \n");
											printf("<<<<<<<<<<<<<<<<<<<<<<<<<< Please Choose The Valid Choice >>>>>>>>>>>>>>>>>>>>>>>>>>>>> \n"	);
											refresh();
											break;
										
									
									}
								}
									break;
								case 3: flag=0;	
									break;
								default:
									printf("<<<<<<<<<<<<<<<<<<<<<<<<<< Invalid Choice >>>>>>>>>>>>>>>>>>>>>>>>>>>>> \n");
									printf("<<<<<<<<<<<<<<<<<<<<<<<<<< Please Choose The Valid Choice >>>>>>>>>>>>>>>>>>>>>>>>>>>>> \n");
									refresh();
								break;
							}
						}
						else{
							printf("USERNAME OR PASSWORD IS WRONGE\n");
							refresh();
							flag=0;
						}
					}
			break;
/**************************************************************************************************************************************/
			case 2:
			
					while(flag)
					{
						
						char password[20];
						
						ptr=found_user();
						if(ptr!=NULL)
						{
						printf("ENTER THE PASSWORD : \n");
						fflush(stdin);
						gets(password);
						fflush(stdin);
						system("cls");
						}
						while( ptr)
						{
							if(strcmp(ptr->password,password)==0)
							{
								printf("\n<<<<<<<<<<<<<<<<<<   WELCOME TO CLIENT WINDOW   >>>>>>>>>>>>>>>>>>\n\n");
								printf("1-EDIT_ACCOUNT_PASSWORD\n2-TRANSFER_AMOUNT\n3-DEPOSIT_AMOUNT\n4-WITHDRAW_AMOUNT\n5-VIEWACCOUNT DATA\n6-BACK\n");
								printf("\n**enter the option number\n");
								scanf("%d",&choice);
								system("cls");
								switch(choice)
								{
									case 1:edit_account_password(ptr);printf("PLEASE LOGIN AGAIN\n");	refresh();	ptr=NULL;
									break;
									case 2:
										printf("ACCOUNT U WANT TO TRANSFER CASH INTO\n");
										ptr2=found_user();
										if(ptr2)transfer_amount(ptr,ptr2);
										break;
									case 3:deposit_amount(ptr);
										break;
									case 4:withdraw_amount(ptr);
										break;
									case 5:view_account_data(ptr);
										break;
									case 6: ptr=NULL;	 flag=0;
										break;
									default:
										printf("<<<<<<<<<<<<<<<<<<<<<<<<<< Invalid Choice >>>>>>>>>>>>>>>>>>>>>>>>>>>>> \n");
										printf("<<<<<<<<<<<<<<<<<<<<<<<<<< Please Choose The Valid Choice >>>>>>>>>>>>>>>>>>>>>>>>>>>>> \n");
										refresh();
										break;
								
								
								}
							}
							else
							{
								printf("PASSWORD IS WRONGE\n");
								refresh();
								ptr=NULL;
								
							}
						}
						if(ptr==NULL)flag=0;
						
					}
					break;
/**************************************************************************************************************************************/


			case 3:printf("\n<<<<<<<<<<<<  THANKS FOR USING OUR BANK  >>>>>>>>>>>\n");	refresh();	return 0;
			
			
/**************************************************************************************************************************************/
			default:
					 printf("<<<<<<<<<<<<<<<<<<<<<<<<<< Invalid Choice >>>>>>>>>>>>>>>>>>>>>>>>>>>>> \n");
					printf("<<<<<<<<<<<<<<<<<<<<<<<<<< Please Choose The Valid Choice >>>>>>>>>>>>>>>>>>>>>>>>>>>>> \n");
					refresh();
					break;
		}
	
	}
	
}
/**************************************************************************************************************************************/
