import sys

def fun(file_name):
    try:
        with open(file_name, 'r') as file:
            rules_ended = False
            rules = []
            ok_pages = []
            pages = list(dict())
            for line in file:
                # print(line)
                
                if line == '\n':
                    rules_ended = True
                    continue

                if not rules_ended:
                    tmp = line.strip().split('|')
                    rules.append(tuple(int(x) for x in tmp))
                else:
                    tmp = line.strip().split(',')
                    page = dict()
                    for i, v in enumerate(tmp):
                        page[int(v)] = i
                    pages.append(page)

            print(f"Pages: {pages}")
            for page in pages:
                nok = False
                for first, second in rules:
                    # print(f"Checking rule {first} < {second}")
                    # print(f"Pages: {pages}")
                    if first in page and second in page:
                        if page[first] > page[second]:
                            # print(f"Rule {first} < {second} NOK.")
                            nok = True
                if not nok:
                    ok_pages.append(list(page.keys()))
                        
            print(f"Ok pages: {ok_pages}")
            
            sum = 0
            for page in ok_pages:
                sum += page[len(page)//2]
                
            print(f"Sum: {sum}")

    except FileNotFoundError:
        print(f"File {file_name} not found.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python day1.py <file_name>")
    else:
        fun(sys.argv[1])