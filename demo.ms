// install the transpiler with `chmod +x ./language/install.sh; ./language/install.sh`
// transpile this file with `ms.sh demo.ms` (just log the transpiled file)
// transpile this file with `ms.sh demo.ms outfile` (save the transpiled file as outfile.c++)
// transpile and run this file with `ms.sh demo.ms outfile run` (save the transpiled file as outfile.c++, and compile outfile.c++ with g++ and run the compiled binary)
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