import sys

def fun(file_name):
    try:
        with open(file_name) as f:
            line = f.read()
            # print(line)
        
        for i in range(13,len(line)):
            code = line[i-13:i+1]
            s = set(code)
            # print(f"{i}, {code} -> {s}")
            if len(code) == len(s):
                print(f"Found: {i+1}")
                break

    except FileNotFoundError:
        print(f"File {file_name} not found.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python day1.py <file_name>")
    else:
        fun(sys.argv[1])