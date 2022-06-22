#!/bin/bash

find ./ ! -regex '.*/\..*' -type f | wc -l
