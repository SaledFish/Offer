/*
正则表达式匹配
*/

bool matchCore(char* str, char* pattern)
{
	if (*str == '\0'&&*pattern == '\0')
		return true;

	if (*str != '\0'&&*pattern == '\0')
		return false;

	if (*(pattern + 1) == '*')
	{
		if (*pattern == *str || (*pattern == '.'&&*str != '\0'))
			//move on the next state
			return matchCore(str + 1, pattern + 2)
			//stay on thr current state
			|| matchCore(str + 1, pattern)
			//ignore a '*'
			|| matchCore(str, pattern + 2);
		else
			return matchCore(str, pattern + 2);
	}

	if (*str == *pattern || (*pattern == '.'&&*str != '\0'))
		return matchCore(str + 1, pattern + 1);

	return false;
}

bool mathch(char *str, char *pattern)
{
	if (str == nullptr || pattern == nullptr)
		return false;

	return matchCore(str, pattern);
}