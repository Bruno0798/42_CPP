/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:53:07 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/11/25 15:50:13 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void replaceString(std::string &line, const std::string &string1, const std::string &string2)
{
	size_t pos = 0;
	size_t string1Length = string1.length();

	while ((pos = line.find(string1, pos)) != std::string::npos) {
		line = line.substr(0, pos) + string2 + line.substr(pos + string1Length);
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
	if (argc != 4 || *argv[1] == '\0' || *argv[2] == '\0' || *argv[3] == '\0')
	{
		std::cout << "Wrong Arguments, filename, string1, and string2" << std::endl;
		return 1;
	}


	std::string readFilename = argv[1];
	std::ifstream readFile(readFilename.c_str());
	if (!openFile(readFile)) {
		return 1;
	}

	std::string outputFilename = readFilename + ".replace";
	std::ofstream outputFile(outputFilename.c_str());
	if (!createFile(outputFile)) {
		return 1;
	}

	std::string line;
	std::string string1 = argv[2];
	std::string string2 = argv[3];

	while (getline(readFile, line)) {
		replaceString(line, string1, string2);
		outputFile << line << std::endl;
	}
	outputFile.close();
	readFile.close();

	return 0;
}