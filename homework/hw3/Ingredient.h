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
        void scale(double const &scalingFactor);

        std::string getName() const;
        std::string getUnit() const;
        double getQuantity() const;
        double getCostPerUnit() const;
        double getCost() const;

        void print();



    private:
        /* the currency symbol output with costs,
         * change this this to a string and edit the print function to output currency after the costs
         * if you want to use a currency code instead of a symbol
         */
        static constexpr char currency = '$';
        std::string name;
        std::string unit;
        double quantity;
        double costPerUnit;
};


#endif //HW3_INGREDIENT_H
