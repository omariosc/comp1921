/************************************************************************
University of Leeds
School of Computing
COMP1921 - Programming Project
Coursework 1
File: graph.c
Purpose:
- Handles graphical outputs and prompts
Student Name: Omar Choudhry
Student ID: 201398269
Email: sc20osc@leeds.ac.uk
Date Work Commenced: 24.02.2020
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"
#include "graph.h"
#include "logic.h"
//-----------------------------------------------------------------------------------------------------------------

// displays all options
void DisplayOptions() {
  printf("\n\nPlease choose an option:\n");
  printf("1) Register an account\n");
  printf("2) Login\n");
  printf("3) Search for books\n");
  printf("4) Display all books\n");
  printf("5) Quit\n");
  printf("Option: ");
}

// display a specific book
void DisplayBook(const struct Book* book) {
  printf("%i\t%s\t\t\t%s\t\t\t%i\t%i\n", book->id, book->title,
  book->authors, book->year, book->copies);
}

// displays all books
void DisplayBookArray() {
  for (int i = 0; i < numBooks; i++) { // displays all books details for number of books 
    DisplayBook(books[i]);
  }
}

// displays invalid option error message
void DisplayInvalidOption() {
  printf("\nSorry, the option you entered was invalid, please try again.\n");
}

// displays enter name message
void DisplayEnterName() {
  printf("\nPlease enter a name: ");
}

// displays enter username message
void DisplayEnterUsername() {
  printf("Please enter a username: ");
}

// displays enter password message
void DisplayEnterPassword() {
  printf("Please enter a password: ");
}

// displays enter email message
void DisplayEnterEmail() {
  printf("Please enter an email: ");
}

// displays user exists message
void DisplayUserExists() {
  printf("\nSorry, registration unsuccessful, the uername you entered already exists.\n");
}

// displays user logged in message
void DisplayLoggedIn(const char* username) {
  printf("\nLogged in as: %s", username);
}

// displays admin options
void DisplayAdminOptions() {
  printf("\n\nPlease choose an option:\n");
  printf("1) Add a book\n");
  printf("2) Remove a book\n");
  printf("3) Search for books\n");
  printf("4) Display all books\n");
  printf("5) Log out\n");
  printf("Option: ");
}

// displays add book message
void DisplayTitleBook() {
  printf("\nEnter the title of the book you wish to add: ");
}

// displays author of the book message
void DisplayAuthorBook() {
  printf("Enter the author of the book you wish to add: ");
}

// displays year of the book message
void DisplayYearBook() {
  printf("Enter the year that the book you wish to add was released: ");
}

// displays copies of the book message
void DisplayCopiesBook() {
  printf("Enter the number of copies of the book you wish to add: ");
}

// displays successful book addition
void DisplaySuccessBookAdd() {
  printf("\nBook was added successfully!\n\n");
}

// displays invalid book addition
void DisplayInvalidBookAdd() {
  printf("\nSorry, you attempted to add an invalid book, please try again.\n\n");
}

// displays search menu options
void DisplaySearchOptions() {
  printf("\n\nLoading search menu...\n\n");
  printf("1) Find books by title\n");
  printf("2) Find books by author\n");
  printf("3) Find books by year\n");
  printf("4) Return to previous menu\n");
  printf("Option: ");
}

// displays title search message
void DisplaySearchTitleBook() {
  printf("\nEnter the title you wish to search: ");
}

// displays author search message
void DisplaySearchAuthorBook() {
  printf("\nEnter the author you wish to search: ");
}

// displays year search message
void DisplaySearchYearBook() {
  printf("\nEnter the publication year that you wish to search: ");
}

// displays returning previous menu message
void DisplayReturnMenu () {
  printf("\nReturning to previous menu...\n");
}

// displays logging out message
void DisplayLogOut () {
  printf("\nLogging out...\n");
}

// displays account registration success message
void DisplayRegisterSuccess () {
  printf("\nRegistered library account successfully!\n");
}

// displays regular user options
void DisplayUserOptions () {
  printf("\n\nPlease choose an option:\n");
  printf("1) Borrow a book\n");
  printf("2) Return a book\n");
  printf("3) Search for books\n");
  printf("4) Display all books\n");
  printf("5) Log out\n");
  printf("Option: ");
}

// displays borrow book message
void DisplayBorowBook () {
  printf("\nEnter the ID number of the book you wish to borrow: ");
}

// displays successful borrow book message
void DisplayBorrowSuccess () {
  printf("\nYou have successfuly borrowed the book!\n");
}

// displays existing copy message
void DisplayExistingCopy () {
  printf("\nSorry, you already have a copy of this book on loan.\n");
}

// displays returning book message
void DisplayReturnBook () {
  printf("\nEnter the ID number of the book you wish to return: ");
}

// displays currently borrowing books
void DisplayLoaned () {
  printf("\nBelow is the list of Books you are currently borrowing:");
}

// displays successful book return message
void DisplayReturnSuccess () {
  printf("\nReturned book successfully!.\n");
}

// displays quit message
void DisplayQuit () {
  printf("\nThank you for using the library!\n");
  printf("Goodbye!\n");
}

// displays email invalid message
void DisplayInvalidEmail () {
  printf("\nSorry, the email you have entered is invalid.\n");
}

// displays invalid login message
void DisplayInvalidLogin () {
  printf("\nSorry, the username or password you have entered is incorrect.\n");
}

// displays book header for displaying books
void DisplayBookHeader () {
  printf("\nID\tTitle\t\t\tAuthors\t\t\tYear\tCopies\n");
}

// displays no books in library message
void DisplayNoBooks () {
  printf("\nSorry, there are no books in the library.\n");
}

// displays no books found message
void DisplayNoBookFound () {
  printf("\nSorry, there are no books in the library that meet your search criteria.\n");
}

// displays no books on loan message
void DisplayNoBookLoan () {
  printf("\nSorry, you do not have any books on loan.\n");
}

// displays error in removing book message
void DisplayErrorRemoval() {
  printf("\nSorry, there was an error in removing the book.\n");
}

// displays book removal prompt
void DisplayBookRemoval() {
  printf("\nEnter the ID of the book you would like to remove: ");
}

// displays invalid book ID message
void DisplayInvalidID() {
  printf("\nSorry, the Book ID you have entered in invalid.\n");
}

// displays successful book removal
void DisplaySuccessBookRemoval() {
  printf("\nBook was removed successfully!\n\n");
}

// displays invalid removal message
void DisplayInvalidRemovalonLoan() {
  printf("\nSorry, the book you are trying to remove is currently on loan\n");
}

// displays error in author input
void DisplayInvalidAuthorInput() {
  printf("\nSorry, the author of the book you have entered is invalid.\n");
}

// displays error in year input
void DisplayInvalidYearInput() {
  printf("\nSorry, the year of the book you have entered is invalid.\n");
}

//-----------------------------------------------------------------------------------------------------------------