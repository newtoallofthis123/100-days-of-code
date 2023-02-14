// Calculator with command line arguments in c
// Usage: calc <Operator> <Nums>
// Author: NoobScience

// <START>

// Imports
#include <stdio.h>
#include <stdlib.h>

// Main function has arguments argc for number of arguments and
// argv is a char list that stores arguments in the form of strings
// This is a double pointer of form **argv
int main(int argc, char *argv[]){
    // If arguments are less than 4, then print usage and exit
    // 4 arguments has <program> <operator> and Minimum of two numbers
    if(argc < 4){
        printf("Usage: <operator> *<nums>");
        return -1;
    }
    // Else proceed
    else{
        // Get operator from first argument
        char op = argv[1][0];
        // Get number of arguments
        int n = argc - 2;
        // Create an array of size n
        int nums[20];
        // Convert arguments to integers and store in nums
        for(int i = 0; i < n; i++){
            nums[i] = atoi(argv[i+2]);
        }
        // Perform operation
        int result = nums[0];
        for(int i = 1; i < n; i++){
            switch(op){
                case '+':
                    result += nums[i];
                    break;
                case '-':
                    result -= nums[i];
                    break;
                case '*':
                    result *= nums[i];
                    break;
                case '/':
                    result /= nums[i];
                    break;
                default:
                    printf("Invalid operator");
                    return -1;
            }
        }
        // Print result with some color formatting
        // Print the logo to make it look cool
        printf(
            "\033[1;31m _____       _            _       _\033[0m\n"
            "\033[1;31m/  __ \\     | |          | |     | |\033[0m\n"
            "\033[1;31m| /  \\/ __ _| | ___ _   _| | __ _| |_ ___  _ __\033[0m\n"
            "\033[1;31m| |    / _` | |/ __| | | | |/ _` | __/ _ \\| '__|\033[0m\n"
            "\033[1;31m| \\__/\\ (_| | | (__| |_| | | (_| | || (_) | |\033[0m\n"
            "\033[1;31m\\_____/\\__,_|_|\\___|\\__,_|_|\\__,_|\\__\\___/|_|\033[0m\n\n");
        printf("\033[1;34mResult of Operation %c on numbers: \033[0m\n", op);
        for (int i = 1; i < n-1;i++){
            printf("\033[1;33m%d \033[0m", nums[i]);
            printf("\033[1;31m%c \033[0m", op);
        }
        printf("\033[1;33m%d\033[0m \033[1;35m=\033[0m \033[1;32m%d\033[0m", nums[n - 1], result);
        return 0;
    }
}

// <END>