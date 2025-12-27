#include <iostream>
#include "core/core.hpp"

int main()
{
    Core testCore(16);
    testCore.readFile("../examples/input.hrm");
    testCore.printInstructions();
    testCore.printInbox();
    testCore.process();

    return 0;
}

