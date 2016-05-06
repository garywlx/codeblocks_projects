#include <stdio.h>
#include <ctype.h>     //��лcityloveָ����
//crytTable[]���汣�����HashString�������潫���õ���һЩ���ݣ���prepareCryptTable
//���������ʼ��
unsigned long cryptTable[0x500];

//���µĺ�������һ������Ϊ0x500����10��������1280����cryptTable[0x500]
void prepareCryptTable()
{
    unsigned long seed = 0x00100001, index1 = 0, index2 = 0, i;

    for( index1 = 0; index1 < 0x100; index1++ )
    {
        for( index2 = index1, i = 0; i < 5; i++, index2 += 0x100 )
        {
            unsigned long temp1, temp2;

            seed = (seed * 125 + 3) % 0x2AAAAB;
            temp1 = (seed & 0xFFFF) << 0x10;

            seed = (seed * 125 + 3) % 0x2AAAAB;
            temp2 = (seed & 0xFFFF);

            cryptTable[index2] = ( temp1 | temp2 );
       }
   }
}

//���º�������lpszFileName �ַ�����hashֵ������dwHashType Ϊhash�����ͣ�
//������GetHashTablePos����������ñ������������ȡ��ֵΪ0��1��2���ú���
//����lpszFileName �ַ�����hashֵ��
unsigned long HashString( char *lpszFileName, unsigned long dwHashType )
{
    unsigned char *key  = (unsigned char *)lpszFileName;
unsigned long seed1 = 0x7FED7FED;
unsigned long seed2 = 0xEEEEEEEE;
    int ch;

    while( *key != 0 )
    {
        ch = toupper(*key++);

        seed1 = cryptTable[(dwHashType << 8) + ch] ^ (seed1 + seed2);
        seed2 = ch + seed1 + seed2 + (seed2 << 5) + 3;
    }
    return seed1;
}

//��main�в���argv[1]������hashֵ��
//./hash  "arr/units.dat"
//./hash  "unit/neutral/acritter.grp"
int main( int argc, char **argv )
{
    unsigned long ulHashValue;
    int i = 0;

    if ( argc != 2 )
    {
        printf("please input two arguments\n");
        return -1;
    }

     /*��ʼ�����飺crytTable[0x500]*/
     prepareCryptTable();

     /*��ӡ����crytTable[0x500]�����ֵ*/
     for ( ; i < 0x500; i++ )
     {
         if ( i % 7 == 0 )
         {
             printf("\n");
         }

         printf("%-12X", cryptTable[i] );
     }

     ulHashValue = HashString( argv[1], 0 );
     printf("\n----%X ----\n", ulHashValue );

     ulHashValue = HashString( argv[1], 1 );
     printf("----%X ----\n", ulHashValue );

     ulHashValue = HashString( argv[1], 2 );
     printf("----%X ----\n", ulHashValue );

     return 0;
}
