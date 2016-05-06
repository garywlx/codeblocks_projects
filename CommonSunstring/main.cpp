#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4
//程序缺陷1  没有设置第一次玩完游戏后继续的选项。
//程序缺陷2  儿童中文版  和成人英文版   难度没有差异。
//程序缺陷3  可以加入金币系统和经验系统。（每次猜对猜错加减金币，每次猜对加经验，经验越高，可以解锁的难度越高）
//程序缺陷4  文曲星模式中现在只能生成四位数，有待改成多种难度，而且可以自定义难度的形式。
//程序缺陷5  文曲星模式中，生成的数字不同位之间可能相同。

//  生成 底数 10 的 a 次幂。
int pow_10(int a);
//  随机生成一个在 a 到 b 内的数字。 a 是下限， b 是上限。
int Magicnumber(int a, int b);
//  读入玩家所猜入的数。 a 和 b 为该数字应满足的范围。a 是下限， b 是上限。
int GuessnumberChi(int a, int b);
int GuessnumberEng(int a, int b);
//  判断输入数字，是否正确。 a 是猜入数， b 是随机系统数。
int Judgenumber(int a, int b);
//  猜数错误， 根据错误答案与正确答案的偏差大小， 输出不同的错误提示。a 是猜入数， b 是随机系统数。
void JudgeWrongChi(int a, int b);
void JudgeWrongEng(int a, int b);
//  猜数正确，利用随机数的方式， 生成不同的祝贺语句。a 是猜入数， b 是随机系统数。
void JudgeRightChi(void);
void JudgeRightEng(void);
//  由于判断猜入数字和所生成数字相同位数。其中a 是猜入数， b 是随机系统数。
int Judgepri(int a, int b);
//  用于存放主程序中多次使用的读数，判断等语句。
void LongAboutMainChi(int a, int upp, int low);
void LongAboutMainEng(int a, int upp, int low);

