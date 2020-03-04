
#include <iostream>
#include <optional>
#include <string>

std::optional<uint8_t> ParseArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid arguments count\n";
		std::cout << "Usage: flipbyte.exe <input number>\n";
		return std::nullopt;
	}

	int temp;

	try
	{
		temp = std::stoi(argv[1]);
	}
	catch (const std::exception&)
	{
		std::cout << "Incorrect number\n";
		return std::nullopt;
	}
	
	if (temp > 255 || temp < 0)
	{
		std::cout << "<input number> must be in range of 0..255\n";
		return std::nullopt;
	}
	return temp;
}

uint8_t FlipByte(uint8_t byte)
{
	byte = (byte & 0x55) << 1 | (byte & 0xAA) >> 1;
	byte = (byte & 0x33) << 2 | (byte & 0xCC) >> 2;
	byte = (byte & 0x0F) << 4 | (byte & 0xF0) >> 4;
	return byte;
}

int main(int argc, char* argv[])
{
	uint8_t arg;

	try
	{
		arg = ParseArgs(argc, argv).value();
	}
	catch (const std::bad_optional_access&)
	{
		return 1;
	}
	printf("%d\n", FlipByte(arg));
	return 0;
}