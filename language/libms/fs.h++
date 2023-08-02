#include <iostream>
#include <fstream>
using namespace std;

namespace fs
{
    String readFile(String path)
    {
        string line;
        static string lines = "";
        ifstream File(path.getValue());
        while (getline(File, line))
        {
            lines += line + "\n";
        }
        File.close();
        return String(lines);
    }

    void writeFile(String path, String content)
    {
        ofstream File(path.getValue());

        File << content.getValue();

        File.close();
    }

    void makeFolder(String path)
    {
        system(FString("mkdir #", {path}).getValue().c_str());
    }

    void removeFolder(String path)
    {
        system(FString("rm -rf #", {path}).getValue().c_str());
    }

    void removeFile(String path)
    {
        system(FString("rm #", {path}).getValue().c_str());
    }
} // namespace fs