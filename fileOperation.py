# Open the file in read mode
with open('text.txt', 'r') as file:
    # Read the file line by line
    firstLine = file.readline()

    if ("bear" in firstLine):
        print("First line contains the word 'bear'")
    else:
        print("First line doesn't contain the word 'bear'")
