
#include "Question.h"

class question_normal : public question
{
public: 
	question_normal() : question() {
		yes = NULL;
		no = NULL;
		prev = NULL;
		nf = true;
	}
	void question_normalSet(string s);
	string question_normalAnimal();
	question_normal* prev;
	question_normal* yes;
	question_normal* no;
private: 
	string animal;
};

