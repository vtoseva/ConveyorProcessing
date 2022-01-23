#include "ifile.h"

// saves info from file in a vector
std::vector<double> readNumbers(std::fstream& numbers) {
	std::vector<double> nmb_vec;

	std::string buffer;

	while (getline(numbers, buffer)) {
		nmb_vec.push_back(stod(buffer));
	}

	return nmb_vec;
}

std::vector<double> readFunctions(std::fstream& functions) {
	std::vector<double> arg_vec;

	std::string buffer;

	//ignore operator get number
	while (getline(functions, buffer)) {
		if (buffer[0] == '>' || buffer[0] == '<') {
			buffer.erase(0, 2);
		}
		else buffer.erase(0, 1);

		arg_vec.push_back(stod(buffer));
	}

	return arg_vec;
}

std::vector<char> readOperators(std::fstream& functions) {
	std::vector<char> op_vec;

	std::string buffer;

	// seeks the beginning of the file
	functions.clear();
	functions.seekg(0, functions.beg);

	// get just the operator
	while (getline(functions, buffer)) {
		buffer.erase(1, buffer.size() - 1);

		std::copy(buffer.begin(), buffer.end(), std::back_inserter(op_vec));
	}

	return op_vec;
}