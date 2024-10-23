import sys

def fun(file_name):
    try:
        with open(file_name, 'r') as file:
            score = 0
            for line in file:
                # print(line.strip())
                half1 = set(line.strip()[0:int(len(line)/2)])
                half2 = set(line.strip()[int(len(line)/2):])
                
                # print(f"{half1}{half2}")
                # & operator on two sets return common part of the sets
                common_element = (half1&half2).pop()
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