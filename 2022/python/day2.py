import sys

def fun(file_name):
    try:
        with open(file_name, 'r') as file:
            score = 0
            for line in file:
                # print(line.strip())
                
                p1 = line.strip().split(' ')[0]
                p2 = line.strip().split(' ')[1]
                print(f"him {p1} - me {p2}")

                if p2 == 'X':
                    score += 1
                elif p2 == 'Y':
                    score += 2
                else:
                    score += 3

                if p1 == 'A':
                    if p2 == 'X':
                        score += 3
                    if p2 == 'Y':
                        score += 6
                elif p1 == 'B':
                    if p2 == 'Y':
                        score += 3
                    if p2 == 'Z':
                        score += 6
                else:
                    if p2 == 'Z':
                        score += 3
                    if p2 == 'X':
                        score += 6
                        
            print(f"Score {score}")

    except FileNotFoundError:
        print(f"File {file_name} not found.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python day1.py <file_name>")
    else:
        fun(sys.argv[1])