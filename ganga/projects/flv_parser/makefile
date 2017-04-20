flv : main.o flv_header.o flv_body.o flv_audio_tags.o flv_video_tags.o dump_flv_header.o dump_audio_tag.o dump_video_tag.o 
	gcc main.o flv_header.o flv_body.o flv_audio_tags.o flv_video_tags.o dump_flv_header.o dump_audio_tag.o dump_video_tag.o -o flv

main.0 : main.c
	gcc -g -c main.c

flv_header.o : flv_header.c 
	gcc -g -c flv_header.c

flv_body.o : flv_body.c
	gcc -g -c flv_body.c

flv_audio_tags.o : flv_audio_tags.c
	gcc -g -c flv_audio_tags.c

flv_video_tags.o : flv_video_tags.c
	gcc -g -c flv_video_tags.c

dump_flv_header.o : flv_header.c 
	gcc -g -c dump_flv_header.c

dump_audio_tag.o : dump_audio_tag.c
	gcc -g -c dump_audio_tag.c

dump_video_tag.o : dump_video_tag.c
	gcc -g -c dump_video_tag.c

clean : 
	rm -rf *.o
	rm -rf flv
	rm -rf v.txt
	rm -rf a.txt
	rm -rf t.txt
	rm -rf v.flv 
	rm -rf inter.flv
	rm -rf key.flv
	rm -rf a.flv
