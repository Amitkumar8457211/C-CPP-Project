#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>
void main()
{
scr1:
clrscr();
textcolor(2);
delay(500);
gotoxy(20,5);
cprintf("###This game is created by Amit Kumar###");
gotoxy(20,6);
cprintf("########################################");
textcolor(YELLOW);
delay(500);
gotoxy(25,9);
cprintf("*** WELCOME LET START GAME ***");
delay(500);
gotoxy(25,10);
cprintf("------------------------------");
textcolor(11);
delay(500);
gotoxy(25,12);
cprintf("1. Start game");
delay(500);
gotoxy(25,13);
cprintf("2. High score ");
delay(500);
gotoxy(25,14);
cprintf("3. select Level");
delay(500);
gotoxy(25,15);
cprintf("4. Exit");
gotoxy(25,16);
int sc=0;
static int hs1=0,hs2=0,hs3=0,level=1;
char ch,ch2,l;
char chh1,chh2,chh3,c1,c2,c3;
ch=getch();
clrscr();
switch(ch)
{
case '1':
{
textcolor(2);
gotoxy(20,5);
cprintf("###This game is created by Amit Kumar###");
gotoxy(20,6);
cprintf("########################################");
textcolor(6);
gotoxy(28,9);
cprintf("Press Plus(+) for play & pause");
gotoxy(20,15);
cprintf("Status:-");
gotoxy(48,15);
cprintf("Score:- ");
gotoxy(32,17);
cprintf("Press Minus(-) for exit");
time_t f,s;
double di;
if(level==1)
{
do
{
chh1=random(26)+97;
gotoxy(40,12);
printf("%c",chh1);
gotoxy(40,13);
conti11:
f=time(NULL);
c1=getche();
s=time(NULL);
di=s-f;
if(di>2)
{
goto dey11;
}
if(c1=='-')
{
goto scr1;
}
sc++;
if(c1=='+')
{
gotoxy(30,15);
printf("pausing");
gotoxy(28,14);
system("pause");
goto conti11;
}
else
{
gotoxy(30,15);
printf("playing");
}
gotoxy(56,15);
printf("%d",sc);
}
while(c1==chh1);
dey11:
if(hs1<sc)
{
hs1=sc;
}
}
if(level==2)
{
do
{
chh1=random(26)+97;
chh2=random(26)+97;
gotoxy(40,12);
printf("%c%c",chh1,chh2);
gotoxy(40,13);
conti21:
f=time(NULL);
c1=getche();
if(c1=='+')
{
gotoxy(30,15);
printf("pausing");
gotoxy(28,14);
system("pause");
goto conti21;
}
else
{
gotoxy(30,15);
printf("playing");
}
if(c1=='-')
{
 goto scr1;
}
conti22:
gotoxy(41,13);
c2=getche();
s=time(NULL);
di=s-f;
if(di>3)
{
goto dey21;
}
if(c1=='+')
{
gotoxy(30,15);
printf("pausing");
gotoxy(28,14);
system("pause");
goto conti22;
}
else
{
gotoxy(30,15);
printf("playing");
}
if(c2=='-')
{
 goto scr1;
}
sc++;
gotoxy(56,15);
printf("%d",sc);
}
while(c1==chh1&&c2==chh2);
dey21:
if(hs2<sc)
{
hs2=sc;
}
}
if(level==3)
{
do
{
chh1=random(26)+97;
chh2=random(26)+97;
chh3=random(26)+97;
gotoxy(40,12);
printf("%c%c%c",chh1,chh2,chh3);
gotoxy(40,13);
conti31:
f=time(NULL);
c1=getche();
if(c1=='+')
{
gotoxy(30,15);
printf("pausing");
gotoxy(28,14);
system("pause");
goto conti31;
}
else
{
gotoxy(30,15);
printf("playing");
}
if(c1=='-')
{
goto scr1;
}
conti32:
gotoxy(41,13);
c2=getche();
if(c1=='+')
{
gotoxy(30,15);
printf("pausing");
gotoxy(28,14);
system("pause");
goto conti32;
}
else
{
gotoxy(30,15);
printf("playing");
}
if(c2=='-')
{
goto scr1;
}
conti33:
gotoxy(42,13);
c3=getche();
s=time(NULL);
di=s-f;
if(di<4)
{
 goto dey31;
}
if(c1=='+')
{
gotoxy(30,15);
printf("pausing");
gotoxy(28,14);
system("pause");
goto conti33;
}
else
{
gotoxy(30,15);
printf("playing");
}
if(c3=='-')
{
 goto scr1;
}
sc++;
gotoxy(56,15);
printf("%d",sc);
}
while(c1==chh1&&c2==chh2&&c3==chh3);
dey31:
if(hs3<sc)
{
hs3=sc;
}
}
delay(2000);
clrscr();
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
goto scr1;
break;
}
case '2':
{
delay(500);
gotoxy(20,5);
cprintf("###This game is created by Amit Kumar###");
gotoxy(20,6);
cprintf("########################################");
gotoxy(25,12);
delay(500);
printf("High-score in Very Easy=%d",hs1);
gotoxy(25,13);
delay(500);
printf("High-score in Easy=%d",hs2);
gotoxy(25,14);
delay(500);
printf("High-score in Hard=%d",hs3);
textcolor(2);
gotoxy(25,16);
delay(500);
cprintf("Press any key for back");
ch2=getch();
goto  scr1;
break;
}
case '3':
{
scr2:
textcolor(2);
delay(500);
gotoxy(20,5);
cprintf("###This game is created by Amit Kumar###");
gotoxy(20,6);
cprintf("########################################");
gotoxy(28,12);
textcolor(13);
delay(500);
cprintf("##Select level##");
delay(500);
gotoxy(28,13);
cprintf("----------------");
textcolor(3);
delay(500);
gotoxy(28,15);
cprintf("1. Very Easy");
delay(500);
gotoxy(28,16);
cprintf("2. Easy");
delay(500);
gotoxy(28,17);
cprintf("3. Hard");
delay(500);
gotoxy(28,18);
cprintf("4. back");
l=getch();
if(l=='1')
{
level=1;
goto scr1;
}
else if(l=='2')
{
level=2;
goto scr1;
}
else if(l=='3')
{
level=3;
goto scr1;
}
else if(l=='4')
{
goto scr1;
}
else
{
 goto scr2;
}

break;
}
case '4':
{
return;
 break;
}
default:
{
goto scr1;
 break;
}
}
getch();
}