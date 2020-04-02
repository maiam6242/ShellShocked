
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


Here is a sample of some of the outputs of our program:
<img src="https://github.com/maiam6242/ShellShocked/blob/master/reports/ls_pwd_cd(original).png" alt="picture of the ls, cd and pwd commands in action!" width = "900">
<img src= "https://github.com/maiam6242/ShellShocked/blob/master/reports/mkdir_and_rm.png" alt = "picture of the mkdir, ls and rm commands in action!" width = "900">
<img src= "https://github.com/maiam6242/ShellShocked/blob/master/reports/man.png" alt = "picture of the man command in action!" width = "900">

In addition, we wanted to use our main function code to explain in more detail the way in which our shell works. 

```C
    while (keep_running) {
      printf(">>> ");
      char *input = readInput();
      char **out = lsh_split_line(input);
      cmd_handler(out); // handle the command (input gives the first token which is the command)
      printf("\n");
  }
```
Essentially, unless there is a signal to stop, our shell executes the loop above. It first reads the input, then splits it by commands based on the locations of the specified delimiters (generally spaces) and pipes (if they are found in the user input), then sends that to the command handler which processes and executes each command which it is given.  

### Design Decision We Made
The most important design decision we made was figuring out how to best parse inputs. We could have parsed things in any number of ways, but decided to parse the line for a variety of characters such as new line characters and tab characters. We parse the entire line (and look for pipes) in one operation, and then process them, as opposed to stopping as soon as we see a command. This allows us to only need to parse the input once, as opposed to needing to return to it multiple times. 

<img src="https://github.com/maiam6242/ShellShocked/blob/master/reports/parse_process.jpg" alt="picture of our process" width = "900">

Above, we have included our brainstorming for the best way to parse and split text, which matches our implementation. This is, again, as opposed to reading and parsing a line multiple times and stopping each time a command is reached. With more time, we wished we would have been able to fully implement pipes, while we are able to read them and understand that they are not commands, we weren't able to implement the behavior around input and output and having things "pipe" to one another. 

### Breakthrough
During the process of implementing the commands, we were confused with our mental model of how our shell should behave. This confusion rose after we observed the output of the implementation of mkdir and cd. Before getting deeper into explaining our breakthrough, we would like to specify these two terms that will be used frequently: the inner shell as the shell that is made/ran by the code that we worked for this project, and the outer shell that runs the code that we worked for this project.

We noticed that when mkdir was called, a new directory with the given name was made both within the inner shell and the outer shell; however, when cd was called, we could only change the path within the inner shell and the change was not transferred to the outer shell. This behavior confused our understanding and expected behavior of the shell; but with help, we learned that the outer shell is a parent process to the inner shell because the outer shell creates the process that runs the inner shell. If the inner shell tried to modify the outer shell (aka the parent process), we would have encountered surprising results. However, commands like mkdir modified the file system, which both the outer and inner shells were observing. 


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
#### Our Project
We believe that our project has definitely reached our initial minimum viable product of making a shell with 5 commands. Halfway into the project, we decided to add another command to the list of commands that our shell would execute as an extra step to our minimum viable product. Apart from achieving this, we were also able to take a little step into dealing with pipes. Although we could not get into writing the behavior of the shell when a pipe is given as an input, we were able to parse the input in a different manner when pipes were detected. To conclude, we believe that we took small additional steps above our minimum viable product.

#### Our Learning Goals

##### Maia
I think that I achieved my learning goals for this project. I came in hoping to get a better understanding of C and how to use it, and I think that I accomplished that pretty well. Boy, oh boy, do I now understand (and don't really like!) pointers! I also wanted to get a better feeling for the way in which commands and operating systems behave, as well as how "real world" people think about C, and I found that through my research I was able to dive much deeper than I've been able to thus far in class, which I appreciated. I think the biggest benefit to me this project was just getting comfortable and familiar with C, and not being as intimidated by it. That was a really nice feeling!

##### HK
By working on this project, I believe that I was not only able to solidify my understanding of C syntax and knowledge we learned in class, but also was able to become more confident in writing snippets of code faster (like for quizzes and homeworks). Prior to working on the project, I was still very confused with manipulating strings and programming with the type match in consideration. Not to even mention how such a low-level language with so many downsides would be applicable in real-life situations. Looking back to our project, I really value how this project helped me get much more comfortable with C.

### GitHub and Trello
GitHub: https://github.com/maiam6242/ShellShocked

Trello: https://trello.com/b/qbu0BTlw/hk-and-maia 
