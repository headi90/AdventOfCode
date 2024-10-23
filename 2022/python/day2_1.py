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
                
                # A - Rock
                # B - Paper
                # C - Scissors
                
                # X - lose
                # Y - draw
                # Z - win
                
                if p1 == 'A':
                    if p2 == 'X':
                        p2n = 'C'
                    elif p2 == 'Y':
                        p2n = 'A'
                        score += 3
                    elif p2 == 'Z':
                        p2n = 'B'
                        score += 6
                elif p1 == 'B':
                    if p2 == 'X':
                        p2n = 'A'
                    elif p2 == 'Y':
                        p2n = 'B'
                        score += 3
                    elif p2 == 'Z':
                        p2n = 'C'
                        score += 6
                elif p1 == 'C':
                    if p2 == 'X':
                        p2n = 'B'
                    elif p2 == 'Y':
                        p2n = 'C'
                        score += 3
                    elif p2 == 'Z':
                        p2n = 'A'
                        score += 6
                
                if p2n == 'A':
                    score += 1
                elif p2n == 'B':
                    score += 2
                else:
                    score += 3
                        
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