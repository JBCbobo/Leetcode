/******************************
Descrip:Count the number of segments in a string, 
where a segment is defined to be a contiguous sequence of non-space characters.
Please note that the string does not contain any non-printable characters
Time:2017/8/23
******************************/
#include <iostream>
using namespace std;

char str[] = { "hello, I'm JBC" };

int countSegments(char* s) 
{
	int number;
	for ( number = 0; *s; s++)
	{
		if (*(s) != ' ' && (*(s+1) == '\0' || *(s+1) == ' '))
		{
			number = number + 1;
		}
	}
	return number;

}
int main()
{
	int temp = 0;
	temp = countSegments(str);
	cout << temp << endl;
	system("pause");
	return 0;
}