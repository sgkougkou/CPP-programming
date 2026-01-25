#include <iostream>
using namespace std;

class ARRAY {
    public:
        ARRAY(int in_n); 
        ~ARRAY();
        void setter(int i, int in_n);
        int getter(int i);
        int print(int i);
        void print();
    int *p, n;
};

int main()
{   
    int n=10;
    int i;
    ARRAY pin(n);

    for (i=0; i<n; i++) {
        pin.setter(i,i*i);
    }

    pin.print(); 
    
    return 0;
}

ARRAY::ARRAY(int in_n) {
     n = in_n;

     p = new int[n];
     if(!p)
        cout<<"Error allocating memory!";
}

ARRAY::~ARRAY() {
    delete [] p; 
}

void ARRAY::setter(int i, int val) {
    
    if (i>=0 && i<n)
        p[i]=val;
    else
        cout<<"Error! Out of bounds.";

}

int ARRAY::getter(int i) {
    
    if (i>=0 && i<n)
        return p[i];
    else 
        cout<<"Error! Out of bounds.";
    
    return -1;

}

void ARRAY::print() {
    int i;

    for (i=0; i<n; i++) {
        cout<<"p["<<i<<"]="<<p[i]<<endl;
    }
}