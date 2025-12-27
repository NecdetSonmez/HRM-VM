#pragma once

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
    void operator=(Instruction& obj);

    std::string getInstructionType();
    ParameterType getParameterType();
    int getParameter();

    void setInstructionType(std::string instructionType);
    void setParameterType(ParameterType parameterType);
    void setParameter(int parameter);

    void print();
private:
    std::string m_instructionType = "";
    ParameterType m_parameterType = ParameterType::None;
    int m_parameter;
};
