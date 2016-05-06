#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
const int MAXN = 101;	//字符串的最大长度位MAXN-1
int a[MAXN][MAXN][MAXN];//a[i][j][k]表示第一个字符串的前i个字符，第二个字符串的前j个字符和
//第三个字符串的前k个字符的最长公共子序列的长度
//函数返回三个字符串的最长公共子序列的长度
int max(int m,int n)
{
	if(m>n)
		return m;
	else
		return n;
}
int max1(int x,int y,int z)
{
	int max=-1;
	if(x>max)
		max=x;
	if(y>max)
		max=y;
	if(z>max)
		max=z;
	return max;
}
int commonLen(string strA, string strB, string strC)
{
	//n1、n2、n3分别为三个字符串的长度
	int n1 = strA.size();
	int n2 = strB.size();
	int n3 = strC.size();
	
	//字符串的个数可以是0-n,共n+1个可能，所以循环中是i<=n
	for(int i = 0; i <= n1; i++)
		for(int j = 0; j <= n2; j++)
			for(int k = 0; k <= n3; k++)
				if(i == 0 || j == 0 || k == 0)	//只要有一个序列的长度为0，公共子序列的长度为0
					a[i][j][k] = 0;
				//自底向上求a[i][j][k]
	for( i = 1; i <= n1; i++)
		for(int j = 1; j <= n2; j++)
			for(int k = 1; k <= n3; k++)
			{
				if(strA[i - 1] == strB[j - 1] && strB[j - 1] == strC[k - 1])
					a[i][j][k] = a[i - 1][j - 1][k - 1] + 1;
				else 
					a[i][j][k] = max1(a[i - 1][j][k], a[i][j - 1][k],
							a[i][j][k -1]);
			}
		return a[n1][n2][n3];
}

int main1()
{
	string str1, str2, str3;
	while(cin >> str1 >> str2 >> str3)
		cout << commonLen(str1, str2, str3) << endl;
	
	return 0;
}