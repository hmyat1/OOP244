#ifndef AIDMAN_H
#define AIDMAN_H
#include "Menu.h"
namespace sdds {
	class AidMan {
	
		char* filename;
		Menu mainMenu;
	public:
		AidMan(const char* fileName);
		~AidMan();
		AidMan(const AidMan&) = delete;
		AidMan& operator=(const AidMan) = delete;


		void run();

	private:
		unsigned int menu();


	};
}

#endif
