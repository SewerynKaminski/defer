# Perfect defer in C++

**defer** delays code execution to the exit of the scope.

- No more code duplication

- No more not all paths covered

- No more errors

Here's an example code in C++
```C++
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
```
Tested in C++11, C++14, C++17 and C++20

## Example output:
```
main before
defer_test begin
defer_test end B
defer executed
main after
```
