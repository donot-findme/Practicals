#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class drawpattern
{
private:
float dx,dy,i,length;
float count;

public:
int x1,y1,x2,y2;
int xmid,ymid;
void getdata();
void ddaline(int x1,int y1, int x2, int y2);
int xc,yc,r;
void bdrawcircle(int xc, int yc, int r);
};

void drawpattern::getdata()
{
cout<<"Enter x1 ";
cin>>x1;
cout<<"Enter y1 ";
cin>>y1;
cout<<"Enter x2 ";
cin>>x2;
cout<<"Enter y2 ";
cin>>y2;
}

void drawpattern::ddaline(int x1,int y1, int x2, int y2)
{
float x,y;
dx=(x2-x1);
dy=(y2-y1);

if (abs(dx)>=abs(dy))
length=abs(dx);
else
length=abs(dy);

dx=dx/length;
dy=dy/length;

x=x1;
y=y1;
i=1;

while(i<=length)
{
x=x+dx;
y=y+dy;
putpixel(x,y,RED);
delay(10);
i++;
}
}

void drawpattern::bdrawcircle(int xc, int yc, int r)
{
int x,y,d;
x=0;
y=r;
putpixel(xc+x,yc-y,BLUE);
d=3-2*r;
do
{
putpixel(xc+x,yc+y,BLUE);
putpixel(xc-x,yc-y,YELLOW);
putpixel(xc+x,yc-y,RED);
putpixel(xc-x,yc+y,GREEN);
putpixel(xc+y,yc-x,WHITE);
putpixel(xc-y,yc+x,BLUE);
putpixel(xc+y,yc+x,RED);
putpixel(xc-y,yc-x,YELLOW);
delay(10);
if (d<0)
{
y=y;
d=d+4*x+6;
}
else
{
d=d+4*(x-y)+10;
y=y-1;
}
x=x+1;
}
while(x<=y);
}

int main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,NULL);

cleardevice();

drawpattern p;
p.getdata();
//p.ddaline(p.x1,p.y1,p.x2,p.y2);
p.ddaline(p.x1,p.y1,p.x2,p.y1);
p.ddaline(p.x2,p.y1,p.x2,p.y2);
p.ddaline(p.x2,p.y2,p.x1,p.y2);
p.ddaline(p.x1,p.y2,p.x1,p.y1);

p.xmid=abs(p.x1+p.x2)/2;
p.ymid=abs(p.y1+p.y2)/2;
p.ddaline(p.xmid,p.x1,p.y1,p.ymid);
p.ddaline(p.xmid,p.x2,p.y2,p.ymid);
p.ddaline(p.xmid,p.x1,p.y2,p.ymid);
p.ddaline(p.xmid,p.x2,p.y1,p.ymid);

float rad,cal,xc,yc;
xc=abs(p.x2-p.x1);
yc=abs(p.y2-p.y1);
cal=pow(xc,2)+pow(yc,2);
cal=2*sqrt(cal);
rad=(xc*yc)/cal;

cout<<xc<<" "<<yc;
cout<<" "<<rad;
p.bdrawcircle(p.xmid,p.ymid,rad);

getch();
closegraph();
return 0;
}



