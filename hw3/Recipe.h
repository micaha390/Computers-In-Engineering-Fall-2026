//
// Created by micah a on 9/27/2026.
//

#ifndef HW3_RECIPE_H
#define HW3_RECIPE_H
#include <string>
#include <vector>

#include "Ingredient.h"


class Recipe {
    public:
    private:
        std::string name;
        int servings;
        std::vector<Ingredient> ingredient;
};


#endif //HW3_RECIPE_H
