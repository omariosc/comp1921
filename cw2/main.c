/************************************************************************
University of Leeds
School of Computing
COMP1921 - Programming Project
Coursework 2
File: main.c

Purpose: 
- Manages entire program interface
- Handles basic logic
- Deals with log file opening and closing

Student Name: Omar Choudhry
Student ID: 201398269
Email: sc20osc@leeds.ac.uk
Date Work Commenced: 03.03.2021
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "main.h"
#include "knowledgebase.h"
#include "stringhandling.h"

//-----------------------------------------------------------------------------------------------------------------

// Main function for entire program
// Handles interface and main logic
int main (void) {
  // Used for randomly generating selections for responses
  srand((unsigned) time(NULL));

  // Gets time to be used for log
  time_t t;
  time(&t);

  // Checks if file exists
  FILE* logFile;
  logFile = fopen("log.txt", "r");

  // If file does not exist
  if (logFile == NULL) {
    // Creates log file
    logFile = fopen("log.txt", "wb");
    // Records file created time in log
    fprintf(logFile, "LOG CREATED: %s", ctime(&t));    
  }
  // Since file exists
  else {
    // Open file to be appended
    logFile = fopen("log.txt", "a");
  }
  
  // Records conversation time in log
  fprintf(logFile, "\nCONVERSATION LOG: %s\n", ctime(&t));  

  // Arrays to hold inputs and responses
  char currentInput[MAX_INPUT_LENGTH];
  char previousInput[MAX_INPUT_LENGTH];
  char currentResponse[MAX_RESPONSE_LENGTH];
  char previousResponse[MAX_RESPONSE_LENGTH];

  // Variables to hold values used for events
  int nullInput = 0;
  int sameInput = 0;

  // Current event is logon
  EventHandler(logFile, LoginKnowledgeBase, NULL, NULL);

  // Continuously asks for input and outputs response
  // Only ends when user matches "BYE" or "GOODBYE" in the input
  while (1) {
    // Retrieves user input
    GetInput(logFile, currentInput);
    // Performs pre processing on input
    strcpy(currentInput, PreprocessedInput(currentInput));
    // Checks that input is not null
    if (!NullInputCheck(currentInput)) {
      // Since input is not null
      nullInput = 0;
      // Checks if user wants to quit
      if (UserQuitCheck(currentInput)) {
        // Final exit response
        EventHandler(logFile, ExitKnowledgeBase, NULL, NULL);
        // Successful system exit
        break;
      }
      // Checks that input is not same or similar as previous input
      if (InputRepetitionCheck(currentInput, previousInput) == 0) {
        // Since input is different
        sameInput = 0;
        // Processes input and output response
        BotResponse(logFile, currentInput, previousResponse, currentResponse);
        // Copies "currentResponse" into "previousResponse"
        strcpy(previousResponse, currentResponse);
        // Copies "currentInput" into "previousInput"
        strcpy(previousInput, currentInput);
      }
      // If previous and current input were the same
      else {
        // If first repetition
        if (!sameInput) {
          EventHandler(logFile, RepetitionT1KnowledgeBase, previousResponse, currentResponse);
          // Copies "currentResponse" into "previousResponse"
          strcpy(previousResponse, currentResponse);
        }
        // If second or higher repetition
        else {
          EventHandler(logFile, RepetitionT2KnowledgeBase, previousResponse, currentResponse);
          // Copies "currentResponse" into "previousResponse"
          strcpy(previousResponse, currentResponse);
        }
        // Sets same input variable to 1
        sameInput = 1;
      }
    }
    // If there is null input
    else {
      // If first null input
      if (!nullInput) {
        EventHandler(logFile, NullInputKnowledgeBase, previousResponse, currentResponse);
        // Copies "currentResponse" into "previousResponse"
        strcpy(previousResponse, currentResponse);
      }
      // If second or more null input repetition
      else {
        EventHandler(logFile, NullInputRepetitionKnowledgeBase, previousResponse, currentResponse);
        // Copies "currentResponse" into "previousResponse"
        strcpy(previousResponse, currentResponse);
      }
      // Sets null input variable to 1
      nullInput = 1;
    }
  }
  // Closes the log file
  fclose(logFile);
  // Successful program exit
  return 0;
}

//-----------------------------------------------------------------------------------------------------------------