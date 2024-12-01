import sys

def fun(file_name):
    try:
        with open(file_name, 'r') as file:
            left_table = []
            right_table = []
            for line in file:
                # print(line.strip())
                
                left = line.strip().split()[0]
                right = line.strip().split()[1]

                left_table.append(int(left))
                right_table.append(int(right))

            left_dict = dict.fromkeys(left_table)

            for k in left_dict:
                left_dict[k] = right_table.count(k)

            # print(left_dict)
            similarity_score = 0
            
            for l in left_table:
                similarity_score += l * left_dict[l]

            # print(f"l: {left_table}")
            # print(f"r: {right_table}")
            print(f"similarity_score: {similarity_score}")

    except FileNotFoundError:
        print(f"File {file_name} not found.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python day1.py <file_name>")
    else:
        fun(sys.argv[1])