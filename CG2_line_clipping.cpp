#include<iostream>
#include<graphics.h>

using namespace std;

static int LEFT=1,RIGHT=2,BOTTOM=4,Above=8,xl,yl,xh,yh;

int getcode(int x,int y)
{
 int code = 0;												
	if(y > yh) code |=Above;
	if(y < yl) code |=BOTTOM;
	if(x < xl) code |=LEFT;
	if(x > xh) code |=RIGHT;
 return code;
}

int main()
{
 int gd= DETECT,gm;
 int x1,y1,x2,y2;

 initgraph(&gd,&gm,NULL);
 setcolor(GREEN);

 cout<<"\n\n\t\t Enter co-ordinates of window/Rectangle: \n\n\n";
 cin>>xl>>yl>>xh>>yh;

 rectangle(xl,yl,xh,yh);


 cout<<"\n\t\t Enter the endpoints of the line: \n\n";
 cin>>x1>>y1>>x2>>y2;
 
 line(x1,y1,x2,y2);

 int outcode1=getcode(x1,y1), outcode2=getcode(x2,y2);

 int accept = 0; 											
 while(1)
 {
	float m =(float)(y2-y1)/(x2-x1);						
	if(outcode1==0 && outcode2==0)
	{
		accept = 1;
		break;
	}														
	else if((outcode1 & outcode2)!=0)	
	{
		break;
	}
	else
	{
		int x,y;
		int temp;
		if(outcode1==0)					
			temp = outcode2;
		else
			temp = outcode1;

		if(temp & Above)										
		{
			x = x1+ (yh-y1)/m;
			y = yh;
		}
		else if(temp & BOTTOM)								
		{
			x = x1+ (yl-y1)/m;
			y = yl;
		}
		else if(temp & LEFT) 								
		{
			x = xl;
			y = y1+ m*(xl-x1);
		}
		else if(temp & RIGHT)								
		{
			x = xh;
			y = y1+ m*(xh-x1);
		}

		if(temp == outcode1)								
		{
			x1 = x;
			y1 = y;
			outcode1 = getcode(x1,y1);
		}
		else
		{
			x2 = x;
			y2 = y;
			outcode2 = getcode(x2,y2);
		}
	}
 }

setcolor(WHITE);


delay(2000);
if(accept)
{
  rectangle(xl,yl,xh,yh);
  line(x1,y1,x2,y2);
  cout<<"After clipping:";
 }
 else
 {
   rectangle(xl,yl,xh,yh); 
   cout<<"Line Reject";
  }
getch();
return 0;
closegraph();
}
