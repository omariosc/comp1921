/************************************************************************
University of Leeds
School of Computing
COMP1921 - Programming Project
Coursework 1
File: logic.h

Purpose:
- Contains function prototypes for logic.c
- Account and Loan structures
- Defines maximum values
- Defines admin credentials
- Declares important global arays and vars

Student Name: Omar Choudhry
Student ID: 201398269
Email: sc20osc@leeds.ac.uk
Date Work Commenced: 24.02.2020
*************************************************************************/

#include <stdio.h>

#define MaxAccount 100
#define MaxLoan 100
#define MaxBook 100
#define AdminUsername "admin"
#define AdminPassword "admin"

//-----------------------------------------------------------------------------------------------------------------

// structure containing user account information
typedef struct {
  char name[30]; // user's registered name
  char username[30]; // user's username for logging on
  char password[30]; // user's password for logging on
  char email[30]; // user's registered email
} Account; 

// structure containing information about a loan
typedef struct {
  char username[30]; // user in the loan
  unsigned int bookid; // book ID in the loan
} Loan;

// global variables
extern int numBooks; // number of books
extern int numAccounts; // number of accounts
extern int numLoans; // number of loans
extern char adminUsername[5]; // admin username
extern char adminPassword[5]; // admin password

// global arrays
extern Account* accounts[MaxAccount];	// the array of accounts
extern Loan* loans[MaxLoan]; // the array of loans
extern struct Book* books[MaxBook]; // the array of books

// stores accounts into file
// returns 0 if file not found
// returns 1 after file written to successfully
int StoreAccounts (void);

// loads accounts from file
// returns 0 if file not found
// returns 1 after file read from successfully
int LoadAccounts (void);

// stores loans into file
// returns 0 if file not found
// returns 1 after file written to successfully
int StoreLoans (void);

// loads loans from file
// returns 0 if file not found
// returns 1 after file read from successfully
int LoadLoans (void);

// checks that username is unique
// returns 1 if username exists
// returns 0 if username is unique
int ExistingUsernameCheck(const char* username);

// checks that email contains the @ symbol
// returns 1 if email is valid
// returns 0 if email is invalid
int EmailValidation (const char* email);

// checks that user credentials are correct
// returns 1 if user exists
// returns 0 if invalid credentials
int UserExists(const char* username, const char* password);

// book search menu
// displays menu
// search by title, author or year
// returns 0 when user returns to previous menu
int BookSearch(void);

//-----------------------------------------------------------------------------------------------------------------