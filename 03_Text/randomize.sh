TIME_TO_SLEEP=$1
if [ -z $"$TIME_TO_SLEEP" ]
then
    TIME_TO_SLEEP=0
fi
TEXT="`cat`"
TMPFILE="`mktemp`"
X=$((0))
Y=$((0))
for ((i=0; $i<${#TEXT}; i++))
do
    PARAM="`/bin/echo -ne $"${TEXT:$i:1}" | od -An -v -t uC`"
    if ((PARAM == 10))
    then
        Y=$(($Y+1))
        X=0
    else
        X=$(($X+1))
        if ((PARAM != 32))
        then
            echo "$PARAM $X $Y" >> $TMPFILE
        fi
    fi
done
tput clear
cat $TMPFILE | shuf | while read line
do
    CODE="`echo $line | cut -d ' ' -f 1`"
    CODE=$(($CODE))
    X="`echo $line | cut -d ' ' -f 2`"
    X=$(($X))
    Y="`echo $line | cut -d ' ' -f 3`"
    Y=$(($Y))
    VAR=$(printf \\$(printf '%03o' $"$CODE"))
    tput cup $Y $X; echo $VAR
    sleep $TIME_TO_SLEEP
done
rm -f $TMPFILE
tput cup $(($Y+1)) 0