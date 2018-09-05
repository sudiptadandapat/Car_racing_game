#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

void player();
void start();
void controls();
void pause()
{
sound(1200);
delay(80);
nosound();
sound(60);
nosound();
getch();
sound(60);
}


///////record the data////////////////////
void Drecord()
{
////array for stroring user names
char fname[50];
int score, numRecords = 0, repeat = 1;
////coordinates of high score page///
int  x_co = 10, y_co = 10, y_co1 = 10, i, j;
////defining pointer fptr for read/write data for record.txt//////
FILE *fptr;
char *name;
////if the text file is empty///
if ((fptr = fopen("record.txt","r")) == NULL) {
	printf("Error: Loading the file\n");
	exit(1);
}


////designing the page
setbkcolor(GREEN);
settextstyle(10,0,3);
outtextxy(70,50,"HIGH SCORES ACHIEVERS");
setcolor(5);
line(51,100,520,100);
setcolor(7);
rectangle(50,110,600,120);
setfillstyle(5,7);
floodfill(51,111,7);
setlinestyle(0,1,3);
setcolor(RED);
line(51,180,200,180);
line(51,230,200,230);
line(51,280,200,280);
line(51,330,200,330);
line(52,380,200,380);

line(380,180,599,180);
line(380,230,599,230);
line(380,280,599,280);
line(380,330,599,330);
line(380,380,599,380);
setlinestyle(0,1,1);
//////reading all user names and scores
while(1) {
	if(fscanf(fptr,"%s %d",&fname, &score) == EOF)
		break;
	numRecords++;
}

if(numRecords == 0) {
setcolor(BLACK);
settextstyle(3,0,4);
outtextxy(100,200,"Sorry,No records Available!!!");
}
rewind(fptr);
//////printing all values///
while ((repeat <= numRecords) && (repeat <= 10)) {
if(repeat <= 5) {
	fscanf(fptr, "%s %d", &fname, &score);
	gotoxy(x_co, y_co);
	printf("Name:\t  %s\n",fname);
	y_co++;
	gotoxy(x_co, y_co);
	printf("Score:  %d\n\n",score);
	y_co += 2;
	repeat++;
	}
else if(repeat > 5 && repeat <= 10) {
x_co = 305;
	fscanf(fptr, "%s %d", &fname, &score);
	gotoxy(x_co, y_co1);
	printf("Name:    %s\n",fname);
	y_co1++;
	gotoxy(x_co, y_co1);
	printf("Score:  %d\n\n",score);
	y_co1 += 2;
	repeat++;
	}

}
getch();
}


//////for getting user name and score after game over////
void record(int displayscore)
{
int loop;
char name[50], ch;
FILE *fptr;
if ((fptr = fopen("record.txt","a+")) == NULL) {
	printf("Error: Opening the file\n");
	exit(1);
}
setcolor(WHITE);


cleardevice();
setcolor(11);
rectangle(50,50,600,400);
setfillstyle(SOLID_FILL,GREEN);
rectangle(40,40,610,410);
floodfill(45,45,11);
setfillstyle(SOLID_FILL,15);
floodfill(55,55,11);
setcolor(5);
settextstyle(3,0,1);
outtextxy(220,160,"Enter Name:");
setcolor(11);
rectangle(220,188,395,213);
rectangle(215,183,400,218);
setfillstyle(SOLID_FILL,GREEN);
floodfill(216,184,11);
setfillstyle(SOLID_FILL,BLACK);
floodfill(225,190,11);
gotoxy(29,13);

//////storing the user name///
gets(name);
name[0] = toupper(name[0]);
for(loop = 0; loop < strlen(name); loop++) {
	if((name[loop]) == ' ')
		break;
}
name[loop + 1] = toupper(name[loop + 1]);
if(strlen(name) > 0) {
////printing the name and score///
fputs(name,fptr);
fputs("\n",fptr);
fprintf(fptr, "%d", displayscore);
fputs("\n",fptr);
}
fclose(fptr);

cleardevice();
setcolor(11);
rectangle(50,50,600,400);
setfillstyle(SOLID_FILL,GREEN);
rectangle(40,40,610,410);
floodfill(45,45,11);
setfillstyle(SOLID_FILL,15);
floodfill(55,55,11);
setcolor(11);
rectangle(215,200,400,230);
setfillstyle(SOLID_FILL,BLACK);
floodfill(225,215,11);
gotoxy(29,14);
printf("RECORD SAVED!!!");
delay(1000);
}





