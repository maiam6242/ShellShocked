// HK and Maia
#include <unistd.h>
#include <stdio.h>
void main(){
    // Should initialize the shell and read, parse and execute for each functionality we hope to include
}

int changeDirectory(char* args[]){
    /* 
    Should move to home if no argument, if directory exists, go to that directory, else output an error. Use chdir to change directories
    Args: either the directory that should be changed to or blank for home
    Returns: 1 if successful, -1 if not 
    */

    // Check if we need to handle cases dealing with implicit vs absolute path
}

char* readInput(){
    /*
    Should read the input from the user and put in into a dynamically allocated buffer, which will then be parsed
    Returns: A pointer to a string which was input by a user
    */
}

char** parseInput() {
    /*
    Check the input against the command in the command table and any options
    */
}

struct Command {
    // 
}Command;

