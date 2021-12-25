#!/bin/bash
##
# This script tests if your program passes our test cases.
#

# Number of test cases and source file name.
NUMS=4
HW=hw1_3
CPP_SRC="./${HW}.cpp"
JAVA_SRC="./${HW}.java"

echo ""
echo "========== Testing $HW =========="

if [[ -f "$CPP_SRC" && -f "$JAVA_SRC" ]]
then
    echo "ERROR:: You have both C++ and Java source files."
    echo "        We need only one source file."
    exit 1
elif [ -f "$CPP_SRC" ]; then
    SRC="$CPP_SRC"
    EXE="./${HW}"
	LANG=CPP
elif [ -f "$JAVA_SRC" ]
then
    SRC="$JAVA_SRC"
	EXE="${HW}"
	LANG=Java
else
    echo "ERROR:: source file does not exist."
    exit 1
fi


INPUT=./input/
OUTPUT=./output/
ANSWER=./answer/
MY_RESULT=./my_result/


# Check if test cases exist.
if [ ! -d "$INPUT" ]; then
    echo "$INPUT does not exit."
#        exit 1
fi


if [ ! -d "$OUTPUT" ]; then
    echo "$OUTPUT does not exit."
#        exit 1
fi


# Cleanup previous test results if they exist.
rm -rf $EXE.class
rm -rf $EXE
rm -rf $ANSWER
rm -rf $MY_RESULT


# Compile the source program
if [ $LANG = "CPP" ]
then
	/usr/bin/g++ -o $EXE -std=c++17 $SRC &> /dev/null
	if ! test -f "$EXE"
	then
		echo "ERROR:: Compilation failed!!!"
 		exit 1
	fi
else
	/usr/bin/javac $SRC &> /dev/null
	if ! test -f "$EXE.class"
	then
		echo "ERROR:: Compilation failed!!!"
 		exit 1
	fi
fi


# Run and test one by one.
cp -r $OUTPUT $ANSWER
mkdir $MY_RESULT

counter=0;
scount=0;
fcount=0;
while [ $counter -lt $NUMS ]
do
    if [ $counter -lt 10 ]
    then
        oname="$OUTPUT/output0$counter.txt"
        aname="$ANSWER/ans0$counter.txt"
        iname="$INPUT/input0$counter.txt"
        rname="$MY_RESULT/result0$counter.txt"
    else
        oname="$OUTPUT/output$counter.txt"
        aname="$ANSWER/ans$counter.txt"
        iname="$INPUT/input$counter.txt"
        rname="$MY_RESULT/result0$counter.txt"

    fi
    cat $oname | tr -d " \t\n\r" > $aname
    
    tname="$MY_RESULT/my_tmp_result.txt"
    rm -f $tname
	
	if [ $LANG = "CPP" ]
	then
		./$EXE < $iname > $tname
	else
		/usr/bin/java $EXE < $iname > $tname
	fi
    
    cat $tname | tr -d " \t\n\r" > $rname
    
    # Compare your result and correct answer
    diff $aname $rname &> /dev/null
    
    PASS=$?
    if [ $PASS -eq 0 ]
    then
        echo "    Test case $counter Passed"
        scount=$((scount+1))
    else
        echo "    Test case $counter Failed"
        fcount=$((fcount+1))
    fi

    counter=$((counter+1))
done

echo "-----------------------"
echo "    $scount PASSED"
echo "    $fcount FAILED"
echo "-----------------------"
echo ""

# Cleanup test results if they exist.
rm -rf $EXE.class
rm -rf $EXE
rm -rf $ANSWER
rm -rf $MY_RESULT
 
