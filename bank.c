/*****************************************************************************
 * Copyright (C) Palash D. Moon
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 ****************************************************************************/
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include"bank.h"
void menu()
{
    int choice;
    printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t WELCOME TO THE MAIN MENU ");
    printf("\n\n\t\t1.Create new account\n\t\t2.Update information of existing account\n\t\t3.For transactions\n\t\t4.Check the details of existing account\n\t\t5.Removing existing account\n\t\t6.View customer's list\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    
    switch(choice)
    {
        case 1:add_acc();
        break;
        case 2:mod_acc();
        break;
        case 3:transaction_acc();
        break;
        case 4:see();
        break;
        case 5:delete_acc();
        break;
        case 6:view_list();
        break;
        case 7:close();
        break;
	
    }
}
void add_acc() {
	int m;
	char ph[11];
	FILE *ptr;
	int no = 1234;
	int quit=0;
	printf("|******************************** NEW USER ACCOUNT ********************************************|\n");
    	ptr = fopen("bank.dat","a+");                                                                               
	if(ptr == NULL) {
		perror("Open Failed :");			
	}
	 printf("\n\n\nEnter today's date(mm/dd/yyyy):");
        scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year); 
    	
	while(fscanf(ptr, "%d %s %s %s %d/%d/%d %d  %s %ld %s %f %d/%d/%d\n", &add.acc_no, add.fname, add.mname,add.lname, &add.dob.day, &add.dob.month, &add.dob.year, &add.age, add.city, &add.phone, add.acc_type, &add.amount, &add.deposit.day, &add.deposit.month, &add.deposit.year) != EOF) {
		no = add.acc_no;    	
	}
	add.acc_no = no + 1;

	printf("Account Number                 :%d\n", add.acc_no);
       	printf("============================= PERSONAL DETAILS ======================================\n");
	printf("First Name                     :");
   	scanf("%s", add.fname);
	printf("Middle Name                    :");
   	scanf("%s", add.mname);
	printf("Last Name                      :");
    	scanf("%s", add.lname);
    	printf("Date Of Birth(dd/mm/yyyy)      :");
    	scanf("%d/%d/%d", &add.dob.day, &add.dob.month, &add.dob.year);
    	printf("Age			       :");
	scanf("%d",&add.age);
    	printf("City/Town/Village              :");
    	scanf("%s", add.city);
	m:
    	printf("Mobile Number                  :");
    	scanf("%ld", &add.phone);
	sprintf(ph, "%ld", add.phone);
	if(strlen(ph) != 10) {
		printf("Enter correct details !\n");
		close();
	}	
	
	printf("=============================== BANK DETAILS =======================================\n");
    	printf("Enter Amount To Deposit        :$");
    	scanf("%f", &add.amount);
     printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice:");
    scanf("%s",add.acc_type);

        fprintf(ptr,"%d %s %s %s %d/%d/%d %d %s %s %ld %s %f %d/%d/%d             \n",add.acc_no,add.fname,add.mname,add.lname,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.city,add.phone,
          add.acc_type,add.amount,add.deposit.month,add.deposit.day,add.deposit.year);


    fclose(ptr);
	
		printf("Account Created Successfully .. \n");
    	
	printf("=====================================================================================\n\n");
    	printf("Enter Your Choice\n\t1. Main Menu\n\t2. Exit\n");
    	scanf("%d", &quit);
    	if (quit == 1) {
        	menu();
        }
    	else (quit == 2);{
        	close();
	}
    
}
void mod_acc() {
	int choice, quit=0, flag = 0;
	int x;
   	FILE *oldrec, *newrec;
	
	printf("|************************************ ACCOUNT UPDATE **********************************|\n");
	
    	oldrec = fopen("bank.dat","r");
    	newrec = fopen("temp.dat","w");
	if(oldrec == NULL) {
		perror("Open Failed :");
		printf("No Accounts Exist !\n");
		printf("Enter Your Choice\n\t1. Main Menu\n\t2. Exit\n");
    		scanf("%d", &quit);
    		if (quit == 1) {
        	menu();
        	}
    		else (quit == 2);{
        	close();	
		}
	}
	if(newrec == NULL) {
		perror("Open Failed :");
		printf("Enter Your Choice\n\t1. Main Menu\n\t2. Exit\n");
    		scanf("%d", &quit);
    		if (quit == 1) {
        	menu();
        	}
    		else (quit == 2);{
        	close();	
		}		
	}	
	printf("Enter Account Number:\n");
    	scanf("%d",&mod.acc_no);
        while(fscanf(oldrec, "%d %s %s %s %d/%d/%d %d %s %ld %s %f %d/%d/%d", &add.acc_no, add.fname, add.mname, add.lname,        &add.dob.day, &add.dob.month, &add.dob.year, &add.age, add.city, &add.phone, 
add.acc_type, &add.amount, &add.deposit.day, &add.deposit.month, &add.deposit.year) != EOF) {
        	if (add.acc_no == mod.acc_no) {
   			flag = 1;
   			printf("Verified .. !\n\n");
            		printf("What Do You Want To Modify ? \n 1. Address\n 2. Phone\n Enter Your Choice:\n");
            		scanf("%d", &choice);
            		if(choice == 1) {
				printf("Enter New City:\n");
                		scanf("%s", mod.city);
                		x = fprintf(newrec, "%d %s %s %s %d/%d/%d %d %s %ld %s %f %d/%d/%d\n", add.acc_no, add.fname, add.mname, add.lname, add.dob.day, add.dob.month, add.dob.year, add.age, mod.city, add.phone, add.acc_type, add.amount, add.deposit.day, add.deposit.month, add.deposit.year);
				
				if(x>0)
					printf("Account Updation Success !\n\n\n");
				else
					printf("Account Updation Failed !\n\n\n");
        		}
        		
		else if(choice == 2) 
			{
			printf("enter new phone no:\n");
			scanf("%ld",&mod.phone);
			x = fprintf(newrec, "%d %s %s %s %d/%d/%d %d %s %ld %s %f %d/%d/%d\n", add.acc_no, add.fname, add.mname, add.lname, add.dob.day, add.dob.month, add.dob.year, add.age, add.city, mod.phone, add.acc_type, add.amount, add.deposit.day, add.deposit.month, add.deposit.year);
				
				if(x>0)
					printf("Account Updation Success !\n\n\n");
				else
					printf("Account Updation Failed !\n\n\n");
		}
        		else
            		fprintf(newrec, "%d %s %s %s %d/%d/%d %d %s %ld %s %f %d/%d/%d\n", add.acc_no, add.fname, add.mname, add.lname, add.dob.day, add.dob.month, add.dob.year, add.age, add.city, add.phone, add.acc_type, add.amount, add.deposit.day, add.deposit.month, add.deposit.year);
    	}
    	fclose(oldrec);
    	fclose(newrec);
    	remove("bank.dat");
    	rename("temp.dat","bank.dat");
	printf("=====================================================================================\n\n");
	if(flag != 1) {
        	printf("No Record Found\n");
            	mod_invalid:
              	printf("Enter Your Choice\n1. Try Again\2. Main Menu\n3. Exit");
              	scanf("%d", &quit);
                if (quit == 1) {
                	mod_acc();
                }
                else if (quit == 2) {
                    	menu();
                }
                else if(quit == 3)
                    	close();
                else {
                	
			printf("Invalid Option !\n");
             
		}
        }
    	else {
		printf("Enter Your Choice\n1. Main Menu\n2. Quit\n");
        	scanf("%d", &quit);
        	if (quit == 1) {
            		menu();
            	}
       	 	else {
            		close();
            	}
        }

}}
void transaction_acc() {
	int choice, flag = 0;
	int quit = 0;
    	FILE *oldrec, *newrec;
	
	printf("|***************************** TRANSACTION  PAGE *********************************** |\n");
	
    	oldrec = fopen("bank.dat","r");
    	newrec = fopen("temp.dat","w");
	if(oldrec == NULL) {
		perror("Open Failed :");
		printf("No Accounts Exist !\n");
		printf("Enter Your Choice\n\t1. Main Menu\n\t2. Exit\n");
    		scanf("%d", &quit);
    		if (quit == 1) {
        	menu();
        	}
    		else (quit == 2);{
        	close();	
		}		
	}
	if(newrec == NULL) {
		perror("Open Failed :");
		printf("Enter Your Choice\n\t1. Main Menu\n\t2. Exit\n");
    		scanf("%d", &quit);
    		if (quit == 1) {
        	menu();
        	}
    		else (quit == 2);{
        	close();	
		}	
	}        
	printf("Enter Account Number:\n");
    	scanf("%d", &transaction.acc_no);
    	
    	while(fscanf(oldrec, "%d %s %s %s %d/%d/%d %d  %s %ld %s %f %d/%d/%d", &add.acc_no, add.fname, add.mname, add.lname, &add.dob.day, &add.dob.month, &add.dob.year, &add.age, add.city, &add.phone, add.acc_type, &add.amount, &add.deposit.day, &add.deposit.month, &add.deposit.year) != EOF) {
        	if(add.acc_no == transaction.acc_no) {   
			flag = 1;
                	
                	printf("1. Deposit\n\n2. Withdraw\n\nEnter your choice:\n");
                	scanf("%d", &choice);
                	printf("======================================================================================\n\n\n");
                	if (choice == 1) {
                    		printf("Enter The Amount You Want To Deposit:$ \n");
                    		scanf("%f", &transaction.amount);
				
                    		add.amount += transaction.amount;
			
                    		fprintf(newrec, "%d %s %s %s %d/%d/%d %d %s  %ld %s %f %d/%d/%d\n", add.acc_no, add.fname, add.mname, add.lname, add.dob.day, add.dob.month, add.dob.year, add.age, add.city, add.phone, add.acc_type, add.amount, add.deposit.day, add.deposit.month, add.deposit.year);
                    		printf("Transaction Successful !\nAmount Deposited $ %.2f\nNew Balance is $ %.2f\n\n", transaction.amount, add.amount);
                	}
                	else {
                    		printf("Enter the amount you want to withdraw:$ \n");
                    		scanf("%f", &transaction.amount);
			
                    		if(transaction.amount > add.amount) {
                    			printf("less balance ! sorryy!\n\n");
					printf("Enter Your Choice\n\t1. Main Menu\n\t2. Exit\n");
    	   				scanf("%d", &quit);
    					if (quit == 1) {
       				 	menu();
        				}
    					else (quit == 2);{
        				close();	
					}                  		
				}
                    		else
                    			add.amount -= transaction.amount;
					
                    		fprintf(newrec, "%d %s %s %s %d/%d/%d %d %s %ld %s %f %d/%d/%d\n", add.acc_no, add.fname, add.mname, add.lname, add.dob.day, add.dob.month, add.dob.year, add.age, add.city, add.phone, add.acc_type, add.amount, add.deposit.day, add.deposit.month, add.deposit.year);
                    		printf("Transaction Successful !\nAmount Withdrawn $ %.2f\nNew Balance is $ %.2f\n\n", transaction.amount, add.amount);
                	}
             	}
            	else
               		fprintf(newrec, "%d %s %s %s %d/%d/%d %d %s  %ld %s %f %d/%d/%d\n", add.acc_no, add.fname, add.mname, add.lname, add.dob.day, add.dob.month, add.dob.year, add.age, add.city, add.phone, add.acc_type, add.amount, add.deposit.day, add.deposit.month, add.deposit.year);
   	}
   	fclose(oldrec);
   	fclose(newrec);
   	remove("bank.dat");
    	rename("temp.dat","bank.dat");
	printf("======================================================================================\n\n\n");
   	if(flag != 1) {
       		printf("No Record Found !\n");
      		printf("Enter Your Choice\n1. Try Again\n2. Main Menu\n3. Quit\n");
      		scanf("%d", &quit);
      		if (quit == 1)
        		transaction_acc();
    		else if (quit == 2)
        		menu();
    		else if (quit == 3)
        		close();
    		
   	}
   	else {

       		printf("Enter Your Choice\n1. Main Menu\n2. Quit\n");
        	scanf("%d", &quit);
        	if (quit == 1)
            		menu();
       	 	else
            		close();
   	}
}
void delete_acc(void) {
	FILE *oldrec, *newrec;
    	int flag = 0;
	int quit = 0;
	
	printf("|****************************** ACCOUNT DELETION WIZARD **************************************** |\n");
	
    	oldrec = fopen("bank.dat","r");
    	newrec = fopen("temp.dat","w");
    	if(oldrec == NULL) {
		perror("Open Failed :");
		printf("No Accounts Exist !\n");
		printf("Enter Your Choice\n\t1. Main Menu\n\t2. Exit\n");
    		scanf("%d", &quit);
    		if (quit == 1) {
        	menu();
        	}
    		else (quit == 2);{
        	close();	
		}				
	}
	if(newrec == NULL) {
		perror("Open Failed :");
		printf("Enter Your Choice\n\t1. Main Menu\n\t2. Exit\n");
    		scanf("%d", &quit);
    		if (quit == 1) {
        	menu();
        	}
    		else (quit == 2);{
        	close();	
		}				
	}
	printf("Enter Account Number To Delete:\n");
    	scanf("%d", &del.acc_no);
	printf("======================================================================================\n\n\n");
    	while (fscanf(oldrec, "%d %s %s %s %d/%d/%d %d %s  %ld %s %f %d/%d/%d", &add.acc_no, add.fname, add.mname, add.lname, &add.dob.day, &add.dob.month, &add.dob.year, &add.age, add.city, &add.phone, add.acc_type, &add.amount, &add.deposit.day, &add.deposit.month, &add.deposit.year) != EOF) {
        	if(add.acc_no != del.acc_no)
            		fprintf(newrec, "%d %s %s %s %d/%d/%d %d %s  %ld %s %f %d/%d/%d\n", add.acc_no, add.fname, add.mname, add.lname, add.dob.day, add.dob.month, add.dob.year, add.age, add.city, add.phone, add.acc_type, add.amount, add.deposit.day, add.deposit.month, add.deposit.year);
        	else {
			flag++;
            		printf("Account Deleted Successfully.. !\n");
            	}
   	}
   	fclose(oldrec);
   	fclose(newrec);
   	remove("bank.dat");
   	rename("temp.dat","bank.dat");
   	if(flag == 0) {
            	printf("No Record Found !!\n");
		printf("======================================================================================\n\n\n");
              	printf("Enter Your Choice\n1. Try Again\n2. Main Menu\n3. Quit\n");
              	scanf("%d", &quit);
                if (quit == 1) {
                    	delete_acc();
                }
                else if (quit == 2) {
                    	menu();
                }
                else (quit == 3);
                    	close();
              
      	}
    	else {
		printf("======================================================================================\n\n\n");
		printf("Enter Your Choice\n1. Main Menu\n2. Quit\n");
        	scanf("%d", &quit);
        	if (quit == 1) {
            		menu();
            	}
        	else
            		close();
        }
}

