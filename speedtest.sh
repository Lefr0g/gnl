#!/bin/sh

make -C libft/ fclean
make -C libft/
gcc -Wall -Wextra -Werror -I libft/includes/ -c get_next_line.c
gcc -Wall -Wextra -Werror -I libft/includes/ -c main_speedtest.c
gcc -o speedtest_gnl get_next_line.o main_speedtest.o -L libft/ -lft
time ./speedtest_gnl 27.txt
