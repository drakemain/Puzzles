#run this from the puzzles root

#!/bin/bash

ROOT=$PWD

echo -e "\e[7mRunning C++ puzzles.\e[0m"
cd /"$ROOT"/c++/
./build.sh
cd build/out/
for bin in *; do
  if [ -f "$bin" ] && [ -x "$bin" ]; then
    ./"$bin"
  fi
done

echo -e "\e[7mRunning JavaScript puzzles.\e[0m"
cd /"$ROOT"/javascript/
npm test

echo -e "\e[7mRunning Rust puzzles.\e[0m"
cd /"$ROOT"/rust/
cargo test
