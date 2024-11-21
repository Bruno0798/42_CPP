#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // For std::exit

// Function to replace all occurrences of string1 with string2 in a line
void replaceString(std::string &line, const std::string &string1, const std::string &string2)
{
	size_t pos = 0;
	size_t string1Length = string1.length();

	// Find all occurrences of string1 in the line
	while ((pos = line.find(string1, pos)) != std::string::npos) {
		// Replace string1 with string2 by concatenation
		line = line.substr(0, pos) + string2 + line.substr(pos + string1Length);

		// Move past the replaced part to avoid infinite loop
		pos += string2.length();
	}
}

bool createFile(std::ofstream &outputFile)
{
	if (!outputFile.is_open()) {
		std::cerr << "Failed to create/open the file!" << std::endl;
		return false;
	}
	return true;
}

bool openFile(std::ifstream &readFile)
{
	if (!readFile.is_open()) {
		std::cerr << "Failed to open file!" << std::endl;
		return false;
	}
	return true;
}

int main(int argc, char **argv)
{
	if (argc != 4) {
		std::cout << "Wrong Arguments, filename, string1, and string2" << std::endl;
		return 1;
	}

	// Open the input file and the output file
	std::ofstream outputFile(argv[1]);
	std::string readFilename = std::string(argv[1]) + ".replace";
	std::ifstream readFile(readFilename);

	// Check if files are opened successfully
	if (!createFile(outputFile) || !openFile(readFile)) {
		return 1;
	}

	// Read and process each line
	std::string line;
	std::string string1 = argv[2]; // The string to replace
	std::string string2 = argv[3]; // The string to replace with

	while (getline(readFile, line)) {
		// Replace all occurrences of string1 with string2 in each line
		replaceString(line, string1, string2);

		// Write the modified line to the output file
		outputFile << line << std::endl;
	}

	// Close the files
	outputFile.close();
	readFile.close();

	return 0;
}
