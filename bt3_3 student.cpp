#include <bits/stdc++.h>
#include "student.h"
using namespace std;

int main()
{
    //Khoi tao 3 doi tuong mau theo yeu de
    student s1, s2("Nguyen Minh Dung", 10, 8.5), s3(s1);
    cout << "Kiem tra khoi tao voi s1(default constructor),s2(constructor tham so), s3(copy constructor s1)" << endl;
    s1.output();
    s2.output();
    s3.output();
    cout << endl;
    cout << "Nhap vao so hoc sinh: ";
    int n;
    cin >> n;
    // cap phat dong mang gom n doi tuong student
    student *s = new student[n];
    //Nhap ten, diem toan, diem van, tinh diem trung binh, xep loai theo diem trung binh
    for (int i = 0; i < n; ++i)
    {
        cout << "S" << i + 1 << ":\n\t";
        (*(s + i)).input();
        (*(s + i)).DTB();
        (*(s + i)).xl();
        cout << endl;
    }
    //Xuat danh sach ban dau cua hoc sinh sau khi nhap, xu li
    cout << "Out danh sach ban dau\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "S" << i + 1 << ":\n\t";
        (*(s + i)).output();
        cout << endl;
    }
    //Thao tac getName, getToan, getVan
    cout << "Xuat danh sach only ho ten\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "\tS" << i + 1 << ": " << (*(s + i)).getName() << endl;
    }
    cout << "Xuat danh sach only diem toan\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "\tS" << i + 1 << ": " << (*(s + i)).getToan() << endl;
    }
    cout << "Xuat danh sach only diem van\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "\tS" << i + 1 << ": " << (*(s + i)).getVan() << endl;
    }
    //setName, setToan, setVan
    cout << "Sua doi lai ten, diem toan, diem van\n-Nhap vao thu tu hs can sua: ";
    int pos;
    cin >> pos;
    if (pos >= 0 && pos <= n)
    {
        cout << "Sua doi cho S" << pos << endl;
        cout << "\tNhap vao ten moi: ";
        char *name1 = new char[256];
        fflush(stdin);
        gets(name1);
        (*(s + pos - 1)).setName(name1);
        cout << "\tNhap vao diem toan moi: ";
        float toan1;
        cin >> toan1;
        (*(s + pos - 1)).setToan(toan1);
        cout << "\tNhap vao diem van moi: ";
        float van1;
        cin >> van1;
        (*(s + pos - 1)).setVan(van1);
        cout << endl;
    }
    else
        cout << "Khong co thu tu hoc sinh nay trong danh sach";
    //Output danh sach cuoi cung
    cout << "Danh sach cuoi cung sau khi sua doi" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << "S" << i + 1 << ":\n\t";
        (*(s + i)).output();
        cout << endl;
    }
}