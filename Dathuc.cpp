#include <iostream>
using namespace std;
class Dathuc {
        int n;
        double *hs;
    public:
        Dathuc(int m=3, double x = 0); //Default constructor
        Dathuc(const Dathuc &); //Copy constructor
        ~Dathuc(); //Destructor
        int getn()const {return n;}
        double &operator [] (int i) const {return hs[i];}
        Dathuc operator + (const Dathuc &x);
        const Dathuc &operator = (const Dathuc &x);
        double operator () (double x) const;
};
Dathuc::Dathuc(int m, double x):n(m){
    hs = new double [n+1];
    for(int i=0; i<=n; i++) hs[i] = x;
}
Dathuc::Dathuc(const Dathuc &x):n(x.n){
    hs = new double [n+1];
    for(int i=0; i<=n; i++) hs[i] = x.hs[i];
}
Dathuc::~Dathuc(){
    delete [] hs;
}
istream &operator >>(istream &in, Dathuc &x){
    for(int i=0; i<=x.getn();i++){
        cout<<"He so thu "<<i<<":";
        in>>x[i];
    }
    return in;
}
ostream &operator <<(ostream &out, const Dathuc &x){
    for(int i=x.getn(); i>0; i--)
        out<<x[i]<<"*x^"<<i<<"+";
    out<<x[0]<<endl;
    return out;
}
Dathuc Dathuc::operator + (const Dathuc &x){
    Dathuc t(n>x.n?n:x.n);
    for(int i=0; i<=t.n; i++){
        double a = i <= this->n ? this->hs[i] : 0;
        double b = i <= x.n ? x[i] : 0;
        t[i] = a + b;
    }
    return t;
}
const Dathuc &Dathuc::operator = (const Dathuc &x){
    if (this != &x) {
        delete [] hs;
        n = x.n;
        hs = new double [n+1];
        for(int i=0; i<=n; i++) hs[i] = x[i];
    }
    return *this;
}
double Dathuc::operator () (double x) const{
    double S=0;
    for(int i=n; i>=0;i--) S = S * x + hs[i];
    return S;
}
int main(){
    Dathuc a,b(5);
    cout<<"Nhập đa thức a:"<<endl;
    cin>>a;
    cout<<"Nhập đa thức b:"<<endl;
    cin>>b;
    cout<<"Đa thức a:"<<a<<endl;
    cout<<"Đa thức b:"<<b<<endl;
    Dathuc c;
    c = a + b;
    cout<<"Đa thức tổng a + b:"<<c<<endl;
    double x;
    cout<<"Nhập x bất kỳ:"; cin>>x;
    cout<<"a("<<x<<")="<<a(x)<<endl;
}