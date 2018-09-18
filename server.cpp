// Server side C/C++ program to demonstrate Socket programming 
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <iostream>
#include <arpa/inet.h>
#include <unordered_map>
#include <sstream>
#include <vector>
#define PORT 4444 
using namespace std ;

unordered_map<string,vector<pair<string,string> > > details ;


int main(int argc, char const *argv[]) 
{ 
    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    char buffer[512000] ;
    int addrlen = sizeof(address); 
    
    char *hello = "Hello from server"; 
       
    // Creating socket file descriptor 
    int count = 0 ;
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
       
    // Forcefully attaching socket to the port 8080 
    if (setsockopt(server_fd, SOL_SOCKET, 1,&opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    address.sin_port = htons( PORT ); 
       
    // Forcefully attaching socket to the port 8080 
    if (bind(server_fd, (struct sockaddr *)&address,sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
   
    if (listen(server_fd, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
     while(1){
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,(socklen_t*)&addrlen))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    }
    pid_t pid = fork() ;
    if(pid==0){
    

        recv(new_socket,buffer,sizeof(buffer),0) ;
        string temp = buffer ;
        string temp1,temp2 ;

        stringstream s(temp) ;

        s>>temp ;
        s>>temp1 ;
        s>>temp2 ;

        details[temp].push_back(make_pair(temp1,temp2)) ;

        unordered_map<string,vector<pair<string,string> > > :: iterator itr ;

        itr = details.begin() ;

        cout<<itr->second[0].second<<endl ;

     exit(0) ;
 }

    
     }
    return 0; 
} 
