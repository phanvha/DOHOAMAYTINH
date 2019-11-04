#include <dos.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <graphics.h>

using namespace std;
// Khai bao bien toan cuc
int phepchieu; // = 1 : phoi canh; = 0 : song song
float r = 50, phi = 10,teta = 20,D = 20, tlx = 100, tly = 100;
int xo = 300, yo = 200; // (xo, yo) vi tri cai dat goc toa do tren man hinh
// Xay dung bo cong cu 3D
void chuyenHQS(float x, float y, float z, float &x1, float &y1, float &z1)
{
	x1 = - x * sin(teta) + y * cos(teta);
	y1 = - x * cos(teta) * sin(phi) - y * sin(teta) * sin(phi) + z * cos(phi);
	z1 = - x * sin(teta) * cos(phi) - y * cos(teta) * sin(phi) - z * sin(phi) + r;
}
void chieu3D_2D(float x, float y, float z, float &xp, float &yp)
{
	if (phepchieu == 1)
	{
		xp = D * x / z;
		yp = D * y / z;
	}
	else
	{
		xp = x;
		yp = y;
	}
}
void chuyenMH(float x, float y, int &xm, int &ym)
{
	xm = (int) (tlx * x + xo);
	ym = (int) (tly * y + yo);
}
void chuyenDen(float x, float y, float z)
{
	float x1, y1, z1, xp, yp;
	int xm, ym;
	chuyenHQS(x, y, z, x1, y1, z1);
	chieu3D_2D(x1, y1, z1, xp, yp);
	chuyenMH(xp, yp, xm, ym);
	moveto(xm, ym);

}
void veDen(float x, float y, float z)
{
	float x1, y1, z1, xp, yp;
	int xm, ym;
	chuyenHQS(x, y, z, x1, y1, z1);
	chieu3D_2D(x1, y1, z1, xp, yp);
	chuyenMH(xp, yp, xm, ym);
	lineto(xm, ym);
}
// Ve truc toa do
void veTruc()
{
	// In ky tu
	chuyenDen(-0.2, 0, 0.1);
	outtext("O");
	chuyenDen(4, 0, 0.3);
	outtext("x");
	chuyenDen(-0.1, 3, 0.3);
	outtext("y");
	chuyenDen(-0.2, 0, 2.1);
	outtext("z");

	// Ve truc
	// Ox
	chuyenDen(0, 0, 0);
	veDen(4, 0, 0);
	// Oy
	chuyenDen(0, 0, 0);
	veDen(0, 3, 0);
	// Oz
	chuyenDen(0, 0, 0);
	veDen(0, 0, 2);
}
// Ve lap phuong
void veLapPhuong(float x, float y, float z, float d)
{
	chuyenDen(x, y, z); // > A
	veDen(x + d, y, z); // > B
	veDen(x + d, y + d, z); // > C
	veDen(x, y + d, z); // > D
	veDen(x, y, z); // > A
	veDen(x, y, z + d); // > E
	veDen(x + d, y, z + d); // > F
	veDen(x + d, y + d, z + d); // > G
	veDen(x, y + d, z + d); // > H
	veDen(x, y, z + d); // > E
	chuyenDen(x + d, y, z); // > B
	veDen(x + d, y, z + d); // > F
	chuyenDen(x + d, y + d, z); // > C
	veDen(x + d, y + d, z + d); // > G
	chuyenDen(x, y + d, z); // > D
	veDen(x, y + d, z + d); // > F
}
void biendoitile(float x, float y, float z, float d)
{
	chuyenDen(x*2, y*2, z*2); // > A
	veDen((x + d)*2, y*2, z); // > B
	veDen((x + d)*2, (y + d)*2, z*2); // > C
	veDen(x*2, (y + d)*2, z*2); // > D
	veDen(x*2, y*2, z*2); // > A
	veDen(x*2, y*2, (z + d)*2); // > E
	veDen((x + d)*2, y*2, (z + d)*2); // > F
	veDen((x + d)*2, (y + d)*2, (z + d)*2); // > G
	veDen(x*2, (y + d)*2, (z + d)*2); // > H
	veDen(x*2, y*2, (z + d)*2); // > E
	chuyenDen((x + d)*2, y*2, z*2); // > B
	veDen((x + d)*2, y*2, (z + d)*2); // > F
	chuyenDen((x + d)*2, (y + d)*2, z*2); // > C
	veDen((x + d)*2, (y + d)*2, (z + d)*2); // > G
	chuyenDen(x*2, (y + d)*2, z*2); // > D
	veDen(x*2, (y + d)*2, (z + d)*2); // > F
}
void tinhtienLapPhuong(float x,float y,float z,float d)
{
	setcolor(BLACK);
	setcolor(WHITE);
	veTruc();
	setcolor(4);
	chuyenDen(x+0.5, y+0.5, z+0.5); // > A
	veDen(x + d+0.5, y+0.5, z+0.5); // > B
	veDen(x + d+0.5, y + d+0.5, z+0.5); // > C
	veDen(x+0.5, y + d+0.5, z+0.5); // > D
	veDen(x+0.5, y+0.5, z+0.5); // > A
	veDen(x+0.5, y+0.5, z + d+0.5); // > E
	veDen(x + d+0.5, y+0.5, z + d+0.5); // > F
	veDen(x + d+0.5, y + d+0.5, z + d+0.5); // > G
	veDen(x+0.5, y + d+0.5, z + d+0.5); // > H
	veDen(x+0.5, y+0.5, z + d+0.5); // > E
	chuyenDen(x + d+0.5, y+0.5, z+0.5); // > B
	veDen(x + d+0.5, y+0.5, z + d+0.5); // > F
	chuyenDen(x + d+0.5, y + d+0.5, z+0.5); // > C
	veDen(x + d+0.5, y + d+0.5, z + d+0.5); // > G
	chuyenDen(x+0.5, y + d+0.5, z+0.5); // > D
	veDen(x+0.5, y + d+0.5, z + d+0.5);
}
void xoayquanhtrucOz(float x,float y,float z,float d){
	setcolor(BLACK);
	float goc;
	cout<<"nhap goc quay";cin>>goc;
	float a=(goc*3.14152)/180;
	setcolor(WHITE);
	veTruc();
	setcolor(BLUE);
	chuyenDen(x*cos(a) - y*sin(a), x*sin(a) + y*cos(a), z); // > A
	veDen((x + d)*cos(a) - y*sin(a),(x + d)*sin(a) + y*cos(a), z); // > B
	veDen((x + d)*cos(a) - (y+d)*sin(a) , (x + d)*sin(a) + (y+d)*cos(a), z); // > C
	veDen(x*cos(a) - (y + d)*sin(a),x*sin(a) + (y+ d)*cos(a), z); // > D
	veDen(x*cos(a) - y*sin(a), x*sin(a) + y*cos(a), z); // > A
	veDen(x*cos(a) - y*sin(a), x*sin(a) + y*cos(a), z + d); // > E
	veDen((x + d)*cos(a) - y*sin(a),(x + d)*sin(a) + y*cos(a), z + d); // > F
	veDen((x + d)*cos(a) - (y+d)*sin(a) , (x + d)*sin(a) + (y+d)*cos(a), z + d); // >
	veDen(x*cos(a) - (y + d)*sin(a),x*sin(a) + (y+ d)*cos(a), z + d); // > H
	veDen(x*cos(a) - y*sin(a), x*sin(a) + y*cos(a), z + d); // > E
	chuyenDen((x + d)*cos(a) - y*sin(a),(x + d)*sin(a) + y*cos(a), z); // > B
	veDen((x + d)*cos(a) - y*sin(a),(x + d)*sin(a) + y*cos(a), z + d); // > F
	chuyenDen((x + d)*cos(a) - (y+d)*sin(a) , (x + d)*sin(a) + (y+d)*cos(a), z); // >
	veDen((x + d)*cos(a) - (y+d)*sin(a) , (x + d)*sin(a) + (y+d)*cos(a), z + d); // >
	chuyenDen(x*cos(a) - (y + d)*sin(a),x*sin(a) + (y+ d)*cos(a), z); // > D
	veDen(x*cos(a) - (y + d)*sin(a),x*sin(a) + (y+ d)*cos(a), z + d); // > F
}
void xoayquanhtrucOy(float x, float y, float z, float d)
{
	setcolor(BLACK);
	float goc;
	cout<<"nhap goc quay";cin>>goc;
	float a=(goc*3.14152)/180;
	setcolor(WHITE);
	veTruc();
	setcolor(BLUE);
	chuyenDen(x*cos(a) + x*sin(a), y , x*cos(a) - x*cos(a)); // > A
	veDen((x+d)*cos(a) + x*sin(a), y , (x+d)*cos(a) - x*cos(a)); // > B
	veDen((x+d)*cos(a) + (x+d)*sin(a), y , (x+d)*cos(a) - (x+d)*cos(a)); // > C
	veDen(x*cos(a) + (x+d)*sin(a), y , x*cos(a) - (x+d)*cos(a)); // > D
	veDen(x*cos(a) + x*sin(a), y , x*cos(a) - x*cos(a)); // > A
	veDen(x*cos(a) + x*sin(a), y + d , x*cos(a) - x*cos(a)); // > E
	veDen((x+d)*cos(a) + x*sin(a), y + d , (x+d)*cos(a) - x*cos(a)); // > F
	veDen((x+d)*cos(a) + (x+d)*sin(a), y + d , (x+d)*cos(a) - (x+d)*cos(a)); // >
	veDen(x*cos(a) + (x+d)*sin(a), y + d , x*cos(a) - (x+d)*cos(a)); // > H
	veDen(x*cos(a) + x*sin(a), y + d , x*cos(a) - x*cos(a)); // > E
	chuyenDen((x+d)*cos(a) + x*sin(a), y , (x+d)*cos(a) - x*cos(a)); // > B
	veDen((x+d)*cos(a) + x*sin(a), y + d  , (x+d)*cos(a) - x*cos(a)); // > F
	chuyenDen((x+d)*cos(a) + (x+d)*sin(a), y , (x+d)*cos(a) - (x+d)*cos(a)); // >
	veDen((x+d)*cos(a) + (x+d)*sin(a), y + d , (x+d)*cos(a) - (x+d)*cos(a)); // >
	chuyenDen(x*cos(a) + (x+d)*sin(a), y , x*cos(a) - (x+d)*cos(a)); // > D
	veDen(x*cos(a) + (x+d)*sin(a), y + d , x*cos(a) - (x+d)*cos(a)); // > F
}
void xoayquanhtrucOx(float x, float y , float z, float d)
{
	setcolor(BLACK);
	float goc;
	cout<<"nhap goc quay";cin>>goc;
	float a=(goc*3.14152)/180;
	setcolor(WHITE);
	veTruc();
	setcolor(BLUE);
	chuyenDen(x ,x*cos(a) - y*sin(a), x*sin(a) - y*cos(a)); // > A
	veDen(x ,(x + d)*cos(a) - y*sin(a),(x + d)*sin(a) - y*cos(a)); // > B
	veDen(x ,(x + d)*cos(a) - (y+d)*sin(a) , (x + d)*sin(a) - (y+d)*cos(a)); // > C
	veDen(x ,x*cos(a) - (y + d)*sin(a),x*sin(a) - (y+ d)*cos(a)); // > D
	veDen(x ,x*cos(a) - y*sin(a), x*sin(a) - y*cos(a)); // > A
	veDen(x + d,x*cos(a) - y*sin(a), x*sin(a) - y*cos(a)); // > E
	veDen(x + d ,(x + d)*cos(a) - y*sin(a),(x + d)*sin(a) - y*cos(a)); // > F
	veDen(x + d , (x + d)*cos(a) - (y+d)*sin(a) , (x + d)*sin(a) - (y+d)*cos(a)); // >
	veDen(x + d , x*cos(a) - (y + d)*sin(a),x*sin(a) - (y+ d)*cos(a)); // > H
	veDen(x + d, x*cos(a) - y*sin(a), x*sin(a) - y*cos(a)); // > E
	chuyenDen(x , (x + d)*cos(a) - y*sin(a),(x + d)*sin(a) - y*cos(a)); // > B
	veDen(x + d, (x + d)*cos(a) - y*sin(a),(x + d)*sin(a) - y*cos(a)); // > F
	chuyenDen(x, (x + d)*cos(a) - (y+d)*sin(a) , (x + d)*sin(a) - (y+d)*cos(a)); // >
	veDen(x + d, (x + d)*cos(a) - (y+d)*sin(a) , (x + d)*sin(a) - (y+d)*cos(a)); // >
	chuyenDen(x,  x*cos(a) - (y + d)*sin(a),x*sin(a) - (y+ d)*cos(a)); // > D
	veDen(x + d, x*cos(a) - (y + d)*sin(a),x*sin(a) - (y+ d)*cos(a)); // > F
}
void doixungLapPhuong(float x, float y, float z, float d)
{
	chuyenDen(x, -y, z); // > A
	veDen(x + d, -y, z); // > B
	veDen(x + d, -(y + d),z); // > C
	veDen(x, -(y + d), z); // > D
	veDen(x, -y, z); // > A 
	veDen(x, -y, (z + d)); // > E
	veDen(x + d, -y, (z + d)); // > F
	veDen(x + d, -(y + d), (z + d)); // > G
	veDen(x,-(y + d), (z + d)); // > H
	veDen(x, -y, (z + d)); // > E
	chuyenDen(x + d, -y, z); // > B
	veDen(x + d, -y, (z + d)); // > F
	chuyenDen(x + d, -(y + d), z); // > C
	veDen(x + d, -(y + d), (z + d)); // > G
	chuyenDen(x, -(y + d), z); // > D
	veDen(x, -(y + d), (z + d)); // > F
}
void chontrucquay()
{
	setcolor(BLACK);
	float truc;
	cout<<"chon truc quay: 1 -> Ox || 2 -> Oy || 3 -> Oz";
	cout<<"Nhap vao: ";cin>>truc;
	if(truc == 1)
	{
		xoayquanhtrucOx(1.5,1.5,0,1);
	}else if(truc == 2)
	{
		xoayquanhtrucOy(1.5,1.5,0,1);
	}else if(truc == 3)
	{
		xoayquanhtrucOz(1.5,1.5,0,1);
	}
}

int main()
{
	int driver = DETECT, mode = 0;
	initgraph(&driver, &mode,"C:\\Dev-Cpp\\include");
	// Ve truc toa do
	setcolor(WHITE);
	veTruc();
	// Ve lap phuong
	setcolor(WHITE);
	veLapPhuong(0.5, 0.5, 0, 1);
	
	float k;
	cout<<"\nnhap yeu cau: ";
	cout<<"\n 1 -> bien doi ti le: ";
	cout<<"\n 2 -> quay quanh truc: ";
	cout<<"\n 3 -> tinh tien: ";
	cout<<"\n 4 -> doi xung: ";
	cout<<"\nnhap: ";cin>>k;
	if(k == 1)
	{
		biendoitile(1.5,1.5,0,1);
	}else if(k == 2)
	{
		chontrucquay();
	}else if(k == 3)
	{
		tinhtienLapPhuong(1.5,1.5,0,1);
	}else if(k == 4)
	{
		doixungLapPhuong(1.5,1.5,0,1);
	}else{
		cout<<"\nmoi nhap lai! ";
	}
	getch();
	return 0;
}
