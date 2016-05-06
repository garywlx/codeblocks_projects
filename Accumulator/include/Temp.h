#ifndef TEMP_H
#define TEMP_H


class Temp
{
    public:
        Temp();
        static void Reset();
        static unsigned int GetSum();
        void init();
        virtual ~Temp();

    protected:

    private:
         static unsigned int N;
         static unsigned int Sum;
         unsigned int m_val;
};

#endif // TEMP_H
