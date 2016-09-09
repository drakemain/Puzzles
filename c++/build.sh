#!/usr/bin/env sh
clang++ -std=c++11 -Wall -Wextra -Werror -g ./src/linked-list.cc -o out/linked-list.bin
clang++ -std=c++11 -Wall -Wextra -Werror -g ./src/binary-tree.cc -o out/binary-tree.bin
clang++ -std=c++11 -Wall -Wextra -Werror -g ./src/vector.cc -o out/vector.bin