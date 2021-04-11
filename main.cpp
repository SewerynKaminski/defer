#include <iostream>
#include <chrono>
#include <defer>

using namespace std;
using namespace std::chrono;

void defer_test ( ) {
    cout << "defer_test begin\n";
    int* p=new int();   // dynamic memory allocation

    defer{              // this is not executed here!
        delete p;
        cout << "defer executed\n";
    };
    
    auto rnd = duration_cast<milliseconds>(system_clock::now().time_since_epoch>
    if ( rnd & 1 ) {    // 50% of probability (try execute few times to see path A and B)
        cout << "defer_test end A\n";
        return;         // triggers defer section
    }

    *p=10;
    cout << "defer_test end B\n";
                        // triggers defer section
}

int main ( ) {
    cout << "main before\n";

    defer_test();

    cout << "main after\n";

    return 0;
}
