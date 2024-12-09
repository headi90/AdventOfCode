import sys

def print_map(input):
    for i in range(0, len(input)):
        for j in range(0, len(input[0])):
            print(input[i][j], end="")
        print()
    print()
    
def map_to_file(input):
    with open("map.txt", 'w') as mapa:
        for i in range(0, len(input)):
            for j in range(0, len(input[0])):
                mapa.write(input[i][j])
            mapa.write('\n')
        mapa.write('\n')
        
def find_start(input, start_char='^'):
    for i in range(0, len(input)):
        for j in range(0, len(input[0])):
            if input[i][j] == start_char:
                return i, j

def fun(file_name):
    try:
        input = []
        with open(file_name, 'r') as file:
            for line in file:
                input.append([c for c in line.strip()])
        
        # print_map(input)
        start_x, start_y = find_start(input)
        print(f"Start: {start_x, start_y}")
        
        directions = [
            (-1, 0), # up
            (0, 1),  # right
            (1, 0),  # down
            (0, -1)  # left
        ]
        
        dir = 0

        x = start_x
        y = start_y
        size_x = len(input)
        size_y = len(input[0])
        
        visited = set()
        cnt = 0
        
        with open("dbg.txt", 'w') as f:
            while True:
                input[x][y] = 'X'
                visited.add((x, y, dir))
                
                n_x = x + directions[dir][0]
                n_y = y + directions[dir][1]
                
                if n_x < 0 or n_x >= size_x or n_y < 0 or n_y >= size_y:
                    print(f"end: {x,y}")
                    break
                s = f"n_x: {n_x}, n_y: {n_y}, input: {input[n_x][n_y]}, dir: {dir}\n"
                # print(s)
                f.write(s)
                
                potential_dir = (dir + 1) % len(directions)
                potential_x = x + directions[potential_dir][0]
                potential_y = y + directions[potential_dir][1]
                
                if (potential_x, potential_y, potential_dir) in visited:
                    cnt += 1
                    print(f"cnt: {cnt}")
                    print(f"Loop detected: {potential_x, potential_y, potential_dir}")
                    print(f"Current position: {x, y, dir}")
                
                if input[n_x][n_y] == '#':
                    dir = (dir + 1) % len(directions)
                    f.write("\nrotate\n")
                    # print_map(input)
                    continue
                x = n_x
                y = n_y
                
            print_map(input)
            map_to_file(input)
        
        print(f"cnt: {cnt}")

    except FileNotFoundError:
        print(f"File {file_name} not found.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python day1.py <file_name>")
    else:
        fun(sys.argv[1])