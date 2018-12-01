with open('01_machine.in', 'r') as f:
    lines = f.readlines()

x = 0
y = None
hist = dict()

while y is None:
    for line in lines:
        if line[0] == '+':
            x += int(line[1:])
        elif line[0] == '-':
            x -= int(line[1:])
        
        if x in hist:
            y = x
            break
        hist[x] = 1

print(y)