#include <cassert>
#include <string>
#include <iostream>
#include <regex>

double calc(std::string expression)
{

    expression = std::regex_replace(expression, std::regex(" "), "");
    expression = std::regex_replace(expression, std::regex("--"), "+");

    std::cout << expression << std::endl;
    return 0;
}

int main(int argc, char const *argv[])
{
    assert(calc("10- 2- -5") == 13);
    assert(calc("1 + 1") == 2);
    assert(calc("8/16") == 0.5);
    assert(calc("3 -(-1)") == 4);
    assert(calc("2 + -2") == 0);

    assert(calc("(((10)))") == 10);
    assert(calc("3 * 5") == 15);
    assert(calc("-7 * -(6 / 3)") == 14);
    return 0;
}
