with open('01_machine.in', 'r') as f:
    lines = f.readlines()

x = 0

for line in lines:
    if line[0] == '+':
        x += int(line[1:])
    elif line[0] == '-':
        x -= int(line[1:])

print(x)