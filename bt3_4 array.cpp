#include <bits/stdc++.h>
#include "array.h"
using namespace std;

int main()
{
    //Khoi tao 3 loai khoi tao cua mang
    Array a0, a1(8), a2(a1);
    cout << "Kiem tra khoi tao voi a1(default constructor),a2(constructor tham so), a3(copy constructor a1)" << endl;
    //Kiem tra so phan tu rong mang a0, a1, a2;
    cout << "So phan tu cua a0 la: " << a0.getSize() << endl;
    cout << "So phan tu cua a1 la: " << a1.getSize() << endl;
    cout << "So phan tu  a2 la (copy tu a1) la: " << a2.getSize() << endl;
    cout << "\nNhap vao so phan tu cua mang a: ";
    int n;
    cin >> n;
    //Khoi tao 1 mang a co n phan tu nhap vao tu ban phim
    Array a(n);
    cout << "Nhap vao gia tri cua cac phan tu trong mang a" << endl;
    a.in();
    cout << "Xuat mang a: ";
    a.out();
    //Lay gia tri tai 1 vi tri nao do trong mang
    cout << "\nLay phan tu tai vi tri nao do trong mang a\n+ Nhap vao vi tri: ";
    int pos, pValue;
    cin >> pos;
    if (pos >= 0 && pos <= n)
        cout << "Gia tri cua phan tu tai vi tri " << pos << " la: " << a.getValue(pos) << endl;
    else
        cout << "Khong co vi tri nay!!" << endl;
    //Thay doi gia tri tai vi tri nao do trong mang
    cout << "\nThay doi gia tri tai vi tri nao do trong mang a\n+ Nhap vao vi tri: ";
    cin >> pos;
    cout << "+ Nhap vao gia tri: ";
    cin >> pValue;
    if (pos >= 0 && pos <= n)
    {
        a.reValue(pos, pValue);
        cout << "Mang a sau khi thay doi gia tri: ";
        a.out();
    }
    else
        cout << "Khong co vi tri nay!" << endl;
    //Tim kiem phan tu
    cout << "\nTim kiem phan tu trong mang a\n+Nhap vao gia tri can tim: ";
    cin >> pValue;
    if (a.findValue(pValue) != -1)
        cout << "Da tim thay phan tu can tim tai vi tri " << a.findValue(pValue) << "tinh tu vi tri dau tien" << endl;
    else
        cout << "Khong tim thay phan tu can tim" << endl;
    //Lua chon sap xep
    cout << "\nSap xep tang, giam\n1.Tang\n2.Giam\n";
    int control;
    do
    {
        cout << ":: ";
        cin >> control;
    } while (control != 1 && control != 2);
    switch (control)
    {
    case 1:
        cout << "Mang a dc sap xep tang dan: ";
        a.sort(stinks);
        a.out();
        break;
    case 2:
        cout << "Mang a dc sap xep giam dan: ";
        a.sort(stonks);
        a.out();
        break;
    }
    cout << endl;
    cout << "Huy 4 doi tuong:" << endl;
    // Object is destroyed !!!
    return 0;
}