#ifndef QUESTION_H
#define QUESTION_H
#include <iostream>

using namespace std;


//Create a Question Class 
//works exactly the same as a binary tree
//but storing string instead of int
//and a boolean to decide yes or no
//*** we also create a previous node to know where to insert a new question *****

class question {
public:
	question(); // constructor
	void questionSet(string s);
	void questionReply(); // ask for a yes and no response and save the response into the answer bool
	string questionShow(); // print out the question
	bool questionNf();
	bool questionReturn();
protected:
	bool answer; //determine yes or no path
	bool nf; //determine if the question is normal final
	string ques; //question
};


#endif
