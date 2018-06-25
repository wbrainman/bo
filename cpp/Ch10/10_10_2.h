#include <string>

using namespace std;
class Qerson {
	private:
		static const int LIMIT = 25;
		string lname;
		char fname[LIMIT];
	public:
		Qerson() {lname = ""; fname[0] = '\0';};
		Qerson(const string &ln, const char* fn = "default");
		~Qerson();
		void Show() const;
		void FormalShow() const;

};
