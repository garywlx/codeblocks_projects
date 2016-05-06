#include <fstream>
#include <iostream>
#include<stdlib.h>
#include<string.h>
#include <ctime>

using namespace std;

#define N 32           //��ʱ�ļ���

#define ID(x)  (x>>27)                 //x��Ӧ���ļ����
#define VALUE(x) (x&0x07ffffff)        //x���ļ��б����ֵ
#define MAKE_IP(x,y)  ((x<<27)|y)      //���ļ���ź�ֵ�õ�IP��ַ.

#define MEM_SIZE  128*1024*1024       //������ڴ�Ĵ�СΪ MEM_SIZE*sizeof(unsigned)

char* data_path="D:/test/ip.dat";        //ip����

 //����n�����IP��ַ
void make_data(const int& n)
{
	ofstream out(data_path,ios::out|ios::binary);
	srand((unsigned)(time(NULL)));
	if (out)
	{
		for (int i=0; i<n; ++i)
		{
			unsigned val=unsigned(rand());
			val = (val<<24)|val;				//����unsigned���͵������

			out.write((char *)&val,sizeof (unsigned));
		}
	}
}

//�ҵ����ʴ�������ip��ַ
int main()
{
	//make_data(100);     //
	make_data(100000000);       //���������õ�IP����
	fstream arr[N];

	for (int i=0; i<N; ++i)                 //����N����ʱ�ļ�
	{
		char tmp_path[128];     //��ʱ�ļ�·��
		sprintf(tmp_path,"D:/test/tmp%d.dat",i);
		arr[i].open(tmp_path, ios::trunc|ios::in|ios::out|ios::binary);  //�򿪵�i���ļ�

		if( !arr[i])
		{
			cout<<"open file"<<i<<"error"<<endl;
		}
	}

	ifstream infile(data_path,ios::in|ios::binary);   //��������õ�IP����
	unsigned data;

	while(infile.read((char*)(&data), sizeof(data)))
	{
		unsigned val=VALUE(data);
		int key=ID(data);
		arr[key].write((char*)(&val), sizeof(val));           //���浽��ʱ�ļ�����
	}

	for(unsigned i=0; i<N; ++i)
	{
		arr[i].seekg(0);
	}
	unsigned max_ip = 0;    //���ִ�������ip��ַ
	unsigned max_times = 0;     //���ֻ���ֵĴ���


	//����512M�ڴ�,����ͳ��ÿ�������ֵĴ���
	unsigned *count = new unsigned[MEM_SIZE];

	for (unsigned i=0; i<N; ++i)
	{
		memset(count, 0, sizeof(unsigned)*MEM_SIZE);

		//ͳ��ÿ����ʱ�ļ����в�ͬ���ֳ��ֵĴ���
		unsigned data;
		while(arr[i].read((char*)(&data), sizeof(unsigned)))
		{
			++count[data];
		}

		//�ҳ����ִ�������IP��ַ
		for(unsigned j=0; j<MEM_SIZE; ++j)
		{
			if(max_times<count[j])
			{
				max_times = count[j];
				max_ip = MAKE_IP(i,j);        // �ָ���ԭip��ַ.
			}
		}
	}
	delete[] count;
	unsigned char *result=(unsigned char *)(&max_ip);
	printf("���ִ�������IPΪ:%d.%d.%d.%d,������%d��",
		result[0], result[1], result[2], result[3], max_times);
}
