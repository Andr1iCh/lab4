#include "array.h"
#include <iostream>

//constructors
Array::Array(int size, int step)
    : m_size(size), m_incrStep(step), m_currentIndex(-1)
{
    if (size <= 0) m_size = 1;
    if (step <= 0) m_incrStep = 1;
    if (m_size > 0) {
        m_pArr = new int[m_size];
        if (!m_pArr) {
            std::cout << "memory is not allocated" << std::endl;
        }
    }
}

Array::Array(const Array& right)
{
    m_size = right.m_size;
    m_incrStep = right.m_incrStep;
    m_currentIndex = right.m_currentIndex;
    m_pArr = new int[m_size];
    for (int i = 0; i < m_size; i++)
    {
        m_pArr[i] = right.m_pArr[i];
    }

}

Array::~Array()
{
    delete[] m_pArr;
}

//operators
Array& Array::operator=(const Array& RArray)
{
    if (this == &RArray)
        return *this;
    delete[]m_pArr;

    m_size = RArray.m_size;
    m_incrStep = RArray.m_incrStep;
    m_currentIndex = RArray.m_currentIndex;
    m_pArr = new int[m_size];

    for (int i = 0; i <= m_currentIndex; i++)
    {
        m_pArr[i] = RArray.m_pArr[i];
    }
    return *this;
}

Array Array::operator+(const Array& right)const
{
    Array newArray(m_size + right.m_size, 1);
    newArray.m_currentIndex = (right.m_currentIndex + m_currentIndex + 1);
    for (int i = 0; i <= m_currentIndex; i++)
    {
        newArray.m_pArr[i] = m_pArr[i];
    }
    for (int i = 0; i <= right.m_currentIndex; i++)
    {
        newArray.m_pArr[(m_currentIndex+1)+i] = right.m_pArr[i];
    }
    return newArray;
}
Array Array::operator+(int val)const
{
    Array newArray = *this;
    for (int i = 0; i <= m_currentIndex; i++)
    {
        newArray.m_pArr[i] += val;
    }
    return newArray;
}
Array Array::operator-(int val)const
{
    Array newArray = *this;
    for (int i = 0; i <= m_currentIndex; i++)
    {
        newArray.m_pArr[i] -= val;
    }
    return newArray;
}
bool Array::operator==(const Array& right) const
{
    if (m_currentIndex != right.m_currentIndex)
        return false;
    for (int i = 0; i <= m_currentIndex; ++i)
    {
        if (m_pArr[i] != right.m_pArr[i])
            return false;
    }
    return true;
}
bool Array::operator!=(const Array& right) const
{
    return !(*this == right);
}
Array Array::operator++(int)
{
    Array tempArray = *this;
    for (int i = 0; i <= m_currentIndex; ++i)
    {
        ++m_pArr[i];
    }
    return tempArray;
}
Array& Array::operator+=(int val)
{
    for (int i = 0; i <= m_currentIndex; ++i)
    {
        m_pArr[i] += val;
    }
    return *this;
}
int& Array::operator[](int index)
{
    if ((0 <= index) && (index < m_size))
    {
        return m_pArr[index];
    }
    else
        return m_pArr[0];
}
std::ostream& operator<<(std::ostream& os, const Array& arr)
{
    for (int i = 0; i <= arr.m_currentIndex; ++i)
        os << arr.m_pArr[i] << " ";
    return os;
}
Array operator+(int val, const Array& arr)
{
    return arr+val;
}

//methods
void Array::showElements()
{
    if (m_currentIndex == -1) {
        std::cout << "Array is empty" << std::endl;
        return;
    }
    for (int i = 0; i <= m_currentIndex; ++i) {
        std::cout << m_pArr[i] << " ";
    }
    std::cout << std::endl;
}

void Array::expandArray(int size)
{
    if (size <= m_size) return;
    int newSize = size + m_incrStep;
    int* newArr = new int[newSize];
    if (!newArr) {
        std::cout << "Failed to expand array!" << std::endl;
        return;
    }
    for (int i = 0; i <= m_currentIndex; ++i) {
        newArr[i] = m_pArr[i];
    }
    delete[] m_pArr;
    m_pArr = newArr;
    m_size = newSize;
}

int Array::getSize()
{
    return m_size;
}

int Array::getElemSize()
{
    return (m_currentIndex + 1);
}

void Array::setValue(int val)
{
    if (m_currentIndex + 1 >= m_size) {
        expandArray(m_size + m_incrStep);
    }
    m_pArr[++m_currentIndex] = val;
}

void Array::setArray(int* pArr, int size)
{
    if (!pArr || size <= 0) {
        return;
    }
    int fullSize = (m_currentIndex + 1) + size;
    if (fullSize > m_size) {
        expandArray(fullSize);
    }
    for (int i = 0; i < size; i++) {
        setValue(pArr[i]);
    }
}
