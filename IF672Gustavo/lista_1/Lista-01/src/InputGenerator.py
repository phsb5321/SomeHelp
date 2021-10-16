from random import randint
inpu_file = open("input_file.txt", "a")
possible_inputs = ["[", "]", "(", ")"]
number_of_inputs = 3000

inpu_file.write("{}\n".format(number_of_inputs))
for i in range(0, number_of_inputs):
    for j in range(0, randint(1, 128)):
        random_char = randint(0, len(possible_inputs) - 1)
        new_input = possible_inputs[random_char]
        inpu_file.write(new_input)
    inpu_file.write("\n")
