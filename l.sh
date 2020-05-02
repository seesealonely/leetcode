#this is script for reducing duplicate operate easily

clear
echo "input title"
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
cinclude="#include\"$classname.h\""
maintext="int main() \n
{\n
\t	Solution s;\n
\t	s.${classname#*.}();\n
\t	return 0;\n
}"
echo -e $cinclude>>$quesionname.cc
echo -e $maintext >> $quesionname.cc
unset cinclude
cinclude="#include\"head.h\""
	echo $cinclude >>$quesionname.h
	echo $line >>$quesionname.h
while read line;do
	if [ "$line" != '};' ]; then
	echo -e $line >>$quesionname.h
	else 
		break
	fi
done
	echo -e $line >>$quesionname.h

echo -e $quesionname >> makefile
echo "end input"
