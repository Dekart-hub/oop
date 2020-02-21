#include <iostream>
#include <fstream>
#include <optional>
#include <string>

struct Args
{
	std::string inputFileName;
	std::string outputFileName;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Invalid arguments count\n";
		std::cout << "Usage: CopyFile.exe <input file name> <output file name>\n";
		return std::nullopt;
	}
	Args args;
	args.inputFileName = argv[1];
	args.outputFileName = argv[2];
	return args;
}

void CopyFile(std::ifstream& input, std::ofstream& output)
{
	char ch;
	while (input.get(ch))
	{
		if (!output.put(ch))
		{
			break;
		}
	}
}

bool CopyFile(std::string const& inputFile, std::string const& outputFile)
{

	std::ofstream output;
	std::ifstream input;

	//Open input file

	input.open(inputFile);
	if (!input.is_open())
	{
		std::cout << "Failed to open '" << inputFile << "' for reading\n";
		return 0;
	}

	// Open output file

	output.open(outputFile);
	if (!output.is_open())
	{
		std::cout << "Failed to open '" << outputFile << "' for writing\n";
		return 0;
	}

	// Copying files
	CopyFile(input, output);

	// close input
	if (input.bad())
	{
		std::cout << "Failed to read data from input file\n";
		return 0;
	}


	//Close output
	if (!output.flush())
	{
		std::cout << "Failed to write data to output file\n";
		return 0;
	}

	return 1;
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	// Check arguments
	if (!args)
	{
		return 1;
	}

	return !CopyFile(args->inputFileName, args->outputFileName);
}