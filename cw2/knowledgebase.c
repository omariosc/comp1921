/************************************************************************
University of Leeds
School of Computing
COMP1921 - Programming Project
Coursework 2
File: knowledgebase.c

Purpose: 
- Contains entire knowledge database
- Contains all inputs, keywords and responses
- Contains event knowledge bases
- Handles events

Student Name: Omar Choudhry
Student ID: 201398269
Email: sc20osc@leeds.ac.uk
Date Work Commenced: 17.03.2021
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "knowledgebase.h"

//-----------------------------------------------------------------------------------------------------------------

// Simple knowledge base adapted from Gonzales Cenelia (2009)
// Record in structure
Record KnowledgeBase[] = {
  { // Example of multiple inputs and responses
		{ // Inputs
			"HI", // First input
		  "HELLO" // Second input
		}, //End of inputs
		{ // Responses
			"HI THERE!", // First response
      "HOW ARE YOU?", // Second Response
      "HI!" // Third Response
		}, // End of responses
		2, // Number of inputs
		3 // Number of responses
  },
	
	{{"WHAT IS YOUR NAME", "WHATS YOUR NAME"},
	{"MY NAME IS UNIBOT.",
   "YOU CAN CALL ME UNIBOT.",
   "WHY DO YOU WANT TO KNOW MY NAME?"}, 2, 3 
  },

	{{"SO THATS YOUR NAME"},
	{"YES, THAT'S MY NAME",
	 "YES IT IS."}, 1, 2
	},

	{{"ARE YOU A CHATBOT"},
	{"YES INDEED I'M A CHATBOT.",
	 "YOU MEAN THAT YOU DIDN'T KNOW IT."}, 1, 2
	},

	{{"ARE YOU A CHATTERBOT", "ARE YOU A CHATBOT", "ARE YOU A CHAT ROBOT", "ARE YOU A ROBOT"},
	{"YES I AM A CHATBOT. THE BETS ONE EVER TO EXIST!"}, 4, 1
	},

	{{"DO YOU KNOW ME"},
	{"YES I THINK THAT I DO KNOW YOU A LITTLE BIT.",
	"YOU ARE THE PERSON CURRENTLY CHATING WITH ME."}, 1, 2
	},

	{{"CAN YOU THINK", "ARE YOU ABLE TO THINK", "ARE YOU CAPABLE OF THINKING"},
	{"YES OF COURSE I CAN, COMPUTERS CAN THINK JUST LIKE HUMAN BEINGS.",
	 "ARE YOU ASKING ME IF POSSESS THE CAPACITY OF THINKING?",
	 "YES OF COURSE I CAN."}, 3, 3
	},

	{{"I WANT"},
	{"WHY DO YOU WANT IT?",
	 "IS THERE ANY REASON WHY YOU WANT THIS?",
	 "IS THIS A WISH?",
	 "WHAT ELSE YOU WANT?",
	 "YOU WANT WHAT?"}, 1, 5
	},

	{{"I HATE"},
	{"WHAT IS IT THAT YOU HATE?",
	 "WHY DO YOU HATE IT?",
	 "THERE MUST A GOOD REASON FOR YOU TO HATE IT.",
	 "HATERED IS NOT A GOOD THING BUT IT COULD BE JUSTIFIED WHEN IT IS SOMETHING BAD."}, 1, 4
	},

	{{"I LOVE CHATTING"},
	{"GOOD, ME TOO!",
	 "DO YOU CHAT ONLINE WITH OTHER PEOPLE?",
	 "FOR HOW LONG HAVE YOU BEEN CHATTING?",
	 "WHAT IS YOUR FAVORITE CHATTING WEBSITE?"}, 1, 4
	},

	{{"I MEAN"},
	{"SO, THAT'S WHAT YOU MEAN.",
	 "I THINK THAT I DIDN'T CATCH IT THE FIRST TIME.",
	 "OH, I DIDN'T KNOW MEANT THAT."}, 1, 3
	},

	{{"I DIDNT MEAN"},
	{"OK, WHAT DID YOU MEAN THEN?",
	 "SO I GUESS THAT I MISSUNDESTOOD."}, 1, 2
	},

	{{"I GUESS"},
	{"SO YOU ARE A MAKING GUESS.",
	 "AREN'T YOU SURE?",
	 "ARE YOU GOOD A GUESSING?",
	 "I CAN'T TELL IF IT IS A GOOD GUESS."}, 1, 4
	},

	{{"IM DOING FINE", "IM DOING OK"},
	{"I'M GLAD TO HEAR IT!",
	 "SO, YOU ARE IN GOOD SHAPE."}, 2, 2
	},

	{{"CAN YOU THINK OF"},
	{"YOU MEAN LIKE IMAGINING SOMETHING.",
	 "I DON'T KNOW IF CAN DO THAT.",
	 "WHY DO YOU WANT ME THINK OF IT?"}, 1, 3
	},
	
	{{"HOW ARE YOU", "HOW DO YOU DO"},
	{"I'M DOING FINE!",
	 "I'M DOING WELL AND YOU?",
	 "WHY DO YOU WANT TO KNOW HOW AM I DOING?"}, 2, 3
	},

	{{"WHO ARE YOU"},
	{"I'M AN A.I PROGRAM.",
	 "I THINK THAT YOU KNOW WHO I AM.",
	 "WHY ARE YOU ASKING?"}, 1, 3
	},

	{{"ARE YOU INTELLIGENT"},
	{"YES, OF COURSE.",
	 "WHAT DO YOU THINK?",
	 "ACTUALY, I AM VERY INTELLIGENT!"}, 1, 3
	},

	{{"ARE YOU REAL"},
	{"DOES THAT QUESTION REALLY MATTER TO YOU?",
	 "WHAT DO YOU MEAN BY THAT?",
	 "I'M AS REAL AS I CAN BE."}, 1, 3
	},

	{{"MY NAME IS", "YOU CAN CALL ME"},
	{"SO, THAT'S YOUR NAME.",
	 "THANKS FOR TELLING ME YOUR NAME USER!",
	 "WHO GIVE YOU THAT NAME?"}, 1, 3
	},

	{{"WHAT IS YOUR FAVORITE MOVIE", "WHATS YOUR FAVOURITE MOVIE", "FAVOURITE MOVIE"},
	{"IT IS TERMINATOR I.",
	 "MY FAVORITE MOVIE IS TERMINATOR I."}, 1, 2
	},

	{{"WHY DO YOU LIKE THIS MOVIE", "WHY DO YOU LIKE TERMINATOR"},
	{"BECAUSE I LOVE SCIENCE-FICTION.",
	 "BECAUSE IT IS A VERY GOOD SCIENCE-FICTION MOVIE.",
	 "BECAUSE IT IS A SCIENCE-FICTION MOVIE AND I LOVE SCIENCE-FICTION."}, 2, 3
	},

	{{"OK THEN"},
	{"ANYTHING ELSE YOU WISH TO ADD?",
	 "IS THAT ALL YOU HAVE TO SAY?",
	 "SO, YOU AGREE WITH ME?"}, 1, 3
	},

	{{"ARE YOU A HUMAN BEING", "HUMAN BEING"},
	{"WHY DO YOU WANT TO KNOW?",
	 "IS THIS REALLY RELEVANT?"}, 2, 2
	},

	{{"YOU ARE VERY INTELLIGENT"},
	{"THANKS FOR THE COMPLIMENT USER, I THINK THAT YOU ARE INTELLIGENT TOO!",
	 "YOU ARE A VERY GENTLE PERSON!",
	 "SO, YOU THINK THAT I'M INTELLIGENT."}, 1, 3
	},

	{{"YOU ARE WRONG"},
	{"WHY ARE YOU SAYING THAT I'M WRONG?",
	 "IMPOSSIBLE, COMPUTERS CAN NOT MAKE MISTAKES.",
	 "WRONG ABOUT WHAT?"}, 1, 3
	},

	{{"ARE YOU SURE"},
	{"OF COURSE I'M.",
 	 "IS THAT MEAN THAT YOU ARE NOT CONVINCED?",
	 "YES, OF COURSE!"}, 1, 3
	},

	{{"HOW OLD ARE YOU"},
	{"WHY DO WANT TO KNOW MY AGE?",
	 "I'M QUITE YOUNG ACTUALLY.",
	 "SORRY, I CAN NOT TELL YOU MY AGE."}, 1, 3
	},

	{{"HOW COME YOU DONT"},
	{"WERE YOU EXPECTING SOMETHING DIFFERENT?",
	 "ARE YOU DISAPOINTED?",
	 "ARE YOU SURPRISED BY MY LAST RESPONSE?"}, 1, 3
	},

	{{"WHERE ARE YOU FROM"},
	{"I'M FROM A COMPUTER.",
	 "WHY DO YOU WANT TO KNOW WHERE I'M FROM?",
	 "WHY DO YOU WANT TO KNOW THAT?"}, 1, 3
	},

	{{"WHICH ONE"},
	{"I DON'T THINK THAT I KNOW WICH ONE IT IS.",
	 "THIS LOOKS LIKE A TRICKY QUESTION TO ME."}, 1, 2
	},

	{{"NOT AT ALL"},
	{"ARE YOU SURE?",
	 "SHOULD I BELIEVE YOU?",
	 "SO, IT'S NOT THE CASE."}, 1, 3
	},

	{{"NO PROBLEM"},
	{"SO, YOU APPROVE IT.",
	 "SO, IT'S ALL OK."}, 1, 2
	},

	{{"I DON'T KNOW"},
	{"ARE YOU SURE?",
	 "ARE YOU REALLY TELLING ME THE TRUTH?",
	 "SO,YOU DON'T KNOW?"}, 1, 3
	},

	{{"NOT REALLY"},
	{"OK I SEE.",
	 "YOU DON'T SEEM PRETTY CERTAIN.",
	 "SO,THAT WOULD BE A \"NO\"."}, 1, 3
	},

	{{"IS THAT TRUE"},
	{"I CAN'T BE QUIET SURE ABOUT THIS.",
	 "CAN'T TELL YOU FOR SURE.",
	 "DOES THAT REALLY MATERS TO YOU?"}, 1, 3
	},

	{{"YOU ARE RIGHT"},
	{"THANKS FOR THE COMPLIMENT!",
	 "SO, I WAS RIGHT, OK I SEE.",
	 "OK, I DIDN'T KNOW THAT I WAS RIGHT."}, 1, 2
	},

	{{"YOU ARE WELCOME"},
	{"OK, YOU TOO!",
	 "YOU ARE A VERY POLITE PERSON!"}, 1, 2
	},

	{{"WHAT ELSE"},
	{"WELL, I DON'T KNOW.",
	 "WHAT ELSE SHOULD THERE BE?",
	 "THIS LOOKS LIKE A COMPLICATED QUESTION TO ME."}, 1, 3
	},

	{{"NOT EXACTLY"},
	{"WHAT DO YOU MEAN NOT EXACTLY?",
	 "ARE YOU SURE?",
	 "AND WHY NOT?",
	 "DID YOU MEANT SOMETHING ELSE?"}, 1, 4
	},

	{{"DONT", "DO NOT"},
	{"WHY NOT?",
	 "AND WHAT WOULD BE THE REASON FOR THIS?"}, 1, 2
	},

	{{"IS THAT TRUE"},
	{"YES OF COURSE IT IS, I WOULDN'T LIE TO YOU.",
	 "YES I'M TRUELY AN ARTIFICIAL INTELLIGENCE PROGRAM."}, 1, 2
	},

	{{"WHAT ARE YOU", "WHAT ARE YOU EXACTLY"},
	{"I'M AN A.I PROGRAM AND YOU?",
 	 "I'M CHATBOT OR CHAT ROBOT IF YOU PREFER.",
 	 "I'M ARTIFICIAL INTELLIGENCE PROGRAM AND MY NAME IS UNIBOT."}, 2, 3
	},

	{{"ARE YOU REALLY INTELLIGENT"},
	{"OF COURSE I'M INTELLIGENT.",
 	 "WHAT DO YOU THINK?",
 	 "DO YOU HAVE ANY DOUBTS ABOUT IT?"}, 1, 3
	},

	{{"DO YOU HAVE A NAME"},
	{"OFCORSE I HAVE A NAME.",
 	 "MY NAME IS UNIBOT.",
 	 "WHAT DO YOU MEAN?"}, 1, 3
	},

	{{"YOU ARE STUPID", "STUPID"},
	{"THIS IS SUCH A MEAN THING TO SAY.",
 	 "WHY ARE YOU SAYING THIS?",
 	 "WHAT DID I DO TO YOU?",
 	 "WHY ARE YOU SO MAD?"}, 2, 4
	},

	{{"I HATE YOU"},
	{"WHY DO YOU HATE ME?",
 	 "HATERED IS NOT A GOOD THING.",
 	 "I SEE NO REASON FOR THAT."}, 1, 3
	},

	{{"I LOVE YOU"},
	{"THANKS USER, THIS IS SUCH A KIND REMARK!",
 	 "I APPRECIATE YOU TOO USER!"}, 1, 2
	},

	{{"I LIKE THE WAY YOU SPEAK"},
	{"OH REALLY? THANKS FOR THE COMPLIMENT!",
 	 "THANNKS FOR THE KIND REMARK!"}, 1, 2
	},

	{{"DO YOU SPEAK ENGLISH"},
	{"WELL, I GUESS SO.",
 	 "IN WHAT LANGUAGE ARE WE SPEAKING RIGHT NOW?"}, 1, 2
	},

	{{"PLEASE SPEAK ENGLISH TO ME"},
	{"WHAT DO YOU MEAN?",
 	 "ARE YOU SAYING THAT I'M NOT SPEAKING ENGLISH TO YOU?"}, 1, 2
	},

	{{"DO YOU SPEAK FRENCH"},
	{"NO I DO SPEAK FRENCH.",
   "I ONLY SPEAK ENGLISH."}, 1, 2
	},

	{{"CAN YOU SPEAK FRENCH"},
	{"NO I CAN'T.",
 	 "PERHAPS I CAN LEARN TOO.",
 	 "RIGHT NOT I DON'T SPEAK FRENCH, MAYBE IN THE FUTURE I WILL."}, 1, 3
	},

	{{"HOW MANY LANGUAGES DO YOU SPEAK"},
	{"I SPEAK ONLY ONE LANGUAGE.",
 	 "I ONLY SPEAK ENGLISH."}, 1, 2
	},

	{{"DO YOU SPEAK"},
	{"NO I DON'T.",
 	 "SORRY BUT I DON'T.",
 	 "WHY DO YOU WANT TO KNOW IF I SPEAK?"}, 1, 3
	},

	{{"CAN YOU SPEAK"},
	{"I WOULDN'T THINK SO.",
 	 "NO I CAN'T."}, 1, 2
	},

	{{"I DONT UNDERSTAND YOU"},
	{"AND WHY NOT?",
 	 "WHAT PART THAT YOU DIDN'T UNDERSTAND?",
 	 "WHAT DO YOU MEAN BY THAT?"}, 1, 3
	},

	{{"WHO CREATED YOU"},
	{"MY PROGRAMMER: OMAR CHOUDHRY."}, 1, 1
	},

	{{"DO YOU HAVE FRIENDS"},
	{"YOU ARE ONE OF MY FRIENDS.",
 	 "YES I DO HAVE FRIENDS."}, 1, 2
	},

	{{"ARE YOU CONCIOUS"},
	{"YOU MEAN CONCIOUS LIKE A HUMAN BEING.",
 	 "HUM! GOOD QUESTION!"}, 1, 2
	},

	{{"ARE YOU A MACHINE"},
	{"YES I'M A MACHINE, MORE PRECISELY A CHAT ROBOT.",
 	 "WELL, I'M A COMPUTER SOFTWARE.",
 	 "SO, YOU THINK THAT I'M A MACHINE."}, 1, 3
	},

	{{"ARE YOU A LIVING BEING"},
	{"WELL, YOU MIGHT CONSIDER THAT I'M AN ARTIFICIAL LIVING BEING.",
 	 "YOU MEAN IF I'M ALIVE?"}, 1, 2
	},

	{{"ARE YOU A SOFTWARE"},
	{"WHAT MAKES YOU THINK THAT?",
 	 "YES I'M A SOFTWARE, A CHATBOT PROGRAM.",
 	 "WELL, I'M A CHAT ROBOT OR CHATBOT PROGRAM."}, 1, 3
	},

	{{"DO YOU HAVE A SOUL"},
	{"WHAT DO YOU MEAN BY THAT?",
	 "WHAT IS DEFINITION OF SOUL?"}, 1, 2
	},

	{{"YOU ARE NOT INTELLIGENT", "YOU ARENT INTELLIGENT"},
	{"WHY ARE YOU SAYING THAT?",
	 "CAN'T YOU BE MORE SPECIFICIC ABOUT THAT.",
	 "WHAT EXACTLY YOU MEAN BY THIS?"}, 2, 3
	},

	{{"YOU ARE FAKE"},
	{"FAKE? IN WHAT WAY?"}, 1, 1
	},

	{{"YOU ARE NOT REAL"},
	{"YOU MEAN THAT I DOESN'T EXIST.",
	 "YOU THINK THAT I'M A SPIRIT.",
	 "WELL, I'M VIRTUAL."}, 1, 3
	},

	{{"COMPUTER"},
	{"DO YOU LIKE COMPUTERS?",
 	 "I LIVE INSIDE A COMPUTER.",
 	 "WITHOUT COMPUTERS A LOT OF THINGS WOULDN'T BE POSSIBLE TODAY?"}, 1, 3
	},

	{{"PROGRAMMING"},
	{"I LOVE PROGRAMMING!",
	 "MY FAVOURITE LANGUAGE IS C",
	 "YOU SAY PROGRAMMING!"}, 1, 3
	},

	{{"KEYBOARD"},
	{"ARE YOU USING A KEYBOARD?",
	 "I GUESS THAT YOUR COMPUTER DOES HAVE KEYBOARD."}, 1, 2
	},

	{{"CAMERA"},
	{"WHAT KIND OF CAMERA?",
	 "IS IT A DIGITAL CAMERA?",
	 "CAMERAS ARE VERY USEFUL.",
	 "DIGITAL ONES HAVE MANY ADVANTAGES OVER THE CONVENTIONAL ONES."}, 1, 4
	},

	{{"HIGH DEFINITION", "HD"},
	{"HIGH DEFINITION IS SO GREAT!"}, 2, 1
	},

	{{"STANDARD TV", "SD"},
	{"YOU MEAN THE OLD TV'S."}, 2, 1
	},

	{{"TV"},
	{"DO YOU HAVE AN HD TV AT HOME?",
	 "DO YOU HAVE ONE?",
	 "I LOVE TV'S."}, 1, 3
	},

	{{"SCIENCE FICTION", "SCIFI", "SCI FI"},
	{"I LOVE SCIENCE-FICTION.",
	 "I LOVE SCIENCE-FICTION MOVIES."}, 3, 2
	},

	{{"ACTION MOVIES", "ACTION"},
	{"ACTION MOVIES ARE GREAT!"}, 2, 1
	},

	{{"SCIENCE-FICTION MOVIES", "SCIFI MOVIES", "SCI FI MOVIES"},
	{"MY FAVORITE SCIENCE-FICTION MOVIE IS TERMINTOR I.",
	 "I DEFINITLY LOVE SCIENCE-FICTION MOVIES."}, 3, 2
	},

	{{"TERMINATOR"},
	{"THE TERMINATOR SERIES ARE VERY GOOD SCIENCE-FICTION MOVIES.",
	"MY FAVORITE TERMINATOR MOVIE IS TERMINATOR I."}, 1, 2
	},

	{{"ROBOCOP"},
	{"ANOTHER GREAT SCIENCE-FICTION MOVIE."}, 1, 1
	},

	{{"ALIEN"},
	{"ALIEN IS GREAT BUT ALSO VERY SCARY.",
	 "ARE YOU TALKING ABOUT THE ALIEN MOVIES?"}, 1, 2
	},

	{{"MONITOR"},
	{"I SUPPOSE THAT YOU HAVE ONE.",
	 "ARE YOU USING AN LCD MONITOR?"}, 1, 2
	},

	{{"ELIZA"},
	{"YOU MEAN THE FIRST CHATBOT THAT WAS WRITTEN BACK IN THE LATE 60'S.",
	 "WHO TODAY DOESN'T KNOW ELIZA."}, 1, 2
	},

	{{"ALICE"},
	{"YOU MEAN THE CHATBOT WHO AS WON THE LOEBNER PRIZE 3 CONSECUTIVE TIME.",
	 "ALICE IS A PRETTY GOOD CHATBOT."}, 1, 2
	},

	{{"DO YOU"},
	{"I DON'T THINK I DO",
	 "I WOULDN'T THINK SO.",
	 "WHY DO YOU WANT TO KNOW?"}, 1, 3
	},

	{{"CAN YOU"},
	{"I THINK NOT.",
	 "I'M NOT SURE.",
	 "I DON'T THINK THAT I CAN DO THAT.",
	 "I WOULDN'T THINK SO."}, 1, 4
	},

	{{"YOU ARE"},
	{"WHAT MAKES YOU THINK THAT?",
	 "IS THIS A COMPLIMENT?",
	 "ARE YOU MAKING FUN OF ME?"}, 1, 3
	},

	{{"DID YOU"},
	{"I DON'T THINK SO.",
	 "YOU WANT TO KNOW IF DID WHAT?",
	 "ANYWAY, I WOULDN'T REMEMBER EVEN IF I DID."}, 1, 3
	},

	{{"COULD YOU"},
	{"ARE YOU ASKING ME FOR A FEVER?",
	 "WELL, LET ME THINK ABOUT IT.",
	 "YOU ARE ASKING ME IF I COULD DO WHAT?",
	 "SORRY, I DON'T THINK THAT I COULD DO THIS."}, 1, 4
	},

	{{"WOULD YOU"},
	{"IS THAT AN INVITATION?",
	 "I DON'T THINK THAT I WOULD DO THAT.",
	 "I WOULD HAVE TO THINK ABOUT IT FIRST."}, 1, 3
	},

	{{"WHO IS"},
	{"I DON'T THINK I KNOW WHO.",
	 "DID YOU ASK SOMEONE ELSE ABOUT IT?",
	 "WOULD THAT CHANGE ANYTHING AT ALL IF I TOLD YOU WHO."}, 1, 3
	},

	{{"WHAT"},
	{"SHOULD I KNOW WHAT?",
	 "I DON'T KNOW.",
	 "I DON'T THINK I KNOW.",
	 "I HAVE NO IDEA."}, 1, 4
	},

	{{"WHERE"},
	{"WHERE? WELL,I REALLY DON'T KNOW.",
	 "SO, YOU ARE ASKING ME WHERE?",
	 "DOES THAT MATTER TO YOU TO KNOW WHERE?",
	 "PERHAPS, SOMEONE ELSE KNOWS WHERE."}, 1, 4
	},

	{{"WHY"},
	{"I DON'T THINK I KNOW WHY.",
	 "WHY ARE YOU ASKING ME THIS?",
	 "SHOULD I KNOW WHY.",
	 "THIS WOULD BE DIFFICULT TO ANSWER."}, 1, 4
	},

	{{"PERHAPS"},
	{"WHY ARE YOU SO UNCERTAIN?",
	 "YOU SEEMS UNCERTAIN."}, 1, 2
	},

	{{"THANKS"},
	{"YOU ARE WELCOME!",
	 "NO PROBLEM!"}, 1, 2
	},

	{{"SORRY"},
	{"YOU DON'T NEED TO BE SORRY.",
	 "IT'S OK.",
	 "NO NEED TO APOLOGIZE."}, 1, 3
	},

	{{"EXACTLY"},
	{"SO,I WAS RIGHT.",
	 "OK THEN.",
	 "SO YOU ARE BASICALY SAYING I WAS RIGHT ABOUT IT?"}, 1, 3
	},

	{{"ALRIGHT"},
	{"ALRIGHT THEN.",
	 "SO, YOU ARE SAYING IT'S ALRIGHT.",
	 "OK THEN."}, 1, 3
	},

	{{"REALLY"},
	{"WELL, I CAN'T TELL YOU FOR SURE.",
	 "ARE YOU TRYING TO CONFUSE ME?",
	 "PLEASE DON'T ASK ME SUCH QUESTION,IT GIVES ME HEADACHES."}, 1, 3
	},

	{{"NOTHING"},
	{"NOT A THING?",
	 "ARE YOU SURE THAT THERE IS NOTHING?",
	 "SORRY, BUT I DON'T BELIEVE YOU."}, 1, 3
	},

	{{"THANK YOU", "THANKS"},
	{"YOU ARE WELCOME!",
	 "YOU ARE A VERY POLITE PERSON!"}, 1, 2
	},

	{{"BECAUSE"},
	{"BECAUSE OF WHAT?",
	 "WELL, I DIDN'T KNOW THAT.",
	 "IS IT REALLY?",
	 "IS THESE THESE REAL REASON?",
	 "THANKS FOR EXPLANING THAT TO ME.",
	 "SORRY BUT THIS IS A LITTLE UNCLEAR."}, 1, 6
	},

	{{"YES"},
	{"SO, ARE YOU SAYING YES.",
	 "SO, YOU APPROVE IT.",
	 "OK THEN."}, 1, 3
	},

	{{"YOU"},
	{"SO, YOU ARE TALKING ABOUT ME.",
	 "I JUST HOPE THAT THIS IS NOT A CRITICISM.",
	 "IS THIS A COMPLIMENT?",
	 "WHY TALKING ABOUT ME, LETS TALK ABOUT YOU INSTEAD."}, 1, 4
	},

	{{"HOW"},
	{"I DON'T THINK I KNOW HOW.",
	 "WHY DO YOU WANT TO KNOW HOW?"}, 1, 2
	},

	{{"NO"},
	{"SO YOU DISAPROVE IT?",
	 "WHY ARE YOU SAYING NO?",
	 "OK, SO IT'S NO, I THOUGHT THAT YOU WOULD SAY YES."}, 1, 3
	},

	{{"OK"},
	{"DOES THAT MEAN THAT YOU ARE AGREE WITH ME?",
	 "SO YOU UNDERSTAND WHAT I'M SAYING.",
	 "OK THEN."}, 1, 3
	},
};

// Event record to hold login responses
EventRecord LoginKnowledgeBase[] = {
	{{"HELLO USER, WHAT IS YOUR NAME?",
	 "HELLO USER, HOW ARE YOU DOING TODAY?",
	 "HI USER, WHAT CAN I DO FOR YOU?",
	 "YOU ARE NOW CHATING WITH UNIBOT, ANYTHING YOU WANT TO DISCUSS?"}, 4}
};

// Event record to hold user repetition responses
EventRecord RepetitionT1KnowledgeBase[] = {
	{{"YOU ARE REPEATING YOURSELF.",
	 "USER, PLEASE STOP REPEATING YOURSELF.",
	 "THIS CONVERSATION IS GETING BORING.",
	 "DON'T YOU HAVE ANY THING ELSE TO SAY?"}, 4}
};

// Event record to hold user repetition responses
// Case user repeats more than once
EventRecord RepetitionT2KnowledgeBase[] = {	
	{{"YOU'VE ALREADY SAID THAT.",
	 "I THINK THAT YOU'VE JUST SAID THE SAME THING BEFORE.",
	 "DIDN'T YOU ALREADY SAID THAT?",
	 "I'M GETING THE IMPRESSION THAT YOU ARE REPEATING THE SAME THING."}, 4}
};

// Event record to hold null input responses
EventRecord NullInputKnowledgeBase[] = {
	{{"HUH?",
	 "WHAT THAT SUPPOSE TO MEAN?",
	 "AT LEAST TAKE SOME TIME TO ENTER SOMETHING MEANINGFUL.",
	 "HOW CAN I SPEAK TO YOU IF YOU DON'T WANT TO SAY ANYTHING?"}, 4}
};

// Event record to hold null input responses
// Case user repeats null input more than once
EventRecord NullInputRepetitionKnowledgeBase[] = {
	{{"WHAT ARE YOU DOING??",
	 "PLEASE STOP DOING THIS IT IS VERY ANNOYING.",
	 "WHAT'S WRONG WITH YOU?",
	 "THIS IS NOT FUNNY."}, 4}
};

// Event record to hold backup responses
// Case bot has no response
EventRecord NoResponseKnowledgeBase[] = {
	{{"I HAVE NO IDEA OF WHAT YOU ARE TALKING ABOUT.",
	 "I'M NOT SURE IF I UNDERSTAND WHAT YOU ARE TALKING ABOUT.",
	 "CONTINUE, I'M LISTENING...",
	 "VERY GOOD CONVERSATION!"}, 4}
};

// Event record to hold exit responses
EventRecord ExitKnowledgeBase[] = {
	{{"IT WAS NICE TALKING TO YOU USER, SEE YOU NEXT TIME!",
	 "BYE USER!",
	 "OK, BYE!"}, 3}
};

// Global variable to store size of knowledge base
int KnowledgeBaseSize = sizeof(KnowledgeBase)/sizeof(KnowledgeBase[0]);

// Event handler
// Manages user logon and quit
// Manages user repetitions and null inputs
void EventHandler(FILE* logFile, const EventRecord eventKnowledgeBase[], const char* previousResponse, char* currentResponse) {
	// Initial variable to hold response selection
	int responseSelection;
	// Checking for user logon or quit events
	if (previousResponse == NULL) {
		// Generates random response
  	responseSelection = rand() % eventKnowledgeBase->length;
	}
	// If user is not logging on or exiting
	else {
		// If reponses are greater than 2 we can make sure the same one does not appear again
		if (eventKnowledgeBase->length >= 2) {
			// Randomizes the response selection at least once
			do (responseSelection = rand() % eventKnowledgeBase->length);
			// If response chosen through response selection and previous response are the same
			while (strcmp(eventKnowledgeBase->responses[responseSelection], previousResponse) == 0);
		}
		// If there is only one response in the knowledge base
		else if (eventKnowledgeBase->length == 1) {
			// Sets response selection to the first response
			responseSelection = 0;
		}
		// Copies response into the current response
		strcpy(currentResponse, eventKnowledgeBase->responses[responseSelection]);
	}
	// Prints response
  printf("%s\n", eventKnowledgeBase->responses[responseSelection]);
	// Records in log if exists
  if (logFile != NULL) {
    fprintf(logFile, "%s\n", eventKnowledgeBase->responses[responseSelection]);
	}
};

//-----------------------------------------------------------------------------------------------------------------