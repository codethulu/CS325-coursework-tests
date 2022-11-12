extern int print_int(int X);
int scope() {
    int a;
    int b;
    a = 4;
    {
        int a;
        a = 5;
        b = a;
        print_int(b);
    }
    b = a + b;
    print_int(b);
    return b;
}