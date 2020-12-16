//
// Created by 朱星宇 on 2020/7/22.
//
#include <iostream>
#include <sstream>
#include "dlist.h"

using namespace std;

class unknown_instruction {
    // OVERVIEW: an exception class
};

class not_enough_operands {
    // OVERVIEW: an exception class
};

class too_many_operands {
    // OVERVIEW: an exception class
};

class address_out_of_bound {
    // OVERVIEW: an exception class
};

class LRUCache{
private:
    int mem_size; // size of memory
    int *memory;
    struct block{
        int address; // its address in memory
        int data;
    };
    Dlist<block> cache;
    int cur_cache_size; // current length of `cache`
    int max_cache_size; // maximum length of `cache`

    static bool compare(const block *a, const block *b);
    // EFFECTS: returns true if two blocks have the same address

public:
    LRUCache(int cache_size, int memory_size); // constructor
    // Initialize `cur_cache_size`, `max_cache_size`, `memory`
    // Initialize all elements in `memory` to 0

    ~LRUCache(); // destructor

    int read(int address);
    // EFFECTS: returns data corresponding to address,
    // 0 <= address < mem_size;
    // if address is out of bound, throws an exception


    void write(int address, int data);
    // EFFECTS: writes data to address, 0 <= address < mem_size
    // if address is out of bound, throws an exception

    void printCache();
    // EFFECTS: prints the cache in given format

    void printMem();
    // EFFECTS: prints the memory in given format
};

// returns true if two blocks have the same address
bool LRUCache::compare(const LRUCache::block *a, const LRUCache::block *b) {
    return a->address == b->address;
}

// constructor
LRUCache::LRUCache(int cache_size, int memory_size): mem_size(memory_size), memory(new int[memory_size]),
cache(Dlist<block>()), cur_cache_size(0), max_cache_size(cache_size) {
    for (int i = 0; i < memory_size; ++i) {
        memory[i] = 0;
    }
}

// destructor
LRUCache::~LRUCache() {
    delete[] memory;
}

// returns data corresponding to address
int LRUCache::read(int address) {
    if (address < 0 || address >= mem_size) {
        address_out_of_bound e;
        throw e;
    }
    block temBlock{address, 0};
    block* cacheBlock = cache.remove(compare, &temBlock);
    if (cacheBlock) {
        cache.insertFront(cacheBlock);
        return cacheBlock->data;
    } else {
        if (cur_cache_size == max_cache_size) {
            cacheBlock = cache.removeBack();
            memory[cacheBlock->address] = cacheBlock->data;
            delete cacheBlock;
        } else
            ++cur_cache_size;
        cacheBlock = new block{address, memory[address]};
        cache.insertFront(cacheBlock);
        return cacheBlock->data;
    }
}

// writes data to address
void LRUCache::write(int address, int data) {
    if (address < 0 || address >= mem_size) {
        address_out_of_bound e;
        throw e;
    }
    block temBlock{address, data};
    block* cacheBlock = cache.remove(compare, &temBlock);
    if (cacheBlock) {
        cacheBlock->data = data;
        cache.insertFront(cacheBlock);
    } else {
        if (cur_cache_size == max_cache_size) {
            cacheBlock = cache.removeBack();
            memory[cacheBlock->address] = cacheBlock->data;
            delete cacheBlock;
        } else
            ++cur_cache_size;
        cacheBlock = new block{address, data};
        cache.insertFront(cacheBlock);
    }
}

// prints the cache
void LRUCache::printCache() {
    block* temp;
    for (int i = 0; i < cur_cache_size; ++i) {
        temp = cache.removeFront();
        cout << temp->address << ' ' << temp->data << endl;
        cache.insertBack(temp);
    }
}

// prints the memory
void LRUCache::printMem() {
    for (int i = 0; i < mem_size; ++i) {
        cout << memory[i] << ' ';
    }
    cout << endl;
}

// MODIFIES: cin
// EFFECTS: initialize the LRUCache
LRUCache initialize();

// MODIFIES: cin lruCache
// EFFECTS: handle the requests
void process(LRUCache& lruCache);


int main() {
    LRUCache lruCache = initialize();
    process(lruCache);
    return 0;
}

// initialize the LRUCache
LRUCache initialize() {
    string line;
    getline(cin, line);
    istringstream istream;
    istream.str(line);
    int cache_size, mem_size;
    istream >> cache_size;
    istream >> mem_size;
    istream.clear();
    LRUCache result(cache_size, mem_size);
    return result;
}

// handle the requests
void process(LRUCache& lruCache) {
    string line, request;
    istringstream istream;
    int operand1, operand2, operand3;
    while (true) {
        getline(cin, line);
        istream.str(line);
        istream.clear();
        istream >> request;
        try {
            if (request == "READ") {
                if (!(istream >> operand1)) {
                    not_enough_operands e;
                    throw e;
                }
                if (istream >> operand3) {
                    too_many_operands e;
                    throw e;
                }
                cout << lruCache.read(operand1) << endl;
            } else if (request == "WRITE") {
                if (!(istream >> operand1)) {
                    not_enough_operands e;
                    throw e;
                }
                if (!(istream >> operand2)) {
                    not_enough_operands e;
                    throw e;
                }
                if (istream >> operand3) {
                    too_many_operands e;
                    throw e;
                }
                lruCache.write(operand1, operand2);
            } else if (request == "PRINTCACHE") {
                if (istream >> operand3) {
                    too_many_operands e;
                    throw e;
                }
                lruCache.printCache();
            } else if (request == "PRINTMEM") {
                if (istream >> operand3) {
                    too_many_operands e;
                    throw e;
                }
                lruCache.printMem();
            } else if (request == "EXIT") {
                if (istream >> operand3) {
                    too_many_operands e;
                    throw e;
                }
                break;
            } else {
                unknown_instruction e;
                throw e;
            }
        } catch (unknown_instruction) {
            cout << "ERROR: Unknown instruction" << endl;
            continue;
        } catch (not_enough_operands) {
            cout << "ERROR: Not enough operands" << endl;
            continue;
        } catch (too_many_operands) {
            cout << "ERROR: Too many operands" << endl;
            continue;
        } catch (address_out_of_bound) {
            cout << "ERROR: Address out of bound" << endl;
            continue;
        }
    }
}