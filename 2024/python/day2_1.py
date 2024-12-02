import sys

def check(line):
    diffs = []
    for i in range(1, len(line)):
        diffs.append(line[i-1] - line[i])
    return (all(e > 0 for e in diffs) or all(e < 0 for e in diffs)) and all(abs(e) >= 1 for e in diffs) and all(abs(e) <=3 for e in diffs)

def fun(file_name):
    try:
        with open(file_name, 'r') as file:
            result = 0
            for line in file:
                # print(line.strip())
                line_vals = [int(v) for v in line.strip().split()]
                # print(line_vals)

                if (check(line_vals)):
                    result += 1
                    continue
                
                # Bruteforce - remove value by value from line and check if it's valid
                for i in range(len(line_vals)):
                    new_line = line_vals[:i] + line_vals[i+1:]
                    if (check(new_line)):
                        result += 1
                        break

            print(f"Result: {result}")

    except FileNotFoundError:
        print(f"File {file_name} not found.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python day1.py <file_name>")
    else:
        fun(sys.argv[1])
