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
void view_list()
{
    FILE *view;
    view=fopen("bank.dat","r");
    int test=0;
    int main_exit;

    printf("\n\n*****************account holder list*****************************");
   
    while(fscanf(view,"%d %s %s %s %d/%d/%d %d %s %ld %s %f %d/%d/%d",&add.acc_no,add.fname,add.mname,add.lname,&add.dob.month,
		&add.dob.day,&add.dob.year,&add.age,add.city, &add.phone ,add.acc_type,&add.amount, &add.deposit.month,
		&add.deposit.day, &add.deposit.year)  != EOF){

        printf("ACCOUNT	:%d\n",add.acc_no);
	printf("first name	:%s\n",add.fname);
	printf("middle name	:%s\n",add.mname);
	printf("last name	:%s\n",add.lname);
	printf("dob(mm/dd/yy)	:%d/%d/%d\n",add.dob.month,add.dob.day,add.dob.year);
	printf("AGE		:%d\n",add.age);
	printf("city		:%s\n",add.city);
	printf("mobile		:%ld\n",add.phone);
	printf("account type	:%s\n",add.acc_type);
	printf("amount		:%f\n",add.amount);
	printf("deposit(mm/dd/yy)	%d/%d/%d \n\n\n",add.deposit.month,add.deposit.day,add.deposit.year);
		test++;
           
       }
	printf("\n================================================================================================\n");

    fclose(view);
    if (test==0)
        {  
            printf("\nNO RECORDS!!\n");}

   
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
      
}
