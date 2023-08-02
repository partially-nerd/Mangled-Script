clear
g++ language/main.c++ -o language/compilation/main.out
if [ $1 == "-r" ]
then
    echo -e "\nPassing arguments: $2 $3 $4\n\e[31m\e[4mOutput:\e[0m\e[0m"
    language/compilation/main.out $2 $3 $4
fi