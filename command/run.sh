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
    oj t/r ./judge 2> judge_log
    if [ $? != 0 ]; then
      cat judge_log
      cat judge_log > i
      exit 1
    fi
  done
  rm judge_log judge
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
    run > i 2>&1 && cat i
    ;;
  i)
    interactive
    ;;
  esac
done

