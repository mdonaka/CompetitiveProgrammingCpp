#!/bin/bash

function usage {
    cat <<EOF
$(basename ${0})
Usage:
  ./$(basename ${0}) [Options]
Options:
  -h       Show usage
  -c       Compile
  -r       Run
  -t       Random case test
  -i       Interactive test
EOF
}

function compile {
  g++-11 -std=c++2a -O2 -D DEBUG $1 $2 $3
  if [ $? != 0 ]; then
    echo "ERROR! compile main.cpp is failed"
    exit 1
  fi
}

function run {
  ./a.out < i
}

function interactive {
  compile interactive.cpp -o judge
  for i in `seq 1 100`
  do
    echo "-------- " $i "th run --------"
    (unbuffer oj t/r ./judge; echo $? > status_file) | tee i
    status=`cat status_file`
    rm -f status_file
    if [ $status != 0 ]; then
      exit $status
    fi
  done
  rm judge
}

if [ $# = 0 ]; then
  run
  exit 0
fi

while getopts hcrti OPT; do
  case $OPT in
  h)
    usage
    ;;
  c)
    compile main.cpp
    ;;
  r)
    run
    ;;
  t)
    compile main.cpp -D TEST
    run | tee i
    ;;
  i)
    interactive
    ;;
  esac
done

