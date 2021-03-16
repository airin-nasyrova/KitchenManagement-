#include <iostream>
using namespace std;

#include "mainMenu.h"

void runMenu() {
	Ingredients* iList = new Ingredients;
	RecipeList* rList = new RecipeList;
	rList->update(iList);
	
	
	int option;

	do {
		iList->update();
		rList->update(iList);
		cout <<
	"\n**********************************************************************************************************************"
	"\n**                       __   __  _______  ___  __    _      __   __  _______  __    _  __   __                     **"
	"\n**                      |  |_|  ||   _   ||   ||  |  | |    |  |_|  ||       ||  |  | ||  | |  |                    **"
	"\n**                      |       ||  |_|  ||   ||   |_| |    |       ||    ___||   |_| ||  | |  |                    **"
	"\n**                      |       ||       ||   ||       |    |       ||   |___ |       ||  |_|  |                    **"
	"\n**                      |       ||       ||   ||  _    |    |       ||    ___||  _    ||       |                    **"
	"\n**                      | ||_|| ||   _   ||   || | |   |    | ||_|| ||   |___ | | |   ||       |                    **"
	"\n**                      |_|   |_||__| |__||___||_|  |__|    |_|   |_||_______||_|  |__||_______|                    **"
	"\n**                                                                                                                  **"
	"\n**  Hungry? Welcome to your personal kitchen assisstant!                                                            **"
	"\n**   Choose an option to make your cooking experience easier today                                                  **"
	"\n**     1. Recipes                                                                                                   **"
	"\n**     2. Ingredients                                                                                               **"
	"\n**     3. I'm done for today                                                                                        **"
	"\n**********************************************************************************************************************"  << endl;
		cout << "Select an option : ";
		cin >> option;

		switch (option) {
		case 1:
				runRecipesMenu(iList, rList);
			break;
		case 2:
				runIngredientsMenu(iList);
			break;
		
		case 3:
			cout << 
			"\n __   __  _______  __   __  _______      _______      __    _  ___   _______  _______      ______   _______  __   __  __  "
			"\n|  | |  ||   _   ||  | |  ||       |    |   _   |    |  |  | ||   | |       ||       |    |      | |   _   ||  | |  ||  | "
			"\n|  |_|  ||  |_|  ||  |_|  ||    ___|    |  |_|  |    |   |_| ||   | |       ||    ___|    |  _    ||  |_|  ||  |_|  ||  | "
			"\n|       ||       ||       ||   |___     |       |    |       ||   | |     __||   |___     | | |   ||       ||       ||  | "
			"\n|       ||       ||       ||    ___|    |       |    |  _    ||   | |    |   |    ___|    | |_|   ||       ||_     _||__| "
			"\n|   _   ||   _   | |     | |   |___     |   _   |    | | |   ||   | |    |__ |   |___     |       ||   _   |  |   |   __  "
			"\n|__| |__||__| |__|  |___|  |_______|    |__| |__|    |_|  |__||___| |_______||_______|    |______| |__| |__|  |___|  |__| "
			 << endl;
				delete iList;
				delete rList;
			break;
		default:
			cout << "\n OOPS......TRY AGAIN 1, 2 or 3  " << endl;
		}
	} while (option != 3);
	
}

