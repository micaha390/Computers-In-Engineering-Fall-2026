//
// Created by micah a on 9/27/2026.
//

#include "Recipe.h"

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
