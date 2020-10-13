/****************************************************************************************************************************
Title        : Drink.hpp
Auhors       : Nursima Donuk & Nigel Ferrer
Description  : header/interface file of a Drink object class which inherits from the abstract Grocery class
Dependencies : Grocery.hpp
****************************************************************************************************************************/

#ifndef DRINK_
#define DRINK_

#include "Grocery.hpp"

class Drink : public Grocery
{
public:
    /** 
        Constructor 
        @param name   : name of item
        @param price  : the unit price of the item
        @param weight : the unit weight of the item
        @post         : updateCost() has been called, which appropriately sets Grocery::total_price_
    */
    Drink(std::string name, double price, double weight);

private:
    /** 
        Calculates and sets Grocery::total_price_ if Grocery::quantity_ >= 0
        by the formula:

            total_price_ = quantity_ * unit_price_ * (unit_weight_ * 16 / FLOZ_PER_LITER)
    */
    void updateCost();
}; // end Drink
#endif