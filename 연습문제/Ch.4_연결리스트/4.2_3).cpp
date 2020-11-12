void Deletestart()
{
	ChainNode* temp = first;
	while (temp->link->link != NULL)
	{
		if (temp == first)
		{
			first = first->link;
			delete temp;
			temp = first->link;
		}
		else
		{
			ChainNode* y = temp->link;
			delete temp;
			temp = y->link;
		}
	}
	if (temp->link->link == NULL)
	{
		ChainNode* y = temp->link;
		delete temp;
	}
}