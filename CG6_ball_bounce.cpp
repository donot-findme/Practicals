#include <iostream>
#include <math.h>
#include <graphics.h>

int main()
{
	int gd =DETECT,gm;
	int angle=0;
	int incx=3, dt=30;
	int bounce;
	double x,y, mult;
	initgraph(&gd,&gm,NULL);

	mult= getmaxx()/2-100;
	setcolor(YELLOW);
	circle(100+x,100+y,YELLOW);
	floodfill(100+x,100+y,YELLOW);
	//setfillstyle(SOLID_FILL, YELLOW);
	bounce=1;

for(x=0; x<getmaxx(); x=x+incx)
{
	if(incx==-1 || x<0)
	break;
	y=mult*sin(angle*3.141/180);
	y=getmaxy()/2-y;
    if(y>getmaxy()/2){
	angle=0;
	mult=0.8*mult;
	bounce++;

	if(bounce%3==0){
	incx=incx-1;
}

	dt=dt-4;

}

line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
pieslice(x,y,0,360,10);
delay(dt);
cleardevice();
angle+=5;
}
getch();

closegraph();

return 0;

}

