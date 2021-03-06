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


int changeDirectory(char* arg){
    /* 
    Should move to home if no argument, if directory exists, go to that directory, else output an error. Use chdir to change directories

    arg: either the directory that should be changed to or blank for home
    Returns: 0 if successful, -1 if not 
    */

    // check for CTRL-D
    if (arg == NULL){
      perror("Args are null! Can't change directory\n");
      return -1;
    }
    else if (chdir(arg)!= 0){
      perror("Sorry some sort of error with cd\n");
      return -1;
    }
    else {
      // printf("%s \n", arg);
      chdir(arg);
      return 0;
    }

    // Check if we need to handle cases dealing with implicit vs absolute path
}


void printDirectory(){
    /*
    This should print the current working directory.
    */
    char cwd[1024]; 
    getcwd(cwd, sizeof(cwd)); 
    printf("Dir: %s \n", cwd);
}


int listFiles(){
  /*
  This should list all of the files in the current directory
  */
 
  DIR * d = opendir(".");
  struct dirent *dir;
  if (d == NULL) {
    return -1;
  }

    while(dir = readdir(d))
    {
      printf("%s\n", dir -> d_name);
    }
    closedir(d);

  return 0;
}


int makeDirectory(char* arg){
  /*
  Make a directory with the name given as an arg, if no name given or other error present, return -1, else return 0

  arg: pointer to character that stores the name of the directory
  */

  int failed = mkdir(arg);

  if(mkdir(arg, 0777) == -1){
    printf("Worked!\n");
    return 0;
  }
  else
    perror("Couldn't create directory\n");
    return -1;
}


int removeObjects(char* arg){
  /*
  Should remove objects that are passed in

  arg: pointer to character that contains the name of the object to remove
  */
  if (remove(arg) == 0 || rmdir(arg)) {
    printf("Deleted successfully\n");
  }
  else {
    printf("Failure to delete\n");
  }
  
}


