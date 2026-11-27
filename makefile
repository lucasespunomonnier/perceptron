perceptron: src/dataset.o src/main.o src/perceptron.o
	gcc src/dataset.o src/main.o src/perceptron.o -o perceptron -Wall -Wextra -g -lm

src/main.o: src/main.c include/dataset.h include/perceptron.h
	gcc -c src/main.c -o src/main.o -Iinclude -Wall -Wextra -g 

src/dataset.o: src/dataset.c include/dataset.h
	gcc -c src/dataset.c -o src/dataset.o -Iinclude -Wall -Wextra -g 

src/perceptron.o: src/perceptron.c include/perceptron.h
	gcc -c src/perceptron.c -o src/perceptron.o -Iinclude -Wall -Wextra -g

clean:
	rm -f src/*.o
	rm -f *.exe