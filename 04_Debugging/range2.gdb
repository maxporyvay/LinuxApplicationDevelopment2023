set pagination off
b 26 if i % 5 == 0
command 1
    printf "@@@ %d %d %d %d\n", start, stop, step, i
    cont
end

run
quit