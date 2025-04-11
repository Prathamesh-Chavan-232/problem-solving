def StringChallenge(strParam):
    challenge_token = "sl9nq3f15e4"

    result = ""
    current_char = strParam[0]
    letterCount = 1
    for i in range(1, len(strParam)):
        if strParam[i] == current_char:
            letterCount += 1
        else:
            result += str(letterCount) + current_char
            current_char = strParam[i]
            letterCount = 1

    result += str(letterCount) + current_char
    result += challenge_token

    for i in range(0, len(result)):
        if (i + 1) % 3 == 0:
            result = result[:i] + "X" + result[i + 1 :]

    return result


def main():
    test_cases = [
        "aabbcde",
        "wwwbbw",
        "aaabbbccc",
        "xyxyxy",
        "abcdefg",
        "zzzz",
    ]

    additional_tests = []

    print("Example Test Cases:")
    print("-" * 50)
    for i, test in enumerate(test_cases, 1):
        result = StringChallenge(test)
        print(f"Test {i}: Input = '{test}'")
        print(f"Output = '{result}'")


if __name__ == "__main__":
    main()
