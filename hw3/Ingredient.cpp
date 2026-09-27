//
// Created by micah a on 9/27/2026.
//

#include "Ingredient.h"

// Function -- Sets the name of the Ingredient object
// Inputs -- newName -- string -- the new name of the Ingredient object
// Outputs -- none
void Ingredient::setName(std::string const &newName) {
    name = newName;
}

// Function -- Sets the unit type of the Ingredient object (e.g. lbs, grams, cups, etc.)
// Inputs -- newUnit -- string -- the new unit type of the Ingredient object
// Outputs -- none
void Ingredient::setUnit(std::string const &newUnit) {
    unit = newUnit;
}

// Function -- Sets the quantity of the Ingredient object to a positive double
// Inputs -- newQuantity -- double -- the new quantity of the Ingredient object,
//           if it is not positive quantity is set to 1.0
// Outputs -- none
void Ingredient::setQuantity(double const &newQuantity) {
    if (newQuantity > 0.0) {
        quantity = newQuantity;
    }
    else {
        quantity = 1.0;
    }
}

// Function -- Sets the cost per unit of the Ingredient object to a positive double
// Inputs -- newCostPerUnit -- double -- the new cost per unit of the Ingredient object,
//           if it is not positive quantity is set to 1.0
// Outputs -- none
void Ingredient::setCostPerUnit(double const &newCostPerUnit) {
    if (newCostPerUnit > 0.0) {
        costPerUnit = newCostPerUnit;
    }
    else {
        costPerUnit = 1.0;
    }
}

std::string Ingredient::getName() const {
    return name;
}

std::string Ingredient::getUnit() const {
    return unit;
}

double Ingredient::getQuantity() const {
    return quantity;
}

double Ingredient::getCostPerUnit() const {
    return costPerUnit;
}

// Function -- constructor for Ingredient objects
// Inputs -- newName -- string -- the name for the ingredient, defaults to "generic ingredient"
//           newUnit -- string -- the units for the ingredient, defaults to "cups"
//           newQuantity -- double -- the amount of the ingredient, defaults to "1.0"
//           newCostPerUnit -- double -- the cost per unit of the ingredient, defaults to "1.0"
// Outputs -- none
Ingredient::Ingredient(std::string const &newName, std::string const &newUnit,
    double const &newQuantity, double const &newCostPerUnit) {

    setName(newName);
    setUnit(newUnit);
    setQuantity(newQuantity);
    setCostPerUnit(newCostPerUnit);
}

// Function -- outputs the member variables of an Ingredient object to the console
// Inputs -- none
// Outputs -- prints the member variables in a readable format
void Ingredient::print() {
    std::cout << "Ingredient: " << std::endl;
    std::cout << "\tName: " << getName() << std::endl;
    std::cout << "\tUnits: " << getUnit() << std::endl;
    std::cout << "\tQuantity: " << getQuantity() << std::endl;
    std::cout << "\tCost Per Unit: " << getCostPerUnit() << std::endl;
}