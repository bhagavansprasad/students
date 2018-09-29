CXXFLAGS:= -c -fsigned-char -W -Wall -Werror=return-type -Werror=non-virtual-dtor -Werror=address -Werror=sequence-point -Wformat -Werror=format-security -Wmissing-declarations -Wundef -Winit-self -Wpointer-arith -Wshadow -Wsign-promo -fdiagnostics-show-option -Wno-long-long -pthread -fomit-frame-pointer -msse -msse2 -mno-avx -msse3 -mno-ssse3 -mno-sse4.1 -mno-sse4.2 -ffunction-sections -fvisibility=hidden -fvisibility-inlines-hidden -O3 -DNDEBUG  -DNDEBUG -I/home/bhagavan/sources/temp/opencv/3rdparty/ippicv/unpack/ippicv_lnx/include -I/home/bhagavan/sources/temp/opencv/release -I/home/bhagavan/sources/temp/opencv/apps/annotation/PRIVATE -I/home/bhagavan/sources/temp/opencv/apps/annotation -I/home/bhagavan/sources/temp/opencv/include/opencv -I/home/bhagavan/sources/temp/opencv/modules/core/include -I/home/bhagavan/sources/temp/opencv/modules/hal/include -I/home/bhagavan/sources/temp/opencv/modules/highgui/include -I/home/bhagavan/sources/temp/opencv/modules/imgproc/include -I/home/bhagavan/sources/temp/opencv/modules/imgcodecs/include -I/home/bhagavan/sources/temp/opencv/modules/videoio/include -I/home/bhagavan/sources/temp/opencv/modules/objdetect/include


LIBS_PATH+=-L/home/bhagavan/sources/temp/opencv/3rdparty/ippicv/unpack/ippicv_lnx/lib/intel64/
LIBS_PATH+=-L/home/bhagavan/llibs/opencvs/lib/

#export LD_LIBRARY_PATH:=/home/bhagavan/llibs/opencvs/lib/:$(LD_LIBRARY_PATH)
LIBS:=-rdynamic -ldl -lm -lpthread -lrt -Wl,-rpath,/home/bhagavan/sources/temp/opencv/release/lib 
LIBS+=-lippicv
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

a.out: w_vid.o
	gcc w_vid.o $(LIBS_PATH) $(LIBS) $(DYN_LIBS_PATH) $(DYN_LIBS) 
w_vid.o: w_vid.cpp
	gcc w_vid.cpp $(CXXFLAGS)
clean:
	rm -rf *.o
	rm -rf a.out
