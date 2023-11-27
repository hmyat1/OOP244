#include "Item.h"
#include "Date.h"
#ifndef PERISHABLE_H
#define PERISHABLE_H

namespace sdds {

	class Perishable :public Item {
    private:
        Date m_expiryDate;
        char* m_handlingInstructions;
        //int exp;

    public:
        Perishable();
        Perishable(const Perishable& src);
        ~Perishable();
        Perishable& operator=(const Perishable& src);
        operator bool() const override;
        const Date& expiry() const;
        std::ostream& display(std::ostream& ostr) const override;

        std::ofstream& save(std::ofstream& ofstr) const override;
        std::ifstream& load(std::ifstream& ifstr) override;

        int readSku(std::istream& istr) override;
        std::istream& read(std::istream& istr) override;
	};
	



}











#endif // PERISHABLE_H