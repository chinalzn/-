第一次尝试在Github上编写代码，准备作为以后写代码的一个记录。
int main()
{
    int i, j, len1, len2, len3, tmp, flag = 1;
    char sNum1[1000], sNum2[1000];
    int nNum[2000];

    gets(sNum1);
    gets(sNum2);


    len1 = strlen(sNum1);
    len2 = strlen(sNum2);
    len3 = len1 + len2 + 1;
    tmp = len3;

    for(i = len1 - 1; i >= 0; i--)
    {
        tmp = --len3;
        for(j = len2 - 1; j >= 0; j--)
        {
            nNum[tmp--] += (sNum2[j] - '0') * (sNum1[i] - '0');
        }
    }

    len3 = len1 + len2 + 1;

    for(i = len3; i > 0; i--)
    {
        while(nNum[i] > 9)
        {
            nNum[i - 1] += nNum[i] / 10;
            nNum[i] = nNum[i] % 10;
        }
    }

    for(i = 0; i < len3; i++)
    {
        if(0 == nNum[i] && 1 == flag)
        {
            continue;
        }
        else
        {
            flag = 0;
        }
        printf("%d", nNum[i]);
    }
    return 0;
}
