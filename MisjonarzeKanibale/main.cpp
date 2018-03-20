
#include "Gra.h"


using std::cout;
using std::endl;

void Info();

/**
 * @fn	int main(int argc, char* argv[])
 *
 * @brief	Main entry-point for this application
 *
 * @date	23.01.2018
 *
 * @param	argc	The number of command-line arguments provided.
 * @param	argv	An array of command-line argument strings.
 *
 * @return	Exit-code for the process - 0 for success, else an error code.
 */

int main(int argc, char* argv[])
{

	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// deklaracja gry
	Gra gra(argc, argv);
	
	gra.NowaGra();
	
	getchar();
	return 0;
}
