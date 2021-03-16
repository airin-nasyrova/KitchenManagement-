#include <iostream>
#include <fstream>
using namespace std; 
#include "hashtable.h"

#ifndef INGREDIENTLIST_H
#define INGREDIENTLIST_H

struct Node {
string data;
struct Node* next = nullptr; 
};

class SinglyLinkedList {
	private:
		
	public: 
		Node* head;
		Node* tail;
		SinglyLinkedList();
		
		void push(string data);
		
		void print();
		
		string pop(string data);
};


class Ingredients: public SinglyLinkedList {
	private: 
		SinglyLinkedList ingredientList;
		HashMap hash;
		int count;
		
	public:
	
		Ingredients();
		
		~Ingredients();
		
		void add(void);
		
		string pop(void);
		
		bool isFound();
		
		bool isFoundV2(string);
		
		void print(void);
		
		void countTxt(void);
		
		void readFile(void);
		
		void writeFile(void);
		
		void update(void);
		
		
	};

#endif

