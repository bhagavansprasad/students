a.out:flv.o flv_parse_header.o flv_parse_tag.o script_data.o video_data.o audio_data.o
	gcc flv.o flv_parse_header.o flv_parse_tag.o script_data.o video_data.o audio_data.o

flv.o:flv.c flv.h fn_declaration.h
	gcc flv.c flv.h fn_declaration.h -c

flv_parse_header.o:flv_parse_header.c
	gcc flv_parse_header.c -c

flv_parse_tag.o:flv_parse_tag.c
	gcc flv_parse_tag.c -c

script_data.o:script_data.c
	gcc script_data.c -c

video_data.o: video_data.c
	gcc video_data.c -c

audio_data.o: audio_data.c
	gcc audio_data.c -c

clean:
	rm *.o
	rm a.out
