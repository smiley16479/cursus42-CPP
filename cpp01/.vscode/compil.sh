#!/bin/bash

# premier arg		$1
# tous les arg :	$@

flag="-Werror -Wall -Wextra"
leaks="-fsanitize=address -g3"
g++ $@ $flag $leaks
if [ $? = 0 ]
then
	echo "$1 compilé sous a.out 🔥 nous lançons l'éxécutable : "
	./a.out
else
	echo le compilation a échouée 🐵
fi