#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4
//����ȱ��1  û�����õ�һ��������Ϸ�������ѡ�
//����ȱ��2  ��ͯ���İ�  �ͳ���Ӣ�İ�   �Ѷ�û�в��졣
//����ȱ��3  ���Լ�����ϵͳ�;���ϵͳ����ÿ�β¶Բ´�Ӽ���ң�ÿ�β¶ԼӾ��飬����Խ�ߣ����Խ������Ѷ�Խ�ߣ�
//����ȱ��4  ������ģʽ������ֻ��������λ�����д��ĳɶ����Ѷȣ����ҿ����Զ����Ѷȵ���ʽ��
//����ȱ��5  ������ģʽ�У����ɵ����ֲ�ͬλ֮�������ͬ��

//  ���� ���� 10 �� a ���ݡ�
int pow_10(int a);
//  �������һ���� a �� b �ڵ����֡� a �����ޣ� b �����ޡ�
int Magicnumber(int a, int b);
//  ������������������ a �� b Ϊ������Ӧ����ķ�Χ��a �����ޣ� b �����ޡ�
int GuessnumberChi(int a, int b);
int GuessnumberEng(int a, int b);
//  �ж��������֣��Ƿ���ȷ�� a �ǲ������� b �����ϵͳ����
int Judgenumber(int a, int b);
//  �������� ���ݴ��������ȷ�𰸵�ƫ���С�� �����ͬ�Ĵ�����ʾ��a �ǲ������� b �����ϵͳ����
void JudgeWrongChi(int a, int b);
void JudgeWrongEng(int a, int b);
//  ������ȷ������������ķ�ʽ�� ���ɲ�ͬ��ף����䡣a �ǲ������� b �����ϵͳ����
void JudgeRightChi(void);
void JudgeRightEng(void);
//  �����жϲ������ֺ�������������ͬλ��������a �ǲ������� b �����ϵͳ����
int Judgepri(int a, int b);
//  ���ڴ���������ж��ʹ�õĶ������жϵ���䡣
void LongAboutMainChi(int a, int upp, int low);
void LongAboutMainEng(int a, int upp, int low);

