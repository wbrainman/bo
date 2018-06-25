#include <string>

class Sales
{
	private:
        enum {Quarters = 4};
        // static const int Quarters = 4;
		double m_sales[Quarters];
		double m_average;
		double m_max;
		double m_min;
	public:
		Sales();
		Sales(const double ar[], int n);
		~Sales();
		void setSales();
		void show() const;
//	private:
        double average();
        double max();
        double min();
};
