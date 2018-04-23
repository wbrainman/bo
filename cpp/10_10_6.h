#ifndef C_10_10_6
#define C_10_10_6


class Move {
    private:
        double x;
        double y;
    public:
        Move(double a = 0, double b = 0);
        ~Move();
        void showmove() const;
        Move add(const Move & m);
        void reset();

};

#endif
