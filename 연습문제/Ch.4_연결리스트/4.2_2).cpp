void Delete(ChainNode* x, ChainNode* y)//y는 x앞의 노드이다. x는 체인의 임의 노드이다.
{
	if (x == first)//만약 x가 First라면 y는 없다
	{
		first = first->link;
	}
	else
	{
		y->link = x->link;//y가 가르키는 것이 x가가르키던 것이된다.
	}
	delete x;
}