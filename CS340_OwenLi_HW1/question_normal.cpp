#include "question_normal.h"

void question_normal::question_normalSet(string s) {
	animal = s;
	ques = "Is your animal " + s + " ?";
}

string question_normal::question_normalAnimal() {
	for (int i = ques.size() - 3; i >= 0; i--) {
		if (ques[i] == ' ') {
			animal = ques.substr(i, ques.size() - i-2);
		}
	}
	return animal;
}
