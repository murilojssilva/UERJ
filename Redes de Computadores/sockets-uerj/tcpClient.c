#define closesocket close
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <locale.h>
#include <netdb.h>
#include <stdlib.h>

#include <stdio.h>
#include <string.h>

#include <limits.h>
#include <wchar.h>

#if (WCHAR_MAX==65535) && WCHAR_MIN==0
typedef wchar_t char_UTF16LE;
#elif USHRT_MAX==65535
typedef unsigned short char_UTF16LE;
#elif UINT_MAX==65535
typedef unsigned char_UTF16LE;
#else
#    error "Cannot find 16-bit type"
#endif

#define PROTOPORT       9925            

extern  int             errno;
char    localhost[] =   "localhost";    

int main(int argc, char * argv[])
{
        struct message {int code; char str[132];} msg;
        struct  hostent  *ptrh;  
        struct  protoent *ptrp;  
        struct  sockaddr_in sad; 
        int     sd;              
        int     port;            
        char    *host;           
        int     n;               
        char    buf[1000];       
        char    *text;           
#ifdef WIN32
        WSADATA wsaData;
        WSAStartup(0x0101, &wsaData);
#endif
        memset((char *)&sad,0,sizeof(sad)); 
        sad.sin_family = AF_INET;

        if (argc > 2) {                 
                port = atoi(argv[2]);   
        } else {
                port = PROTOPORT;       
        }
        if (port > 0)                   
                sad.sin_port = htons((u_short)port);
        else {                          
                fprintf(stderr,"Bad port number %s\n",argv[2]);
                exit(1);
        }

        if (argc > 1) {
                host = argv[1];
        } else {
                host = localhost;
        }

        ptrh = gethostbyname(host);
        if ( ((char *)ptrh) == NULL ) {
                fprintf(stderr,"Invalid host: %s\n", host);
                exit(1);
        }
        memcpy(&sad.sin_addr, ptrh->h_addr, ptrh->h_length);

        if ( ((int)(ptrp = getprotobyname("tcp"))) == 0) {
                fprintf(stderr, "Cannot map \"tcp\" to protocol number");
                exit(1);
        }

        sd = socket(AF_INET, SOCK_STREAM, ptrp->p_proto);
        if (sd < 0) {
                fprintf(stderr, "Socket creation failed\n");
                exit(1);
        }

        if (connect(sd, (struct sockaddr *)&sad, sizeof(sad)) < 0) {
                fprintf(stderr,"Connect failed\n");
                exit(1);
        }

        while (msg.code < 4) {
           printf ("Client: connection established with server\n");
           printf ("Codigo = ");
           msg.code = atoi (fgets(buf, sizeof(buf), stdin));
           printf ("Mensagem = ");
           text = fgets(msg.str, sizeof(msg.str), stdin);
        
           send(sd, &msg/*buf*/, sizeof msg /*strlen(*buf)*/, 0);
           n = recv(sd, &msg /*buf*/, sizeof(msg /*buf*/), 0);
           printf ("Resposta = %s\n", msg.str);
                
        }

        closesocket(sd);

        exit(0);
}