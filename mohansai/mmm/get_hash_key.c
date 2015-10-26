int get_hash_key(int size)
{
	if(size<=128)
		return 0;
	else if(size<=256)
		return 1;
	else if(size<=512)
		return 2;
	else if(size<=1024)
		return 3;
	else if(size<=2048)
		return 4;
	else
		return 5;
}


