
CXXFLAGS:= -g -c -fsigned-char -W -Wall -Werror=return-type -Werror=non-virtual-dtor -Werror=address -Werror=sequence-point -Wformat -Werror=format-security -Wmissing-declarations -Wundef -Winit-self -Wpointer-arith -Wshadow -Wsign-promo -fdiagnostics-show-option -Wno-long-long -pthread -fomit-frame-pointer -msse -msse2 -mno-avx -msse3 -mno-ssse3 -mno-sse4.1 -mno-sse4.2 -ffunction-sections -fvisibility=hidden -fvisibility-inlines-hidden -O3 -DNDEBUG  -DNDEBUG -I/home/bhagavan/sources/temp/opencv/include/opencv -I/home/bhagavan/sources/temp/opencv/modules/core/include -I/home/bhagavan/sources/temp/opencv/modules/hal/include -I/home/bhagavan/sources/temp/opencv/modules/highgui/include -I/home/bhagavan/sources/temp/opencv/modules/imgproc/include -I/home/bhagavan/sources/temp/opencv/modules/imgcodecs/include -I/home/bhagavan/sources/temp/opencv/modules/videoio/include -I/home/bhagavan/sources/temp/opencv/modules/objdetect/include -I/home/bhagavan/sources/temp/opencv/modules/video/include


LIBS_PATH+=-L/home/bhagavan/llibs/opencvs/lib/

#export LD_LIBRARY_PATH:=/home/bhagavan/llibs/opencvs/lib/:$(LD_LIBRARY_PATH)
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

a.out: st_video.o
	gcc st_video.o $(LIBS_PATH) $(LIBS) $(DYN_LIBS_PATH) $(DYN_LIBS) 
st_video.o: st_video.cpp
	gcc st_video.cpp $(CXXFLAGS)
clean:
	rm -rf *.o
	rm -rf a.out
