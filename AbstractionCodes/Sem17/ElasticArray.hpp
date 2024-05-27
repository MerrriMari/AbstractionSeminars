//
//  ElasticArray.hpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 20.05.24.
//

#ifndef ElasticArray_hpp
#define ElasticArray_hpp

#include <stdio.h>

class ElasticArray {
private:
    int size;
    double* data;
    
    bool isValidIndex(int index);
public:
    
    ElasticArray(int size = 10);
    ~ElasticArray();
    
    // resizable
    void resize(int size);
    
    // needed
    double get(int index);
    void set(int index, double value);
};

#endif /* ElasticArray_hpp */
