#include <iostream>
#include <regex>
#include <string.h>
#include <math.h>

using namespace std;

class Num
{
private:
    double value;

public:
    // Constructors
    Num(int val)
    {
        this->value = (double)val;
    }
    Num(string val)
    {
        this->value = stod(val);
    }
    Num(double val)
    {
        this->value = val;
    }
    // Converters
    double getValue()
    {
        return this->value;
    }
    // Operators
    Num operator+(Num a)
    {
        return this->value + a.getValue();
    }
    Num operator+(double a)
    {
        return this->value + a;
    }

    void operator+=(Num a)
    {
        this->value += a.getValue();
    }
    void operator+=(double a)
    {
        this->value += a;
    }

    void operator-=(Num a)
    {
        this->value -= a.getValue();
    }
    void operator-=(double a)
    {
        this->value -= a;
    }

    void operator*=(Num a)
    {
        this->value *= a.getValue();
    }
    void operator*=(double a)
    {
        this->value *= a;
    }

    void operator/=(Num a)
    {
        this->value /= a.getValue();
    }
    void operator/=(double a)
    {
        this->value /= a;
    }

    Num operator-(Num a)
    {
        return this->value - a.getValue();
    }
    Num operator-(double a)
    {
        return this->value - a;
    }

    Num operator*(Num a)
    {
        return this->value * a.getValue();
    }
    Num operator*(double a)
    {
        return this->value * a;
    }

    Num operator/(Num a)
    {
        return this->value / a.getValue();
    }
    Num operator/(double a)
    {
        return this->value / a;
    }

    bool operator==(Num a)
    {
        return this->value == a.getValue();
    }
    bool operator==(double a)
    {
        return this->value == a;
    }

    bool operator>=(Num a)
    {
        return this->value >= a.getValue();
    }
    bool operator>=(double a)
    {
        return this->value >= a;
    }

    bool operator<=(Num a)
    {
        return this->value <= a.getValue();
    }
    bool operator<=(double a)
    {
        return this->value <= a;
    }

    bool operator<(Num a)
    {
        return this->value < a.getValue();
    }
    bool operator<(double a)
    {
        return this->value < a;
    }

    bool operator>(Num a)
    {
        return this->value > a.getValue();
    }
    bool operator>(double a)
    {
        return this->value > a;
    }
    Num operator^(Num a)
    {
        return pow(this->value, a.getValue());
    }
    Num operator^(double a)
    {
        return pow(this->value, a);
    }
}; // Number class

class String
{
private:
    string value;

public:
    // Constructors
    String(string val)
    {
        this->value = val;
    }
    String(const char *val)
    {
        this->value = (string)val;
    }
    String(int val)
    {
        this->value = to_string(val);
    }
    String(Num val)
    {
        this->value = to_string(val.getValue());
    }
    String(double val)
    {
        this->value = to_string(val);
    }
    // Converters
    Num toNum()
    {
        return Num(this->value);
    }
    string getValue()
    {
        return this->value;
    }
    // Operators
    String operator+(String a)
    {
        return String(this->value + a.getValue());
    }
    String operator+(string a)
    {
        return String(this->value + a);
    }
    String operator+(Num a)
    {
        return String(this->value + to_string(a.getValue()));
    }
    bool operator==(String a)
    {
        return not strcmp(this->value.c_str(), a.getValue().c_str());
    }
}; // String class

String FString(string a, vector<Num> args)
{
    for (auto arg : args)
    {
        a = regex_replace(a, (regex) "\#", to_string(arg.getValue()), regex_constants::format_first_only);
    }
    return a;
} // Formatted String

String FString(string a, vector<String> args)
{
    for (auto arg : args)
    {
        a = regex_replace(a, (regex) "\#", arg.getValue(), regex_constants::format_first_only);
    }
    return a;
} // Formatted String

class Range
{
    int x, y, z;

public:
    Range(int x)
    {
        this->x = 0;
        this->y = x;
        this->z = 1;
    }
    Range(int x, int y)
    {
        this->x = x;
        this->y = y;
        this->z = 1;
    }
    Range(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    struct Iterator
    {
        Iterator(int val, int inc) : val{val}, inc{inc} {}
        Iterator &operator++()
        {
            val += inc;
            return *this;
        }

        int operator*() const { return val; }
        friend bool operator!=(const Iterator &a, const Iterator &b) { return a.val < b.val; }

    private:
        int val, inc;
    };

    Iterator begin() { return Iterator(x, z); }
    Iterator end() { return Iterator(y, z); }
}; // Range