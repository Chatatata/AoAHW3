//
//  RadixSortableArray.hpp
//  AoAHW3
//
//  Created by Buğra Ekuklu on 24.11.2016.
//  Copyright © 2016 The Digital Warehouse. All rights reserved.
//

#pragma once

#include "../PrefixHeader.pch"

template <typename T>
class AlgorithmicSortStrategy;

namespace Container {
    template <typename T>
    class Array;
}

template <typename T>
class RadixSortStrategy : public AlgorithmicSortStrategy<T> {
public:
    RadixSortStrategy(const Container::Array<T> &array);
    
    void sort() noexcept override;
    
private:
    void countSort(UInt64 exponent);
};