void quit()
{
setbkcolor(15);
setcolor(RED);
settextstyle(1,0,4);
outtextxy(150,210,"QUITING THE GAME .....");
delay(1000);
}



void first()
{
 int gdriver = DETECT,gmode,i;
 initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");

 setbkcolor(0);
 setcolor(BLUE);
 floodfill(100,100,3);
 settextstyle(1,0,4);
 outtextxy(5,100,"Intra college Innovation Challenge 2018...");
 delay(500);
 for(i=1;i<=5;++i)
 {
 setcolor(0);
 settextstyle(1,0,i);
 outtextxy(150,200,"Car Racing Game");
 delay(100);
 setcolor(15);
 settextstyle(1,0,i-1);
 outtextxy(150,200,"Car Racing Game");
 }

setcolor(RED);
for(i=0;i<=90;++i)
{

setfillstyle(2,RED);
settextstyle(2,0,5);

circle(500+i,460,3);

outtextxy(500,439,"Loading...");
floodfill(500+i,463,RED);

delay(20);

}


setcolor(RED);
settextstyle(8,0,1);
outtextxy(180,350,"press any key to continue...");
delay(300);
setcolor(WHITE);



getch();
cleardevice();
setbkcolor(15);
setcolor(RED);
settextstyle(2,0,6);
outtextxy(210,109,"......WELCOME......");
outtextxy(210,129,"This game is designed by......");
outtextxy(210,149,"CODING_COMANDOS");
outtextxy(370,149,"( 1.Purbayan Kar");
outtextxy(370,169,"  2.Arindam Chattopadhyay");
outtextxy(370,189,"  3.Ayan Chowdhury");
outtextxy(370,209,"  4.Abhishek Jha");
outtextxy(370,229,"  5.Saptarshi Dash");
outtextxy(370,249,"  6.Sneha Kumari )");
outtextxy(210,279,"CSE FIRST YEAR");
settextstyle(4,0,3);
outtextxy(190,320,"Press any key to Continue");
delay(500);
getch();
cleardevice();



player();
getch();
closegraph();

}

/////////////////////////////// For the menu page////////////////////////
void player()
{

int ch=0,i=0,x=250,y=168,m,n,u;

///////Setting the background, text color and style/////
setbkcolor(YELLOW);
setcolor(RED);
settextstyle(8,0,3);

////////////list of menu/////
outtextxy(270,150,"start");
outtextxy(270,200,"high scores");
outtextxy(270,250,"controls");
outtextxy(270,300,"quit");

//////bullets in the list of menu/////
circle(x,y,4);
circle(x,y+50,4);
circle(x,y+100,4);
circle(x,y+150,4);


while(1)
{

//////conditions for each options////
 if(ch==13 && y==168)
 {
////// calling start fn/////
 cleardevice();
 start();
 break;

 }

if(ch==13 && y==218)
 {
////// calling credits fn/////
 cleardevice();
 Drecord();
 cleardevice();
 player();
 break;

 }

 if(ch==13 && y==318)
 {
////// calling exit fn/////
 cleardevice();
 quit();
 exit(0);

 }

 if(ch==13 && y==268)
 {
////// calling controls fn/////
 controls();
 break;

 }

 if(y>=168 && y<=318)
 {

 if(i==0)
 {
 setfillstyle(1,12);
 floodfill(x,y,RED);

 i++;
 n=y;

 }


 }


 if(kbhit())
 {

 ch=getch();

 if(ch==72)
 {

      if(y>168)
      {
	 y=y-50;
      }

 }


 if(ch==80)
 {

      if(y<318)
      {
	 y=y+50;
      }

 }


 if(y>=168 && y<=318)
 {

    setfillstyle(1,12);
    floodfill(x,y,RED);

    if(y!=168 && y!=318)
    {

    setfillstyle(1,YELLOW);
    floodfill(x,n,RED);

    }

    n=y;

 }


 }

 if(ch==27)
 exit(0);

 }

 cleardevice();
 closegraph();

 }


 void start()
{


char name[25];
outtextxy(240,220,"player name");

gotoxy(55,16);
gets(name);
cleardevice();
setbkcolor(YELLOW);
setcolor(RED);
settextstyle(1,0,3);
outtextxy(240,150,".....WELCOME.....");
outtextxy(265,200,name);
delay(6000);
void main();

}


