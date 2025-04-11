def ArrayChallenge(strArr):
    N = int(strArr[0])
    stations = [list(map(int, s.split(":"))) for s in strArr[1:]]

    for start in range(N):
        gas = 0
        valid = True
        for i in range(N):
            index = (start + i) % N
            gas += stations[index][0]
            if gas < stations[index][1]:
                valid = False
                break
            gas -= stations[index][1]

        if valid:
            return start + 1

    return "Impossible"


print(ArrayChallenge(["4", "3:1", "2:2", "1:2", "0:1"]))  # Output: 1
print(ArrayChallenge(["4", "0:1", "2:2", "1:2", "3:1"]))  # Output: 4
print(ArrayChallenge(["4", "1:1", "2:2", "1:2", "0:1"]))  # Output: 4
