/************************************************************************
University of Leeds
School of Computing
COMP1921 - Programming Project
Coursework 1
File: logic.c

Purpose:
- Creates accounts, loans and book arrays
- Stores and loads accounts and loans from files
- Implements other important logic in program

Student Name: Omar Choudhry
Student ID: 201398269
Email: sc20osc@leeds.ac.uk
Date Work Commenced: 24.02.2020
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "book_management.h"
#include "logic.h"
#include "graph.h"

//-----------------------------------------------------------------------------------------------------------------

// global variables defined in logic.h
int numBooks = 0; // number of books
int numAccounts = 0; // number of accounts
int numLoans = 0; // number of loans
char adminUsername[5] = AdminUsername; // admin username
char adminPassword[5] = AdminPassword; // admin password
 
// global arrays defined in logic.h
Account* accounts[MaxAccount];	// the array of accounts
Loan* loans[MaxLoan]; // the array of loans
struct Book* books[MaxBook]; // the array of books

// stores accounts into file
// returns 0 if file not found
// returns 1 after file written to successfully
int StoreAccounts (void) {
	FILE *users = fopen("users.bin", "wb"); // writes file
	if (users == NULL) return 0; // if file does not exist
  else { // if file exists
    fwrite(&numAccounts, sizeof(int), 1, users); // stores number of accounts
    for (int i = 0; i < numAccounts; i++) { // iterates through every user in accounts array

      // write all user details to file
      fwrite(accounts[i]->name, 30*sizeof(char), 1, users);
      fwrite(accounts[i]->username, 30*sizeof(char), 1, users);
      fwrite(accounts[i]->password, 30*sizeof(char), 1, users);
      fwrite(accounts[i]->email, 30*sizeof(char), 1, users); 
    }
		fclose(users); // closes file
		return 1; // function complete
	}
}

// loads accounts from file
// returns 0 if file not found
// returns 1 after file read from successfully
int LoadAccounts (void) {
	FILE *users = fopen("users.bin", "rb"); // reads file
	if (users == NULL) return 0; // if file does not exist
  else { // if file exists
    // frees all members in account array
    for (int i = 0; i < MaxAccount; i++) free(accounts[i]);
    fread(&numAccounts, sizeof(int), 1, users); // reads number of accounts
    for (int i = 0; i < numAccounts; i++) { // iterates through every user in accounts array
      accounts[i] = malloc (sizeof(Account));  // allocates memory for the user account

      // stores all user details from file to array
      fread(accounts[i]->name, 30*sizeof(char), 1, users);
      fread(accounts[i]->username, 30*sizeof(char), 1, users);
      fread(accounts[i]->password, 30*sizeof(char), 1, users);
      fread(accounts[i]->email, 30*sizeof(char), 1, users);
    }
		fclose(users); // closes file
		return 1; // function complete
	}
}

// stores loans into file
// returns 0 if file not found
// returns 1 after file written to successfully
int StoreLoans (void) {
	FILE *loanfile = fopen("loans.bin", "wb"); // writes file
	if (loanfile == NULL) return 0; // if file does not exist
  else { // if file exists
    fwrite(&numLoans, sizeof(int), 1, loanfile); // stores number of loans
    for (int i = 0; i < numLoans; i++) { // iterates through every user in accounts array

      // write all loan details to file
      fwrite(loans[i]->username, 30*sizeof(char), 1, loanfile);
      fwrite(&loans[i]->bookid, sizeof(unsigned int), 1, loanfile);
    }
		fclose(loanfile); // closes file
		return 1; // function complete
	}
}

// loads loans from file
// returns 0 if file not found
// returns 1 after file read from successfully
int LoadLoans (void) {
	FILE *loanfile = fopen("loans.bin", "rb");
	if (loanfile == NULL) return 0;
  else { // if file exists
    // frees all members in account array
    for (int i = 0; i < MaxAccount; i++) free(loans[i]);
    fread(&numLoans, sizeof(int), 1, loanfile); // reads number of loans
    for (int i = 0; i < numLoans; i++) { // iterates through every user in accounts array
      loans[i] = malloc (sizeof(Loan));  // allocates memory for the loan

      // stores all loan details from file to array
      fread(loans[i]->username, 30*sizeof(char), 1, loanfile);
      fread(&loans[i]->bookid, sizeof(unsigned int), 1, loanfile);
      
    }
		fclose(loanfile); // closes file
		return 1; // function complete
	}
}

// checks that username is unique
// returns 1 if username exists
// returns 0 if username is unique
int ExistingUsernameCheck(const char* username) {
  // if username is the same as the admin username then username is invalid
  if (strcmp(username, adminUsername) == 0) return 0;
  for (int i = 0; i < numAccounts; i++) { // iterates through all accounts
    // if existing username is found
    if (strcmp(username, accounts[i]->username) == 0) return 0;
  }
  // different username so valid
  return 1;
}

// checks that email contains the @ symbol
// returns 1 if email is valid
// returns 0 if email is invalid
int EmailValidation(const char* email) {
  // iterates through length of email
  for (int i = 0; i < strlen(email) + 1; i++) {
    // checks each character
    if (email[i] == '@') return 1; // email contains @ symbol so valid
  }
  return 0; // if there was no @ symbol then email is invalid
}

// checks that user credentials are correct
// returns 1 if user exists
// returns 0 if invalid credentials
int UserExists(const char* username, const char* password) {
  for (int i = 0; i < numAccounts; i++) { // iterate through users
    if (strcmp(accounts[i]->username, username) == 0) { // if usernames match
      if (strcmp(accounts[i]->password, password) == 0) { // if passwords match
        return 1;
      }
    }
  }
  return 0; // credentials don't match
}

// book search menu
// displays menu
// search by title, author or year
// returns 0 when user returns to previous menu
int BookSearch(void) {

  char searchOption; // variable used to store user option

  while(1) { // whilst user is in the search menu

    while (1) { // for user to input valid option
      DisplaySearchOptions(); // outputs search menu
      scanf(" %c", &searchOption); // option input
      if (searchOption < '1' || searchOption > '4') { // checks if input is valid
        DisplayInvalidOption(); // displays error message
      }
      else break; // breaks from loop   
    }

    if (searchOption == '1') { // title search
      DisplaySearchTitleBook(); // search prompt

      char *bookTitle = malloc (30*sizeof (char)); // variable used to store input title
      scanf(" %s", bookTitle); // stores book title input

      int bookFound = 0; // variable used if book is found

      for (int i = 0; i < numBooks; i++) { // iterate through all books
        if (strcmp(books[i]->title, bookTitle) == 0) { // if book found with same title
          bookFound++; // book has been found
          break; // ends loop
        }
      }

      if (bookFound) { // if at least one book exists output books
        DisplayBookHeader();
        for (int i = 0; i < numBooks; i++) { // iterate through all books
          if (strcmp(books[i]->title, bookTitle) == 0) { // if book found with same title
            // this time output all books
            DisplayBook(books[i]);
          }
        }      
      }
      else DisplayNoBookFound(); // if there were no books
    }
    else if (searchOption == '2') { // author search
      DisplaySearchAuthorBook(); // search prompt

      char *bookAuthors = malloc (30*sizeof (char)); // variable used to store input author
      scanf(" %s", bookAuthors); // stores book author input

      int validInput = 1; // used to control if input is valid

      for (int i = 0; i < strlen(bookAuthors) + 1; i++) {
        if (isdigit(bookAuthors[i])) { // if author contains a number
          DisplayInvalidAuthorInput(); // outputs error message
          validInput = 0; // invalid input so do not search for book
          break; // ends loop
        }
      }

      if (validInput) { // if author input was valid
        int bookFound = 0; // variable used if book is found

        for (int i = 0; i < numBooks; i++) { // iterate through all books
          if (strcmp(books[i]->authors, bookAuthors) == 0) { // if book found with same year
            bookFound++; // book has been found
            break; // ends loop
          }
        }

        if (bookFound) { // if at least one book exists output books
          DisplayBookHeader();
          for (int i = 0; i < numBooks; i++) { // iterate through all books
            if (strcmp(books[i]->authors, bookAuthors) == 0) { // if book found with same year
              // this time output all books
              DisplayBook(books[i]);
            }
          }      
        }
        else DisplayNoBookFound(); // if there were no books
      }
    }
    else if (searchOption == '3') { // year search
      DisplaySearchYearBook(); // search prompt

      char* bookYear = malloc (sizeof(int)); // variable used to store input year
      scanf(" %s", bookYear); // stores input year

      int validInput = 1; // used to control if input is valid

      for (int i = 0; i < strlen(bookYear); i++) { // iterate through all characters in input
        if (isalpha(bookYear[i])) { // if year contains a letter
          DisplayInvalidYearInput(); // outputs error message
          validInput = 0; // input year is invalid
          break; // ends loop
        }
      }

      if (validInput) { // if input year was valid
        int bookFound = 0; // variable used if book is found

        int bookYearInt = atoi(bookYear); // converts year into integer

        for (int i = 0; i < numBooks; i++) { // iterate through all books
          if (books[i]->year == bookYearInt) { // if book found with same year
            bookFound++; // book found
            break; // ends loop
          }
        }

        if (bookFound) { // if at least one book exists output books
          DisplayBookHeader(); // outputs header
          for (int i = 0; i < numBooks; i++) { // iterate through all books
            if (books[i]->year == bookYearInt) { // if book found with same year
              // this time output all books
              DisplayBook(books[i]);
            }
          }      
        }
        else DisplayNoBookFound(); // if there were no books
      }
    }
    else if (searchOption == '4') { // return no previous menu
      DisplayReturnMenu(); // output message
      return 0; // ends function
    }
  }
}

//-----------------------------------------------------------------------------------------------------------------