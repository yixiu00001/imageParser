
path="/home/yx/fr/project/imageParser"
#ls "${path}/lfw" |while read line
#do
#	num=`ls "${path}/lfw/${line}" |wc -l`
#	if [ $num -gt 20 ];then
#		echo $line,${num}
#	fi
#done

#cut -d ","  -f1 "${path}/res" >t1
#cat t1 |while read line
#do
#	ls "${path}/lfw/${line}">t2
#	num=0
#	cat t2|while read name
#	do
#		if [ $num  -lt 20 ];then
#			echo ${name}
#			mkdir "${path}/trainSet/${line}"
#			cp "${path}/lfw/$line/${name}" "${path}/trainSet/${line}"
#			#$num=$(($num+1))
#			num=`expr $num + 1`
#		fi
#	done
#done

num=0
ls "${path}/trainSet/" |while read line
do
	ls "${path}/trainSet/${line}" |while read name
	do
		echo "${path}/trainSet/${line}/${name}" >>list
		echo ${num}>>label

	done
	num=`expr ${num} + 1 `
done
