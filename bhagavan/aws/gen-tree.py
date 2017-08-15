import os

def normalize_filename(fname):
    return fname.strip().replace(" ", "")

def create_dir(folder_name, is_changedir):
    folder_name = normalize_filename(folder_name)
    if not os.path.exists(folder_name):
        os.mkdir(folder_name)

        if (is_changedir == True):
            os.chdir(folder_name)
        print os.getcwd()
    return

def mk_chapter(cname, title):
    #print "cname :", cname
    chapt_name, chapt_no = cname.split()
    #print chapt_name, chapt_no

    chapt_name = "%s%02d" % (chapt_name, int(chapt_no))
    #print "chapt_name :", chapt_name
    chapt_name = normalize_filename(chapt_name) + "-" + normalize_filename(title)
    print "chapt_name :", chapt_name
    create_dir(chapt_name, False)


def is_skip_line(data):
    if (data.isspace() == True):
        return True

    return False

fd = open("outline.txt", "r")
fdata = fd.readlines()

#for lineno,data in enumerate(fdata):

linecount = len(fdata)
print linecount

i = 0
while(i < linecount):
    line = fdata[i]

    if (is_skip_line(line) == True):
        i = i + 1
        continue

    #line = normalize_filename(line)
    print "%d:%s" % (i, line)

    if (i == 0):
        create_dir(line, True)

    if (line.find("CHAPTER") >= 0):
        print fdata[i]
        mk_chapter(line, fdata[i+1])
        i = i + 2
        continue

    '''
    if (i == 30):
        break
    '''
    
    i = i + 1

