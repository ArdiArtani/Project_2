/****************************************************************************************************************************
Title        : Vegetable.hpp
Auhors       : Nursima Donuk & Nigel Ferrer
Description  : header/interface file of a Vegetable object class which inherits from the abstract Grocery class
Dependencies : Grocery.hpp
****************************************************************************************************************************/

#ifndef VEGETABLE_
#define VEGETABLE_

#include "Grocery.hpp"

class Vegetable : public Grocery
{
public:
    /** 
        Constructor 
        @param name   : name of item
        @param price  : the unit price of the item
        @param weight : the unit weight of the item
        @post         : updateCost() has been called, which appropriately sets Grocery::total_price_
    */
    Vegetable(std::string name, double price, double weight);

private:
    /** 
        Calculates and sets Grocery::total_price_ if Grocery::quantity_ >= 0
        by the formula:

            total_price_ = quantity_ * unit_weight_ * unit_price_
    */
    void updateCost();

}; // end Vegetable
#endif