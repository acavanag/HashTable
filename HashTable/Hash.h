//
//  Hash.h
//  
//
//  Created by Andrew Cavanagh on 7/17/15.
//
//

#include <iostream>
#include <string>

#ifndef ____Hash__
#define ____Hash__

using namespace std;

class Hash {
public:
    Hash(int *size);
    
    string* valueForKey(string key);
    void removeValue(string key);
    void setValue(string key, string value);
    void printTable();
    
private:
    
    struct Item {
        bool isSet;
        string key;
        string value;
        Item *next;
    };
    
    int hashTableSize;
    Item *hashTable;
    
    int hash(string key);
    void printItem(Item item, int index, int linkedIndex);
};

#endif /* defined(____Hash__) */
