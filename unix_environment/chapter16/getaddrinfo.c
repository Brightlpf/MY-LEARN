#include <apue.h>
#if defined (SOLARIS)
#include <neinet/in.h>
#endif
#include <netdb.h>
#include <arpa/inet.h>
#if defined (BSD)
#include <sys/socket.h>
#include <netinet/in.h>
#endif

#define PRINTF printf
/*
struct addrinfo
{ 
int ai_flags; 
int ai_family; //AF_INET,AF_INET6,UNIX etc
int ai_socktype; //STREAM,DATAGRAM,RAW
int ai_protocol; //IPPROTO_IP, IPPROTO_IPV4, IPPROTO_IPV6 etc
size_t ai_addrlen;//length of ai_addr
char* ai_canonname; //full hostname 
struct sockaddr* ai_addr; //addr of host
struct addrinfo* ai_next;
}

value of ai_falgs:
AI_PASSIVE: Socket address is intended for `bind'.
AI_CANONNAME:Request for canonical name.
AI_NUMERICHOST: Don't use name resolution.
AI_V4MAPPED: IPv4 mapped addresses are acceptable. 
AI_ALL: Return IPv4 mapped and IPv6 addresses. 
AI_ADDRCONFIG:Use configuration of this host to choose

int getaddrinfo( const char *hostname, const char *service, const struct addrinfo *hints,
struct addrinfo **result );
const char *inet_ntop(int af, const void *src, char *dst, socklen_t cnt);
uint16_t ntohs(uint16_t netshort);
*/
void print_family(struct addrinfo *aip);
void print_type(struct addrinfo *aip);
void print_protocol(struct addrinfo *aip);
void print_flags(struct addrinfo *aip);

int main(int argc, char *argv[])
{
	struct addrinfo * ailist;
	struct addrinfo   hint;
	struct addrinfo * aip;
	char abuf[INET_ADDRSTRLEN];
	struct sockaddr_in * sinp;
	int err = 0;
	const char * addr;
	
	if(argc != 3)
	{
		printf("usage: %s nodename service\n", argv[0]);
		return 1;
	}
	hint.ai_flags = AI_CANONNAME;
	hint.ai_family = 0;
	hint.ai_socktype = 0;
	hint.ai_protocol = 0;
	hint.ai_addrlen = 0;
	hint.ai_canonname = NULL;
	hint.ai_addr = NULL;
	hint.ai_next = NULL;
	
	if((err = getaddrinfo(argv[0], argv[1], &hint, &ailist)) != 0)
	{
		err_quit("getaddrinfo error: %s", gai_strerror(err));
	}
	
	for(aip = ailist; aip != NULL; aip = aip->ai_next)
	{
		print_flags(aip);
		print_family(aip);
		print_type(aip);
		print_protocol(aip);
		printf("\n\thost: %s\n", aip->ai_canonname? aip->ai_canonname: "-");
		
		if(aip->ai_family == AF_INET)
		{
			sinp = (struct sockaddr_in *)aip->ai_addr;
			addr = inet_ntop(AF_INET, &sinp->sin_addr, abuf, INET_ADDRSTRLEN);
			printf("address %s\n", addr);
			printf("port %d\n", ntohs(sinp->sin_port));
		}
		printf("\n");
	}
	exit(0);
}


void print_family(struct addrinfo *aip)
{
	if(aip == NULL)
	{
		return ;
	}
	printf("family: ");
	switch(aip->ai_family)
	{
		case AF_INET:
			printf("inet");
			break;
		case AF_INET6:
			printf("inet6");
			break;
		case AF_UNIX:
			printf("unix");
			break;
		case AF_UNSPEC:
			printf("unspecified");
			break;
		default:
			printf("unknown");
	}
}

void print_type(struct addrinfo *aip)
{
	if(aip == NULL)
	{
		return ;
	}
	printf("socket type: ");
	switch(aip->ai_socktype)
	{
		case SOCK_STREAM:
			printf("stream");
			break;
		case SOCK_DGRAM:
			printf("datagram");
			break;
		case SOCK_SEQPACKET:
			printf("seqpacket");
			break;
		case SOCK_RAW:
			printf("raw");
			break;
		default:
			printf("unknown %d", aip->ai_socktype);
	}
}

void print_protocol(struct addrinfo *aip)
{
	if(aip == NULL)
	{
		return ;
	}
	printf("protocol: ");
	switch(aip->ai_protocol)
	{
		case 0:
			printf("default");
			break;
		case IPPROTO_TCP:
			printf("tcp");
			break;
		case IPPROTO_UDP:
			printf("udp");
			break;
		case IPPROTO_RAW:
			printf("raw");
			break;
		default:
			printf("unknown %d", aip->ai_protocol);
	}
	
}
void print_flags(struct addrinfo *aip)
{
	if(aip == NULL)
	{
		return ;
	}
	printf("flag: ");
	
	if(aip->ai_flags == 0)
	{
		printf("0");
	}
	else
	{
		if(aip->ai_flags & AI_PASSIVE)
			PRINTF(" passive");
		if(aip->ai_flags & AI_CANONNAME)
			PRINTF(" canon");
		if(aip->ai_flags & AI_NUMERICHOST)
			PRINTF(" numhost");
		if(aip->ai_flags & AI_NUMERICSERV)
			PRINTF(" numserv");
		if(aip->ai_flags & AI_V4MAPPED)
			PRINTF(" v4mapped");
		if(aip->ai_flags & AI_ALL)
			PRINTF(" all");
	}
}
