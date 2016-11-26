//
//  HeapSortStrategy.hpp
//  AoAHW3
//
//  Created by Buğra Ekuklu on 26.11.2016.
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
class HeapSortStrategy : public AlgorithmicSortStrategy<T> {
public:
    HeapSortStrategy(const Container::Array<T> &array);
    
    void sort() noexcept override;
    void buildHeap() noexcept;
    void minimumHeapify(const UInt64 targetIndex, const UInt64 lastIndex) noexcept;
};
