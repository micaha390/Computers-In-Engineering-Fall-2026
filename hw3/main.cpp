#include <iostream>
#include "Ingredient.h"
#include "Recipe.h"

using namespace std;

int main() {
    Recipe recipe1;
    Recipe recipe2("Honey Chicken", 10);

    recipe1.print();
    recipe2.print();

    return 0;
}
