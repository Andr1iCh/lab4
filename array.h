#ifndef ARRAY_H
#define ARRAY_H
#include<iostream>
class Array {
	int m_size;
	int m_incrStep;
	int* m_pArr;
	int m_currentIndex;

public:
	friend std::ostream& operator<<(std::ostream& os, const Array& Array);
	friend Array operator+(int, const Array&);
	// constructors
	Array(int size = 1, int step = 1);
	Array(const Array&);
	~Array();

	//operators
	Array& operator=(const Array&);

	Array operator+(const Array&)const;
	Array operator+(int )const;
	Array operator-(int)const;
	bool  operator==(const Array&)const;
	bool  operator!=(const Array&)const;
	Array operator++();
	Array& operator+=(int val);
	int& operator[](int );
	

	//methods
	void showElements();
	void expandArray(int size);
	int getSize();
	int getElemSize();
	void setValue(int  val);
	void setArray(int* pArr, int size);

};


#endif
