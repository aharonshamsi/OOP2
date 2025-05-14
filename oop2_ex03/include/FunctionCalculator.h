#pragma once

#include <vector>
#include <memory>
#include <string>
#include <iosfwd>
#include <optional>
#include <iostream>
#include <sstream>
#include <fstream>
#include "MessageException.h"
#include "ResizeException.h"
#include "ManyArgumentsException.h"

inline constexpr int MAX_MAT_SIZE = 5;
inline constexpr int MAX_NUM_FUNCTIONS = 100;
inline constexpr int MINI_NUM_FUNCTIONS = 2;

class Operation;

class FunctionCalculator
{
public:
    FunctionCalculator(std::ostream& ostr);
    void run(std::istream& istr);
    void run();


private:

    template <typename FuncType>
    void binaryFunc(std::istream& istr)
    {
        if (auto f0 = readOperationIndex(istr), f1 = readOperationIndex(istr); f0 && f1)
        {
            if (m_operations.size() >= m_maxSizeFunction)
                throw MessageException("Error: Cannot add more functions. The maximum number of functions ("
                    + std::to_string(m_maxSizeFunction) + ") has been reached.\n");

            m_operations.push_back(std::make_shared<FuncType>(m_operations[*f0], m_operations[*f1]));
        }
    }

    template <typename FuncType>
    void unaryFunc()
    {
    	m_operations.push_back(std::make_shared<FuncType>());
	}

    template <typename FuncType>
    void unaryWithIntFunc(std::istream& istr)
    {
        int i = 0;
        istr >> i;
        m_operations.push_back(std::make_shared<FuncType>(i));
    }
    void printOperations() const;

    enum class Action
    {
        Invalid,
        Eval,
        Iden,
        Tran,
        Scal,
        Sub,
        Add,
        Mul,
        Comp,

        Read,
        Resize,

        Del,
        Help,
        Exit,
    };

    struct ActionDetails 
    {
        std::string command; 
        std::string description; 
        Action action;
    };

    using ActionMap = std::vector<ActionDetails>;
    using OperationList = std::vector<std::shared_ptr<Operation>>;



    const ActionMap m_actions;
    OperationList m_operations;
    bool m_running = true;
    std::ostream& m_ostr;
    bool m_readFormFile;
    int m_maxSizeFunction;
    int m_resizFunctions;
    int m_numLine;


    void eval(std::istream& istr);
    void del(std::istream& istr);
    void help(std::istream& istr);
    void exit(std::istream& istr);
    void readFromFile(std::istream& istr);
    void resizeSizeFunctions(std::istream& istr);
    void ChooseNumFunctions();
    void handleFileException();
    void updateNumOperation();
    bool checkArgumentSize(std::istream& istr);
    std::optional<int> readOperationIndex(std::istream& istr) const;
    Action readAction(std::istream& istr);
    void runAction(std::istream& istr, Action action);
    ActionMap createActions() const;
    OperationList createOperations() const;

};
