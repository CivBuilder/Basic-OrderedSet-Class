/// @file OrderedSet.h
/// @author Chris Catechis
/// @date 6/17/21
/// @brief This program creates the OrderedSet class.

    #ifndef ORDERED_SET_H
    #define ORDERED_SET_H

    #include "Container.h"

    /// An OrderedSet is a Container that stores a sorted set of unique values.

    class OrderedSet : public Container {
    public:

        /// Constructs the Container.
        OrderedSet() {used = 0;}

        /// Inserts an item into the container and shifts greater items right.
        /// Internally, the items are maintained in an ascending order.
        /// @pre size() < CAPACITY
        /// @param value Element value to insert.
        void insert(const value_type& value);

        /// Removes item from the container equal to the target value.
        /// Shifts greater items left after removal of item. 
        /// Internally, the items are maintained in an ascending order.
        /// @param target Key value of the items to remove.
        void erase(const value_type& target);

        /// Checks if there is an item with its value equal to the target and
        /// ensures the OrderedSet is ordered.
        /// @param target Key value of the item to search for.
        /// @returns true if there is such an item and the set in in order,
        ///          otherwise false.
        bool contains(const value_type& target);
    };

    #endif /* ORDERED_SET_H */