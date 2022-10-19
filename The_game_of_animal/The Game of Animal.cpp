#include <iostream>
#include <sstream>
#include <fstream>
#include "Question.h"
#include "question_normal.h"

using namespace std;


//take the root note and traverse it 
//DFS preorder traversal
//at the end of each question shows 0 or 1 to indicate leaf or not
void traverse(question_normal* root, ofstream &file) {
	if (!root) {
		file << "null" <<endl << "1" <<endl;
		return; 
	}
	else {
		//check if it is a leaf
			file << root->questionShow() << endl;
			if (root->yes || root->no) {
				file << "0" << endl;
				traverse(root->yes, file);
				traverse(root->no, file);
			}
			else {
				file << "1" << endl;
			}
	}
		
}

//this allows users to generate a txt file that stores the questions he/she just created
void downloadData(question_normal* root) {
	cout << endl << "What do you want to call your text file? : " << endl;
	string input;
	cin >> input;
	ofstream output(input + ".txt");
	traverse(root,output);
	output.close();
}

question_normal* parseData(string filename) {
	ifstream infile;
	infile.open(filename);
	//check for file if not a file exit the program
	if (!infile.is_open()) {
		cout << "Can't open this file!" << endl << endl;
		exit(0); 
	}
	//if we here means the file opens
	cin.ignore();
	string s;
	//initialize the treenode first 
	question_normal* root = new question_normal();
	question_normal* yes = new question_normal();
	question_normal* no = new question_normal();
	getline(infile, s); 
	root->questionSet(s);
	root->no = no;
	root->yes = yes;
	root->yes->prev = root;
	root->no->prev = root;
	while (getline(infile, s)) {
		//we are reading from a preorder tree
		//so we have to read from the last most tree path first untill it finds a leaf
		if (s == "") {
			getline(infile, s);
			getline(infile, s);
		}
		else if (s != "0" && s != "1") { //if this is not a leaf indicator
			//if the yes node has not been taken go to the left node
			if (root->yes->questionShow() == "") root = root->yes;
			else if (root->no->questionShow() == "") root = root->no;
				question_normal* yes = new question_normal();
				question_normal* no = new question_normal();
				root->questionSet(s);
				root->no = no;
				root->yes = yes;
				root->yes->prev = root;
				root->no->prev = root;
			
		}
		// if where there is a 1 as a leaf node go back to the previous
		else if(s == "1"){			
			root = root->prev;
 
			while (root->yes->questionShow() != "" && root->no->questionShow() != "" && root -> prev) {
				root = root->prev;
			}
		}

	}
	infile.close();
	return root;
}


int main()
{
	question_normal* root = new question_normal();
	char begin = 'y';
	while (begin == 'y') {
		char cont = 'y';
		cout << "********************************" << endl
			<< "Welcome to AKINATOUR" << endl
			<< "think about an animal and I would try to guess it" << endl
			<< "LET'S START!!!" << endl << endl;
		string load = "";
		//check for error input
		while (load == "")
		{
			cout << "Do you have a text file to load for the database? (y/n): " << endl;
			cin >> load;
				cin.ignore();
			if (load != "y" && load != "n") {
				cout << "invalid character" << endl;
			}
		}
			cout << endl;
			//if no data base start with default 
			if (load == "n") {
				root->questionSet("Does your animal swim underwater?");
				question_normal* right = new question_normal();
				right->question_normalSet("horse");
				right->prev = root;
				question_normal* left = new question_normal();
				left->question_normalSet("shark");
				left->prev = root;
				root->yes = left;
				root->no = right;
			}
			else if (load == "y") {
				cout << "Enter the filename that you want to load: ";
				string filename;
				cin >> filename;
				root = parseData(filename);
			}
			question_normal* starting = root;
		while (cont == 'y') {
			bool bad = true;
			bool enter = false;
			bool hit = true;
			while (root && bad) {
				//if we hit null means that there is no data at this path and no matching animal at all
				//hit means that there is no animal to compare with
				if (root->questionShow() == "null") {
					if (!root->questionReturn()) {
						cout << "Sorry could not find your animal" << endl;
						hit = false;
						enter = true;
					}
					bad = false;
				}
				else if (root->questionShow() == "") {
					bad = false;
					root = root->prev; 
					if (!root->questionReturn()) {
						enter = true;
					}
					else enter = false;
				}
				//else if the node is not a leaf
				else if (root) {
					root->questionReply();
					if (!root->yes && !root->no) {
						if (!root->questionReturn()) {
							enter = true;
						}
						bad = false;
					}
					else if (root->questionReturn()) root = root->yes;
					else {
						if (!root->no) {
							question_normal* nn = new question_normal();
							root->no = nn;
							cout << "Sorry could not find your animal" << endl;
							hit = false;
							enter = true;
							bad = false;
							root->no->prev = root; 
						}
						 root = root->no; 
					}
				}
				//else just leave the loop
				else {
					cout << "Sorry could not find your animal" << endl;
					hit = false;
					enter = true;
					bad = false;
				}
			}
			//at this point we didnt guess the correct answer ask the user to improve our data
			if (enter) {
				string new_ques;
				string animal;
				string ny="";
				cout << endl << endl << "Which animal are you thinking about? " << endl;
				cin.ignore();
				getline(cin, animal);
				cout << "Provide us with a characteristic about this animal" << endl
					<< animal << " is / has ... : ";
				getline(cin, new_ques);
				if (hit == true) {
					cout << "Does " << root->question_normalAnimal() << " is / has " << new_ques << " too ? (y/n) " << endl;
					cin >> ny;
				}
				//create a new question and put it into the database
				//n_root = the new question that the user put
				//a_root = the leaf node of a new animal
				//root = the previous question before leaf node
				//temp = the leaf node animal
				question_normal* n_root = new question_normal();
				n_root->questionSet("Is / Does your animal " + new_ques + " ?");
				question_normal* temp = NULL;
				question_normal* a_root = new question_normal();
				a_root->question_normalSet(animal);
				a_root->prev = n_root;
				n_root->prev = root;
				n_root->yes = a_root;
				if (ny == ""){
					root = root->prev;
					root->no = n_root;
				}
				else {
					temp = root;
					root = root->prev;
					//if the current question is on the yes tree
					if (root->questionReturn()) {
						root->yes = n_root;
					}
					//if the current question is on the no tree
					else {
						root->no = n_root;
					}
					//if the question provides does not match with the last animal
					if (ny == "n") {
						temp->prev = n_root;
						n_root->no = temp;
					}
					//if the question provided match with the last animal
					if (ny == "y") {
						a_root->no = temp;
						temp->prev = a_root;
					}
				}
			}
			/*while (root->prev) { 
				cout << "here" << endl;
				root = root->prev;
			}*/
			root = starting; 
			cout << "Do you want to play again? (y/n) : ";
			cin >> cont;
			cout << endl << endl;
			bad = true;
		}
		cout << "Do you want to export your data as an text file? (y/n): ";
		char whatever;
		cin >> whatever;
		if(whatever == 'y')downloadData(root);
		cout << endl << "Do you want to start from the begginning? (y/n): ";
		cin >> begin;
	}

}

