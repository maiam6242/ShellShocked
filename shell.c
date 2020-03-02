// HK and Maia
#include <unistd.h>
#include <stdio.h>

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"
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
char **lsh_split_line(char *line)
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
    char** ln = "yoo | how's it | hangin?";
    lsh_split_line(ln);
    printf("hey, are we tech bros or what? ");
}