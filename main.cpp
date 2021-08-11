#include "myVector.cpp" // cannot include .h file because it's a template class.
using namespace std;

int main() //testing code
{
    myVector<int> test1(3,4);
    test1.push_back(9);
    cout<<"test1:"<<test1[3]<<endl;
    test1.push_back(86);
    cout<<test1.clear(2)<<endl;
    cout<<"size="<<test1.getSize()<<endl;
    cout<<test1[3];
    return 0;
}
