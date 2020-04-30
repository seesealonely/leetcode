#this is script for reducing duplicate operate easily

clear
echo "提示信息"
read s
quesionname="$(echo -e "${s}" | tr -d '[ ]')"
echo $quesionname.h
touch $quesionname.h 
echo $quesionname.cc
touch $quesionname.cc
echo "end Enter"

cclass=class
fenjie='/*'
echo "$fenjie" >>$quesionname.h
echo "$fenjie" >>$quesionname.cc
while read line;do
	if [ "${line%% *}" = "$cclass" ] 
	then
	break
	fi
	echo $line >>$quesionname.h 
	echo $line >>$quesionname.cc
done
unset fenjie
fenjie='*/' 
echo $fenjie>>$quesionname.h
echo $fenjie>>$quesionname.cc

classname=$quesionname
cinclude="#include"${classname#*.}.h""
maintext="int main() \n
{\n
\t	Solution s;\n
\t	s.${classname#*.}();\n
\t	return 0;\n
}"
echo $quesionname>>$quesionname.cc
echo -e $maintext >> $quesionname.cc
unset cinclude
cinclude="#include\"head.h\""
	echo $cinclude >>$quesionname.h
	echo $line >>$quesionname.h
while read line;do
	echo $line >>$quesionname.h
done

ms
read makefile>ms
echo $ms
unset cinclude
cinclude=$quesionname
echo ${cinclude#*.} >>makefile
echo "end input"
