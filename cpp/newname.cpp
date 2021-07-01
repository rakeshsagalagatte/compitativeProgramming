#include <iostream> 
#include <string> 

using namespace std; 

void printInfo(string &s) { 
        cout << "length = " << s.length() << endl; 
        cout << "capacity = " << s.capacity() << endl; 
        cout << "max size = " << s.max_size() << endl; 
        cout << "---------" << endl; 
} 

int main(void) { 
        string TheString = "content"; 
        printInfo(TheString); 
        TheString.append("newWala",3,5);
        cout << TheString << endl;
        TheString.insert(4,"mansoon",3,2);   // contsoentWala 
        string sku;
        sku.assign(80,'A');
        string ToDo = "mansu nanu neenu";
        string last = "nan en ankondiya";
        ToDo.replace(2,2,last,6,8);
        string er   = "naknfksdnf sdmv aedvjnadv amvjaev aemvnev";
        er.erase(4,8);
        cout << TheString << endl << sku << endl << ToDo << endl << er << endl;

        string Drink = "A martini";
	string Needs = "Shaken, not stirred";
		
	cout << Drink << ". " << Needs << "." << endl;
	Drink.swap(Needs);
	cout << Drink << ". " << Needs << "." << endl;
        return 0; 
} 
