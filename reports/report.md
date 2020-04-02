
# Shell Shocked: Creating a UNIX Shell in C

## HK Rho and Maia Materman

### Project Goals

Through this project, we would like to learn how to create a simple, functional UNIX shell in C. As for the minimum viable product, we vision our shell to run 6 basic commands: **cd**, **pwd**, **ls**, **mkdir**, **rm**, and **man**. By the end of working on this project, we want to have a good understanding of how shells work. 

If we go beyond our minimum viable product, we would like to implement more commands and deal more with the edge cases and options associated with each command we have created. We also would like to try to implement a text editor as a major stretch goal.

### Learning Goals

We would like to learn more about how to write C in a "real world context" and practice with the C that we've learned. We'd also like to better learn and understand UNIX commands, so that we can get better at using them! We are looking forward to getting more comfortable with how operating systems work at a pretty low level. 

### Resources
Chapter from Book About Writing Our Own Shell:
https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf

Stephan Brennan's Tutorial on Writing Shell in C:
https://brennan.io/2015/01/16/write-a-shell-in-c/

GeeksforGeeks Linux Shell in C:
https://www.geeksforgeeks.org/making-linux-shell-c/

### What We've Done
We completed a substantial amount of research about shells and implementing UNIX shells in C. Before directly diving into the coding part, we started by mapping out the process that a shell will undergo, which involved drawing several detailed diagrams of how the keyboard input will be passed into the shell and how the input would be organized to execute the desired commands. We have also written code to read and parse user inputs based on pipes and spaces. We also implemented commands like **cd**, **pwd**, **ls**, **mkdir**, **rm**, and **man**. We found a wide array of resources throughout the process which allowed us to more easily complete our project. 

INCLUDE CODE SNIPPETS AND OUTPUTS

### Design Decision We Made
The most important design decision we made was figuring out how to best parse inputs. We could have parsed things in any number of ways, but decided to parse the line for a variety of characters such as new line characters and tab characters. We parse the entire line (and look for pipes) in one operation, and then process them, as opposed to stopping as soon as we see a command. This allows us to only need to parse the input once, as opposed to needing to return to it multiple times. 

<> INSERT PROCESS PICTURE HERE!

Above, we have included our brainstorming for the best way to parse and split text, which matches our implementation. This is, again, as opposed to reading and parsing a line multiple times and stopping each time a command is reached.

### More Code!

This is a code snippet from our split line function that parsed user input. This snippet is accounting for variability in input length. 
```C
    if (position >= bufsize) {
        bufsize += LSH_TOK_BUFSIZE;
        tokens = realloc(tokens, bufsize * sizeof(char*));
        if (!tokens) {
          fprintf(stderr, "lsh: allocation error\n");
          exit(1);
        }
    }
```

This is a code snippet from our ls command. Essentially, what it does is assigns whatever directory is currently being read to the variable d, then looks in the struct of type dirent for the name. The dirent structure is from the dirent.h library. It then closes the directory that it is reading. 

```C
    while(dir = readdir(d))
    {
      printf("%s\n", dir -> d_name);
    }
    closedir(d);

```

### Reflection

//TODO: THIS!
Maia: I think that I achieved my learning goals for this project. I came in hoping to get a better understanding of C and how to use it 

### GitHub and Trello
GitHub: https://github.com/maiam6242/ShellShocked

Trello: https://trello.com/b/qbu0BTlw/hk-and-maia 
