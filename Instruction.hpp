#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include <string>

enum class ParameterType
{
    None = 0,
    Data,
    CellIndex,
    Label
};

class Instruction
{
public:
    Instruction();

    std::string getInstructionType();
    ParameterType getParameterType();
    int getParameter();

    void setInstructionType(std::string instructionType);
    void setParameterType(ParameterType parameterType);
    void setParameter(int parameter);
private:
    std::string m_instructionType;
    ParameterType m_parameterType = ParameterType::None;
    int m_parameter;
};

#endif