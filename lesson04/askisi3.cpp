#include <iostream>
#include <cstring>
using namespace std;

class String {
    public: 
        String();
        String(char *in_str);
        String(const String &ob);
        int get_length() const;
        char *get_str() const;
        void print();
        ~String();
    char *str; 
    int length;
};

int main()
{   
    char s[80] ="String";
    String s1(s);
    String s2=s1;

    s1.print();
    s2.print();

    return 0;
}

String::String() {
    length = 0;
    str = NULL;
}

String::String(char *in_str) {
    length = strlen(in_str);

    str = new char[length];
    if (!str)
        cout <<"Error allocating memory!";

    strcpy(str, in_str);
}

String::String(const String &ob) {
    length = ob.get_length();

    str = new char[length];
    if (!str)
        cout<<"Error allocating memory!";   

    strcpy(str , ob.get_str());
}

int String::get_length() const {
    return length;
}

char *String::get_str() const {
    return str;
}

void String::print() {
    cout<<str;
}

String::~String () {
    delete [] str;
}