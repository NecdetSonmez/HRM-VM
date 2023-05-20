#include "Instruction.hpp"

Instruction::Instruction()
{
    
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
    m_parameter = parameter;
}


