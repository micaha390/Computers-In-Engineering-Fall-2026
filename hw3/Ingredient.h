//
// Created by micah a on 9/27/2026.
//

#ifndef HW3_INGREDIENT_H
#define HW3_INGREDIENT_H
#include <iostream>
#include <string>

class Ingredient {
    public:
        Ingredient(std::string const &newName = "generic ingredient", std::string const &newUnit = "cups",
            double const &newQuantity = 1.0, double const &newCostPerUnit = 1.0);

        void setName(std::string const &newName);
        void setUnit(std::string const &newUnits);
        void setQuantity(double const &newQuantity);
        void setCostPerUnit(double const &newCostPerUnit);

        std::string getName() const;
        std::string getUnit() const;
        double getQuantity() const;
        double getCostPerUnit() const;

        void print();

    private:
        std::string name;
        std::string unit;
        double quantity;
        double costPerUnit;
};


#endif //HW3_INGREDIENT_H
