#include <winbgim.h>
#include<conio.h>
#define DELAY 10
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
   if(p<0) p=p+4*x+6;
   else
       {
            p=p+4*(x-y)+10;
            y=y-1;
       }
   x=x+1;
  }
}
int main(){
    int x1,y1,x2,y2;
    int gd,gm=VGAMAX; gd=DETECT;
    initgraph(&gd,&gm,NULL);
    circle(200,200,100);
    return 0;
}
