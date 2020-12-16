#include "recursive.h"


list_t selectMod(list_t lElements, int mod);
// REQUIRES: mod is a positive integer
// EFFECTS: returns all the elements of lElements (in the same order)
//          whose indices i are such that i modulo mod == 0

list_t selectMod_helper(list_t lElements, int mod, int index) {
    if (list_isEmpty(lElements))
        return list_make();
    else
        if (index % mod == 0)
            return list_make(list_first(lElements), selectMod_helper(list_rest(lElements), mod, ++index));
        else
            return selectMod_helper(list_rest(lElements), mod, ++index);
}

list_t selectMod(list_t lElements, int mod) {
    return selectMod_helper(lElements, mod, 0);
}
