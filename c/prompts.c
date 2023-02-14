// <Archived>

// These are just improvements to the standard prompts.

#include <stdio.h>
#include <stdlib.h>

// Main function has arguments argc for number of arguments and
// argv is a char list that stores arguments in the form of strings
// This is a double pointer of form **argv

int main(int argc, char *argv[]){
    if(argc < 3){
        printf("Usage: <prompt Type in Int> '<prompt>'");
    }
    else{
        int option= atoi(argv[1]);
        char *prompt[] = argv[3];
        switch(option){
            case 1:
            printf("Choosen prompt type: %d is question prompt", prompt);
            printf("%c", *prompt);
            break;
        }
    }
    return 0;
}