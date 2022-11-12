; ModuleID = 'mini-c'
source_filename = "mini-c"

define i32 @foo(i32 %X) {
entry:
  %X1 = alloca i32, align 4
  store i32 %X, ptr %X1, align 4
  %X2 = load i32, ptr %X1, align 4
  ret i32 %X2
}

define i32 @implicit() {
entry:
  %calltmp = call i32 @foo(i32 3)
  ret i32 %calltmp
}
