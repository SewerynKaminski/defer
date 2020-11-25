#include <defer>

void defer_test ( ) {
    std::cout << "defer_test begin\n";
    int* p=new int();

    defer{
        delete p;
        std::cout << "defer executed\n";
    };
    
    if ( !random() ) {
        std::cout << "defer_test end A\n";
        return;
    }

    *p=10;
    std::cout << "defer_test end B\n";
}

int main ( ) {
    cout << "main before\n";
    
    defer_test();
    
    cout << "main after\n";
    
    return 0;
}
