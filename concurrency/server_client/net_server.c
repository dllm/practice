#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/un.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

//#define SOCKET_PATHNAME  "/Users/bikwong/Documents/tmp/lab10"
#define BUFSIZE          200

void consumer()
{
	struct sockaddr_in clientAddr;
	struct sockaddr_in serverAddr;
	int len;
	int size;
	char buf[BUFSIZE];
	unsigned short portnum = 2345;
	int sock, snew;
	int client_len;
	char c;
	printf("consumer connecting to producer\n");
//	unlink (SOCKET_PATHNAME);

	memset (&serverAddr, 0x0, sizeof (serverAddr));
	memset (&clientAddr, 0x0, sizeof (clientAddr));

	if ((sock = socket (AF_INET, SOCK_STREAM, 0)) < 0) {
		fprintf (stderr, "socket failed, errno \n");
		exit (1); 
	}

	serverAddr.sin_family = AF_INET; 
	serverAddr.sin_port = htons(portnum);
	printf ("\nBinding server port %d\n", portnum);

	if (bind (sock, (struct sockaddr *)&serverAddr, sizeof (serverAddr)) != 0 ) {
		fprintf (stderr, "bind failed, errno \n"); 
		close (sock);
		exit (1); 
	}

	printf ("Listening for connect...\n");
	if (listen (sock, 2) != 0) {
		printf ("listen failed\n"); close (sock);
		exit (1);
	}
	/* The client has connected. Accept, and receive chars */
	printf ("Accepting client connection...\n");
	client_len = sizeof (clientAddr);
	snew = accept (sock, (struct sockaddr *)&clientAddr, &client_len);
	if (snew < 0) {
		printf ("accept failed\n"); 
		close (sock);
		exit (1);
	}

	/* receive characters from client and put on stdout */
	while (1) {
		if (recv (snew, &c, 1, 0) == 0) {
			/* client has disappeared */
			break; }
		putchar (c);
	}
	/* close the socket from the Linux side */
	shutdown(sock, 2);
	shutdown(snew, 2);
	close (sock);
	close (snew);
	printf ("\n...goodbye\n");

	printf("consumer received message: %s\n", &buf[0]);
}

int main()
{
	/* parent process proceeds here */
	consumer();
	exit(0);
}
