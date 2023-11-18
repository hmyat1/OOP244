#include <ostream>
#include "iProduct.h"
#include "Status.h"
#ifndef ITEM_H
#define ITEM_H
#define MAX_SKU_LEN 10

namespace sdds {
    class Item : public iProduct {
        double m_price;
        int m_quantityOnHand;
        int m_quantityNeeded;
        char* m_description;
        bool m_displayLinear;
        Status m_status;
        int m_sku;

    public:
        Item();
        ~Item();
        Item(const Item& src);
        Item& operator=(const Item& src);

        void clear();

        int qtyNeeded() const override;
        int qty() const override;
        operator double() const override;
        operator bool() const override;

        int operator-=(int qty) override;
        int operator+=(int qty) override;
        void linear(bool isLinear) override;

        bool operator==(int sku) const override;
        bool operator==(const char* description) const override;

        std::ofstream& save(std::ofstream& ofstr) const override;
        std::ifstream& load(std::ifstream& ifstr) override;
        std::ostream& display(std::ostream& ostr) const override;

        int readSku(std::istream& istr) override;
        std::istream& read(std::istream& istr) override;

        bool linear() const;
    };
}

#endif // ITEM_H