/****************************************************************************************************************************
Title        : Vegetable.cpp
Auhors       : Nursima Donuk & Nigel Ferrer
Description  : implementation file of a Vegetable object class which inherits from the abstract Grocery class
Dependencies : Grocery.hpp, Vegetable.hpp
****************************************************************************************************************************/

#include "Vegetable.hpp"

/* Constructor */
Vegetable::Vegetable(std::string name, double price, double weight) : Grocery(name, price, weight)
{
    updateCost();
}

/* Setter: Grocery::total_price_ */
void Vegetable::updateCost()
{
    if (quantity_ >= 0)
    {
        total_price_ = quantity_ * unit_weight_ * unit_price_;
    }
}