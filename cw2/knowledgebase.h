/************************************************************************
University of Leeds
School of Computing
COMP1921 - Programming Project
Coursework 2
File: knowledgebase.h

Purpose: 
- Contains record structure definition for main knowledge base
- Contains event record structure definition for events
- Defines maximum number of input and responses
- Contains global knowledge bases
- Contains global log file

Student Name: Omar Choudhry
Student ID: 201398269
Email: sc20osc@leeds.ac.uk
Date Work Commenced: 17.03.2021
*************************************************************************/

#include <stdio.h>

#define MAX_INPUT 10 // Defines maximum number of inputs that lead to responses
#define MAX_RESPONSE 10 // Defines maximum number of responses 

//-----------------------------------------------------------------------------------------------------------------

// Structure to contain records of knowledge base
typedef struct {
  char* input[MAX_INPUT]; // The input which results in a response and maximum number of inputs
  char* responses[MAX_RESPONSE]; // Response correlating to input and maximum number of responses
  int inputLength; // Stores number of inputs
  int responsesLength; // Stores number of responses
} Record;

// Structure to contain records of knowledge base
typedef struct {
  char* responses[MAX_RESPONSE]; // Responses for each event
  int length; // Stores number of responses
} EventRecord;

// Global knowledge bases
extern Record KnowledgeBase[];

// Event record to hold login responses
extern EventRecord LoginKnowledgeBase[];

// Event record to hold user repetition responses
extern EventRecord RepetitionT1KnowledgeBase[];

// Event record to hold user repetition responses
// Case user repeats more than once
extern EventRecord RepetitionT2KnowledgeBase[];

// Event record to hold null input responses
extern EventRecord NullInputKnowledgeBase[];

// Event record to hold null input responses
// Case user repeats null input more than once
extern EventRecord NullInputRepetitionKnowledgeBase[];

// Event record to hold backup responses
// Case bot has no response
extern EventRecord NoResponseKnowledgeBase[];

// Event record to hold exit responses
extern EventRecord ExitKnowledgeBase[];

// Global variable to store size of knowledge base records
extern int KnowledgeBaseSize;

// File to store log of conversation
extern FILE* logFile;

// Event handler
// Manages user logon and quit
// Manages user repetitions and null inputs
void EventHandler (FILE* logFile, const EventRecord eventKnowledgeBase[], const char* previousResponse, char* currentResponse);

//-----------------------------------------------------------------------------------------------------------------