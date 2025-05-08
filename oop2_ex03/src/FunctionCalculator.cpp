#include "FunctionCalculator.h"
#include "SquareMatrix.h"
#include "Add.h"
#include "Sub.h"
#include "Comp.h"
#include "Identity.h"
#include "Transpose.h"
#include "Scalar.h"

#include <iostream>
#include <algorithm>


FunctionCalculator::FunctionCalculator(std::istream& istr, std::ostream& ostr)
    : m_actions(createActions()), m_operations(createOperations()), m_istr(istr), m_ostr(ostr)
{
}


// ================= שגיאה שם פקודה
void FunctionCalculator::run()
{
    do
    {
        try {
            m_ostr << '\n';
            printOperations();  // הדפסת הפונקצית הפעילות
            m_ostr << "Enter command ('help' for the list of available commands): ";
            const auto action = readAction(); // מחזיר enum פקודה

            // אם קבלתי 
            if (action == Action::Invalid)
                throw MessageException("Error: The user entered an invalid command. \n");

            runAction(action);
        }
        catch (MessageException& exception) {
            m_istr.clear();
            m_istr.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            m_ostr << exception.what();
        }

    } while (m_running);
}


void FunctionCalculator::eval()
{
    if (auto index = readOperationIndex(); index) // index זה מספר הפקודה
    {
        const auto& operation = m_operations[*index];
		int inputCount = operation->inputCount();
        int size = 0;

        if (!(m_istr >> size))
            throw MessageException("Error: Please enter a numeric value for matrix size. \n");

        else if (size > MAX_MAT_SIZE)
            throw MessageException("Error: Matrix size must not exceed 5. \n");


        //// בדיקה שאין עודף ארגומנטים
        //// צריך לטפל בפונקציה זו, ראה דוגמה במצגת
        //if (!(m_istr >> std::ws).eof())
        //    throw MessageException("Error: Too many arguments after operation index and size.\n");


        //============
        auto matrixVec = std::vector<Operation::T>(); // וקטור של מטריצות דו 
        if (inputCount > 1)
            m_ostr << "\nPlease enter " << inputCount << " matrices:\n";

		for (int i = 0; i < inputCount; ++i)
		{
            auto input = Operation::T(size); // קולט ערכים למטריצה דו מימידית
            m_ostr << "\nEnter a " << size << "x" << size << " matrix:\n";
            m_istr >> input;
			matrixVec.push_back(input);

		}

        // בדיקה שסכום המטריצה אינו עובר את הערכים 1000 -1024
        if (!operation->isInAllowedRange(matrixVec))
            throw MessageException("Error: Matrix sum is out of allowed range. \n");

        
        m_ostr << "\n";
        operation->print(m_ostr, matrixVec);
        m_ostr << " = \n" << operation->compute(matrixVec);

    }
}


void FunctionCalculator::del()
{
    if (auto i = readOperationIndex(); i)
    {
        m_operations.erase(m_operations.begin() + *i);
    }
}


void FunctionCalculator::help()
{
    m_ostr << "The available commands are:\n";
    for (const auto& action : m_actions)
    {
        m_ostr << "* " << action.command << action.description << '\n';
    }
    m_ostr << '\n';
}


void FunctionCalculator::exit()
{
    m_ostr << "Goodbye!\n";
    m_running = false;
}


void FunctionCalculator::printOperations() const
{
    m_ostr << "List of available matrix operations:\n";
    for (decltype(m_operations.size()) i = 0; i < m_operations.size(); ++i)
    {
        m_ostr << i << ". ";
        m_operations[i]->print(m_ostr,true);
        m_ostr << '\n';
    }
    m_ostr << '\n';
}


// ================= שגיאה מספר פקודה
std::optional<int> FunctionCalculator::readOperationIndex() const
{
    int i = 0;
    m_istr >> i; // הזנת מספר הפקודה

    if (i >= static_cast<int>(m_operations.size()) || i < 0 || m_istr.fail())
    {
        //return {};

        if (i >= static_cast<int>(m_operations.size())) {
            m_ostr << "Operation #" << i << " doesn't exist\n";
            throw MessageException("Error: Operation number not found.\n");
        }

        else if (i < 0) {
            m_ostr << "Operation #" << i << " doesn't exist\n";
            throw MessageException("Error: Operation index cannot be negative.\n");
        }

        else
            throw MessageException("Error: Operation index must be a number.\n");
    }
    return i;
}


FunctionCalculator::Action FunctionCalculator::readAction() const
{
    auto action = std::string();
    m_istr >> action;

    const auto i = std::ranges::find(m_actions, action, &ActionDetails::command);
    if (i != m_actions.end())
    {
        return i->action;
    }

    return Action::Invalid;
}


void FunctionCalculator::runAction(Action action)
{
    switch (action)
    {
        default:
            m_ostr << "Unknown enum entry used!\n";
            break;

        case Action::Invalid:
            m_ostr << "Command not found\n";
            break;

        case Action::Eval:         eval();                     break;
        case Action::Add:          binaryFunc<Add>();          break;
        case Action::Sub:          binaryFunc<Sub>();          break;
        case Action::Comp:         binaryFunc<Comp>();         break;
        case Action::Del:          del();                      break;
        case Action::Help:         help();                     break;
        case Action::Exit:         exit();                     break;
        //case Action::Iden:          unaryFunc<Identity>();      break;
        //case Action::Tran:          unaryFunc<Transpose>();      break;
        case Action::Scal:          unaryWithIntFunc<Scalar>();      break;
    }
}


FunctionCalculator::ActionMap FunctionCalculator::createActions() const
{
    return ActionMap
    {
        {
            "eval",
            "(uate) num n - compute the result of function #num on an n×n matrix "
			"(that will be prompted)",
            Action::Eval
        },
        {
            "scal",
            "(ar) val - creates an operation that multiplies the "
			"given matrix by scalar val",
            Action::Scal
        },
        {
            "add",
            " num1 num2 - creates an operation that is the addition of the result of operation #num1 "
			"and the result of operation #num2",
            Action::Add
        },
         {
            "sub",
            " num1 num2 - creates an operation that is the subtraction of the result of operation #num1 "
			"and the result of operation #num2",
            Action::Sub
        },
        {
            "comp",
            "(osite) num1 num2 - creates an operation that is the composition of operation #num1 "
			"and operation #num2",
            Action::Comp
        },
        {
            "del",
            "(ete) num - delete operation #num from the operation list",
            Action::Del
        },
        {
            "help",
            " - print this command list",
            Action::Help
        },
        {
            "exit",
            " - exit the program",
            Action::Exit
        }
    };
}


FunctionCalculator::OperationList FunctionCalculator::createOperations() const
{
    return OperationList
    {
        std::make_shared<Identity>(),
        std::make_shared<Transpose>(),
    };
}

// ==== All Erorr  
void FunctionCalculator::errAction()
{
}
