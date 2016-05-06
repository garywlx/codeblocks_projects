#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
const int MAXN = 101;	//�ַ�������󳤶�λMAXN-1
int a[MAXN][MAXN][MAXN];//a[i][j][k]��ʾ��һ���ַ�����ǰi���ַ����ڶ����ַ�����ǰj���ַ���
//�������ַ�����ǰk���ַ�������������еĳ���
//�������������ַ���������������еĳ���
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
	//n1��n2��n3�ֱ�Ϊ�����ַ����ĳ���
	int n1 = strA.size();
	int n2 = strB.size();
	int n3 = strC.size();
	
	//�ַ����ĸ���������0-n,��n+1�����ܣ�����ѭ������i<=n
	for(int i = 0; i <= n1; i++)
		for(int j = 0; j <= n2; j++)
			for(int k = 0; k <= n3; k++)
				if(i == 0 || j == 0 || k == 0)	//ֻҪ��һ�����еĳ���Ϊ0�����������еĳ���Ϊ0
					a[i][j][k] = 0;
				//�Ե�������a[i][j][k]
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