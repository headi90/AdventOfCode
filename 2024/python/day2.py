import sys

def fun(file_name):
    try:
        with open(file_name, 'r') as file:
            for line in file:
                print(line.strip())

    except FileNotFoundError:
        print(f"File {file_name} not found.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python day1.py <file_name>")
    else:
        fun(sys.argv[1])

