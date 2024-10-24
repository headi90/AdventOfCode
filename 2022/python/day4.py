import sys

def fun(file_name):
    try:
        with open(file_name, 'r') as file:
            score = 0
            for line in file:
                # print(line.strip())
                elf1 = line.strip().split(',')[0]
                elf2 = line.strip().split(',')[1]
                
                elf1min = int(elf1.split('-')[0])
                elf1max = int(elf1.split('-')[1])
                elf2min = int(elf2.split('-')[0])
                elf2max = int(elf2.split('-')[1])
                                
                if (elf1min <= elf2min and elf1max >= elf2max) or (elf2min <= elf1min and elf2max >= elf1max):
                    score += 1
                    print(f"{elf1min} {elf1max} {elf2min} {elf2max}")
                    
        print(f"score: {score}")
        
    except FileNotFoundError:
        print(f"File {file_name} not found.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python day1.py <file_name>")
    else:
        fun(sys.argv[1])