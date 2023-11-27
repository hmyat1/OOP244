#include "iProduct.h"
#include <iostream>



namespace sdds {
	std::ostream& operator <<(std::ostream& os, const iProduct& iproduct) {
		iproduct.display(os);
		return os;
	}

	std::istream& operator >>(std::istream& is, iProduct& iproduct) {
		iproduct.read(is);
		return is;
	}
}