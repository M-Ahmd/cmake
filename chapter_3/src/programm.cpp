#include<iostream>
using namespace std;

int main(){
    #ifndef NDEBUG
        cout << "bad world\n";
    #else
        cout << "hello world\n";
    #endif
    return 0;
}