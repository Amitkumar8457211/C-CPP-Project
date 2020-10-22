#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

FILE *fp;
 struct detail
{	
	char name[20];
	char admno[12];
	char dob[12];
	char branch[15];
	char state[15];
	char year[6];
	char mobno[12];
	char adhno[18];
	char roll[12];
 };
struct detail rec,rec1;
 void layout();
 void loading();
 void option();
 void showalldata();
 void getdata();
 void findstudent();
 void showdata();
 void showbranch();
 void showyear();
 void showstate();
 void showuniroll();
 void margin(char[],int);
 void open();

 void main()
{
       open();
       loading();
	option();

}

 void margin(char str[],int m)
 {
   int l=strlen(str);
   int s=m-l;
   for(int i=0;i<s;i++)
   {
	  cout<<" ";
   }

  }
void  open()
{
	fp=fopen("svietstudentdetail.txt","a+");
	if(fp==NULL)
	{
	layout();
	gotoxy(31,12);
	printf("file could not open");
	delay(2000);
	exit(0);
	}
}
void layout()
{
	clrscr();
	textcolor(2);
	textbackground(2);
	gotoxy(16,3);
	cprintf("##################################################");
	gotoxy(16,7);
	cprintf("##################################################");
	gotoxy(16,20);
	cprintf("##################################################");
	gotoxy(16,22);
	cprintf("##################################################");
	for(int i=0;i<20;i++)
	{
		 gotoxy(16,3+i);
		cprintf("#");
		 gotoxy(65,3+i);
		 cprintf("#");
	}
	textcolor(13);
	textbackground(0);
	gotoxy(27,21);
	cprintf("Design by Super60 group H");
	textcolor(1);
	gotoxy(27,5);
	cprintf("*Super 60 Student Record*");
	textcolor(15);
	textbackground(0);
}
void loading()
{
	layout();
	textcolor(3);
	gotoxy(35,10);
	cprintf("Student Record");
	gotoxy(26,12);
	cprintf("Loading....");
	gotoxy(26,16);
	cprintf("Pease wait...");
	for(int i=0;i<15;i++)
	{

		gotoxy(26+(i*2),14);
		textbackground(3);
		cprintf("##");
		delay(400);
		textbackground(0);
	}

}
void getdata()
{
	layout();
	textcolor(6);
	gotoxy(20,9);
	cprintf("Name:");
	gotoxy(20,10);
	cprintf("Admission no.:");
	gotoxy(20,11);
	cprintf("University roll no.:");
	gotoxy(20,12);
	cprintf("Branch:");
	gotoxy(20,13);
	cprintf("year:");
	gotoxy(20,14);
	cprintf("DOB:");
	gotoxy(20,15);
	cprintf("Adhaar no.:");
	gotoxy(20,16);
	cprintf("State:");
	gotoxy(20,17);
	cprintf("Mob no.:");
	gotoxy(20,19);
	cprintf("Press C for confirm");
	gotoxy(44,19);
	cprintf("Press X for Back ");
	gotoxy(40,9);
	gets(rec.name);
	gotoxy(40,10);
	gets(rec.admno);
	gotoxy(40,11);
	gets(rec.roll);
	gotoxy(40,12);
	gets(rec.branch);
	gotoxy(40,13);
	gets(rec.year);
	gotoxy(40,14);
	gets(rec.dob);
	gotoxy(40,15);
	gets(rec.adhno);
	gotoxy(40,16);
	gets(rec.state);
	gotoxy(40,17);
	gets(rec.mobno);
	gotoxy(40,18);
	again:
	char c=getch();
	switch(c)
	{
		case 'c':case'C':
		{
			int c=0;
			rewind(fp);
			char check[11];
			strcpy(check,rec.admno);
			while((fread(&rec1,sizeof(rec1),1,fp))>0)
			{
				if(strcmp(check,rec1.admno)==0)
				{
					 c++;
				}
			}
			 if(c!=0)
			 {
				layout();
				gotoxy(28,14);
				printf("Student allready found  ");
				gotoxy(28,15);
				delay(2000);
				option();
			  }
			  else
			  {
				   layout();
				   rewind(fp);
				   if(fwrite(&rec,sizeof(rec),1,fp)>0)
				   {
					  gotoxy(26,14);
					  printf("         Record Save       ");
					  delay(2000);
					  option();
				   }
			   }
		}
		case 'x':
		{
			option();
		}
		default:
		{
			goto again;
		}
	}
}
void deletedata()
{
    layout();
    int c=0;
    char admno[12];
	textcolor(15);
    gotoxy(20,11);
	cprintf("Enter Admission no. to delete: ");
	gotoxy(51,11);
	gets(admno);
	gotoxy(28,14);
	cprintf("press Backspace for back");
	gotoxy(28,15);
	cprintf("  press C for confirm");
	again:
	char ch=getch();
	if(ch==' ')
	{
	     option();
	}
	if(ch=='c'||ch=='C')
	{
	rewind(fp);
	while((fread(&rec,sizeof(rec),1,fp))>0)
	{
		if(strcmp(admno,rec.admno)==0)
		{
		    c++;
		    layout();
			textcolor(6);
			gotoxy(20,9);
			cprintf("Name:");
			gotoxy(20,10);
			cprintf("Admission no.:");
			gotoxy(20,11);
			cprintf("University roll no.:");
			gotoxy(20,12);
			cprintf("Branch:");
			gotoxy(20,13);
			cprintf("year:");
			gotoxy(20,14);
			cprintf("DOB:");
			gotoxy(20,15);
			cprintf("Adhaar no.:");
			gotoxy(20,16);
			cprintf("State:");
			gotoxy(20,17);
			cprintf("Mob no.:");
			gotoxy(20,18);
			cprintf("Press B for back");
			gotoxy(44,18);
			cprintf("Press C for Confirm");
			textcolor(15);
			gotoxy(40,9);
			puts(rec.name);
			gotoxy(40,10);
			puts(rec.admno);
			gotoxy(40,11);
			puts(rec.roll);
			gotoxy(40,12);
			puts(rec.branch);
			gotoxy(40,13);
			puts(rec.year);
			gotoxy(40,14);
			puts(rec.dob);
			gotoxy(40,15);
			puts(rec.adhno);
			gotoxy(40,16);
			puts(rec.state);
			gotoxy(40,17);
			puts(rec.mobno);
			show:
			char c=getch();
			if(c=='b'||c=='B')
			{
				option();
			}
			if(c=='c'||c=='C')
			{
				fclose(fp);
		FILE *temp;
			fp = fopen("svietstudentdetail.txt","rb");
				 temp = fopen("temp.txt", "wb");
			    while(fread(&rec, sizeof(rec),1,fp) > 0)
				{
				if(strcmp(admno,rec.admno) != 0)
				{
					  fwrite(&rec,sizeof(rec),1,temp);
				}
			}
				    fclose(temp);
					 fclose(fp);
					 remove("svietstudentdetail.txt");
					 rename("temp.txt","svietstudentdetail.txt");
					 open();
					 layout();
					 gotoxy(25,12);
				cprintf("The record is sucessfully deleted");
				delay(2000);
				option();
			}
			else
			{
				goto show;
			}
		}
	}

}
	if(c==0)
	{
		layout();
		gotoxy(27,14);
		printf("     Account not found      ");
		gotoxy(27,15);
		printf("press any key to continue...");
		getch();
		option();
	}

	else
	{
	goto again;
	}
}
void option()
{
	layout();
	textcolor(5);
	gotoxy(26,11);
	cprintf("1.Show all Students");
	gotoxy(26,12);
	cprintf("2.Add Student");
	gotoxy(26,13);
	cprintf("3.Delete Student");
	gotoxy(26,14);
	cprintf("4.Find Student");
	gotoxy(26,15);
	cprintf("5.Exit");
	again:
	char c=getch();
	switch(c)
	{
		case '1':
		{
		  showalldata();
		  break;
		}
		case '2':
		{
			getdata();
			break;
		}
		case '3':
		{
			deletedata();
			break;
		}
		case '4':
		{
			findstudent();
			break;
		}
		case '5':
		{
			fclose(fp);
			exit(0);
		}
		default:
		{
			goto again;
		}
	}
	goto again;
}
void findstudent()
{
	layout();
	textcolor(4);
	gotoxy(30,10);
	cprintf("1.By Admission no");
	gotoxy(30,11);
	cprintf("2.By Branch");
	gotoxy(30,12);
	cprintf("3.By Year");
	gotoxy(30,13);
	cprintf("4.By State");
	gotoxy(30,14);
	cprintf("5.Back");
	textcolor(15);
	gotoxy(40,16);
	again:
	char c=getch();
	switch(c)
	{
	    case '1':
		{
		    showdata();
		    findstudent();
		}
		case '2':
		{
			showbranch();
			findstudent();
		}
		case '3':
		{      showyear();
			findstudent();

		}
		case '4':
		{        showstate();
			 findstudent();

		}
		case '5':
		{
			option();
		}
		default:
		{
			goto again;
		}
	}

}
void showdata()
{

	layout();
	char admno[12];
	textcolor(15);
	gotoxy(20,11);
	cprintf("Enter your Admission no.: ");
	gotoxy(48,11);
	gets(admno);
	gotoxy(28,14);
	cprintf("press Backspace for back");
	gotoxy(28,15);
	cprintf("  press C for confirm");
	again:
	char ch=getch();
	if(ch==' ')
	{
	     findstudent();
	}
	if(ch=='c'||ch=='C')
	{
	int c=0;
	rewind(fp);
	while((fread(&rec,sizeof(rec),1,fp))>0)
	{
		if(strcmp(admno,rec.admno)==0)
		{
		    c++;
		    layout();
			textcolor(6);
			gotoxy(20,9);
			cprintf("Name:");
			gotoxy(20,10);
			cprintf("Admission no.:");
			gotoxy(20,11);
			cprintf("University roll no.:");
			gotoxy(20,12);
			cprintf("Branch:");
			gotoxy(20,13);
			cprintf("year:");
			gotoxy(20,14);
			cprintf("DOB:");
			gotoxy(20,15);
			cprintf("Adhaar no.:");
			gotoxy(20,16);
			cprintf("State:");
			gotoxy(20,17);
			cprintf("Mob no.:");
			gotoxy(30,18);
			cprintf("Press X for back");
			textcolor(15);
			gotoxy(40,9);
			puts(rec.name);
			gotoxy(40,10);
			puts(rec.admno);
			gotoxy(40,11);
			puts(rec.roll);
			gotoxy(40,12);
			puts(rec.branch);
			gotoxy(40,13);
			puts(rec.year);
			gotoxy(40,14);
			puts(rec.dob);
			gotoxy(40,15);
			puts(rec.adhno);
			gotoxy(40,16);
			puts(rec.state);
			gotoxy(40,17);
			puts(rec.mobno);
			show:
			char c=getch();
			if(c=='x'||c=='X')
			{
				findstudent();
			}
			else
			{
				goto show;
			}
		}
	}
	if(c==0)
	{
		layout();
		gotoxy(27,14);
		printf("     Account not found      ");
		gotoxy(27,15);
		printf("press any key to continue...");
		getch();
	}
	}
	else
	{
	goto again;
	}
}
void showalldata()
{
	clrscr();
	int i=0,n=0;
	rewind(fp);
	cout<<"S.no "<<"Student Name";
	margin("Student Name",25);
	cout<<"Admission No";
	margin("Admission no",12);
    cout<<"\n--------------------------------------------------------------------------------";
	while((fread(&rec,sizeof(rec),1,fp))>0)
	{
	    if(i<=20)
		{
			cout<<endl;
			cout<<++n<<"   " ;
	       cout<<rec.name;
	   margin(rec.name,25);
	       cout<<rec.admno;
		       margin(rec.admno,12);
			i++;
			if(i==21)
			{
				cout<<"\t\t\t\tpress enter to continue";
				getch();
				clrscr();
				cout<<"S.no "<<"Student Name";
				margin("Student Name",30);
				cout<<"Admission No";
				margin("Admission no",15);
		    cout<<"\n--------------------------------------------------------------------------------";
		    i=0;
			}
		}
	}
    printf("\n\n\t\t\tEnding \n");
    getch();
    option();
}