void controls()
{

setcolor(RED);
cleardevice();
settextstyle(1,0,4);
outtextxy(250,60,"controls");
settextstyle(2,0,6);
outtextxy(215,152,"1.");
rectangle(250,152,280,182);
rectangle(248,150,282,184);
rectangle(262,170,268,177);
line(265,160,260,170);
line(265,160,270,170);

outtextxy(290,152,"forward");
outtextxy(215,212,"2.");

rectangle(250,212,280,242);
rectangle(248,210,282,244);
rectangle(262,217,268,225);
line(260,228,270,228);
line(265,236,260,227);
line(265,236,270,227);


outtextxy(290,212,"backward");
outtextxy(215,272,"3.");

rectangle(250,272,280,302);
rectangle(248,270,282,304);
rectangle(267,283,276,290);
line(265,281,265,291);
line(266,281,256,286);
line(256,286,266,291);

outtextxy(290,272,"Left");
outtextxy(215,332,"4.");

rectangle(250,332,280,362);
rectangle(248,330,282,364);
rectangle(255,343,265,350);
line(267,341,267,351);
line(266,341,276,346);
line(276,346,266,351);

outtextxy(290,332,"RIGHT");

getch();
cleardevice();
player();

}

void enemycar(int x,int y)
{

setcolor(15);

rectangle(x+1,y,x+35,y+40);


rectangle(x+3,y+40,x+32,y+50);

rectangle(x+1,y+43,x+2,y+48);


rectangle(x+33,y+43,x+34,y+48);

}

void mycar(int x,int y)
{

setcolor(15);

rectangle(x+1,y+80,x+39,y+120);


rectangle(x+10,y+80,x+30,y+120);

rectangle(x+4,y+65,x+35,y+80);


rectangle(x+1,y+69,x+2,y+76);
rectangle(x+37,y+69,x+38,y+76);

}

void myclear(int x,int y)
{

setcolor(8);

rectangle(x+1,y+80,x+39,y+120);


rectangle(x+10,y+80,x+30,y+120);

rectangle(x+4,y+65,x+35,y+80);


rectangle(x+1,y+69,x+2,y+76);
rectangle(x+37,y+69,x+38,y+76);

}

void enemyclear(int x,int y)
{

setcolor(8);

rectangle(x+1,y,x+35,y+40);


rectangle(x+3,y+40,x+32,y+50);

rectangle(x+1,y+43,x+2,y+48);


rectangle(x+33,y+43,x+34,y+48);

}

