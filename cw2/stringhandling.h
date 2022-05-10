/************************************************************************
University of Leeds
School of Computing
COMP1921 - Programming Project
Coursework 2
File: stringhandling.h

Purpose: 
- Contains function prototypes for stringhandling.c

Student Name: Omar Choudhry
Student ID: 201398269
Email: sc20osc@leeds.ac.uk
Date Work Commenced: 17.03.2021
*************************************************************************/

#include <stdio.h>

#define MIN_SIMILARITY_CHECK 0.85 // Minimum value set for similarity check for inputs

//-----------------------------------------------------------------------------------------------------------------

// Gets inputs from the user
void GetInput (FILE* logFile, char* input);

// Does some preprocessing on like:
// removing punctuation characters, symbols,
// redundant spaces, and converts input to uppercase
char* PreprocessedInput (char* input);

// Returns 1 if input is null
// Returns 0 if input is not null
int NullInputCheck (const char* input);

// Returns 1 if user wants to quit
// Returns 0 if user doesn’t want to quit
int UserQuitCheck (const char* input);

// Chooses random response from responses
char* ResponseChoice (FILE* logFile, char* responses[], const char* previousResponse, char* currentResponse, const int responsesLength);

// Returns 1 if response exists
// Returns 0 if no response exists
// Prints response or no response message
int BotResponse (FILE* logFile, char* input, const char* previousResponse, char* currentResponse);

// Returns 1 if same or similar input
// Returns 0 if different input
int InputRepetitionCheck (char* previousInput, char* currentInput);

//-----------------------------------------------------------------------------------------------------------------