#! /usr/bin/python3
# %%
import os
import time
HERE = f"{os.getcwd()}/mine"
print(HERE)

# %%
def FuncDelAOut():
    try:
        if os.path.exists(f"{HERE}/a.out"):
            os.remove(f"{HERE}/a.out")
        if os.path.exists(f"{HERE}/../a.out"):
            os.remove(f"{HERE}/../a.out")
    except Exception:
        print("Not Found!")

# %%
inFile = f"{HERE}/../in.txt"
outFile = f"{HERE}/../out/MINE.txt"

# %%
os.system(f"g++ {HERE}/main.cpp")
now = time.time()
os.system(f"./a.out <{inFile}> {outFile}")
time = time.time() - now
print(f"MINE Took About: {time} seconds")
FuncDelAOut()
