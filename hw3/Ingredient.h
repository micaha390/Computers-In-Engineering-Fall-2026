//
// Created by micah a on 9/27/2026.
//

#ifndef HW3_INGREDIENT_H
#define HW3_INGREDIENT_H
#include <string>

class Ingredient {
    public:
        void setName(std::string const &newName);
        void setUnit(std::string const &newUnits);
        void setQuantity(double const &newQuantity);
        void setCostPerUnit(double const &newCostPerUnit);

        std::string getName() const;
        std::string getUnit() const;
        double getQuantity() const;
        double getCostPerUnit() const;

    private:
        std::string name;
        std::string unit;
        double quantity;
        double costPerUnit;
};


#endif //HW3_INGREDIENT_H
