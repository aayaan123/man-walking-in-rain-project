#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<conio.h>
#define ScreenWidth getmaxx()
#define ScreenHeight getmaxy()
#define GroundY ScreenHeight*0.75

int ldisp=5;

void DrawManAndUmbrella(int x,int ldisp)
{
//head
circle(x,GroundY-90,10);
circle(x+6,GroundY-92,1.5);
line(x,GroundY-80,x,GroundY-30);
//hand
line(x,GroundY-70,x+10,GroundY-60);
line(x,GroundY-65,x+10,GroundY-55);
line(x+10,GroundY-60,x+30,GroundY-70);
line(x+10,GroundY-55,x+30,GroundY-70);
//legs
line(x,GroundY-30,x+ldisp,GroundY);
line(x,GroundY-30,x-ldisp,GroundY);
//umbrella
pieslice(x+30-ldisp,GroundY-120,ldisp,180+ldisp,40);
line(x+30-ldisp,GroundY-120,x+30,GroundY-70);
}
		 void Rain2(int x)
{
int i,rx,ry;
for(i=0;i<500;i++)
{
 rx=rand() % ScreenWidth;
 ry=rand() % ScreenHeight;
  if(ry>GroundY && ry<GroundY+20)
  line(rx,ry,rx+4,ry+0.5);
}
}
void Rain1(int x)
{
int i,rx,ry;
for(i=0;i<400;i++)
{
 rx=rand() % ScreenWidth;
 ry=rand() % ScreenHeight;
 if(ry<GroundY)
 {
  if(ry<GroundY-165 || (ry>GroundY-165 && (rx<x-30 || rx>x+60)))
  line(rx,ry,rx+0.2,ry+4);
 }
}
}
int main()
{
  int gd=DETECT,gm,x=0;
  initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
  while(!kbhit())
  {
   rectangle(-1,GroundY,ScreenWidth+1,GroundY+20);
   Rain1(x);
   Rain2(x);
   ldisp=(ldisp+2)%30;
   DrawManAndUmbrella(x,ldisp);
   delay(10);
   cleardevice();
   x=(x+2)%ScreenWidth;
}
  getch();
  closegraph();
  return 0;
}
