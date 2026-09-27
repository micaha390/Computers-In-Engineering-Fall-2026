#include <iostream>
#include "Ingredient.h"
#include "Recipe.h"

using namespace std;

int main() {
    Recipe recipe1;
    Recipe recipe2("Honey Chicken", 6);

    Ingredient chickenThighs("Chicken Thighs", "lbs", 2.5, 3.99);
    Ingredient honey("Honey", "cups", .33, 1.99);
    Ingredient soySauce("Soy Sauce", "cups", .33, .50);
    Ingredient mincedGarlic("Minced Garlic", "cloves", 6, .05);

    recipe2.addIngredient(chickenThighs);
    recipe2.addIngredient(honey);
    recipe2.addIngredient(soySauce);
    recipe2.addIngredient(mincedGarlic);


    recipe1.print();
    recipe2.print();

    recipe2.removeIngredient("Minced Garlic");

    recipe2.print();

    return 0;
}
