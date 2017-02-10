//
//  DOMElement.hpp
//  AoAHW3
//
//  Created by Buğra Ekuklu on 25.11.2016.
//  Copyright © 2016 The Digital Warehouse. All rights reserved.
//

#pragma once

#include "../PrefixHeader.pch"

struct DOMElement {
public:
    DOMElement(const UInt64 index = 0, const UInt64 data = 0);
    DOMElement(const DOMElement &other);
    DOMElement &operator = (const DOMElement &other);
    Boolean operator < (const DOMElement &other) const noexcept;
    
    UInt64 index;
    UInt64 data;
    
    operator UInt64() const noexcept;
};
