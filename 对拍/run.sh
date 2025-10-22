g++ input.cpp -o input
g++ hacked.cpp -o hacked 
g++ std.cpp -o std

for ((cnt = 1;;cnt++))
do 
    echo -ne "\r${cnt}th hack"

    ./input > data.in
    ./hacked < data.in > data.result
    ./std < data.in > data.out

    if ! cmp -s data.out data.result
    then 
        echo -e "\nhack success"
        break
    fi
done