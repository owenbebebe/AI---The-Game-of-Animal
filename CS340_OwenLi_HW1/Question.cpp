#include "Question.h"



question::question() {
	ques = "";
}

void question::questionSet(string s) {
	ques = s;
}

//print out the question and ask user for ues or no input
//store the result in bool:answer;
void question::questionReply() {
	cout << ques << " (y/n) " << endl;
	//check for valid yes and no
	string temp;
	cin >> temp;
	if (temp == "y") answer = true;
	else if (temp == "n") answer = false;
	else {
		//print out error
		cout << "invalid character" << endl;
		questionReply();
	}
}

string question::questionShow() {
	return ques;
}

//return the type of question (normal or final)
bool question::questionNf() {
	return nf;
}

//return the yes or no path 
bool question::questionReturn() {
	return answer;
}