#include <string>

class Count 
{
	private:
		std::string	m_name;
		std::string	m_countNum;
		int 		m_fund;


	public:
		Count();
		Count(const std::string &name, const std::string &countNum, const int fund);
		~Count();
		void show();
		void deposite(const int in);
		void withdraw(const int out);
};

