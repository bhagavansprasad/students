flv:audio_video.o audio_video_fun.o
	gcc audio_video.o audio_video_fun.o -o flv

audio_video.o:audio_video.c
	          gcc audio_video.c -c 

audio_video_fun.o:audio_video_fun.c
				gcc audio_video_fun.c -c

clean:
	rm -rf flv
	rm -rf *.o
