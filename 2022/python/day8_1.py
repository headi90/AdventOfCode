import sys

def fun(file_name):
    try:
        with open(file_name, 'r') as file:
            trees = []
            for line in file:
                trees.append([int(c) for c in line.strip()])

            results = []
            for i in range(1,len(trees)-1):
                for j in range(1,len(trees[0])-1):
                    tree = trees[j][i]
                    vertical = [r[i] for r in trees]
                    horizontal = trees[j]

                    up = vertical[0:j]
                    down = vertical[j+1:]
                    left = horizontal[0:i]
                    right = horizontal[i+1:]
                    
                    res = 1
                    ru = 1
                    rd = 1
                    rl = 1
                    rr = 1

                    # print(f"tree: {tree}")
                    # print(f"u: {up}")
                    # print(f"u1: {up[::-1]}")
                    # print(f"d: {down}")
                    # print(f"d1: {down[::-1]}")
                    # print(f"l: {left}")
                    # print(f"l1: {left[::-1]}")
                    # print(f"r: {right}")
                    # print(f"r1: {right[::-1]}")
                    
                    for idx, el in enumerate(up[::-1]):
                        ru = idx + 1
                        # print(f"ru:{ru}")
                        if el >= tree:
                            break
                    for idx, el in enumerate(down):
                        rd = idx + 1
                        # print(f"rd:{rd}")
                        if el >= tree:
                            break
                    for idx, el in enumerate(left[::-1]):
                        rl = idx + 1
                        # print(f"rl:{rl}")
                        if el >= tree:
                            break
                    for idx, el in enumerate(right):
                        rr = idx + 1
                        # print(f"rr:{rr}")
                        if el >= tree:
                            break
                    res = ru*rd*rl*rr
                    # print(f"res: {res}")
                    results.append(res)
                    # print()

            # Add trees from the edge
            # print(results)
            print(f"Result: {max(results)}")
        
    except FileNotFoundError:
        print(f"File {file_name} not found.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python day1.py <file_name>")
    else:
        fun(sys.argv[1])