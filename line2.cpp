#include <winbgim.h>
#include<conio.h>
#define DELAY 10
int color = 2;
void Bresenham(int x1, int y1, int x2, int y2){
    int Dx = abs(x2 - x1);
    int Dy = abs(y2 - y1);
    int p = 2*Dy - Dx;
    int c1 = 2*Dy;
    int c2 = 2*(Dy-Dx);
    int x = x1;
    int y = y1;
    int x_unit = 1, y_unit = 1;
    putpixel(x,y,color);
    while(x != x2){
        delay(DELAY);
        if (p<0) p += c1;
        else{
            p += c2;
            y += y_unit;
        }
        x += x_unit;
        putpixel(x, y, color);
    }
}
int main(){
    int x1,y1,x2,y2;
    int gd,gm=VGAMAX; gd=DETECT;
    initgraph(&gd,&gm,NULL);
//  setbkcolor(4);
    Bresenham(50,150, 300, 200);
    delay(9000);
    return 0;
}
