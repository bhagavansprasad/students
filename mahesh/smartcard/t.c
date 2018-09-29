case 1 :
						str=str+32;
						sbitmap(str,16);
						str+16;
				case 3 :
						proccode(str,6);
						str+6;
				case 4 : 
						amount(str,12);
						str+12;
				case 7 : 
						date(str,10);
						str+10;
				case 11 : 
						trace(str,6);
						str+6;
				case 12 : 
						time(str,6);
						str+6;
				case 13 : 
						dateissued(str,4);
						str+4;
				case 15 : 
						limitdate(str,4);
						str+4;
				case 17 :
						expdate(str,4);
						str+4;
				case 32 : 
						str+2;
						idcode(str,3);
						str+3;
				case 35 : 
						str+2;
						t2data(str,17);
						str+17;
				case 37 : 
						ref(str,12);
						str+12;
				case 41 : 
						termid(str,16);
						str+16;
				case 43 :
						rxlocation(str,40);
						str+40;
				case 48 : 
						str+3;
						privatedata(str,10);
						str+10;
				case 49 : 
						currency(str,3);
						str+3;
				case 60 : 
						str+3;
						res1(str,12);
						str+12;
				case 61 : 
						str+3; 
						res2(str,5);
						str+5;


