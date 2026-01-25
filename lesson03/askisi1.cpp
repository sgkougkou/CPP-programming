#include <iostream>
using namespace std;

int main()
{   
    int x=3;
    int *p;
    int **p2;

    p=&x;
    p2=&p;

    cout<<"Value of x="<<x<<", Address of x="<<&x<<endl;
    cout<<"Value of p="<<p<<", Address of p="<<&p<<", Value of x through p="<<*p<<endl;
    cout<<"Value of p2="<<p2<<", Address of p="<<&p2<<", Value of p through p2="<<*p2<<endl;

    cout<<sizeof p2;
    return 0;
}