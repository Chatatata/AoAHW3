//
//  DOMElement.cpp
//  AoAHW3
//
//  Created by Buğra Ekuklu on 25.11.2016.
//  Copyright © 2016 The Digital Warehouse. All rights reserved.
//

#include "DOMElement.hpp"

DOMElement::DOMElement(const UInt64 index, const UInt64 data)
: index(index), data(data)
{
    //  Empty implementation
}

DOMElement::DOMElement(const DOMElement &other)
: index(other.index), data(other.data)
{
    //  Empty implementation
}

DOMElement &
DOMElement::operator = (const DOMElement &other)
{
    if (this != &other) {
        index = other.index;
        data = other.data;
    }
    
    return *this;
}

Boolean
DOMElement::operator < (const DOMElement &other) const noexcept
{
    return this->data < other.data;
}

DOMElement::operator UInt64() const noexcept
{
    return data;
}
