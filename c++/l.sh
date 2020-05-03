#this is script for reducing duplicate operate easily

clear
echo "input title"
read s
quesionname="$(echo -e "${s}" | tr -d '[ ]')"
urltail="$(echo -e "${s#*.}" | tr 'A-Z' 'a-z' | tr ' ' '-')"
urltail=${urltail#*-}
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


unset cinclude
cinclude="#include\"head.h\""
	echo $cinclude >>$quesionname.h
	echo $line >>$quesionname.h

num=1
while read line;do
	if [ $num -eq 3 ] ;then 
		funcname=${line#* }
		funcname=${funcname%(*}
	fi
	if [ "$line" != '};' ]; then
	echo -e $line >>$quesionname.h
	else 
		break
	fi
	num=$(($num+1))
done
	echo -e $line >>$quesionname.h

unset cinclude
classname=$quesionname
cinclude="#include\"$classname.h\""
maintext="int main() \n
{\n
\t	Solution s;\n
\t	s.${funcname}();\n
\t	return 0;\n
}"
echo -e $cinclude>>$quesionname.cc
echo -e $maintext >> $quesionname.cc
echo -e $quesionname >> makefile
echo "end input"

url="https://leetcode.com/problems/"$urltail'/'
echo -e "[$quesionname]($url)">>README.md
