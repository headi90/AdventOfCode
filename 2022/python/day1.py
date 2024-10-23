import sys

def fun(file_name):
    try:
        with open(file_name, 'r') as file:
            max = 0
            sum = 0
            for line in file:
                # print(line.strip())
                if line.strip() == "":
                    if sum != 0:
                        if sum > max:
                            max = sum
                        sum = 0
                    continue
                sum += int(line.strip())
                
            print(f"Max number: {max}")

    except FileNotFoundError:
        print(f"File {file_name} not found.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python day1.py <file_name>")
    else:
        fun(sys.argv[1])