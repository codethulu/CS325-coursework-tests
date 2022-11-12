int mutable_var;

int mutating_function(void) {
    mutable_var = mutable_var + 1;
    return 1;
}

// If control == 1 then mutating_function should be run and mutable_var = 1
// If control != 1 then mutating_function should not be run and mutable_var = 0
int lazyeval_and(int control) {
    mutable_var = 0;
    if (control == 1 && mutating_function()) {
        return mutable_var;
    } else {
        return mutable_var;
    }
}

// If control == 1 then mutating_function should not be run and mutable_var = 0
// If control != 1 then mutating_function should be run and mutable_var = 1
int lazyeval_or(int control) {
    mutable_var = 0;
    if (control == 1 || mutating_function()) {
        return mutable_var;
    } else {
        return mutable_var;
    }
}