int main()
{
    //ѡ����Ϸ�汾��1.Ӣ�İ� 2. �����   ������Ŀǰ�Ѷ���ͬ���д��Ľ���
    printf("Choose edition.\n1. English and for adult\n2. ���� ��ͯ��\n");
    char anwser1 = 0, anwser2 = 0;
    //anwser 1 �� anwser 2 �����ж������Ƿ�Ϸ��� �����Ϸ�����ô�������룬ֱ���Ϸ�Ϊֹ��
    anwser1 = getchar();
    anwser2 = getchar();
    for (;(anwser1 != '1' && anwser1 != '2') || anwser2 != '\n';)
        {
            while (anwser2 != '\n' && getchar() != '\n');
            printf("It seems that you have input something wrong.>_<\nPlease input again :");
            anwser1 = getchar();
            anwser2 = getchar();
        }
    if (anwser1 == '1')
    {
        int b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0, j = 0;
        int count = 0;
        char anwser = 0, m = 0;
        // ѡ����Ϸģʽ   1�� ��ͨ������Ϸ    2�������ǲ�����Ϸ����Ϸ�����ں��棩    3���˳�
        printf("Welcome to The Game of Guess Number\n");
        printf("1.Guess it as a whole number.\n");
        //  2 ���д��޸ģ��ܹ��ĳɶ��Ѷȵġ�
        printf("2.Guess it as some independent numbers.\n");
        printf("3.Exit.\n");
        printf("Your choose is : ");
        //��ֹ��������
        anwser1 = getchar();
        anwser2 = getchar();
        for (;(anwser1 < '1' && anwser1 > '3') || anwser2 != '\n';)
            {
                while (anwser2 != '\n' && getchar() != '\n');
                printf("It seems that you have input something wrong.>_<\nPlease input again :");
                anwser1 = getchar();
                anwser2 = getchar();
            }
            //ѡ����Ϸ�Ѷ�
        switch (anwser1)
        {
            case '1':
                printf("1.easy(number from 001 - 100)\n2.normal(number from 0001 - 1000)\n3.hard(number from 00001 - 10000)\n4.defined by yourself(no less than 1 and no more than 10000)\nYour choose is :");
                anwser1 = getchar();
                anwser2 = getchar();
                for (;(anwser1 < '1' && anwser1 > '4') || anwser2 != '\n';)
                    {
                        while (anwser2 != '\n' && getchar() != '\n');
                        printf("It seems that you have input something wrong.>_<\nPlease input again :");
                        anwser1 = getchar();
                        anwser2 = getchar();
                    }
                switch (anwser1)
                {
                    //���������ѡ����Ѷȣ�����ָ�����Ͷ�Ӧ����
                    case '1':
                        b = Magicnumber(1, 100);
                        LongAboutMainEng(b, 1, 100);
                        break;
                    case '2':
                        c = Magicnumber(1, 1000);
                        LongAboutMainEng(c, 1, 1000);
                        break;
                    case '3':
                        d = Magicnumber(1, 10000);
                        LongAboutMainEng(d, 1, 1000);
                        break;
                    case '4':
                        printf("Please input you upper limit ");
                        scanf("%d", &f);
                        printf("Please input you lower limit ");
                        scanf("%d", &g);
                        e = Magicnumber(f, g);
                        LongAboutMainEng(e, f, g);
                        break;
                }
                break;
            case '2':
                //���¼��� printf Ϊ�����ǲ�����Ϸ��Ϸ˵����
                printf("Superscript : The computer will produce a 4-digit number (including 0001 - 0999) \n");
                printf("              and the player should input a 4-digit number.\n");
                printf("              Example 1 :\n");
                printf("              The number produced by computer is\n");
                printf("              4387\n");
                printf("              The number inputed by you is \n");
                printf("              4072\n");
                printf("              Then the strings print on the screen will be\n");
                printf("              1A1B\n");
                printf("              Because the number produced by computer has a '4' and you put it on the correct position, there is a A.\n");
                printf("              Likely the number produced by computer has a '7', however you put it on the wrong position ,there is a B.\n");
                printf("              Also if the magic number is 6600, and your input is 6543, there will be a tip 1A1B.\n");
                h = Magicnumber(1, 9999);
                while (1)
                {
                    i = GuessnumberEng(1, 9999);
                    j = Judgepri(i, h);
                    if (j)
                    {
                        JudgeRightEng();
                        exit(0);
                    }
                    else
                    {
                        count++;// count ���ڼ�¼���������
                        printf("You have guessed %d times,would you want to continue? Y/N",count);
                        anwser = getchar();
                        m = getchar();
                        for (;(anwser != 'Y' && anwser != 'y' && anwser != 'N' && anwser != 'n') || m != '\n';)
                        {
                            while (m != '\n' && getchar() != '\n');
                            printf("It seems that you have input something wrong.>_<\nPlease input again :");
                            anwser = getchar();
                            m = getchar();
                        }
                        if (anwser == 'N' || anwser == 'n')
                        {
                            exit(0);
                        }
                    }
                }
                break;
            case '3':
                exit(0);
        }
    }
    // ���Ķ�ͯ��
    else
    {
        int b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0, j = 0;
        int count = 0;
        char anwser = 0, m = 0;
        printf("\t��ӭ������������Ϸ\n");
        printf("1.��һ������\n");
        //  2 ���д��޸ģ��ܹ��ĳɶ��Ѷȵġ�
        printf("2.������\n");
        printf("3.�˳�\n");
        printf("ѡ��һ�°� : ");
        anwser1 = getchar();
        anwser2 = getchar();
        for (;(anwser1 < '1' && anwser1 > '3') || anwser2 != '\n';)
            {
                while (anwser2 != '\n' && getchar() != '\n');
                printf("С���ѣ����ƺ�û�а�Ҫ������Ŷ~\n�����������^_^ :");
                anwser1 = getchar();
                anwser2 = getchar();
            }
        switch (anwser1)
        {
            case '1':
                printf("1.���Ѷ�(��1-100�в�����)\n2.�е��Ѷ�(��1-1000�в�����)\n3.�����Ѷ�(��1-10000�в�����)\n4.�Զ���~(������1��������10000)\n������ң����ѡ�� :");
                anwser1 = getchar();
                anwser2 = getchar();
            for (;(anwser1 < '1' && anwser1 > '4') || anwser2 != '\n';)
            {
                while (anwser2 != '\n' && getchar() != '\n');
                printf("С���ѣ����ƺ�û�а�Ҫ������Ŷ~\n�����������^_^ :");
                anwser1 = getchar();
                anwser2 = getchar();
            }
                switch (anwser1)
                {
                    case '1':
                        b = Magicnumber(1, 100);
                        LongAboutMainChi(b, 1, 100);
                        break;
                    case '2':
                        c = Magicnumber(1, 1000);
                        LongAboutMainChi(c, 1, 1000);
                        break;
                    case '3':
                        d = Magicnumber(1, 10000);
                        LongAboutMainChi(d, 1, 1000);
                        break;
                    case '4':
                        printf("���������� ��");
                        scanf("%d", &f);
                        printf("���������� ��");
                        scanf("%d", &g);
                        e = Magicnumber(f, g);
                        LongAboutMainChi(e, f, g);
                        break;
                }
                break;
            case '2':
                printf("��Ϸ���� �� ����������������һ��4λ��������0001 - 9999��\n");
                printf("            С���ѣ�������Ҫ����Ҳ������һ����λ��\n");
                printf("            ���磺\n");
                printf("            ��������ɵ�������\n");
                printf("            4387\n");
                printf("            �����µ�������\n");
                printf("            4072\n");
                printf("            ��ô��Ļ�Ͻ�����ʾһ���ַ�\n");
                printf("            1A1B\n");
                printf("            ��Ϊ���������ɵ���������һ��'4' �������������������'4'ǡ������ȷ��λ��, ���Ծͻ���һ�� A.\n");
                printf("            ͬ���ģ��������ɵ���������һ��'7', Ȼ����ȴ��û�а�7������ȷ��λ�� ,��������һ�� B.\n");
                printf("            ����������ɵ������� 6600, ͬʱ������������� 6543, ��ô��ʾ�ͻ��� 1A1B.\n");
                h = Magicnumber(1, 9999);
                while (1)
                {
                    i = GuessnumberChi(1, 9999);
                    j = Judgepri(i, h);
                    if (j)
                    {
                        JudgeRightChi();
                            exit(0);
                    }
                    else
                    {
                        count++;
                        printf("���Ѿ�����%d��,Ҫ������? Y/N",count);
                        anwser = getchar();
                        m = getchar();
                        for (;(anwser != 'Y' && anwser != 'y' && anwser != 'N' && anwser != 'n') || m != '\n';)
                        {
                            while (m != '\n' && getchar() != '\n');
                            printf("�ƺ�С�����㲢û�а�Ҫ�����롣\n������һ�ΰ� ^_^:");
                            anwser = getchar();
                            m = getchar();
                        }
                        if (anwser == 'N' || anwser == 'n')
                        {
                            exit(0);
                        }
                    }
                }
                break;
            case '3':
                exit(0);
        }
    }
    return 0;
}

