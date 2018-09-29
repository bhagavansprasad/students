def is_prime(n):
    i = 2

    while (i < n):
        if (n % i == 0):
            break
        i += 1

    if (i == n):
        return 1
    else:
        return 0

n = 7
if (is_prime(n)):
    print n, "Prime"
else:
    print n, "NOT Prime"



