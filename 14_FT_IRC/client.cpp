#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int		main(int argc, char* argv[]){
	int		client_sock;
	struct sockaddr_in	serv_addr;
	char	message[1024] = {0, };
	char	*end;

	client_sock = socket(PF_INET, SOCK_STREAM, 0);
	if (client_sock == -1){
		std::cout << "Socket Error\n";
		exit(1);
	}
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(std::strtod(argv[2], &end));
	if (connect(client_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1){
		std::cout << "Connect Error\n";
		exit(1);
	}
	if (read(client_sock, message, sizeof(message) - 1) == -1){
		std::cout << "Read Error\n";
		exit(1);
	}
	std::cout << "Message = " << message << std::endl;
	close(client_sock);
	return 0;
}
