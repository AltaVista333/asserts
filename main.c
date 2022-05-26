#include "test/main.h"
#include <stdio.h>
int main() {
    SystemOpen(100);
    for (int i = 0; i < 10; ++i) {
        ASSERT(3 == 3, "TRUE");
        ASSERT(3 < 0, "Assertion #1");
        ASSERT(11 < 8, "Assertion #2");
        f();
        printf("#########\n");
    }

    Fatal_Error(5 > 5, "Fatal error, return code 5", 5);
    SystemClose();
    return 0;
}
