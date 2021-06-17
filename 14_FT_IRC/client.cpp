#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int		main(int argc, char* argv[]){
	int		client_sock;
	struct sockaddr_in	serv_addr;
	char	message[1024] = "hello\n";
	char	*end;

	client_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (client_sock == -1){
		std::cout << "Socket Error\n";
		exit(1);
	}
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(80);
	if (connect(client_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1){
		std::cout << "Connect Error\n";
		exit(1);
	}
	std::cout << "Connected\n";
	while (1){
		fgets(message, 1024, stdin);
		message[strlen(message) - 1] = 0;
		if (write(client_sock, message, sizeof(message)) == -1){
			std::cout << "Write Error\n";
			close(client_sock);
			exit(1);
		}
		if (strncmp(message, "quit", 4) == 0){
			close(client_sock);
			exit(1);
		}
		std::cout << "Message = " << message << std::endl;
		while (1){
			if (read(client_sock, message, 1024) == -1){
				std::cout << "Read Error\n";
				exit(1);
			}
			if (strncmp(message, "end", 3) == 0)
				break ;
		}
		memset(message, 0, 1024);
	}
	close(client_sock);
	return 0;
}
