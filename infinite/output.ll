; ModuleID = 'mini-c'
source_filename = "mini-c"

declare i32 @print_int(i32)

declare float @print_float(float)

define void @infinite() {
entry:
  br label %before

before:                                           ; preds = %loop, %entry
  br i1 true, label %loop, label %end

loop:                                             ; preds = %before
  %calltmp = call i32 @print_int(i32 1)
  br label %before
  br label %end

end:                                              ; preds = %loop, %before
  ret void
}
