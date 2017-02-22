def greet(name):
    print("Hello, " + name + ". Good morning!")
    return 10

def my_temp(name, x, y):
    print("Hello, " + name + ". Good morning!")
    print "x, y:", x, y
    return (100, 200)

def my_temp2(name):
    print("Hello, " + name + ". Good morning!")

greet("Bhagavan")

t = greet("Bhagavan")
print "return value t:", t


a, b = my_temp("Bhagavan", 20, 30)
print a, b
exit(1)
