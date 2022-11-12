extern int print_int(int X);
int a;

int foo() {
    a = a + 1;
    return a;
}

int scope() {
    a = 5;
    return foo();
}