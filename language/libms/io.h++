#include <iostream>
#include <cstring>
using namespace std;

namespace io
{
    void print(String text, bool newline = 1)
    {
        if (newline == 1)
        {
            cout << text.getValue() << endl;
        }
        else
        {
            cout << text.getValue();
        }
    }
    void shell(String command)
    {
        system(command.getValue().c_str());
    }
    String input(String text)
    {
        string val;
        print(text, 0);
        cin >> val;
        return String(val);
    }
} // namespace io
