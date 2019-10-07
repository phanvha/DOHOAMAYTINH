#include <iostream>
#include <graphics.h>
#include <math.h>
#define Round(a) (int)(a+0.5)   // lam tron so
#define max(a,b) (a>b)?a:b
#define DELAY 10
#include <conio.h>
using namespace std ;
int color = 2;
   
void lineDDA(int x1, int y1, int x2, int y2){       // thuat toan DDA
    int  Dx = x2 - x1, Dy = y2 - y1;  
    float x_inc , y_inc;
    float step=max(abs(Dx),abs(Dy));
    x_inc=Dx/step;
    y_inc=Dy/step;
    float x=x1, y=y1;// Khoi tao cac gia tri ban dau
    putpixel(x, y, color);
      
    int k=1;
    while(k <=step){
        k++;
        delay(DELAY);  // thoi gian tre khi ve 1 diem anh
        x += x_inc;
        y += y_inc;
        cout<<"x="<<x<<"\ty="<<y<<endl;
        putpixel(Round(x),Round(y),color);
         
    }
}
int main(){
    int gd,gm;
    gd=DETECT;
    initgraph(&gd,&gm,NULL);        // khoi tao cua so do hoa
    setcolor(5);
    lineDDA(20,30,500,250);   	  //ve duong thang theo DDA
    getch();
    return 0;
}
