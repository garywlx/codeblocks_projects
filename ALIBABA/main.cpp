#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;
void test_hash_map()
{
    cout << "Test Hash Map" << endl;
    unordered_map<string,int> yeah;
    string hello = "hello";
	yeah.insert(pair<string,int>("hello",1));
	yeah["Mellow Gold"] = 233;
	if (yeah["Mellow Gold"])
		cout << "YEY!,value:"<< yeah["Mellow Gold"] << endl;
    else
        cout << "NO!" << endl;
	cout << yeah["hello"];
	yeah["okay"] = 23;
	cout << endl << yeah["okay"] << endl;

}
void test_hash_set()
{
    cout << "Test Hash Set" << endl;
    unordered_set<int> hset ={ 1,2,3,4,23,2,2,2};
	unordered_set<int>::const_iterator got=hset.find(2);
	if(got==hset.end())
        cout <<"not find in my set"<< endl;
    else
        std::cout << *got << " is in myset" << endl;
    cout <<"the size of hashset:" <<hset.size() <<endl;
    cout <<"the buckect of hashset:" <<hset.bucket_size(2) <<endl;

}
int main()
{



	return 0;
}
