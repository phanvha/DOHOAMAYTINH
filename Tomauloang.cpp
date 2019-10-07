#include <conio.h>
#include <winbgim.h>
#include <iostream>
#include <queue>
using namespace std;
struct ToaDo
{
    int x,y;
};
int MauNen;
void NhapDaGiac(int &n,int &x,int &y,ToaDo a[])
{
    cout<<"Nhap so dinh cua da giac n= "; cin>>n;
    for (int i=1;i<=n;i++)
    {
    cout<<"Toa do dinh P["<<i<<"].x= "; cin>>a[i].x;
    cout<<"Toa do dinh P["<<i<<"].y= "; cin>>a[i].y;
    }
    cout<<"Nhap diem (x,y) thuoc da giac:\n";
    cout<<"nhap x="; cin>>x;
    cout<<"nhap y="; cin>>y;
}
void VeDaGiac(int n,ToaDo a[],int color)
{
    setcolor(color);
    for (int i=1;i<=n;i++)
    {
    int j;
    if (i==n) j=1; else j=i+1;
    line(a[i].x,a[i].y,a[j].x,a[j].y);
    }
}
void ToLoang(int x,int y,int color)
{
    //  Khai bao queue chua pixel chua duoc to mau
    queue<ToaDo> Q;
    ToaDo m, Tg;
    if (getpixel(x,y)==MauNen  && x<getmaxx() && y<getmaxy())
    {
        m.x = x;
        m.y = y;
        putpixel(m.x, m.y, color);
        Q.push(m);  //  Them 1 diem vao queue, queue size tang 1
        while(Q.empty() == false)   //Xet 4 diem xung quanh voi moi diem luu trong queue (neu queue con phan tu)
        {
            Q.pop();//  Xoa 1 diem phia dau queue, queue size giam 1
            //Xet cac diem lan can cua 1 diem
            if(getpixel(m.x+1, m.y) == MauNen)
            {
                putpixel(m.x+1, m.y, color );
                Tg.x = m.x+1;
                Tg.y = m.y; 
                Q.push(Tg);// Them 1 diem vao cuoi queue
            }  
            if(getpixel(m.x-1, m.y) == MauNen)
            {
                putpixel(m.x-1, m.y, color);
                Tg.x = m.x-1;
                Tg.y = m.y;
                Q.push(Tg);
            }
            if(getpixel(m.x, m.y+1) == MauNen)
            {
                putpixel(m.x, m.y+1, color);
                Tg.x = m.x;
                Tg.y = m.y+1;
                Q.push(Tg);
            }
            if(getpixel(m.x, m.y-1) == MauNen)
            {
                putpixel(m.x, m.y-1, color);
                Tg.x = m.x;
                Tg.y = m.y-1;
                Q.push(Tg);
            }
            m = Q.front();// Dua ve gia tri dau tien cho hang doi
        delay(1);
        }
    }
}
int main()
{
    int x,y,n,Gd,Gm=VGAMAX;
    ToaDo a[10];
    NhapDaGiac(n,x,y,a);
    Gd=DETECT;
    initgraph(&Gd,&Gm,"");
    VeDaGiac(n,a,15);
    MauNen=getpixel(x,y);
    ToLoang(x,y,10);
    getch();
    closegraph();
}
