#include <iostream>
#include <vector>
#include <string>

class Simpleop
{
private:
    std::vector<int> num;

public:
    Simpleop()
    {
        num.resize(1);
        num[0] = 0;
    }
    Simpleop(std::string s)
    {
        for (int i = s.length() - 1; i >= 0; i--)
        {
            num.push_back(s[i] - '0');
        }
    }
    Simpleop(std::vector<int> n)
    {
        this->num = n;
    }

    void print()
    {
        for (int i = num.size() - 1; i >= 0; i--)
        {
            std::cout << num[i];
        }
        std::cout << "\n";
    }

    void add_zero(int mul) 
    {
        for (int i = 0; i < mul; i++) 
        {
            this->num.insert(this->num.begin(), 0);
        }
    }

    Simpleop operator * (int mul)
    {
        std::vector<int> v;

        int t = 0;
        for (int i = 0; i < this->num.size(); i++)
        {
            v.push_back((this->num[i] * mul + t) % 10);
            t = (this->num[i] * mul + t) / 10;
        }
        if (t != 0)
            v.push_back(t);

        Simpleop x(v);
        return x;
    }

    Simpleop operator + (Simpleop Sum)
    {
        std::vector<int> v;
        if (this->num.size() >= Sum.num.size())
        {
            v.resize(this->num.size());
            Sum.num.resize(this->num.size());
        }
        else
        {
            v.resize(Sum.num.size());
            this->num.resize(Sum.num.size());
        }
        int y = 0;
        for (int i = 0; i < std::max(this->num.size(), Sum.num.size()); i++)
        {
            v[i] = (this->num[i] + Sum.num[i] + y) % 10;
            y = (this->num[i] + Sum.num[i] + y) / 10;
        }
        if (y > 0)
            v.push_back(y);
        Simpleop x(v);
        return x;
    }

    Simpleop operator * (Simpleop Mul)
    {
        Simpleop x;
        if (this->num.size() >= Mul.num.size()) 
        {
            Simpleop B(this->num);
            for (int i = 0; i < Mul.num.size(); i++) 
            {
                Simpleop y = B * Mul.num[i];
                y.add_zero(i);
                x = x + y;
            }
        }
        else {
            Simpleop B(Mul.num);
            for (int i = 0; i < this->num.size(); i++) 
            {
                Simpleop y = B * this->num[i];
                y.add_zero(i);
                x = x + y;
            }
        }
        return x;
    }
};

int main()
{
    std::string a, b;
    std::cin >> a >> b;
    Simpleop num1(a);
    Simpleop num2(b);
    Simpleop num3 = num1 * num2;
    num3.print();
}