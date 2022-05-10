/************************************************************************
University of Leeds
School of Computing
COMP1921 - Programming Project
Coursework 2
File: stringhandling.c

Purpose:
- Retrieves user input
- Handles all string pre processing
- Returns response using input
- Checks for null inputs
- Checks if user wants to quit
- Performs similarity check on strings

Student Name: Omar Choudhry
Student ID: 201398269
Email: sc20osc@leeds.ac.uk
Date Work Commenced: 17.03.2021
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stringhandling.h"
#include "knowledgebase.h"

//-----------------------------------------------------------------------------------------------------------------

// Gets inputs from the user
void GetInput (FILE* logFile, char* input) {
  // Prints leading character
  printf("\n> ");
  // Stores input
  scanf(" %[^\n]s", input);
  // Records in log if exists
  if (logFile != NULL) {
    fprintf(logFile, "> %s\n", input);
  }
}

// Does some preprocessing like:
// removing punctuation characters, symbols,
// redundant spaces, and converts input to uppercase
char* PreprocessedInput (char* input) {
  // Code adapted from (Programiz, 2021)
  // Loops over string
  for (int i = 0, j; input[i] != '\0'; i++) {
    // Enter the loop if the character is not an alphabet
    // And not the null character
    while (!(input[i] >= 'a' && input[i] <= 'z') && !(input[i] >= 'A' && input[i] <= 'Z') && !(input[i] == '\0') && !(input[i] == ' ')) {
      for (j = i; input[j] != '\0'; j++) {
        // If jth element of user input is not an alphabet,
        // Assign the value of (j+1)th element to the jth element
        input[j] = input[j + 1];
      }
      // End of string character
      input[j] = '\0';
    }
  }
  // End of code adapted from (Programiz, 2021)
  // Loops over string and capitalizes all lower case characters
  for (int i = 0; input[i] != '\0'; i++) {
    // If character is a lower case alphabet
    if (input[i] >= 'a' && input[i] <= 'z') {
      // Makes the character upper case
      input[i] = toupper(input[i]);
    }
  }
  // Removes redundant spaces
  // Temporary counter variables
  // Code adapted from (krrishna, 2013)
  int i, x;
  for (i = x = 0; input[i]; i++) {
    // Looks for multiple spaces
    if(!isspace(input[i]) || (i > 0 && !isspace(input[i-1]))) {
      // Overwrites the extra space(s)
      input[x++] = input[i];
    }
  }
  // End of code adapted from (krrishna, 2013)
  if (input[x-1] == ' ') {
    // Reduces length of input to remove the ' '
    x--;
  }
  // Sets final character
  input[x] = '\0';
  // Returns completely pre processed inputs
  return input;
}

// Returns 1 if input is null
// Returns 0 if input is not null
int NullInputCheck (const char* input) {
  // If input is end of string character
  if (input[0] == '\0') {
    return 1;
  }
  // If input is not null
  else {
    return 0;
  }
}

// Returns 1 if user wants to quit
// Returns 0 if user doesn’t want to quit
int UserQuitCheck (const char* input) {
  // Checks if substring from knowledge base exists in input
  if (strstr(input, "BYE") != NULL) {
    return 1;
  }
  // If user does not want to quit
  return 0;
}

// Chooses random response from responses
char* ResponseChoice (FILE* logFile, char* responses[], const char* previousResponse, char* currentResponse, const int responsesLength) {
  // Initial variable to hold response selection
  int responseSelection;
  // If reponses are greater than 2 we can make sure the same one does not appear again
  if (responsesLength >= 2) {
    // Randomizes the response selection at least once
    do {
      responseSelection = rand() % responsesLength;
    }
    // IF response chosen through response selection and previous response are the same
    while (strcmp(responses[responseSelection], previousResponse) == 0);
  }
  // If there is only one response in the knowledge base
  else if (responsesLength == 1) {
    // Sets response selection to the first response
    responseSelection = 0;
  }
  // Copies response into the current response
  strcpy(currentResponse, responses[responseSelection]);
  // Records in log if exists
  if (logFile != NULL) {
    fprintf(logFile, "%s\n", responses[responseSelection]);
  }
  // Returns selected response
  return responses[responseSelection];
}

// Returns 1 if response exists
// Returns 0 if no response exists
// Prints response or no response found message
int BotResponse (FILE* logFile, char* input, const char* previousResponse, char* currentResponse) {
  // Checks if exact string is found in the knowledge base
  for (int i = 0; i < KnowledgeBaseSize; i++) {
    // Iterates through inputs in knowledge base
    for (int j = 0; j < KnowledgeBase[i].inputLength; j++) {
      // Check if entire string exists in the knowledge base
      if (strcmp(KnowledgeBase[i].input[j], input) == 0) {
        // Outputs response
        printf("%s\n", ResponseChoice(logFile, KnowledgeBase[i].responses, previousResponse, currentResponse, KnowledgeBase[i].responsesLength));
        return 1;
      }
    }
  }
  // Checks if a substring is found in the knowledge base
  for (int i = 0; i < KnowledgeBaseSize; i++) {
    // Iterates through inputs in knowledge base
    for (int j = 0; j < KnowledgeBase[i].inputLength; j++) {
      // Checks if substring from knowledge base exists in input
      if (strstr(input, KnowledgeBase[i].input[j]) != NULL) {
        // Outputs response
        printf("%s\n", ResponseChoice(logFile, KnowledgeBase[i].responses, previousResponse, currentResponse, KnowledgeBase[i].responsesLength));
        return 1;
      }
    }
  }
  // If string not found exactly checks for a single keyword in the knowledge base
  for (int i = 0; i < KnowledgeBaseSize; i++) {
    // Splits input into words (tokenizes input)
    char* tokenInput = strtok(input, " ");
    // Goes through each word in input
    while (tokenInput != NULL) {
      // Iterates through inputs in knowledge base
      for (int j = 0; j < KnowledgeBase[i].inputLength; j++) {
        // If word in input matches input in knowledge base
        if (strcmp(KnowledgeBase[i].input[j], tokenInput) == 0) {
          // Outputs response
          printf("%s\n", ResponseChoice(logFile, KnowledgeBase[i].responses, previousResponse, currentResponse, KnowledgeBase[i].responsesLength));
          return 1;
        }
      }
      // Further tokenizes tokenized input to move to next word and not search for it anymore
      tokenInput = strtok(NULL, " ");
    }
  }
  // If no response was found
  EventHandler(logFile, NoResponseKnowledgeBase, previousResponse, currentResponse);
  return 0;
}

// Quick swap of the address of 2 arrays of unsigned int
void swap (unsigned **first, unsigned **second) {
	unsigned *temp;
	temp = *first;
	*first = *second;
	*second = temp;
}

// Returns 1 if same or similar input
// Returns 0 if different input
// Function contains code adapted from (Rebelo, 2004)
int InputRepetitionCheck (char* previousInput, char* currentInput) {
  // First check for exact same inputs
  if (!strcmp(currentInput, previousInput)) {
    // Same input
    return 1;
  }

  // Calculates similarity value between inputs
  // Start of code adapted from (Rebelo, 2004)
  // Calculates length of inputs
  size_t previousInputLength = strlen(previousInput), currentInputLength = strlen(currentInput);
  // Declared variables to be used
	float lowestCommonSequenceLength;
	unsigned j, k, *previous, *next;
  // If the length of the inputs are less than 7
	if (previousInputLength < 7 || currentInputLength < 7)	{
    return 0;
  }
  // Allocates size through size on inputs
	previous = (unsigned *) calloc (previousInputLength + 1, sizeof(unsigned));
	next = (unsigned *) calloc (previousInputLength + 1, sizeof(unsigned));
  // Calculates similarity and lowest common sequence length
	for (j = 0; j < currentInputLength; j++){
		for (k = 1; k <= previousInputLength; k++) {
      if (previousInput[k-1] == currentInput[j]) {
        next[k] = previous[k-1] + 1;
      }
      else {
        next[k] = previous[k] >= next[k-1]?previous[k]:next[k-1];
      }
    }
		swap(&previous, &next);
	}
  // Calculates similarity value
	lowestCommonSequenceLength = (float) previous[previousInputLength];
	float similarityValue = lowestCommonSequenceLength / previousInputLength;
  // End of code adapted from (Rebelo, 2004)
  
  // If the strings are more similar than the pre defined similarity check
  if (similarityValue >= MIN_SIMILARITY_CHECK) {
    // Same inputs to similarity check value
    return 1;
  }
  // If inputs are less similar than the similarity check
  else {
    // Not same inputs
    return 0;
  }
}

//-----------------------------------------------------------------------------------------------------------------