#include <iostream>
#include "array.h"

int main()
{
	Array a1(5, 1);
	Array a3(7, 1);
	a1.setValue(2);
	a1.setValue(3);
	a1.setValue(4);
	a3.setValue(12);
	a3.setValue(13);
	a3.setValue(14);
	a3.setValue(15);
	a3.setValue(16);
	a3.setValue(17);

	Array a2 = a1;
	a2.showElements();
	a1=a3;
	a1.showElements();

}