int main()
{
    //选择游戏版本。1.英文版 2. 汉语版   （二者目前难度相同，尚待改进）
    printf("Choose edition.\n1. English and for adult\n2. 汉语 儿童版\n");
    char anwser1 = 0, anwser2 = 0;
    //anwser 1 和 anwser 2 用来判断输入是否合法， 若不合法，那么重新输入，直至合法为止。
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
        // 选择游戏模式   1、 普通猜数游戏    2、文曲星猜数游戏（游戏介绍在后面）    3、退出
        printf("Welcome to The Game of Guess Number\n");
        printf("1.Guess it as a whole number.\n");
        //  2 还有待修改，能够改成多难度的。
        printf("2.Guess it as some independent numbers.\n");
        printf("3.Exit.\n");
        printf("Your choose is : ");
        //防止错误输入
        anwser1 = getchar();
        anwser2 = getchar();
        for (;(anwser1 < '1' && anwser1 > '3') || anwser2 != '\n';)
            {
                while (anwser2 != '\n' && getchar() != '\n');
                printf("It seems that you have input something wrong.>_<\nPlease input again :");
                anwser1 = getchar();
                anwser2 = getchar();
            }
            //选择游戏难度
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
                    //根据玩家所选择的难度，生成指定数和对应程序
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
                //以下几行 printf 为文曲星猜数游戏游戏说明。
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
                        count++;// count 用于记录输入次数。
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
    // 中文儿童版
    else
    {
        int b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0, j = 0;
        int count = 0;
        char anwser = 0, m = 0;
        printf("\t欢迎您来到猜数游戏\n");
        printf("1.猜一个整数\n");
        //  2 还有待修改，能够改成多难度的。
        printf("2.文曲星\n");
        printf("3.退出\n");
        printf("选择一下吧 : ");
        anwser1 = getchar();
        anwser2 = getchar();
        for (;(anwser1 < '1' && anwser1 > '3') || anwser2 != '\n';)
            {
                while (anwser2 != '\n' && getchar() != '\n');
                printf("小朋友，你似乎没有按要求输入哦~\n请重新输入吧^_^ :");
                anwser1 = getchar();
                anwser2 = getchar();
            }
        switch (anwser1)
        {
            case '1':
                printf("1.简单难度(从1-100中猜数字)\n2.中等难度(从1-1000中猜数字)\n3.困难难度(从1-10000中猜数字)\n4.自定义~(不少于1，不多于10000)\n请告诉我，你的选择 :");
                anwser1 = getchar();
                anwser2 = getchar();
            for (;(anwser1 < '1' && anwser1 > '4') || anwser2 != '\n';)
            {
                while (anwser2 != '\n' && getchar() != '\n');
                printf("小朋友，你似乎没有按要求输入哦~\n请重新输入吧^_^ :");
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
                        printf("请输入上限 ：");
                        scanf("%d", &f);
                        printf("请输入下限 ：");
                        scanf("%d", &g);
                        e = Magicnumber(f, g);
                        LongAboutMainChi(e, f, g);
                        break;
                }
                break;
            case '2':
                printf("游戏介绍 ： 计算机将会随机生成一个4位数（包括0001 - 9999）\n");
                printf("            小朋友，你所需要做的也是输入一个四位数\n");
                printf("            比如：\n");
                printf("            计算机生成的数字是\n");
                printf("            4387\n");
                printf("            你所猜的数字是\n");
                printf("            4072\n");
                printf("            那么屏幕上将会显示一串字符\n");
                printf("            1A1B\n");
                printf("            因为电脑所生成的数字里有一个'4' 并且你所输入的数字中'4'恰好在正确的位置, 所以就会有一个 A.\n");
                printf("            同样的，电脑生成的数字里有一个'7', 然而你却并没有把7猜在正确的位置 ,所以有了一个 B.\n");
                printf("            如果电脑生成的数字是 6600, 同时你输入的数字是 6543, 那么提示就会是 1A1B.\n");
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
                        printf("你已经猜了%d次,要继续吗? Y/N",count);
                        anwser = getchar();
                        m = getchar();
                        for (;(anwser != 'Y' && anwser != 'y' && anwser != 'N' && anwser != 'n') || m != '\n';)
                        {
                            while (m != '\n' && getchar() != '\n');
                            printf("似乎小朋友你并没有按要求输入。\n再输入一次吧 ^_^:");
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
            count++;    //count  用于记录输入次数
            printf("你已经猜了%d次,要继续吗? Y/N",count);
            anwser = getchar();
            m = getchar();
            // 用于防止错误输入
            for (;(anwser != 'Y' && anwser != 'y' && anwser != 'N' && anwser != 'n') || m != '\n';)
            {
                while (m != '\n' && getchar() != '\n');
                printf("似乎小朋友你并没有按要求输入。\n再输入一次吧  ^_^:");
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

int Magicnumber(int a, int b)   //a 是下限， b 是上限。
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
    printf("猜一个数吧，小朋友:^_^");
    scanf("%d",&c);
    d = getchar();
    while (d != '\n' || c < a || c > b)
    {
        printf("似乎小朋友你并没有按要求输入。\n再输入一次吧 ^_^:");
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

int Judgenumber(int a, int b)  //a 是猜入数， b 是随机系统数。
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

void JudgeWrongChi(int a, int b)   //a 是猜入数， b 是随机系统数。
{
    //  在确定时错误输入后， 比较猜的数字大还是小。
    if (a > b)
    {
        //  确定数字猜得过大后， 根据偏离正确答案的程度， 给予不同提示。
        if (a > 1.5 * b)
        {
            printf("呃……小朋友，你猜的数字有点大。试一试小一点的数吧~\n");
        }
        else if (a < 1.04 * b)
        {
            printf("(⊙o⊙)只大了一点点哦~ 加油！加油！\n");
        }
        else
        {
            printf("^o^真棒！ 已经非常非常接近了！\n");
        }
    }
    else
    {
        //  确定数字猜得过小后， 根据偏离正确答案的程度， 给予不同提示。
        if (a < 0.5 * b)
        {
            printf("数字有点太小了，尝试一下大一点的数吧。\n");
        }
        else if (a > 0.96 * b)
        {
            printf("O(∩_∩)O 继续努力，数字还是小一些。\n");
        }
        else
        {
            printf("真聪明！数字已经非常接近答案了。\n");
        }
    }
}

void JudgeWrongEng(int a, int b)   //a 是猜入数， b 是随机系统数。
{
    if (a > b)
    {
        if (a > 1.5 * b)
        {
            printf("Umm… It's too big. Why not try a little number?\n");
        }
        else if (a < 1.04 * b)
        {
            printf("(⊙o⊙) Just a little bigger. Come on !\n");
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
            printf("O(∩_∩)O Still a little smaller. hold on!\n");
        }
        else
        {
            printf("Very very close! Continue! Continue! Continue!\n");
        }
    }
}

void JudgeRightChi(void)   //a 是猜入数， b 是随机系统数。
{
    //  利用随机数，生成不同的庆祝语句。
    int a = 0;
    srand((int)time(0));
    a = rand() % 4 + 1;
    switch (a)
    {
        case 1:
            printf("干得漂亮！你猜对了。\n");
        case 2:
            printf("恭喜你，小朋友。你真聪明。\n");
        case 3:
            printf("酷！答案就是这个。\n");
        case 4:
            printf("鼓掌！你真厉害！\n");
    }
}

void JudgeRightEng(void)   //a 是猜入数， b 是随机系统数。
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

int Judgepri(int gue, int anw)    //a 是猜入数， b 是随机系统数。
{
    int a[N] = {0}, b[N] = {0};
    int i = 0, j = 0, s = 0, t = 0;
    // 把两个数字的不同位分别储存在两个数组中。
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
