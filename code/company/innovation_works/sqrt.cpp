#include <iostream>
using std::cin;
using std::cout;
using std::endl;

const double ACCURACY = 0.001;

double get_sqrt(int n)
{
    double low = 0.0;
    double high = (double) n;
    double mid = (low + high) / 2;
    cout << "low\t\thigh\t\tmid" << endl;
    while (low - high <= ACCURACY)
    {
        cout << low <<"\t\t" << high << "\t\t" << mid << endl;
        double tmp = mid*mid - (double)n;
        if (tmp <= ACCURACY*ACCURACY && tmp >= ACCURACY*ACCURACY*(-1.0))
            return mid;
        else if (tmp > ACCURACY*ACCURACY)
            high = mid;
        else
            low = mid;
            
        mid = (low + high) / 2;
    }
    
    return -1.0;
}
int main()
{
    cout.precision(10);
    int n;
    cout << "input number: ";
    while (cin >> n)
    {
        cout << "sqrt of " << n << ": " << get_sqrt(n) << endl;
        cout << "--------------------" << endl;
        cout << "input number: ";
    }
    
    return 0;
}