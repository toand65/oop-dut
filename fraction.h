#include <bits/stdc++.h>
#ifndef fraction_h
#define fraction_h
using namespace std;
//Khoi tao class fraction, thuoc tinh va methods
class fraction
{
private:
    //Khai bao thuoc tinh
    int tu, mau;

public:
    //Khai bao methods
    //Khai bao default constructor, constructor with parameters, copy constructor
    fraction();
    fraction(int, int);
    fraction(const fraction &);
    //Nhap xuat phan so
    void in();
    void out();
    //Lay gia tri tu va mau
    int getTu();
    int getMau();
    //Gan gia tri cho tu mau
    void setTu(int t);
    void setMau(int m);
    //Nghich dao, rut gon phan so
    fraction nghichDao();
    int UCLN(int a, int b);
    void RutGon();
    //Phep toan phan so
    fraction cong(fraction other);
    fraction tru(fraction other);
    fraction nhan(fraction other);
    fraction chia(fraction other);
    //So sanh 2 phan so
    bool isBigger(fraction other);
    bool isEqual(fraction other);
};
//Default Constructor
fraction::fraction()
{
    tu = mau = 0;
}
//Constructor with parameters
fraction::fraction(int t, int m = 1)
{
    tu = t;
    mau = m;
}
//Copy constructor
fraction::fraction(const fraction &other)
{
    tu = other.tu;
    mau = other.mau;
}
//Nhap tu va mau phan so
void fraction::in()
{
    cout << "Nhap vao tu so: ";
    cin >> tu;
    while (1)
    {
        cout << "Nhap vao mau so != 0: ";
        cin >> mau;
        if (mau != 0)
            break;
        cout << "Nhap mau khong hop le " << endl;
    }
}
//Xuat phan so
void fraction::out()
{
    if (tu == 0)
        cout << "0" << endl;
    else if (mau == 1)
        cout << tu << endl;
    else
        cout << tu << "/" << mau << endl;
}
//Lay tu so va mau so
int fraction::getTu()
{
    return tu;
}

int fraction::getMau()
{
    return mau;
}
//Thay doi tu so mau so
void fraction::setTu(int t)
{
    tu = t;
}
void fraction::setMau(int m)
{
    mau = m;
}
//Nghich dao phan sol
fraction fraction::nghichDao()
{
    if (tu != 0)
    {
        fraction temp;
        temp.setTu(mau);
        temp.setMau(tu);
        return temp;
    }
}
//Rut gon phan so
int fraction::UCLN(int a, int b)
{
    if (a % b != 0)
        return UCLN(b, a % b);
    else
        return b;
}
void fraction::RutGon()
{
    int temp = UCLN(tu, mau);
    tu /= temp;
    mau /= temp;
    if (mau != 1)
    {
        if (mau < 0)
        {
            mau = mau * -1;
            tu = tu * -1;
        }
        cout << tu << "/" << mau << endl;
    }
    else
        cout << tu << endl;
}
//Phep toan cong tru nhan chia kem rut gon phan so
fraction fraction::cong(fraction other)
{
    int x = tu * other.getMau() + other.getTu() * mau;
    int y = mau * other.getMau();
    return fraction(x / UCLN(x, y), y / UCLN(x, y));
}
fraction fraction::tru(fraction other)
{
    int x = tu * other.getMau() - other.getTu() * mau;
    int y = mau * other.getMau();
    return fraction(x / UCLN(x, y), y / UCLN(x, y));
}
fraction fraction::nhan(fraction other)
{
    int x = tu * other.getTu();
    int y = mau * other.getMau();
    return fraction(x / UCLN(x, y), y / UCLN(x, y));
}
fraction fraction::chia(fraction other)
{
    int x = tu * other.getMau();
    int y = mau * other.getTu();
    return fraction(x / UCLN(x, y), y / UCLN(x, y));
}
//Toan tu so sanh
bool fraction::isBigger(fraction other)
{
    return (tu / mau) > (other.tu / other.mau);
}
bool fraction::isEqual(fraction other)
{
    float x = tu / mau;
    float y = other.tu / other.mau;
    if (x == y) return true;
    else return false;
}
#endif