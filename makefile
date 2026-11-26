perceptron: src/dataset.o src/main.o src/perceptron.o
	gcc src/dataset.o src/main.o src/perceptron.o -o perceptron -Wall -Wextra -g 

main.o: src/main.c include/dataset.h include/perceptron.h
	gcc -c src/main.c -o src/main.o -Wall -Wextra -g 

dataset.o: src/dataset.c include/dataset.h
	gcc -c src/dataset.c -o src/dataset.o -Wall -Wextra -g 

perceptron.o: src/perceptron.c include/perceptron.h
	gcc -c src/perceptron.c -o src/perceptron.o -Wall -Wextra -g

clean:
	rm -f src/*.o
	rm -f *.exe