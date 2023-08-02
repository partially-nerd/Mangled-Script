#include "libms/core.h++"
using namespace std;

string regex_replacify(string replace_what, string replace_by, string replace_in){
    regex regex_rep(replace_what, regex_constants::multiline);
    string replaced;
    // regex_replace(back_inserter(replaced), replace_in.begin(), replace_in.end(),
    //               regex_rep, replace_by);
    replaced = regex_replace(replace_in, regex_rep, replace_by, regex_constants::match_default);
    return replaced;
}

int main(int argc, char const *argv[])
{
    // Load File
    string file = fs::readFile((string)argv[1]).getValue();
    // Interpret File
    string replace_what[] = {
        "^\\s*import\\s(.*)$",
        "^\\s*([a-zA-Z]+\\s\=\\s\".*\")$",
        "^\\s*([a-zA-Z]+\\s\=\\s[0-9]+\.[0-9]+)$",
        "^\\s*([a-zA-Z]+\\s\=\\s.*)$",
        "^\\s*if\\s(.*\\s\=\=\\s.*)$",
        "^\\s*for\\s(.*\\s\:\\s.*)$",
        "^\\s*function\\s([a-zA-Z]\(.*\)\\s\-\>\\s.*)$",
        "^\\s*while\\s(.*)$",
        "^\\s*(end.*)$",
        "^\\s*\n+$",
        "^\\s*([^\#].*[^\;\.\{])$",
    };
    string replace_by[] = {
        "#include \"$1.h++\"",
        "String $1;",
        "Num $1;",
        "auto $1;",
        "if\($1\){",
        "for\(auto $1\){",
        "auto $1{",
        "while\($1\){",
        "};",
        "\n",
        "$1\;"
    };
    int size = *(&replace_what + 1) - replace_what;
    for (int i = 0; i < size; i++)
    {
        file = regex_replacify(replace_what[i], replace_by[i], file);
    }
    // Print Interpreted
    io::print(file);
    // Write Interpreted File
    if (argc < 3)
    {
        return 0;
    }
    if(argv[2] != NULL){
        // Write Interpreted File
        io::print(argv[2]);
        fs::writeFile((string) argv[2] + ".c++", file);
        io::shell((string) "astyle --style=allman " + argv[2] + ".c++");
        fs::removeFile((string) argv[2] + ".c++.orig");
    }
    // Run Interpreted File
    if (argc < 4){
        return 0;
    }
    if(argv[3] != NULL){
        if(strcmp(argv[3], "run") == 0){
            string command = (string) "g++ " + argv[2] + ".c++ -I $HOME/.ms/libms/ -o " + argv[2] + ".out";
            io::print("Running: \e[31m\e[4m"+command+"\e[0m\e[0m");
            io::shell(command);
            command = (string) "./" + argv[2] + ".out";
            io::print("Running: \e[31m\e[4m"+command+"\e[0m\e[0m");
            io::print("\e[31m\e[4mOutput:\e[0m\e[0m");
            io::shell(command);
        }
    }
    return 0;
}