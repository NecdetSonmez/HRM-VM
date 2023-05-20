#include "Core.hpp"

Core::Core()
{
    m_memory = new int[m_memorySize];
}

Core::Core(unsigned int memorySize)
{
    m_memorySize = memorySize;
    m_memory = new int[m_memorySize];
}


Core::~Core()
{
    delete m_memory;
}

void Core::readFile(std::string fileName)
{
    std::ifstream inputFile;
	std::string inputLine;
    std::vector<std::string> inputLines;
    bool writeToInbox = true;

    inputFile.open(fileName);

    while(!inputFile.eof())
    {
        inputFile >> inputLine;

        if(!inputLine.empty())
        {
            inputLines.push_back(inputLine);
        }
    }

    for(auto token : inputLines)
    {
        if (writeToInbox)
        {
            // Inbox data loading
            if(token.front() == '#')
                continue;

            else if(std::isdigit(token.front()))
            {
                m_inbox.push_back(std::stoi(token));
                continue;
            }

            writeToInbox = false;
        }

        // Instruction start (does not process labels currently)
        if(std::isalpha(token.front()))
        {
            Instruction newInstruction;
            newInstruction.setInstructionType(token);
            m_instructions.push_back(newInstruction);
            continue;
        }

        // Parameter
        else if(std::isdigit(token.front()))
        {
            m_instructions.back().setParameterType(ParameterType::Data);
            m_instructions.back().setParameter(std::stoi(token));
            continue;
        }
    }
}

void Core::printInstructions()
{
    for(auto inst : m_instructions)
    {
        std::cout << inst.getInstructionType() << " ";
        if(inst.getParameterType() != ParameterType::None)
            std::cout << inst.getParameter();
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Core::printInbox()
{
    for (auto in : m_inbox)
        std::cout << in << std::endl;
}