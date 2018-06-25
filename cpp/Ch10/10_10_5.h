//10_10_5.h


typedef struct _customer {

    char fullname[35];
    double payment;
}customer;

typedef customer Item;

class Stack {
    public:
        Stack();
        ~Stack();
        bool isFull();
        bool isEmpty();
        bool push(const Item &item);
        bool pop(Item &item);
        void show();
    private:
        enum {MAX = 10};
        int m_top;
        Item m_item[MAX];
        double m_sum;
};



