#include <iostream>
using namespace std;
class Date {
        int d, m, y;
    public:
        Date(int n=1, int t=1, int na=2020);
        //Tiền tố
        Date &operator ++ ();
        //Hậu tố
        Date operator ++ (int);
        friend istream &operator >>(istream &in, Date &x);
        friend ostream &operator <<(ostream &out, const Date &x);
};
//cin
Date::Date(int n, int t, int na):d(n), m(t), y(na){

}
int songay(int m, int y){
    int sn[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((y%4==0&&y%100!=0)||(y%400==0)) sn[2] = 29;
    return sn[m];
}
//Tiền tố
Date &Date::operator ++ (){
    if (d <songay(m, y)) d++;
    else {
        d = 1;
        if (m<12) m++;
        else {
            m = 1; y++;
        }
    }
    return *this;
}
//Hậu tố
Date Date::operator ++ (int){
    Date t = *this; 
    ++(*this);
    return t;
}
istream &operator >>(istream &in, Date &x){
    cout<<"Ngày: "; in>>x.d;
    cout<<"Tháng: "; in>>x.m;
    cout<<"Năm: "; in>>x.y;
    return in;
}
ostream &operator <<(ostream &out, const Date &x){
    out<<x.d<<"/"<<x.m<<"/"<<x.y<<endl;
    return out;
}
int main(){
    Date today, today1;
    cout<<"Nhap ngay bất kỳ:"; cin>>today;
    cout<<"Ngày vừa nhập: "<<today;
    cout<<"Ngày hôm sau:"<<today++;
    cout<<"Ngày hôm sau:"<<today;

}