//
//  main.cpp
//  HashTable
//
//  Created by Andrew Cavanagh on 7/15/15.
//  Copyright (c) 2015 andrewjmc. All rights reserved.
//

#include "Hash.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    int size = 1;
    Hash hashObj = Hash(&size);
    
    hashObj.setValue("Andrew", "Yolo");
    hashObj.setValue("Laura", "Swag");
    hashObj.setValue("Katie", "woot");
    hashObj.setValue("Sarah", "lulz");

    string *x = hashObj.valueForKey("Andrew");
    if (x != nullptr) {
        cout << "Value for key \"Andrew\": " << *x << endl;
    }
    
    hashObj.removeValue("Andrew");
    
    hashObj.printTable();


    return 0;
}
