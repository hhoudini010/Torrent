#include "lib.h"

using namespace std ;


void bin2hex( unsigned char * src, int len, char * hex )
{
    int i, j;

    for( i = 0, j = 0; i < len; i++, j+=2 )
        sprintf( &hex[j], "%02x", src[i] );
}


void create_mtorrent_file(string path, string torrent_filename, string tr1ip, string tr2ip)
{
	FILE *fp,*fp1 ;
	unsigned char ch[5120000],out[SHA_DIGEST_LENGTH] ;
	char hex[2*SHA_DIGEST_LENGTH]; 
	char *abs;
	int bytesRead ;
	struct stat mystat ;

	abs = realpath(path.c_str(),NULL) ;


	stat(path.c_str(), &mystat) ;
	size_t siz = mystat.st_size ;


	string hash ;

	fp = fopen(torrent_filename.c_str(),"w") ;
	fp1 = fopen(path.c_str(),"rb") ;
	
	while(1)
	{
		bytesRead = fread(ch, sizeof(char), 512000, fp1) ;
		SHA1(ch, bytesRead, out);
		bin2hex(out,sizeof(out),hex) ;

		string temp(hex,20) ;
		hash = hash + temp;

		if(bytesRead <= 0)
			break ;
	}


	


	fprintf(fp,"%s\n%s\n%s\n%zu\n%s",tr1ip.c_str(),tr2ip.c_str(),abs,siz,hash.c_str()) ;

}
