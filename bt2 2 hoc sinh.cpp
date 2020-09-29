#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

struct Hs
{
    string hoten, xeploai;
    float toan, van, dtb;
    void operator=(const Hs &hs)
    {
        hoten = hs.hoten;
        toan = hs.toan;
        van = hs.van;
        dtb = hs.dtb;
        xeploai = hs.xeploai;
    }
    friend istream &operator>>(istream &input, Hs &hs)
    {
        cin.ignore();
        cout << "\n\tNhap vao ho va ten: ";
        getline(input, hs.hoten);
        cout << "\tNhap vao diem mon toan: ";
        input >> hs.toan;
        cout << "\tNhap vao diem mon van: ";
        input >> hs.van;
        return input;
    }
    friend ostream &operator<<(ostream &output, Hs &hs)
    {
        cout << "\n\tHo va ten: " << hs.hoten << endl;
        cout << "\tDiem toan: " << hs.toan << endl;
        cout << "\tDiem van: " << hs.van << endl;
        return output;
    }
    friend void diemTB(Hs *&hs, int n)
    {
        for (int i = 0; i < n; ++i)
            (*(hs + i)).dtb = (((*(hs + i)).toan) * 2 + (*(hs + i)).van) / 3;
    }
    friend void xl(Hs *&hs, int n)
    {
        for (int i = 0; i < n; ++i)
        {
            if ((*(hs + i)).dtb >= 8.0)
                (*(hs + i)).xeploai = "Gioi";
            else if ((*(hs + i)).dtb >= 7.0)
                (*(hs + i)).xeploai = "Kha";
            else if ((*(hs + i)).dtb >= 5.0)
                (*(hs + i)).xeploai = "Trung Binh";
            else
                (*(hs + i)).xeploai = "Yeu";
        }
    }
    friend bool operator<(Hs &hs1, Hs &hs2)
    {
        return hs1.dtb < hs2.dtb;
    }
    friend bool operator>(Hs &hs1, Hs &hs2)
    {
        return hs1.dtb > hs2.dtb;
    }
};
void fillList(Hs *&hs, int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << "Nhap Hs " << i + 1 << ":";
        cin >> *(hs + i);
    }
}
void printList(Hs *&hs, int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << "Hs " << i + 1 << ":";
        cout << *(hs + i) << endl;
    }
}
void printDTB(Hs *&hs, int n)
{
    for (int i = 0; i < n; ++i)
        cout << "\n\tHo va ten: " << (*(hs + i)).hoten << "\n\tDiem trung binh: " << (*(hs + i)).dtb << "   xep loai: " << (*(hs + i)).xeploai << endl;
}
bool *(compare)(Hs, Hs);
bool stonks(Hs hs1, Hs hs2)
{
    return hs1 < hs2;
}
bool stinks(Hs hs1, Hs hs2)
{
    return hs1 > hs2;
}
void sSort(Hs *&hs, int n, bool (*compare)(Hs, Hs))
{
    for (int i = 0; i < n - 1; ++i)
    {
        int min = i;
        for (int j = i + 1; j < n; ++j)
            if (!compare((*(hs + min)), (*(hs + j))))
                min = j;
        Hs temp = *(hs + i);
        *(hs + i) = *(hs + min);
        *(hs + min) = temp;
    }
}
int main()
{
    int n;
    while (1)
    {
        cout << "Nhap vao so luong hoc sinh: ";
        cin >> n;
        if (n > 0)
        {
            cout << "Input accept!";
            break;
        }
    }
    sleep(1);
    system("cls");
    Hs *hs = new Hs[n];
    cout << "===Nhap thong tin hoc sinh===\n";
    fillList(hs, n);
    cout << "===Xuat thong tin hoc sinh===\n";
    printList(hs, n);
    cout << "===Diem trung binh va xep loai cua moi hs===";
    diemTB(hs, n);
    xl(hs, n);
    printDTB(hs, n);
    int tick;
    cout << "===Sap xep danh sach hoc sinh theo thu tu===\n\t1.Tang dan\n\t2.Giam dan" << endl;
    while (1)
    {
        cout << "Lua chon: ";
        cin >> tick;
        if (tick <= 2 && tick >= 1)
            break;
    }
    switch (tick)
    {
    case 1:
        cout << "Sap xep danh sach hoc sinh theo diem trung binh tang dan";
        sSort(hs, n, stonks);
        printDTB(hs, n);
        break;
    case 2:
        cout << "Sap xep danh sach hoc sinh theo diem trung binh giam dan";
        sSort(hs, n, stinks);
        printDTB(hs, n);
        break;
    }
    // Free the memory
    delete[] hs;
    return 0;
}