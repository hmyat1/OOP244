#ifndef AIDMAN_H
#define AIDMAN_H
#include "Menu.h"
#include "iProduct.h"
namespace sdds {
	const int sdds_max_num_items = 100;
	class AidMan {
		Menu mainMenu;
		
		char* filename;
		int num_items;
		iProduct* items[sdds_max_num_items];
		
		

	public:
		AidMan();
		~AidMan();
		AidMan(const AidMan&) = delete;
		AidMan& operator=(const AidMan) = delete;
		void loadDataFromFile(const char* filename);
		void deallocate();
		void run();
		void listItems()const;

	private:
		unsigned int menu();


	};
}

#endif