import sys

def fun(file_name):
    try:
        with open(file_name, 'r') as file:
            score = 0
            lines = []
            i = 0
            for line in file:
                # print(line.strip())
                i += 1
                lines.append(set(line.strip()))
                
                if i % 3 == 0:
                    # & operator on two sets return common part of the sets
                    c1 = (lines[0]&lines[1])
                    c2 = (lines[1]&lines[2])
                    common_element = (c1&c2).pop()
                    lines.clear()
                    if(common_element.isupper()):
                        # ord transfers character to the ASCII value
                        val = ord(common_element) - ord('A') + 27
                    else:
                        val = ord(common_element) - ord('a') + 1
                    score += val
        print(f"Score: {score}")
        
    except FileNotFoundError:
        print(f"File {file_name} not found.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python day1.py <file_name>")
    else:
        fun(sys.argv[1])