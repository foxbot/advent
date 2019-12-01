# Day 1: fuel requirements calculator
#   notes - this isn't optimized for performance...
#       notably, we calculate module fuels twice (which includes a lot of int parsing)
#       i reckon this is pretty heavy on allocations with the use of generators as well


# --- part one ---
# algorithm:
#   fuel(module) = floor(module.mass / 3) - 2
#
# problem:
#   sum([module] -> fuel)

def read_input():
    with open('day01_data.txt', 'r') as f:
        return f.readlines()

def fuel(mass):
    return (mass // 3) - 2

def fuels(modules):
    for mass in modules:
        yield fuel(mass)

def modules():
    return map(int, read_input())

print('---part one---')
print(sum(fuels(modules())))

# --- part two ---
# algorithm:
#   total_fuel(module) = fuel(module) + fuel(fuel(module)) + ... + 0
#
# problem:
# sum([module] -> sum([fuel]))

def total_fuels(module_fuels):
    for module_fuel in module_fuels:
        f = module_fuel
        fuels = [f]
        while f > 0:
            f = fuel(f)
            fuels.append(f) if f > 0 else None
        yield fuels

print('---part two---')
total_fuels = total_fuels(fuels(modules()))
# total_fuels: [[fuel...], [fuel...], ...]
# sum each inner fuels, then sum the total fuels
print(sum(map(sum, total_fuels)))