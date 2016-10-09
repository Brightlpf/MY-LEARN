/*
#include <arpa/inet.h>

uint32_t htonl(uint32_t hostint32);
uint16_t htons(uint16_t hostint16);
uint32_t ntohl(uint32_t netint32);
uint16_t ntohs(uint16_t netint16);

linux通用地址结构(其它套接字地址需要转换为这个地址，以便套接字函数使用)

struct sockaddr{
	sa_family_t sa_family;
	char sa_data[14];
};


因特网地址（AF_INET 域）
#include <netinet/in.h>

struct in_addr{
	in_addr_t		s_addr;  //ipv4 address
};

struct sockaddr_in{
	sa_family_t 	sin_family;
	in_port_t		sin_port;
	struct in_addr 	sin_addr;
};



因特网地址格式与字符串的转换

#include <arpa/inet.h>
const char * inet_ntop(int domain, const void *restrict addr, 
						char * restrict str, socklen_t size);
						
int inet_pton(int domain, const char * restrict str, void * restrict addr);
domain 可取 AF_INET, AF_INET6
size 指定保存文本字符串的缓冲区（str）大小， INET_ADDRSTRLEN, INET6_ADDRSTRLEN
*/










