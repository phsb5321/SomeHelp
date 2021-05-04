from random import randint

def generateInputFile():
    inpu_file = open("INPUT.txt", "w")
    iterations = 1
    max_number = 3000

    for i in range(0, iterations):
        num_elements = max_number
        num_queries = max_number
        array = [x for x in range(0, num_elements)]
        list_of_queries = [randint(-100, 100) for w in range(0, num_queries)]
        inpu_file.write("{} {}\n".format(num_elements, num_queries))
        inpu_file.write("{}\n".format(str(array)[1:-1].replace(",", "")))
        inpu_file.write("{}".format("\n".join(map(str, list_of_queries))))
        inpu_file.write("\n")


def generateOutPutCSV():
    outPutFile = open("OUTPUT.csv", "w")
    cppFile = open("CPP.txt", "r")
    pythonFile = open("PYTHON.txt", "r")
    input_file = open("INPUT.txt", "r")

    something = [input_file.readline() for x in range(0, 2)]

    line = "{},{},{}".format(input_file.readline(),
                             cppFile.readline(),
                             pythonFile.readline())

    while len(line) > 2:
        outPutFile.write(line.replace("\n", "") + "\n")
        line = "{},{},{}".format(input_file.readline(),
                                 cppFile.readline(),
                                 pythonFile.readline())


# generateInputFile()
generateOutPutCSV()
