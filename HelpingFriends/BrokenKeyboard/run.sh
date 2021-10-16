#! /usr/bin/bash
chmod +x ./make.py
python3 ./make.py 
find . -name "*.out" -type f -delete
