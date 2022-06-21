#!/bin/zsh
git checkout main
git remote add Day08 git@github.com:EpitechIT2020/B-CPE-100-STG-1-1-cpoolday08-timothe.coniel.git
git fetch Day08
git checkout -b Day08 Day08/master
git checkout CPoolDays
git merge Day08 --allow-unrelated-histories
mkdir Day08
