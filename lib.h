#include <iostream>
#include <sstream>
#include <cstdio>
#include <openssl/sha.h>
#include <string.h>
#include <sys/stat.h>
#include <cstdlib>
#include <unistd.h>


using namespace std ;
#ifndef ls_h
#define ls_h

void create_mtorrent_file(std::string, std::string, std::string , std::string, std::string ) ;
void share(string,string,string) ;
void remo(string,string) ;


#endif