void runRecipesMenu(Ingredients* iList, RecipeList* rList){
	
    int option;
    do {
    cout << 
    "\n**********************************************************************************************************************"
	"\n**                       ______    _______  _______  ___   _______  _______  _______                                **"
	"\n**                      |    _ |  |       ||       ||   | |       ||       ||       |                               **"
	"\n**                      |   | ||  |    ___||       ||   | |    _  ||    ___||  _____|                               **"
	"\n**                      |   |_||_ |   |___ |       ||   | |   |_| ||   |___ | |_____                                **"
	"\n**                      |    __  ||    ___||      _||   | |    ___||    ___||_____  |                               **"
	"\n**                      |   |  | ||   |___ |     |_ |   | |   |    |   |___  _____| |                               **"
	"\n**                      |___|  |_||_______||_______||___| |___|    |_______||_______|                               **"
    "\n**                                                                                                                  **"
    "\n**      1. View Recipes                                                                                             **" 
    "\n**      2. Add Recipes                                                                                              **"
    "\n**      3. Remove Recipes                                                                                           **"
    "\n**      4. Return to the previous menu                                                                              **"
    "\n**********************************************************************************************************************"
        << endl;
    cout << "Select an option : ";
    cin >> option;
    switch (option) {
		case 1:
            viewRecipesMenu(iList, rList);
			break;
		case 2:
            addRecipesMenu(iList, rList);
			break;
        case 3:
			removeRecipesMenu(iList, rList);
			break;
		case 4:
			cout << "\n\n  Going Back..." << endl;
			break;
		default:
			cout << "\n OOPS......TRY AGAIN 1, 2, 3 or 4 " << endl;
	}
}while (option != 4);
}

void viewRecipesMenu(Ingredients* iList, RecipeList* rList){
    int option;
    do {
	
		cout << 
		 "\n**********************************************************************************************************************"
		 "\n**             __   __  ___   _______  _     _      ______    _______  _______  ___   _______  _______  _______     **" 
		 "\n**            |  | |  ||   | |       || | _ | |    |    _ |  |       ||       ||   | |       ||       ||       |    **" 
		 "\n**            |  |_|  ||   | |    ___|| || || |    |   | ||  |    ___||       ||   | |    _  ||    ___||  _____|    **" 
		 "\n**            |       ||   | |   |___ |       |    |   |_||_ |   |___ |       ||   | |   |_| ||   |___ | |_____     **" 
		 "\n**            |       ||   | |    ___||       |    |    __  ||    ___||      _||   | |    ___||    ___||_____  |    **" 
		 "\n**             |     | |   | |   |___ |   _   |    |   |  | ||   |___ |     |_ |   | |   |    |   |___  _____| |    **" 
		 "\n**              |___|  |___| |_______||__| |__|    |___|  |_||_______||_______||___| |___|    |_______||_______|    **"  
		 "\n**                                                                                                                  **"
		 "\n**      1. Available Recipes                                                                                        **" 
		 "\n**      2. Unavailable Recipes                                                                                      **"
		 "\n**      3. Return to the previous menu                                                                              **"
		 "\n**********************************************************************************************************************"
			<< endl;
		cout << "\tHere is a list of all of the recipes!" << endl;
		rList->printRecipeNames();
		cout << "\tSelect an option from the above menu: ";
		cin >> option;
		switch (option) {
			case 1:
				viewAvailableRecipesMenu(iList, rList);
				break;
			case 2:
				viewUnavailableRecipesMenu(iList, rList);
				break;
			case 3:
				cout << "\n\n\tGoing Back...";
				break;
			default:
				cout << "\n\t OOPS......TRY AGAIN 1, 2 or 3 " << endl;
		} 
	} while (option != 3);
}

