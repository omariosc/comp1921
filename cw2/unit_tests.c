/************************************************************************
University of Leeds
School of Computing
COMP1921 - Programming Project
Coursework 2
File: unit_tests.c

Purpose: 
- Used for testing functions in stringhandling.c

Student Name: Omar Choudhry
Student ID: 201398269
Email: sc20osc@leeds.ac.uk
Date Work Commenced: 27.04.2021
*************************************************************************/

#include "unity.h"
#include "stringhandling.h"

//-----------------------------------------------------------------------------------------------------------------

void Test_PreprocessedInput_Null () {
  char input[] = "", *result = PreprocessedInput(input);
  TEST_ASSERT_EQUAL_STRING_MESSAGE("", result, "Preprocessed input not null");
}

void Test_PreprocessedInput_Digit () {
  char input[] = "123", *result = PreprocessedInput(input);
  TEST_ASSERT_EQUAL_STRING_MESSAGE("", result, "Preprocessed input contains integers");
}

void Test_PreprocessedInput_Alpha () {
  char input[] = "abc", *result = PreprocessedInput(input);
  TEST_ASSERT_EQUAL_STRING_MESSAGE("ABC", result, "Preprocessed input contains non upper case letters");
}

void Test_PreprocessedInput_Spaces () {
  char input[] = " abc  def ", *result = PreprocessedInput(input);
  TEST_ASSERT_EQUAL_STRING_MESSAGE("ABC DEF", result, "Preprocessed input contains redundant spaces or non upper case letters");
}

void Test_PreprocessedInput_Symbol () {
  char input[] = ";',.", *result = PreprocessedInput(input);
  TEST_ASSERT_EQUAL_STRING_MESSAGE("", result, "Preprocessed input contains symbols");
}

void Test_PreprocessedInput_Upper () {
  char input[] = "ABC", *result = PreprocessedInput(input);
  TEST_ASSERT_EQUAL_STRING_MESSAGE("ABC", result, "Preprocessed input contains non upper case characters");
}

void Test_PreprocessedInput_Complete () {
  char input[] = " is  today  the  1st  of  the  month? ", *result = PreprocessedInput(input);
  TEST_ASSERT_EQUAL_STRING_MESSAGE("IS TODAY THE ST OF THE MONTH", result, "Returned incorrect preprocessed input");
}

void Test_NullInputCheck_Null () {                    TEST_ASSERT_EQUAL_INT_MESSAGE(1, NullInputCheck(""), "NullInputCheck returned incorrect error code"); }
void Test_NullInputCheck_NullCharacter () {           TEST_ASSERT_EQUAL_INT_MESSAGE(1, NullInputCheck("\0"), "NullInputCheck returned incorrect error code"); }
void Test_NullInputCheck_NonNull () {                 TEST_ASSERT_EQUAL_INT_MESSAGE(0, NullInputCheck("abc"), "NullInputCheck returned incorrect error code"); }
void Test_UserQuitCheck_ValidBye () {                 TEST_ASSERT_EQUAL_INT_MESSAGE(1, UserQuitCheck("BYE"), "UserQuitCheck returned incorrect error code"); }
void Test_UserQuitCheck_ValidGoodbye () {             TEST_ASSERT_EQUAL_INT_MESSAGE(1, UserQuitCheck("GOODBYE"), "UserQuitCheck returned incorrect error code"); }
void Test_UserQuitCheck_ValidByeSpace () {            TEST_ASSERT_EQUAL_INT_MESSAGE(1, UserQuitCheck("OK BYE"), "UserQuitCheck returned incorrect error code"); }
void Test_UserQuitCheck_ValidGoodbyeSpace () {        TEST_ASSERT_EQUAL_INT_MESSAGE(1, UserQuitCheck("GOODBYE FOR NOW"), "UserQuitCheck returned incorrect error code"); }
void Test_UserQuitCheck_Null () {                     TEST_ASSERT_EQUAL_INT_MESSAGE(0, UserQuitCheck(""), "UserQuitCheck returned incorrect error code"); }
void Test_UserQuitCheck_Invalid () {                  TEST_ASSERT_EQUAL_INT_MESSAGE(0, UserQuitCheck("GOOD"), "UserQuitCheck returned incorrect error code"); }
void Test_InputRepetitionCheck_Same () {              TEST_ASSERT_EQUAL_INT_MESSAGE(1, InputRepetitionCheck("abc", "abc"), "Inputs not similar"); }
void Test_InputRepetitionCheck_SimilarShort () {      TEST_ASSERT_EQUAL_INT_MESSAGE(0, InputRepetitionCheck("abcdef", "abcdeg"), "Inputs similar"); }
void Test_InputRepetitionCheck_SimilarLong () {       TEST_ASSERT_EQUAL_INT_MESSAGE(1, InputRepetitionCheck("abcdefgh", "abcdefgi"), "Inputs not similar"); }
void Test_InputRepetitionCheck_SimilarEqual () {      TEST_ASSERT_EQUAL_INT_MESSAGE(1, InputRepetitionCheck("abcdefg", "abcdefh"), "Inputs not similar"); }
void Test_InputRepetitionCheck_DifferentShort () {    TEST_ASSERT_EQUAL_INT_MESSAGE(0, InputRepetitionCheck("abcdef", "ghijkl"), "Inputs similar"); }
void Test_InputRepetitionCheck_DifferentLong () {     TEST_ASSERT_EQUAL_INT_MESSAGE(0, InputRepetitionCheck("abcdefgh", "ijklmnop"), "Inputs similar"); }
void Test_InputRepetitionCheck_DifferentEqual () {    TEST_ASSERT_EQUAL_INT_MESSAGE(0, InputRepetitionCheck("abcdefg", "hijklmn"), "Inputs similar"); }
void Test_InputRepetitionCheck_Null () {              TEST_ASSERT_EQUAL_INT_MESSAGE(1, InputRepetitionCheck("", ""), "Inputs not similar"); }

