#include<iostream>
#include<winbgim.h>
#include<math.h>
#include<conio.h>
//thuat toan ve duong tron bresenham
void ve8diem(int x0,int y0,int x, int y, int color)
{
  putpixel( x0 + x , y0 + y ,color);
  putpixel( x0 - x , y0 + y ,color);
  putpixel( x0 + x , y0 - y ,color);
  putpixel( x0 - x , y0 - y ,color);
  putpixel( x0 + y , y0 + x ,color);
  putpixel( x0 - y , y0 + x ,color);
  putpixel( x0 + y , y0 - x ,color);
  putpixel( x0 - y , y0 - x ,color);
}
void circle(int x0,int y0,int r)
{
  int x=0;int y=r;
  int p=3-2*r;
  while (x<=y)
  {
   ve8diem(x0,y0,x,y,15);
   if(p < 0) p=p+4*x+6;
   else
       {
            p=p+4*(x-y)+10;
            y=y-1;
       }
   x=x+1;
  }
}
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "c:\\tc\\bgi");
 
	circle(200, 200, 100);
 
	Sleep(3000);
	closegraph();
	return 0;	
}
