//
//  AlgorithmicSortStrategy.cpp
//  AoAHW3
//
//  Created by Buğra Ekuklu on 26.11.2016.
//  Copyright © 2016 The Digital Warehouse. All rights reserved.
//

#include "AlgorithmicSortStrategy.hpp"

template <typename T>
AlgorithmicSortStrategy<T>::AlgorithmicSortStrategy(const Container::Array<T> &array)
: array(array)
{
    //  Empty implementation
}

template <typename T>
const Container::Array<T> &
AlgorithmicSortStrategy<T>::getArray() const noexcept
{
    return array;
}
