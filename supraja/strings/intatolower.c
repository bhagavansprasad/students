int intatolower(char d)
{

	if(d >= 65 && d <= 90)
		d = d + 32;

	return (d);

	//Using terinary operator
	//(<condition> ? <true part> : <false part>)
	//return (d >= 65 && d <= 90 ? d + 32: d);
}

