#include <iostream>
#include <fstream>
using namespace std; 

#include "hashtable.h"
#include "ingredientList.h"

	SinglyLinkedList::SinglyLinkedList() : head(nullptr), tail(nullptr) {}
	
	void SinglyLinkedList::push(string data) {
		Node *tmp = new Node;
		tmp->data = data; //initialize tmp Node with data

		if(head == NULL) { //if no data in list, 
							//then set both head and tail to same node
			head = tmp;
			tail = tmp;
		}
		else { 
			//if list has something in it
			//then make a new tail to hold the 
			//next Node with the new data.
			tail->next = tmp; //
			tail = tail->next;
		}
	}
	
	void SinglyLinkedList::print() {
		Node* tmp = nullptr;
		if (head == nullptr) {
			cout << "The singly linked list is empty!" << endl;
		} else {
			tmp = head;
			while (tmp->next != nullptr) {
				cout<< tmp->data << endl;
				tmp = tmp->next;
			}
			cout << tmp->data << endl;
		}
		
	}
	
	string SinglyLinkedList::pop(string data) {
		Node* tmp = head;
		if (tmp->data == data) {
			head = tmp->next;
			cin.clear();
			cin.sync();
			return data;
		}
		Node* beforeDelete = nullptr;
		while (tmp->data != data && tmp->next != nullptr) {
			beforeDelete = tmp;
			tmp = tmp->next;
		}
		if (tmp->data == data) {
			beforeDelete->next = tmp->next;
			delete tmp;
			cin.clear();
			cin.sync();
			return data;
		} else {
			cout << "Item not found!" << endl;
			cin.clear();
			cin.sync();
			return "-1";
		}
	}



	
		Ingredients::Ingredients() {
			readFile();
				
		}
		
		Ingredients::~Ingredients() {
			writeFile();
		}
		
		void Ingredients::add(void) {
			string tmp;
			cout << "Enter additional ingredient: ";
			cin.clear();
			cin.sync();
			getline(cin, tmp, '\n');
			hash.insert(tmp, tmp);
			ingredientList.push(tmp);
			writeFile();
			readFile();
			cin.clear();
			cin.sync();
		}
		
		string Ingredients::pop() {
			string tmp;
			cout << "Enter ingredient you would like to remove: ";
			cin.clear();
			cin.sync();
			getline(cin, tmp, '\n');
			ingredientList.pop(tmp);
			hash.remove(tmp);
			writeFile();
			readFile();
			cin.clear();
			cin.sync();
			return ingredientList.pop(tmp);
		}
		
		bool Ingredients::isFound() {
			bool result;
			string tmp;
			cout << "Enter ingredient you would like to search for: ";
			cin.clear();
			cin.sync();
			getline(cin, tmp, '\n');
			result = hash.search(tmp);
			cin.clear();
			cin.sync();
			if (result) {
				cout << "Found!" << endl;
			} 
			else {
				cout << "Not Found!" << endl; 
				}
			
			return result;
		}
		
		bool Ingredients::isFoundV2(string str) {
			bool result;
			result = hash.search(str);
			return result;
		}
		
		void Ingredients::print(void) {
			ingredientList.print();
			cout << endl;
		}
		
		void Ingredients::countTxt(void) {
			ifstream myfile;
			string tmpString;
			count = 0;
			myfile.open("ingredients.txt");

			//check for error
			if (myfile.fail()) {
				cerr << "Error Opening File" << endl;
				exit(1);
			}
			getline(myfile, tmpString);
			
			if (tmpString[0] == '\0') {
				cout << "The text file is empty!" << endl;
			} else if (tmpString[0] == '*') {
				getline(myfile, tmpString);
				/* cout << "3." << tmpString << endl; */
				/* cout << tmpString[0] << endl; */
				for (int i = 0; tmpString[0] != '*'; i++) {
					getline(myfile, tmpString);
					count = i + 1;
				}
			} else cout << "Ingredient List is not properly structured!\n" 
						<< "Please use the following structure in the txt file:\n"
						<< "*\ningredient1\ningredient2\ningredientN\n*\n\n"
						<< "An empty ingredient list should look like:\n"
						<< "*\n*" << endl;
		}
		
		void Ingredients::readFile(void) {
			if (ingredientList.head != nullptr) {
				delete ingredientList.head;
				ingredientList.head = nullptr;
			}
			ifstream myfile;
			string tmpString;
			myfile.open("ingredients.txt");
			countTxt();
			if(count == 0) { 
				cout << "You have no ingredients!" << endl;
				
			} 
			else {
				//check for error
				if (myfile.fail()) {
					cerr << "Error Opening File" << endl;
					exit(1);
				}
				
				getline(myfile, tmpString);
				getline(myfile, tmpString);
				/* cout << "3." << tmpString << endl; */
				/* cout << tmpString[0] << endl; */
				for (int i = 0; tmpString[0] != '*'; i++) {
					ingredientList.push(tmpString);
					hash.insert(tmpString, tmpString);
					getline(myfile, tmpString);
				}
				myfile.close();
			}	
		}
		
		void Ingredients::writeFile(void) {
			Node* tmp = nullptr;
			ofstream myfile;
			myfile.open("ingredients.txt");

			//check for error
			if (myfile.fail()) {
				cerr << "Error Opening File" << endl;
				exit(1);
			}
			if (ingredientList.head == nullptr) {
				myfile << "*\n*";
			} else {
				myfile << "*" << endl;
				tmp = ingredientList.head;
				while (tmp->next != nullptr) {
					myfile << tmp->data << endl;
					tmp = tmp->next;
				}
				myfile << tmp->data << endl;
				myfile << "*";
			}

			myfile.close();
		}
		
		void Ingredients::update(void) {
			writeFile();
			hash.removeAll();
			readFile();
		}
	/*
int main() {
	Ingredients ingredList;

	ingredList.print();
	
	ingredList.add();
	
	ingredList.print();
	
	ingredList.add();
	
	ingredList.print();
	
	ingredList.add();
	
	ingredList.print();
	
	ingredList.isFound();
	
	ingredList.pop();
	ingredList.print();
	
	ingredList.pop();
	ingredList.print();
	
	ingredList.pop();
	ingredList.print();
	

}



	*/