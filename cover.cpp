//cover.cpp
void cover(int tr,int tc,int dr,int dc,int size)
{
	int s,t;
	if(size<2)
		return;
	s=size/2;
	t=title++;
	if(dr<tr+s && dc<tc+s)
	{
		cover(tr,tc,dr,dc,s);
	//TODO...
	}
	return;
}

