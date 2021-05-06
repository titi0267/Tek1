#!/bin/bash

total=0
success=0
fail=0

function run_file() {
    local file=$1
    mysh="$(cat $file | ../../mysh 2>/dev/null)"
    mysh_err="$(cat $file | ../../mysh 2>&1)"
    mysh_ret=$(echo $?)

    tcsh="$(cat $file | tcsh 2>/dev/null)"
    tcsh_err="$(cat $file | tcsh 2>&1)"
    tcsh_ret=$(echo $?)

    if [ "$mysh" = "$tcsh" ] && [ "$mysh_err" = "$tcsh_err" ] && [ $mysh_ret -eq $tcsh_ret ]; then
        printf "\e[32mSUCCESS\e[0m\n"
        success=$((success + 1))
    else
        if ! [ "$mysh" = "$tcsh" ]; then
            printf "\e[31mFAIL : stdout is different\e[0m\n"
            echo "> "
            echo $mysh
            echo "< "
            echo $tcsh
        fi
        if ! [ "$mysh_err" = "$tcsh_err" ]; then
            printf "\e[31mFAIL : stderr is different \e[0m\n"
            echo "> "
            echo $mysh_err
            echo "< "
            echo $tcsh_err
        fi
        if ! [ $mysh_ret -eq $tcsh_ret ]; then
            printf "\e[31mFAIL : return is different ($mysh_ret / $tcsh_ret)\e[0m\n"
        fi
        fail=$((fail + 1))
    fi
    total=$((total + 1))
}

function main() {
    cd ./test_files
    export LANG=en_US.UTF-8

    for file in `ls`; do
        printf "File \e[33m$file\e[0m\n"
        run_file $file
        printf "\n"
    done

    printf "\e[1mResults\e[0m: Total\e[0m: \e[33m$total\e[0m - \e[32mSuccess\e[0m: \e[33m$success\e[0m - \e[31mFail\e[0m: \e[33m$fail\e[0m\n"
}

main