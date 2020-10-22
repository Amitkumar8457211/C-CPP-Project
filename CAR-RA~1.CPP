#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<time.h>
#include<iostream.h>

void car(int);
void carformed();
void carformed1();
void intro();
void footpath();
void score();
void end();
void mainmenu();
void game();
 int cx1,cy1,cx2,cy2,cx,cy;
static float hs=0;
float sc=0;
void main()
{
clrscr();
intro();
again:
mainmenu();
char c=getch();
switch(c)
{
 case'1':
 {
  sc=0;
  game();
  goto again;
 }
 case'2':
 {
 clrscr();
textcolor(2);
gotoxy(20,5);
cprintf("###This game is created by Amit Kumar###");
gotoxy(20,6);
cprintf("########################################");
gotoxy(30,8);
textcolor(9);
cprintf("High Score:-");
gotoxy(43,8);
printf("%.0f",hs);
textcolor(10);
gotoxy(24,10);
cprintf("Press any key for go home screen");
getch();
goto again;
 }
 case'3':
 {
  break;
 }
 default:
 {
  goto again;
 }
}
}

 void game()
 {
footpath();
while(1)
{
while(!kbhit())
{
sound(20*sc);
footpath();
car(0);
carformed();
footpath();
carformed1();
footpath();
if(cx==cx1&&cy==cy1||cx==cx2&&cy==cy2)
{
 nosound();
 delay(2000);
 end();
 return;
}
 sc=sc+0.1;
 if(sc>hs)
 {
  hs=sc;
 }
  }
char ab=getch();
if(ab=='4')
{
 car(4);
}
 if(ab=='6')
 {
  car(6);
 }
 if(ab=='p')
 {
 gotoxy(55,23);
  system("pause");
 }
 if(ab=='x')
 {
 nosound();
 end();
return;
}
}
}
void car(int c)
{
static int i=0;
switch(c)
{
 case 6:{ i=i+7; if(i>14) { i=14; } break;}
 case 4:{ i=i-7; if(i<0 ) { i=0;  } break;}
 }
clrscr();
textcolor(6);
textbackground(6);
gotoxy(18+i,21);
cprintf("####");
textcolor(1);
textbackground(1);
gotoxy(17+i,22);
cprintf("######");
gotoxy(17+i,23);
cprintf("######");
gotoxy(17+i,24);
cprintf("######");
cx=18+i;
cy=21;
}
void carformed()
{
static int a=17;
int p=a;
static int j=0;
{
textcolor(3);
textbackground(3);
gotoxy(p,1+j);
cprintf("######");
gotoxy(p,2+j);
cprintf("######");
gotoxy(p,3+j);
cprintf("######");
textcolor(4);
textbackground(4);
gotoxy(p+1,4+j);
cprintf("####");
textbackground(0);
gotoxy(26,4);
delay(1);
cx1=p+1;
cy1=4+j;
j++;
if(j==20)
 {
 j=0;
int r=random(9999);
     if(r<=2000) { a=24; }
else if(r<=4000) { a=31; }
else if(r<=6000) { a=17; }
else if(r<=8000) { a=24; }
else             { a=31; }

  }
}
}

void carformed1()
{
static int a=31;
int p=a;
static int j=0;
{
textcolor(6);
textbackground(6);
gotoxy(p,1+j);
cprintf("######");
gotoxy(p,2+j);
cprintf("######");
gotoxy(p,3+j);
cprintf("######");
textcolor(5);
textbackground(5);
gotoxy(p+1,4+j);
cprintf("####");
textbackground(0);
gotoxy(26,4);
delay(50);
cx2=p+1;
cy2=4+j;
j++;
if(j==22)
 {
 j=0;
int r=random(9999);
     if(r<=2000) { a=17; }
else if(r<=4000) { a=24; }
else if(r<=6000) { a=31; }
else if(r<=8000) { a=17; }
else             { a=24; }
  }
}
}
void intro()
{
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
for(int i=1;i<=8;++i)
{
setcolor(i+1);
settextstyle(1,0,i);
outtextxy(50,150,"CAR RACE");
delay(100);
setcolor(0);
settextstyle(1,0,i-1);
outtextxy(50,150,"CAR RACE");
if(i<6)
{
setcolor(i+6);
settextstyle(1,0,i);
outtextxy(200,320,"DESIGNED BY: Amit");
delay(100);
setcolor(0);
settextstyle(1,0,i-1);
outtextxy(200,320,"DESIGNED BY: Amit");
}
}
delay(2000);
closegraph();
}
void mainmenu()
{
clrscr();
textcolor(2);
gotoxy(20,5);
cprintf("###This game is created by Amit Kumar###");
gotoxy(20,6);
cprintf("########################################");
textcolor(YELLOW);
gotoxy(25,9);
cprintf("*** WELCOME LET START GAME ***");
gotoxy(25,10);
cprintf("------------------------------");
textcolor(11);
gotoxy(25,12);
cprintf("1. Start game");
gotoxy(25,13);
cprintf("2. High score ");
gotoxy(25,14);
cprintf("3. Exit");
gotoxy(25,16);
}
void end()
{
clrscr();
endscreen:
textcolor(2);
gotoxy(20,5);
cprintf("###This game is created by Amit Kumar###");
gotoxy(20,6);
cprintf("########################################");
gotoxy(30,8);
textcolor(9);
cprintf("Your score:-");
gotoxy(43,8);
printf("%.0f",sc);
textcolor(10);
gotoxy(24,10);
cprintf("Press key H for go home screen");
char en=getch();
if(en=='h'|| en=='H')
{
mainmenu();
}
else
{
goto endscreen;
}
}
void footpath()
{
	 score();
 for(int y=1;y<25;y++)
 {
  textcolor(2);
  textbackground(2);
  gotoxy(1,y);
  cprintf("###############");
  gotoxy(23,y);
  printf("l");
  gotoxy(30,y);
  printf("l");
  gotoxy(38,y);
  cprintf("###############");
  gotoxy(60,1);
  textbackground(0);
 }
}
void score()
{
  textcolor(14);
  textbackground(14);
  for(int z=1;z<25;z++)
  {
   gotoxy(77,z);
   cprintf("####");
   gotoxy(55,z);
   cprintf("####");
  }
  gotoxy(59,1);
  cprintf("##################");
     gotoxy(59,7);
  cprintf("##################");
     gotoxy(59,13);
  cprintf("##################");
    gotoxy(59,19);
  cprintf("##################");
     gotoxy(59,24);
  cprintf("##################");
   textbackground(0);
  gotoxy(63,3);
  textcolor(5);
  cprintf("CAR_RACING");
  gotoxy(63,5);
  textcolor(13);
  cprintf("AMIT KUMAR");
   gotoxy(59,9);
  textcolor(2);
  cprintf("YOUR SCORE:-");
  printf("%.0f",sc);
    gotoxy(59,11);
  textcolor(10);
  cprintf("HIGH SCORE:-");
  printf("%.0f",hs);
   gotoxy(59,15);
  textcolor(7);
  cprintf("Press'P'for pause");
    gotoxy(59,17);
  textcolor(8);
  cprintf("Press'X'for exit");
  gotoxy(63,21);
  textcolor(14);
  cprintf("Thanks you");
  gotoxy(59,23);
  }









