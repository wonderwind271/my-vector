//
// Created by X1G8 on 2021/7/24.
//

#ifndef EXERCISE7_MYVECTOR_MYVECTOR_H
#define EXERCISE7_MYVECTOR_MYVECTOR_H
#include <iostream>
//using std::size_t;

template<typename Type>
class myVector
{
private:
    Type* data;
    int size;
    int maxSpace;
    void doubleSpace(); //should not be accessed by public

public:
    myVector();
    ~myVector();
    myVector(unsigned int nums,const Type& elem);
    Type& operator[](int index);
    void push_back(const Type& elem);
    Type pop();
    int getSize() const;
    Type clear(int index);
    void clear(int index, int length);

};


#endif //EXERCISE7_MYVECTOR_MYVECTOR_H
