#include <string>

using namespace std;
class Golf
{
	private:
		string fullname;
		int handicap;
	public:
		Golf();
		Golf(const string name, int hc);
		~Golf();
		Golf &selfGolf(Golf &g);
		void setGolf();
		void show();
};
