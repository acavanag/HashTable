//
//  Hash.cpp
//  
//
//  Created by Andrew Cavanagh on 7/17/15.
//
//

#include "Hash.h"

static const int __hash_kDefaultTableSize = 10;

using namespace std;

Hash::Hash(int *size)
{
    if (size == nullptr) {
        hashTableSize = __hash_kDefaultTableSize;
    } else {
        hashTableSize = *size;
    }
    
    hashTable = new Item[hashTableSize];
    for (int i = 0; i < hashTableSize; i++) {
        hashTable[i].key = "";
        hashTable[i].value = "";
        hashTable[i].isSet = false;
        hashTable[i].next = NULL;
    }
}

string* Hash::valueForKey(string key)
{
    int index = Hash::hash(key);
    if (hashTable[index].isSet == false) {
        return nullptr;
    } else {
        Item *ptr = &hashTable[index];
        while (ptr->next != NULL && ptr->key != key) {
            ptr = ptr->next;
        }
        return &(ptr->value);
    }
}

void Hash::setValue(string key, string value)
{
    int index = Hash::hash(key);
    if (hashTable[index].isSet == false) {
        hashTable[index].isSet = true;
        hashTable[index].key = key;
        hashTable[index].value = value;
        hashTable[index].next = NULL;
    } else {
        Item *ptr = &hashTable[index];
        
        do {
            if (ptr->key == key) {
                ptr->value = value;
                return;
            }
            if (ptr->next == NULL) break;
            ptr = ptr->next;
        } while (true);
        
        Item *newItem = new Item;
        newItem->key = key;
        newItem->isSet = true;
        newItem->value = value;
        newItem->next = NULL;
        
        ptr->next = newItem;
    }
}

int Hash::hash(string key)
{
    int sum = 0;
    for (int i = 0; i < key.length(); i++) {
        sum = sum + key[i];
    }
    return sum % hashTableSize;
}

void Hash::printTable()
{
    for (int i = 0; i < hashTableSize; i++) {
        if (hashTable[i].isSet == true) {
            Item *ptr = &hashTable[i];
            
            int linkedIndex = 0;
            printItem(*ptr, i, linkedIndex);
            
            while (ptr->next != NULL) {
                linkedIndex++;
                ptr = ptr->next;
                printItem(*ptr, i, linkedIndex);
            }
        }
    }
}

void Hash::printItem(Item item, int index, int linkedIndex)
{
    cout << "--------------------" << endl;
    
    cout << "Set: " << item.isSet << endl;
    cout << "Key: " << item.key << endl;
    cout << "Value: " << item.value << endl;
    cout << "Table Index: " << index << endl;
    cout << "Linked Index: " << linkedIndex << endl;
    
    string end = (item.next == NULL) ? "Yes" : "No";
    cout << "Is End: " << end << endl;
    
    cout << "--------------------" << endl;
}
