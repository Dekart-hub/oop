#include <fstream>
#include <iostream>
#include <optional>
#include <string>

using namespace std;

struct Args
{
	string mode;
	string inputFile;
	string outputFile;
};

optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 4)
	{
		cout << "Invalid arguments count" << endl;
		cout << "Usage: RLE.exe <mode> <input file> <output file>" << endl;
		return nullopt;
	}
	Args args;
	args.mode = argv[1];
	args.inputFile = argv[2];
	args.outputFile = argv[3];
	return args;
}

int Unpack(ifstream& input, ofstream& output)
{
	char ch;
	while (input.get(ch))
	{
		unsigned char count;
		if (input.get(reinterpret_cast<char&>(count)))
		{
			for (unsigned i = 0; i < count; i++)
			{
				output << ch;
			}
		}
		else
		{
			return 0;
		}
	}

	return 1;
}

bool Pack(ifstream& input, ofstream& output)
{

	char ch0;
	char ch1;
	int counter = 0;
	if (input.get(ch0))
	{
		counter++;
	}
	else
	{
		return false;
	}
	while (input.get(ch1))
	{
		if (ch1 == ch0 && counter != 255)
		{
			counter++;
		}
		else
		{
			output << ch0 << (char)(counter);
			ch0 = ch1;
			counter = 1;
		}
	}

	if (counter != 0)
	{
		output << ch0 << (char)(counter);
	}

	return true;
}

bool Unnamed(string const& inputFile, string const& outputFile, string const& mode)
{
	ifstream input;
	ofstream output;
	//Open input
	input.open(inputFile);
	if (!input.is_open())
	{
		cout << "Failed to open '" << inputFile << "' for reading" << endl;
		return false;
	}

	//Open output
	output.open(outputFile);
	if (!output.is_open())
	{
		cout << "Failed to open '" << outputFile << "' for writing" << endl;
		return false;
	}

	if (mode == "pack")
	{
		return Pack(input, output);
	}
	else if (mode == "unpack")
	{
		return Unpack(input, output);
	}
	else
	{
		cout << "Incorrect mode" << endl;
		cout << "Usage: RLE.exe <mode> <input file> <output file>";
		return false;
	}

	//Close input
	if (input.bad())
	{
		cout << "Failed to read data from input file" << endl;
		return false;
	}

	//Close output
	if (!output.flush())
	{
		cout << "Failed to write data to output file" << endl;
		return false;
	}

	return true;
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return 1;
	}
	Unnamed(args->inputFile, args->outputFile, args->mode);
	return 0;
}