// Unity testing
void setUp () {}
void tearDown() {}

int main () {
  UNITY_BEGIN ();
  RUN_TEST (Test_PreprocessedInput_Null); // Testing preprocessing on null input
  RUN_TEST (Test_PreprocessedInput_Digit); // Testing preprocessing on all digit input
  RUN_TEST (Test_PreprocessedInput_Alpha); // Testing preprocessing on all alphabet input
  RUN_TEST (Test_PreprocessedInput_Spaces); // Testing preprocessing on input with extra spaces
  RUN_TEST (Test_PreprocessedInput_Symbol); // Testing preprocessing on all symbol input
  RUN_TEST (Test_PreprocessedInput_Complete); // Testing preprocessing on all upper case input
  RUN_TEST (Test_PreprocessedInput_Upper); // Testing preprocessing on a typical input
  RUN_TEST (Test_NullInputCheck_Null); // Testing null input check on null input
  RUN_TEST (Test_NullInputCheck_NonNull); // Testing null input check on end of string input
  RUN_TEST (Test_NullInputCheck_NullCharacter); // Testing null input check on non null input
  RUN_TEST (Test_UserQuitCheck_ValidBye); // Testing user quit check on valid quit message
  RUN_TEST (Test_UserQuitCheck_ValidGoodbye); // Testing user quit check on valid quit message with prefix
  RUN_TEST (Test_UserQuitCheck_ValidByeSpace); // Testing user quit check on valid quit message with space
  RUN_TEST (Test_UserQuitCheck_ValidGoodbyeSpace); // Testing user quit check on valid quit message with prefix and space
  RUN_TEST (Test_UserQuitCheck_Null); // Testing user quit check on null quit message
  RUN_TEST (Test_UserQuitCheck_Invalid); // Testing user quit check on invalid quit message
  RUN_TEST (Test_InputRepetitionCheck_Same); // Testing input repetition with same inputs
  RUN_TEST (Test_InputRepetitionCheck_SimilarShort); // Testing input repetition with similar inputs under length 7
  RUN_TEST (Test_InputRepetitionCheck_SimilarLong); // Testing input repetition with similar inputs over length 7
  RUN_TEST (Test_InputRepetitionCheck_SimilarEqual); // Testing input repetition with similar inputs with length 7
  RUN_TEST (Test_InputRepetitionCheck_DifferentShort); // Testing input repetition with different inputs under length 7
  RUN_TEST (Test_InputRepetitionCheck_DifferentLong); // Testing input repetition with different inputs over length 7
  RUN_TEST (Test_InputRepetitionCheck_DifferentEqual); // Testing input repetition with different inputs with length 7
  RUN_TEST (Test_InputRepetitionCheck_Null); // Testing input repetition with null inputs
  return UNITY_END ();
}

//-----------------------------------------------------------------------------------------------------------------