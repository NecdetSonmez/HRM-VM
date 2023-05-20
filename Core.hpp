#ifndef CORE_HPP
#define CORE_HPP

#include <fstream>
#include <vector>
#include <ctype.h>
#include <iostream>
#include "Instruction.hpp"

class Core
{
public:
	Core();
	Core(unsigned int memorySize);
	~Core();
	void readFile(std::string fileName);
	void printInstructions();
	void printInbox();

private:
	int* m_memory;
	int m_hand;
	unsigned int m_programCounter;
	unsigned int m_memorySize = 8;

    std::vector<Instruction> m_instructions;
	std::vector<int> m_inbox;
};

#endif // !CORE_HPP