void viewAvailableRecipesMenu(Ingredients* iList, RecipeList* rList){
	int option;
    do {   
		iList->update();
		rList->update(iList);

		cout << 
	"\n _______  __   __  _______  ___   ___      _______  _______  ___      _______      ______    _______  _______  ___   _______  _______  _______ "
	"\n|   _   ||  | |  ||   _   ||   | |   |    |   _   ||  _    ||   |    |       |    |    _ |  |       ||       ||   | |       ||       ||       |"
	"\n|  |_|  ||  |_|  ||  |_|  ||   | |   |    |  |_|  || |_|   ||   |    |    ___|    |   | ||  |    ___||       ||   | |    _  ||    ___||  _____|"
	"\n|       ||       ||       ||   | |   |    |       ||       ||   |    |   |___     |   |_||_ |   |___ |       ||   | |   |_| ||   |___ | |_____ "
	"\n|       ||       ||       ||   | |   |___ |       ||  _   | |   |___ |    ___|    |    __  ||    ___||      _||   | |    ___||    ___||_____  |"
	"\n|   _   | |     | |   _   ||   | |       ||   _   || |_|   ||       ||   |___     |   |  | ||   |___ |     |_ |   | |   |    |   |___  _____| |"
	"\n|__| |__|  |___|  |__| |__||___| |_______||__| |__||_______||_______||_______|    |___|  |_||_______||_______||___| |___|    |_______||_______|" << endl;
		
		cout << "\tHere are all of your available recipes!" << endl;
		rList->printARecipeNames();
		
		cout << "\n\tWhat would you like to do?"
			<< "\n\t1. Select an available recipe" 
			<< "\n\t2. Go back to previous menu!" << endl
			<< "\n\tPlease Enter an integer option: ";
			cin >> option;
		switch (option) {
			case 1:
				cout << "\n\n*************************************************" << endl;
				cout << "\tHere are all of your available recipes!" << endl;
				rList->printARecipeNames();
				cout << "\tTo select a recipe, please enter the number next to its name: ";
				cin >> option;
				cout << endl;
				rList->printRecipeInfoAt(option);
				cout << "*************************************************" << endl;
				option = 1;
				break;
			case 2:
				cout << "\n\n\tGoing Back..." << endl;
				break;	
			default:
				 cout << "\tWrong Option!" << endl;
		}
	} while (option != 2);
}
void viewUnavailableRecipesMenu(Ingredients* iList, RecipeList* rList){
    
	int option;
    do {
		iList->update();
		rList->update(iList);
		cout << 
	"\n __   __  __    _  __   __  _______  ___   ___      _______  _______  ___      _______      ______    _______  _______  ___   _______  _______  _______ "
	"\n|  | |  ||  |  | ||  | |  ||   _   ||   | |   |    |   _   ||  _    ||   |    |       |    |    _ |  |       ||       ||   | |       ||       ||       |"
	"\n|  | |  ||   |_| ||  |_|  ||  |_|  ||   | |   |    |  |_|  || |_|   ||   |    |    ___|    |   | ||  |    ___||       ||   | |    _  ||    ___||  _____|"
	"\n|  |_|  ||       ||       ||       ||   | |   |    |       ||       ||   |    |   |___     |   |_||_ |   |___ |       ||   | |   |_| ||   |___ | |_____ "
	"\n|       ||  _    ||       ||       ||   | |   |___ |       ||  _   | |   |___ |    ___|    |    __  ||    ___||      _||   | |    ___||    ___||_____  |"
	"\n|       || | |   | |     | |   _   ||   | |       ||   _   || |_|   ||       ||   |___     |   |  | ||   |___ |     |_ |   | |   |    |   |___  _____| |"
	"\n|_______||_|  |__|  |___|  |__| |__||___| |_______||__| |__||_______||_______||_______|    |___|  |_||_______||_______||___| |___|    |_______||_______|" << endl;
		
		cout << "\n\tHere are all of your unavailable recipes!" << endl;
		rList->printURecipeNames();
		
		cout << "\n\tWhat would you like to do?"
			<< "\n\t1. Select an Unavailable recipe" 
			<< "\n\t2. Go back to previous menu!" << endl
			<< "\n\tPlease Enter an integer option: ";
		cin >> option;
		switch (option) {
			case 1:
				cout << "\n\n*************************************************" << endl;
				cout << "\tHere are all of your unavailable recipes!" << endl;
				rList->printURecipeNames();
				cout << "\tTo select a recipe, please enter the number next to its name: ";
				cin >> option;
				cout << endl;
				rList->printRecipeInfoAt(option);
				cout << "*************************************************" << endl;
				option = 1;
				break;
			case 2:
				cout << "\n\n\tGoing Back..." << endl;
				break;	
			default:
				 cout << "\tWrong Option!" << endl;
		}
	} while (option != 2);
}
void addRecipesMenu(Ingredients* iList, RecipeList* rList){
    int option;
    do {
		iList->update();
		cout <<
		 "\n**********************************************************************************************************************"
		 "\n**                   _______  ______   ______       ______    _______  _______  ___   _______  _______  _______     **" 
		 "\n**                  |   _   ||      | |      |     |    _ |  |       ||       ||   | |       ||       ||       |    **" 
		 "\n**                  |  |_|  ||  _    ||  _    |    |   | ||  |    ___||       ||   | |    _  ||    ___||  _____|    **" 
		 "\n**                  |       || | |   || | |   |    |   |_||_ |   |___ |       ||   | |   |_| ||   |___ | |_____     **" 
		 "\n**                  |       || |_|   || |_|   |    |    __  ||    ___||      _||   | |    ___||    ___||_____  |    **" 
		 "\n**                  |   _   ||       ||       |    |   |  | ||   |___ |     |_ |   | |   |    |   |___  _____| |    **" 
		 "\n**                  |__| |__||______| |______|     |___|  |_||_______||_______||___| |___|    |_______||_______|    **" 
		 "\n**                                                                                                                  **"
		 "\n**     1. Add Recipes                                                                                               **"       
		 "\n**     2. Return to the previous menu                                                                               **"
		 "\n**********************************************************************************************************************"
			<< endl;
			cout << "\tHere is a list of all of the recipes!" << endl;
			rList->printRecipeNames();
		cout << "Select an option : ";
		cin >> option;
		switch (option) {
			case 1:
				cout << "   Calling addRecipes()!" << endl;
					rList->push();
					rList->update(iList);
				break;
			case 2:
				cout << "\n\n . Going Back...";
				break;
			default:
				cout << "\n OOPS......TRY AGAIN 1 or 2" << endl;
		}
	} while (option != 2);
}
void removeRecipesMenu(Ingredients* iList, RecipeList* rList){
    int option;
    do {
    cout << 
     "\n************************************************************************************************************************************"
	 "\n**        ______    _______  __   __  _______  __   __  _______      ______    _______  _______  ___   _______  _______  _______  **"
	 "\n**       |    _ |  |       ||  |_|  ||       ||  | |  ||       |    |    _ |  |       ||       ||   | |       ||       ||       | **"
	 "\n**       |   | ||  |    ___||       ||   _   ||  |_|  ||    ___|    |   | ||  |    ___||       ||   | |    _  ||    ___||  _____| **"
	 "\n**       |   |_||_ |   |___ |       ||  | |  ||       ||   |___     |   |_||_ |   |___ |       ||   | |   |_| ||   |___ | |_____  **"
	 "\n**       |    __  ||    ___||       ||  |_|  ||       ||    ___|    |    __  ||    ___||      _||   | |    ___||    ___||_____  | **"
	 "\n**       |   |  | ||   |___ | ||_|| ||       | |     | |   |___     |   |  | ||   |___ |     |_ |   | |   |    |   |___  _____| | **"
	 "\n**       |___|  |_||_______||_|   |_||_______|  |___|  |_______|    |___|  |_||_______||_______||___| |___|    |_______||_______| **"
     "\n**                                                                                                                                **"
     "\n**     1. Remove Recipes                                                                                                          **"   
     "\n**     2. Return to the previous menu                                                                                             **"
     "\n************************************************************************************************************************************"
        << endl;
    cout << "Select an option : ";
    cin >> option;
    switch (option) {
		case 1:
			cout << "   Calling removeRecipes()!" << endl;
				rList->pop();
				rList->update(iList);
			break;
		case 2:
			cout << "\n\n . Going Back...";
			break;
		default:
			cout << "\n OOPS......TRY AGAIN 1 or 2" << endl;
	}
} while (option != 2);
}

