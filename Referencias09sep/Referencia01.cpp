#include <iostream>

using namespace std;
int sum (int a, int& b)
{
    int s = a + b;
    a++;
    b++;
    return s;
}
int main()
{
    int m = 10 , n = 12;
    cout << sum(m,n) << "\n";
    cout <<"m and n are " << m <<" "<<n<<endl;

    return 0;
}