void LongAboutMainChi(int a, int upp, int low)
{
    int c = 0, b1 = 0, count = 0;
    char anwser = 0, m = 0;
    while (1)
    {
        c = GuessnumberChi(upp, low);
        b1 = Judgenumber(c, a);
        if (b1)
        {
            JudgeRightChi();
            exit(0);
        }
        else
        {
            JudgeWrongChi(c, a);
            count++;    //count  ���ڼ�¼�������
            printf("���Ѿ�����%d��,Ҫ������? Y/N",count);
            anwser = getchar();
            m = getchar();
            // ���ڷ�ֹ��������
            for (;(anwser != 'Y' && anwser != 'y' && anwser != 'N' && anwser != 'n') || m != '\n';)
            {
                while (m != '\n' && getchar() != '\n');
                printf("�ƺ�С�����㲢û�а�Ҫ�����롣\n������һ�ΰ�  ^_^:");
                anwser = getchar();
                m = getchar();
            }
            if (anwser == 'N' || anwser == 'n')
            {
                exit(0);
            }
        }
    }
}

void LongAboutMainEng(int a, int upp, int low)
{
    int c = 0, b1 = 0, count = 0;
    char anwser = 0, m = 0;
    while (1)
    {
        c = GuessnumberEng(upp, low);
        b1 = Judgenumber(c, a);
        if (b1)
        {
            JudgeRightEng();
            exit(0);
        }
        else
        {
            JudgeWrongEng(c, a);
            count++;
            printf("You have guessed %d times, do you want to continue? Y/N",count);
            anwser = getchar();
            m = getchar();
            for (;(anwser != 'Y' && anwser != 'y' && anwser != 'N' && anwser != 'n') || m != '\n';)
            {
                while (m != '\n' && getchar() != '\n');
                printf("It seems that you have inputed something.\nInput it again, please:");
                anwser = getchar();
                m = getchar();
            }
            if (anwser == 'N' || anwser == 'n')
            {
                exit(0);
            }
        }
    }
}

int Magicnumber(int a, int b)   //a �����ޣ� b �����ޡ�
{
    int magic = 0;
    srand((int)time(0));
    magic = rand() % (b - a) + a;
    return magic;
}

int GuessnumberChi(int a, int b)
{
    int c = 0;
    char d = 0;
    printf("��һ�����ɣ�С����:^_^");
    scanf("%d",&c);
    d = getchar();
    while (d != '\n' || c < a || c > b)
    {
        printf("�ƺ�С�����㲢û�а�Ҫ�����롣\n������һ�ΰ� ^_^:");
        while (getchar() != '\n');
        scanf("%d",&c);
        d = getchar();
    }
    return c;
}

