/************************************************************************
University of Leeds
School of Computing
COMP1921 - Programming Project
Coursework 1
File: main.c

Purpose: 
- Manages entire program interface
- Manages user, admin, register interfaces

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
#include "graph.h"
#include "logic.h"
#include "main.h"

//-----------------------------------------------------------------------------------------------------------------

// administrator menu
// can add and remove books
int AdminMenu(void) {

  char Option; // variable used to store user option

  // controls program flow
  while (1) {

    while (1) { // for user to input valid option
    DisplayLoggedIn("admin");
      DisplayAdminOptions(); // displays options
      scanf(" %c", &Option); // option input
      if (Option < '1' || Option > '5') { // checks if input is valid
        DisplayInvalidOption(); // displays error message
      }
      else break; // breaks from loop 
    }
  
    if (Option == '1') { // add a book

      char *Title = malloc (30*sizeof (char)); // variable used to store book title
      char *Author = malloc (30*sizeof (char)); // variable used to store book title
      char *Year = malloc (sizeof (int));; // variable used to store book year
      char *Copies = malloc (sizeof (int));; // variable used to store book year

      // prompts input
      DisplayTitleBook();
      // stores book title
      scanf(" %s", Title); // stores input title

      DisplayAuthorBook();
      // stores book title
      scanf(" %s", Author); // stores input author
      
      DisplayYearBook();
      // stores book title
      scanf(" %s", Year); // stores input year
      
      DisplayCopiesBook();
      // stores book title
      scanf(" %s", Copies); // stores input copies

      int validInput = 1; // used to control if inputs are valid

      // checks for valid author input
      for (int i = 0; i < strlen(Author) + 1; i++) {
        if (isdigit(Author[i])) { // if author contains a number
          DisplayInvalidBookAdd(); // outputs error message
          validInput = 0; // invalid author
          break; // ends loop
        }
      }

      if (validInput) { // if author was valid
        // checks for valid year input
        for (int i = 0; i < strlen(Year); i++) { // iterate through all characters in input
          if (isalpha(Year[i])) { // if year contains a letter
            DisplayInvalidBookAdd(); // outputs error message
            validInput = 0; // invalid year
            break; // ends loop
          }
        }
      }

      if (validInput) { // if author and year was valid
        // checks for valid copies input
        for (int i = 0; i < strlen(Copies); i++) { // iterate through all characters in input
          if (isalpha(Copies[i])) { // if copies contains a letter
            DisplayInvalidBookAdd(); // outputs error message
            validInput = 0; // invalid copies
            break; // ends loop
          }
        }
      }

      if (validInput) { // if all inputs were correct
        
        // creates new book structure
        struct Book newBook;

        // assigns all inputs and ID
        newBook.id = numBooks;
        strcpy(newBook.title, Title);
        strcpy(newBook.authors, Author);
        newBook.year = atoi(Year);
        newBook.copies = atoi(Copies);

        // stores book in array
        add_book(newBook);

        DisplaySuccessBookAdd(); // outputs success message
      }
    }
    else if (Option == '2') { // remove a book

      if (numBooks == 0) DisplayNoBooks(); // outputs no books message
      else {
        DisplayBookHeader(); // outputs header
        DisplayBookArray(); // outputs books
        
        char* bookID = malloc (sizeof(int)); // variable to store book ID for removal
        DisplayBookRemoval(); // outputs prompt
        scanf(" %s", bookID);

        int validID = 1; // used to check if input is valid
        // checks for valid ID input
        for (int i = 0; i < strlen(bookID); i++) { // iterate through all characters in input
          if (isalpha(bookID[i])) { // if copies contains a letter
            DisplayInvalidID(); // outputs error message
            validID = 0; // invalid ID
            break; // ends loop
          }
        }
        
        if (validID) { // if valid book ID input
          // checks if book is out on loan
          for (int i = 0; i < numLoans; i++) { // iterates through loans
            if (loans[i]->bookid == atoi(bookID)) { // if a loan exists with same book ID
              validID = 0; // not valid book to remove
              DisplayInvalidRemovalonLoan(); // displays error message
              break;
            }
          }
        }

        if (validID) {
          for (int i = 0; i < numBooks; i++) { // iterate through books
            if (books[i]->id == atoi(bookID)) { // if book with matching ID is found
              // removes book
              // stores result in variable
              int removeCheck = remove_book(*(books[i]));
              if (!removeCheck) { // if removal was success
                DisplaySuccessBookRemoval();  // output message
              }
              if (removeCheck == -99) DisplayErrorRemoval(); // error message if removal was unsuccessful
              break;
            }
          }
        }
      }
    }
    else if (Option == '3') { // book search
      BookSearch();
    }
    else if (Option == '4') { // display books
      if (numBooks == 0) DisplayNoBooks(); // outputs no books message
      else {
        DisplayBookHeader(); // outputs header
        DisplayBookArray(); // outputs books
      }
    }
    else if (Option == '5') { // quit
      DisplayLogOut(); // show quit message
      return 0; // logs out
    }
  }
}

// regular user menu
// can borrow and return books
int UserMenu(const char* username) {

  char Option; // variable used to store user option

  // controls program flow
  while (1) {

    while (1) { // for user to input valid option
    DisplayLoggedIn(username);
      DisplayUserOptions(); // displays options
      scanf(" %c", &Option); // option input
      if (Option < '1' || Option > '5') { // checks if input is valid
        DisplayInvalidOption(); // displays error message
      }
      else break; // breaks from loop 
    }
  
    if (Option == '1') { // borrow a book

      if (numBooks == 0) DisplayNoBooks(); // outputs no books message
      else {
        DisplayBookHeader(); // outputs header
        DisplayBookArray(); // outputs books
      }

      // variable to store user input
      char* bookID = malloc (sizeof(int));
      // prompts user for input
      DisplayBorowBook();
      // stores input
      scanf(" %s", bookID);

      int validID = 1; // used to check if input is valid
      // checks for valid ID input
      for (int i = 0; i < strlen(bookID); i++) { // iterate through all characters in input
        if (isalpha(bookID[i])) { // if copies contains a letter
          DisplayInvalidID(); // outputs error message
          validID = 0; // invalid ID
          break; // ends loop
        }
      }
      
      if (validID) { // if valid book ID input

        // checks if book is out on loan
        for (int i = 0; i < numLoans; i++) { // iterates through loans
          if (loans[i]->bookid == atoi(bookID)) { // if a loan exists with same book ID
            validID = 0; // not valid book to borrow
            DisplayExistingCopy();
            break;
          }
        }
      }

      if (validID) {
        for (int i = 0; i < numBooks; i++) { // iterate through books

          // if book with matching ID is found
          // if there is at least one copy of the book in the library
          if (books[i]->id == atoi(bookID) && books[i]->copies >= 1) { 

            Loan* loanBook = malloc (sizeof(Loan)); // creates loan
            strcpy(loanBook->username, username); // copies username to loan
            loanBook->bookid = atoi(bookID); // stores book ID in the loan
            loans[numLoans] = loanBook; // stores the loan in the array of loans
            numLoans++; // increments number of loans
            books[i]->copies--; // decrements the copies of the book
            DisplayBorrowSuccess(); // output borrow success message
          }
        }
      }
    }
    else if (Option == '2') { // return a book
      
      int currentLoan = 0; // used for outputting header and managing output
      // displays all current user loans
      for (int i = 0; i < numLoans; i++) { // iterates through loans
        // if user has a loan
        // if loan has been returned
        if (strcmp(loans[i]->username, username) == 0 && loans[i]->bookid != -99) {
          currentLoan++; // increments as user has a loan
          if (currentLoan == 1) DisplayBookHeader(); // displays header
          DisplayBook(books[loans[i]->bookid]); // displays book
        }
      }

      if (currentLoan) { // if user has a loan they can return
        // variable to store user input
        char* bookID = malloc (sizeof(int));
        // prompts user for input
        DisplayReturnBook();
        // stores input
        scanf(" %s", bookID);

        int validID = 1; // used to check if input is valid
        // checks for valid ID input
        for (int i = 0; i < strlen(bookID); i++) { // iterate through all characters in input
          if (isalpha(bookID[i])) { // if copies contains a letter
            DisplayInvalidID(); // outputs error message
            validID = 0; // invalid ID
            break; // ends loop
          }
        }
        
        if (validID) { // if valid book ID input

          // checks if book is out on loan
          for (int i = 0; i < numLoans; i++) { // iterates through loans
          // if a loan exists with same book ID
          // if user has book on loan
            if (loans[i]->bookid == atoi(bookID) && strcmp(loans[i]->username, username) == 0) { 
              loans[i]->bookid = -99; // removes loan
              // increment book copies
              books[atoi(bookID)]->copies++;
              // end loop as book has been returned
              break;
            }
          }
        }
      }
      else DisplayNoBookLoan (); // outputs error message
    }
    else if (Option == '3') { // book search
      BookSearch();
    }
    else if (Option == '4') { // display books
      if (numBooks == 0) DisplayNoBooks(); // outputs no books message
      else {
        DisplayBookHeader(); // outputs header
        DisplayBookArray(); // outputs books
      }
    }
    else if (Option == '5') { // quit
      DisplayLogOut(); // show quit message
      return 0; // logs out
    }
  }
}

// main function for entire program
// handles interface
int main (void) {

  char Option; // variable used to store user option

  // loads all files
  FILE* infile;
  load_books(infile);
  LoadAccounts();
  LoadLoans();

  // controls program flow
  while (1) {

    while (1) { // for user to input valid option
      DisplayOptions(); // displays options
      scanf(" %c", &Option); // option input
      if (Option < '1' || Option > '5') { // checks if input is valid
        DisplayInvalidOption(); // displays error message
      }
      else break; // breaks from loop 
    }

    if (Option == '1') { // registration

      char *Name = malloc (30*sizeof (char)); // variable used to store user's name
      char *Username = malloc (30*sizeof (char)); // variable used to store user's username
      char *Password = malloc (30*sizeof (char)); // variable used to store user's password
      char *Email = malloc (30*sizeof (char)); // variable used to store user's email address

      // whilst inputs are valid
      while(1) {
            
        // prompt input display
        // stores name input
        DisplayEnterName();
        scanf(" %s", Name);      

        // prompt input display
        // stores username input
        DisplayEnterUsername();      
        scanf(" %s", Username);

        // checks username does not already exist
        if (!ExistingUsernameCheck(Username)) { // if username is invalid
          DisplayUserExists(); // outputs message
          break; // ends while loop
        }

        // prompt input display
        // stores password input
        DisplayEnterPassword();      
        scanf(" %s", Password);

        // prompt input display
        // stores email input
        DisplayEnterEmail();
        scanf(" %s", Email);

        // check email is valid
        if (!EmailValidation(Email)) { // if email is invalid
          DisplayInvalidEmail(); // outputs message
          break; // ends while loop
        }   

        // allocates memory for account
        Account* registerUser = malloc(sizeof(Account));

        // copies all inputs into struct 
        strcpy(registerUser->name, Name);
        strcpy(registerUser->username, Username);
        strcpy(registerUser->password, Password);
        strcpy(registerUser->email, Email);

        accounts[numAccounts] = registerUser; // stores user in array
        numAccounts++; // increments number of accounts
        DisplayRegisterSuccess(); // if registration was successful
        // successful registration
        break;
      }
    }
    else if (Option == '2') { // login

      char *Username = malloc (30*sizeof (char)); // variable used to store user's username
      char *Password = malloc (30*sizeof (char)); // variable used to store user's password

      printf("\n"); // line break

      // prompt input display
      // stores username input
      DisplayEnterUsername();      
      scanf(" %s", Username);

      // prompt input display
      // stores password input
      DisplayEnterPassword();      
      scanf(" %s", Password);

       // if user has inputted administrator credentials
      if (strcmp(Username, "admin") == 0 && strcmp(Password, "admin") == 0) {
        AdminMenu(); // take user to administrator menu
      }
      // checks if user exists in users.bin file
      else if (UserExists(Username, Password)) { 
        UserMenu(Username); // take user to user menu
      }
      // invalid username/password
      else DisplayInvalidLogin(); // output error message
    }
    else if (Option == '3') { // book search
      BookSearch();
    }
    else if (Option == '4') { // display books
      if (numBooks == 0) DisplayNoBooks(); // outputs no books message
      else {
        DisplayBookHeader(); // outputs header
        DisplayBookArray(); // outputs books
      }
    }
    else if (Option == '5') { // quit
      // store data
      FILE *file;
      store_books(file);
      StoreLoans();
      StoreAccounts();
      DisplayQuit(); // show quit message 
      return 0; // ends function/program
    }
  }
  return 0;
}

//-----------------------------------------------------------------------------------------------------------------