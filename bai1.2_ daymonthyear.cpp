#include <bits/stdc++.h>
using namespace std;

struct Date
{
    int d;
    int m;
    int y;
};
int checkDate(int m, int y)
{
    int x;
    switch (m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        x = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        x = 30;
        break;
    case 2:
        if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
            x = 29;
        else
            x = 28;
        break;
    default:
        x = 0;
    }
    return x;
}
istream &operator>>(istream &input, Date &date)
{
    int x;
    do
    {
        cout << "\tNhap vao ngay: ";
        input >> date.d;
        cout << "\tNhap vao thang: ";
        input >> date.m;
        cout << "\tNhap vao nam: ";
        input >> date.y;
        x = checkDate(date.m, date.y);
        if (x == 0 || date.d <= 0 || date.d > x)
            cout << "\tInput loi nhap vao, end" << endl;
    } while (x == 0 || date.d <= 0 || date.d > x);
}
ostream &operator<<(ostream &output, Date &date)
{
    output << date.d << "/" << date.m << "/" << date.y << endl;
    return output;
}
//Tien To++
Date &operator++(Date &date)
{
    date.d += 1;
    int x = checkDate(date.m, date.y);
    if (date.d > x)
    {
        date.d = 1;
        if (date.m == 12)
        {
            date.m = 1;
            date.y++;
        }
        else date.m++;
    }
    return date;
}
//Hau to ++
Date operator++(Date &date, int)
{
    Date temp = date;
    date.d += 1;
    int x = checkDate(date.m, date.y);
    if (date.d > x)
    {
        date.d = 1;
        if (date.m != 12)
        {
            date.m++;
        }
        else
        {
            date.m = 1;
            date.y++;
        }
    }
    return temp;
}
//Tien to --
Date &operator--(Date &date)
{
    date.d--;
    if (date.d == 0)
    {
        if (date.m == 1)
        {
            date.m = 12;
            date.y--;
        }
        else
            date.m--;
        date.d = checkDate(date.m, date.y);
    }
    return date;
}
//Hau to --
Date operator--(Date &date, int)
{
    Date temp = date;
    date.d--;
    if (date.d == 0)
    {
        if (date.m == 1)
        {
            date.m = 12;
            date.y--;
        }
        else
            date.m--;
        date.d = checkDate(date.m, date.y);
    }
    return temp;
}
//Tinh thu khi biet ngay thang nam, su dung cong thuc Julian
int returnDay(int d, int m, int y)
{
    int day = (d + ((153 * (m + 12 * ((14 - m) / 12) - 3) + 2) / 5) + (365 * (y + 4800 - ((14 - m) / 12))) + ((y + 4800 - ((14 - m) / 12)) / 4) - ((y + 4800 - ((14 - m) / 12)) / 100) + ((y + 4800 - ((14 - m) / 12)) / 400) - 32045) % 7;
    ;
    return day;
}
void printDay(Date &date)
{
    int day = returnDay(date.d, date.m, date.y);
    switch (day)
    {
    case 0:
        cout << "Thu 2" << endl;
        break;
    case 1:
        cout << "Thu 3" << endl;
        break;
    case 2:
        cout << "Thu 4" << endl;
        break;
    case 3:
        cout << "Thu 5" << endl;
        break;
    case 4:
        cout << "Thu 6" << endl;
        break;
    case 5:
        cout << "Thu 7" << endl;
        break;
    case 6:
        cout << "Chu Nhat" << endl;
        break;
    }
}
int operator<(Date date1, Date date2)
{
    if (date1.y < date2.y)
        return 1;
    if (date1.y == date2.y)
    {
        if (date1.m < date2.m)
            return 1;
        if ((date1.m == date2.m) && (date1.d < date2.d))
            return 1;
    }
    return 0;
}
int operator>(Date date1, Date date2)
{
    if (date1.y > date2.y)
        return 1;
    if (date1.y == date2.y)
    {
        if (date1.m > date2.m)
            return 1;
        if ((date1.d > date2.d) && (date1.m == date2.m))
            return 1;
    }
    return 0;
}
int operator==(Date date1, Date date2)
{
    if ((date1.d == date2.d) && (date1.m == date2.m) && (date1.y == date2.y))
        return 1;
    else
        return 0;
}
int operator!=(Date date1, Date date2)
{
    if (date1 == date2)
        return 0;
    else
        return 1;
}
int main()
{
    Date tg, tg2;
    cout << "Nhap vao thoi gian: "<<endl;
    cin >> tg;
    cout << "Thoi gian vua nhap la: ";
    cout << tg;
    cout << "Ngay la thu: ";
    printDay(tg);
    cout << "=== Toan tu ++ va -- ===" << endl;

    cout << "Toan tu tang 1 ngay voi ++tg: ";
    ++tg;
    cout << tg;

    cout << "\t++test: ";
    Date test1=++tg;
    cout << test1;

    cout << "Toan tu tang 1 ngay voi tg++: ";
    tg++;
    cout << tg;

    cout << "\ttest++: ";
    Date test2=tg++;
    cout << test2;
    
    cout << "Toan tu giam 1 ngay voi --tg: ";
    --tg;
    cout << tg;

    cout << "\t--test: ";
    Date test3=--tg;
    cout << test3;

    cout << "Toan tu giam 1 ngay voi tg--: ";
    tg--;
    cout << tg;

    cout << "\ttest--: ";
    Date test4=tg--;
    cout << test4;

    cout << "=== Toan tu so sanh giua 2 ngay ===" << endl;
    cout << "Nhap vao thoi gian thu 2: "<<endl;
    cin >> tg2;

    cout << "Thoi gian vua nhap la: ";
    cout << tg2;
    cout << "Ngay la thu: ";
    printDay(tg);
    if (tg == tg2)
        cout << "Thoi gian thu nhat trung voi Thoi gian thu 2" << endl;
    else
        cout << "Thoi gian thu nhat khong trung voi Thoi gian thu 2" << endl;
    if (tg < tg2)
        cout << "Thoi gian thu nhat dien ra truoc Thoi gian thu 2" << endl;
    if (tg > tg2)
        cout << "Thoi gian thu nhat dien ra sau Thoi gian thu 2" << endl;
    return 0;
}