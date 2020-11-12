void Merge(Chain& x, Chain& y, Chain& z)
{
	ChainNode* x_temp = x.first;
	ChainNode* y_temp = y.first;
	ChainNode* z_temp = z.first;

	while (y.first != NULL || x_temp != NULL)//둘중 길이가 짧은 것이 끝날때가지 번갈아서 넣는다.
	{
		if (x.Data() <= y.Data())
		{
			z_temp = z.Insert(z_temp, x.Data());
			x.Delete(x.First());
		}
		else
			z_temp = z.Insert(z_temp, y.Data());
		y.Delete(y.First());
	}
	if (x.length() > y.length())//남은것을 넣는다. 
	{
		while (x_temp != NULL)
		{
			z_temp = z.Insert(z_temp, x.Data());
			x.Delete(x.First());
		}
	}
	else if (x.length() < y.length())
	{
		while (x_temp != NULL)
		{
			z_temp = z.Insert(z_temp, y.Data());
			y.Delete(y.First());
		}
	}
}