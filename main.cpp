/*
 * This is only a testing file that shows how the myVector works.
 */
#include "myVector.hpp"
using namespace std;

int main() //testing code
{
    myVector<int> test1(3,4);
    test1.push_back(9);
    cout<<"test1:"<<test1[3]<<endl;
    test1.push_back(86);
    cout<<test1.clear(2)<<endl;
    cout<<"size="<<test1.getSize()<<endl;
    cout<<test1[3]<<endl;
    test1.clear(1,1);
    cout<<test1.getSize()<<" "<<test1[2]<<endl;
    myVector<int> testcopy;
    auto testnew = (testcopy = test1);
    cout<<testcopy[0]<<endl;
    cout<<testnew[1]<<endl;

    return 0;
}
