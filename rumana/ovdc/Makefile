a.out:main1.o ovd1.o ovc1.o
	gcc main1.o ovd1.o ovc1.o

main1.o: main1.c
	gcc main1.c -c
	
ovd1.o: ovd1.c
	gcc ovd1.c -c

ovc1.o: ovc1.c
	gcc ovc1.c -c
clean:
	rm *.o
	rm a.out
