#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
/*
struct	in_addr{
	unsigned long	s_addr;
};

struct	sockaddr{
	sa_family_t		sa_family;
	char			sa_data[14];
};

struct	sockaddr_in{
	sa_family_t			sin_family;
	unsigned short int	sin_port;
	struct in_addr		sin_addr;
	unsigned char  __pad[__SOCK_SIZE__ - sizeof(short int) -
      sizeof(unsigned short int) - sizeof(struct in_addr)];
};
*/
/*
void		create_server(){
	int		s;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (!proto)
		std::cout << "Error\n";
	s = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(80);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(s, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
		std::cout << "Error\n";
	listen(s, 42);
}
*/
int			main(){
	int			s;
	sockaddr_in	sin;
	protoent	*proto;

	proto = getprotobyname("tcp");
	if (!proto)
		std::cout << "Error\n";
	s = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	if (s == -1){
		std::cout << "Socket Error" << std::endl;
		exit(0);
	}
	sin.sin_family = AF_INET;
	sin.sin_port = htons(80);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(s, (const sockaddr *)&sin, sizeof(sin))){
		std::cout << "Bind Error" << std::endl;
		exit(0);
	}
	if (listen(s, 42) != 0){
		std::cout << "listen Error" << std::endl;
		exit(0);
	}
	std::cout << "Listened\n";
	int		ret;
	while (true){
		ret = select(42, NULL, NULL, NULL, 0);
	}
	return 0;
}
