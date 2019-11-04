#include<iostream>
#include<winbgim.h>
#include<math.h>
using namespace std;
 
void midpoint(int x1,int y1,int x2, int y2,int color){
    //Truong hop 0<m<1 && x1<x2 && y1<y2
    int a,b,pi,x,y,p;
    a=y2-y1;
    b=-(x2-x1);
    y=y1;
    x=x1;
    putpixel(x,y,color);    //Ve diem pixel dau tien
    p=2*a+b;        //tinh vi tri tuong doi cua diem Midpoint so voi duong thang
    while(x < x2){
        if(p < 0){   
            p+=2*a; // chon diem yi
        }else{      
            y++;
            p+=2*(a+b);//ch diem yi +1
        }
        x++;
        cout<<"Pixel (x,y) midpoint = ("<<x<<", "<<y<<")\n";
        putpixel(x,y,color);
        delay(10);
    }
}
void rotate()
{
		
}

 
 
int main(){
    initwindow(1000,1000);

	line(50,100,100,50);
	line(100,50,200,100);
	line(200,100,50,100);
	line(50+100,100+200,100+100,50+200);
	line(100+100,50+200,200+100,100+200);
	line(200+100,100+200,50+100,100+200);
    
    setwindowtitle("Thuat toan Line Midpoint");  
      //thiet   lap tieu    de  cho windows
    midpoint(20,50,100,100,10);
    midpoint(20-20,50-50,100-20,100-50,10);
    getch();
    return true;
}

