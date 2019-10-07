#include<iostream>
#include<winbgim.h>
#include<math.h>
#include<conio.h>

void put8pixel(int xc, int yc, int x, int y, int color)
{
    putpixel(x + xc, y + yc, color);
    putpixel(-x + xc, y + yc, color);
    putpixel(x + xc, -y + yc, color);
    putpixel(-x + xc, -y + yc, color);
    putpixel( y + xc, x + yc, color);
    putpixel(-y + xc, x + yc, color);
    putpixel(y + xc, -x + yc, color);
    putpixel(-y + xc, -x + yc, color);
}
void drawCircleMidpoint(int xc, int yc, int r, int color)
{
    int x = 0; int y = r;
    int f = 1 - r;
    put8pixel(xc, yc, x, y, color);
    while (x < y)
    {
        if (f < 0) f += (x << 1) + 3;
        else
        {
            y--;
            f += ((x - y) << 1) + 5;
        }
        x++;
        put8pixel(xc, yc, x, y, color);
    }
}
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "c:\\tc\\bgi");
 
	drawCircleMidpoint(200, 200, 100, 2);
 
	Sleep(10000);
	closegraph();
	return 0;
}
