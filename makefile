all:
	g++ -o3 src/*.cpp  -std=c++17                               \
	-ldl -lsfml-graphics -lsfml-window -lsfml-system 			\
	-Isrc/*.hpp                                                 \
	-Ilib/SFML/include                                          \
	-Llib/SFML/lib                                              \
	-o bin/a.out && bin/./a.out         
check:
	valgrind  ./bin/a.out                                                                         \
	--leak-check=full  -s    --leak-check=full --show-reachable=yes --show-leak-kinds=all         \