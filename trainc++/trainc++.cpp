// trainc++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include<process.h>
#include<dos.h>
//#include<graphics>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int f = 0, col = 0;
class emp
{
	int eid;
	char ename[50], dept[70], doj, comno[10], sno[10], desig[20];
public:
	void _input()
	{
		cout << "\n\n\t\t (please enter the following details of employee) ";
		cout << "\n\n\t Id   :\t";
		cin >> eid;
		cout << "\n\n\t Name            :\t";
		gets_s(ename);
		cout << "\n\n\t Department      :\t";
		gets_s(dept);
		cout << "\n\n\t Date Of Joining :\n \t   (DD-MM-YYYY)  \t";
		cin >> doj;
		cout << "\n\n\t Intercom Number :\t";
		cin >> comno;
		cout << "\n\n\t Seat Number     :\t";
		cin >> sno;
		cout << "\n\n\t Designation     :\t";
		cin >> desig;
	}
};
class book
{
	int b_id;
	char title[30], author[30], cat[30];
	float price;
public:
	void bookin()
	{
  		cout << "\n\n\t\t (please enter the following details of book) ";
		cout << "\n\n\t Id       :\t";
		cin >> b_id;
		puts("\n\n\t Title    :\t");
//		cout << ;
		gets_s(title);
		//cout << "\n\n\t Author   :\t";
		gets_s(author);
		//cout << "\n\n\t Category : \t";
		gets_s(cat);
		//cout << "\n\n\t Price    :\t";
		cin >> price;
	}
	void bookout()
	{
		cout << "\n\n\t Id       :\t" << b_id;
		cout << "\n\n\t Title    :\t" << title;
		cout << "\n\n\t Author   :\t" << author;
		cout << "\n\n\t Category : \t" << cat;
		cout << "\n\n\t Price    :\t" << price;
	}
	int retb_id()
	{
		return b_id;
	}
};
void book_read()
{
	system ("cls");
	book b;
	cout << "\n\n\t\tBOOK DETAILS";
	fstream f("book.dat", ios::in | ios::binary);
	while (f.read((char*)&b, sizeof(book)))
	{
		b.bookout();
	}
	f.close();
}
void book_write()
{
	char ch;
	book b;
	fstream f("book.dat", ios::out | ios::app | ios::binary);
	do
	{
		system ("cls");
		b.bookin();
		f.write((char*)&b, sizeof(b));
		system ("cls");
		cout << "\n\n\n\n\t\t BOOK SUCCESSFULLY ADDED";
		cout << "\n\n\t Do you want to add more book.....(y/n)?";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	f.close();
}
void book_rem(int bb)
{
	book b;
	fstream f("book.dat", ios::in | ios::out | ios::binary);
	fstream f1("temp.dat", ios::out | ios::binary);
	f.seekg(0, ios::beg);
	while (f.read((char*)&b, sizeof(b)))
	{
		if (bb != b.retb_id())
		{
			f1.write((char*)&b, sizeof(book));
		}
	}
	f.close();
	f1.close();
	remove("book.dat");
	rename("temp.dat", "book.dat");
	cout << "\n\n\t\t Book Deleted...... ";
	/*delay(1500);*/
}
int mainmenu()
{
	system ("cls");
	int i;
	cout << "\n\n\n\t\t(press number keys for your choice)";
	cout << "\n\n\n\t\t\t1> BOOK MASTER";
	cout << "\n\n\n\t\t\t2> EMPLOYEE MASTER";
	cout << "\n\n\n\t\t\t3> BOOK ISSUE/RETURN";
	cout << "\n\n\n\t\t\t4> EXIT";
	cin >> i;
	return i;
}
int bookmas()
{
	do
	{
		system ("cls");
		int _inp;
		cout << "\n\n\n\t\t(press number keys for your choice)";
		cout << "\n\n\n\t\t\t1> ADD NEW BOOK";
		cout << "\n\n\n\t\t\t2> REMOVE BOOK";
		cout << "\n\n\n\t\t\t3> UPDATE BOOK";
		cout << "\n\n\n\t\t\t4> DISPLAY BOOK";
		cout << "\n\n\n\t\t\t5> EXIT\t";
		cin >> _inp;
		if (_inp == 1)
		{
			system ("cls");
			book_write();
		}
		else if (_inp == 2)
		{
			int boid;
			system ("cls");
			cout << "\n\n\n\n\n\n\n\t\t\t Enter Book Id :\t";
			cin >> boid;
			book_rem(boid);
		}
		else if (_inp == 3)
		{
			int bokid;
			system ("cls");
			cout << "\n\n\n\n\n\n\n\t\t\t Enter Book Id :\t";
			cin >> bokid;
			return bokid;
		}
		else if (_inp == 4)
		{
			system ("cls");
			book_read();
		}
		else if (_inp == 5)
		{
			system ("cls");
			/*sound(10);
			textcolor(col + 5);
			gotoxy(30, 12);
			textbackground(3);*/
			_cprintf(" THANK YOU ");
			/*delay(2000);*/
			exit(0);
		}
		else
			cout << "WRONG _inpUT !!!!!";
	} while (_inp != 0);
}

void login()
{
	int p;
	int idd = 12345;
	p = 12345;
	do
	{
		int id;
		int pass;
	/*	gotoxy(30, 10);
		textcolor(3);
		textbackground(col + 2);*/
		cout << "USER ID  :\t";
		cin >> id;
		/*gotoxy(30, 12);*/
		cout << "PASSWORD :\t";
		cin >> pass;
		if (id == idd&&p == pass)
		{
			system ("cls");
			f = 1;
			/*gotoxy(25, 13);
			textbackground(col + 5);*/
			cout << "LOGIN ID & PASSWORD MATCHED";
			/*delay(1000);*/
			break;
		}
		else
		{
			system ("cls");
			/*gotoxy(25, 13);*/
			cout << "WRONG PASSWORD OR LOGIN ID";
			/*delay(1500);
			*/exit(0);
		}
	} while (f != 1);
}
//int wel(void)
//{
//	int gdriver = DETECT, gmode, errorcode;
//	int left, top, right, bottom;
//	initgraph(&gdriver, &gmode, "");
//	errorcode = graphresult();
//	if (errorcode != grOk)
//	{
//		printf("Graphics error: %s\n", grapherrormsg(errorcode));
//		printf("Press any key to halt:");
//		_getch();
//		exit(1);
//	}
//	left = getmaxx() / 2 - 200;
//	top = getmaxy() / 2 - 200;
//	right = getmaxx() / 2 + 200;
//	bottom = getmaxy() / 2 + 200;
//	rectangle(left, top, right, bottom);
//	gotoxy(31, 15);
//	textbackground(col + 1);
//	textcolor(4);
//	cout << " WELCOME ";
//	_getch();
//	closegraph();
//	return 0;
//}

int _tmain(int argc, _TCHAR* argv[])
{
	system ("cls");
	//wel();
	int k;
	login();
	k = mainmenu();
	if (k == 1)
	{
		system ("cls");
		bookmas();
	}
	_getch();
	return 0;
}

