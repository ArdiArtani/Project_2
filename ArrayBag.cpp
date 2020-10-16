/****************************************************************************************************************************
Title       : ArrayBag.cpp
Auhors      : Ardi Artani
Description     : The purpose of the ArrayBag class is to serve as the base class of the ShoppingCart class that has been provided to you in the given code; essentially, ArrayBag is meant to replace the DynamicArray of the previous project. Thus, you can test the final output of this project in the same way that you tested that of your previous project.
Copyright © 2020 Ardi Artani. All rights reserved.
****************************************************************************************************************************/

#include "ArrayBag.hpp"

/**
   Default Constructor
   item_count_  <- 0
**/
template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): item_count_(0) {}


/**
   @return item_count_ : the current size of the bag
**/
template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const {
    // returns item_count_
    return item_count_;
}


/**
   @return true if item_count_ == 0, false otherwise
**/
template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const {
    // checks if item_count is equal to 0, if it is, it will return true otherwise not empty false
    return item_count_ == 0;
}


/**
   @return true if new_entry was successfully added to items_, false otherwise
**/
template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& new_entry){
    // check if item_count_ is less than DEFAULT_CAPACITY
    bool bag_room_ = (item_count_ < DEFAULT_CAPACITY);
    if (bag_room_)
    {
        // insert new_entry and increment item_count_
        items_[item_count_] = new_entry;
        item_count_++;
    }
    return bag_room_;
}


/**
   @return true if an_entry was successfully removed from items_, false otherwise
**/
template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& an_entry) {
    // first get the index of an_entry
    int locatedIndex = getIndexOf(an_entry);

    // it must check whether an_entry is within the array
    bool can_remove_item_ = !isEmpty() && (locatedIndex > -1);
    if (can_remove_item_)
    {
        // decrement item_count_, last item in place of item to be removed
        item_count_--;
        items_[locatedIndex] = items_[item_count_];
    }
    return can_remove_item_;
}


/**
   @post item_count_ == 0
**/
template<class ItemType>
void ArrayBag<ItemType>::clear() {
    // set item_count_ to 0
    item_count_ = 0;
}


/**
   @return true if an_entry is found in items_, false otherwise
   -> THIS METHOD MUST CALL getIndexOf() <-
**/
template <class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& an_entry) const {
    // returns whether the caller contains parameter T an_entry by checking whether its indexis above sentinel value -1
    return getIndexOf(an_entry) > -1;
}


/**
   @return the number of times an_entry appears in items_
**/
template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& an_entry) const {
    // initialize frequency, current_index to 0
    int frequency_ = 0;
    int current_index = 0;
    while (current_index < item_count_)
    {
        if (items_[current_index] == an_entry)
        {
            frequency_++;
        }
        current_index++; //increment to next entry
    }
    return frequency_;
}


/**
   Implements Set Union.  The union of two sets A and B is the set of
   elements, which are in A, in B, or in both A and B.
   @param a_bag to be combined with the contents of this (the calling) bag
   @post adds as many items from a_bag as space allows lhs += rhs,
   the left hand side (the calling side) of the operator will be modified.
**/
template<class ItemType>
void ArrayBag<ItemType>::operator+=(const ArrayBag<ItemType> &a_bag)
{
    // for loop the total items in a_bag
    for(int i=0; i < a_bag.getCurrentSize(); i++)
    {
        // NOT [check if item from lhs is found in rhs]
        if (!this->contains(a_bag.items_[i]))
        {
            this->add(a_bag.items_[i]);
        }
    }
}


/**
   Implements Set Difference
   The (set) difference between two sets A and B is the set that
   consists of the elements in A which are not elements of B.
   @param a_bag to be subtracted from this (the calling) bag
   @post removes all the data from items_ that is also found in a_bag
      lhs -= rhs, the left hand side (the calling side) of the operator
      will be modified, remove elements from lhs that are also elements
      of the rhs (a_bag).
**/
template<class ItemType>
void ArrayBag<ItemType>::operator-=(const ArrayBag<ItemType> &a_bag)
{
    // for loop the total items in a_bag
    for(int i=0; i < a_bag.getCurrentSize(); i++)
    {
        // check if item from rhs is found in lhs
        if (this->contains(a_bag.items_[i]))
        {
            this->remove(a_bag.items_[i]);
        }
    }
}


/**
   Implements Set Intersection
   The intersection of two sets A and B is the set that
   consists of the elements that are in both A and B.
   @param a_bag to be intersected with this (the calling) bag
   @post items_ no longer contains elements not found in a_bag
      lhs /= rhs, the left hand side (the calling side) of
      the operator will be modified, remove elements from
      lhs that are NOT elements of the rhs (a_bag).
**/
template<class ItemType>
void ArrayBag<ItemType>::operator/=(const ArrayBag<ItemType> &a_bag)
{
    // for loop the total items in a_bag
    for (int i = 0; i < a_bag.getCurrentSize(); i++) {
        // NOT [check if item from lhs is found in rhs (a_bag)]
        if (!a_bag.contains(this->items_[i]))
        {
            this->remove(this->items_[i]);
        }
    }
}


/**
   Implements Equal Comparison
   Two ArrayBags are equal to each other if they contain the same elements
   the order of the elements do not matter.
   @param a_bag to be compared with this (the calling) bag
   @return true if the two bags contain the same elements, false otherwise
   Note that in order for two bags to be equal the must be of equal sizes.
**/
template<class ItemType>
bool ArrayBag<ItemType>::operator==(const ArrayBag<ItemType> &a_bag)
{
    // If both bags are empty, then they are equal. You wrote return false in the == operator when they are empty.
    if( (this->isEmpty()) && (a_bag.isEmpty()) )
    {
        return true;
    }
    else if (this->getCurrentSize() == a_bag.getCurrentSize())
    {
        // for loop the total items in a_bag
        for (int i = 0; i < a_bag.getCurrentSize(); i++) {
            if (!a_bag.contains(this->items_[i]))
            {
                return false;
            }
        }
        return true;
    } // size comparison
    return false;
}


/**
   Implements Not Equal Comparison Opposite of the == operator, if two bags
      have at least one element different they are not equal
   @param a_bag to be compared with this (the calling) bag
   @return true if two bags have a differing element, false if they are equal
      In this case we can be sure that two arrays are not equal if they have different sizes.
**/
template<class ItemType>
bool ArrayBag<ItemType>::operator!=(const ArrayBag<ItemType> &a_bag)
{
    if( (this->isEmpty()) && (a_bag.isEmpty()) )
    {
        return true;
    }
    else if (this->getCurrentSize() == a_bag.getCurrentSize())
    {
        // for loop the total items in a_bag
        for (int i = 0; i < a_bag.getCurrentSize(); i++) {
            if (a_bag.contains(this->items_[i]))
            {
                return false;
            }
        }
        return true;
    } // size comparison
    return false;
}

// PROTECTED MEMBERS

/**
   @param target to be found in items_
   @return either the index target in the array items_ or -1,
   if the array does not containthe target.
**/
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const {
    bool found = false;
    int result = -1;
    int search_index = 0;

    // If the bag is empty, item_count_ is zero, so loop is skipped
    while (!found && (search_index < item_count_))
    {
        if (items_[search_index] == target)
        {
            found = true;
            result = search_index;
        }
        else
        {
            search_index++;
        }    // end if
    }    // end while
    return result;
}






// end of ArrayBag.cpp


