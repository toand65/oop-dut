#include <bits/stdc++.h>
#include "bds.cc"
using namespace std;

#define for(x, n) for(int x = 0; x < n; ++x)

int main()
{
    int n;
    cout << "Nhap vao so luong dat can quan li: ";
    cin >> n;
    double sumArea = 0;
    double sumMoney = 0;
    for(i, n)
    {
        cout << "Nhap vao loai dat ma cong ty co: ";
        int type;
        cout << "\n1.Dat Hinh Chu Nhat" << endl;
        cout << "2.Dat Hinh Tam Giac" << endl;
        cout << "3.Dat Hinh Thang" << endl;
        cin >> type;
        if (type == 1)
        {
            Dat *d1 = new DatHCN();
            d1->inputInfo();
            d1->outInfo();
            sumArea = d1->DienTich();
            sumMoney = d1->GiaTien();
        }
        else if (type == 2)
        {
            Dat *d2 = new DatTamGiac();
            d2->inputInfo();
            d2->outInfo();
            sumArea = d2->DienTich();
            sumMoney = d2->GiaTien();
        }
        else
        {
            Dat *d3 = new DatHinhThang();
            d3->inputInfo();
            d3->outInfo();
            sumArea = d3->DienTich();
            sumMoney = d3->GiaTien();
        }
    }
    cout<<"Tong Dien Tich la: "<<sumArea;
    cout<<"\tTong Tien la: "<<sumMoney;
    return 0;
}