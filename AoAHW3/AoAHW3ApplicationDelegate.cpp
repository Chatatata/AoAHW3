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

//#include "Strategies/RadixSortStrategy.cpp"
#include "Models/DOMElement.hpp"

#include "Strategies/HeapSortStrategy.cpp"

UInt16
AoAHW3ApplicationDelegate::applicationDidStart(const Container::Array<String> &arguments) const noexcept
{
//    using StringStream = std::stringstream;
//    using InputFileStream = std::ifstream;
//    using OutputFileStream = std::ofstream;
//    using Container::Array;
//    
//    Array<DOMElement> array;
//    
//    InputFileStream inputFile("numbers_to_sort.txt");
//    OutputFileStream outputFile("sorted_numbers.txt");
//    String feed;
//    
//    for (UInt64 i = 0; !inputFile.eof(); ++i) {
//        inputFile >> feed;
//        inputFile >> feed;
//        
//        array.append(DOMElement(i, std::stoll(feed)));
//    }
//    
//    RadixSortStrategy<DOMElement> rss(array);
//    
//    rss.sort();
//    
//    for (UInt64 i = 0; i < rss.getArray().getLength(); ++i) {
//        outputFile
//        << rss.getArray()[i].index
//        << "\t"
//        << rss.getArray()[i].data
//        << std::endl;
//    }
    
    using StringStream = std::stringstream;
    using InputFileStream = std::ifstream;
    using OutputFileStream = std::ofstream;
    using Container::Array;
    
    Array<DOMElement> array;
    
    InputFileStream inputFile("ClanA.txt");
    OutputFileStream outputFile("sorted_numbers.txt");
    String feed;
    
    for (UInt64 i = 0; !inputFile.eof(); ++i) {
        inputFile >> feed;
        inputFile >> feed;
        
        array.append(DOMElement(i, std::stoll(feed)));
    }
    
    HeapSortStrategy<DOMElement> hss(array);
    
    hss.sort();
    
    for (UInt64 i = 0; i < hss.getArray().getLength() - 1; ++i) {
        assert(hss.getArray()[i] >= hss.getArray()[i + 1]);
//        
//        std::cout
//        << hss.getArray()[i].index
//        << "\t"
//        << hss.getArray()[i].data
//        << std::endl;
    }
    
    return 0;
}




















