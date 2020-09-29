#include <bits/stdc++.h>
#ifndef student_h
#define student_h
using namespace std;

class student
{
    //Khoi tao thuoc tinh va methods
private:
    char *name, *typeRank;
    float van, toan, dtb;
public:
    //Khai bao constructor theo yc
    student();
    student(char *, float, float);
    student(const student &);
    //Destructor
    ~student();
    //Nhap xuat hoc sinh
    void input();
    void output();
    //Lay ten, diem toan, diem van
    char *getName();
    float getVan();
    float getToan();
    //Gan gia tri cho ten, diem toan, diem van
    void setName(char *other);
    void setVan(float other);
    void setToan(float other);
    //DTB((Toán * 2 + Văn)/3) : assignment 2
    float DTB();
    char *xl();
};
#endif
//Khoi tao default constructor
student::student()
{
    name = new char[50];
    van = toan = 0;
    dtb = 0;
    typeRank = (char *)"Chua Xep Loai";
}
//Khoi tao constructor voi tham so cho san
student::student(char *name1, float t, float v)
{
    name = name1;
    van = v;
    toan = t;
    dtb = 0;
    typeRank = (char *)"Chua Xep loai";
}
//Khoi tao copy constructor
student::student(const student &other)
{
    name = other.name;
    van = other.van;
    toan = other.toan;
    dtb = other.dtb;
    typeRank = other.typeRank;
}
//To be garbage collector :))
student::~student()
{
    delete[] name;
}
//Nhap ten, diem toan, diem van cua hoc sinh
void student::input()
{
    cin.ignore();
    cout << "Nhap vao ten hoc sinh: ";
    fflush(stdin);
    gets(name);
    cout << "\tNhap vao diem toan: ";
    cin >> toan;
    cout << "\tNhap vao diem van: ";
    cin >> van;
}
//Xuat ten, diem toan, diem van, dtb mon, xep loai
void student::output()
{
    cout << "Ho Ten: " << name << " || Diem toan: " << toan << " || van: " << van << " || Diem trung binh: " << dtb << " || Xep loai: " << typeRank << endl;
}
//Lay ten, diem toan, diem van
char *student::getName()
{
    return name;
}
float student::getVan()
{
    return van;
}
float student::getToan()
{
    return toan;
}
//Gan gia tri cho ten, diem toan, diem van
void student::setName(char *name1)
{
    name = name1;
}
void student::setVan(float van1)
{
    van = van1;
}
void student::setToan(float toan1)
{
    toan = toan1;
}
//Tinh diem trung binh theo cong thuc toan*2 cong van chia 3
float student::DTB()
{
    return dtb = ((toan * 2) + van) / 3;
}
//Xep loai hoc sinh
char *student::xl()
{
    if (dtb >= 8.0)
        typeRank = (char *)"Gioi";
    else if (dtb >= 7.0)
        typeRank = (char *)"Kha";
    else if (dtb >= 5.0)
        typeRank = (char *)"TB";
    else
        typeRank = (char *)"Yeu";
    return typeRank;
}
