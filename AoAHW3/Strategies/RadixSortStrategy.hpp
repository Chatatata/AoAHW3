//
//  RadixSortableArray.hpp
//  AoAHW3
//
//  Created by Buğra Ekuklu on 24.11.2016.
//  Copyright © 2016 The Digital Warehouse. All rights reserved.
//

#pragma once

#include "../Containers/Array.hpp"

using Container::Array;

template <typename T>
class RadixSortStrategy {
public:
    RadixSortStrategy(const Array<T> &array);
    
    void sort() noexcept;
    const Array<T> &getArray() const noexcept;
    
private:
    Array<T> array;
    
    void countSort(UInt64 exponent);
};
