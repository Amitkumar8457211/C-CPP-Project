#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
void mainscreen();
void man(int);
void board(int,int);
void fire();
void game();
void show();
void mainmenu();
void end();
void intro();
void score();
 int b=60,h=300,m=0,mx=0,my=0;
char chh;
 int sc,a,y;
static int hs=0;
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
 a=10;
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
printf("%d",hs);
textcolor(10);
gotoxy(24,10);
cprintf("Press any key for go home screen");
getch();
goto again;
 }
case'3':
{
 exit(0);
}
default:
{
 goto again;
}
}
}
void game()
{

int gd=DETECT,gm;
initgraph(&gd,&gm,"C://TC//BGI");

while(a!=0)
{
cleardevice();
while(!kbhit())
{
mainscreen();
show();
board(mx,my);
man(h);
}
chh=getch();
if(chh=='8')
{
man(--h);
cleardevice();
}
if(chh=='2')
{
man(++h);
cleardevice();
}
if(chh=='x'||chh=='X')
{
 exit(0);
}
if(chh=='F'||chh=='f')
{
 fire();
   a--;
   delay(2000);
   score();
   mx=random(250);
   my=random(230);
}
}
closegraph();
end();

}
void board(int  j,int i=0)
{
   m=i;
  setcolor(5);
circle(550-j,350-i,36);
setfillstyle(1,5);
floodfill(584-j,350-i,5);
  setcolor(14);
circle(550-j,350-i,26);
setfillstyle(1,14);
floodfill(574-j,350-i,14);
  setcolor(2);
circle(550-j,350-i,16);
setfillstyle(1,2);
floodfill(564-j,350-i,2);
    setcolor(1);
circle(550-j,350-i,8);
setfillstyle(1,1);
floodfill(556-j,350-i,1);
  setcolor(4);
circle(550-j,350-i,2);
setfillstyle(1,4);
floodfill(551-j,350-i,4);
putpixel(550-j,350-i,0);
}
  void man(int h)
  {
 setcolor(11);
circle(60,280,10);
setfillstyle(1,11);
floodfill(61,282,11);
setcolor(0);
circle(66,276,2);
setfillstyle(1,0);
floodfill(67,277,0);
setcolor(6);
ellipse(60,316,0,360,15,25);
setfillstyle(1,6);
fillellipse(60,316,15,25);
setcolor(15);
line(60,290,60,340);
line(53,338,53,380);
line(68,338,68,380);
 line(60,300,100,h);
}
void fire()
{
int p=100;
y=h;
while(p!=550-mx&&y!=80&&y!=390)
{
    setcolor(p);
  line(60,300,p,y);
 p=p++;
y=((p*h)-(300*p)-(60*h)+30000)/40;
delay(3);
}
}
void mainscreen()
{
setbkcolor(0);
setcolor(14);
rectangle(0,0,639,479);
rectangle(10,10,629,469);
rectangle(10,400,629,410);
setfillstyle(1,14);
floodfill(2,2,14);
floodfill(12,402,14);
setcolor(6);
settextstyle(1,0,5);
outtextxy(240,10,"WELCOME");
settextstyle(3,0,4);
outtextxy(240,50,"^^^^^^^^^^^");
 setcolor(2);
settextstyle(0,0,1);
outtextxy(180,420,"This game is create by Amit kumar");
outtextxy(30,440,"YOUR-SCORE:-");
outtextxy(450,440,"HIGH-SCORE:-");
outtextxy(250,455,"Press x for exit");
outtextxy(30,40,"#*LASER GUN GAME*#");
outtextxy(450,40,"ARROW REMAINING:-");
setcolor(11);
rectangle(10,70,629,400);
rectangle(20,80,619,390);
setfillstyle(8,11);
floodfill(15,72,11);
}

void score()
{
if(y>=(350-m)-2&&y<=(350-m)+2)
{
sc=sc+10;
}
else if(y>=(350-m)-8&&y<=(350-m)+8)
{
sc=sc+9;
}
else if(y>=(350-m)-16&&y<=(350-m)+16)
{
sc=sc+8;
}
else if(y>=(350-m)-26&&y<=(350-m)+26)
{
sc=sc+7;
}
else if(y>=(350-m)-36&&y<=(350-m)+36)
{
sc=sc+6;
}
else
{
sc=sc+0;
}

 if(sc>hs)
 {
  hs=sc;
 }
 }
 void show()
 {
 setcolor(15);
char arr[3];
 sprintf(arr,"%d",sc);
 outtextxy(140,440,arr);
 char arrr[3];
 sprintf(arrr,"%d",hs);
 outtextxy(570,440,arrr);
 char arrrr[3];
 sprintf(arrrr,"%d",a);
 outtextxy(590,40,arrrr);
 }

void intro()
{
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
for(int i=1;i<=8;++i)
{
setcolor(i+1);
settextstyle(1,0,i);
outtextxy(50,150,"LASER GUN");
delay(100);
setcolor(0);
settextstyle(1,0,i-1);
outtextxy(50,150,"LASER GUN");
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
delay(3000);
closegraph();
}
void mainmenu()
{
clrscr();
textcolor(2);
delay(500);
gotoxy(20,5);
cprintf("###This game is created by Amit Kumar###");
gotoxy(20,6);
cprintf("########################################");
textcolor(YELLOW);
delay(300);
gotoxy(25,9);
cprintf("*** WELCOME LET START GAME ***");
delay(300);
gotoxy(25,10);
cprintf("------------------------------");
textcolor(11);
delay(300);
gotoxy(25,12);
cprintf("1. Start game");
delay(300);
gotoxy(25,13);
cprintf("2. High score ");
delay(300);
delay(300);
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
printf("%d",sc);
textcolor(10);
gotoxy(24,10);
cprintf("Press any key for go home screen");
getch();
}
