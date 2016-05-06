#include<IOSTREAM>
#include<VECTOR>
#include<STRING>
#include<fstream>
#include<SSTREAM>
using namespace std;

enum Tokens{INLINE=128,VIRTUAL=129};
void ff(Tokens);
void ff(int);
void newf(unsigned char);
void newf(int);
bool (*pf)(const string &, const string &);
typedef bool (*cmpFuc)(const string &,const string &);
bool lengthCmp(const string &,const string &);
ofstream &print(ofstream&);
void process(const string s){
	cout << s << endl;
}
/************************************************************************/
/* Open file Function                                                                     */
/************************************************************************/
ifstream& open_file(ifstream &in,const string &file){
	in.close();
	in.clear();
	in.open(file.c_str());
	return in;
}
int main1(){
	ofstream out1,out2;
	cout << "hi!" <<ends;
	cout << "hi!" << ends;
	cout << "hi!" << endl;
	cout << unitbuf << "first " << "second!" << nounitbuf;
	cout << "first " << flush << "second " << flush;
	cout << endl;
/*
	cin.tie(&cout);
	ostream *old_tie=cin.tie();
	cin.tie(0);
	cin.tie(&cerr);
	cin.tie(0);
	cin.tie(old_tie);*/
	//ofstream outfile("a");
	ofstream outfile2("a",ofstream::out|ofstream::trunc);
	ofstream appfile("b", ofstream::app);
	vector<string> files;
	files.push_back("a");
	files.push_back("b");
	ifstream input;
	vector<string>::const_iterator it = files.begin();
	// for each file in the vector
	string s;
	while (it != files.end()) {
		input.open(it->c_str()); // open the file
		// if the file is ok, read and "process" the input
		if (!input)
			cerr << "cannot open file:" << it->c_str() << endl;
			break; // error: bail out!
		while(input >> s) // do the work on this file
			process(s);
		input.close(); // close file when we're done with it
		input.clear(); // reset state to ok
		++it; // increment iterator to get next file
	}
	fstream inOut("copyOut",fstream::in|fstream::out);

	ofstream outfile;
	// output mode set to out, "scratchpad" truncated
	outfile.open("a", ofstream::out);
	outfile.close(); // close outfile so we can rebind it
	// appends to file named "precious"
	outfile.open("b", ofstream::app);
	outfile.close();
	// output mode set by default, "out" truncated
	outfile.open("out");
	return 0;
}
