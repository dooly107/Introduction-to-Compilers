compiler:
	mkdir -p generated
	mkdir -p build
	flex  -o generated/scanner.cpp src/scanner.ll
	bison -d -o generated/parser.cpp src/parser.yy
	g++ -std=c++0x -c -o build/parser.o generated/parser.cpp -g
	g++ -std=c++0x -c -o build/scanner.o generated/scanner.cpp -g
	g++ -std=c++0x -c -o build/main.o src/main.cpp -g
	g++ -std=c++0x -o Micro build/scanner.o build/parser.o build/main.o -g
clean:
	rm -rf generated
	rm -rf build
	rm -f Micro

test1: 
	make clean
	make compiler
	./runme input/step7_test1.micro output.out

test2:
	make clean
	make compiler
	./runme input/step7_test2.micro output.out

test3:
	make clean
	make compiler
	./runme input/step7_test3.micro output.out

test4:
	make clean
	make compiler
	./runme input/step7_test4.micro output.out

test5:
	make clean
	make compiler
	./runme input/step7_test5.micro output.out

test6:
	make clean
	make compiler
	./runme input/step7_test6.micro output.out

test7:
	make clean
	make compiler
	./runme input/step7_test7.micro output.out

test8:
	make clean
	make compiler
	./runme input/step7_test8.micro output.out

test9:
	make clean
	make compiler
	./runme input/step7_test9.micro output.out

test10:
	make clean
	make compiler
	./runme input/step7_test10.micro output.out

test11:
	make clean
	make compiler
	./runme input/step7_test11.micro output.out

test12:
	make clean
	make compiler
	./runme input/step7_test12.micro output.out

test13:
	make clean
	make compiler
	./runme input/step7_test13.micro output.out

test14:
	make clean
	make compiler
	./runme input/step7_test14.micro output.out

test15:
	make clean
	make compiler
	./runme input/step7_test15.micro output.out

test16:
	make clean
	make compiler
	./runme input/step7_test16.micro output.out

test17:
	make clean
	make compiler
	./runme input/step7_test17.micro output.out

test18:
	make clean
	make compiler
	./runme input/step7_test18.micro output.out

test19:
	make clean
	make compiler
	./runme input/step7_test19.micro output.out

test20:
	make clean
	make compiler
	./runme input/step7_test20.micro output.out

test21:
	make clean
	make compiler
	./runme input/step7_test21.micro output.out
team:
	@echo "Team: Kims' Club"
	@echo
	@echo "Sang Hun Kim"
	@echo "dooly107"
	@echo
	@echo "Jeong Min (Jimmy) Kim"
	@echo "jeongjimmykim"
