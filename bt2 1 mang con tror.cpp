#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
//MSV 102190109 : SelectionSort
void fillArray(int **a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << "a[" << i << "][" << j << "]: "; // chay tu 0 toi n-1
            cin >> *(*(a + i) + j);
        }
        cout << endl;
    }
}
void outArray2D(int **a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << *(*(a + i) + j) << " ";
        cout << endl;
    }
}
void outArray(int *a, int n)
{
    for (int i = 0; i < n; ++i)
        cout << *(a + i) << "  ";
}
int max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}
int *findArray(int **a, int n)
{
    int *maxArray = new int[n + 1];
    for (int i = 0; i < n; ++i)
    {
        int maxElement = *(*(a + i) + 0);
        for (int j = 0; j < n; ++j)
            maxElement = max(maxElement, *(*(a + i) + j));
        *(maxArray + i) = maxElement;
    }
    return maxArray;
}
int *insertElemet(int *a, int &n, int k)
{
    int x;
    cout << "\nNhap vao x can chen: ";
    cin >> x;
    for (int i = n; i >= k; i--)
        *(a + i) = *(a + i - 1);
    *(a + k) = x;
    n++;
    return a;
}
int *deleteElemet(int *a, int &n, int k)
{
    for (int i = k; i < n; ++i)
        *(a + i) = *(a + i + 1);
    n--;
    return a;
}
void (*compare)(int, int);
void sSort(int *a, int n, bool (*compare)(int, int))
{
    for (int i = 0; i < n - 1; ++i)
    {
        int min = i;
        for (int j = i + 1; j < n; ++j)
            if (!compare(*(a + min), *(a + j)))
                min = j;
        int temp = *(a + i);
        *(a + i) = *(a + min);
        *(a + min) = temp;
    }
}
bool stonks(int l, int r)
{
    return l < r;
}
bool stinks(int l, int r)
{
    return l > r;
}
int linearSearch(int *a, int n)
{
    int x;
    cout << "\nNhap vao x can tim: ";
    cin >> x;
    for (int i = 0; i < n; ++i)
        if (*(a + i) == x)
            return i;
    return -1;
}
int binarySearch(int *a, int l, int r, int x, bool (*compare)(int, int))
{
    if (l <= r)
    {
        int m = (int)((l + r) / 2);
        if (*(a + m) == x)
            return m;
        if (!compare(x, *(a + m)))
            return binarySearch(a, m + 1, r, x, compare);
        return binarySearch(a, l, m - 1, x, compare);
    }
    return -1;
}
int main()
{
    int n, k;
    while (1)
    {
        cout << "Nhap vao n voi 3 <= n <= 10: ";
        cin >> n;
        cout << "Nhap vao k voi k <= n: ";
        cin >> k;
        // check dk input
        if ((n >= 3 && n <= 10) && n >= k)
        {
            cout << "Input accept!" << endl;
            break;
        }
    }
    sleep(1);
    system("cls");
    cout << "Ban vua nhap cap ma nhan n la: " << n << " va so nguyen k la: " << k << endl;
    cout << "=======Cap phat dong ma tran cap n========";
    int **a = new int *[n];
    for (int i = 0; i < n; ++i)
        a[i] = new int[n];
    int n1 = n; // 1 bien phu n1 de gia tri cap ma tran n ko bi thay doi
    cout << "\nDone!";
    cout << "\n=======Nhap phan tu vao ma tran========\n";
    fillArray(a, n);
    cout << "=======Xuat ma tran========\n";
    outArray2D(a, n);
    cout << "=======Mang 1 chieu X voi phan tu la cac so lon nhat trong tung i========\n";
    int *a1 = findArray(a, n);
    cout << "Output: ";
    outArray(a1, n);
    cout << "\n=======Chen so nguyen vao vi tri k = " << k << " cua mang X========";
    insertElemet(a1, n1, k); //n1 tang
    cout << "Output: ";
    outArray(a1, n1);
    cout << "\n=======Xoa phan tu cua mang X tai vi tri k = " << k << " ==========\n";
    deleteElemet(a1, n1, k); //n1 giam
    cout << "Output: ";
    outArray(a1, n1);
    cout << "\n=======SelectionSort va BinarySearch=========";
    int tick, x, pos;
    cout << "\nChon 1 trong 2:\n\t1.Tang dan\n\t2.Giam dan" << endl;
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
        sSort(a1, n1, stonks);
        cout << "Thu tu tang dan: ";
        outArray(a1, n1);
        cout << "\nTim kiem nhi phan voi thu tu tang dan:";
        cout << "\n\tNhap vao x can tim: ";
        cin >> x;
        pos = binarySearch(a1, 0, n1 - 1, x, stonks);
        if (pos == -1)
            cout << "Khong tim thay vi tri cua x trong mang !" << endl;
        else
            cout << "Vi tri cua x trong mang la: a[" << pos << "]" << endl;
        break;
    case 2:
        sSort(a1, n1, stinks);
        cout << "Thu tu giam dan: ";
        outArray(a1, n1);
        cout << "\nTim kiem nhi phan voi thu tu giam dan:";
        cout << "\n\tNhap vao x can tim: ";
        cin >> x;
        pos = binarySearch(a1, 0, n1 - 1, x, stinks);
        if (pos == -1)
            cout << "Khong tim thay vi tri cua x trong mang!" << endl;
        else
            cout << "Vi tri cua x trong mang la: a[" << pos << "]" << endl;
        break;
    }
    //Free the memory
    for (int i = 0; i < n; ++i)
        delete[] * (a + i);
    delete[] a;
    delete[] a1;
    return 0;
}