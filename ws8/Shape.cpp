#include <iostream>
#include "Shape.h"

using namespace std;
namespace sdds {
	std::ostream& operator<<(std::ostream& os, const Shape& shape) {
		shape.draw(os);
		return os;
	};

	std::istream& operator>>(std::istream& is, Shape& shape) {
		shape.getSpecs(is);
		return is;
	};

	Shape::~Shape() {
	};
}