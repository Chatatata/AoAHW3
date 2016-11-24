//
//  AoAHW3ApplicationDelegate.cpp
//  AoAHW3
//
//  Created by Buğra Ekuklu on 04.11.2016.
//  Copyright © 2016 The Digital Warehouse. All rights reserved.
//

#include "AoAHW3ApplicationDelegate.hpp"

#include <cassert>
#include <algorithm>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>

#include <fstream>

#include "Strategies/RadixSortStrategy.cpp"
#include "Models/DOMElement.hpp"

using StringStream = std::stringstream;

UInt16
AoAHW3ApplicationDelegate::applicationDidStart(const Container::Array<String> &arguments) const noexcept
{
    Array<DOMElement> array;
    
    std::ifstream inputFile("numbers_to_sort.txt");
    String feed;
    
    for (UInt64 i = 0; !inputFile.eof(); ++i) {
        inputFile >> feed;
        inputFile >> feed;
        
        array.append(DOMElement(i, std::stoll(feed)));
    }
    
    RadixSortStrategy<DOMElement> rss(array);
    
    rss.sort();
    
    for (UInt64 i = 0; i < rss.getArray().getLength(); ++i) printf("%llu\t%llu\n", rss.getArray()[i].index, rss.getArray()[i].data);
    
    return 0;
}
