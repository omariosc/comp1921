# COMP1921 Programming Project Coursework 2: UniBot

**Note**: I would recommend viewing this file on GitLab or a suitable markdown viewer.

<br>

## Git Repositry URL

I have used the [COMP1921 GitLab Repositry](https://gitlab.com/comp1921_2021/sc20osc/-/tree/master/cw2) for this project.

<br>

## Git Commit History

Complete git commit history can be found in the files as text [```commithistory.txt```](commithistory.txt), or you can press the link directly to [GitLab](https://gitlab.com/comp1921_2021/sc20osc/-/commits/master)

<br>

## Instructions on running UniBot

- You must hit the enter key for ```UniBot``` to process the input.<br>
- You can change size of input in [```main.h```](main.h) through ```MAX_INPUT_LENGTH```. With the current length, the chatbot can take a valid input of around 60 characters.<br>
- You can change the similarity check value in [```stringhandling.h```](stringhandling.h) through ```MIN_SIMILARITY_CHECK```. **Note**: If you make a spelling mistake and retype, the chatbot may see it as a repetition.<br>
- To exit the program you must contain ```"BYE"``` or ```"GOODBYE"``` within the input.<br>
- A log of your conversation will be recorded in the file [```log.txt```](log.txt)<br>
- This file is a log of all conversations with ```UniBot```.<br>
- But otherwise, simply run the program and start chatting away!<br>
- **Note:** ```UniBot``` is not case sensitive and cleans input from non alphabetic characters.<br>

<br>

## Video Demonstration

Video demonstration can be found at [```VideoDemonstration.mp4```](VideoDemonstration.mp4)

<br>

## CMake Build

Run the following commands in the terminal:<br>

```c
mkdir build
cd build
cmake ..
make
./UniBot // To run the chatbot
./unit_tests // To run the unit tests
```

<br>

## Manual Compilation

UniBot can also be compiled manually using the following command:<br>

```gcc -std=c99 knowledgebase.h knowledgebase.c stringhandling.h stringhandling.c main.c main.h -o UniBot && ./UniBot```

<br>

## Test Suite

You can find a well-designed, dedicated regression unity test suite suite in the file [```unit_tests.c```](unit_tests.c). It contains tests for all the main string processing functions. Unit tests can be compiled using the following command too:

```gcc -std=c99 -fdump-rtl-expand unit_tests.c unity.c knowledgebase.h knowledgebase.c stringhandling.h stringhandling.c -o unit_tests && ./unit_tests```

<br>

## Egypt

I have included a file called [```UniBotCallGraph.pdf```](UniBotCallGraph.pdf) which shows all the dependencies of the project, created through Egypt.

<br>

## Critical Reflection

Critical reflection can be found in the file [```CriticalReflection.pdf```](CriticalReflection.pdf)

<br>

## References

- Gonzales Cenelia (2009). *Chatbot Tutorial.* [Codeproject.com](https://www.codeproject.com/Articles/36106/Chatbot-Tutorial#intro) [Accessed 4 May 2021].<br>
- krrishna (2013). *Remove extra whitespace from a string in C.* [Stack Overflow](https://stackoverflow.com/questions/17770202/remove-extra-whitespace-from-a-string-in-c) [Accessed 2 May 2021].<br>
- Programiz (2021). *C Program to Remove all Characters in a String Except Alphabets.* [Programiz.com](https://www.programiz.com/c-programming/examples/remove-characters-string) [Accessed 1 May 2021].<br>
- Rebelo, R.A. (2004). *More than strcmp(): similarity in strings.* [Codeproject.com](https://www.codeproject.com/Articles/8265/More-than-strcmp-similarity-in-strings) [Accessed 4 May 2021].
