#pragma once

#include <vector>
#include <memory>
#include <string>
#include <iosfwd>
#include <optional>
#include <iostream>

#include <sstream>

#include "MessageException.h"

inline constexpr int MAX_MAT_SIZE = 5;


class Operation;


class FunctionCalculator
{
public:
    FunctionCalculator(std::istream& istr, std::ostream& ostr);
    void run();

private:
    void eval();
    void del();
    void help();
    void exit();

    template <typename FuncType>
    void binaryFunc()
    {
        if (auto f0 = readOperationIndex(), f1 = readOperationIndex(); f0 && f1)
        {
            m_operations.push_back(std::make_shared<FuncType>(m_operations[*f0], m_operations[*f1]));
        }
    }

    template <typename FuncType>
    void unaryFunc()
    {
    	m_operations.push_back(std::make_shared<FuncType>());
	}
    template <typename FuncType>
    void unaryWithIntFunc()
    {
        int i = 0;
        m_istr >> i;
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
        Del,
        Help,
        Exit,
    };

    struct ActionDetails // פרטי פעולה
    {
        std::string command; // שם הפעולה
        std::string description; //תיאור הפעולה
        Action action; // מספר פונקציה
    };

    using ActionMap = std::vector<ActionDetails>;
    using OperationList = std::vector<std::shared_ptr<Operation>>;

    const ActionMap m_actions; // של עזרה ActionDetails וקטור של 
    OperationList m_operations; // וקטור הדפסת הפעולות
    bool m_running = true; // משתנה שמייצג האם הפונקציה פעילה
    std::istream& m_istr;  // משדר קלט
    std::ostream& m_ostr;  // משדר פלט



    std::optional<int> readOperationIndex() const;
    Action readAction() const;

    void runAction(Action action);

    ActionMap createActions() const;
    OperationList createOperations() const ;



private:
    void errAction();
};
