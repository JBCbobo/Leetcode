/******************************
Descrip:Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.
Time:2017/8/25
******************************/

int romantoint(char str)
{
	int integer = 0;
	switch(str)
	{
		case 'I':integer = 1;break;
		case 'V':integer = 5;break;
		case 'X':integer = 10;break;
		case 'L':integer = 50;break;
		case 'C':integer = 100;break;
		case 'D':integer = 500;break;
		case 'M':integer = 1000;break;
		default :integer = 0;
	}
	return integer;
}

int romanToInt(char* s) {
    
	Roman_numeral r1;
    int sum = 0;
	int now_str = 0;
	int next_str = 0;
	while(*s)
	{
		now_str = romantoint(*s++);
		next_str = romantioint(*s++);
		if(now_str < next_str)
		{
			sum = sum  - now_str;
		}
		else
		{
			sum = sum + now_str;
		}

	}
	return sum;
    
}