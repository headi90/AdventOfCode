import sys

def fun(file_name):
    try:
        with open(file_name) as f:
            lines = [line.rstrip('\n') for line in f]

        first_part_read = False
        stack_lines = []
        stacks = [""]*9
        for i, line in enumerate(lines):
            if not first_part_read:
                if len(line.strip()) == 0:
                    first_part_read = True
                    stack_lines = lines[0:i-1]
                    index_line = lines[i-1]
                    indexes = []
                    for k, val in enumerate(index_line):
                        if val.isnumeric():
                            indexes.append(k)
                    for li in stack_lines:
                        for l, idx in enumerate(indexes):
                            if li[idx].isalpha():
                                stacks[l] += (li[idx])
                    print(stacks)
                    continue
            else:
                print(line)
                _, how_many, _, src, _, dst = line.split()
                how_many = int(how_many)
                src = int(src)
                dst = int(dst)
                # print(f"{how_many}, {src}, {dst}")
                
                dest = []
                s = stacks[src-1][0:how_many]
                print(s)
                dest += s
                dest += stacks[dst-1]
                stacks[dst-1] = dest
                stacks[src-1] = stacks[src-1][how_many:]
                print(stacks)

        print("Result:")
        for s in stacks:
            print(s[0], end="")
        print()

    except FileNotFoundError:
        print(f"File {file_name} not found.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python day1.py <file_name>")
    else:
        fun(sys.argv[1])