import os

def normalize_filename(fname):
    return fname.strip().replace(" ", "")

def create_dir(folder_name, is_changedir, is_root):
    folder_name = normalize_filename(folder_name)

    if (is_root == False):
        print os.getcwd()
        os.chdir(os.path.dirname(os.getcwd()))
        print os.getcwd()

    if not os.path.exists(folder_name):
        os.mkdir(folder_name)

    if (is_changedir == True):
        os.chdir(folder_name)
    print os.getcwd()
    return

def mk_chapter(cname, title):
    chapt_name, chapt_no = cname.split()

    chapt_name = "%s%02d" % (chapt_name, int(chapt_no))
    chapt_name = normalize_filename(chapt_name) + "-" + normalize_filename(title)
    print "chapt_name :", chapt_name
    create_dir(chapt_name, True, False)


def is_skip_line(data):
    if (data.isspace() == True):
        return True

    return False

fd = open("outline.txt", "r")
fdata = fd.readlines()

linecount = len(fdata)
print linecount

i = 0
got_space = False
while(i < linecount-1):
    line = fdata[i]

    if (is_skip_line(line) == True):
        i = i + 1
        got_space = True
        continue

    #print "%d:%s" % (i, line.strip())

    if (i == 0):
        create_dir(line, True, True)

    if (line.find("CHAPTER") >= 0):
        print ""
        print fdata[i].strip()
        mk_chapter(line, fdata[i+1])
        i = i + 2
        got_space = False
        continue

    if (line.find("Quiz") >= 0):
        print "file :", normalize_filename(line.strip())+".mp4"
        i = i + 1
        continue

    if (got_space == True):
        #print "file :", fdata[i+1].strip() + line
        print "file :", normalize_filename(fdata[i+1].strip() + "-" + line.strip())+".mp4"
        i = i + 1

    '''
    if (i >= 70):
        break
    '''
    
    i = i + 1

