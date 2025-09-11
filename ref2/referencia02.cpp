#include <iostream>

using namespace std;

int & large (int& a, int& b)
{
    if (a > b)
        return a;
    else
        return b;
}
int main()
{
    int m = 10 , n = 12;
    large (m , n) = 10000;
    cout <<"m and n are " << m <<" "<<n<<endl;

    return 0;
}
