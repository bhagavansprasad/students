def main():
    fd = open("input.txt", "r")

    print ("[")
    while(1):
        data = fd.readline()
        if (not data):
            break
        print ("[", end = "")
        for byte in data.split():
            #print ('"%c", ' % (byte), end="")
            print ('%c, ' % (byte), end="")
        print ("],", end = "")
        print ("")
    print ("]")



if (__name__ == "__main__"):
     main()

