extern int print_int(int X);
extern float print_float(float X);

int foo(int x) {
    while (x < 10)
        if (x < 5) {
            x = x + 2;
        } else {
            x = x + 1;
        }

    return x;
}