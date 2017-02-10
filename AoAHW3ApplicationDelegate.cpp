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
#include <chrono>
#include <fstream>

#include "Models/DOMElement.hpp"
#include "Strategies/RadixSortStrategy.cpp"

UInt16
AoAHW3ApplicationDelegate::applicationDidStart(const Container::Array<String> &arguments) const noexcept
{
    using StringStream = std::stringstream;
    using InputFileStream = std::ifstream;
    using OutputFileStream = std::ofstream;
    using HighResolutionClock = std::chrono::high_resolution_clock;
    using Container::Array;
    
    if (arguments.getLength() == 2) {
        Array<DOMElement> array;
        
        InputFileStream inputFile("numbers_to_sort.txt");
        OutputFileStream outputFile("sorted_numbers.txt");
        String feed;
        UInt64 inputLength = std::stoll(arguments[1]);
        
        for (UInt64 i = 0; !inputFile.eof() && i < inputLength; ++i) {
            inputFile >> feed;
            inputFile >> feed;
            
            array.append(DOMElement(i, std::stoll(feed)));
        }
        
        RadixSortStrategy<DOMElement> rss(array);
        
        auto startTime = HighResolutionClock::now();
        
        rss.sort();
        
        auto endTime = HighResolutionClock::now();
        
        printf("Counting sort based radix sort duration: %llu nanoseconds\n", std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count());
        
        for (UInt64 i = 0; i < rss.getArray().getLength(); ++i) {
            outputFile
            << rss.getArray()[i].index
            << "\t"
            << rss.getArray()[i].data
            << std::endl;
        }
            
        return 0;
    } else {
        fprintf(stderr, "wrong number of input argument(s), expected 1 or 2");
        
        return 9;
    }
}




















