compiler:
	mkdir -p generated
	mkdir -p build
	flex -o generated/scanner.cpp src/scanner.ll
	bison -d -o generated/parser.cpp src/parser.yy
	g++ -std=c++0x -c -o build/parser.o generated/parser.cpp -g
	g++ -std=c++0x -c -o build/scanner.o generated/scanner.cpp -g
	g++ -std=c++0x -c -o build/main.o src/main.cpp -g
	g++ -std=c++0x -o Micro build/scanner.o build/parser.o build/main.o -g
clean:
	rm -rf generated
	rm -rf build
	rm -f Micro
output:
	./Micro input/test1.micro output.out
	@cat output.out
	@echo
	./Micro input/test2.micro output.out
	@cat output.out
	@echo
	./Micro input/test3.micro output.out
	@cat output.out
	@echo
	./Micro input/test4.micro output.out
	@cat output.out
	@echo
	./Micro input/test5.micro output.out
	@cat output.out
	@echo
	./Micro input/test6.micro output.out
	@cat output.out
	@echo
	./Micro input/test7.micro output.out
	@cat output.out
	@echo
	./Micro input/test8.micro output.out
	@cat output.out
	@echo
	./Micro input/test9.micro output.out
	@cat output.out
	@echo
	./Micro input/test10.micro output.out
	@cat output.out
	@echo
	./Micro input/test11.micro output.out
	@cat output.out
	@echo
	./Micro input/test12.micro output.out
	@cat output.out
	@echo
	./Micro input/test13.micro output.out
	@cat output.out
	@echo
	./Micro input/test14.micro output.out
	@cat output.out
	@echo
	./Micro input/test15.micro output.out
	@cat output.out
	@echo
	./Micro input/test16.micro output.out
	@cat output.out
	@echo
	./Micro input/test17.micro output.out
	@cat output.out
	@echo
	./Micro input/test18.micro output.out
	@cat output.out
	@echo
	./Micro input/test19.micro output.out
	@cat output.out
	@echo
	./Micro input/test20.micro output.out
	@cat output.out
	@echo
	./Micro input/test21.micro output.out
	@cat output.out
	@echo

team:
	@echo "Team: Kims' Club"
	@echo
	@echo "Sang Hun Kim"
	@echo "dooly107"
	@echo
	@echo "Jeong Min (Jimmy) Kim"
	@echo "jeongjimmykim"
