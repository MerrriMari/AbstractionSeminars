//
//  Sem2_1.cpp
//  Blank Project
//
//  Created by Mariam Samkharadze on 29.04.24.
//


#include <stdio.h>
#include "console.h"
#include "simpio.h"
#include "grid.h"
#include "set.h"
#include "vector.h"
#include "tokenscanner.h"

struct itemS {
    int w;
    int c;
    itemS() {}
    itemS(int w, int c) {
        this -> w = w;
        this -> c = c;
    }
};

int maxValueFromItems(Vector<itemS>& items, int maxWeight, Vector<itemS>& chosenItems, int index) {
    if(items.size() == index) {
        chosenItems.clear();
        return 0;
    }
    
    itemS currIteam = items.get(index);
    
    // chosing this item
    Vector<itemS> withCurrItemChosenItems;
    int withCurrCost = 0;
    if(maxWeight >= currIteam.w) {
        withCurrCost = maxValueFromItems(items, maxWeight - currIteam.w, withCurrItemChosenItems, index + 1);
    }
    
    // not chosing this item
    Vector<itemS> withoutCurrItemChosenItems;
    int withoutCurrCost = maxValueFromItems(items, maxWeight, withoutCurrItemChosenItems, index + 1);
    
    withCurrCost += currIteam.c;
    withCurrItemChosenItems.add(currIteam);
    
    if(withCurrCost > withoutCurrCost && maxWeight >= currIteam.w) {
        chosenItems = withCurrItemChosenItems;
        return withCurrCost;
    } else {
        chosenItems = withoutCurrItemChosenItems;
        return withoutCurrCost;
    }
}

int main() {
    Vector<itemS> items;
    items.add(itemS(2, 2));
    items.add(itemS(3, 1));
    items.add(itemS(5, 6));
    items.add(itemS(1, 2));
    Vector<itemS> chosenItems;
    cout << maxValueFromItems(items, 5, chosenItems, 0) << endl;
    for(itemS iteam : chosenItems) {
        cout << iteam.w << " " << iteam.c << endl;
    }
//    cout << chosenItems.toString() << endl;
    return 0;
}


