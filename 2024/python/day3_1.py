import sys
import re

def fun(file_name):
    try:
        with open(file_name, 'r') as file:
            input = file.read()
            # print(input)
            regex1 = r"mul\(\d{1,3},\d{1,3}\)"
            regex2 = r"do\(\)"
            regex3 = r"don't\(\)"

            regex = re.compile( '|'.join( [regex1, regex2, regex3] ) )
            # print(regex)
            
            f = re.findall(regex, input)
            # print(f)
            
            f1=[]
            don_t = False
            for i in range(len(f)):
                if f[i] == "don't()":
                    don_t = True
                    continue
                if f[i] == "do()":
                    don_t = False
                    continue
                
                if don_t == False:
                    f1.append(f[i])
            
            # print(f1)
            result = 0
            for el in f1:
                m = re.findall("\d{1,3}", el)
                # print(m)
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