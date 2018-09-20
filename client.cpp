#include "lib.h"

using namespace std ;

#define clear() printf("\033[H\033[J")

int main(int argc, char const *argv[])
{
	clear() ;
	string line;
	string command ;

	printf("Enter command : ");
	 getline(cin,line) ;


	stringstream input (line) ;
	input>> command ;

	if(command.compare("share") == 0)
	{
		string path, torrent_filename ; // Variables for storing path of file and torrent file name.


		input>>path ;
		input>>torrent_filename ;

		create_mtorrent_file(path,torrent_filename,argv[2],argv[3],argv[1]) ;


	}

	// else if(command.compare("get") == 0)
	// {
	// 	pid_t pid = fork() ;
	// 	if(pid == 0)
	// 	{
	// 		while(1){
	// 			cout<<"I'm child !"<<endl ;
	// 			getchar() ;
	// 			}
	// 	}

	// 	while(1)
	// 	{
	// 		cout<<"I'm server"<<endl ;
	// 		getchar() ;
	// 	}
	// }



	return 0;
}