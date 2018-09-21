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
#include <thread>
#define PORT 8080 
using namespace std ;


unordered_map<string,vector<pair<string,string> > > details ;


void shareproc(int new_socket,string filp)
{
    //recv(new_socket,buffer.c_str(),512000,0) ;
    char buffer[512000] ;
    read(new_socket,buffer,512000) ;

        string temp = buffer ;
        string temp1,temp2 ;
        stringstream s;
         s << temp ;

         s>>temp ;

         cout<<temp<<endl ;
         if(temp.compare("share") == 0)
         {

            s>>temp;
            s>>temp1 ;
            s>>temp2 ;

         //   cout<<temp<<endl<<temp1<<endl<<temp2<<endl ;

     if(!details[temp].empty()) 
         return ;

     FILE *fp = fopen(filp.c_str(),"a+") ;

    details[temp].push_back(make_pair(temp1,temp2)) ;
    fprintf(fp,"%s\n%s\n%s\n",temp.c_str(),temp1.c_str(),temp2.c_str()) ;

    memset(buffer,0,sizeof(buffer)) ;
    fclose(fp) ;

        }

        // else if(temp.compare("get") ==0)
        // {
        //     string hashish
        //     s>>hashish ;

        //     int len = details[hashish].size() ;

        //     for(int i = 0 ; i < len; i++)
        //     {
        //         cin>>
        //         send(new_socket,)
        //     }


        // }

         else if(temp.compare("remove") == 0)
        {
            cout<<"Hello there" ;
            string hashish ;
            s>>hashish ;

            details.erase(hashish) ;
            FILE *fp ;
            fp = fopen(filp.c_str(),"w") ;

             for(auto i = details.begin(); i!= details.end(); i++)
            {
                 int siz = i->second.size() ;
                for(int j = 0; j < siz ; j++)
                {
                    cout<<i->second[j].first.c_str()<<endl ;
                    fprintf(fp,"%s\n%s",i->second[j].first.c_str(),i->second[j].second.c_str()) ;
                }
             }

             fclose(fp) ;


        }

    // unordered_map<string,vector<pair<string,string> > > :: iterator itr ;

    // for(auto i = details.begin(); i!= details.end(); i++)
    // {
    //     int siz = i->second.size() ;
    //     for(int j = 0; j < siz ; j++)
    //         cout<<i->second[j].second<<endl ;
    // }
}


int main(int argc, char const *argv[]) 
{ 
    FILE *fp4 = fopen(argv[1],"a+") ;
    fclose(fp4) ;
     FILE *fp3 = fopen(argv[1],"r") ;
    while(!feof(fp3))
    {
        char temp[512000],temp1[512000],temp2[512000] ;
        fscanf(fp3,"%s\n%s\n%s\n",temp,temp1,temp2) ;
        if(!details[temp].empty())
        details[temp].push_back(make_pair(temp1,temp2)) ;

    }
    fclose(fp3) ;
    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    char buffer[512000] ;
    int addrlen = sizeof(address);
       
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
    if (::bind(server_fd, (struct sockaddr *)&address,sizeof(address))<0) 
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

            thread t {shareproc,new_socket,argv[1]}  ;
            t.detach() ;
    

    
     }
    return 0; 
} 
