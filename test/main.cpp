#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    vector<int> a= {1,2,3,1,4,5};
    vector<int> inc(6,INT_MAX);
    vector<int> c(6,0);
    vector<int> d(6,0);
    for(int i=0; i<6; i++)
    {
        int low = 0,high = i;
        while(low < high)
        {
            int mid = (low + high) >> 1;
            if(inc[mid] < a[i])
            {
                low = mid+1;
            }
            else high = mid;
        }
        c[i] = low +1;
        inc[low] = a[i];
    }
    for(auto elem : c)
        cout << elem << ends;

    cout << endl;
    reverse(a.begin(),a.end());
    inc.clear();
    for(int i=0; i<6; i++)inc[i] = INT_MAX;
    for(int i=0; i<6; i++)
    {
        int low = 0,high = i;
        while(low < high)
        {
            int mid = (low + high) >> 1;
            if(inc[mid] < a[i])
            {
                low = mid+1;
            }
            else high = mid;
        }
        d[i] = low + 1;
        inc[low] = a[i];
    }
    reverse(d.begin(),d.end());
    for(auto elem : d)
        cout << elem << ends;
    cout << endl;
    int max = 0;
    for (int i = 0; i < 6; ++i )
        if (c[i] + d[i] > max) max = c[i] + d[i];
    cout << 7-max;
    return 0;
}
