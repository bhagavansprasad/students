import os

def normalize_filename(fname):
    fname = fname.strip().replace(" ", "").replace(",", "").replace(":","-").replace("&", "-").replace("'","")
    fname = fname.replace("(", "-").replace(")","").replace("!","").replace("?", "")
    return fname

def create_root_dir(folder_name):
    folder_name = normalize_filename(folder_name)

    if not os.path.exists(folder_name):
        os.mkdir(folder_name)

    os.chdir(folder_name)

    print "root :", os.getcwd()
    return

def create_dir(folder_name, change_dir):
    folder_name = normalize_filename(folder_name)

    if (change_dir == True):
        print os.getcwd()
        os.chdir(os.path.dirname(os.getcwd()))
        print os.getcwd()
    '''
    '''

    if not os.path.exists(folder_name):
        os.mkdir(folder_name)

    #if (is_changedir == True):
    os.chdir(folder_name)
    print "subdir   :", os.getcwd()
    return os.getcwd()

is_in_sub_dir = False

def mk_chapter(cname, title):
    global is_in_sub_dir
    chapt_name, chapt_no = cname.split()

    chapt_name = "%02d%s" % (int(chapt_no), chapt_name)
    chapt_name = normalize_filename(chapt_name) + "-" + normalize_filename(title)
    print "chapt_name :", chapt_name

    subdir = create_dir(chapt_name, is_in_sub_dir)
    is_in_sub_dir = True
    return subdir

def is_skip_line(data):
    if (data.isspace() == True):
        return True

    return False

def create_new_file(filename):
    open(filename, 'a').close()

def main():
    fd = open("outline.txt", "r")
    fdata = fd.readlines()

    linecount = len(fdata)
    print linecount

    dirname = ""

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
            create_root_dir(line)

        if (line.find("CHAPTER") >= 0):
            print ""
            print fdata[i].strip()
            dirname = mk_chapter(line, fdata[i+1])
            i = i + 2
            got_space = False
            continue

        if (line.find("Quiz") >= 0):
            filename = normalize_filename(line.strip())+".mp4"
            print "filename :", filename
            file_with_path = dirname + "/" + filename 
            print "path     :", file_with_path 
            create_new_file(file_with_path)
            i = i + 1
            continue

        if (got_space == True):
            #print "file :", fdata[i+1].strip() + line
            filename = normalize_filename(fdata[i+1].strip() + "-" + line.strip())+".mp4"
            print "filename :", filename
            print "path     :", dirname+filename 
            file_with_path = dirname + "/" + filename 
            print "path     :", file_with_path 
            create_new_file(file_with_path)
            i = i + 1

        '''
        if (i >= 10):
            break
        '''
    
        i = i + 1

if __name__ == '__main__':
    main()
