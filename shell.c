// HK and Maia
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define LSH_TOK_BUFSIZE 64
// delimiter: tab, carriage return, end of line, system bell
#define LSH_TOK_DELIM " \t\r\n\a"
void main(){
    // Should initialize the shell and read, parse and execute for each functionality we hope to include
}

int changeDirectory(char* args[]){
    /* 
    Should move to home if no argument, if directory exists, go to that directory, else output an error. Use chdir to change directories
    Args: either the directory that should be changed to or blank for home
    Returns: 0 if successful, -1 if not 
    */
    if(args == NULL){
      perror("Args are null! Can't change directory");
      return -1;
    }
    else if (chdir(args[1])!= 0){
      perror("Sorry some sort of error with cd");
      return -1;
    }
    else 
      return chdir(args[1]);

    // Check if we need to handle cases dealing with implicit vs absolute path
}

void printDirectory(){
    /*
    This should print the current working directory.
    */
    char cwd[1024]; 
    getcwd(cwd, sizeof(cwd)); 
    printf("\nDir: %s", cwd);
}

int listFiles(char* args[]){
  /*
  This should list all of the files in the current 

  */
}

int makeDirectory(char* args[]){
  /*
  Make a directory with the name given as an arg, if no name given or other error present, return -1, else return 0
  */

  int failed = mkdir(args[0]);

  if(!failed){
    printf("Worked!");
    return 0;
  }
  else
    perror("Couldn't create directory");
    return -1;
}


char* readInput(){
    /*
    Should read the input from the user and put in into a dynamically allocated buffer, which will then be parsed
    Returns: A pointer to a string which was input by a user
    */
    int buffer_size = LSH_TOK_BUFSIZE;
    int location = 0; 
    int ch = 0; // getchar() returns an ASCII value
    char *buffer = malloc(sizeof(char) * buffer_size);

    while(1):
      ch = getchar();
      
      // when reach the end of input
      if (ch == EOF || ch == '\n') {
        buffer[location] = '\0';
        return buffer;
      } else {
        buffer[location] = ch;
      }
      location++;
      
      // when input goes over allocated buffer
      if (location >= buffer_size) {
        buffer_size += LSH_TOK_BUFSIZE;
        buffer = realloc(buffer, buffer_size);
      }
}

char** parseInput() {
    /*
    Check the input against the command in the command table and any options
    */


}
char **lsh_split_at_pipe(char *line)
/*
Split given line into tokens with delimiter '|' 
*/
{
  int bufsize = LSH_TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  if (!tokens) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(1);
  }

  token = strtok(line, "|");
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += LSH_TOK_BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(1);
      }
    }

    token = strtok(NULL, LSH_TOK_DELIM);
  }
  tokens[position] = NULL;
  for(int i = 0; i < sizeof tokens / sizeof tokens[0]; i++){
      printf("%s\n", tokens[i]);
  }
  return tokens;
}

char **lsh_split_line(char *line)
/* 
Split given line into tokens with delimiters LSH_TOK_DELIM
*/
{
  int bufsize = LSH_TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  if (!tokens) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(1);
  }

  token = strtok(line, LSH_TOK_DELIM);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += LSH_TOK_BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(1);
      }
    }

    token = strtok(NULL, LSH_TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}


struct Command {
    // 
}Command;

int main(){
    char *input = readInput();
    printf("%s", input);
    // char** ln = "yoo | how's it | hangin?";
    // lsh_split_line(ln);
    printf("hey, are we tech bros or what? ");
}