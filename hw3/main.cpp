#include <iostream>
#include "Ingredient.h"

using namespace std;

int main() {
    Ingredient ingredient1;
    Ingredient ingredient2("flour", "grams", 780, .01);

    ingredient1.print();
    ingredient2.print();

    return 0;
}
