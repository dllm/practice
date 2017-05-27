#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]) {
	struct sockaddr_in serverAddr;;
	char c;
	unsigned short portnum;
	char *hostName;
	struct hostent *hptr;
	int sock;

	/* Check for the correct number of arguments */ 
	if (argc < 2) {
		printf ("usage: %s <hostname/IP Addr> <port number>\n", argv [0]);
		printf("Example:\n");
		printf ("%s myhost 2345 -- would connect to host \"myhost\" on port 2345 0\n", argv [0]);
		printf ("%s 192.168.100.1 2345 -- would connect to 192.168.100.1 on port 2345 0\n", argv [0]);
		exit (1); 
	}

	/* Decode the arguments first */ hostName = argv[1];
	portnum = atoi(argv[2]);
	/* let's resolve the hostname/IP addr */
	if ( (hptr = gethostbyname(hostName)) == NULL) 
	{
		fprintf(stderr, "gethostbyname error for host %s!\n", hostName);
		exit(1); 
	}
	/* Zero out the sock_addr structure */
	memset (&serverAddr, 0x0, sizeof (serverAddr));
	/* Open the socket */
	if ((sock = socket (AF_INET, SOCK_STREAM, 0)) < 0){
		fprintf (stderr, "socket failed, \n");
		exit (1); 
	}
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(portnum);
	serverAddr.sin_addr = * (struct in_addr *)
		*hptr->h_addr_list;
	printf ("Server's address is %x:\n", htonl(serverAddr.sin_addr.s_addr));
	if (connect (sock, (struct sockaddr *) &serverAddr,
				sizeof (serverAddr)) != 0) {
		printf ("Connect failed:\n"); shutdown(sock, 2);
		close (sock);
		exit(1);
	}
	printf ("Connected...\n Press <ESC> to exit \n\n");
	/* repeatedly read characters from stdin and send to server */
	while (1) {
		c = getchar();
		if (c != 0x1b) { /* ESC */
			send(sock, &c, 1, 0);
		} else { 
			break;
		} 
	}
	/* close the socket */
	shutdown(sock, 2);
	close (sock);
	printf ("\n...goodbye\n");
}
