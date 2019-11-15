def get_entrance(table):
    entrances = {'E':[]}
    for row, line in enumerate(table, 0):
        idx = 0
        if ('E' in line):
            while(True):
                try:
                    idx = line.index('E', idx)
                    entrances['E'].append((row, idx))
                    idx = idx + 1
                except ValueError:
                    break
    return (entrances)

def get_edges(table):
    edges = {'Edge':[]}
    for row, line in enumerate(table, 0):
        idx = 0
        for col, ele in enumerate(line, 0):
            if (
                    table[row][col] == 'R' and
                    table[row][col] == 'R' and

            if (ele == 'R'):
                if

       
def get_elements_by_type(table, etype):
    if(etype == 'E'):
        get_entrance(table)
    elif(etype == 'R'):
        get_edges(table)

def get_map_data(mapfile):
    table = []
    with open(mapfile)  as rfd:
        data = rfd.readlines()

    for line in data:
        table.append(line.strip().split("\t"))

    return table

def dump_data(table):
    for line in table:
        print (line)

def main():
    mapfile = "map.txt"
    table = get_map_data(mapfile)
    dump_data(table)
    print ("")

    entrances = get_elements_by_type(table, 'E')
    entrances = get_elements_by_type(table, 'R')

if(__name__ == "__main__"):
    main()
