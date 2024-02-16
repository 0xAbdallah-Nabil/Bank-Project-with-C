#ifndef __BANK__
#define __BANK__

#define  refresh()   do{ fflush(stdin);\
					getch(); \
                    system("cls");}while(0)

struct user
{
	char name[40];
	char activation[20];
	char address[50];
	char password[20];
	char national_id[40];
	unsigned char age;
	unsigned long long int id;
	unsigned long long int currency;
	struct user *next;
};


struct user * found_user();												
void new_account();														
void edit_account_state(struct user *ptr);								
void view_account_data(struct user *ptr);					    		
void deposit_amount(struct user *ptr);									
void transfer_amount(struct user *ptr1,struct user *ptr2);				
void withdraw_amount(struct user *ptr);									
void edit_account_password(struct user *ptr);						 	


#endif
