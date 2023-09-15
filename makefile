all:
	clang++ -o3 src/*.cpp  -std=c++17                           \
	-ldl -lsfml-graphics -lsfml-window -lsfml-system 			\
	-Isrc/*.hpp                                                 \
	-I/home/nour/Downloads/SFML-2.5.1/include/                                          \
	-L/home/nour/Downloads/SFML-2.5.1/build/lib/                \
	-o bin/a.out && bin/./a.out         
check:
	valgrind  ./bin/a.out                                                                         \
	--leak-check=full  -s    --leak-check=full --show-reachable=yes --show-leak-kinds=all         
