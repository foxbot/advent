# this takes absurdly long to run, 1m55s on my machine
# hist grows to over 138k elements wide.. should look into better solution

with open('01_machine.in', 'r') as f:
    lines = f.readlines()

x = 0
y = None
hist = [0]

while y is None:
    for line in lines:
        if line[0] == '+':
            x += int(line[1:])
        elif line[0] == '-':
            x -= int(line[1:])
        if x in hist:
            y = x
            break
        hist.append(x)

print(y)