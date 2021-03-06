#ifndef EXERCISE7_MYVECTOR_MYVECTOR_HPP
#define EXERCISE7_MYVECTOR_MYVECTOR_HPP
#include <iostream>
#include <cmath>
using std::cout;
using std::endl;


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
    myVector(const myVector &a);//copy constructor
    myVector& operator=(const myVector& a);
    Type& operator[](int index);//get index
    void push_back(const Type& elem);//add elem at the end of the vector
    Type pop();//delete elem at the end of the vector
    int getSize() const;//equal to size() in std::vector
    Type clear(int index);//delete elem at index
    void clear(int index, int nums);//delete [nums] of elem start from index



};
template<typename Type>
void copyArray(Type* dist, Type* src, int nums)
{
    for (int i=0;i<nums;i++)
    {
        dist[i]=src[i];
    }
}

template<typename Type>
myVector<Type>::myVector() //init maxsize=128, size=0
{
    size=0;
    maxSpace=128;
    data=new Type[maxSpace]; //allocate space
}

template<typename Type>
myVector<Type>::myVector(unsigned int nums,const Type& elem)
{
    myVector::size=nums;
    if (nums<=128)
    {
        maxSpace=128;
        data=new Type[maxSpace]; //allocate space
    }
    else
    {
        int digits=int(log2(nums))+1;
        maxSpace=int(pow(2,digits));
        data=new Type[maxSpace]; //allocate space
    }

    for (int i=0;i<nums;i++)
    {
        data[i] = elem;
    } //assign value

}


template<typename Type>
myVector<Type>::~myVector() //free all the memory
{
    delete[] data;
}
template<typename Type>
void myVector<Type>::doubleSpace() //reassign the memory when there's not enough space
{
    Type* temp=data;
    data=new Type[2*maxSpace];
    copyArray(data,temp,size);
    maxSpace*=2;
    //cout<<"called `doubleSpace()`, maxSpace now:"<<maxSpace<<endl;
    //cout<<"size now:"<<size<<endl;
    delete[] temp;
}

template<typename Type>
Type& myVector<Type>::operator[](int index)
{
    Type& val= data[index];
    return val;
}

template<typename Type>
void myVector<Type>::push_back(const Type &elem)
{
    if (size<maxSpace)
    {
        data[size]=elem;
        ++size;
    }
    else
    {
        doubleSpace();
        data[size]=elem;
        ++size;
    }
}

template<typename Type>
Type myVector<Type>::pop()
{
    return data[--size];
}

template<typename Type>
int myVector<Type>::getSize() const
{
    return size;
}

template<typename Type>
Type myVector<Type>::clear(int index)
{
    Type temp=data[index];
    if(index>=size-1)
    {
        pop();
    }
    else
    {
        for (int i = index; i <= size-2 ; i++)
        {
            data[i]=data[i+1];
        }
        --size;
    }
    return temp;
}

template<typename Type>
void myVector<Type>::clear(int index, int nums)
{
    if(index>=size)
    {
        //do nothing
    }
    else if (index+nums > size)
    {
        int realNums=size-index; //clear everything after the index
        clear(index,realNums);
    }
    else
    {
        int p1=index;
        int p2=index+nums;
        while (p2<size)
        {
            data[p1]=data[p2];
            ++p2;++p1;
        }
        size-=nums;
    }
}

template<typename Type>
myVector<Type>::myVector(const myVector &a) {
    cout<<"copy constructor is called"<<endl;//only test
    size=a.size;
    maxSpace=a.maxSpace;
    data=new Type[maxSpace];
    for (int i = 0; i < size; ++i)
    {
        data[i]=a.data[i];
    }//deep copy
}

template<typename Type>
myVector<Type>& myVector<Type>::operator=(const myVector &a) {
    //free the memory, and then reallocate
    cout<<"operator '=' has been overloaded"<<endl;//only test
    if (this == &a)
    {
        return *this;
    }
    delete[] data;
    size=a.size;
    maxSpace=a.maxSpace;
    data=new Type[maxSpace];
    for (int i = 0; i < size; ++i)
    {
        data[i]=a.data[i];
    }//deep copy
    return *this;
}



#endif //EXERCISE7_MYVECTOR_MYVECTOR_HPP
