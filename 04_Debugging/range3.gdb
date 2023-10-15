set pagination off
b 26 if ((i - start) / step >= 28 && (i - start) / step <= 35)
command 1
    printf "@@@ %d %d %d %d\n", start, stop, step, i
    cont
end

run
quit