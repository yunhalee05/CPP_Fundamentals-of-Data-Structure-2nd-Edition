void Delete(ChainNode* x, ChainNode* y)//y�� x���� ����̴�. x�� ü���� ���� ����̴�.
{
	if (x == first)//���� x�� First��� y�� ����
	{
		first = first->link;
	}
	else
	{
		y->link = x->link;//y�� ����Ű�� ���� x������Ű�� ���̵ȴ�.
	}
	delete x;
}