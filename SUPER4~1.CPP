#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

#include <windows.h>

void layout();
void takedata();
void login();
void alllist();
void option();
void Withdraw();
void Deposit();
void balance();
void passbook();


COORD coord = {0,0}; ///set the cordinate to 0, 0 (top-left corner of window);
void gotoxy(int x, int y){
    coord.X = x; coord.Y = y; /// X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void clearWindow(){
   /* int i,j;
    for(i = 37; i < 78; i++){
        for(j = 7; j < 25; j++){
            gotoxy(i,j);printf(" ");
        }
    }*/
    system("cls");
    return;
}

struct detail
{
	char name[30];
	char password[10];
	float bal;
}rec;
struct detail1
{
	char name[30];
	char password[10];
	float bal;
}rec1;
 FILE *fp;
 FILE *fp1;
	char name1[30];
	char password1[10];

int main()
{
	fp=fopen("super40bank.txt","a+");
	fp1=fopen("svietbank.txt","a+");
	if(fp==NULL&&fp1==NULL)
	{      // clrscr();
		clearWindow();
		layout();
		gotoxy(31,12);
		printf("file could not open");
		gotoxy(27,14);
		printf("Press ant key to continue...");
		getch();
		exit(0);
	}

	while(1)
	{       //clrscr();
		clearWindow();
		layout();
		gotoxy(32,11);
		printf("1. Login ");
		gotoxy(32,12);
		printf("2. Open Account");
		gotoxy(32,13);
		printf("3. Exit");
		gotoxy(32,15);
		printf("Enter your choice...");
		char c;
		c=getch();
		switch(c)
		{
		case'1':
		{
			login();
			break;
		}
		case'2':
		{
			takedata();
			break;
		}
		case'3':
		{
			fclose(fp);
			fclose(fp1);
			exit(0);
		}
		case'$':
		{
			alllist();
			getch();
			break;
		}
		}
	}
return 0;
}

void layout()
{      // textcolor(2);
	//textbackground(2);
	gotoxy(16,3);
	printf("##################################################");
	gotoxy(16,7);
	printf("##################################################");
	gotoxy(16,20);
	printf("##################################################");
	gotoxy(16,22);
	printf("##################################################");
	for(int i=0;i<20;i++)
	{
	 gotoxy(16,3+i);
	 printf("#");
	 gotoxy(65,3+i);
	 printf("#");
	}
	//textcolor(13);
	//textbackground(0);
	gotoxy(28,21);
	printf("Design by Amit kumar...");
	//textcolor(1);
	gotoxy(28,5);
	printf("**SVIET Super 60 Bank**");
	//textcolor(15);
	//textbackground(0);
}

void takedata()
{
    //clrscr();
    clearWindow();
    layout();
    char name[30];
    char password[10];
    gotoxy(24,11);
    printf("Enter your name: ");
    gotoxy(24,12);
    printf("Enter password : ");
    gotoxy(42,11);
    gets(name);
    gotoxy(42,12);
    gets(password);
    gotoxy(28,14);
    printf("press Backspace for back");
    gotoxy(28,15);
    printf("press Enter for conform");
    char ch=getch();
    if(ch==' ')
    {
     return;
    }
    int c=0;
    rewind(fp);
    while((fread(&rec,sizeof(rec),1,fp))>0)
    {
	if((strcmp(name,rec.name)==0)&&(strcmp(password,rec.password)==0))
	{
	     c++;
	}
    }
    if(c!=0)
    {
	 gotoxy(28,14);
	  printf("Account allready found   ");
	  gotoxy(28,15);
	  printf("Press any key to continue...");
	  getch();
    }
    else
    {
	  rewind(fp1);
	  strcpy(rec.name,name);
	  strcpy(rec.password,password);
	  rec.bal=0;
	 if((fwrite(&rec,sizeof(rec),1,fp)>0)&&(fwrite(&rec,sizeof(rec),1,fp1)>0))
	 {
	  gotoxy(26,14);
	  printf("         Record Save       ");
	  gotoxy(26,15);
	  printf("Press any key to continue...");
	  getch();
	  }
    }
}

void login()
{
//	clrscr();
clearWindow();
	layout();
	char name[30];
	char password[10];
	gotoxy(24,11);
	printf("Enter your name: ");
	gotoxy(24,12);
	printf("Enter  password: ");
	gotoxy(42,11);
	gets(name);
	gotoxy(42,12);
	gets(password);
	strcpy(name1,name);
	strcpy(password1,password);
	gotoxy(28,14);
	printf("press Backspace for back");
	gotoxy(28,15);
	printf("press Enter for conform");
	char ch=getch();
	if(ch==' ')
	{
	     return;
	}
	int c=0;
	rewind(fp);
	while((fread(&rec,sizeof(rec),1,fp))>0)
	{
		if((strcmp(name,rec.name)==0)&&(strcmp(password,rec.password)==0))
		{
		    c++;
		    strcpy(rec1.name,rec.name);
		    strcpy(rec1.password,rec.password);
		    rec1.bal=rec.bal;
		}
	 }
	if(c==0)
	{       gotoxy(27,14);
		printf("     Account not found      ");
		gotoxy(27,15);
		printf("press any key to continue...");
		getch();
	}
	else
	{
       if((strcmp(name,rec1.name)==0)&&(strcmp(password,rec1.password)==0))
		{
		     option();
		}
	}
}

