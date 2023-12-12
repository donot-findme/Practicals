#include<iostream>
using namespace std;
class complex
{
float  real,imag;
public:
complex(float x1,float x2)//parametrrised consructor
{real=x1;
imag=x2;}

complex()//default consructor
{real=imag=0;}

friend istream &operator>>(istream &in,complex &t) //operator >> overloaded
{
in>>t.real>>t.imag;
return in;
}

complex operator+(complex t) //operator + overloaded
{
complex z;
z.real=this->real+t.real;
z.imag=this->imag+t.imag;
return z;
}

complex operator*(complex t) //operator * overloaded
{
complex z;
z.real=this->real*t.real-this->imag*t.imag;
z.imag=this->imag*t.real+this->real*t.imag;
return z;
}


friend ostream &operator<<(ostream &op,complex &t) //operator << overloaded
{
op<<t.real<<"+i"<<t.imag;
return op;
}

};
int main()
{complex c1/*creates complex no 0+i0(default)*/,c2(3,5)/*creates complex no 3+i5(parameterized)*/,c3,c4;
int c;
char ch;
do
{
cout<<"%%%%%%%%%%%%%%polynimial operations%%%%%%%%%%%%%\n";
cout<<"1]addition of two complex no\n";
cout<<"2]multiplication of two complex no\n";
cout<<"enter your choise :";
cin>>c;
switch(c)
{
case 1:
cout<<"enter real & img  part of complex no. 1\n";
cin>>c1;
cout<<"enter real & img  part of complex no. 2\n";
cin>>c2;
c3=c1+c2;
cout<<"addition is : ";
cout<<c3<<"\n";
break;

case 2:
cout<<"enter real & img  part of complex no. 1\n";
cin>>c1;
cout<<"enter real & img  part of complex no. 2\n";
cin>>c2;
cout<<"multiplication is :";
c4=c1*c2;
cout<<c4<<"\n";
break;
}
cout<<"do you want to continue";
cin>>ch;
}while(ch=='y'||ch=='Y');

}