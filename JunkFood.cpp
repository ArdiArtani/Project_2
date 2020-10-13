/****************************************************************************************************************************
Title        : JunkFood.hpp
Auhors       : Nursima Donuk & Nigel Ferrer
Description  : implementation file of a JunkFood object class which inherits from the abstract Grocery class
Dependencies : Grocery.hpp, JunkFood.hpp
****************************************************************************************************************************/

#include "JunkFood.hpp"

/* Constructor */
JunkFood::JunkFood(std::string name, double price, double weight) : Grocery(name, price, weight)
{
    updateCost();
}

/* Setter: Grocery::total_price_ */
void JunkFood::updateCost()
{
    if (quantity_ >= 0)
    {
        total_price_ = quantity_ * unit_price_;
    }
}