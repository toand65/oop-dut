#include <bits/stdc++.h>
using namespace std;

//Cau hinh Phan So
struct PhanSo
{
    int tu;
    int mau;
};
//Toan tu nhap >>
istream &operator>>(istream &in, PhanSo &f)
{
    cout << "Nhap vao tu so: ";
    in >> f.tu;
    while (1)
    {
        cout << "Nhap vao mau so != 0: ";
        in >> f.mau;
        if (f.mau != 0)
            break;
        cout << "Nhap mau khong hop le " << endl;
    }
    return in;
}
//Toan tu xuat >>
ostream &operator<<(ostream &out, PhanSo &f)
{
    out << f.tu << "/" << f.mau << endl;
    return out;
}
//Nghich Dao phan so
void NghichDao(PhanSo f)
{
    if (f.tu != 0)
    {
        PhanSo temp;
        temp.tu = f.mau;
        temp.mau = f.tu;
        cout << temp;
    }
    else
        cout << "\n Phan so nay khong the nghich dao" << endl;
}
//Rut gon phan so (tim UCLN cua ca tu va mau roi lay lan luot tu, mau chia cho UCLN)
int UCLN(int a, int b)
{
    if (a % b != 0)
        return UCLN(b, a % b);
    else
        return b;
}
void RutGon(PhanSo f)
{
    int temp = UCLN(f.tu, f.mau);
    f.tu /= temp;
    f.mau /= temp;
    if (f.mau != 1)
    {
        if (f.mau < 0)
        {
            f.mau = f.mau * -1;
            f.tu = f.tu * -1;
        }
        cout << f.tu << "/" << f.mau << endl;
    }
    else
        cout << f.tu << endl;
}
//Toan tu phan so
PhanSo operator+(PhanSo a, PhanSo b)
{
    PhanSo temp;
    temp.tu = a.tu * b.mau + a.mau * b.tu;
    temp.mau = a.mau * b.mau;
    return temp;
}
PhanSo operator-(PhanSo a, PhanSo b)
{
    PhanSo temp;
    temp.tu = a.tu * b.mau - a.mau * b.tu;
    temp.mau = a.mau * b.mau;
    return temp;
}
PhanSo operator*(PhanSo a, PhanSo b)
{
    PhanSo temp;
    temp.tu = a.tu * b.tu;
    temp.mau = a.mau * b.mau;
    return temp;
}
PhanSo operator/(PhanSo a, PhanSo b)
{
    PhanSo temp;
    temp.tu = a.tu * b.mau;
    temp.mau = a.mau * b.tu;
    return temp;
}
int operator<(PhanSo a, PhanSo b)
{
    int x = a.tu / a.mau;
    int y = b.tu / b.mau;
    if (x < y)
        return 1;
    return 0;
}
int operator>(PhanSo a, PhanSo b)
{
    int x = a.tu / a.mau;
    int y = b.tu / b.mau;
    if (x > y)
        return 1;
    return 0;
}
int operator==(PhanSo a, PhanSo b)
{
    int x = a.tu / a.mau;
    int y = b.tu / b.mau;
    if (x == y)
        return 1;
    return 0;
}
int operator!=(PhanSo a, PhanSo b)
{
    int x = a.tu / a.mau;
    int y = b.tu / b.mau;
    if (x != y)
        return 1;
    return 0;
}
int main()
{
    PhanSo a, b, c;
    cout << "Nhap vao phan so dau tien: " << endl;
    cin >> a;
    cout << "Phan so vua nhap la: ";
    cout << a;
    cout << "Nghich dao: ";
    NghichDao(a);
    cout << "Phan so sau khi rut gon: ";
    RutGon(a);
    cout << "===========================" << endl;
    cout << "Nhap vao phan so thu 2: " << endl;
    cin >> b;
    cout << "Phan so vua nhap la: ";
    cout << b;
    cout << "Phan so sau khi rut gon: ";
    RutGon(b);
    c = a + b;
    cout << "Toan tu + cua 2 phan so: ";
    RutGon(c);
    c = a - b;
    cout << "Toan tu - cua 2 phan so: ";
    RutGon(c);
    c = a * b;
    cout << "Toan tu * cua 2 phan so: ";
    RutGon(c);
    c = a / b;
    cout << "Toan tu / cua 2 phan so: ";
    RutGon(c);
    cout << "Toan tu < cua 2 phan so: ";
    if (a < b)
        cout << "Phan so a < Phan so b" << endl;
    else
        cout << "Phan so a khong < Phan so b" << endl;
    cout << "Toan tu > cua 2 phan so: ";
    if (a > b)
        cout << "Phan so a > Phan so b" << endl;
    else
        cout << "Phan so a khong > Phan so b" << endl;
    cout << "Toan tu == cua 2 phan so: ";
    if (a == b)
        cout << "Phan so a == Phan so b" << endl;
    else
        cout << "Phan so a khong == Phan so b" << endl;
    cout << "Toan tu != cua 2 phan so: ";
    if (a != b)
        cout << "Phan so a != Phan so b" << endl;
    else
        cout << "Phan so a khong != Phan so b" << endl;
    return 0;
}