#include<IOSTREAM>
#include"StdAfx.h"

using namespace std;

class Base{
	virtual void virtualfunc(){
		cout << "This is the Base's virtual function!" << endl;
	}
};
class Derived1:public Base{
public :
	void virtualfunc(){
		cout << "THe is the Derived1's virtual function" << endl;
	}
};
class Derived2:public Base{
public :
	void virtualfunc(){
		cout << "THe is the Derived1's virtual function" << endl;
	}
};
