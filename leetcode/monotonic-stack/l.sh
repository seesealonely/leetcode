#this is script for reducing duplicate operation easily

clear
echo "input title,end using Enter"
read s
quesionname="$(echo -e "${s}" | tr -d '[ ]')"
urltail="$(echo -e "${s#*.}" | tr 'A-Z' 'a-z' | tr ' ' '-')"
urltail=${urltail#*-}
echo $quesionname.cc
touch $quesionname.cc
echo "end Enter"

cclass='class'
fenjie='/*'
echo "$fenjie" >>$quesionname.cc
while read line;do
	if [ "${line%% *}" = "class" ] 
	then
	break
	fi
	echo $line >>$quesionname.cc
done
unset fenjie
fenjie='*/' 
echo $fenjie>>$quesionname.cc


unset cinclude
cinclude="#include\"head.h\""
	echo $cinclude >>$quesionname.cc

echo $line>>$quesionname.cc
num=1
while read line;do
	if [ "$line" != '};' ]; then
	echo -e $line >>$quesionname.cc
	else 
		break
	fi
	if [ $num -eq 2 ] ;then 
		funcname=${line#* }
		funcname=${funcname%(*}
	fi
	num=$(($num+1))
done
	echo -e $line >>$quesionname.cc

unset cinclude
classname=$quesionname
cinclude="#include\"$classname.h\""
maintext="int main() \n
{\n
\t	Solution s;\n
\t	s.${funcname}();\n
\t	return 0;\n
}"
#echo -e $cinclude>>$quesionname.cc
echo -e $maintext >> $quesionname.cc
echo -e $quesionname >> makefile
echo "end input"

url="https://leetcode.com/problems/"$urltail'/'
echo -e "[$quesionname]($url)\n">>../README.md
