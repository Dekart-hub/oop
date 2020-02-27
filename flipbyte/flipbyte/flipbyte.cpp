
#include <iostream>
#include <optional>
#include <string>

struct Args
{
	int inNum;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid arguments count\n";
		std::cout << "Usage: flipbyte.exe <input number>\n";
		return std::nullopt;
	}
	Args args;
	try
	{
		args.inNum = std::stoi(argv[1]);
	}
	catch (std::exception&)
	{
		std::cout << "Incorrect number\n";
		return std::nullopt;
	}
	return args;
}


int FlipByte(int byte)
{
	byte = (byte & 0x55) << 1 | (byte & 0xAA) >> 1;
	byte = (byte & 0x33) << 2 | (byte & 0xCC) >> 2;
	byte = (byte & 0x0F) << 4 | (byte & 0xF0) >> 4;
	return byte;
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return 1;
	}


	if ((args->inNum > 255) || (args->inNum < 0))
	{
		std::cout << "<input number> must be in range of 0..255\n";
		return 1;
	}

	std::cout << FlipByte(args->inNum) << "\n";

	return 0;
}