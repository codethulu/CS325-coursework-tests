#!/bin/bash
set -e
#export LLVM_INSTALL_PATH=/home/gihan/LLVM/install-10.0.1
#export LLVM_INSTALL_PATH=/modules/cs325/llvm-8/
#export LLVM_INSTALL_PATH=/modules/cs325/llvm-10.0.1
#export LLVM_INSTALL_PATH=/modules/cs325/llvm-12.0.1
#export LLVM_INSTALL_PATH=/tmp/LLVM/llvm-14.0.6
export LLVM_INSTALL_PATH=/modules/cs325/llvm-15.0.0

export PATH=$LLVM_INSTALL_PATH/bin:$PATH
export LD_LIBRARY_PATH=$LLVM_INSTALL_PATH/lib:$LD_LIBRARY_PATH
CLANG=$LLVM_INSTALL_PATH/bin/clang++

module load GCC/9.2.0

DIR="$(pwd)"

### Build mccomp compiler
echo "Cleanup *****"
rm -rf ./mccomp

echo "Compile *****"

make clean
make mccomp

COMP=$DIR/mccomp
echo $COMP

function validate {
  $1 > perf_out
  echo
  echo $1
  grep "Result" perf_out;grep "PASSED" perf_out
  rc=$?; if [[ $rc != 0 ]]; then echo "TEST FAILED *****";exit $rc; fi;rm perf_out
}

echo "Test *****"

cd hardertests/implicit/
pwd
rm -rf output.ll imp
"$COMP" ./implicit.c
$CLANG driver.cpp output.ll  -o imp
validate "./imp"

cd ../scope/
pwd
rm -rf output.ll scope
"$COMP" ./scope.c
$CLANG driver.cpp output.ll  -o scope
validate "./scope"

cd ../associativity/
pwd
rm -rf output.ll assoc
"$COMP" ./associativity.c
$CLANG driver.cpp output.ll  -o assoc
validate "./assoc"

cd ../global/
pwd
rm -rf output.ll global
"$COMP" ./global.c
$CLANG driver.cpp output.ll  -o global
validate "./global"

cd ../returns/
pwd
rm -rf output.ll returns
"$COMP" ./returns.c
$CLANG driver.cpp output.ll  -o returns
validate "./returns"

cd ../unary2/
pwd
rm -rf output.ll unary2
"$COMP" ./unary2.c
$CLANG driver.cpp output.ll  -o unary2
validate "./unary2"

cd ../while/
pwd
rm -rf output.ll while
"$COMP" ./while.c
$CLANG driver.cpp output.ll  -o while
validate "./while"

cd ../assign/
pwd
rm -rf output.ll assign
"$COMP" ./assign.c
$CLANG driver.cpp output.ll  -o assign
validate "./assign"

cd ../lazyeval/
pwd
rm -rf output.ll lazyeval
"$COMP" ./lazyeval.c
$CLANG driver.cpp output.ll -o lazyeval
validate "./lazyeval"

echo "***** ALL (HARDER) TESTS PASSED *****"
