// Test written by Joey
int returns(int x) {
    while (x == 1) {
        return 0;
        x = x + 1;
    }

    if (x > 1) {
        return 1;
        x = x + 1;

    } else {
        return 2;
        x = x + 1;
    }
    return 3;
    x = x + 1;
}