void runIngredientsMenu(Ingredients* iList){
    int option;
    do {
		iList->update();
		cout << 
		"\n**********************************************************************************************************************"
		"\n**                 ___   __    _  _______  ______    _______  ______   ___   _______  __    _  _______  _______     **"
		"\n**                |   | |  |  | ||       ||    _ |  |       ||      | |   | |       ||  |  | ||       ||       |    **"
		"\n**                |   | |   |_| ||    ___||   | ||  |    ___||  _    ||   | |    ___||   |_| ||_     _||  _____|    **"
		"\n**                |   | |       ||   | __ |   |_||_ |   |___ | | |   ||   | |   |___ |       |  |   |  | |_____     **"
		"\n**                |   | |  _    ||   ||  ||    __  ||    ___|| |_|   ||   | |    ___||  _    |  |   |  |_____  |    **"
		"\n**                |   | | | |   ||   |_| ||   |  | ||   |___ |       ||   | |   |___ | | |   |  |   |   _____| |    **"
		"\n**                |___| |_|  |__||_______||___|  |_||_______||______| |___| |_______||_|  |__|  |___|  |_______|    **"
		"\n**                                                                                                                  **"
		"\n**     1. View Available Ingredients                                                                                **" 
		"\n**     2. Add Ingredients                                                                                           **"
		"\n**     3. Remove Ingredients                                                                                        **"
		"\n**     4. Search Ingredients                                                                                        **"
		"\n**     5. Return to the previous menu                                                                               **"
		"\n**********************************************************************************************************************"   << endl;
		cout << "Select an option : ";
		cin >> option;
		switch (option) {
			case 1:
				viewAvailableIngredientsMenu(iList);
				break;
			case 2:
				addIngredientsMenu(iList);
				break;
			case 3:
				removeIngredientsMenu(iList);
				break;
			case 4:
				searchIngredientsMenu(iList);
				break;
			case 5:
				cout << "\n\n  Going Back...";
				break;
			default:
				cout << "\n OOPS......TRY AGAIN 1, 2 or 3 " << endl;
		} 
	} while (option != 5);
}
void viewAvailableIngredientsMenu(Ingredients* iList){
    int option;
    do {
		iList->update();
		cout << 
		   "\n******************************************************************************************************************************"
		   "\n**              _______  __   __  _______  ___   ___      _______  _______  ___      _______                                **"
		   "\n**             |   _   ||  | |  ||   _   ||   | |   |    |   _   ||  _    ||   |    |       |                               **"
		   "\n**             |  |_|  ||  |_|  ||  |_|  ||   | |   |    |  |_|  || |_|   ||   |    |    ___|                               **"
		   "\n**             |       ||       ||       ||   | |   |    |       ||       ||   |    |   |___                                **"
		   "\n**             |       ||       ||       ||   | |   |___ |       ||  _   | |   |___ |    ___|                               **"
		   "\n**             |   _   | |     | |   _   ||   | |       ||   _   || |_|   ||       ||   |___                                **"
		   "\n**             |__| |__|  |___|  |__| |__||___| |_______||__| |__||_______||_______||_______|                               **"
		   "\n**              ___   __    _  _______  ______    _______  ______   ___   _______  __    _  _______  _______                **"
		   "\n**             |   | |  |  | ||       ||    _ |  |       ||      | |   | |       ||  |  | ||       ||       |               **"
		   "\n**             |   | |   |_| ||    ___||   | ||  |    ___||  _    ||   | |    ___||   |_| ||_     _||  _____|               **"
		   "\n**             |   | |       ||   | __ |   |_||_ |   |___ | | |   ||   | |   |___ |       |  |   |  | |_____                **"
		   "\n**             |   | |  _    ||   ||  ||    __  ||    ___|| |_|   ||   | |    ___||  _    |  |   |  |_____  |               **"
		   "\n**             |   | | | |   ||   |_| ||   |  | ||   |___ |       ||   | |   |___ | | |   |  |   |   _____| |               **"
		   "\n**             |___| |_|  |__||_______||___|  |_||_______||______| |___| |_______||_|  |__|  |___|  |_______|               **"
		   "\n**                                                                                                                          **"
		   "\n**   1. View available ingredients                                                                                          **"   
		   "\n**   2. Return to the previous menu                                                                                         **"
		   "\n******************************************************************************************************************************" << endl;
		cout << "Select an option : ";
		cin >> option;
		switch (option) {
			case 1:
				cout << "\n   LIST OF AVAILABLE INGREDIENTS" << endl;
				iList->print();
				break;
			case 2:
				cout << "\n  Going Back...";
				break;
			default:
				cout << "\n OOPS......TRY AGAIN 1 or 2" << endl;
		} 
	} while (option != 2);
}
void addIngredientsMenu(Ingredients* iList){
    int option;
	string tmpString;
    do {
    cout << 
    "\n**********************************************************************************************************************************"
	"\n** _______  ______   ______       ___   __    _  _______  ______    _______  ______   ___   _______  __    _  _______  _______  **"
	"\n**|   _   ||      | |      |     |   | |  |  | ||       ||    _ |  |       ||      | |   | |       ||  |  | ||       ||       | **"
	"\n**|  |_|  ||  _    ||  _    |    |   | |   |_| ||    ___||   | ||  |    ___||  _    ||   | |    ___||   |_| ||_     _||  _____| **"
	"\n**|       || | |   || | |   |    |   | |       ||   | __ |   |_||_ |   |___ | | |   ||   | |   |___ |       |  |   |  | |_____  **"
	"\n**|       || |_|   || |_|   |    |   | |  _    ||   ||  ||    __  ||    ___|| |_|   ||   | |    ___||  _    |  |   |  |_____  | **"
	"\n**|   _   ||       ||       |    |   | | | |   ||   |_| ||   |  | ||   |___ |       ||   | |   |___ | | |   |  |   |   _____| | **"
	"\n**|__| |__||______| |______|     |___| |_|  |__||_______||___|  |_||_______||______| |___| |_______||_|  |__|  |___|  |_______| **"
    "\n**                                                                                                                              **"
    "\n**     1. Add ingredients                                                                                                       **"   
    "\n**     2. Return to the previous menu                                                                                           **"
    "\n**********************************************************************************************************************************"  << endl;
    cout << "Select an option : ";
    cin >> option;
    switch (option) {
		case 1:
			cout << "\n   -ADD INGREDIENTS-" << endl;
			while(option != 2) {
				iList->add();
				cout << "\tDo you have any more ingredients?\n\tEnter \t1. Yes\t2. No\t: ";
				cin >> option;
				while (option != 1 && option != 2){
					cout << "\tWrong Entry!\n" << endl;
					cout << "\tDo you have any more steps?\n\tEnter 1. Yes\t2. No\t: ";
					cin >> option;
				}
			}
			iList->update();
			break;
		case 2:
			cout << "\n  Going Back...";
			break;
		default:
			cout << "\n OOPS......TRY AGAIN 1 or 2" << endl;
	}} while (option != 2);
}
void removeIngredientsMenu(Ingredients* iList){
    int option;
    do {
    cout << 
		"\n**********************************************************************************************************************"
		"\n**                           ______    _______  __   __  _______  __   __  _______                                  **"
		"\n**                          |    _ |  |       ||  |_|  ||       ||  | |  ||       |                                 **"
		"\n**                          |   | ||  |    ___||       ||   _   ||  |_|  ||    ___|                                 **"
		"\n**                          |   |_||_ |   |___ |       ||  | |  ||       ||   |___                                  **"
		"\n**                          |    __  ||    ___||       ||  |_|  ||       ||    ___|                                 **"
		"\n**                          |   |  | ||   |___ | ||_|| ||       | |     | |   |___                                  **"
		"\n**                          |___|  |_||_______||_|   |_||_______|  |___|  |_______|                                 **"
		"\n**         ___   __    _  _______  ______    _______  ______   ___   _______  __    _  _______  _______             **"
		"\n**        |   | |  |  | ||       ||    _ |  |       ||      | |   | |       ||  |  | ||       ||       |            **"
		"\n**        |   | |   |_| ||    ___||   | ||  |    ___||  _    ||   | |    ___||   |_| ||_     _||  _____|            **"
		"\n**        |   | |       ||   | __ |   |_||_ |   |___ | | |   ||   | |   |___ |       |  |   |  | |_____             **"
		"\n**        |   | |  _    ||   ||  ||    __  ||    ___|| |_|   ||   | |    ___||  _    |  |   |  |_____  |            **"
		"\n**        |   | | | |   ||   |_| ||   |  | ||   |___ |       ||   | |   |___ | | |   |  |   |   _____| |            **"
		"\n**        |___| |_|  |__||_______||___|  |_||_______||______| |___| |_______||_|  |__|  |___|  |_______|            **"
		"\n**                                                                                                                  **"
		"\n**     1. Remove ingredients                                                                                        **"   
		"\n**     2. Return to the previous menu                                                                               **"
		"\n**********************************************************************************************************************"  << endl;
    cout << "Select an option : ";
    cin >> option;
    switch (option) {
		case 1:
			cout << "\n   -REMOVE INGREDIENTS-" << endl;
			while(option != 2) {
				iList->pop();
				cout << "\tDo you have any more ingredients?\n\tEnter \t1. Yes\t2. No\t: ";
				cin >> option;
				while (option != 1 && option != 2){
					cout << "\tWrong Entry!\n" << endl;
					cout << "\tDo you have any more steps?\n\tEnter 1. Yes\t2. No\t: ";
					cin >> option;
				}
			}
			iList->update();
			break;
		case 2:
			cout << "\n  Going Back...";
			break;
		default:
			cout << "\n OOPS......TRY AGAIN 1 or 2" << endl;
	}} while (option != 2);
}

