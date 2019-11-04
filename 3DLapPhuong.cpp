#include <stdio.h>
#include <conio.h>
#include <graphics.h>
int x1,y1,x2,y2,x3,y3,x4,y4,y5,x5,x6,y6,x7,y7,x8,y8;
void velapphuong()
{
	x1=200,y1=200;
	x2=300,y2=200;
	x3=300,y3=300;
	x4=200,y4=300;
	x5=250,y5=150;
	x6=350,y6=150;
	x7=350,y7=250;
	x8=250,y8=250;
	setcolor(BLUE);
	rectangle(x5,y5,x7,y7);
	rectangle(x1,y1,x3,y3);
	line(x1,y1,x5,y5);
	line(x2,y2,x6,y6);
	line(x3,y3,x7,y7);
	line(x4,y4,x8,y8);
}
void tinhtien()
{
	int x,y;
	printf("Enter x & y");
	scanf("%d",&x);
	scanf("%d",&y);
	rectangle(x5+x,y5+y,x7+x,y7+y);
	rectangle(x1+x,y1+y,x3+x,y3+y);
	line(x1+x,y1+y,x5+x,y5+y);
	line(x2+x,y2+y,x6+x,y6+y);
	line(x3+x,y3+y,x7+x,y7+y);
	line(x4+x,y4+y,x8+x,y8+y);
}

int main() 
{
	int gd = DETECT,gm;
	initgraph(&gd, &gm,"C:\\TC\\BGI");
	
	velapphuong();
	tinhtien();
	getch();
	return 0;
}
