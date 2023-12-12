#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
int main()
{
    int gd=DETECT,gm,s,i;
    initgraph(&gd,&gm,NULL);
    cout<<"1.Translation\n2.Rotation\n3.Scaling\n4.Reflection\n5.Shearing"<<endl;
   for(i=1;i<10;i++)
	{ 
		cout<<"Selection:";
   	 	cin>>s;

    	switch(s)
        {
	 case 1:
            {   int x1=30,y1=30,x2=70,y2=70;
                int tx=300,ty=0;
//                outtextxy(25,25,"Rectangle before translation");
                setcolor(3);
                rectangle(x1,y1,x2,y2);
                setcolor(4);
                cout<<"Rectangle after translation:";
//                outtextxy(x1+tx,y1,"Rectangle after translation");
                rectangle(x1+tx,y1+ty,x2+tx,y2+ty);
                getch();
				closegraph();
                break;
            }
        case 2:
            {  	long int x1=200,y1=200,x2=300,y2=200,x3=300,y3=300,x4=200,y4=300, x,y;
                double a;
//                outtextxy(30,130,"Rectangle for rotation");
                setcolor(3);
				line(x1,y1,x2,y2);
				line(x2,y2,x3,y3);
				line(x3,y3,x4,y4);
				line(x4,y4,x1,y1);
                cout<<"Angle of rotation:";
                cin>>a;
                a=(a*3.14/180);
		x=x1;y=y1;
		x1 = x*cos(a)-y*sin(a);
		y1 = x*sin(a)+y*cos(a);

		x=x2;y=y2;
		x2 = x*cos(a)-y*sin(a);
		y2 = x*sin(a)+y*cos(a);
		
		x=x3;y=y3;
		x3 = x*cos(a)-y*sin(a);
		y3 = x*sin(a)+y*cos(a);

		x=x4;y=y4;
		x4 = x*cos(a)-y*sin(a);
		y4 = x*sin(a)+y*cos(a);

                setcolor(4);
//		outtextxy(x1,y1,"Rectangle after rotation");
               
		line(x1,y1,x2,y2);
		line(x2,y2,x3,y3);
		line(x3,y3,x4,y4);
		line(x4,y4,x1,y1);

                getch();
		//closegraph(); 
                break;
	   }
        case 3:
            {
                int x1=30,y1=30,x2=70,y2=70,y=1,x=2;
//                outtextxy(30,200,"Before scaling");
                setcolor(3);
                rectangle(x1,y1,x2,y2);
//                outtextxy(x1*x,y1*y,"After scaling");
                setcolor(4);
                rectangle(x1*x,y1*y,x2*x,y2*y);
                getch();
                break;
	    }
	case 4:
            {
                 int x1=100,y1=100,x2=200,y2=200,x3=300,y3=100;
                 cout<<"triangle before reflection"<<endl;
                 setcolor(3);
                 line(x1,y1,x2,y2);
                 line(x1,y1,x3,y3);
                 line(x2,y2,x3,y3);cout<<"triangle after reflection"<<endl;
                 setcolor(5);
                 line(x1,-y1+500,x2,-y2+500);
                 line(x1,-y1+500,x3,-y3+500);
                 line(x2,-y2+500,x3,-y3+500);
                 getch();
		// closegraph();
                 break;}
        case 5:
        {
	     int x1=100,y1=100,x2=200,y2=100,x3=200,y3=200,x4=100,y4=200,shx=2;
             cout<<"Before shearing of rectangle"<<endl;
             setcolor(3);
             line(x1,y1,x2,y2);
             line(x2,y2,x3,y3);
             line(x3,y3,x4,y4);
             line(x4,y4,x1,y1);
             cout<<"After shearing of rectangle"<<endl;
             x1=x1+shx*y1;
             //Y1=Y1+SHY*X1;
             x2=x2+shx*y2;
             x3=x3+shx*y3;
             x4=x4+shx*y4;
             setcolor(13);
             line(x1,y1,x2,y2);
             line(x2,y2,x3,y3);
             line(x3,y3,x4,y4);
             line(x4,y4,x1,y1);
	     getch();
	      //closegraph();
                 break;	
	}
       	default:
          {
            cout<<"Invalid Selection"<<endl;
            break;
          }
        }
}
return 0;
}

