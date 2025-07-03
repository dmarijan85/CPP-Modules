#include "RPN.hpp"
#include <iostream>
#include <cstdlib>

void testRPN(const std::string& expression) {
    RPN calculator;
    try {
        double result = calculator.processRPN(expression);
        std::cout << "Expression: " << expression << " = " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc == 2) {
        // If an argument is provided, use it as the RPN expression
        testRPN(argv[1]);
        return 0;
    }

    // Test cases
    std::cout << "Running predefined tests..." << std::endl << std::endl;

    // Basic operations
    testRPN("2 3 +");        // 5
    testRPN("5 2 -");        // 3
    testRPN("3 4 *");        // 12
    testRPN("10 5 /");       // 2
    testRPN("10 3 /");       // ~3.333

    // Multiple operations
    testRPN("3 4 + 5 *");    // (3+4)*5 = 35
    testRPN("5 1 2 + 4 * +"); // 5 + (1+2)*4 = 17
    testRPN("15 7 1 1 + - / 3 * 2 1 1 + + -"); // ((15 / (7 - (1 + 1))) * 3) - (2 + (1 + 1)) = 5

    // Edge cases
    testRPN("42");           // 42
    testRPN("0 0 +");        // 0
    testRPN("1 0 /");        // Should throw (division by zero)
    testRPN("1.5 2.5 +");    // 4.0

    // Invalid expressions
    testRPN("");             // Empty
    testRPN("1 +");          // Missing operand
    testRPN("1 2 3 +");      // Too many numbers
    testRPN("1 2 + 3");      // Number at the end
    testRPN("a b +");        // Invalid characters
    testRPN("1 2 ++");       // Too many operators
    testRPN("+ 1 2");        // Operator first
    testRPN("-3 -2 *");      // Can't handle negatives

    return 0;
}
