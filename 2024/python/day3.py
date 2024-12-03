import sys
import re

def fun(file_name):
    try:
        with open(file_name, 'r') as file:
            input = file.read()
            # print(input)
            regex = r"mul\(\d{1,3},\d{1,3}\)"

            f = re.findall(regex, input)
            print(f)
            
            result = 0
            for el in f:
                m = re.findall("\d{1,3}", el)
                print(m)
                result += int(m[0]) * int(m[1])
                
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