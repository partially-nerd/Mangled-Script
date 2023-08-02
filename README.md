# Mangled-Script
A hackable transpiler (trans-compiler) for C++ and the Mangled-Script format making use of &lt;regex>, including handy functions like io::input, fs::writeFile, and FString

# Installation
Install the transpiler with `chmod +x ./language/install.sh; ./language/install.sh`
* Note: Ensure that your shell sources `/etc/environment/`` *
## Dependencies:
- astyle
- g++ & gcc
- a GNU/Linux based operating system (windows ports will be released soon)

# Documentation
## Boilerplate
```lua
import core

function main() -> int

end
```

## Demo
```lua
import core

function main() -> int
    sum = 0.0
    for i : Range(3)
        number = io::input("Enter a number: ").toNum()
        sum += number
    end for
    avg = sum / 3
    io::print(FString("The average of the numbers is #"),{avg})
    return 0
end function
```
Transpiles to:
```c++
#include "core.h++"
int main()
{
    Num sum = 0.0;
    for(auto i : Range(3))
    {
        Num number = io::input("Enter a number: ").toNum();
        sum += number;
    };
    Num avg = sum / 3;
    io::print(FString("The average of the numbers is #"), {avg});
    return 0;
};
```

## How it works
- Indentation doesn't matter
- Automatically identify variable types
    - For Num type, the number must be in x.y format
    - For String, the value must be enclosed in double quotes
    - The rest are perfectly identified, and converted to proper types * Even in for auto loops *
- Automatically add semi-colons at the end of required-lines
- Formatted Strings (FString)
- String class, and Num class for useful operations like string comparisons with ==, number ^2
- An interator based Range
- Automatic round bracketting in while statements, if statements, and for statements
- Lua-like syntax. End codeblocks with `end`. All characters (not \n) after the end statement are ignored

## Transpiler
- transpile demo.ms with `ms.sh demo.ms` (just log the transpiled file)
- transpile demo.ms with `ms.sh demo.ms outfile` (save the transpiled file as outfile.c++)
- transpile and run demo.ms with `ms.sh demo.ms outfile run` (save the transpiled file as outfile.c++, and compile outfile.c++ with g++ and run the compiled binary)
