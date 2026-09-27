//
// Created by micah a on 9/27/2026.
//

#include "Recipe.h"

// Function -- constructor for Recipe objects
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
