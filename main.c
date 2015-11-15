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
#include"bank.h"
int main()
{
    char pass[10],password[10]="palash";
    int i=0;
    int main_exit;
    printf("\n\n\t\t login:");
    scanf("%s",pass);

    if ( strcmp (pass,password) == 0 )
	{
        printf("\n\nPassword Match! \n  LOADING");
        for(i=0;i<=6;i++)
        {
            printf(".");
        }
            menu();
        }
    else
        {   printf("\n\n Wrong password!!  \n\n\n");
          
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        main();
                    }
            else
                 {
			printf("\nInvalid!\n");
			close();
			//printf("\n******thankyu********\n");	    	
		   }

        }
        return 0;
}
