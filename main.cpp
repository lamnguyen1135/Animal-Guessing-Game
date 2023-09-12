/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
using namespace std;
#include <iostream>
#include <string>


struct animalNode
{
  string question;		//a question to ask the user
  string guess;			//the name of an animal to guess
  animalNode *yesAnswer;	//null or pointer to the byesb animalNode
  animalNode *noAnswer;		//null or pointer to the bnob animalNode
};
bool controlflag = false;
string temp, animalanswer;
class binary_tree
{
  animalNode *curPointer, *headPointer, *tailPointer;

public:  binary_tree ()
  {
    curPointer = NULL;
    tailPointer = NULL;
    headPointer = NULL;
  }



  void first ()
  {
    string guessanswer, tryagainanswer, animalanswer, question, answeryesorno,
      tryagain, temp, tryagainanswer2, questionanswer;
    bool gameEnd = false;
    int yes = 1;
    bool f = false;
    animalNode *curPointer = new animalNode;	//establishes the first node to first ask the user if it is a lizard or not
    curPointer->guess = "Lizard";
    curPointer->yesAnswer = NULL;
    curPointer->noAnswer = NULL;
    tailPointer = curPointer;
    while (gameEnd == false)	//initiates a while loop until the game is finished
      {
	if (f == true)
	  {			//here it establishes current pointer as the headpointer if f is true, later down the code, there will be a place that sets f to be true
	    //when this is asked, the game is restarted
	    curPointer = headPointer;
	    f = false;
	  }
	if ((curPointer->yesAnswer == NULL || curPointer->noAnswer == NULL))	//if both is null, computer will take a guess
	  {
	    cout << "Is it a(an) " << curPointer->guess << "? ";
	    getline (cin, guessanswer);
	    if (guessanswer == "Yes" || guessanswer == "yes")
	      {
		cout << "Good! I guessed your animal." << endl <<
		  "Try again? ";
		getline (cin, tryagainanswer);
		if (tryagainanswer == "Yes" || tryagainanswer == "yes")
		  {
		    if (headPointer == NULL)
		      {

		      }
		    else
		      {
			curPointer = headPointer;	//sets the current pointer to headpointer(the beginning) when user wannts to try again
		      }
		  }
		else
		  {
		    cout << "Program is quitting" << endl;
		    return;
		  }
	      }

	    else
	      {			//when the program gets the guess wrong, it goes through here
		cout << "Bummer! What animal were you thinking of? ";
		getline (cin, animalanswer);
		cout << "What is a yes/no question that I can use to tell a "
		  << curPointer->guess << " from " << animalanswer << "? ";
		getline (cin, question);
		cout << "For a " << animalanswer <<
		  ", is the answer yes or no? ";
		getline (cin, answeryesorno);
		cout << "Try again? ";
		getline (cin, tryagainanswer2);
		temp = curPointer->guess;
		delete (curPointer);	//deletes the unecessary node now
		if (tryagainanswer2 == "yes" || tryagainanswer2 == "Yes")
		  {
		    animalNode *curPointer = new animalNode;	//creates a new node, add the questions user entered into it, and if it is the first question,
		    curPointer->question = question;	// it will be the headpointer
		    tailPointer = curPointer;
		    if (headPointer == NULL)
		      {
			headPointer = curPointer;
			tailPointer = curPointer;
		      }

		    if (answeryesorno == "yes" || answeryesorno == "Yes")	//if the question's answer is yes to the provided animal, it goes through here
		      {
			//creating node for no asnwer
			animalNode *curPointer = new animalNode;
			curPointer->guess = temp;	//creating node for no answer
			tailPointer->noAnswer = curPointer;	//tail pointer servers to make yesAnswer and NoAnswer that is being created here, then direct it back
			curPointer->yesAnswer = NULL;	//to where the current pointer is
			curPointer->noAnswer = NULL;

			if (yes == 1)
			  {	//for some reason i need this if statement in order to create a new node, i dont know why though, but this
			    animalNode *curPointer = new animalNode;	//if statement will always be true
			    curPointer->yesAnswer = NULL;
			    curPointer->noAnswer = NULL;
			    curPointer->guess = animalanswer;	//creating node for yes answer
			    tailPointer->yesAnswer = curPointer;
			    tailPointer = tailPointer->yesAnswer;

			    curPointer = headPointer;
			    f = true;	//here if the program goes through this if statement, f will be set to true, so that the program knows the game restarted
			  }

			if (controlflag == true)
			  {	//debug
			    cout << curPointer->guess << endl;
			    cout << curPointer->question << endl;
			    cout << curPointer->yesAnswer << endl;
			    cout << curPointer->noAnswer << endl;
			  }
		      }
		    else	//if the question's answer is no to the provided animal, it goes through here, same code as above but just reversed
		      {
			animalNode *curPointer = new animalNode;
			curPointer->guess = temp;
			curPointer->yesAnswer = NULL;
			curPointer->noAnswer = NULL;
			tailPointer->yesAnswer = curPointer;

			if (yes == 1)
			  {
			    animalNode *curPointer = new animalNode;
			    curPointer->guess = animalanswer;
			    curPointer->yesAnswer = NULL;
			    curPointer->noAnswer = NULL;
			    tailPointer->noAnswer = curPointer;
			    tailPointer = tailPointer->yesAnswer;
			    curPointer = headPointer;
			    f = true;
			  }
		      }

		  }
		else
		  {
		    cout << "Program is quitting3" << endl;
		    return;
		  }
	      }
	  }
	else
	  {			//here the current pointer is pointing to a question.
	    cout << curPointer->question << " ";
	    getline (cin, questionanswer);
	    if (questionanswer == "Yes" || questionanswer == "yes")
	      {

		curPointer = curPointer->yesAnswer;	//if user enters yes, then it points to the yesAnswer

	      }
	    else
	      {
		curPointer = curPointer->noAnswer;	//if user enters no, then it points to noAnswer
	      }

	  }

      }
  }
};


int
main ()
{
  binary_tree a;
  string Ready;
  cout << "Let's play the Guess the Animal game." << endl;
  cout << "Think of an animal and type ready when you're ready. ";
  getline (cin, Ready);
  if (Ready == "Ready" || Ready == "ready")
    {
      a.first ();
    }


}
