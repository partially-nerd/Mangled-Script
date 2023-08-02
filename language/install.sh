clear
language/reCompileTranspiler.sh
rm -rf $HOME/.ms/
rm $HOME/.local/bin/ms.sh
mkdir $HOME/.ms/
cp -r language/* $HOME/.ms/
chmod +x $HOME/.ms/*
rm $HOME/.ms/install.sh
mv $HOME/.ms/ms.sh $HOME/.local/bin/ms.sh
if grep -q "$HOME/.local/bin" /etc/environment
then
echo "$HOME/.local/bin is aready in path"
else
    read -p "Do you wish to add $HOME/.local/bin/ to path (y/n): " confirm && [[ $confirm == [yY] || $confirm == [yY][eE][sS] ]] || exit 1
    confirm=$(echo "$confirm" | tr '[:lower:]' '[:upper:]')
    if [ $confirm HOME/.local/bin== "Y" ] || [ $confirm == "YES" ]
    then
        command="PATH=$HOME/.local/bin:$PATH"
        su -c "echo $command >> /etc/environment"
    fi
fi
echo -e "\e[31m\e[4mInstallation Successful\e[0m\e[0m"
echo -e "\e[31m\e[4mMake sure your shell sources /etc/environment\e[0m\e[0m"