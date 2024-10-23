import sys

def fun(file_name):
    try:
        with open(file_name, 'r') as file:
            tab = []
            s = 0
            for line in file:
                # print(line.strip())
                if line.strip() == "":
                    if s != 0:
                        tab.append(s)
                        s = 0
                    continue
                s += int(line.strip())
                
            if s != 0:
                tab.append(s)

            tab.sort()
            # print(f"Tab: {tab}")
            max3num = sum(tab[-3:])
            print(f"Sum of max 3 numbers: {max3num}")

    except FileNotFoundError:
        print(f"File {file_name} not found.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python day1.py <file_name>")
    else:
        fun(sys.argv[1])