#include <iostream>
#include <SSTREAM>
#include <string>
using namespace std;
int main1(){
	string word,line;
	int val1=512,val2=1024;
	ostringstream format_message;
	format_message << "val1:" << val1 << "\n"
		<< "val2" << val2 << "\n";
	istringstream input_istring(format_message.str());
	string dump;
	input_istring >> dump >> val1 >> dump >> val2;
	cout << val1 << " " << val2 << endl;
	while(getline(cin,line)){
		istringstream stream(line);
		while(stream >> word){
			cout << word << endl;
		}
	}
	return 0;
}