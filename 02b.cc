#include <iostream>
#include <vector>
using namespace std;

struct Complex
{
    long long a, b;
    Complex operator+(Complex other)
    {
        return {a+other.a,b+other.b};
    }
    Complex operator-(Complex other)
    {
        return {a-other.a,b-other.b};
    }
    Complex operator*(Complex other)
    {
        return {a*other.a-b*other.b,a*other.b+b*other.a};
    }
    Complex operator/(Complex other)
    {
        return {a/other.a,b/other.b};
    }
};

int main()
{
    Complex A;
    cin >> A.a >> A.b;

    int goodPoints = 0;

    for (int i = A.a; i <= A.a + 1000; i += 1)
    {
        for (int j = A.b; j <= A.b + 1000; j += 1)
        {
            bool goodPoint = true;
            Complex t = {i,j};
            Complex result = {0,0};
            for (int i = 0; i < 100 && goodPoint; i++)
            {
                result = result*result/Complex{100000,100000} + t;
                goodPoint = abs(result.a) <= 1000000 && abs(result.b) <= 1000000;
            }
            if (goodPoint)
            {
                ++goodPoints;
                cout << '#';
            } 
            else cout << '.';
        }
        cout << endl;
    }
    

    cout << goodPoints << endl;
}