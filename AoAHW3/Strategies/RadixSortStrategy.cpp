//
//  RadixSortableArray.cpp
//  AoAHW3
//
//  Created by Buğra Ekuklu on 24.11.2016.
//  Copyright © 2016 The Digital Warehouse. All rights reserved.
//

#include "RadixSortStrategy.hpp"

template <typename T>
RadixSortStrategy<T>::RadixSortStrategy(const Array<T> &array)
: array(array)
{
    //  Empty implementation
}

template <typename T>
void
RadixSortStrategy<T>::sort() noexcept
{
    T maximumValue = array[0];
    
    for (UInt64 i = 0; i < array.getLength(); ++i) {
        if (static_cast<UInt64>(array[i]) > static_cast<UInt64>(maximumValue)) {
            maximumValue = array[i];
        }
    }

    for (UInt64 exponent = 1; maximumValue / exponent > 0; exponent *= 10) {
        countSort(exponent);
    }
}

template <typename T>
void
RadixSortStrategy<T>::countSort(UInt64 exponent)
{
    Array<T> temporaryArray;
    temporaryArray.setLength(array.getLength());
    UInt64 bucket[10] = {0};
    
    for (UInt64 i = 0; i < array.getLength(); ++i) {
        bucket[(array[i] / exponent) % 10] += 1;
    }
    
    for (UInt64 i = 1; i < 10; ++i) {
        bucket[i] += bucket[i - 1];
    }
    
    for (UInt64 i = array.getLength() - 1; i > 0; --i) {
        temporaryArray[bucket[(static_cast<UInt64>(array[i]) / exponent) % 10] - 1] = array[i];
        bucket[(array[i] / exponent) % 10] -= 1;
    }
    
    temporaryArray[bucket[(static_cast<UInt64>(array[0]) / exponent) % 10] - 1] = array[0];
    bucket[(array[0] / exponent) % 10] -= 1;
    
    array = temporaryArray;
}

template <typename T>
inline
const Array<T> &
RadixSortStrategy<T>::getArray() const noexcept
{
    return array;
}















