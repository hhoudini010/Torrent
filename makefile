CC = g++
CFLAGS = -Wall -std=c++14
DEPS = lib.h
OBJ = lib.o remo.o sharec.o create_mtor_fil.o client.o
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< -lcrypto

client: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lcrypto

