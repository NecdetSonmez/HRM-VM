#include "Instruction.hpp"

#include <iostream>

Instruction::Instruction()
{

}

void Instruction::operator=(Instruction& obj)
{
    this->setInstructionType(obj.getInstructionType());
    this->setParameterType(obj.getParameterType());
    this->setParameter(obj.getParameter());
}

std::string Instruction::getInstructionType()
{
    return m_instructionType;
}

ParameterType Instruction::getParameterType()
{
    return m_parameterType;
}

int Instruction::getParameter()
{
    return m_parameter;
}

void Instruction::setInstructionType(std::string instructionType)
{
    m_instructionType = instructionType;
}

void Instruction::setParameterType(ParameterType parameterType)
{
    m_parameterType = parameterType;
}

void Instruction::setParameter(int parameter)
{
    if(m_parameterType != ParameterType::None)
        m_parameter = parameter;
}

void Instruction::print()
{
    if(m_parameterType != ParameterType::None)
        std::cout << m_instructionType << " " << m_parameter << "\n";
    else
        std::cout << m_instructionType << "\n";
}


