SRC=./problems/

# Compile last edited file in ${SRC} directory
default:
	${CC} -Wall -Wextra $(shell find ${SRC} -type f -printf '%T@ %p\n' | sort -n | tail -1 | cut -f2 -d' ')
