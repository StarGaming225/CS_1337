#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for EXIT_FAILURE
#include <string.h> // Include string.h for strlen function

// Checks to see if operator is valid
int validateOperator(char op) {
    	return op == '|' || op == '&' || op == '^' || op == 'q';
}

// Checks to see if operator / integer amount is more than one cause you can't get anywhere without two numbers
int validateOperandCount(int count) {
    	return count > 1;
}

// Checks to validate hexadecimal integers
int validateHexInteger(char* input) {
	// Check if input length (excluding null terminator) is within the range [1, 8]
    	size_t length = strlen(input);
    	if (length < 1 || length > 8)
        	return 0;

	// Iterate through each character in the input string
    	for (int i = 0; i < strlen(input); i++) {
        	// Check if the character is a valid hexadecimal digit
        	if (!((input[i] >= '0' && input[i] <= '9') || (input[i] >= 'A' && input[i] <= 'F') || (input[i] >= 'a' && input[i] <= 'f'))) {
            		return 0; // Return false if any character is not a valid hexadecimal digit
        	}
    	}
    	return 1;
}

// Function to convert an integer to its binary representation
void printBinary(unsigned int num) {
    	for(int i = 31; i >= 0; i--) {
        	printf("%d", (num >> i) & 1);
        	if(i % 8 == 0) printf(" "); // Add a space every 8 bits for clarity
    	}
}

// Main function
int main() {
    	char operator;
    	int operandCount;

    	// Prompt user for operator
    	do {
        	printf("Enter operation: ");
        	scanf(" %c", &operator);
        	while (getchar() != '\n'); // Clear input buffer

        	if (!validateOperator(operator)) {
            		printf("Please enter |, &, ^, or q\n");
        	}
    	} while (!validateOperator(operator));

    	if (operator == 'q') {
    	    	return 0;
    	}

    	// Prompt user for operand count
    	do {
        	printf("Enter number of integers: ");
        	scanf("%d", &operandCount);
        	while (getchar() != '\n'); // Clear input buffer

        	if (!validateOperandCount(operandCount)) {
            		printf("Please enter an integer greater than 1\n");
        	}
    	} while (!validateOperandCount(operandCount));

    	// Array to store hexadecimal integers
    	unsigned int operands[operandCount];

    	// Prompt user for hexadecimal operands
    	for (int i = 0; i < operandCount; i++) {
        	char hexInput[1000]; // Buffer for input
        	do {
            		printf("Enter integer %d: ", i + 1);
            		fgets(hexInput, sizeof(hexInput), stdin); // Read input
            		if (hexInput[strlen(hexInput) - 1] == '\n') // Remove newline character
                		hexInput[strlen(hexInput) - 1] = '\0';

            		if (!validateHexInteger(hexInput)) {
                		printf("Please enter a valid 8-digit hexadecimal integer\n");
        	    	}
        	} while (!validateHexInteger(hexInput));
        	sscanf(hexInput, "%X", &operands[i]); // Convert input to integer
	}

    	// Perform the calculation
    	unsigned int result = operands[0]; // Initialize result with first operand
    	switch (operator) {
        	case '|':
            		for (int i = 1; i < operandCount; i++) {
                		result |= operands[i];
            		}
            	break;
        	case '&':
            		for (int i = 1; i < operandCount; i++) {
                		result &= operands[i];
            		}
            	break;
        	case '^':
            		for (int i = 1; i < operandCount; i++) {
                		result ^= operands[i];
            		}
            	break;
    	}

    	// Display the result in hexadecimal and binary
    	printf("Hexadecimal operation:\n");
    	for (int i = 0; i < operandCount; i++) {
        	printf("%08X\n%c ", operands[i], (i == operandCount - 1) ? operator : ' ');
    	}
    	printf("= %08X\n", result);

    	printf("Binary operation:\n");
    	for (int i = 0; i < operandCount; i++) {
        	printBinary(operands[i]); // Print binary representation
        	printf("%c \n", (i == operandCount - 1) ? operator : ' ');
    	}
    	printBinary(result); // Print binary representation of the result
    	printf("\n");

    	return 0;
}
