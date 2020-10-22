#include<stdio.h>
#include<conio.h>
#include<fstream.h>
#include<iostream.h>
#include<stdlib.h>
#include<string.h>
void fscreen();
void sign();
void open();
void wscreen();
void balance();
void credits();
void debits();
float bal=0;
char un[20],ps[10];

void main()
{
clrscr();
fscreen();
}
void fscreen()
{
clrscr();
 char c;
 textcolor(2);
 gotoxy(30,10);
 cprintf("\n1.Sign in");
 gotoxy(30,11);
 cprintf("\n2.Open Account");
 gotoxy(30,12);
 cprintf("\n3.Exit");
   textcolor(4);
 gotoxy(28,6);
 cprintf("\nSVIET SUPER 40 BANK");
 textbackground(4);
 gotoxy(28,7);
 cprintf("\n-------------------");
 textcolor(15);
 textbackground(0);
 gotoxy(30,14);
c=getch();
if(c=='1')
{
 sign();
}
if(c=='2')
{
  open();
}
if(c=='3')
{
exit(0);
}
else
{
 fscreen();
}
}
void sign()
{
char unc[20],psc[20];
 clrscr();
 gotoxy(20,7);
 textcolor(5);
 cprintf("Enter Username: ");
 gotoxy(20,8);
 cprintf("Enter password: ");
 textcolor(15);
 gotoxy(37,7);
 gets(unc);
 gotoxy(37,8);
 gets(psc);
 if((strcmp(un,unc)!=0)||(strcmp(ps,psc))!=0)
 {
 clrscr();
 gotoxy(32,7);
 printf("Account not found");
 getch();
  fscreen();
 }
 else
 {
   wscreen();
 }
}
void open()
{
clrscr();
   char ps1[10],ps2[10];
 textcolor(2);
 gotoxy(20,10);
 cprintf("\nEnter your name: ");
 gotoxy(20,11);
 cprintf("\nEnter your password: ");
 gotoxy(20,12);
 cprintf("\nRe-enter your password: ");
 gotoxy(28,15);
 textcolor(1);
 cprintf("Press"" enter"" for submit");
   textcolor(3);
 gotoxy(20,6);
 cprintf("\nSVIET Super 40 Bank Account open form");
 textbackground(3);
 gotoxy(20,7);
 cprintf("\n######################################");
 textbackground(0);
 textcolor(15);
 gotoxy(44,11);
 gets(un);
 gotoxy(44,12);
 gets(ps1);
 gotoxy(44,13);
 gets(ps2);
 if(strcmp(ps1,ps2)!=0)
 {
 clrscr();
 gotoxy(25,7);
 printf("your password not match");
 gotoxy(25,8);
 printf("Error try again");
 gotoxy(25,9);
 printf("Thanks you");
 getch();
 open();
}
else
{
 strcpy(ps,ps1);
 fscreen();
}
}
 void wscreen()
 {
 char o;
  clrscr();
   textcolor(1);
 gotoxy(30,10);
 cprintf("\n1.Debits");
 gotoxy(30,11);
 cprintf("\n2.Credits");
 gotoxy(30,12);
 cprintf("\n3.Check Balance");
 gotoxy(30,13);
 cprintf("\n4.Log out");
   textcolor(3);
 gotoxy(25,6);
 cprintf("\nWelcome in Super 40 Bank");
 textbackground(3);
 gotoxy(25,7);
 cprintf("\n########################");
 textcolor(15);
 textbackground(0);
 gotoxy(30,14);
 o=getch();
 if(o=='1')
 {
   debits();
 }
 if(o=='2')
 {
   credits();
 }
 if(o=='3')
 {
   balance();
 }
 if(o=='4')
 {
  strcpy(un,"username");
 strcpy(ps,"password");
  fscreen();
 }
 else
 {
  wscreen();
 }
 }
 void balance()
 {
 clrscr();
  gotoxy(20,7);
 textcolor(2);
 printf("Your current balance:  %.2f",bal);
 gotoxy(20,10);
 cprintf("Enter any key for go Back");
 textcolor(15);
getch();
}
 void credits()
 {
 int add=0;
 char ca;
 clrscr();
  gotoxy(20,7);
 textcolor(7);
 printf("Enter Amount: ");
 cin>>add;
 gotoxy(20,10);
 cprintf("Press B for go Back");
 gotoxy(20,11);
 cprintf("Press C for confirm");
 textcolor(15);
 gotoxy(35,7);
 gotoxy(20,12);
 ca=getch();
 if(ca=='b'||ca=='B')
 {
  wscreen();
 }
 if(ca=='c'||ca=='C')
 {
 bal=bal+add;
 balance();
 }
 else
 {
  credits();
 }
 }
  void debits()
 {
 int sub=0;
 char cs;
 clrscr();
  gotoxy(20,7);
 textcolor(7);
 printf("Enter Amount: ");
 cin>>sub;
 gotoxy(20,10);
 cprintf("Press B for go Back");
 gotoxy(20,11);
 cprintf("Press C for confirm");
 textcolor(15);
 gotoxy(35,7);
 gotoxy(20,12);
  if(bal<sub)
 {
 clrscr();
 gotoxy(20,8);
 printf("Amounts not sufficiants");
 gotoxy(20,9);
 printf("Enter any key for back");
 getch();
 debits();
 }
 cs=getch();
 if(cs=='b'||cs=='B')
 {
  wscreen();
 }
 if(cs=='c'||cs=='C')
 {
 bal=bal-sub;
 balance();
 }
 else
 {
  debits();
 }
 }
