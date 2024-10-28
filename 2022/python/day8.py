import sys

def fun(file_name):
    try:
        with open(file_name, 'r') as file:
            trees = []
            for line in file:
                trees.append([int(c) for c in line.strip()])

            sum=0
            for i in range(1,len(trees)-1):
                for j in range(1,len(trees[0])-1):
                    tree = trees[j][i]
                    vertical = [r[i] for r in trees]
                    horizontal = trees[j]
                    # print((f"{i} {j}"))
                    # print(tree)
                    # print(vertical)
                    # print(horizontal)
                    up = vertical[0:j]
                    down = vertical[j+1:]
                    left = horizontal[0:i]
                    right = horizontal[i+1:]
                    if(max(up) < tree or max(down) < tree or max(left) < tree or max(right) < tree):
                        sum+=1
                        
            # Add trees from the edge
            edges = 2 * len(trees) + 2 * len(trees[0]) - 4
            sum += edges
            print(f"Result: {sum}")
        
    except FileNotFoundError:
        print(f"File {file_name} not found.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python day1.py <file_name>")
    else:
        fun(sys.argv[1])