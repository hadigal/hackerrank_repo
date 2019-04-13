void push(char **stack, int *topFlg, int val, int len)
{
    char *tmp = *stack;
    *topFlg += 1;
    if(*topFlg < len)
    {
        *(tmp+ (*topFlg)) = val;
    }
    return;
}

void pop(char **stack, int *topFlg)
{
    if(*topFlg == -1)
    {
        return;
    }
    char *tmp = *stack;
    *(tmp + (*topFlg)) = '\0';
    *topFlg -= 1;
    return;
}

bool backspaceCompare(char* S, char* T)
{
    uint32_t len1 = strlen(S);
    uint32_t len2 = strlen(T);

    char *stack1 = (char *)calloc(len1+1, sizeof(*stack1));
    char *stack2 = (char *)calloc(len2+1, sizeof(*stack2));

    int32_t tF1 = -1, tF2 = -1;

    while(*S != '\0' && *T != '\0')
    {
        if(*S != '#')
        {
            push(&stack1,&tF1,*S, len1);
        }
        else if(*S == '#')
        {
            pop(&stack1,&tF1);
        }

        if(*T != '#')
        {
            push(&stack2,&tF2,*T,len2);
        }
        else if(*T == '#')
        {
            pop(&stack2,&tF2);
        }
        ++S;
        ++T;
    }

    while(*S != '\0')
    {
        if(*S != '#')
        {
            push(&stack1,&tF1,*S, len1);
        }
        else if(*S == '#')
        {
            pop(&stack1,&tF1);
        }
        ++S;
    }

    while(*T != 0)
    {
        if(*T != '#')
        {
            push(&stack2,&tF2,*T,len2);
        }
        else if(*T == '#')
        {
            pop(&stack2,&tF2);
        }
        ++T;
    }

    if(strcmp(stack1,stack2) == 0)
    {
        free(stack1);
        free(stack2);
        return true;
    }
    else
    {
        free(stack1);
        free(stack2);
        return false;
    }

}
