/// @file OrderedSet.cpp
/// @author Chris Catechis
/// @date 6/17/21
/// @brief This program hosts out of line functions for the OrderedSet
/// class.

#include "OrderedSet.h"
#include <iostream>
#include <cassert>

/// Inserts an item into the container and shifts greater items right.
/// Internally, the items are maintained in an ascending order.
/// @pre size() < CAPACITY
/// @param value Element value to insert.
void OrderedSet::insert(const value_type& value) {
    size_type index = 0;  // index for insertion of value.

    // locate insertion point
    for ( ; index < size() && data[index] < value; ++index) {}

    if (index == size() || (index < size() && data[index] != value)){
        assert (size() < CAPACITY);

        for (auto i = size(); i > index ; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        
        ++used;
    }
}


/// Removes item from the container equal to the target value.
/// Shifts greater items left after removal of item. 
/// Internally, the items are maintained in an ascending order.
/// @param target Key value of the items to remove.
void OrderedSet::erase(const value_type& target) {
    size_type index = 0;  // location of target in the array


    // locate point to erase
    for ( ; index < size() && data[index] != target; ++index) {}

    if (index != size()) {
        // copy items left to right, overwriting previous item.
        for (auto i = index; i < size() - 1; ++i){
            data[i] = data[i + 1];
        }

        used--;
    }

    // else data does not contain target.
}

/// Checks if there is an item with its value equal to the target and
/// ensures the OrderedSet is ordered.
/// @param target Key value of the item to search for.
/// @returns true if there is such an item and the set in in order,
///          otherwise false.
bool OrderedSet::contains(const value_type& target)const {
    bool isPresent = false;  // checks if target is present.
    bool flag = false;  // loop control bool.

    for (size_type i = 0; i < used && flag == false; i++){
        if (data[i] == target){
            isPresent = true;
            flag = true;
        }
        else if (data[i] > target){
            flag = true;
        }
    }

    return isPresent;
}