void road()
{
char a[3];

for(int i=3;i>=1;i--)
{

 setfillstyle(1,8);
 bar3d(220,-1,410,getmaxy()+1,0,0);
 sprintf(a,"%d",i);
 outtextxy(300,200,a);
 delay(500);

 }

 if(a==0)
 setfillstyle(1,8);
 bar3d(220,-1,410,getmaxy()+1,0,0);
settextstyle(1,0,5);
outtextxy(300,200,"Go");
delay(500);
setfillstyle(1,8);
bar3d(220,-1,410,getmaxy()+1,0,0);


 }


 void main()
 {

 first();

 int gdriver = DETECT,gmode;
 initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");

 int x=300,y=350,ch,life=3,score=0;
 char choice;


 setbkcolor(15);
 setcolor(RED);
 settextstyle(1,0,5);
 outtextxy(150,120,"let the race begin");

 delay(2000);

 for(int m=1;m<25;m++)
  for(int n=1;n<80;n++)
   {

     gotoxy(n,m);
     cout<<" ";
     }
     setbkcolor(CYAN);

  setcolor(15);
  gotoxy(5,21);
  cout<<"coding_comandos";
  gotoxy(5,18);
  cout<<"press <p> to pause";


  road();
  sound(60);
  setcolor(RED);
  gotoxy(5,15);
  cout<<"press <esc> to exit";
  for(int level=1;(level<=3) && (life>0); level++)
  {

   if(level==1)
   {
    gotoxy(5,5);
    cout<<"race start now";
    gotoxy(5,7);
    cout<<"all the best";
    delay(1500);
    gotoxy(5,5);
    cout<<"              ";
    gotoxy(5,7);
    cout<<"            ";

  }

  else{

  gotoxy(5,9);
  cout<<"next level";
  delay(1000);
  gotoxy(5,9);
  cout<<"             ";
  setbkcolor(GREEN);
  if(level==3)
  {
   setbkcolor(BROWN);
  }

 }

 for(int i=0;(i<15) && (life>0); i++)
 {
  if((level==3) && (i==14))
  {

   settextstyle(1,0,5);
   outtextxy(220,150,"you win");
   gotoxy(35,16);
   cout<<"continue <y/n>";
   nosound();
   choice = getch();
   if((choice=='y') ||(choice=='Y'))
   {
   record(score);
    main();
   }
   else if((choice=='n') ||(choice=='N'))
   {
    record(score);
   cleardevice();
   quit();
   exit(0);
   }
  }

  setcolor(RED);
  gotoxy(55,10);
  cout<<"level ="<<level;
  gotoxy(55,18);
  cout<<"lives ="<<life;
  gotoxy(55,24);
  cout<<"score ="<<score;


  int accident=0;
  int y1=1,x1=250+((rand()%3)*50);
   int y2=1,x2=250+((rand()%3)*50);
   score +=10;

   while(y1<getmaxy()+1)
   {

   enemyclear(x1,y1);
enemyclear(x2,y2);

    y1++;
    y2++;
    if(accident == 1)
      break;
   enemycar(x1,y1);
   enemycar(x2,y2);
    mycar(x,y);
    delay(3-level);
    if(kbhit())
    {
     mycar(x,y);
     ch=getch();
     switch(ch)

     {
       case 27:
       nosound();
       myclear(x,y);
       cleardevice();
       player();
     break;

      case 75:
      sound(1200);
      delay(40);
      nosound();
      sound(60);
      myclear(x,y);
      if(x>250)
       x=x-50;

       if((x==x1)||(x==x2))
       if((y+14==y1)||(y+14==y2))
       {
	accident=1;
	x=x+50;
	mycar(x,y);

	goto Next1;
       }

       mycar(x,y);

break;

 case 77:
 sound(1200);
 delay(40);
 nosound();
 sound(60);
 myclear(x,y);
      if(x<350)
	  x=x+50;

	    if((x==x1)||(x==x2))
       if((y+14==y1)||(y+14==y2))
       {
	accident=1;
	x=x-50;
	mycar(x,y);

	goto Next1;
       }

       mycar(x,y);
       break;
   case 112:
   pause();
   break;
   case 72:
   sound(1200);
   delay(40);
   nosound();
   myclear(x,y);

	   if(y>0)
	  y=y-5;

	    if((x==x1)||(x==x2))
		if((y+14==y1)||(y+14==y2))
       {
	accident=1;
	mycar(x,y);
	goto Next1;
       }

       mycar(x,y);
       break;

       case 80:myclear(x,y);
	   if(y<getmaxy()-150)
	      y=y+5;
      mycar(x,y);

break;

       }

       }
       if((x==x1)||(x==x2))
	if((y+14==y1)||(y+14==y2))
	  accident=1;

       Next1:
       if(accident==1)
       {
	life=life-1;
	if(life==0)
	{
	nosound();
	 settextstyle(1,0,5);
	 outtextxy(200,150,"game over");

	 gotoxy(35,16);
	 sleep(1);

	 cout<<"continue <y/n>";

	 choice=getch();
	 if(choice=='y')
	 {
	 nosound();
	 record(score);
	  main();
	 }
	 else
	 {
	 nosound();
	 record(score);
	  cleardevice();
	  quit();
	  exit(0);
	  }
	  }

	  gotoxy(5,5);
	  cout<<"life is getting low";
	  delay(500);
	  gotoxy(5,5);
	  cout<<"      ";
	  }

	  }

	  }

	  }
	  nosound();
	  getch();
	  nosound();

	  }
