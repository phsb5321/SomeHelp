#! /usr/bin/python3
# %%
import os
import timeit
paths = ['mine', 'internet']


if __name__ == '__main__':
    def run_file(path):
        HERE = os.path.join(os.getcwd(), path)
        inFile = f"{HERE}/../in.txt"
        outFile = f"{HERE}/../out/{path.upper()}.txt"

        os.system(f"g++ {HERE}/main.cpp")
        os.system(f'./a.out <{inFile}> {outFile}')
        time = timeit.timeit(lambda: os.system(
            f'./a.out <{inFile}> {outFile}'), number=100)
        print(f'{path.upper()} took about: {time} seconds')
        return time

    times = []
    for x in paths:
        new_time = run_file(x)
        times.append(new_time)

    average = sum(times) / len(times)

    print('')
    print(
        f'MINE represents {round(times[0]/ average, 2)}% of the time INTERNET took to run')
