#include <iostream>
#include <fstream>
using namespace std;
#include "recipe.h"
#include "ingredientList.h"

#ifndef MAINMENU_H
#define MAINMENU_H

void runMenu(void);
void runRecipesMenu(Ingredients*, RecipeList*);
void viewRecipesMenu(Ingredients*, RecipeList*);
void viewAvailableRecipesMenu(Ingredients*, RecipeList*);
void viewUnavailableRecipesMenu(Ingredients*, RecipeList*);
void addRecipesMenu(Ingredients*, RecipeList*);
void removeRecipesMenu(Ingredients*, RecipeList*);
void runIngredientsMenu(Ingredients*);
void viewAvailableIngredientsMenu(Ingredients*);
void addIngredientsMenu(Ingredients*);
void removeIngredientsMenu(Ingredients*);
void searchIngredientsMenu(Ingredients*);

#endif