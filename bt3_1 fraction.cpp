#include <bits/stdc++.h>
#include "fraction.h"
using namespace std;

int main()
{
    //Khoi tao theo yeu cau bai 1 default, 1 co 2 tham so, 1 co gia tri nguyen, 1 copy
    fraction p1, p2(1, 2), p3(3), p4(p1);
    cout << "Kiem tra khoi tao voi p1(default constructor) input p1, p2(constructor voi tu va mau cho truoc), p3(constructor gia tri nguyen cho truoc), p4(copy constructor p1)" << endl;
    p1.in();
    cout << "Phan so p1: ";
    p1.out();
    cout << "Phan so p2 voi tu va mau cho truoc la 1 va 2: ";
    p2.out();
    cout << "Phan so p3 voi gia tri nguyen cho truoc la 3: ";
    p3.out();
    p4 = p1;
    cout << "Phan so p4 (copy p1): ";
    p4.out();
    //Khoi tao 2 phan so temp;
    fraction p, p_r;
    cout << "Phan so p1 nghich dao: ";
    p_r = p1.nghichDao();
    if (p1.getTu() != 0)
        p_r.out();
    else
        cout << "Phan so nay khong the nghich dao" << endl;
    cout << "Rut gon phan so p1: ";
    p1.RutGon();
    //Phep toan phan so
    cout << "Nhap vao phan so p de tinh voi p1:\n\t";
    p.in();
    cout << "Phan so p: ";
    p.out();
    p_r = p.cong(p1);
    cout << "p + p1 = ";
    p_r.out();
    p_r = p.tru(p1);
    cout << "p - p1 = ";
    p_r.out();
    p_r = p.nhan(p1);
    cout << "p x p1 = ";
    p_r.out();
    if (p1.getTu() != 0)
    {
        p_r = p.chia(p1);
        cout << "p / p1 = ";
        p_r.out();
    }
    else
        cout << "Khong the thuc hien phep chia p / p1" << endl;
    // So sanh 2 phan so
    cout << "So sanh 2 phan so:\n\t";
    if (p.isEqual(p1))
        cout << "\tPhan so p bang p1";
    else
    {
        cout << "Phan so p khac p1" << endl;
        if (p.isBigger(p1))
            cout << "\tPhan so p lon hon p1";
        else
            cout << "\tPhan so p be hon p1";
    }
    return 0;
}