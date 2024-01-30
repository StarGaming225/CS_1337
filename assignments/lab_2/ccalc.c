#include <stdio.h>

int validateOperator(char op) {
	return op == '+' || op == '-' || op == '*' || op == '/';
}

int validateOperandCount(int count) {
	return count > 1;
}

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

int main() {
	char operator;
	int operandCount, result = 0;

	while (1) {
		printf("Enter Operation: ");
		scanf(" %c", &operator);

		if (operator == 'q') {
			break;
		} else if (!validateOperator(operator)) {
			printf("Enter a Valid Operation!! (+,-,*,/):\n");
			continue;
		}

		printf("Enter number of integers: ");
		scanf("%d", &operandCount);

		if (!validateOperandCount(operandCount)) {
			printf("Please enter an integer greater than 1\n");
			continue;
		}

		int operands[operandCount];
		printf("Enter integer 1: ");
		for (int i = 0; i < operandCount; i++) {
			if (scanf("%d", &operands[i]) != 1) {
                                printf("Please enter an integer\n");
                                printf("Enter integer %d:", i+1);
                                i--;
                                continue;
                        }
                }


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

		printf("COMPUTING... *BEEP* *BOOP* %d %c ", operands[0], operator);
		for (int i=1;i<operandCount;i++) {
			printf("%d %c ", operands[i], (i == operandCount -1) ? '=' : operator);
		}
		printf("%d\n", result);
	}

	return 0;
}




