#!/bin/bash
file_test_s21_cat="test_file/text1.txt"
declare -a flags=("-e" "-t" "-n" "-v" "-b" "-s")
VSEGO=0
FALSE=0
TRUE=0
flags_l="--number-nonblank --number --squeeze-blank"
flags_ls="-b -n -s"
for fg in ${flags[@]}; do
	for fg1 in ${flags[@]}; do
		for fg2 in ${flags[@]}; do
			for fg3 in ${flags[@]}; do
cat $fg $fg1 $fg2 $fg3 $file_test_s21_cat >> test1
./s21_cat $fg $fg1 $fg2 $fg3 $file_test_s21_cat >> test2
if diff test1 test2
then
	echo "$fg $fg1 $fg2 $fg3 true"
	((TRUE++))
	((VSEGO++))
else
	echo "$fg $fg1 $fg2 $fg3 false"
	((FALSE++))
	((VSEGO++))
fi
rm -rf test1 test2
				done
			done
	done
done



cat $flag_l $file_test_s21_cat >> test1
./s21_cat $flag_ls $file_test_s21_cat >> test2
if diff test1 test2
then
for fl in $flags_l; do
echo "$fl "
done
echo "true"
((TRUE++))
((VSEGO++))
else
echo "$flag_l false"
((FALSE++))
((VSEGO++))
fi
rm -rf test1 test2




cat -bnets $file_test_s21_cat >> test1
./s21_cat -bnets $file_test_s21_cat >> test2
if diff test1 test2
then
echo "-bnefs true"
((TRUE++))
((VSEGO++))
else
echo "-bnefs false"
((FALSE++))
((VSEGO++))
fi
rm -rf test1 test2

cat file_test_s21_cat >> test1
./s21_cat file_test_s21_cat >> test2
if diff test1 test2
then
echo "true"
((TRUE++))
((VSEGO++))
else
echo "false"
((FALSE++))
((VSEGO++))
fi
rm -rf test1 test2

for fg in ${flags[@]}; do

cat $fg $file_test_s21_cat >> test1
./s21_cat $fg $file_test_s21_cat >> test2
if diff test1 test2
then
	echo "$fg true"
	((TRUE++))
	((VSEGO++))
else
	echo "$fg false"
	((FALSE++))
	((VSEGO++))
fi
rm -rf test1 test2

done

for fg in ${flags[@]}; do


echo ////////////////ERROR///////////////

cat $fg file_test_s21_cat >> test1
./s21_cat $fg file_test_s21_cat >> test2
if diff test1 test2
then
	echo "not file error: true"
	((TRUE++))
	((VSEGO++))
else
	echo "not file error: false"
	((FALSE++))
	((VSEGO++))
fi
rm -rf test1 test2

done

echo ////////////////ERROR///////////////
cat -r $file_test_s21_cat >> test1
./s21_cat -r $file_test_s21_cat >> test2
if diff test1 test2
then
	echo "-r true"
	((TRUE++))
	((VSEGO++))
else
	echo "-r false"
	((FALSE++))
	((VSEGO++))
fi
rm -rf test1 test2


echo "True: $TRUE"
echo "False: $FALSE"
echo "NUMBER: $VSEGO"