int man(char* arg){
   /*
   Displays fun information about us for each command!

   arg: pointer to character that contains the command to display manual
   */
  int switch_arg = 0, i;

  char *command_list[NUM_COMMANDS]; // store commands that our shell can deal with
  command_list[0] = "cd";
  command_list[1] = "pwd";
  command_list[2] = "ls";
  command_list[3] = "mkdir";
  command_list[4] = "rm";
  command_list[5] = "man";

  // find which command in command_list cmd equals to
  for (i = 0 ;i < NUM_COMMANDS; i++) {
    if (strcmp(arg, command_list[i]) == 0) {
      switch_arg = i + 1;
    }
  }
  
  switch (switch_arg) {
    case 1: 
      // cd 
      printf("COMMAND NAME\n");
      printf("cd – change directory\n");
      printf("\n");

      printf("SYNTAX\n");
      printf("cd [directory name]\n");
      printf("\n");

      printf("DESCRIPTION\n");
      printf("Changes directory to the directory specified, or to home directory if no directory is specifie.\n");
      printf("\n");

      printf("🦸‍♀️🦸‍♀️🦸‍♀️🦹‍🦹‍♀️🦹‍♀️👮‍♀️👮‍👮‍♀️👷‍♀️👷‍♀️👷‍♀💂‍♀️💂‍♀️💂‍♀️🕵️‍🕵️‍♀️🕵️‍♀️️👩‍⚕️👩‍⚕️👩‍⚕️👩‍🌾👩‍🌾👩‍🌾👩‍🍳👩‍🍳👩‍🍳👩‍🎓👩‍🎓👩‍🎓👩‍🎤👩‍🎤👩‍🎤👩‍🏫👩‍🏫👩‍🏫👩‍🏭👩‍🏭👩‍🏭👩‍💻👩‍💻👩‍💻👩‍💼👩‍💼👩‍💼👩‍🔧👩‍🔧👩‍🔧👩‍🔬👩‍🔬👩‍🔬👩‍🎨👩‍🎨👩‍🎨👩‍🚒👩‍🚒👩‍🚒👩‍✈️👩‍✈️👩‍✈️👩‍🚀👩‍🚀👩‍🚀👩‍⚖️👩‍⚖️👩‍⚖️🧙‍♀️🧙‍♀️🧙‍♀️\n"); // ACK why are all the emojis White?!
      break;
    case 2:
      // pwd
      printf("COMMAND NAME\n");
      printf("pwd – print working directory\n");
      printf("\n");

      printf("SYNTAX\n");
      printf("pwd \n");
      printf("\n");

      printf("DESCRIPTION\n");
      printf("Prints the directory which the user is currently in.\n");
      printf("\n");

      printf("Fun fact! HK and Maia had a great time making this shell! We'd like to thank all of our adoring fans, our friends, families, zoom, VSCode live share and Allen B Downey. Without all of you, none of this would be possible. Thank you! \n");
      break;
    case 3:
      // ls
      printf("COMMAND NAME\n");
      printf("ls – list files in directory\n");
      printf("\n");

      printf("SYNTAX\n");
      printf("ls [directory name]\n");
      printf("\n");

      printf("DESCRIPTION\n");
      printf("List all files or directories in a given directory.\n");
      printf("\n");

      printf(" Tell me your deepest, darkest secret. \n Actually, please don't. The shell will be very confused and you'll be looking at your secrets in your terminal. Which, you know what, if that's what you want, then more power to ya!\n");
      break;
    case 4:
      // mkdir
      printf("COMMAND NAME\n");
      printf("mkdir – make directories\n");
      printf("\n");

      printf("SYNTAX\n");
      printf("mkdir [directory name]\n");
      printf("\n");

      printf("DESCRIPTION\n");
      printf("Create a new directory(ies) if the directory does not exist.\n");
      printf("\n");

      printf("FUN FACT\n");
      printf("Why was Rapunzel stuck in a tower for all her life?\n");
      printf(".\n");
      printf(".\n");
      printf(".\n");
      printf("Because the name of the 🏰kingdom🏰 is Corona. She had to be quarantined haha\n");
      break;
    case 5:
      // rm
      printf("COMMAND NAME\n");
      printf("rm – remove files or directories\n");
      printf("\n");

      printf("SYNTAX\n");
      printf("rm [file OR directory]\n");
      printf("\n");

      printf("DESCRIPTION\n");
      printf("Remove file(s) or directory(ies) in the current path.\n");
      printf("\n");

      printf("FUN FACT\n");
      printf("When Maia and HK tried to implement this the first time, they learned that rm only could delete files and not directories… (つ﹏<)･ﾟ｡ But they found out there was a function specific for removing directories in the dirent.h!\n");
      printf("Lesson of the day: understand what is in the library you are using!\n");
      break;
    case 6:
      // man
      printf("COMMAND NAME");
      printf("man - summons manual page");
      printf("\n");

      printf("SYNTAX");
      printf("man [command name]");
      printf("\n");

      printf("DESCRIPTION");
      printf("Displays manual about the input command. ");
      printf("\n");

      printf("FUN FACT");
      printf("Maia came up with the brilliant idea of including fun facts in descriptions of each function.");
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


char **lsh_split_at_pipe(char *line) {
  /*
  Split given line into tokens with delimiter '|' 

  line: pointer to character that stores the user input from terminal
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

    // printf("token: %s \n", token);
    token = strtok(NULL, "|");
  }
  tokens[position] = NULL;
  for(int i = 0; i < sizeof tokens / sizeof tokens[0]; i++){
      // printf("%s\n", tokens[i]);
  }
  return tokens;
}


char **lsh_split_line(char *line) {
  /* 
  Split given line into tokens with delimiters LSH_TOK_DELIM

  line: pointer to character that stores the user input from terminal
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

      // printf("token: %s \n", token);
      token = strtok(NULL, LSH_TOK_DELIM);
    }
    tokens[position] = NULL;
   
    }
    return tokens;
}


int cmd_handler(char **input) {
/* 
Execute different functions depending on the command received 

input: pointer to pointer to character containing parsed user input
*/

  int switch_arg = 0, i;

  char *command_list[NUM_COMMANDS]; // store commands that our shell can deal with
  command_list[0] = "cd";
  command_list[1] = "pwd";
  command_list[2] = "ls";
  command_list[3] = "mkdir";
  command_list[4] = "rm";
  command_list[5] = "man";

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
      break;
    case 2:
      // pwd
      printDirectory();
      break;
    case 3:
      // ls
      listFiles();
      break;
    case 4:
      // mkdir
      makeDirectory(input[1]);
      break;
    case 5:
      // rm
      removeObjects(input[1]);
      break;
    case 6:
      // man
      man(input[1]);
      break;
  }
}


int main(){
  // Should initialize the shell and read, parse and execute for each functionality we hope to include
  int keep_running = 1;

  while (keep_running) {
    printf(">>> ");
    char *input = readInput();
    char **out = lsh_split_line(input);
    cmd_handler(out); // handle the command (input gives the first token which is the command)
    printf("\n");
  }

  puts("Stopped by signal `SIGINT'");
  return EXIT_SUCCESS;
}
