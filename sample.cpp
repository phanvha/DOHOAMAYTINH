#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>

void KimGiay()
{
	int a, b, r , goc,	xoa;
	float x,y;
	a = getmaxx()/2;
	b = getmaxy()/2;
	setlinestyle(0,0,1);
	circle(a,b,4);
	//floodfill(x,y,4);
	setcolor(4);
	circle(a,b,b-10);
	r = b-18;
	x = y =0;
	setcolor(2);
	goc = 0;
	while(!kbhit())
	{
		x = r*cos((goc*3.14)/180);
		if(x<0){
			x = a + x;
		}else{
			x = a+x;
		}
		y = r*sin((goc*3.14)/180);
		if(y<0){
			y = y+b;
		}else{
			y =y+b;
		}
		setcolor(2);
		line(a,b,(int)ceil(x),(int)ceil(y));
		delay(200);
		goc++;
		
		//xoa duong vua ve
		xoa = goc -1;
		x = cos(xoa*3.14)/180);
		if(x<0){
			x = a +x;
		}else{
			x = x + a;
		}
		y = r*sin((xoa*3.14)/180);
		if(y<0){
			y = b + y;
		}else{
			y = b + y;
		}
		setcolor(0);
		line(a,b,(int)ceil(x),(int)ceil(y));
		if(goc>360){
			goc = 0;
		}
		delay(50);
	}
	int main()
	{
		int mh, mode;
		mh = mode =0;
		initgraph(&mh,&mode,(C:\TC\BGT));
		KimGiay();
		getch();
		closegraph();
		return();	
	}
}
