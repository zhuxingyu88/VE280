int main() {
    // simple input 1
    list_t a = list_make(1, list_make(2, list_make(3, list_make(4, list_make()))));
    list_t b = list_make(2, list_make(3, list_make()));
    assert(longestCommon(a, b) == 2);

    // simple input 2
    a = list_make(1, list_make(2, list_make(3, list_make(4, list_make()))));
    b = list_make(-1, list_make(1, list_make(2, list_make())));
    assert(longestCommon(a, b) == 2);

    // boundary case 1
    a = list_make();
    b = list_make(2, list_make(3, list_make(4, list_make())));
    assert(longestCommon(a, b) == 0);

    // boundary case 2
    a = list_make();
    b = list_make();
    assert(longestCommon(a, b) == 0);

    // boundary case 3
    a = list_make(1, list_make(1, list_make(1, list_make(1, list_make()))));
    b = list_make(1, list_make(1, list_make(1, list_make(1, list_make()))));
    assert(longestCommon(a, b) == 4);

    // boundary case 4
    a = list_make(1, list_make(1, list_make(1, list_make())));
    b = list_make(0, list_make(0, list_make(0, list_make())));
    assert(longestCommon(a, b) == 0);

    // boundary case 5
    a = list_make();
    b = list_make(1, list_make(1, list_make(1, list_make(1, list_make()))));
    assert(longestCommon(a, b) == 0);

    // non-sense case 1
    try {
        a = list_make(1, list_make(2, list_make()));
        b = list_make(1, list_make(-1, list_make()));
        assert(longestCommon(a, b) == 0);
    } catch (string& e) {
        cout << e << endl;
    }

    // non-sense case 2
    try {
        a = list_make(1, list_make(-2, list_make()));
        b = list_make(1, list_make(-1, list_make()));
        assert(longestCommon(a, b) == 0);
    } catch (string& e) {
        cout << e << endl;
    }

    // non-sense case 3
    try {
        a = list_make(1, list_make(-2, list_make()));
        b = list_make();
        assert(longestCommon(a, b) == 0);
    } catch (string& e) {
        cout << e << endl;
    }

    return 0;
}
