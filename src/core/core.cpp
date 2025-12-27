#include "core/core.hpp"

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
        inst.print();
    std::cout << std::endl;
}

void Core::printInbox()
{
    for (auto in : m_inbox)
        std::cout << in << std::endl;
    std::cout << std::endl;
}

void Core::process()
{
    Instruction currentInstruction;
    std::cout << "Program started.\n";
    while(true)
    {
        currentInstruction = m_instructions[m_programCounter];

        // Find instruction index from instruction type string
        int instructionIndex = 0;
        while(instructionsList[instructionIndex].compare(currentInstruction.getInstructionType()))
            instructionIndex++;

        // Process instruction
        switch(instructionIndex)
        {
        case 0: // INBOX
            m_hand = m_inbox.back();
            m_inbox.pop_back();
            m_programCounter++;
        break;

        case 1: // OUTBOX
            std::cout << "Outbox: " << m_hand << "\n";
            // TODO: Clear m_hand
            m_programCounter++;
        break;

        case 2: // COPYFROM, TODO: Add indirect 
            m_hand = m_memory[currentInstruction.getParameter()];
            m_programCounter++;
        break;

        case 3: // COPYTO, TODO: Add indirect 
            m_memory[currentInstruction.getParameter()] = m_hand;
            m_programCounter++;
        break;

        case 4: // ADD, TODO: Add indirect 
            m_hand += m_memory[currentInstruction.getParameter()];
            m_programCounter++;
        break;

        case 5: // SUB, TODO: Add indirect 
            m_hand -= m_memory[currentInstruction.getParameter()];
            m_programCounter++;
        break;

        case 6: // BUMPUP, TODO: Add indirect 
            m_memory[currentInstruction.getParameter()] += 1;
            m_hand = m_memory[currentInstruction.getParameter()];
            m_programCounter++;
        break;

        case 7: // BUMPDOWN, TODO: Add indirect 
            m_memory[currentInstruction.getParameter()] -= 1;
            m_hand = m_memory[currentInstruction.getParameter()];
            m_programCounter++;
        break;

        default: // Ignore
        break;
        }

        if(m_programCounter >= m_instructions.size())
        {
            std::cout << "Program finished.\n";
            break;
        }
    }
}