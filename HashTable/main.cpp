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
    
    Hash hashObj = Hash(NULL);
    
    hashObj.setValue("Andrew", "Yolo");
    hashObj.setValue("Laura", "Swag");

    string *x = hashObj.valueForKey("Andrew");
    if (x != nullptr) {
        cout << "Value for key \"Andrew\": " << *x << endl;
    }
    
    hashObj.printTable();

    return 0;
}
