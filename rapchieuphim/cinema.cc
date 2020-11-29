#include "cinema.h"

Cinema::Cinema(int x = 0, int y = 0)
{
    this->x = x;
    this->y = y;
    this->name = new string *[x];
    this->active = new bool *[x];
    this->price = new int *[x];
    for (int i = 0; i < x; i++)
    {
        this->name[i] = new string[y];
        this->active[i] = new bool[y];
        this->price[i] = new int[y];
    }
    for (int i = 0; i < this->x; i++)
    {
        for (int j = 0; j < this->y; j++)
        {
            this->name[i][j] = "";
            this->active[i][j] = 1;
            this->price[i][j] = 0;
        }
    }
}
Cinema::~Cinema()
{
    for (int i = 0; i < this->x; ++i)
    {
        delete[] name[i];
        delete[] active[i];
        delete[] price[i];
    }
    delete[] name;
    delete[] active;
    delete[] price;
}
void Cinema::Booking()
{
    int x1, y1;
    cout << "Nhap vao ghe X Y muon dat: ";
    cout << "\n\tHang ngang: ";
    cin >> x1;
    cout << "\tHang doc: ";
    cin >> y1;
    x1--;
    y1--;
    if (*(*(active + y1) + x1) == false)
        cout << "Ghe nay da dc dat tu truoc, vui long chon ghe khac" << endl;
    else
    {
        cout << "Ghe tai vi tri " << x1 + 1 << " " << y1 + 1 << " dat thanh cong!" << endl;
        cout << "Gia la: " << *(*(price + y1) + x1) << endl;
        *(*(active + y1) + x1) = false;
    }
}
bool Cinema::isActive(int x1, int y1)
{
    return *(*(active + y1) + x1);
}
int Cinema::getPrice(int x1, int y1)
{
    return *(*(price + y1) + x1);
}
int Cinema::Available()
{
    int count = 0;
    for (int i = 0; i < this->x; ++i)
        for (int j = 0; j < this->y; ++j)
            count += *(*(active + j) + i);
    return count;
}
// CinemaNormal::CinemaNormal(int x = 0, int y = 0)
// {
//     this->x = x;
//     this->y = y;
//     this->name = new string *[this->x];
//     this->active = new bool *[this->x];
//     this->price = new int *[this->x];
//     for (int i = 0; i < this->x; i++)
//     {
//         this->name[i] = new string[this->y];
//         this->active[i] = new bool[this->y];
//         this->price[i] = new int[this->y];
//     }
//     for (int i = 0; i < this->x; i++)
//         for (int j = 0; j < this->y; j++)
//         {
//             this->name[i][j] = "";
//             this->active[i][j] = 1;
//             this->price[i][j] = 0;
//         }
// }
void CinemaNormal::returnInfo()
{
    cout << "RAP CHIEU PHIM LOAI NORMAL" << endl;
    cout << "Khung ghe " << this->x << "." << this->y << endl;
    cout << "Gia ve cua hang ghe trung tam la 60k" << endl;
}
void CinemaNormal::Price(int day)
{
    int priceCenter;
    if (day == 5)
        priceCenter = 60000;
    else
        priceCenter = 30000;
    bool isEven = this->x % 2 ? false : true;
    for (int i = 0; i < this->y; ++i)
    {
        if (isEven)
            this->price[this->x / 2][i] = priceCenter;
        else
        {
            this->price[this->x / 2 - 1][i] = priceCenter;
            this->price[this->x / 2][i] = priceCenter;
        }
    }
    for (int i = 0; i < this->x; ++i)
    {
        for (int j = 0; j < this->y; ++j)
        {
            if (isEven)
            {
                if (i != this->x / 2)
                    this->price[i][j] = priceCenter - (this->x / 2 - i) * 2000;
                else
                    this->price[i][j] = priceCenter;
            }
            else
            {
                if (i < (this->x / 2 - 1))
                    this->price[i][j] = priceCenter - (this->x / 2 - 1 - i) * 2000;
                else
                    this->price[i][j] = priceCenter;
                if (i < this->x / 2)
                    this->price[i][j] = priceCenter - (i - this->x / 2) * 2000;
                else
                    this->price[i][j] = priceCenter;
            }
        }
    }
}
// CinemaVip::CinemaVip(int x = 0, int y = 0)
// {
//     this->x = x;
//     this->y = y;
//     this->name = new string *[x];
//     this->active = new bool *[x];
//     this->price = new int *[x];
//     for (int i = 0; i < x; i++)
//     {
//         this->name[i] = new string[y];
//         this->active[i] = new bool[y];
//         this->price[i] = new int[y];
//     }
//     for (int i = 0; i < this->x; i++)
//     {
//         for (int j = 0; j < this->y; j++)
//         {
//             this->name[i][j] = "";
//             this->active[i][j] = 1;
//             this->price[i][j] = 0;
//         }
//     }
// }
void CinemaVip::returnInfo()
{
    cout << "RAP CHIEU PHIM LOAI NORMAL" << endl;
    cout << "Khung ghe " << this->x << "x" << this->y << endl;
    cout << "Gia ve cua hang ghe trung tam la 100k" << endl;
}
void CinemaVip::Price(int day)
{
    const int priceCenter = 100000;
    bool isEven = this->x % 2 ? true : false;
    for (int i = 0; i < this->y; ++i)
    {
        if (isEven)
            this->price[this->x / 2][i] = priceCenter;
        else
        {
            this->price[this->x / 2 - 1][i] = priceCenter;
            this->price[this->x / 2][i] = priceCenter;
        }
    }
    for (int i = 0; i < this->x; ++i)
    {
        for (int j = 0; j < this->y; ++j)
        {
            if (isEven)
            {
                if (i != this->x / 2)
                    this->price[i][j] = priceCenter - abs(this->x / 2 - i) * 2000;
                else
                    this->price[i][j] = priceCenter;
            }
            else
            {
                if (i < (this->x / 2 - 1))
                    this->price[i][j] = priceCenter - (this->x / 2 - 1 - i) * 2000;
                else
                    this->price[i][j] = priceCenter;
                if (i < this->x / 2)
                    this->price[i][j] = priceCenter - (i - this->x / 2) * 2000;
                else
                    this->price[i][j] = priceCenter;
            }
        }
    }
}