void alllist()
{
	//clrscr();
	clearWindow();
	int i=0;
	float tbal;
	rewind(fp1);
	printf("\tName\t\t\tBalance\n\n");
	while((fread(&rec1,sizeof(rec1),1,fp1))>0)
	{
		rewind(fp);
		while((fread(&rec,sizeof(rec),1,fp))>0)
		{
			if((strcmp(rec.name,rec1.name)==0)&&(strcmp(rec.password,rec1.password)==0))
			{
				strcpy(name1,rec.name);
				tbal=rec.bal;
			}
		}
		if(i==22)
		{
			getch();
			//clrscr();
			clearWindow();
		}
		if(i<22)
		{
			printf("\t%s\t\t\t%.2f\n",name1,tbal);
			i++;
		}
		else
		{
			printf("\tName\t\t\tBalance\n\n");
			printf("\t%s\t\t\t%.2f\n",name1,tbal);
			i=0;
		}
	}
	printf("\n \t\tEnding \n");
}

void option()
{
	while(1)
	{
		//clrscr();
		clearWindow();
		layout();
		gotoxy(32,10);
		printf("1. Withdraw ");
		gotoxy(32,11);
		printf("2. Deposit");
		gotoxy(32,12);
		printf("3. Check Balance");
		gotoxy(32,13);
		printf("4. Passbook");
		gotoxy(32,14);
		printf("5. Log out");
		gotoxy(32,16);
		printf("Enter your choice...");
		char c;
		c=getch();
		switch(c)
		{
		case'1':
		{
			Withdraw();
			break;
		}
		case'2':
		{
			Deposit();
			break;
		}
		case'3':
		{
			 balance();
			 break;
		}
		case'4':
		{
			passbook();
			break;
		}
		case'5':
		{
			fclose(fp);
			main();
		}
		}
	}
}

void Withdraw()
{
//	clrscr();
clearWindow();
	layout();
	int amt=0;
	gotoxy(30,12);
	printf("Enter amount:- ");
	scanf("%d",&amt);
	gotoxy(30,14);
	printf("press Tab key for comform");
	gotoxy(30,15);
	printf("press Backspace for Quit");
	while(1)
	{
	char c=getch();
	switch(c)
	{
		case'\t':
		{
		       if(rec1.bal<amt)
		       {
				gotoxy(30,14);
				printf("    Insufficient balance    ");
				gotoxy(30,15);
				printf("Press any key to continue...");
				getch();
				balance();
				return;
		       }
		       rec1.bal=rec1.bal-amt;
		       if((fwrite(&rec1,sizeof(rec1),1,fp))>0)
		       {
				gotoxy(30,14);
				printf("          Sucessful        ");
				gotoxy(30,15);
				printf("Press any key to continue...");
				getch();
				balance();
				return;
		       }
		       else
		       {
				gotoxy(30,14);
				printf("     Error Try again       ");
				gotoxy(30,15);
				printf("Press any key to continue...");
				getch();
				return;
		       }
		}
		case' ':
		{
			return;
		}
	}
	}
}

void Deposit()
{
	//clrscr();
	clearWindow();
	layout();
	int amt=0;
	gotoxy(30,12);
	printf("Enter amount:- ");
	scanf("%d",&amt);
	gotoxy(30,14);
	printf("press Tab key for comform");
	gotoxy(30,15);
	printf("press Backspace for Quit");
	while(1)
	{
	char c=getch();
	switch(c)
	{
		case'\t':
		{
			rec1.bal=rec1.bal+amt;
		       if((fwrite(&rec1,sizeof(rec1),1,fp))>0)
		       {
				gotoxy(30,14);
				printf("          Sucessful        ");
				gotoxy(30,15);
				printf("Press any key to continue...");
				getch();
				balance();
				return;
		       }
		       else
		       {
				gotoxy(30,14);
				printf("     Error Try again       ");
				gotoxy(30,15);
				printf("Press any key to continue...");
				getch();
				return;
		       }
		}
		case' ':
		{
			return;
		}
	}
	}
}

void balance()
{
     //clrscr();
     clearWindow();
     layout();
     gotoxy(30,11);
     printf("Welcome ");
     puts(rec1.name);
     gotoxy(30,13);
     printf("Balance:- Rs.%.2f",rec1.bal);
     gotoxy(27,16);
     printf("Press any key to continue...");
    getch();
}
  void passbook()
  {
  //clrscr();
  clearWindow();
  rewind(fp);
    printf("Name\t\t\tDebit\t\t\tCredit\t\tBalance\n");
    while((fread(&rec,sizeof(rec),1,fp))>0)
    {
	if((strcmp(rec.name,name1)==0)&&(strcmp(rec.password,password1)==0))
	{
		float deb=0,cre=0;
		static float tempb;
		if(tempb<rec.bal)
		{
			deb=rec.bal-tempb;
		}
		else
		{
			cre=tempb-rec.bal;
		}
		tempb=rec.bal;
		printf("\n%s\t\t\t%.2f\t\t\t%.2f\t\t%.2f",name1,cre,deb,rec.bal);
	}
    }
    getch();
   }


