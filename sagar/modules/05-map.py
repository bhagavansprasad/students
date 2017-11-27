items = [1, 2, 3, 4, 5]
squared = []
for i in items:
    squared.append(i**2)
print(squared)


squared = list([x**2 for x in items])
print(squared)
