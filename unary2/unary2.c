extern int print_int(int X);
extern float print_float(float X);

int unary2() {
    float f;
    int i;
    int i2;
    bool b;
    bool b2;
    int z;
    i2 = 0;
    f = 0.0;
    i = 1;
    b = -!f + i;
    b2 = true || b;
    i2 = b2;
    return i2;
}