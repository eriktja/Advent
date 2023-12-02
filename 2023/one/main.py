test_case_1 = """1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet"""

test_case_2 = """two1nine
eightwothree
abcone2threexyz
xtwone3four
4nineeightseven2
zoneight234
7pqrstsixteen"""


num_dict = {
    "one": 1,
    "two": 2,
    "three": 3,
    "four": 4,
    "five": 5,
    "six": 6,
    "seven": 7,
    "eight": 8,
    "nine": 9
}

def first_task(input_string):
    arr = input_string.split("\n")
    numbers = []

    for word in arr:
        start = ""
        end = ""

        for i in range(len(word)-1):
            if (word[i].isdigit() and start == ""):
                start = word[i]
            if (word[len(word)- (i+1)].isdigit() and end == ""):
                end = word[len(word)-(i+1)]
        s = int(f"{start}{end}")
        numbers.append(s)

    print(sum(numbers))


def isNumber(input, start, end):
    return num_dict.get(input[start:end])
    

def second_task(input_string):
    arr = input_string.split("\n")
    numbers = []

    for word in arr:
        for i in range(len(word)-1):
            con = None
            start = 0
            end = len(word)
            first = ""
            last = ""
            while (con == None and last == ""):
                if word[end-1].isdigit():
                    last = word[end-1]
                if start == end:
                    start = 0
                    end -= 1
                con = isNumber(word, start, end)
                start += 1
            if (last == ""):
                last = con
            con = None
            while (con == None and first == ""):
                if word[start].isdigit():
                    first = word[start]
                if start == end-1:
                    start += 1
                    end = len(word)
                con = isNumber(word, start, end)
                end -= 1
            
            if first == "":
                first = con
        a = f"{first}{last}"
        numbers.append(a)

        print(sum(numbers))

if __name__ == "__main__":
    with open("input.txt") as f:
        input = f.read()
        second_task(test_case_2)