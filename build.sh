
# clear
rm err.log
touch err.log
g++ -std=c++11 main.cpp 2>&1 | tee err.log
if [ -s err.log ]; then
    echo ERROR: Check err.log
else
    ./a.exe
fi