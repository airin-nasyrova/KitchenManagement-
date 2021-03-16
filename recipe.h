#include <iostream>
#include <fstream>
using namespace std; 

#include "ingredientList.h"

#ifndef RECIPE_H
#define RECIPE_H



class SinglyLinkedListV2 {
	private:
		
	public: 
		Node* head;
		Node* tail;
		SinglyLinkedListV2();
		
		void push(string data);
		
		void print(void);
		
		void printwNum(void);
		
		void popAll(void);
		
		string pop(string data);
};

struct Recipe {
	int stepCount = 0;
	int ingredientCount = 0;
	string name;
	SinglyLinkedListV2 steps;
	SinglyLinkedListV2 ingredientList;
	SinglyLinkedListV2 unavailableList;
	string prepTime;
	string cookTime;
	string totalTime;
	bool available = false;
};

struct NodeR {
Recipe data;
struct NodeR* next = nullptr; 
};

class RecipeLinkedList {
private:
	
public: 
	NodeR* head;
	NodeR* tail;
	RecipeLinkedList();
	
	void push(Recipe data);
	
	void printRecipes();
	void printARecipes();
	void printURecipes();
	
	void printRecipeAt(int n);
	void printRecipeTimesAt(int n);
	void printUIngredientsAt(int n);
	void printIngredientsAt(int n);
	void printStepsAt(int n);
	
	void printIngredients(string name);
	
	void printSteps(string name);
	void printUnavailable(string name);
	
	bool pop(string name);
};


int length(string x);

string intToStr(int x);

int strToInt(string str);


class RecipeList {
	private: 
		int recipeCount;
		RecipeLinkedList rList;
	public:
		RecipeList();
		
		~RecipeList();
		
		void push(void);
		
		void setRecipe(Recipe &obj);
		
		void setName(Recipe &obj);
		
		void setPrepTime(Recipe &obj);
		
		void setCookTime(Recipe &obj);
		
		void setTotalTime(Recipe &obj);
		
		void setSteps(Recipe &obj);
		
		void setIngredients(Recipe &obj);
		
		void printRecipeNames(void);
		
		void printURecipeNames(void);
		
		void printARecipeNames(void);
		
		void printRecipeTimesAt(int n);
		
		void printRecipeAt(int n);
		
		void printRecipeInfoAt(int n);
		
		void printStepsAt(int n);
		
		void printIngredientsAt(int n);
		
		void printUIngredientsAt(int n);
		
		void printIngredients(string name);
		
		void printSteps(string name);
		
		void printUnavailable(string name);
		
		void pop(void);
		
		void update(Ingredients*);
		
		void countRecipes(void);
		
		void readFile(void);
		
		void readFileAgain(Ingredients*);
	
		void writeFile(void);
};

#endif
