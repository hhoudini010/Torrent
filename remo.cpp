
#include "lib.h"

#include <cstdio> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

void remo(string hash, string clip)
{

	struct sockaddr_in address; 
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
    char *hello = "Hello from client"; 
    char buffer[512000] = {0}; 
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        exit(1) ;
    } 
   
 //    // memset(&serv_addr, '0', sizeof(serv_addr)); 
   
    serv_addr.sin_family = AF_INET; 
    address.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    serv_addr.sin_port = htons(PORT); 
       
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        exit(1) ;
    } 
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        exit(1) ;
    } 

    string mode("remove") ;

    mode = mode + " " + hash + " " + clip;


    send(sock,mode.c_str(),mode.length(),0) ;

  
}