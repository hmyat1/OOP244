// selection.h

#ifndef SELECTION_H
#define SELECTION_H

#include <cstddef>
#include <iostream>

namespace sdds {

    // Function template to select elements based on a key
    template <typename arrayType, typename keyType>
    int* select(const arrayType array[], const keyType& key, size_t size) {
        int* indices = new int[size + 1]; // Dynamic array to store indices
        int count = 0;

        for (size_t i = 0; i < size; ++i) {
            if (array[i] == key) {
                indices[count++] = static_cast<int>(i);
            }
        }

        indices[count] = -1; // Terminator
        return indices;
    }

    // Function template to display selected elements in CSV format
    template <typename arrayType>
    void csvDisplaySelection(const char* title, const arrayType array[], const int* indices) {
        std::cout << title  << std::endl;

        if (indices != nullptr && indices[0] != -1) {
            size_t i = 0;
            while (indices[i] != -1) {
                std::cout << array[static_cast<size_t>(indices[i])];
                if (indices[i + 1] != -1) {
                    std::cout << ", ";
                }
                ++i;
            }
        } else {
            std::cout << "Empty Selection";
        }

        std::cout << std::endl;
    }

} // namespace sdds

#endif // SELECTION_H
