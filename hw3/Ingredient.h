//
// Created by micah a on 9/27/2026.
//

#ifndef HW3_INGREDIENT_H
#define HW3_INGREDIENT_H
#include <string>

class Ingredient {
    public:
        void setName(std::string newName);
        void setUnits(std::string newUnits);
        void setQuantity(double newQuantity);
        void setCostPerUnit(double newCost);

        std::string getName();
        std::string getUnits();
        double getQuantity();
        double getCostPerUnit();

    private:
        std::string name;
        std::string unit;
        double quantity;
        double costPerUnit;
};


#endif //HW3_INGREDIENT_H
