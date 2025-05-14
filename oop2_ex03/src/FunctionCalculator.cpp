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

FunctionCalculator::FunctionCalculator(std::ostream& ostr)
    : m_actions(createActions()),
      m_operations(createOperations()),
      m_ostr(ostr), m_readFormFile(false),
      m_maxSizeFunction(0), m_resizFunctions(0), m_numLine(0)
{}

//===================================================
void FunctionCalculator::run()
{
    try {
        ChooseNumFunctions();
    }
    catch (MessageException& exception) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        m_ostr << exception.what();
        run();
    }
    run(std::cin);
}

//===================================================
void FunctionCalculator::run(std::istream& istr)
{
    while (m_running) {

        try {

            m_ostr << '\n';
            if (m_readFormFile)
                m_numLine++;

            printOperations();  
            m_ostr << "Enter command ('help' for the list of available commands): ";
            const auto action = readAction(istr); 
            runAction(istr, action);
        }

        catch (MessageException& exception) {
            istr.clear();
            istr.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (m_readFormFile) {
                m_ostr << std::endl << std::endl << "Line " << m_numLine << ": " << exception.what();
                handleFileException();
            }
            else 
                m_ostr << exception.what();
        }

        catch (ManyArgumentsException& exception) {
            istr.clear();

            if (m_readFormFile) {
                m_ostr << std::endl << std::endl << "Line " << m_numLine << ": " << exception.what();
                handleFileException();
            }
            else
                m_ostr << exception.what();
        }

        catch (ResizeException& exception) {
            istr.clear();
            istr.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            m_ostr << std::endl << exception.what();
            updateNumOperation();
        }
       
    }
}

//=========================================================================
void FunctionCalculator::printOperations() const
{
    std::cout << "The number of functions remaining to add is: "
        << (m_maxSizeFunction - m_operations.size())
        << std::endl;

    m_ostr << "List of available matrix operations:\n";
    for (decltype(m_operations.size()) i = 0; i < m_operations.size(); ++i)
    {
        m_ostr << i << ". ";
        m_operations[i]->print(m_ostr, true);
        m_ostr << '\n';
    }
    m_ostr << '\n';
}


//===========================================================================
FunctionCalculator::Action FunctionCalculator::readAction(std::istream& istr)
{
    auto action = std::string();
    istr >> action;

    if (istr.eof()) {  // The file is finished recording.
        m_readFormFile = false;
        m_numLine = 0;
        run(std::cin);
    }

    const auto i = std::ranges::find(m_actions, action, &ActionDetails::command);
    if (i != m_actions.end())
    {
        return i->action;
    }

    return Action::Invalid;
}


//====================================================================
void FunctionCalculator::runAction(std::istream& istr, Action action)
{
    switch (action)
    {
    default:
        m_ostr << "Unknown enum entry used!\n";
        break;

    case Action::Invalid:
            throw MessageException("Error: The user entered an invalid command. \n"); 
        break;

    case Action::Eval:         eval(istr);                     break;
    case Action::Add:          binaryFunc<Add>(istr);          break;
    case Action::Sub:          binaryFunc<Sub>(istr);          break;
    case Action::Comp:         binaryFunc<Comp>(istr);         break;
    case Action::Del:          del(istr);                      break;
    case Action::Help:         help(istr);                         break;
    case Action::Exit:         exit(istr);                         break;
    case Action::Read:         readFromFile(istr);             break;
    case Action::Resize:       resizeSizeFunctions(istr);      break;
    //case Action::Iden:          unaryFunc<Identity>();      break;
    //case Action::Tran:          unaryFunc<Transpose>();      break;
    case Action::Scal:        unaryWithIntFunc<Scalar>(istr);  break;
    }
}


//============================================================================
void FunctionCalculator::eval(std::istream& istr)
{
    if (auto index = readOperationIndex(istr); index) // index זה מספר הפקודה
    {
        const auto& operation = m_operations[*index];
		int inputCount = operation->inputCount(); // מספר המטריצות שצריך להזין
        int size = 0;

        if (!(istr >> size))
            throw MessageException("Error: Please enter a numeric value for matrix size. \n");

        else if (size > MAX_MAT_SIZE)
            throw MessageException("Error: Matrix size must not exceed 5. \n");

        if (!checkArgumentSize(istr))
            throw ManyArgumentsException("Error: Too many arguments after operation index and size.\n");

        auto matrixVec = std::vector<Operation::T>(); 
        if (inputCount > 1)
            m_ostr << "\nPlease enter " << inputCount << " matrices:\n";

		for (int i = 0; i < inputCount; ++i)
		{
            auto input = Operation::T(size); 
            m_ostr << "Enter a " << size << "x" << size << " matrix:\n";
            readMatrix(istr, input, m_numLine);
			matrixVec.push_back(input);
		}

        if (!operation->isInAllowedRange(matrixVec))
            throw MessageException("Error: Matrix sum is out of allowed range. \n");

        m_ostr << "\n";
        operation->print(m_ostr, matrixVec);
        m_ostr << " = \n" << operation->compute(matrixVec);

    }
}


