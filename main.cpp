#include <iostream>
#include <defer>

using namespace std;

void defer_test ( ) {
    cout << "defer_test begin\n";
    int* p=new int();

    defer{
        delete p;
        cout << "defer executed\n";
    };
    
    if ( !random() ) {
        cout << "defer_test end A\n";
        return;
    }

    *p=10;
    cout << "defer_test end B\n";
}

int main ( ) {
    cout << "main before\n";

    defer_test();

    cout << "main after\n";

    return 0;
}
