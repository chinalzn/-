#include <iostream>
#include <algorithm>
#include <ctype.h>

using namespace std;

int compare(const int a, const int b)
{
    return a > b;
}

int getBeautifulScore(int n, char *str)
{
    if(n < 0)
    {
        return 0;
    }

    //´´½¨¹þÏ£±í
    const int TableSize = 256;
    unsigned int hashTable[TableSize];
    for(int i = 0; i < TableSize; i++)
    {
        hashTable[i] = 0;
    }

    char *pHashKey = str;
    while(*pHashKey)
    {
        if(isalpha(*pHashKey))
        {
            hashTable[*pHashKey]++;
        }
        pHashKey++;
    }

    sort(hashTable, hashTable + 256, compare);

    int score = 26;
    int scoreSum = 0;
    for(int i = 0; i < TableSize; i++)
    {
        scoreSum += score * hashTable[i];
        score --;
    }
    return scoreSum;
}

int main()
{
    char str[256];
    int n, i, *score;
    cin >> n;
    score = (int *)malloc(sizeof(int) * (n + 1));
    for(i = 1; i <= n; i++)
    {
        cin >> str;
        *(score + i) = getBeautifulScore(n, str);
    }

    for(i = 1; i <= n; i++)
    {
        cout << *(score + i) << endl;
    }
    return 0;
}
