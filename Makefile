CC=g++
CFLAGS=-lcrypto
DEPS = CBC_enc.hpp
OBJ = CBC_enc.o main.o 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

CPA: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
	
	
clean:
	rm -f *.o *~ core $(INCDIR)/*~ 
