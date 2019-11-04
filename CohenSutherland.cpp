#include<graphics.h>
#include<math.h>
#include<dos.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void Cohensutherland(int x1,int y1,int x2,int y2,int xa, int ya, int xb,int yb)
{
	int a[4],b[4],i,kthuc=0;
	while(kthuc==0)
	{
		a[1]=a[2]=a[3]=a[4]=0;
		if(xa<x1) a[1]=1;
		if(xa>x2) a[2]=1;
		if(ya<y1) a[3]=1;
		if(ya>y2) a[4]=1;b[1]=b[2]=b[3]=b[4]=0;
		if(xb<x1) b[1]=1;
		if(xb>x2) b[2]=1;
		if(yb<y1) b[3]=1;
		if(yb>y2) b[4]=1;
		int ktra=0;
		for(i=1;i<=4;i++)
		{ 
			if( (a[i]==1) || (b[i]==1) ) ktra=1; 
		};
		if(ktra==0) { 
			setcolor(10);line(xa,ya,xb,yb);kthuc=1;
		}
		else
		{
			int ktra1=1;
			for(i=1;i<=4;i++)
			{
				if( (a[i]==1) && (b[i]==1) ) ktra1=0;
			}
			if(ktra1==0) {
				kthuc=1;
			}
			else
			{ 
				if(a[1]==0 && a[2]==0 && a[3]==0 && a[4]==0)
				{
					for(i=1;i<=4;i++)
					{
						int tg1=a[i];a[i]=b[i];b[i]=tg1;
					}
					int tg2=xa;xa=xb;xb=tg2;
					int tg3=ya;ya=yb;yb=tg3;
				}
				if(a[1]==1)
				{
					ya=(yb-ya)*(x1-xa)/(xb-xa)+ya;
					xa=x1; //cout<<xa<<" "<<ya<<endl;
				}
				if(a[2]==1)
				{
					ya=(yb-ya)*(x2-xa)/(xb-xa)+ya;
					xa=x2;
				}
				if(a[3]==1)
				{
					xa=(xb-xa)*(y1-ya)/(yb-ya)+xa;
					ya=y1;
				}
				if(a[4]==1)
				{
					xa=(xb-xa)*(y2-ya)/(yb-ya)+xa;
					ya=y2;
				}
			}
		}
	}
}
int main(){
	int md=0, dr=0;
	initgraph(&md,&dr,"c:\\tc\\bgi");
	setcolor(11);
	rectangle(200,200,400,400);
	Cohensutherland(200,200,400,400,150,100,300,300);
	getch();
}
