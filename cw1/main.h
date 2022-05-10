/************************************************************************
University of Leeds
School of Computing
COMP1921 - Programming Project
Coursework 1
File: main.h

Purpose:
- Contains function prototypes for main.c

Student Name: Omar Choudhry
Student ID: 201398269
Email: sc20osc@leeds.ac.uk
Date Work Commenced: 24.02.2020
*************************************************************************/

#include <stdio.h>

//-----------------------------------------------------------------------------------------------------------------

// main function for entire program
// handles interface
int main (void);

// administrator menu
// can add and remove books
int AdminMenu(void);

// regular user menu
// can borrow and return books
int UserMenu(const char* username);

//-----------------------------------------------------------------------------------------------------------------
