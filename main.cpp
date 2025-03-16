#include <iostream>
#include "array.h"

int main()
{
    Array arr1, arr2;
    arr1.setValue(6);
    arr1.setValue(60);
    arr2.setValue(40);
    arr2.setValue(40);

    if (arr1 == arr2) {
        std::cout << "Eq" << std::endl;
    }

    if (arr1 != arr2) {
        std::cout << "Not Eq" << std::endl;
    }

    Array arr3 = arr1 + arr2;
    arr3.showElements();
}