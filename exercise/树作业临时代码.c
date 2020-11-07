Tree * findparent(Tree T,p)
{
	while(T)
	{	if(T->lc==p)
    {
        return T;
    }
    else if(T->rc==p)
    {
        return T;
    }
    
		findparent(T->lc,p);
        findparent(T->rc,p);
	}
} 