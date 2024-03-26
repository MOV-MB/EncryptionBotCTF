#include <iostream>
#include <string>

int charToDecimal(char c)
{
    const std::string charset = "RSTUVWXYZ0123456789ABCDEFGHIJKLMNOPQabcdefghijklmnopqrstuvwxyz";
    return charset.find(c);
}

std::string decimalToBinary(int decimal)
{
    std::string binary;
    for (int i = 0; i < 6; ++i) {
        binary = static_cast<char>(decimal % 2 + '0') + binary;
        decimal /= 2;
    }
    return binary;
}

char binaryToChar(const std::string &binary)
{
    int decimal = 0;

    for (const char bit : binary) {
        decimal = decimal * 2 + (bit - '0');
    }
    return static_cast<char>(decimal);
}

int main()
{
	const std::string encoded = "9W8TLp4k7t0vJW7n3VvMCpWq9WzT3C8pZ9Wz";

    std::string binary;

    for (char c : encoded)
    {
        binary += decimalToBinary(charToDecimal(c));
    }

    std::string originalText;

    for (size_t i = 0; i < binary.length(); i += 8) 
    {
        originalText += binaryToChar(binary.substr(i, 8));
    }

    std::cout << originalText << '\n';

    return 0;
}
