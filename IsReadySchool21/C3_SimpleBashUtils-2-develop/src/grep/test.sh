#!/bin/bash
file_test_s21_cat="1.txt 2.txt"
declare -a flags=( "-h" "-l" "-i" "-c" "-n" "-v" "-s" "-o")
declare -a flags_one=( "-h" "-l" "-i" "-c" "-n" "-v" "-s" "-o" "-f" "-e")
VSEGO=0
FALSE=0
TRUE=0

for fg in ${flags[@]}; do
	for fg1 in ${flags[@]}; do
grep  $fg $fg1 -e HELLO -f q.txt $file_test_s21_cat >> test1
./s21_grep  $fg $fg1 -e HELLO -f q.txt $file_test_s21_cat >> test2
if diff test1 test2
then
	echo "$fg $fg1 -e -f true"
	((TRUE++))
	((VSEGO++))
else
	echo "$fg $fg1 -e -f false"
	((FALSE++))
	((VSEGO++))
fi
rm -rf test1 test2
			done
done

for fg in ${flags[@]}; do
	for fg1 in ${flags[@]}; do
grep  $fg $fg1  HELLO  $file_test_s21_cat >> test1
./s21_grep  $fg $fg1 HELLO $file_test_s21_cat >> test2
if diff test1 test2
then
	echo "$fg $fg1 true"
	((TRUE++))
	((VSEGO++))
else
	echo "$fg $fg1 false"
	((FALSE++))
	((VSEGO++))
fi
rm -rf test1 test2
			done
done

for fg in ${flags_one[@]}; do
grep  $fg  HELLO  1.txt >> test1
./s21_grep  $fg  HELLO 1.txt  >> test2
if diff test1 test2
then
	echo "$fg  true"
	((TRUE++))
	((VSEGO++))
else
	echo "$fg  false"
	((FALSE++))
	((VSEGO++))
fi
rm -rf test1 test2
done

echo ////////////////ERROR/////////////////
grep  -g  HELLO  1.txt >> test1
./s21_grep  -g  HELLO 1.txt  >> test2
if diff test1 test2
then
	echo "nevernii flag:  true"
	((TRUE++))
	((VSEGO++))
else
	echo "nevernii flag:  false"
	((FALSE++))
	((VSEGO++))
fi
rm -rf test1 test2

grep  -e  HELLO  d.txt >> test1
./s21_grep  -e  HELLO d.txt  >> test2
if diff test1 test2
then
	echo "not file error: true"
	((TRUE++))
	((VSEGO++))
else
	echo "not file error:  false"
	((FALSE++))
	((VSEGO++))
fi
rm -rf test1 test2

grep  -f  HELLO  d.txt >> test1
./s21_grep  -f  HELLO d.txt  >> test2
if diff test1 test2
then
	echo "not file error: true"
	((TRUE++))
	((VSEGO++))
else
	echo "not file error:  false"
	((FALSE++))
	((VSEGO++))
fi
rm -rf test1 test2

grep  -v  HELLO  d.txt >> test1
./s21_grep  -v  HELLO d.txt  >> test2
if diff test1 test2
then
	echo "not file error: true"
	((TRUE++))
	((VSEGO++))
else
	echo "not file error:  false"
	((FALSE++))
	((VSEGO++))
fi
rm -rf test1 test2
echo "True: $TRUE"
echo "False: $FALSE"
echo "NUMBER: $VSEGO"