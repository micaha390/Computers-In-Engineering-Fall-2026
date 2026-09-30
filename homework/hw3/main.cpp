// programmer: Micah Anderson
// date: September 28 2026
// filename: main.cpp
// description: this program models recipes using a class that contains a vector of ingredient objects


#include <iostream>
#include "Ingredient.h"
#include "Recipe.h"

using namespace std;

int main() {
    Ingredient groundBeefCasserole("Ground Beef", "lb", 1, 6.99);
    Ingredient shreddedCheese("Shredded Cheese", "ozs", 12, .32);
    Ingredient cheeseSoup("Cheddar Cheese Soup", "can", 1, 1.99);
    Ingredient mushroomSoup("Mushroom Soup", "can", 1, 1.99);
    Ingredient taterTots("Frozen Tater Tots", "bag", 1, 4.99);

    Ingredient chickenThighs("Chicken Thighs", "lbs", 2.5, 3.99);
    Ingredient honey("Honey", "cups", .33, 1.99);
    Ingredient soySauce("Soy Sauce", "cups", .33, .50);
    Ingredient mincedGarlic("Minced Garlic", "cloves", 6, .05);

    Ingredient groundBeefChili("Ground Beef", "lb", 2, 6.99);
    Ingredient blackBeans("Black Beans", "can", 1, .99);
    Ingredient kidneyBeans("Kidney Beans", "can", 2, .99);
    Ingredient pintoBeans("Pinto Beans", "can", 1, .99);
    Ingredient crushedTomato("Crushed Tomato", "can", 2, 1.99);
    Ingredient tomatoPaste("Tomato Paste", "can", 1, .99);
    Ingredient chiliPowder("Chili Powder", "Tbsps", 3, .15);
    Ingredient worcestershireSauce("Worcestershire Sauce", "Tbsp", 1, .25);

    cout << "create recipe named Tater Tot Casserole that makes 10 servings" << endl;
    Recipe recipe1("Tater Tot Casserole", 10);
    cout << "Expected results:" << endl << "\tname: Tater Tot Casserole, servings: 10, costs: both 0, no ingredients" << endl;
    recipe1.print();
    cout << "adding ingredients: " << endl << "\t1 lb ground beef @ $2.99 per lb" << endl;
    cout <<"\t12 oz shredded cheese @ $0.32 per oz" << endl << "\t1 can cheese soup @ $1.99 per can" << endl;
    recipe1.addIngredient(groundBeefCasserole);
    recipe1.addIngredient(shreddedCheese);
    recipe1.addIngredient(cheeseSoup);
    cout << "Expected results:" << endl << "\tname: Tater Tot Casserole, servings: 10" << endl;
    cout << "\tcost per serving: $1.28" << endl;
    cout << "\ttotal cost: $12.82" << endl;
    cout << "\tIngredients:" << endl << "\t\t1.00 lb Ground Beef" << endl << "\t\t12.00 ozs Shredded Cheese" << endl;
    cout << "\t\t1.00 can Cheddar Cheese Soup" << endl;
    recipe1.print();
    cout << "adding ingredients: " << endl << "\t1 can mushroom soup @ $1.99 per can" << endl;
    cout <<"\t1 bag tater tots @ $4.99 per bag" << endl;
    recipe1.addIngredient(mushroomSoup);
    recipe1.addIngredient(taterTots);
    cout << "Expected results:" << endl << "\tname: Tater Tot Casserole, servings: 10" << endl;
    cout << "\tcost per serving: $1.98" << endl;
    cout << "\ttotal cost: $19.80" << endl;
    cout << "\tIngredients:" << endl << "\t\t1.00 lb Ground Beef" << endl << "\t\t12.00 ozs Shredded Cheese" << endl;
    cout << "\t\t1.00 can Cheddar Cheese Soup" << endl << "\t\t1.00 can Mushroom Soup" << endl;
    cout << "\t\t1.00 bag Frozen Tater Tots" << endl;
    recipe1.print();
    cout << "Expected results:" << endl << "\tname: Tater Tot Casserole, servings: 10" << endl;
    cout << "\tcost per serving: $1.58" << endl;
    cout << "\ttotal cost: $15.82" << endl;
    cout << "\tIngredients:" << endl << "\t\t1.00 lb Ground Beef" << endl << "\t\t12.00 ozs Shredded Cheese" << endl;
    cout << "\t\t1.00 bag Frozen Tater Tots" << endl;
    cout << "removing ingredients: " << endl << "\t1 can mushroom soup @ $1.99 per can" << endl;
    cout <<"\t1 can cheese soup @ $1.99 per can" << endl;
    recipe1.removeIngredient("Mushroom Soup");
    recipe1.removeIngredient("Cheddar Cheese Soup");
    cout << "Expected results:" << endl << "\tname: Tater Tot Casserole, servings: 10" << endl;
    cout << "\tcost per serving: $1.58" << endl;
    cout << "\ttotal cost: $15.82" << endl;
    cout << "\tIngredients:" << endl << "\t\t1.00 lb Ground Beef" << endl << "\t\t12.00 ozs Shredded Cheese" << endl;
    cout << "\t\t1.00 bag Frozen Tater Tots" << endl;
    recipe1.print();
    cout << "adding ingredients: " << endl << "\t1 can mushroom soup @ $1.99 per can" << endl;
    cout <<"\t1 can cheese soup @ $1.99 per can" << endl;
    recipe1.addIngredient(mushroomSoup);
    recipe1.addIngredient(cheeseSoup);
    cout << "changing the number of servings to 15, 1.5 times the original recipe";
    recipe1.scaleServings(15);
    cout << "Expected results:" << endl << "\tname: Tater Tot Casserole, servings: 15" << endl;
    cout << "\tcost per serving: $1.98" << endl;
    cout << "\ttotal cost: $29.70" << endl;
    cout << "\tIngredients:" << endl << "\t\t1.50 lb Ground Beef" << endl << "\t\t18.00 ozs Shredded Cheese" << endl;
    cout << "\t\t1.50 can Cheddar Cheese Soup" << endl << "\t\t1.50 can Mushroom Soup" << endl;
    cout << "\t\t1.50 bag Frozen Tater Tots" << endl;
    recipe1.print();


    Recipe recipe2("Honey Chicken", 6);
    recipe2.addIngredient(chickenThighs);
    recipe2.addIngredient(honey);
    recipe2.addIngredient(soySauce);
    recipe2.addIngredient(mincedGarlic);
    cout << "Expected results:" << endl << "\tname: Honey Chicken, servings: 6" << endl;
    cout << "\tcost per serving: $1.85" << endl;
    cout << "\ttotal cost: $11.10" << endl;
    cout << "\tIngredients:" << endl << "\t\t2.50 lbs Chicken Thighs" << endl << "\t\t0.33 cups Honey" << endl;
    cout << "\t\t0.33 cups Soy Sauce" << endl << "\t\t6.00 cloves Minced Garlic" << endl;
    recipe2.print();
    cout << "increase the serving by 2.5 times" << endl;
    recipe2.scaleServings(15);
    cout << "Expected results:" << endl << "\tname: Honey Chicken, servings: 6" << endl;
    cout << "\tcost per serving: $1.85" << endl;
    cout << "\ttotal cost: $27.74" << endl;
    cout << "\tIngredients:" << endl << "\t\t6.25 lbs Chicken Thighs" << endl << "\t\t0.83 cups Honey" << endl;
    cout << "\t\t0.83 cups Soy Sauce" << endl << "\t\t15.00 cloves Minced Garlic" << endl;
    recipe2.print();

    Recipe recipe3("Chili", 12);
    recipe3.addIngredient(groundBeefChili);
    recipe3.addIngredient(blackBeans);
    recipe3.addIngredient(kidneyBeans);
    recipe3.addIngredient(pintoBeans);
    recipe3.addIngredient(crushedTomato);
    recipe3.addIngredient(tomatoPaste);
    recipe3.addIngredient(chiliPowder);
    recipe3.addIngredient(worcestershireSauce);

    cout << "Expected results:" << endl << "\tname: Chili, servings: 12" << endl;
    cout << "\tcost per serving: $1.97" << endl;
    cout << "\ttotal cost: $23.61" << endl;
    cout << "\tIngredients:" << endl << "\t\t2.00 lbs Ground Beef" << endl << "\t\t1.00 can Black Beans" << endl;
    cout << "\t\t2.00 cans Kidney Beans" << endl << "\t\t1.00 can Pinto Beans" << endl;
    cout << "\t\t2.00 cans Crushed Tomato" << endl << "\t\t1.00 can Tomato Paste" << endl;
    cout << "\t\t3.00 Tbsps Chili Powder" << endl << "\t\t1.00 Tbsp Worcestershire Sauce" << endl;
    recipe3.print();
    cout << "double the servings" << endl;
    recipe3.scaleServings(24);
    cout << "Expected results:" << endl << "\tname: Chili, servings: 24" << endl;
    cout << "\tcost per serving: $1.97" << endl;
    cout << "\ttotal cost: $47.22" << endl;
    cout << "\tIngredients:" << endl << "\t\t4.00 lbs Ground Beef" << endl << "\t\t2.00 can Black Beans" << endl;
    cout << "\t\t4.00 cans Kidney Beans" << endl << "\t\t2.00 can Pinto Beans" << endl;
    cout << "\t\t4.00 cans Crushed Tomato" << endl << "\t\t2.00 can Tomato Paste" << endl;
    cout << "\t\t6.00 Tbsps Chili Powder" << endl << "\t\t2.00 Tbsp Worcestershire Sauce" << endl;
    recipe3.print();

    return 0;
}
