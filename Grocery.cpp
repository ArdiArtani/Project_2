/****************************************************************************************************************************
Title        : Grocery.hpp
Auhors       : Nursima Donuk & Nigel Ferrer
Description  : partial implementation file of an abstract Grocery item class
Dependencies : Grocery.hpp
****************************************************************************************************************************/

#include "Grocery.hpp"

/* Constructor */
Grocery::Grocery(std::string name, double price, double weight) : name_{name}, unit_price_{price}, unit_weight_{weight}, quantity_{1}
{
}

bool Grocery::incrementQuantity()
{
    try
    {
        quantity_++;
        updateCost();
    }

    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }

    return true;
}

bool Grocery::decrementQuantity()
{
    try
    {
        if (quantity_ > 0)
        {
            quantity_--;
            updateCost();
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }

    return true;
}

double Grocery::getTotalPrice() const
{
    return total_price_;
}

double Grocery::getUnitPrice() const
{
    return unit_price_;
}

double Grocery::getUnitWeight() const
{
    return unit_weight_;
}

int Grocery::getQuantity() const
{
    return quantity_;
}

std::string Grocery::getName() const
{
    return name_;
}

/* comparison operator overload */
bool Grocery::operator==(const Grocery &rhs) const
{
    return rhs.getName() == name_ && rhs.getUnitPrice() == unit_price_ && rhs.getQuantity() == quantity_ && rhs.getUnitWeight() == unit_weight_;
}
