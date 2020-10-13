/****************************************************************************************************************************
Title       : Grocery.hpp
Auhors      : Nursima Donuk & Nigel Ferrer
Description : header/interface file of an abstract Grocery item class
****************************************************************************************************************************/

#ifndef GROCERY_
#define GROCERY_

#include <iostream>
#include <string>

class Grocery
{
public:
    /** 
        Constructor 
        @param name   : name of item
        @param price  : the unit price of the item
        @param weight : the unit weight of the item
        @post         : quantity_ <- 1, total_price_ <- 0
    */
    Grocery(std::string name, double price, double weight);

    /**
        @post   : quantity_ <- quantity_++
                    called updateCost()
        @return : true if quantity has been successfully
                    incremented; false otherwise
    */
    bool incrementQuantity();

    /**
        @post   : quantity_ <- quantity_--
                    called updateCost()
        @return : true if quantity has been successfully
                    decremented; false otherwise
    */
    bool decrementQuantity();

    double getTotalPrice() const; // Accessor: total_price_
    double getUnitPrice() const;  // Accessor: unit_cost_
    double getUnitWeight() const; // Accessor: unit_weight_
    int getQuantity() const;      // Accessor: quantity_
    std::string getName() const;  // Accessor: name_

    /**
        defines comparison operator for Grocery objects
    */
    bool operator==(const Grocery &rhs) const;

protected:
    /** 
        PURE VIRTUAL FUNCTION; THERE IS NO IMPLEMENTATION

        Calculates and sets total_price_ if quantity_ >= 0
    */
    virtual void updateCost() = 0;

    std::string name_;
    int quantity_;
    double unit_price_;
    double unit_weight_;
    double total_price_;
}; // end Grocery

#endif
