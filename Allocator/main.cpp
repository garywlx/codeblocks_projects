#include <iostream>
#include <string>
#include <memory>
#include <sstream>

using namespace std;

int main()
{
    int n=10;
    cout << "Hello world!" << endl;
    allocator<string> alloc;
    auto const p=alloc.allocate(n);
    auto q=p;
    alloc.construct(q++);
    alloc.construct(q++,10,'c');
    alloc.construct(q++,"Hi");
    cout << *(p+1) << endl;
    //cout << *q << endl;
    while(q!=p)
        alloc.destroy(--q);
    alloc.deallocate(p,n);
    string txt,word;
    getline(cin,txt);
    istringstream line(txt);
    while(line >> word)
    {
        cout << word <<endl;
    }
    return 0;
}
