#include <bits/stdc++.h>
#ifndef SoPhuc_h
#define SoPhuc_h
using namespace std;
//Khai bao class So phuc, thuoc tinh, methods
class SoPhuc
{
private:
    float r, i;

public:
    //Khai bao 3 constructor theo yeu cau cua de
    SoPhuc();
    SoPhuc(float, float);
    SoPhuc(const SoPhuc &);
    // Modify toan tu nhap xuat
    friend istream &operator>>(istream &input, SoPhuc &s)
    {
        cout << "Nhap vao phan thuc: ";
        input >> s.r;
        cout << "Nhap vao phan ao: ";
        input >> s.i;
        return input;
    }
    friend ostream &operator<<(ostream &output, SoPhuc &s)
    {
        if (s.r == 0 && s.i == 0)
            cout << "0";
        if (s.r != 0)
            output << s.r;
        if (s.i > 0)
        {
            if (s.r == 0)
            {
                output << s.i;
                cout << "i";
            }
            else
            {
                cout << "+";
                output << s.i;
                cout << "i";
            }
        }
        if (s.i < 0)
        {
            output << s.i;
            cout << "i";
        }
        return output;
    }
    //Lay phan thuc, phan ao
    float getReal();
    float getImag();
    //Gan gia tri cho phan thuc va phan ao
    void setReal(float real);
    void setImag(float imag);
    //Tinh module
    float module();
    //Phep toan tren so phuc
    SoPhuc sum(SoPhuc other);
    SoPhuc subtract(SoPhuc other);
    SoPhuc multiply(SoPhuc other);
    SoPhuc divide(SoPhuc other);
    //So sanh so phuc
    bool compare(SoPhuc other);
};
//Nguyen mau ham
SoPhuc::SoPhuc()
{
    r = i = 0;
}
SoPhuc::SoPhuc(float real, float imag = 1)
{
    r = real;
    i = imag;
}
SoPhuc::SoPhuc(const SoPhuc &other)
{
    r = other.r;
    i = other.i;
}
float SoPhuc::getReal()
{
    return r;
}
float SoPhuc::getImag()
{
    return i;
}
void SoPhuc::setReal(float real)
{
    r = real;
}
void SoPhuc::setImag(float imag)
{
    i = imag;
}
float SoPhuc::module()
{
    //a+bi
    //module=sqrt(pow(a,2)+pow(b,2))
    return sqrt(pow(r, 2) + pow(i, 2));
}
SoPhuc SoPhuc::sum(SoPhuc other)
{
    float x = r + other.getReal();
    float y = i + other.getImag();
    return SoPhuc(x, y);
}
SoPhuc SoPhuc::subtract(SoPhuc other)
{
    float x = r - other.getReal();
    float y = i - other.getImag();
    return SoPhuc(x, y);
}
SoPhuc SoPhuc::multiply(SoPhuc other)
{
    float x = r * other.getReal() - i * other.getImag();
    float y = r * other.getImag() + i * other.getReal();
    return SoPhuc(x, y);
}
SoPhuc SoPhuc::divide(SoPhuc other)
{
    float x = (r * other.getReal() + i * other.getImag()) / (pow(other.getReal(), 2) + pow(other.getImag(), 2));
    float y = (r * other.getReal() + i * other.getImag()) / (pow(other.getReal(), 2) + pow(other.getImag(), 2));
    return SoPhuc(x, y);
}
bool SoPhuc::compare(SoPhuc other)
{
    return r == other.getReal() && i == other.getImag();
}
#endif