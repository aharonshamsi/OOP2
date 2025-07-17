#pragma once
#include <string>



namespace OutputConsts
{
	const std::string AVAILABLE_OPERATIONS = "List of available matrix operations:";
	const std::string ENTER_COMMAND = "Enter command ('help' for the list of available commands): ";
	const std::string HELP = 
        "The available commands are:\n"
        "* eval(uate) num n - compute the result of operation #num on all needed nªn matrices (that will be prompted)\n"
        "* scal(ar) val - creates an operation that multiplies the given matrix by scalar val\n"
        "* add num1 num2 - creates an operation that is the addition of the result of operation #num1 and the result of operation #num2\n"
        "* sub num1 num2 - creates an operation that is the subtraction of the result of operation #num1 and the result of operation #num2\n"
        "* comp(osite) num1 num2 - creates an operation that is the composition of operation #num1 and operation #num2\n"
        "* del(ete) num - delete operation #num from the operation list\n"
        "* help - print this command list\n"
        "* exit - exit the program";

	const std::string EXIT = "goodbye";
}