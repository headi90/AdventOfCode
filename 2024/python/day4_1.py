import sys

def fun(file_name):
    try:
        grid = [
                ((0, 0), (1, 1), (2, 2)), # diagonal
                ((0, 2), (1, 1), (2, 0)), # other diagonal
                ]
        input = []
        with open(file_name, 'r') as file:
            for line in file:
                input.append([c for c in line.strip()])
        size = len(input)
        count = 0
        xmas = ["MAS", "SAM"]

        for i in range(0, size):
            for j in range(0, size):
                words = []
                for dir in grid:
                    w = ""
                    for x,y in dir:
                        i_ = i + x
                        j_ = j + y
                        if i_ < size and j_ < size:
                            w += input[i_][j_]
                    words.append(w)
                # print(f"i:{i} j:{j} w:{words}")
                if words[0] in xmas and words[1] in xmas:
                    count += 1
        print(f"Result = {count}")

    except FileNotFoundError:
        print(f"File {file_name} not found.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python day1.py <file_name>")
    else:
        fun(sys.argv[1])