for((i = 0;;i++)) do
    echo $i
    python3 gen.py > input
    ./btree < input > out1
    ./brute < input > out2
    diff out1 out2 || break
done