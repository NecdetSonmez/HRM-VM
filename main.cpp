#include <iostream>
#include "Core.hpp"

int main()
{
    Core testCore(16);
    testCore.readFile("input.hrm");
    testCore.printInstructions();
    testCore.printInbox();
    testCore.process();

    return 0;
}

