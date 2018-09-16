#include "lib.h"

using namespace std ;

#define clear() printf("\033[H\033[J")

int main(int argc, char const *argv[])
{
	clear() ;
	string line;
	string command ;


	printf("Enter whole sentence (yeah, bring spaces too, I can handle it):\n");
	 getline(cin,line) ;


	stringstream input (line) ;
	input>> command ;

	if(command.compare("share") == 0)
	{
		string path, torrent_filename ; // Variables for storing path of file and torrent file name.


		input>>path ;
		input>>torrent_filename ;

		create_mtorrent_file(path,torrent_filename,argv[2],argv[3]) ;


	}

	

	return 0;
}