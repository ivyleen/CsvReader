#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <string>
#include <sstream> // std::stringstream
#include <iomanip> // std::setprecision
#include <algorithm>


uint64_t calculateMaxOfColumn(const std::vector<uint64_t> &vec)
{
	// C++11 and higher - using operator<.
	return *std::max_element(vec.begin(), vec.end());
}

uint64_t calculateSum(const std::vector<uint64_t> &vec)
{
	// C++11 and higher - using operator+ under the hood from left to right, initial value - 0
	return std::accumulate(vec.begin(), vec.end(), 0);

	// C++17 and higher - doesn't guarantee any order, initial value to the default constructed value of the underlying type
	//return std::reduce(vec.begin(), vec.end());
}


void printColumns(const std::vector<std::pair<std::string, std::vector<uint64_t>>> &columns)
{
}

void printSumOfEachColumns(const std::vector<std::pair<std::string, std::vector<uint64_t>>> &columns)
{
	// Do nothing with an empty table...
	if (columns.begin() == columns.end()) { return; }

	for (const auto &pair : columns)
	{
		std::cout << std::left << std::setw(12) << pair.first << " ";
	}

	std::cout << std::endl;

	for (const auto &pair : columns)
	{
		std::cout << std::right << std::setw(5) << calculateSum(pair.second) << std::setw(7) << " ";
	}
	
	std::cout << "\n\n";
}

void printTheMaximumOfEachColumns(const std::vector<std::pair<std::string, std::vector<uint64_t>>> &columns)
{
	// Do nothing with an empty table...
	if (columns.begin() == columns.end()) { return; }

	for (const auto &pair : columns)
	{
		std::cout << std::left << std::setw(12) << pair.first << " ";
	}

	std::cout << std::endl;

	for (const auto &pair : columns)
	{
		std::cout << std::right << std::setw(5) << calculateMaxOfColumn(pair.second) << std::setw(7) << " ";
	}

	std::cout << "\n\n";
}

void printSumOfAllRows(const std::vector<std::pair<std::string, std::vector<uint64_t>>> &columns)
{
}

int main(int argc, char *argv[])
{
	switch (argc)
	{
		case 2:
			std::cout << "You've only entered the chosen file, please add the option after. Find available options with h option.\n";
			return 0;

		case 3:
			if (*argv[2] == 'h')
			{
				std::cout << "You've asked for help. Available options are:\n"
					"'p': print the contents of all columns\n"
					"'+': print the sum of all columns\n"
					"'m' : print the maximum of all columns\n"
					"'a' : add each row together and print a single column containing the result.\n"
					"'h' : display available options";
				return 0;
			}
			else if ((*argv[2] == 'p') || (*argv[2] == '+') || (*argv[2] == 'm') || (*argv[2] == 'a'))
			{
				break;
			}
			else
			{
				std::cout << "Please restart the program and pass a valid option." << std::endl;
			}
			return -1;

		default:
			std::cout << "Please restart the program and pass a filename as argument and a option to process the file." << std::endl;
			return -1;
	}

	std::ifstream file(argv[1]);

	if (!file)
	{
		std::cout << "Error in opening the file." << std::endl;
		return -1;
	}

	if (file.is_open() && file.good())
	{
		// Read from file.

		// The container for all values.
		std::vector<std::pair<std::string, std::vector<uint64_t>>> columns;

		// Get all the names of the colums.
		std::string line, colname;
		getline(file, line);

		// Create a stringstream from line to be able to parse them.
		std::stringstream ss(line);

		// Extract each column name.
		while (std::getline(ss, colname, ' ')) {

			// Initialize and add <colname, int vector>.
			columns.push_back({ colname, std::vector<uint64_t>{} });
		}

		// Get all the values in the columns.
		uint64_t val = 0;
		// For each line..
		while (std::getline(file, line))
		{
			// 
			std::stringstream ss(line);

			// Keep track of the current column index.
			uint64_t colIdx = 0;

			// Extract each uint64_teger.
			while (ss >> val)
			{
				// Add the current uint64_teger to the 'colIdx' column's values vector.
				columns.at(colIdx).second.push_back(val);

				// If the next token is a comma, ignore it and move on.
				if (ss.peek() == ' ') ss.ignore();

				// Increment the column index.
				colIdx++;
			}
		}

		switch (*argv[argc - 1])
		{
			case 'p':
				std::cout << "Option 'p': print the contents of all columns." << std::endl;
				printColumns(columns);
				break;

			case '+':
				std::cout << "Option '+': print the sum of all columns." << std::endl;
				printSumOfEachColumns(columns);
				break;

			case 'm':
				std::cout << "Option 'm': print the maximum of all columns." << std::endl;
				printTheMaximumOfEachColumns(columns);
				break;

			case 'a':
				std::cout << "Option 'a': add each row together and print a single column containing the result." << std::endl;
				printSumOfAllRows(columns);
				break;

			default:
				// It shouldn't come to this.
				break;
		}
	}

	file.close();

	return 0;
}
