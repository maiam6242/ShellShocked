/* 
  Software Systems Mini-Project 1 
  
  Shell that can execute six commands: cd, pwd, ls, mkdir, rm, and man.

  Team: Maia and HK
  Professor: Allen Downey
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <dirent.h>


#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a" // delimiter: tab, carriage return, end of line, system bell
#define NUM_COMMANDS 6

char *command_list[NUM_COMMANDS]; // store commands that our shell can deal with
command_list[0] = "cd";
command_list[1] = "pwd";
command_list[2] = "ls";
command_list[3] = "mkdir";
command_list[4] = "rm";
command_list[5] = "man";


int changeDirectory(char* arg){
    /* 
    Should move to home if no argument, if directory exists, go to that directory, else output an error. Use chdir to change directories
    Args: either the directory that should be changed to or blank for home
    Returns: 0 if successful, -1 if not 
    */

    // check for CTRL-D
    if (arg == NULL){
      perror("Args are null! Can't change directory");
      return -1;
    }
    else if (chdir(arg)!= 0){
      perror("Sorry some sort of error with cd");
      return -1;
    }
    else 
      printf("%s \n", arg);
      chdir(arg);
      return 0;

    // Check if we need to handle cases dealing with implicit vs absolute path
}


void printDirectory(){
    /*
    This should print the current working directory.
    */
    char cwd[1024]; 
    getcwd(cwd, sizeof(cwd)); 
    printf("\nDir: %s \n", cwd);
}


int listFiles(){
  /*
  This should list all of the files in the current directory
  */
 
  DIR * d = opendir(".");
  struct dirent *dir;
  if (d == NULL) {
    return -1;
    // d = opendir(".");
  }

  // if (d) {
    
    while(dir = readdir(d))
    {
      printf("%s\n", dir -> d_name);
    }
    closedir(d);
  // }
  return 0;
}


int makeDirectory(char* arg){
  /*
  Make a directory with the name given as an arg, if no name given or other error present, return -1, else return 0
  */

  int failed = mkdir(arg);

  if(mkdir(arg, 0777) == -1){
    printf("Worked!");
    return 0;
  }
  else
    perror("Couldn't create directory");
    return -1;
}


int removeObjects(char* arg){
  /*
  Should remove objects that are passed in
  */
  if (remove(arg) == 0 || rmdir(arg)) {
    printf("deleted successfully");
  }
  else {
    printf("failure to delete");
  }
  
}


int man(char* arg){
   /*
   Displays fun information about us for each command!
   */
  int switch_arg = 0, i;

  // find which command in command_list cmd equals to
  for (i = 0 ;i < NUM_COMMANDS; i++) {
    if (strcmp(arg, command_list[i]) == 0) {
      switch_arg = i + 1;
    }
  }
  
  switch (switch_arg) {
    case 1: 
      // cd 
      // maia
      printf(" blahblahblahblahblha \n");
      break;
    case 2:
      // pwd
      // maia
      printf(" \n");
      break;
    case 3:
      // ls
      // maia
      printf(" \n");
      break;
    ////////// hk ///////////
    case 4:
      // mkdir
      printf("Hello Allen B Downey! Fancy meeting you here! \n If you are not Allen B Downey, still welcome! We like just the same (maybe...) ha! jkjk... unless... 🔥🔥🔥 \n");
      printf("─▄██▄██▄\n");
      printf("─▀█████▀\n");
      printf("───▀█▀\n");
      printf("");
      printf("");
      break;
    case 5:
      // rm
      printf(" \n");
      break;
    case 6:
      // man
      printf("");
      break;
  }

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

    while(1) {
        ch = getchar();
        
        // when reach the end of input
        if(ch == EOF){
          printf("End Of File Character Pressed. Terminating shell.\n");
          exit(1);
        }
        else if (ch == '\n') {
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
}


char** parseInput() {
    /*
    Check the input against the command in the command table and any options
    */


}
char **lsh_split_at_pipe(char *line) {
  /*
  Split given line into tokens with delimiter '|' 
  */

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

    printf("token: %s \n", token);
    token = strtok(NULL, "|");
  }
  tokens[position] = NULL;
  for(int i = 0; i < sizeof tokens / sizeof tokens[0]; i++){
      printf("%s\n", tokens[i]);
  }
  return tokens;
}

char **lsh_split_line(char *line) {
  /* 
  Split given line into tokens with delimiters LSH_TOK_DELIM
  */

  int bufsize = LSH_TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  if (!tokens) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(1);
  }

  // if there is a pipe in the input call the lsh_split_pipe
  if (strchr(line, '|') != NULL) {
    lsh_split_at_pipe(line);
  }
  
  // if no pipes were found, just split by delimiters
  else {
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

      printf("token: %s \n", token);
      token = strtok(NULL, LSH_TOK_DELIM);
    }
    tokens[position] = NULL;
    for (int i = 0; i < position; i++){
        printf("tokens: %s \n", tokens[i]);
    }
    return tokens;
  }
}


int cmd_handler(char **input) {
/* Execute different functions depending on the command received */
  int switch_arg = 0, i;

  // find which command in command_list cmd equals to
  for (i = 0 ;i < NUM_COMMANDS; i++) {
    if (strcmp(input[0], command_list[i]) == 0) {
      switch_arg = i + 1;
    }
  }

  switch (switch_arg) {
    case 1:
      // cd
      changeDirectory(input[1]);
      printf("cd \n");
      break;
    case 2:
      // pwd
      printDirectory();
      printf("pwd \n");
      break;
    case 3:
      // ls
      listFiles();
      printf("ls \n");
      break;
    case 4:
      // mkdir
      makeDirectory(input[1]);
      printf("mkdir \n");
      break;
    case 5:
      // rm
      removeObjects(input[1]);
      printf("rm \n");
      break;
    case 6:
      // man
      man(input[1]);
      printf("man \n");
      break;
  }
}

struct Command {
    // 
}Command;


int main(){
  // Should initialize the shell and read, parse and execute for each functionality we hope to include
  int keep_running = 1;

  while (keep_running) {
    printf(">>> ");
    char *input = readInput();
    char **out = lsh_split_line(input);
    // printf("INPUT: %s \n", *out);
    // printf("INPUT: %s \n", out[1]);
    cmd_handler(out); // handle the command (input gives the first token which is the command)
  
  }

  puts("Stopped by signal `SIGINT'");
  return EXIT_SUCCESS;
  

    //// TEST FOR PWD ////
    // printDirectory(); 

    //// TEST FOR LS ////
    // listFiles();

    //// TEST FOR CD ///// seems like its working?
    // char* path = "/home";  
    // // char** path = "~/";
    // changeDirectory(path);
    // printDirectory();
    // listFiles();

    //// TEST FOR MKDIR ////
    // char* new_dir = "test_shell";
    // makeDirectory(new_dir);
    // listFiles();
    
    // lsh_split_at_pipe(input);
    // printf("%s", input);
    // char ln[] = "yoo | how's it | hangin?";
    // lsh_split_at_pipe(input);
}