void searchIngredientsMenu(Ingredients* iList){
    int option;
    do {
	iList->update();
    cout << 
    "\n**********************************************************************************************************************"
	"\n**                         _______  _______  _______  ______    _______  __   __                                    **"
	"\n**                        |       ||       ||   _   ||    _ |  |       ||  | |  |                                   **"
	"\n**                        |  _____||    ___||  |_|  ||   | ||  |       ||  |_|  |                                   **"
	"\n**                        | |_____ |   |___ |       ||   |_||_ |       ||       |                                   **"
	"\n**                        |_____  ||    ___||       ||    __  ||      _||       |                                   **"
	"\n**                         _____| ||   |___ |   _   ||   |  | ||     |_ |   _   |                                   **"
	"\n**                        |_______||_______||__| |__||___|  |_||_______||__| |__|                                   **"
	"\n**         ___   __    _  _______  ______    _______  ______   ___   _______  __    _  _______  _______             **"
	"\n**        |   | |  |  | ||       ||    _ |  |       ||      | |   | |       ||  |  | ||       ||       |            **"
	"\n**        |   | |   |_| ||    ___||   | ||  |    ___||  _    ||   | |    ___||   |_| ||_     _||  _____|            **"
	"\n**        |   | |       ||   | __ |   |_||_ |   |___ | | |   ||   | |   |___ |       |  |   |  | |_____             **"
	"\n**        |   | |  _    ||   ||  ||    __  ||    ___|| |_|   ||   | |    ___||  _    |  |   |  |_____  |            **"
	"\n**        |   | | | |   ||   |_| ||   |  | ||   |___ |       ||   | |   |___ | | |   |  |   |   _____| |            **"
	"\n**        |___| |_|  |__||_______||___|  |_||_______||______| |___| |_______||_|  |__|  |___|  |_______|            **"
    "\n**                                                                                                                  **"
    "\n**     1. Search ingredients                                                                                        **"   
    "\n**     2. Return to the previous menu                                                                               **"
    "\n**********************************************************************************************************************"  << endl;
    cout << "Select an option : ";
    cin >> option;
    switch (option) {
		case 1:
			cout << "\n   -SEARCH INGREDIENTS-***" << endl;
			iList->isFound();
			break;
		case 2:
			cout << "\n  Going Back...";
			break;
		default:
			cout << "\n OOPS......TRY AGAIN 1 or 2" << endl;
	} } while (option != 2);
}