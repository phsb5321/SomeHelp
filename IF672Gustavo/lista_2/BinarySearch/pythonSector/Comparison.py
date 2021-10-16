if __name__ == "__main__":
    comands = input().split()
    str_builder = ""

    number_of_elements = int(comands[0])
    number_of_queries = int(comands[1])

    array = input().split()
    for j in range(0, number_of_queries):
        element = str(input())
        if element in array:
            index = array.index(element)
            str_builder += "{}\n".format(index)
        else:
            str_builder += "{}\n".format(-1)

    inpu_file = open("PYTHON.txt", "w")
    inpu_file.write(str_builder)
