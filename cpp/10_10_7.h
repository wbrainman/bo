#ifndef C_10_10_7
#define C_10_10_7

class Plorg {
    private:
        static const int MAX = 19;
        char m_name[MAX];
        int m_ci;
    public:
        Plorg();
        Plorg(char* name, int ci = 50);
        ~Plorg();
        void show();
};

#endif
