#include <bits/stdc++.h>
using namespace std;
//Khai bao class Array, thuoc tinh, methods
class Array
{
private:
    int *value;
    int size;
public:
    //Khai bao cac constructor
    Array();
    Array(int);
    Array(const Array &);
    //Destructor
    ~Array();
    //Nhap xuat mang
    void in();
    void out();
    //Lay size Array, lay gia tri cua mang tai vi tri nao do
    int getSize();
    int getValue(int pos);
    //Gan gia tri khac vao vi tri nao do
    int reValue(int pos, int pValue);
    //Tim kiem phan tu, sap xep mang
    int findValue(int pValue);
    int sort(bool typeSort(int, int));
};
Array::Array()
{
    size = 0;
    value = new int[size];
}
Array::Array(int n)
{
    size = n;
    value = new int[size];
}
Array::Array(const Array &other)
{
    size = other.size;
    value = new int[size];
    for (int i = 0; i < other.size; ++i)
        *(value + i) = *(other.value + i);
}
Array::~Array()
{
    cout<<"Object is destroyed"<<endl;
    delete[] value;
}
void Array::in()
{
    cout << "So phan tu la: " << size << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << "\ta[" << i + 1 << "]: ";
        cin >> *(value + i);
    }
}
void Array::out()
{
    for (int i = 0; i < size; ++i)
        cout << *(value + i) << " ";
    cout << endl;
}

int Array::getSize()
{
    return size;
}
int Array::getValue(int pos)
{
    return *(value + pos - 1);
}
int Array::reValue(int pos, int pValue)
{
    return *(value + pos - 1) = pValue;
}
bool stinks(int a, int b)
{
    return a < b;
}
bool stonks(int a, int b)
{
    return a > b;
}
int Array::findValue(int pValue)
{
    for (int i = 0; i < size; ++i)
        if (*(value + i) == pValue)
            return i + 1;
    return -1;
}
int Array::sort(bool typeSort(int, int))
{
    for (int i = 0; i < size - 1; ++i)
    {
        int min = i;
        for (int j = i + 1; j < size; ++j)
            if (!typeSort(*(value + min), *(value + j)))
                min = j;
        int temp = *(value + i);
        *(value + i) = *(value + min);
        *(value + min) = temp;
    }
    return *value;
}
