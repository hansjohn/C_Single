GraphCreate()
{
    while (m < n * (n - 1) / 2)
    {
    scanf:v1, v2, wi;
        if (v1 = v2 || v1 < 0 || v2 < 0)
            break;
        ++m; //边或弧计数
        p = (Alink *)malloc(sizeof(ALink));
        p->Vi = v2；p->Wi = wi;
        p->next = NULL;
        if (!V0[v1].Vh) //链入头指针
            V0[v1].Vh = p;
        else //找到邻接链表尾并链入p
        {
            q = V0[v1].Vh;
            while (q->next)
                q = q->next;
            q->next = p;
        } //if-else
    }     //while
} //GraphCreate算法结束
