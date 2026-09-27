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
        Recipe(std::string const &newName = "generic recipe", int const &newServings = 1);

        void setName(std::string const &newName);
        void setServings(int const &newServings);

        std::string getName() const;
        int getServings() const;

    private:
        std::string name;
        int servings;
        std::vector<Ingredient> ingredient{};
};


#endif //HW3_RECIPE_H
