
a = [
    [1,   2,  3,  4],
    [12, 13, 14,  5],
    [11, 16, 15,  6],
    [10,  9,  8,  7]
]

def dump_matrix(sr, sc, er, ec):
   for i in range (sr, er+1):
       for j in range (sc, ec+1):
           print("%3d" % (a[i][j]), end='')
       print ("")
   print ("")


def genarate_cells_to_ratate(sr, sc, er, ec):
    i = sr; j = sc
    for i in range (sr, er+1):
        yield((i, j))

    for j in range (sc+1, ec+1):
        yield((i, j))
        
    for i in range (i-1, sr-1, -1):
        yield((i, j))

    for j in range (j-1, sc, -1):
        yield((i, j))

def rotate_matrix_values_by_cells(cells):
    llen = len(cells)
    r, c  = cells[-1]
    lcell_value = a[r][c]
    #print (cells)

    i = llen-1
    while (i > 0):
        r,   c = cells[i]
        nr, nc = cells[i-1]
        a[r][c] = a[nr][nc]
        i = i - 1

    r,   c = cells[i]
    a[r][c] = lcell_value

def get_next_concentric_rectangle(sr, sc, er, ec):
    #sr = 0; sc = 0; er = m-1; ec = n-1
    #print("(%d, %d), (%d, %d)" % (sr, sc, er, ec))
    sr = sr + 1
    er = er - 1

    sc = sc + 1
    ec = ec - 1

    if((er - sr) < 1 or (ec - sc) < 1):
        #print("\t==(%d, %d), (%d, %d)" % (sr, sc, er, ec))
        return (False, sr, sc, er, ec)

    return (True, sr, sc, er, ec)

def is_concentric_rectangle(m, n):
    sr = 0; sc = 0; er = m-1; ec = n-1
    while(1):
        sr = sr + 1
        er = er - 1

        sc = sc + 1
        ec = ec - 1

        if (sr == er or sc == ec):
            #print("\t==(%d, %d), (%d, %d)" % (sr, sc, er, ec))
            return False

        if((er - sr) < 1 or (ec - sc) < 1):
            break
        return True

def rotate_matrix_by_90_degrees(m, n):
    if (is_concentric_rectangle(m, n) == False):
        print ("Matrix (%d, %d) NOT a Concentric Rectangle, Rotation is not possible" % (m, n))
        return

    return
    sr = 0; sc = 0; er = m-1; ec = n-1

    while(1):
        cells = genarate_cells_to_ratate(sr, sc, er, ec)
        lcells = list(cells)

        col_len = ec - sc

        for i in range (1, col_len+1):
            rotate_matrix_values_by_cells(lcells)

        next_rct, sr, sc, er, ec = get_next_concentric_rectangle(sr, sc, er, ec)
        if (next_rct == False):
            break

def main():
    for i in range(0, 20):
        for j in range(0, 20):
            rotate_matrix_by_90_degrees(i, j)

    return

    rotate_matrix_by_90_degrees(4, 4)
    dump_matrix(0, 0, 3, 3)
    rotate_matrix_by_90_degrees(4, 4)
    dump_matrix(0, 0, 3, 3)
    return

if (__name__ == "__main__"):
    main()

