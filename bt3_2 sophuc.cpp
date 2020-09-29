#include <bits/stdc++.h>
#include "sophuc.h"
using namespace std;

int main()
{
    //Khoi tao theo 4 yeu cau de
    SoPhuc s1, s2(1.5, 2.5), s3(3.5), s4(s1);
    //Kiem tra khoi tao 4 yeu cau
    cout << "Kiem tra khoi tao voi s1(default constructor) = 0,s2(constructor 2 phan thuc va ao cho truoc), s3(constructor voi phan thuc cho truoc), s4(copy constructor s1)" << endl;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;
    cout << "s4: " << s4 << endl;
    //Nhap gia tri cho s1
    cout << "\nNhap phan ao va phan thuc cho s1" << endl;
    cin >> s1;
    cout << "\nGia tri ban dau cua s1: " << s1 << endl;
    //Thay doi phan thuc, phan ao cho s1
    cout << "\nNhap vao mot so de thay doi gia tri thuc cua s1: ";
    float temp;
    cin >> temp;
    s1.setReal(temp);
    cout << "Nhap vao mot so de thay doi gia tri ao cua s1: ";
    cin >> temp;
    s1.setImag(temp);
    cout << "Gia tri moi cua s1 la: " << s1 << endl;
    //Tinh Module s1
    cout << "Module cua s1: " << s1.module() << endl;
    //Phep toan so phuc
    cout << "\nPhep toan so phuc" << endl;
    SoPhuc s, s5;
    cout<<"Nhap vao s5 de tinh voi s1"<<endl;
    cin >> s5;
    cout << "s1 = " << s1 << " tinh toan voi s5 = " << s5 << endl;
    s = s1.sum(s5);
    cout << "\ts1 + s5 = " << s << endl;
    s = s1.subtract(s5);
    cout << "\ts1 - s5 = " << s << endl;
    s = s1.multiply(s5);
    cout << "\ts1 * s5 = " << s << endl;
    s = s1.divide(s5);
    cout << "\ts1 / s5 = " << s << endl;
    //So sanh hai so phuc chi so sanh 2 so khac hay bang nhau
    cout << "\nSo sanh 2 so phuc s1 va s5" << endl;
    if (s1.compare(s5))
        cout << "\ts1 bang s5";
    else
        cout << "\ts1 khac s5";
    return 0;
}