//============================================================================
std::optional<int> FunctionCalculator::readOperationIndex(std::istream& istr) const
{
    int i = 0;
    istr >> i; 

    if (i >= static_cast<int>(m_operations.size()) || i < 0 || istr.fail())
    {
        if (i >= static_cast<int>(m_operations.size()) || i < 0) {
            throw MessageException("Error: Operation number " + std::to_string(i) +" doesn't exist.\n");
        }

        else
            throw MessageException("Error: Operation index must be a number.\n");
    }
    return i;
}


//============================================================================
void FunctionCalculator::readFromFile(std::istream& istr)
{
    std::string path;
    istr >> path;

    std::ifstream file(path);
    if (!file.is_open())
        throw MessageException("Error: Could not open file.\n");

    m_readFormFile = true;
    m_numLine = 0;
    run(file); // Read form file
}

//============================================================================
void FunctionCalculator::del(std::istream& istr)
{
    if (auto i = readOperationIndex(istr); i)
    {
        m_operations.erase(m_operations.begin() + *i);
    }
}

//============================================================================
void FunctionCalculator::help(std::istream& istr)
{
    if (!checkArgumentSize(istr))
        throw ManyArgumentsException("Error: Too many arguments after operation index and size.\n");

    m_ostr << "The available commands are:\n";
    for (const auto& action : m_actions)
    {
        m_ostr << "* " << action.command << action.description << '\n';
    }
    m_ostr << '\n';
}

//============================================================================
void FunctionCalculator::exit(std::istream& istr)
{
    if (!checkArgumentSize(istr))
        throw ManyArgumentsException("Error: Too many arguments after operation index and size.\n");

    m_ostr << "Goodbye!\n";
    m_running = false;
}

FunctionCalculator::OperationList FunctionCalculator::createOperations() const
{
    return OperationList
    {
        std::make_shared<Identity>(),
        std::make_shared<Transpose>(),
    };
}

//============================================================================
void FunctionCalculator::ChooseNumFunctions()
{
    std::cout << "Please enter the maximum number of functions that can be stored in this program:\n";

    m_maxSizeFunction = 0;
    std::cin >> m_maxSizeFunction;

    if (m_maxSizeFunction > MAX_NUM_FUNCTIONS || m_maxSizeFunction < MINI_NUM_FUNCTIONS)
        throw MessageException(
            "Error: The number of functions must be between " + std::to_string(MINI_NUM_FUNCTIONS) +
            " and " + std::to_string(MAX_NUM_FUNCTIONS) + ".\n");
}

//============================================================================
void FunctionCalculator::handleFileException()
{
    m_ostr << "Continue reading? (y to continue, any other key to exit file mode.\n";
    std::string choseCommand;
    std::cin >> choseCommand;

    if (choseCommand != "y" && choseCommand != "Y") {
        m_readFormFile = false;
        run(std::cin);
    }
}

//============================================================================
void FunctionCalculator::updateNumOperation()
{
    std::string choseCommand;
    std::cin >> choseCommand;

    if (choseCommand == "y" || choseCommand == "Y") {
        m_maxSizeFunction = m_resizFunctions;
        m_operations.resize(m_resizFunctions);
    }
}

//============================================================================
bool FunctionCalculator::checkArgumentSize(std::istream& istr)
{
    std::string restOfLine;
    std::getline(istr, restOfLine);

    if (!restOfLine.empty() && restOfLine.find_first_not_of(" \t\r") != std::string::npos)
        return false;
    return true;
}

//============================================================================
void FunctionCalculator::resizeSizeFunctions(std::istream& istr)
{
    if (!(istr >> m_resizFunctions) || m_resizFunctions < 0)
        throw MessageException("Error: The number of functions you are trying to remove is invalid.\n");

    if (m_resizFunctions < m_operations.size())
        throw ResizeException(
           "Warning: You are trying to reduce the function capacity below the current number of functions.\n"
            "Confirm the change? (y to confirm, any other key to cancel)\n");

    m_maxSizeFunction = m_resizFunctions;
}

//============================================================================
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
            "read",
            " path - reads and executes commands from a file at the given path",
            Action::Read
        },
        {
            "resize",
            " resize - changes the maximum allowed number of functions in the calculator",
            Action::Resize
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

