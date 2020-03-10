
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

### What We've Done (as of 3/10/2020)
We have completed a substantial amount of research about shells and implementing UNIX shells in C. Before directly diving into the coding part, we started by mapping out the process that a shell will undergo, which involved drawing several detailed diagrams of how the keyboard input will be passed into the shell and how the input would be organized to execute the desired commands. We have also written code to read and parse user inputs based on pipes and spaces. We have also started to implement commands like **cd**, **pwd**, and **mkdir**. So far, we are focusing on getting the major functionalities of each function from our theoretical understanding to our code (e.g. reading input, parsing, and commands). Because of this, we have not yet had the chance to test our functions nor debug them, but we will immediately start testing them out after we finish transferring our theoretical understanding to code. We have found a wide array of resources throughout the process which have allowed us to more easily complete our project. 

### What We're Doing Next

We have outlined four major tasks for the next team meetings: 

1. Write the **ls** command 
    * Definition of Done: Show that it is able to execute the command on the shell
2. Connect the reading and parsing functionality  
    * Definition of Done: Demonstrate shell taking input from stdin and the result of the parsing
3. Write the **rm** command  
    * Definition of Done: Show that it is able to execute the command on the shell
4. Start to write the **man** command  
    * Definition of Done: Show that it is able to execute the command on the shell

    
For all the next steps mentioned above, both teammates will be working together on the tasks. HK will likely handle the integration, and Maia will likely work more on the commands. Both of us will code together and work with one another throughout the entire process. We will be utilizing Visual Studio Code Live Share and video calls, so that we can work together as needed for the next few weeks.

### GitHub and Trello
GitHub: https://github.com/maiam6242/ShellShocked

Trello: https://trello.com/b/qbu0BTlw/hk-and-maia 
