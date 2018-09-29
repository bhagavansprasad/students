import os

is_in_sub_dir = False

def normalize_filename(fname):
    print "fname :", fname
    return fname.strip().replace(" ", "")

def create_root_dir(folder_name):
    folder_name = normalize_filename(folder_name)

    if not os.path.exists(folder_name):
        os.mkdir(folder_name)

    os.chdir(folder_name)

    print os.getcwd()
    return

def create_dir(folder_name, is_changedir, is_root, is_sub_dir):
    folder_name = normalize_filename(folder_name)

    if (is_root == False and is_in_sub_dir == True):
        print os.getcwd()
        os.chdir(os.path.dirname(os.getcwd()))
        print os.getcwd()

    if not os.path.exists(folder_name):
        os.mkdir(folder_name)

    if (is_changedir == True):
        os.chdir(folder_name)

    if (is_sub_dir == True):
        is_in_sub_dir = True

    print os.getcwd()
    return

def mk_chapter(cname, title):
    chapt_name, chapt_no = cname.split()

    chapt_name = "%s%02d" % (chapt_name, int(chapt_no))
    chapt_name = normalize_filename(chapt_name) + "-" + normalize_filename(title)
    print "chapt_name :", chapt_name
    create_dir(chapt_name, True, False, True)


def is_skip_line(data):
    if (data.isspace() == True):
        return True

    return False

def create_new_file(filename):
    open(filename, 'a').close()

fd = open("outline.txt", "r")
fdata = fd.readlines()

print fdata
linecount = len(fdata)
print linecount

i = 0
got_space = False
while(i < linecount-1):
    line = fdata[i]

    print "1. line      :", line
    if (is_skip_line(line) == True):
        i = i + 1
        got_space = True
        continue

    #print "%d:%s" % (i, line.strip())

    if (i == 0):
        create_root_dir(line)

    if (line.find("CHAPTER") >= 0):
        print ""
        print fdata[i].strip()
        mk_chapter(line, fdata[i+1])
        i = i + 2
        got_space = False
        continue

    if (line.find("Quiz") >= 0):
        file_name =  normalize_filename(line.strip())+".mp4"
        print "line      :", line
        print "file_name :", file_name
        create_new_file(file_name)
        i = i + 1
        continue

    if (got_space == True):
        file_name =  normalize_filename(line.strip())+".mp4"
        print "line      :", line
        print "file_name :", file_name
        create_new_file(file_name)
        i = i + 1

    if (i >= 20):
        break
    '''
    '''
    
    i = i + 1

