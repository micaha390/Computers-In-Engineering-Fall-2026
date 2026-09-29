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
        double getTotalCost() const;
        double getCostPerServing() const;

        void addIngredient(Ingredient const &newIngredient);
        void removeIngredient(std::string const &minusIngredient);
        void scaleServings(int const &newServings);

        void print() const;
    private:
        /* the currency symbol output with costs,
         * change this this to a string and edit the print function to output currency after the costs
         * if you want to use a currency code instead of a symbol
         */
        static constexpr char currency = '$';
        std::string name;
        int servings;
        std::vector<Ingredient> ingredient{};
};


#endif //HW3_RECIPE_H
