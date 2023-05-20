#ifndef CORE_HPP
#define CORE_HPP

#include <fstream>
#include <vector>
#include <ctype.h>
#include <iostream>
#include "Instruction.hpp"

static const std::string instructionsList[] = {
	"INBOX",
	"OUTBOX",
	"COPYFROM",
	"COPYTO",
	"ADD",
	"SUB",
	"BUMPUP",
	"BUMPDOWN"
};

class Core
{
public:
	Core();
	Core(unsigned int memorySize);
	~Core();
	void readFile(std::string fileName);
	void printInstructions();
	void printInbox();
	void process();

private:
	int* m_memory;
	int m_hand;
	unsigned int m_programCounter = 0;
	unsigned int m_memorySize = 8;

    std::vector<Instruction> m_instructions;
	std::vector<int> m_inbox;
};

#endif // !CORE_HPP

