def chunk_data(srcfile, cs):
    fd = open(srcfile, "r")

    data = fd.read(cs)
    print(f"data :{data}")
    print(f"len  :{len(data)}")

    data = fd.read(cs)
    print(f"data :{data}")
    print(f"len  :{len(data)}")

    data = fd.read(cs)
    print(f"data :{data}")
    print(f"len  :{len(data)}")

    fd.close()    

def chunk_data_02(srcfile, cs):
    fd = open(srcfile, "rt")

    i = 1
    while(True):
        data = fd.read(cs)
        length = len(data)
        print(f"{i}: {length}->{data}")

        i = i + 1
        if (length < cs):
            break

def chunk_overlap(srcfile, cs):
    fd = open(srcfile, "rb")

    i = 1
    while(True):
        data = fd.read(cs)
        length = len(data)
        print(f"{i}: {length}->{data}, fd.tell()")
        fd.seek(-10, 1)

        i = i + 1
        if (length < cs):
            break
    

def main():
    fname = "t.txt"
    chunk_size = 128
    # chunk_data(fname, chunk_size)
    # chunk_data_02(fname, chunk_size)
    chunk_overlap(fname, chunk_size)
if (__name__ == "__main__"):
    main()

