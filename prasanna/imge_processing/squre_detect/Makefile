CXXFLAGS:= -c -W -Wall -I/home/bhagavan/sources/temp/opencv/include/opencv -I/home/bhagavan/sources/temp/opencv/modules/core/include -I/home/bhagavan/sources/temp/opencv/modules/hal/include -I/home/bhagavan/sources/temp/opencv/modules/highgui/include -I/home/bhagavan/sources/temp/opencv/modules/imgproc/include -I/home/bhagavan/sources/temp/opencv/modules/imgcodecs/include -I/home/bhagavan/sources/temp/opencv/modules/videoio/include -I/home/bhagavan/sources/temp/opencv/modules/objdetect/include



LIBS_PATH+=-L/home/bhagavan/llibs/opencvs/lib/
LIBS:=-rdynamic -ldl -lm -lpthread -lrt -Wl,-rpath,/home/bhagavan/sources/temp/opencv/release/lib 
LIBS+=-lopencv_hal
LIBS+=-lopencv_objdetect
LIBS+=-lopencv_videoio

DYN_LIBS_PATH +=-L/home/bhagavan/llibs/opencvs/lib/

DYN_LIBS+=-lopencv_core 
DYN_LIBS+=-lopencv_highgui
DYN_LIBS+=-lopencv_imgcodecs
DYN_LIBS+=-lopencv_imgproc
DYN_LIBS+=-lopencv_objdetect
DYN_LIBS+=-lopencv_videoio

a.out: square_detect.o
	gcc -fprofile-arcs -ftest-coverage square_detect.o $(LIBS_PATH) $(LIBS) $(DYN_LIBS_PATH) $(DYN_LIBS) 
square_detect.o: square_detect.cpp
	gcc -fprofile-arcs -ftest-coverage square_detect.cpp $(CXXFLAGS)
clean:
	rm -rf *.o
	rm -rf a.out

