#include <iostream>
using namespace std;
class Stack {
    public:
        int n, top, *data;
    public:
        Stack(int max = 10);
        Stack(const Stack &x);
        ~Stack();
        void Push(int x);
        void Pop(int &x);
        bool isFull();
        bool isEmpty();
};
Stack::Stack(const Stack &x){
    this->n = x.n;
    top = x.top;
    data = new int [n];
    for (int i=0; i<=top; i++) data[i] = x.data[i]; 
}
Stack::Stack(int max){
    data = new int [max];
    n = max;
    top = -1;
}
Stack::~Stack(){
    delete [] data;
}
void Stack::Push(int x){
    if (!isFull()) data[++top] = x;
}
void Stack::Pop(int &x){
    if (!isEmpty()) x = data[top--];
}
bool Stack::isFull(){
    return (top == n-1);
}
bool Stack::isEmpty(){
    return (top == -1);
}
int main(){
    int n;
    Stack S(8);
    cout<<"Nhap n:"; cin>>n;
    do {
        S.Push(n % 16);
        n /= 16;
    } while (n);
    cout<<"Day so thap luc phan:";
    int x;
    Stack S1(S);
    S1.data[1] = 10;
    char Hex[] = "0123456789ABCDEF";
    while (!S.isEmpty()) {
        S.Pop(x);
        cout<<Hex[x];
    }
    cout<<endl;
}