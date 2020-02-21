#include <iomanip>
#include <iostream>

using namespace std;

class calculator {
public:
    void initialise();

    void display_result();

private:
    float get_valid_operand(const char *prompt);

    void get_valid_operator(char &character);

protected:
    float operand_1;
    float operand_2;
    char arithmetic_operator;
};

void calculator::initialise() {
    operand_1 = get_valid_operand("Enter first operand");
    operand_2 = get_valid_operand("Enter second operand");
    get_valid_operator(arithmetic_operator);
}

float calculator::get_valid_operand(const char *prompt) {
    float operand;
    char terminator;
    do {
        std::cout << prompt;
        std::cin >> operand;
    } while (operand == 0);
    std::cin.get(terminator);
    return operand;
}

void calculator::get_valid_operator(char &character) {
    char terminator;
    do {
        std::cout << "Enter the operator: ";
        std::cin.get(character);
        std::cin.get(terminator);
    } while (!((character == '+') || (character == '-') || (character == '*') || (character == '/')));
};

void calculator::display_result() {
    float result;
    switch(arithmetic_operator) {
        case '+': result = operand_1 + operand_2;
            break;
        case '-': result = operand_1 - operand_2;
            break;
        case '*': result = operand_1 * operand_2;
            break;
        case '/': result = operand_1 / operand_2;
            break;
    }
    std::cout << operand_1 << " " << arithmetic_operator << " " << operand_2 << " = " << setprecision(3) << result << std::endl;
}