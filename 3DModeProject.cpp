#include<dos.h>
#include<math.h>
#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<graphics.h>
//khai bao bien
	int phepchieu;//=1:phoi canh; =0: song song 
	float r = 50;
	float phi = 10;
	float teta = 20.0;
	float D = 20;
	float tlx = 00;
	float tly = 100;
	int x0 = 300;//x0 la vi tri cai dat goc toa do tren man hinh
	int y0 = 200;//y0 la vi tri cai dat goc toa do tren man hinh
//xay dung bo cong cu 3D
void chuyenHQS(float x, float y, float z, float &x1, float &y1, float &z1)
{
	x1 = -x*sin(teta) + y*cos(teta);
	y1 = -x*cos(teta) * sin(phi) - y*sin(teta) * sin(phi) + z*cos(phi);
	z1 = -x*sin(teta) * cos(phi) - y*cos(teta) * sin(phi) - z*sin(phi) + r;
}
void chieu3D_2D(float x, float y, float z, float &xp, float &yp)
{
	if(phepchieu == 1)
	{
		xp = D * x/z;
		yp = D * y/z;
	} else
	{
		xp = x;
		yp = y;
	}
}
void chuyenMH(float x, float y, int &xm, int &ym)
{
	xm = (int) (tlx * x + x0);
	ym = (int) (tly * y + y0);
}
void chuyenDen(float x, float y, float z)
{
	float x1;
	float y1;
	float z1;
	float xp;
	float yp;
	int xm;
	int ym;
	chuyenHQS(x,y,z,x1,y1,z1);
	chieu3D_2D(x1,y1,z1.xp.yp);
	chuyenMH(xp,yp,xm,ym);
	moveto(xm,ym);
}
void veDen(float x, float y, float z)
{
	float x1;
	float y1;
	float z1;
	float xp;
	float yp;
	int xm;
	int ym;
	chuyenHQS(x,y,z,x1,y1,z1);
	chieu3D_2D(x1,y1,z1.xp.yp);
	chuyenMH(xp,yp,xm,ym);
	lineto(xm,ym);
}
//ve truc toa do
void veTruc()
{
	//in ky tu
	chuyenDen(-2.0, 0, 0.1);
	outtext("O");
	chuyenDen(4, 0, 0.3);
	outtext("x");
	chuyenDen(-0.1, 3, 0.3);
	outtext("y");
	chuyenDen(-0.2, 0, 2.1);
	outttext("z");
	//ve truc Ox
	chuyenDen(0,0,0);
	veDen(4,0,0);
	//Oy
	chuyenDen(0,0,0);
	veDen(0,3,0);
	//Oz
	chuyenDen(0,0,0);
	veDen(0,0,2);
}
//ve lap phuong
void veLapPhuong(float x, float y, float z, float d)
{
	chuyenDen(x,y,z);//>A
	veDen(x + d, y, z);//>B
	veDen(x + d, y + d,z);//>C
	veDen(x,y,z+d);//>D
	veDen(x,y,z);//>A
	veDen(z,y,z+d);//>E
	veDen(x+d,y,z+d);//>F
	veDen(x+d,y+d,z+d);//>G
	veDen(z,y+d,z+d);//>H
	veDen(x,y,z+d);//>E
	chuyenDen(x+d,y,z);//>B
	veDen(x+d,y,z+d);//>F
	chuyenDen(x+d,y+d,z);//>C
	veDen(x+d,y+d,z+d);//>G
	chuyenDen(x,y+d,z);//>D
	veDen(z.y+d,z+d);//>F
}
void biendoitile(float x, float y, float z, float d)
{
	chuyenDen(x*2,y*2,z*2);//>A
	veDen((x+d)*2,y*2,z);//>Bs
	veDem((x+d)*2,(y+d)*2,z*2);//>C
	veDen(x*2,(y+d)*2,z*2);//>D
	veDen(x*2,y*2,z*2);//>A
	veDen(x*2,y*2,(z+d)*2);//>E
	veDen((x+d)*2,y*2,(z+d)*2);//>F
	veDen((x+d)*2,(y+d)*2,(z+d)*2);//>G
	veDen(x*2,(y+d)*2,(z+d)*2);//>H
	veDen(x*2,y*2,(z+d)*2);//>E
	chuyenDen((x+d)*2,y*2,z*2);//>B
	veDen((x+d)*2,y*2,(z+d)*2);//>F
	chuyenDen((x+d)*2,(y+d)*2,z*2);//>C
	veDen((x+d)*2,(y+d)*2,(z+d)*2);//>G
	chuyenDen(x*2,(y+d)*2,z*2);//>D
	veDen(x*2,(y+d)*2,(z+d)*2);//>F
}
void biendangLapPhuong(float x, float y, float z, float d)
{
}
	
int main()
{	
	
	int driver = DETECT, mode = 0;
	initgraph(&driver, &mode,"C:\\Dev-Cpp\\include");
	//ve truc toa do
	setcolor(YELLOW);
	vetruc();
	//ve lap phuong
	setcolor(WHITE);
	veLapPhuong(0.5, 0.5, 0.1);
	//quay quanh truc 0z
	biendoitile(0.5, 0.5, 0.1);
	
}
