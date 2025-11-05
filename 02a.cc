#include <iostream>
#include <vector>
using namespace std;

struct Complex
{
    int a, b;
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
    Complex result = {0,0};
    Complex A;
    cin >> A.a >> A.b;
    for (int i = 0; i < 3; i++)
    {
        result = result*result/Complex{10,10} + A;
    }
    cout << '[' << result.a << ',' << result.b << ']' << endl;
}