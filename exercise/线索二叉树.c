PreOrderT(Tree T)
{
    StackInit(S) ; //构造一个空栈
        p = T->lc;
        p0 = p; //记录左子树最后1个叶子结点
    while (p)
    {
        while (p->lc)
        {
            Push(S, p);
            p = p->lc;
        } //寻找子树的最左端点
        if (p->rc)
            p = p->rc;
        else //记录子树的最左端点
        {
            p0 = p;
            while (!p->rc)
                Pop(S, p);
            if (p->rc)
            {
                p = p->rc;
                p0->rc = p;
            }
        }
    }
}