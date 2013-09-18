#include <iostream>
#include <string>
#include <cstdlib> // malloc
using std::cout;
using std::endl;
using std::string;

class Time
{
public:
    Time()
    {
        cout << "Time default constructor" << endl;
    }
    Time(int h, int m, int s, string n)
         : hour(h), min(m), sec(s), name(n)
    {
        cout << "Time constructor --> " << name << endl;
    }
    ~Time()
    {
        cout << "Time destructor --> " << name << endl;
    }

private:
    int hour;
    int min;
    int sec;
    string name;
};

int main()
{
    cout << "sizeof(Time)=" << sizeof(Time) << endl;
    cout << "---malloc/free---" << endl;
    Time *t1;
    t1 = (Time *)malloc(sizeof(Time));
    free(t1);

    cout << endl;
    cout << "---new/delete---" << endl;
    Time *t2;
    t2 = new Time(0, 0, 0, "t2");
    delete t2;

    cout << endl;
    cout << "---new[]/delete[]---" << endl;
    Time *t3;
    t3 = new Time[3];
    delete[] t3;

    return 0;
}