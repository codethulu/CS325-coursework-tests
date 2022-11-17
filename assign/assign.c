// Test written by Toby
extern int print_int(int X);
extern float print_float(float X);

int z;

int assign() {
    int x;
    int y;
    x = y = 2;
    z = y = 3;

    return x + y + z;
}