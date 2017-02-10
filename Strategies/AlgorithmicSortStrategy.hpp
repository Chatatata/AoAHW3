//
//  AlgorithmicSortStrategy.hpp
//  AoAHW3
//
//  Created by Buğra Ekuklu on 26.11.2016.
//  Copyright © 2016 The Digital Warehouse. All rights reserved.
//

#pragma once

#include "../Containers/Array.hpp"

template <typename T>
class AlgorithmicSortStrategy {
public:
    AlgorithmicSortStrategy(const Container::Array<T> &array);
    virtual ~AlgorithmicSortStrategy() { }
    
    virtual void sort() noexcept = 0;
    virtual const Container::Array<T> &getArray() const noexcept;
    
protected:
    Container::Array<T> array;
};
