#this is script for reducing duplicate operate easily

clear
echo "finish input by Enter"
read s
quesionname="$(echo -e "${s}" | tr -d '[ ]')"
echo $quesionname.cc
touch $quesionname.cc

echo "input description"
cclass=class
fenjie='/*'
echo "$fenjie" >>$quesionname.cc
while read line;do
    if [ "${line%% *}" = "$cclass" ] 
    then
        break
    fi
    echo $line >>$quesionname.cc
done
unset fenjie
fenjie='*/' 
echo "$fenjie">>$quesionname.cc

echo -e "\n">>$quesionname.cc
cinclude="#include\"head.h\""
echo $cinclude >>$quesionname.cc
echo $line >>$quesionname.cc

end='};'
i=1
while read line;do
    i=$[$i+1]
    echo $line >>$quesionname.cc
    if [ "${line:-2}" == $end ]
    then 
        break
    fi
    if [ $i == "3" ]
    then
        classname=${line%%(*}
        classname=${classname##* }
    fi
done

main="int main() \n
{\n
    \t	Solution s;\n
    \t	s.$classname();\n
    \t	return 0;\n
}"
echo -e "\n">>$quesionname.cc
echo -e $main>> $quesionname.cc

echo ${quesionname} >>makefile
echo "end all input operation"
