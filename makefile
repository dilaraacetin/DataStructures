all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/AVL_Agaci.cpp -o ./lib/AVL_Agaci.o
	g++ -c -I "./include" ./src/AVL_Dugum.cpp -o ./lib/AVL_Dugum.o
	g++ -c -I "./include" ./src/Yigit.cpp -o ./lib/Yigit.o
	
bagla:
	g++ ./lib/Yigit.o ./lib/AVL_Agaci.o ./lib/AVL_Dugum.o ./lib/main.o -o ./bin/program
	
calistir:
	./bin/program
