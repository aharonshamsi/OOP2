#include "FunctionManager.h"

FunctionManager::FunctionManager()
{
	m_functions.push_back(std::make_shared<IdOperation>(OperationTypes::Id));
	m_functions.push_back(std::make_shared<Transpose>(OperationTypes::Transpose));
}


void FunctionManager::runCalculator()
{
	std::string input;
	while (true)
	{
		printAll();
		std::cin >> input;
		OperationTypes option = inputManager(input);
		manageChoice(option);
		if (option == OperationTypes::Exit)
			break;
	}
}


void FunctionManager::printAll()
{
	std::cout << OutputConsts::AVAILABLE_OPERATIONS << std::endl;
	
	for (size_t i = 0; i < m_functions.size(); ++i)
	{
		std::cout << i << ". ";
		m_functions[i]->print();
		std::cout << std::endl;
	}

	std::cout << std::endl << OutputConsts::ENTER_COMMAND << std::endl;
}


OperationTypes FunctionManager::inputManager(const std::string& input)
{
	if (input == OperationNames::EVALUATE)
		return OperationTypes::Evaluate;
	else if (input == OperationNames::SCALAR)
		return OperationTypes::Scalar;
	else if(input == OperationNames::ADD)
		return OperationTypes::Add;
	else if (input == OperationNames::SUB)
		return OperationTypes::Sub;
	else if (input == OperationNames::COMPOSITE)
		return OperationTypes::Composite;
	else if (input == OperationNames::DELETE)
		return OperationTypes::Delete;
	else if (input == OperationNames::EXIT)
		return OperationTypes::Exit;
	else
		return OperationTypes::Help;
}


void FunctionManager::manageChoice(const OperationTypes option)
{
	
	switch (option)
	{
	case OperationTypes::Evaluate: {
		int funcNum;
		std::cin >> funcNum;
		if (funcNum >= m_functions.size())
			return;
		SquareMatrix matrix;
		m_functions[funcNum]->evaluate(matrix);
		std::cout << " = \n";
		matrix.print();
		break;
	}

	case OperationTypes::Scalar: {
		m_functions.push_back(std::make_shared<Scalar>(OperationTypes::Scalar));
		break;
	}

	case OperationTypes::Add: {
		int funcNum1, funcNum2;
		std::cin >> funcNum1 >> funcNum2;
		m_functions.push_back(std::make_shared<Add>(OperationTypes::Add, m_functions[funcNum1], m_functions[funcNum2]));
		break;
	}

	case OperationTypes::Sub: {
		int funcNum1, funcNum2;
		std::cin >> funcNum1 >> funcNum2;
		m_functions.push_back(std::make_shared<Sub>(OperationTypes::Sub, m_functions[funcNum1], m_functions[funcNum2]));
		break;
	}

	case OperationTypes::Composite: {
		int funcNum1, funcNum2;
		std::cin >> funcNum1 >> funcNum2;
		m_functions.push_back(std::make_shared<Composite>(OperationTypes::Composite, m_functions[funcNum1], m_functions[funcNum2]));
		break;
	}

	case OperationTypes::Delete: {
		int funcNum;
		std::cin >> funcNum;
		if(m_functions.size() && funcNum < m_functions.size())
			m_functions.erase(m_functions.begin() + funcNum);
		break;
	}
			
		case OperationTypes::Help:
			std::cout << OutputConsts::HELP << std::endl;
			break;

		case OperationTypes::Exit:
			std::cout << OutputConsts::EXIT << std::endl;
			break;
	}
}