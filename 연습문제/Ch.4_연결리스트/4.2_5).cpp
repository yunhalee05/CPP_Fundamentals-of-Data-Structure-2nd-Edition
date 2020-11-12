void Merge(Chain& x, Chain& y, Chain& z)
{
	ChainNode* x_temp = x.first;
	ChainNode* y_temp = y.first;
	ChainNode* z_temp = z.first;

	while (y.first != NULL || x_temp != NULL)//���� ���̰� ª�� ���� ���������� �����Ƽ� �ִ´�.
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
	if (x.length() > y.length())//�������� �ִ´�. 
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