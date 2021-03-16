#include <iostream>
#include <fstream>
using namespace std; 
#include "recipe.h"
#include "ingredientList.h"


	SinglyLinkedListV2::SinglyLinkedListV2() : head(nullptr), tail(nullptr) {}
		
	void SinglyLinkedListV2::push(string data) {
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
	
	void SinglyLinkedListV2::print() {
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
	
	void SinglyLinkedListV2::printwNum() {
		Node* tmp = nullptr;
		int count = 1;
		if (head == nullptr) {
			cout << "The singly linked list is empty!" << endl;
		} else {
			tmp = head;
			while (tmp->next != nullptr) {
				cout << count << ". " << tmp->data << endl;
				tmp = tmp->next;
				count++;
			}
			cout << count << ". " << tmp->data << endl;
		}
		
	}
	
	string SinglyLinkedListV2::pop(string data) {
		Node* tmp = head;
		if (tmp->data == data) {
			head = tmp->next;
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
			return data;
		} else {
			cout << "Item not found!" << endl;
			return "-1";
		}
	}
	
	void SinglyLinkedListV2::popAll(void) {
		if (head == nullptr) {
			cout << "List is already empty" << endl;
		}
		else {
			head = nullptr;
			tail = nullptr;
			head->next = nullptr;
			tail->next = nullptr;
		}
	}
	
	

	RecipeLinkedList::RecipeLinkedList() : head(nullptr), tail(nullptr) {}
	
	void RecipeLinkedList::push(Recipe data) {
		//cout << "Pushing Recipe: " << data.name << endl;
		NodeR *tmp = new NodeR;
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
	
	void RecipeLinkedList::printRecipes() {
		NodeR* tmp = nullptr;
		int count = 1;
		if (head == nullptr) {
			cout << "The singly linked list is empty!" << endl;
		} else {
			tmp = head;
			while (tmp->next != nullptr) {
				cout << count << ". " << tmp->data.name << endl;
				tmp = tmp->next;
				count++;
			}
			cout << count << ". " << tmp->data.name << endl;
		}
		
	}
	
	void RecipeLinkedList::printARecipes() {
		NodeR* tmp = nullptr;
		int count = 1;
		if (head == nullptr) {
			cout << "The singly linked list is empty!" << endl;
		} else {
			tmp = head;
			while (tmp->next != nullptr) {
				if (tmp->data.available) {
					cout << count << ". " << tmp->data.name << endl;
				}
				tmp = tmp->next;
				count++;
			}
			if (tmp->data.available) {
					cout << count << ". " << tmp->data.name << endl;
			}
		}
		
	}
	
	
	void RecipeLinkedList::printURecipes() {
		NodeR* tmp = nullptr;
		int count = 1;
		if (head == nullptr) {
			cout << "The singly linked list is empty!" << endl;
		} else {
			tmp = head;
			while (tmp->next != nullptr) {
				if (!(tmp->data.available)) {
					cout << count << ". " << tmp->data.name << endl;
				}
				tmp = tmp->next;
				count++;
			}
			if (!(tmp->data.available)) {
					cout << count << ". " << tmp->data.name << endl;
				}
		}
		
	}
	
	void RecipeLinkedList::printRecipeAt(int n) {
		NodeR* tmp = nullptr;
		int count = 1;
		if (head == nullptr) {
			cout << "The singly linked list is empty!" << endl;
		} else {
			tmp = head;
			while (tmp->next != nullptr) {
				if (count == n) {
					cout << count << ". " << tmp->data.name << endl;
				}
				tmp = tmp->next;
				count++;
			}
			if (count == n) {
				cout << count << ". " << tmp->data.name << endl;
			}
		}
	}
	
	void RecipeLinkedList::printRecipeTimesAt(int n) {
		NodeR* tmp = nullptr;
		int count = 1;
		if (head == nullptr) {
			cout << "The singly linked list is empty!" << endl;
		} else {
			tmp = head;
			while (tmp->next != nullptr) {
				if (count == n) {
					cout << "Preptime: " << tmp->data.prepTime << " minutes."<< endl;
					cout << "Cooktime: " << tmp->data.cookTime << " minutes."<< endl;
					cout << "Totaltime: " << tmp->data.totalTime << " minutes."<< endl;
				}
				tmp = tmp->next;
				count++;
			}
			if (count == n) {
				cout << "Preptime: " << tmp->data.prepTime << " minutes."<< endl;
				cout << "Cooktime: " << tmp->data.cookTime << " minutes."<< endl;
				cout << "Totaltime: " << tmp->data.totalTime << " minutes."<< endl;
			}
		}
	}
	
	void RecipeLinkedList::printIngredientsAt(int n) {
		NodeR* tmp = nullptr;
		int count = 1;
		if (head == nullptr) {
			cout << "The singly linked list is empty!" << endl;
		} else {
			tmp = head;
			while (tmp->next != nullptr) {
				if (count == n) {
					tmp->data.ingredientList.print();
				}
				tmp = tmp->next;
				count++;
			}
			if (count == n) {
				tmp->data.ingredientList.print();
			}
		}
	}
	
	void RecipeLinkedList::printUIngredientsAt(int n) {
		NodeR* tmp = nullptr;
		int count = 1;
		if (head == nullptr) {
			cout << "The singly linked list is empty!" << endl;
		} else {
			tmp = head;
			while (tmp->next != nullptr) {
				if (count == n) {
					tmp->data.unavailableList.print();
				}
				tmp = tmp->next;
				count++;
			}
			if (count == n) {
				tmp->data.unavailableList.print();
			}
		}
	}
	
	void RecipeLinkedList::printStepsAt(int n) {
		NodeR* tmp = nullptr;
		int count = 1;
		if (head == nullptr) {
			cout << "The singly linked list is empty!" << endl;
		} else {
			tmp = head;
			while (tmp->next != nullptr) {
				if (count == n) {
					tmp->data.steps.print();
				}
				tmp = tmp->next;
				count++;
			}
			if (count == n) {
				tmp->data.steps.print();
			}
		}
	}
	
	void RecipeLinkedList::printIngredients(string name) {
		NodeR* tmp = head;
		if (tmp->data.name == name) {
			cout << "Here are the ingredients of the Recipe: " << name << ": " << endl;

			tmp->data.ingredientList.print();
		
		}
		else {
			NodeR* beforeDelete = nullptr;
			while (tmp->data.name != name && tmp->next != nullptr) {
				beforeDelete = tmp;
				tmp = tmp->next;
			}
			if (tmp->data.name == name) {
				cout << "Here are the ingredients in the Recipe: " << name << ": " << endl;
				tmp->data.ingredientList.print();
			} else {
				cout << "Item not found!" << endl;
			}
		}
	}
	
	void RecipeLinkedList::printSteps(string name){
		NodeR* tmp = head;
		if (tmp->data.name == name) {
			cout << "Here are the steps of the Recipe: " << name << ": " << endl;
			tmp->data.steps.printwNum();
		
		}
		else {
			NodeR* beforeDelete = nullptr;
			while (tmp->data.name != name && tmp->next != nullptr) {
				beforeDelete = tmp;
				tmp = tmp->next;
			}
			if (tmp->data.name == name) {
				cout << "Here are the steps in the Recipe: " << name << ": " << endl;
				tmp->data.steps.printwNum();
			} else {
				cout << "Item not found!" << endl;
			}
		}
	}
	
	void RecipeLinkedList::printUnavailable(string name){
		NodeR* tmp = head;
		if (tmp->data.name == name) {
			cout << "Here are the unavailable ingredients for the Recipe: " << name << ": " << endl;
			tmp->data.unavailableList.printwNum();
		
		}
		else {
			NodeR* beforeDelete = nullptr;
			while (tmp->data.name != name && tmp->next != nullptr) {
				beforeDelete = tmp;
				tmp = tmp->next;
			}
			if (tmp->data.name == name) {
				cout << "Here are the unavailable ingredients for the Recipe: " << name << ": " << endl;
				tmp->data.unavailableList.printwNum();
			} else {
				cout << "Item not found!" << endl;
			}
		}
	}
	
	bool RecipeLinkedList::pop(string name) {
		NodeR* tmp = head;
		if (tmp->data.name == name) {
			head = tmp->next;
			return true;
		}
		NodeR* beforeDelete = nullptr;
		while (tmp->data.name != name && tmp->next != nullptr) {
			beforeDelete = tmp;
			tmp = tmp->next;
		}
		if (tmp->data.name == name) {
			beforeDelete->next = tmp->next;
			delete tmp;
			return true;
		} else {
			cout << "Item not found!" << endl;
			return false;
		}
	}


int length(string x) {
	int length = 0;
	for (int i = 0; x[i] != '\0'; i++) {
		length++;	
	}
	return length;
}

string intToStr(int x) {
    int tmp = x;
    int length = 0;
    string result;
    while(tmp/10 != 0) {
        length++;
        tmp/=10;
    }
    char z [length + 1];
    z[length] = '\0';
    for (int i = length; i > -1; i--) {
        z[i] = x % 10 + 48;
        x /= 10;
    }
    result = z;
    return result;
    
}

int strToInt(string str) {
    int len = length(str);
    int scale = 1;
    int tmp = len;
    int result = 0;
    
    while (tmp != 1) {
        scale *= 10;
        tmp--;
    }
    
    
    for (int i = 0; i < len; i++) {
        tmp = (str[i] - 48) * scale;
        result += tmp;
        scale /= 10;
    }
    return result;
}



		RecipeList::RecipeList() {
			readFile();
		}
		
		RecipeList::~RecipeList() {
			writeFile();
		}
		
		void RecipeList::push() {
			Recipe* tmpRecipe = nullptr;
			tmpRecipe = new Recipe;
			setRecipe(*tmpRecipe);
			rList.push(*tmpRecipe);
			recipeCount++;
		}
		
		void RecipeList::setRecipe(Recipe &obj) {
			setName(obj);
			setPrepTime(obj);
			setCookTime(obj);
			setTotalTime(obj);
			setIngredients(obj);
			setSteps(obj);
		}
		
		void RecipeList::setName(Recipe &obj) {
			string tmpString;
			cin.clear();
			cin.sync();
			cout << "What is the name of your recipe?: ";
			getline(cin, tmpString);
			obj.name = tmpString;
			cin.clear();
			cin.sync();
		}
		
		void RecipeList::setPrepTime(Recipe &obj) {
			string tmpString;
			cout << "What is the prepTime of your recipe: ";
			cin.clear();
			cin.sync();
			getline(cin, tmpString);
			obj.prepTime = tmpString;
			cin.clear();
			cin.sync();
		}
		
		void RecipeList::setCookTime(Recipe &obj) {
			string tmpString;
			cout << "What is the cookTime of your recipe: ";
			cin.clear();
			cin.sync();
			getline(cin, tmpString);
			obj.cookTime = tmpString;
			cin.clear();
			cin.sync();
		}
		
		void RecipeList::setTotalTime(Recipe &obj) {
			obj.totalTime = intToStr(strToInt(obj.prepTime) 
												+ strToInt(obj.cookTime));
		}
		
		void RecipeList::setSteps(Recipe &obj) {
			string tmpString;
			int stepCount = 1;
			bool needSteps = true;
			int option = 1;
			while (needSteps) {
				cin.clear();
				cin.sync();
				cout << "What is step #"<< stepCount << " of your recipe? Press Enter when done!"
					<< "\n#" << stepCount << " ";
				getline(cin, tmpString);
				obj.steps.push(tmpString);
				cin.clear();
				cin.sync();
				
				cout << "\tDo you have any more steps?\n\tEnter 1. Yes\t2. No\t: ";
				cin >> option;
				while (option != 1 && option != 2){
					cout << "\tWrong Entry!\n" << endl;
					cout << "\tDo you have any more steps?\n\tEnter 1. Yes\t2. No\t: ";
					cin >> option;
				}
				if (option == 2) {
					needSteps = false;
				}
				stepCount++;
			}
			
		}
		
		void RecipeList::setIngredients(Recipe &obj) {
			string tmpString;
			int ingredCount = 1;
			bool needIngredients = true;
			int option = 1;
			while (needIngredients) {
				cin.clear();
				cin.sync();
				cout << "What is ingredient #"<< ingredCount << " of your recipe? Press Enter when done!"
					<< "\n#" << ingredCount << " ";
				getline(cin, tmpString);
				obj.ingredientList.push(tmpString);
				cin.clear();
				cin.sync();
				cout << "\tDo you have any more ingredients?\n\tEnter \t1. Yes\t2. No\t: ";
				cin >> option;
				while (option != 1 && option != 2){
					cout << "\tWrong Entry!\n" << endl;
					cout << "\tDo you have any more ingredients?\n\tEnter 1. Yes\t2. No\t: ";
					cin >> option;
				}
				if (option == 2) {
					needIngredients = false;
				}
				ingredCount++;
			}
			
		}
		
		void RecipeList::printRecipeNames() {
			rList.printRecipes();
		}
		
		void RecipeList::printARecipeNames(void) {
			rList.printARecipes();
		}
		
		void RecipeList::printURecipeNames(void) {
			rList.printURecipes();
		}
		
		void RecipeList::printRecipeTimesAt(int n) {
			if (n > 0 && n <= recipeCount) {
				rList.printRecipeTimesAt(n);
			}
			else {
				cout << "Wrong Option!" << endl;
			}
		}
		
		void RecipeList::printRecipeAt(int n) {
			if (n > 0 && n <= recipeCount) {
				rList.printRecipeAt(n);
			}
			else {
				cout << "Wrong Option!" << endl;
			}
		}
		
		void RecipeList::printRecipeInfoAt(int n) {
			if (n > 0 && n <= recipeCount) {
				cout << "Here is the selected recipe Info:" << endl;
				cout << "The Recipe number and name: ";
				printRecipeAt(n);
				printRecipeTimesAt(n);
				cout << "Here are all of the ingredients in the recipe: " << endl;
				printIngredientsAt(n);
				cout << "Here are the ingredients you are missing: " << endl;
				printUIngredientsAt(n);
				cout << "Here are the steps of the recipe: " << endl;
				printStepsAt(n);
				cout << endl;
			}
			else {
				cout << "Number not on the list!" << endl;
			}
			
			
			
		}
		
		void RecipeList::printStepsAt(int n) {
			if (n > 0 && n <= recipeCount) {
				rList.printStepsAt(n);
			}
			else {
				cout << "Wrong Option!" << endl;
			}
		}
		
		void RecipeList::printIngredientsAt(int n) {
			if (n > 0 && n <= recipeCount) {
				rList.printIngredientsAt(n);
			}
			else {
				cout << "Wrong Option!" << endl;
			}
		}
		
		void RecipeList::printUIngredientsAt(int n) {
			if (n > 0 && n <= recipeCount) {
				rList.printUIngredientsAt(n);
			}
			else {
				cout << "Wrong Option!" << endl;
			}
		}
		
		void RecipeList::printIngredients(string name) { //name = name of recipe
			rList.printIngredients(name);
		}
		
		void RecipeList::printUnavailable(string name) { //name = name of recipe
			rList.printUnavailable(name);
		}
		
		void RecipeList::printSteps(string name) { //name = name of recipe
			rList.printSteps(name);
		}
		
		void RecipeList::pop() {
			if (recipeCount == 0) {
				cout << "\tThere are no recipes to remove!" << endl;
			} else {
				string tmp;
				cout << "\tEnter Recipe you would like to remove: ";
				cin.clear();
				cin.sync();
				getline(cin, tmp, '\n');
				if(rList.pop(tmp)) {
					recipeCount--;
					cout << tmp << " was REMOVED!" << endl;
				}
				cout << tmp << " was not REMOVED! (it may not have existed)" << endl;
				cin.clear();
				cin.sync();
			}
		}
		
		void RecipeList::update(Ingredients* iList) {
			writeFile();
			readFileAgain(iList);
		}
		
		void RecipeList::countRecipes(void) {
		ifstream myfile;
			string tmpString;
			myfile.open("recipelist.txt");
			if (myfile.fail()) {
				cerr << "Error Opening File" << endl;
				exit(1);
			}
			getline(myfile, tmpString);
			
			if (tmpString[0] == '\0') {
				cout << "The text file is empty!" << endl;
				recipeCount = 0;
			} else if (tmpString[0] == '*') {
				getline(myfile, tmpString); 
				recipeCount = strToInt(tmpString);
				/* cout << "3." << tmpString << endl; */
				/* cout << tmpString[0] << endl; */
				
			} else cout << "Ingredient List is not properly structured!\n" 
						<< "Please use the following structure in the txt file:\n"
						<< "*\ningredient1\ningredient2\ningredientN\n*\n\n"
						<< "An empty ingredient list should look like:\n"
						<< "*\n*" << endl;
			
			myfile.close();
		}
		
		void RecipeList::readFile(void) {
			ifstream myfile;
			Recipe* tmpRecipe = nullptr;
		
			string tmpString;
			countRecipes();
			int count = 0;
			//cout << "recipeCount: " << recipeCount << endl;
			if(recipeCount == 0) { 
				cout << "You have no Recipes!" << endl;
			} 
			else {
				myfile.open("recipelist.txt");
				//check for error
				if (myfile.fail()) {
					cerr << "Error Opening File" << endl;
					exit(1);
				}
				
				getline(myfile, tmpString);
				getline(myfile, tmpString);
				getline(myfile, tmpString);
				
				while (count < recipeCount) { //count max is recipeCount - 1
					tmpRecipe = new Recipe;
					getline(myfile, tmpString);
					tmpRecipe->name = tmpString;
					
					getline(myfile, tmpString);
					tmpRecipe->cookTime = tmpString;
					
					getline(myfile, tmpString);
					tmpRecipe->prepTime = tmpString;
					
					getline(myfile, tmpString);
					getline(myfile, tmpString);
					
					while(tmpString[0] != 'X') {
						tmpRecipe->steps.push(tmpString);
						tmpRecipe->stepCount++;
						getline(myfile, tmpString);
					}
					
					getline(myfile, tmpString);
					
					while(tmpString[0] != '*') {
						tmpRecipe->ingredientList.push(tmpString);
						tmpRecipe->ingredientCount++;
						getline(myfile, tmpString);
					}
					
					
					tmpRecipe->totalTime = intToStr(strToInt(tmpRecipe->prepTime) + strToInt(tmpRecipe->cookTime));
					//cout << "Total time: " << tmpRecipe->totalTime << endl;
					rList.push(*tmpRecipe);
					count++;
					//cout << count << endl;
				}
				tmpRecipe = nullptr;
				myfile.close();
			}
		}
		
		void RecipeList::readFileAgain(Ingredients* iList) {
			//cout << "readingFileAgain();" << endl;
			if(rList.head != nullptr) {
				delete rList.head;
				rList.head = nullptr;}
			if(rList.tail != nullptr) {
				delete rList.tail;
				rList.tail = nullptr;}
			
			ifstream myfile;
			Recipe* tmpRecipe = nullptr;
			Node* tmpNode = nullptr;
			string tmpString;
			countRecipes();
			int count = 0;
			bool available;
			
			//cout << "recipeCount: " << recipeCount << endl;
			if(recipeCount == 0) { 
				cout << "You have no Recipes!" << endl;
			} 
			else {
				myfile.open("recipelist.txt");
				//check for error
				if (myfile.fail()) {
					cerr << "Error Opening File" << endl;
					exit(1);
				}
				
				getline(myfile, tmpString);
				getline(myfile, tmpString);
				getline(myfile, tmpString);
				
				while (count < recipeCount) { //count max is recipeCount - 1
					available = true;
					tmpRecipe = new Recipe;
					getline(myfile, tmpString);
					tmpRecipe->name = tmpString;
					
					getline(myfile, tmpString);
					tmpRecipe->cookTime = tmpString;
					
					getline(myfile, tmpString);
					tmpRecipe->prepTime = tmpString;
					
					getline(myfile, tmpString);
					getline(myfile, tmpString);
					
					while(tmpString[0] != 'X') {
						tmpRecipe->steps.push(tmpString);
						tmpRecipe->stepCount++;
						getline(myfile, tmpString);
					}
					
					getline(myfile, tmpString);
					
					while(tmpString[0] != '*') {
						//cout << "Pushing " << tmpString << endl;
						tmpRecipe->ingredientList.push(tmpString);
						tmpRecipe->ingredientCount++;
						getline(myfile, tmpString);
					}
					tmpRecipe->totalTime = intToStr(strToInt(tmpRecipe->prepTime) 
												+ strToInt(tmpRecipe->cookTime));
												
					
					//here I should do the comparison of ingredients in recipe
					tmpNode = tmpRecipe->ingredientList.head;
					while (tmpNode->next != nullptr) {
						//cout << "Testing " <<tmpNode->data << " in isFoundV2" << endl;
						if(!(iList->isFoundV2(tmpNode->data))){
							//cout << "Not Found!" << endl;
							tmpRecipe->unavailableList.push(tmpNode->data);
							available = false;
						}
						
						tmpNode = tmpNode->next;
					}
					//cout << "Testing " <<tmpNode->data << " in isFoundV2" << endl;
					if(!(iList->isFoundV2(tmpNode->data))){
							//cout << "Not Found!" << endl;
							tmpRecipe->unavailableList.push(tmpNode->data);
							available = false;
						}
					tmpRecipe->available = available;
					//cout << "**Pushing Recipe: " << tmpRecipe->name << endl;
					//cout << "tmpRecipe has bool " << tmpRecipe->available << endl;
					rList.push(*tmpRecipe);
					count++;
					//cout << count << endl;
				}
				tmpRecipe = nullptr;
				myfile.close();
			}
		}		
	
		void RecipeList::writeFile(void) {
			NodeR* tmpNR = nullptr;
			Node* tmpNode = nullptr;
			ofstream myfile;
			myfile.open("recipelist.txt");
			int count = 0;

			//check for error
			if (myfile.fail()) {
				cerr << "Error Opening File" << endl;
				exit(1);
			} 
			if (recipeCount == 0) {
				myfile << "*\n" << recipeCount << "\n*";
			} else {
				myfile << "*\n" << recipeCount << "\n*" << endl;
				tmpNR = rList.head;
				
				while (count < recipeCount) {
					myfile << tmpNR->data.name << endl 
							<< tmpNR->data.cookTime << endl 
							<< tmpNR->data.prepTime << endl
							<< "X" << endl;
					tmpNode = tmpNR->data.steps.head;
					while (tmpNode->next != nullptr) {
						myfile << tmpNode->data << endl;
						tmpNode = tmpNode->next;
					}
					myfile << tmpNode->data << endl << "X" << endl;
					
					tmpNode = tmpNR->data.ingredientList.head;
					while (tmpNode->next != nullptr) {
						myfile << tmpNode->data << endl;
						tmpNode = tmpNode->next;
					}
					myfile << tmpNode->data << endl;
					
					if(count == recipeCount - 1) {
						myfile << "*";
					} else {
						myfile << "*" <<endl;
					}
					count++;
					
					tmpNR = tmpNR->next;
					
				}
				
			}
			myfile.close();
		}

/*
int main() {
	RecipeList obj;
	obj.printRecipeNames();
	
	obj.push();
	
	// obj.pop();
	// obj.pop();
	
	
	obj.printRecipeNames();
	//obj.printRecipeAt(3);
	//obj.printSteps("Borsch3");
	
	return 0;
}
*/
/*

Structure of Txt file
*
1
*
name
cooktime
preptime
X
1. blah
2. blah
3. blah
X
ingredient1
ingredient2
ingredient3
*


*/