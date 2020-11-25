# defer
Perfect defer in C++

Here are exaple code in C++.
```
#include <defer>

void defer_test() {
    std::cout << "\ndefer_test begin\n";
    int* p=new int();

    defer{
        delete p;
        std::cout << "defer executed\n";
    };
    
    if ( true ) {
        std::cout << "defer_test end A\n";
        return;
    }

    *p=10;
    std::cout << "defer_test end B\n";
}

int main(){
   defer_test();
   return 0;
}
```
