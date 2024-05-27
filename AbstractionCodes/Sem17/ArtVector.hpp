//
//  ArtVector.hpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 24.05.24.
//

#ifndef ArtVector_hpp
#define ArtVector_hpp

#include <stdio.h>

class ArtVector {
private:
    ElasticArray arr;
    int realSize;
public:
    ArtVector();
    
    // vector methods
    void add(double value);
    
    int size();
    
    void remove(int index);
    
    double get(int index);
    void set(int index, double value);
}

#endif /* ArtVector_hpp */
