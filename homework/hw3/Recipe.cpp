//
// Created by micah a on 9/27/2026.
//

#include "Recipe.h"

#include <iomanip>

// Function -- constructor for Recipe objects, ingredient is initialized to an empty vector by in its declaration,
//             and is not changed by the constructor
// Inputs -- newName -- string -- the name of the recipe, defaults to "generic recipe"
//           newServings -- int -- the number of servings, defaults to "1"
// Outputs -- none
Recipe::Recipe(std::string const &newName, int const &newServings) {
    setName(newName);
    setServings(newServings);
}

// Function -- Sets the name of the Recipe object
// Inputs -- newName -- string -- the new name of the Recipe object
// Outputs -- none
void Recipe::setName(std::string const &newName) {
    name = newName;
}

// Function -- Sets the servings of the Recipe object to a positive int greater than 0
// Inputs -- newServings -- int -- the new servings of the Recipe object,
//           if it is not positive and greater than 0 servings is set to 1
// Outputs -- none
void Recipe::setServings(int const &newServings) {
    if (newServings > 0) {
        servings = newServings;
    }
    else {
        servings = 1;
    }
}

std::string Recipe::getName() const {
    return name;
}

int Recipe::getServings() const {
    return servings;
}

// Function -- Adds an Ingredient object to your Recipe
// Inputs -- newIngredient -- Ingredient -- an Ingredient object that is added to the ingredient vector
// Output -- none
void Recipe::addIngredient(Ingredient const &newIngredient) {
    ingredient.push_back(newIngredient);
}

// Function -- Removes an Ingredient object from your Recipe
// Inputs -- minusIngredient -- Ingredient -- an Ingredient object that is removed from the ingredient vector
// Output -- none
void Recipe::removeIngredient(std::string const &minusIngredient) {
    for (int i = 0; i < ingredient.size(); i++) {
        if (ingredient[i].getName() == minusIngredient) {
            ingredient.erase(ingredient.begin() + i);
        }
    }
}

// Function -- Changes the number of servings in your Recipe and scales the ingredients to match the new serving
// Inputs -- newServings -- int -- the new number of servings this Recipe makes
// Outputs -- none
void Recipe::scaleServings(int const &newServings){
    const double scalingFactor = static_cast<double>(newServings) / servings;
    for (auto &i:ingredient) {
        i.setQuantity(i.getQuantity() * scalingFactor);
    }
    servings = newServings;
}

// Function -- Returns the total cost of the recipe by summing the costs of the ingredients
// Inputs -- none
// Outputs -- totalCost -- double -- The total cost of the recipe
double Recipe::getTotalCost() const {
    double totalCost{0};

    for (auto i:ingredient) {
        totalCost += i.getCost();
    }

    return totalCost;
}

// Function -- Returns the cost per serving of the recipe
// Inputs -- none
// Outputs -- double -- The cost of the recipe per serving
double Recipe::getCostPerServing() const {
    return getTotalCost() / getServings();
}

// Function -- outputs the member variables of a Recipe object to the console
// Inputs -- none
// Outputs -- prints the member variables in a readable format
void Recipe::print() const {
    std::cout << "Recipe: " << std::endl;
    std::cout << "\tName: " << getName() << std::endl;
    std::cout << "\tServings: " << getServings() << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "\tCost Per Serving: " << currency << getCostPerServing() << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "\tTotal Cost: " << currency << getTotalCost() << std::endl;
    std::cout  << "\tIngredients:" << std::endl;
    for (auto i:ingredient) {
        std::cout << "\t\t" << i.getQuantity() << " " << i.getUnit() << " " << i.getName() << std::endl;
    }
}