void showbranch()
{
       layout();
	char branch[15];
	gotoxy(25,11);
	printf("Enter Branch : ");
	gotoxy(40,11);
	gets(branch);
	gotoxy(28,14);
	printf("press Backspace for back");
	gotoxy(28,15);
	printf("  press C for confirm");
	again:
	char ch=getch();
	if(ch==' ')
	{
	     findstudent();
	}
	if(ch=='c'||ch=='C')
	{
	   clrscr();
	   int i=0,n=0;
	   rewind(fp);
	   cout<<"S.no "<<"Student Name";
	   margin("Student Name",30);
	   cout<<"Admission No";
	   margin("Admission no",15);
	   cout<<"Branch";
	   margin("Branch",15);
	   cout<<"\n--------------------------------------------------------------------------------";
	   while((fread(&rec,sizeof(rec),1,fp))>0)
	  {
		if(strcmp(branch,rec.branch)==0)
		{
			if(i<=20)
			{
				cout<<endl;
				cout<<++n<<"   " ;
				cout<<rec.name;
				margin(rec.name,30);
				cout<<rec.admno;
				margin(rec.admno,15);
				cout<<rec.branch;
				margin(rec.branch,15);
			       i++;
			       if(i==20)
			       {
					cout<<"\t\t\t\tpress enter to continue";
					getch();
					clrscr();
					cout<<"S.no "<<"Student Name";
					margin("Student Name",30);
					cout<<"Admission No";
					margin("Admission no",15);
					cout<<"branch";
					margin("Branch",15);
					cout<<"\n--------------------------------------------------------------------------------";
					i=0;
				}
			}
		      }
		}
		printf("\n\n\t\t\tEnding \n");
	getch();
	}
	else
	{
	goto again;
	}
}
void showyear()
{
       layout();
	char year[6];
	gotoxy(25,11);
	printf("Enter Year : ");
	gotoxy(40,11);
	gets(year);
	gotoxy(28,14);
	printf("press Backspace for back");
	gotoxy(28,15);
	printf("  press C for confirm");
	again:
	char ch=getch();
	if(ch==' ')
	{
	     findstudent();
	}
	if(ch=='c'||ch=='C')
	{
	   clrscr();
	   int i=0,n=0;
	   rewind(fp);
	   cout<<"S.no "<<"Student Name";
	   margin("Student Name",30);
	   cout<<"Admission No";
	   margin("Admission no",15);
	   cout<<"Year";
	   margin("year",4);
	   cout<<"\n--------------------------------------------------------------------------------";
	   while((fread(&rec,sizeof(rec),1,fp))>0)
	  {
		if(strcmp(year,rec.year)==0)
		{
			if(i<=20)
			{
				cout<<endl;
				cout<<++n<<"   " ;
				cout<<rec.name;
				margin(rec.name,30);
				cout<<rec.admno;
				margin(rec.admno,15);
				cout<<rec.year;
				margin(rec.year,15);
			       i++;
			       if(i==20)
			       {
					cout<<"\t\t\t\tpress enter to continue";
					getch();
					clrscr();
					cout<<"S.no "<<"Student Name";
					margin("Student Name",30);
					cout<<"Admission No";
					margin("Admission no",15);
					cout<<"Year";
					margin("Year",15);
					cout<<"\n--------------------------------------------------------------------------------";
					i=0;
				}
			}
		      }
		}
		printf("\n\n\t\t\tEnding \n");
	getch();
	}
	else
	{
	goto again;
	}
}
void showstate()
{
       layout();
	char state[15];
	gotoxy(25,11);
	printf("Enter State : ");
	gotoxy(40,11);
	gets(state);
	gotoxy(28,14);
	printf("press Backspace for back");
	gotoxy(28,15);
	printf("  press C for confirm");
	again:
	char ch=getch();
	if(ch==' ')
	{
	     findstudent();
	}
	if(ch=='c'||ch=='C')
	{
	   clrscr();
	   int i=0,n=0;
	   rewind(fp);
	   cout<<"S.no "<<"Student Name";
	   margin("Student Name",30);
	   cout<<"Admission No";
	   margin("Admission no",15);
	   cout<<"State";
	   margin("State",15);
	   cout<<"\n--------------------------------------------------------------------------------";
	   while((fread(&rec,sizeof(rec),1,fp))>0)
	  {
		if(strcmp(state,rec.state)==0)
		{
			if(i<=20)
			{
				cout<<endl;
				cout<<++n<<"   " ;
				cout<<rec.name;
				margin(rec.name,30);
				cout<<rec.admno;
				margin(rec.admno,15);
				cout<<rec.state;
				margin(rec.state,15);
			       i++;
			       if(i==20)
			       {
					cout<<"\t\t\t\tpress enter to continue";
					getch();
					clrscr();
					cout<<"S.no "<<"Student Name";
					margin("Student Name",30);
					cout<<"Admission No";
					margin("Admission no",15);
					cout<<"state";
					margin("state",15);
					cout<<"\n--------------------------------------------------------------------------------";
					i=0;
				}
			}
		      }
		}
		printf("\n\n\t\t\tEnding \n");
	getch();
	}
	else
	{
	goto again;
	}
}

