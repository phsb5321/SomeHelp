#!/usr/bin/env python3
import os

HERE = os.path.dirname(os.path.realpath(__file__))


def FuncDelAOut():
    try:
        if os.path.exists(f"{HERE}/a.out"):
            os.remove(f"{HERE}/a.out")
    except:
        print("Not Found!")


inFile = f"{HERE}/../in.txt"
outFile = f"{HERE}/out/out.txt"

FuncDelAOut()
os.system("g++ main.cpp")
os.system(f"./a.out <{inFile}> {outFile}")
FuncDelAOut()

