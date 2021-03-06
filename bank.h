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
struct data{
	int day,month,year;
};

struct {
	char fname[9],mname[9],lname[9],city[9];
	char address [9];
	int acc_no , age;
	char acc_type[10];
	long int phone;
	float amount;
	struct data dob;
	struct data deposit;
	struct data withdraw;
}add,mod,check,del,transaction;



void menu();
void add_acc();
void mod_acc();
void check_acc();
void delete_acc();
void show_acc();
void transaction_acc();
float si(float t,float amount ,int rate);
