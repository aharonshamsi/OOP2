#include "Operation.h"

#include <iostream>


void Operation::print(std::ostream& ostr, const std::vector<T>& input) const
{
	print(ostr);
	for (int i = 0; i < inputCount(); ++i)
	{
		ostr << "(\n" << input[i] << ")";
	}
}

bool Operation::isInAllowedRange(const std::vector<T>& input)
{
    const auto resultMatrix = compute(input);

    for (int i = 0; i < resultMatrix.size(); i++) {
        for (int j = 0; j < resultMatrix.size(); j++) {
            if ((resultMatrix(i, j) > MAX_ALLOWED_VALUE ||
                resultMatrix(i, j) < MIN_ALLOWED_VALUE)) {
                return false;
            }
        }
    }
    return true;
}
