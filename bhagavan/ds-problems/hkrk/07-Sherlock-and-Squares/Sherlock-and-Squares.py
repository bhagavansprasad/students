import math

def squares(a, b):
    count = 0
    t = int (math.sqrt(a))
    if (t*t < a):
        t = t + 1
        
    while(True):
        sq = t*t
        if (sq >= a and sq <= b):
            count = count + 1
        else:
            break;

        t = t + 1

	return count


def main():
	print (squares(3, 9))
	print (squares(17, 24))

if (__name__ == "__main__"):
	main()

