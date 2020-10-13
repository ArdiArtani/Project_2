/****************************************************************************************************************************
Title        : Drink.hpp
Auhors       : Nursima Donuk & Nigel Ferrer
Description  : implementation file of a Drink object class which inherits from the abstract Grocery class
Dependencies : Grocery.hpp, Drink.hpp
****************************************************************************************************************************/

#include "Drink.hpp"

#define FLOZ_PER_LITER 33.814

/* Constructor */
Drink::Drink(std::string name, double price, double weight) : Grocery(name, price, weight)
{
    updateCost();
}

/* Setter: Grocery::total_price_ */
void Drink::updateCost()
{
    if (quantity_ >= 0)
    {
        total_price_ = quantity_ * unit_price_ * (unit_weight_ * 16 / FLOZ_PER_LITER);
    }
}