int GuessnumberEng(int a, int b)
{
    int c = 0;
    char d = 0;
    printf("Please guess a number :^_^");
    scanf("%d",&c);
    d = getchar();
    while (d != '\n' || c < a || c > b)
    {
        printf("It seems that you have inputed something.\nInput it again, please:");
        while (getchar() != '\n');
        scanf("%d",&c);
        d = getchar();
    }
    return c;
}

int Judgenumber(int a, int b)  //a �ǲ������� b �����ϵͳ����
{
    if (a == b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void JudgeWrongChi(int a, int b)   //a �ǲ������� b �����ϵͳ����
{
    //  ��ȷ��ʱ��������� �Ƚϲµ����ִ���С��
    if (a > b)
    {
        //  ȷ�����ֲµù���� ����ƫ����ȷ�𰸵ĳ̶ȣ� ���費ͬ��ʾ��
        if (a > 1.5 * b)
        {
            printf("������С���ѣ���µ������е����һ��Сһ�������~\n");
        }
        else if (a < 1.04 * b)
        {
            printf("(��o��)ֻ����һ���Ŷ~ ���ͣ����ͣ�\n");
        }
        else
        {
            printf("^o^����� �Ѿ��ǳ��ǳ��ӽ��ˣ�\n");
        }
    }
    else
    {
        //  ȷ�����ֲµù�С�� ����ƫ����ȷ�𰸵ĳ̶ȣ� ���費ͬ��ʾ��
        if (a < 0.5 * b)
        {
            printf("�����е�̫С�ˣ�����һ�´�һ������ɡ�\n");
        }
        else if (a > 0.96 * b)
        {
            printf("O(��_��)O ����Ŭ�������ֻ���СһЩ��\n");
        }
        else
        {
            printf("������������Ѿ��ǳ��ӽ����ˡ�\n");
        }
    }
}

void JudgeWrongEng(int a, int b)   //a �ǲ������� b �����ϵͳ����
{
    if (a > b)
    {
        if (a > 1.5 * b)
        {
            printf("Umm�� It's too big. Why not try a little number?\n");
        }
        else if (a < 1.04 * b)
        {
            printf("(��o��) Just a little bigger. Come on !\n");
        }
        else
        {
            printf("^o^Cool! It's very very close.\n");
        }
    }
    else
    {
        if (a < 0.5 * b)
        {
            printf("It's not very close to the answer, try again~\n");
        }
        else if (a > 0.96 * b)
        {
            printf("O(��_��)O Still a little smaller. hold on!\n");
        }
        else
        {
            printf("Very very close! Continue! Continue! Continue!\n");
        }
    }
}

void JudgeRightChi(void)   //a �ǲ������� b �����ϵͳ����
{
    //  ��������������ɲ�ͬ����ף��䡣
    int a = 0;
    srand((int)time(0));
    a = rand() % 4 + 1;
    switch (a)
    {
        case 1:
            printf("�ɵ�Ư������¶��ˡ�\n");
        case 2:
            printf("��ϲ�㣬С���ѡ����������\n");
        case 3:
            printf("�ᣡ�𰸾��������\n");
        case 4:
            printf("���ƣ�����������\n");
    }
}

void JudgeRightEng(void)   //a �ǲ������� b �����ϵͳ����
{
    int a = 0;
    srand((int)time(0));
    a = rand() % 4 + 1;
    switch (a)
    {
        case 1:
            printf("Perfect! You have guessed the right answer!\n");
        case 2:
            printf("Congratulations! you have the answer on target!\n");
        case 3:
            printf("Good job! \n");
        case 4:
            printf("How smart you are! It is the right answer.\n");
    }
}

int Judgepri(int gue, int anw)    //a �ǲ������� b �����ϵͳ����
{
    int a[N] = {0}, b[N] = {0};
    int i = 0, j = 0, s = 0, t = 0;
    // ���������ֵĲ�ͬλ�ֱ𴢴������������С�
    a[0] = gue / 1000;
    b[0] = anw / 1000;
    for (i = 1; i < 4; ++i)
    {
        gue = gue - a[i - 1] * pow_10(4 - i);
        anw = anw - b[i - 1] * pow_10(4 - i);
        a[i] = gue / pow_10(3 - i);
        b[i] = anw / pow_10(3 - i);
    }
    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            if (a[i] == b[j])
            {
                ++t;
            }
        }
    }
    for (i = 0; i < 4; ++i)
    {
        if (a[i] == b [i])
        {
            ++s;
            --t;
        }
    }
    printf("%dA%dB\n",s, t);
    if (s == 4 && t == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pow_10(int a)
{
    int sum = 1;
    for (; a > 0; a--)
    {
        sum = sum * 10;
    }
    return sum;
}
