compile: pipe_networking.c pipe_networking.h client.c server.c
	gcc client.c pipe_networking.c -o client; gcc server.c pipe_networking.c -o server;

clean:
	rm server; rm client; rm *~