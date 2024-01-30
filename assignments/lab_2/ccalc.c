#include <stdio.h>

// Checks to see if operator is valid
int validateOperator(char op) {
	return op == '+' || op == '-' || op == '*' || op == '/';
}

// Checks to see if operator / integer amount is more than one cause you can't get anywhere without two numbers
int validateOperandCount(int count) {
	return count > 1;
}

// Checks to see if the user is trying to divide by zero
int validateOperands(int operands[], int count, char op) {
	if (op == '/') {
		for (int i=1; i<count; i++) {
			if (operands[i] == 0) {
				printf("C'mon! You know you can't Divide by Zero dude! \n");
				return 0;
			}
		}
	}
	return 1;
}

// Main function
int main() {
	char operator;
	int operandCount, result = 0;

	while (1) {
		// Starting Operation input
		printf("Enter Operation: ");
		scanf(" %c", &operator);

		if (operator == 'q') {
			break;
		} else if (!validateOperator(operator)) {
			printf("Enter a Valid Operation!! (+,-,*,/):\n");
			continue;
		}

		// Choosing how many integers to combine with the selected operation imput
		printf("Enter number of integers: ");
		scanf("%d", &operandCount);

		if (!validateOperandCount(operandCount)) {
			printf("Please enter an integer greater than 1\n");
			continue;
		}

		//Entering the selected amount of integers
		int operands[operandCount];
		printf("Enter integer 1: ");
		for (int i = 0; i < operandCount; i++) {
			if (scanf("%d", &operands[i]) != 1) {
                                i--;
                                continue;
                        }
                }

		//Doing the mathmatical calculations
		if (!validateOperands(operands, operandCount, operator)) {
			continue;
		}

		switch (operator) {
			case '+':
				result = operands[0];
				for (int i = 1; i< operandCount; i++) {
					result += operands[i];
				}
				break;
			case '-':
				result = operands[0];
				for (int i = 1; i< operandCount; i++) {
                                        result -= operands[i];
                                }
				break;
			case '*':
				result = operands[0];
				for (int i = 1; i< operandCount; i++) {
                                        result *= operands[i];
                                }
				break;
			case '/':
				result = operands[0];
				for (int i = 1; i< operandCount; i++) {
                                        result /= operands[i];
                                }
				break;
		}

		//Presenting the problem and solution
		printf("COMPUTING... *BEEP* *BOOP* %d %c ", operands[0], operator);
		for (int i=1;i<operandCount;i++) {
			printf("%d %c ", operands[i], (i == operandCount -1) ? '=' : operator);
		}
		printf("%d\n", result);
	}

	return 0;
}




