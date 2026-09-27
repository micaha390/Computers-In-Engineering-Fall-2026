#include <iostream>
#include "Ingredient.h"
#include "Recipe.h"

using namespace std;

int main() {
    Recipe recipe1;
    Recipe recipe2("Honey Chicken", 10);
    Ingredient chickenThighs("Chicken Thighs", "lbs", 2.5, 3.99);
    Ingredient honey("Honey", "cups", .33, 1.99);
    recipe2.addIngredient(chickenThighs);
    recipe2.addIngredient(honey);

    recipe1.print();
    recipe2.print();

    return 0;
}
