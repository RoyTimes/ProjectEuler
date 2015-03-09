#include <bits/stdc++.h>
using namespace std;

#define COLOR_H 0
#define COLOR_C 1
#define COLOR_S 2
#define COLOR_D 3

using namespace std;

char PACards[5][3];
char PBCards[5][3];
int PAHash[4][13];
int PBHash[4][13];

inline int calcPokerIndex(char card)
{
    if (card >= '2' && card <= '9')
        return card - '2';
    if (card == 'T') return 8;
    if (card == 'J') return 9;
    if (card == 'Q') return 10;
    if (card == 'K') return 11;
    if (card == 'A') return 12;
}

void doHash(char cards[5][3], int hash[4][13])
{
    memset(hash, 0, sizeof(int) * 4 * 13);

    for (int i = 0; i <= 4; i++)
    {
        int pokerIndex = calcPokerIndex(cards[i][0]);

        switch (cards[i][1])
        {
        case 'H':
            hash[COLOR_H][pokerIndex] = 1;
            break;
        case 'C':
            hash[COLOR_C][pokerIndex] = 1;
            break;
        case 'S':
            hash[COLOR_S][pokerIndex] = 1;
            break;
        case 'D':
            hash[COLOR_D][pokerIndex] = 1;
            break;
        default:
            break;
        }
    }
}

int getMaxPoker(int hash[4][13], int which)
{
    int cnt = 0;
    int tmpHash[13];
    memset(tmpHash, 0, sizeof(tmpHash));

    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 12; j++)
        {
            if (hash[i][j])
                tmpHash[j]++;
        }
    }

    for (int i = 12; i >= 0; i--)
    {
        while (tmpHash[i])
        {
            tmpHash[i]--;
            cnt++;
            if (cnt == which)
                return i;
        }
    }
}

int isOnePair(int hash[4][13])
{
    int count = 0;
    int pairCount = 0;
    int firstPairVal = 0;

    for (int j = 0; j <= 12; j++)
    {
        count = 0;
        for (int i = 0; i <= 3; i++)
        {
            if (hash[i][j])
                count++;
        }
        if (count == 2)
        {
            pairCount++;
            firstPairVal = j;
        }
    }

    if (pairCount == 1)
        return firstPairVal;

    return -1;
}

int isTwoPairs(int hash[4][13])
{
    int count = 0;
    int pairCount = 0;
    int firstPairVal = 0;
    int secondPairVal = 0;

    for (int j = 0; j <= 12; j++)
    {
        count = 0;
        for (int i = 0; i <= 3; i++)
        {
            if (hash[i][j])
                count++;
        }
        if (count == 2)
        {
            pairCount++;
            if (pairCount == 1)
                firstPairVal = j;
            else
                secondPairVal = j;
        }
    }

    if (pairCount == 2)
        return 13 * secondPairVal + firstPairVal;

    return -1;
}

int isThreeOfAKind(int hash[4][13])
{
    int count = 0;

    for (int j = 0; j <= 12; j++)
    {
        count = 0;
        for (int i = 0; i <= 3; i++)
        {
            if (hash[i][j])
                count++;
        }
        if (count == 3)
            return j;
    }
    return -1;
}

int isStraight(int hash[4][13])
{
    int tmpHash[13];
    memset(tmpHash, 0, sizeof(tmpHash));

    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 12; j++)
        {
            if (hash[i][j])
                tmpHash[j]++;
        }
    }

    for (int i = 0; i <= 8; i++)
    {
        if (tmpHash[i] && tmpHash[i + 1] && tmpHash[i + 2] && tmpHash[i + 3] && tmpHash[i + 4])
            return i + 4;
    }

    return -1;
}

int isFlush(int hash[4][13])
{
    int count = 0;

    for (int i = 0; i <= 3; i++)
    {
        count = 0;
        for (int j = 0; j <= 12; j++)
        {
            if (hash[i][j])
                count++;
        }
        if (count == 5)
            return 1;
    }
    return -1;
}

int isFullHouse(int hash[4][13])
{
    int count = 0;
    int pairVal = -1;
    int threeVal = -1;

    for (int j = 0; j <= 12; j++)
    {
        count = 0;
        for (int i = 0; i <= 3; i++)
        {
            if (hash[i][j])
                count++;
        }

        if (count == 2)
            pairVal = j;
        if (count == 3)
            threeVal = j;
    }

    if (pairVal == -1 || threeVal == -1)
        return -1;

    return 13 * threeVal + pairVal;
}

int isFourOfAKind(int hash[4][13])
{
    int count = 0;

    for (int j = 0; j <= 12; j++)
    {
        count = 0;
        for (int i = 0; i <= 3; i++)
        {
            if (hash[i][j])
                count++;
        }
        if (count == 4)
            return j;
    }
    return -1;
}

int isStraightFlush(int hash[4][13])
{
    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 8; j++)
        {
            if (hash[i][j] && hash[i][j + 1] && hash[i][j + 2] && hash[i][j + 3] && hash[i][j + 4])
                return j + 4;
        }
    }
    return -1;
}

int isRoyalFlush(int hash[4][13])
{
    for (int i = 0; i <= 3; i++)
    {
        if (hash[i][8] && hash[i][9] && hash[i][10] && hash[i][11] && hash[i][12])
            return 1;
    }
    return -1;
}

int checkDefault(int PAHash[4][13], int PBHash[4][13])
{
    for (int i = 1; i <= 5; i++)
    {
        int PAPokerVal = getMaxPoker(PAHash, i);
        int PBPokerVal = getMaxPoker(PBHash, i);

        if (PAPokerVal != PBPokerVal)
            return PAPokerVal > PBPokerVal;
    }
}

int checkOnePair(int PAHash[4][13], int PBHash[4][13])
{
    int PARetVal;
    int PBRetVal;

    PARetVal = isOnePair(PAHash);
    PBRetVal = isOnePair(PBHash);

    if (PARetVal != -1 && PBRetVal == -1)
        return 1;
    if (PARetVal == -1 && PBRetVal != -1)
        return 0;

    if (PARetVal != -1 && PBRetVal != -1)
    {
        if (PARetVal != PBRetVal)
            return PARetVal > PBRetVal;

        for (int i = 1; i <= 5; i++)
        {
            int PAPokerVal = getMaxPoker(PAHash, i);
            int PBPokerVal = getMaxPoker(PBHash, i);

            if (PAPokerVal != PBPokerVal)
                return PAPokerVal > PBPokerVal;
        }
    }

    return -1;
}

int checkTwoPairs(int PAHash[4][13], int PBHash[4][13])
{
    int PARetVal;
    int PBRetVal;

    PARetVal = isTwoPairs(PAHash);
    PBRetVal = isTwoPairs(PBHash);

    if (PARetVal != -1 && PBRetVal == -1)
        return 1;
    if (PARetVal == -1 && PBRetVal != -1)
        return 0;

    if (PARetVal != -1 && PBRetVal != -1)
    {
        if (PARetVal != PBRetVal)
            return PARetVal > PBRetVal;

        for (int i = 1; i <= 5; i++)
        {
            int PAPokerVal = getMaxPoker(PAHash, i);
            int PBPokerVal = getMaxPoker(PBHash, i);

            if (PAPokerVal != PBPokerVal)
                return PAPokerVal > PBPokerVal;
        }
    }

    return -1;
}

int checkThreeOfAKind(int PAHash[4][13], int PBHash[4][13])
{
    int PARetVal;
    int PBRetVal;

    PARetVal = isThreeOfAKind(PAHash);
    PBRetVal = isThreeOfAKind(PBHash);

    if (PARetVal != -1 && PBRetVal == -1)
        return 1;
    if (PARetVal == -1 && PBRetVal != -1)
        return 0;

    if (PARetVal != -1 && PBRetVal != -1)
    {
        if (PARetVal != PBRetVal)
            return PARetVal > PBRetVal;

        for (int i = 1; i <= 5; i++)
        {
            int PAPokerVal = getMaxPoker(PAHash, i);
            int PBPokerVal = getMaxPoker(PBHash, i);

            if (PAPokerVal != PBPokerVal)
                return PAPokerVal > PBPokerVal;
        }
    }

    return -1;
}

int checkStraight(int PAHash[4][13], int PBHash[4][13])
{
    int PARetVal;
    int PBRetVal;

    PARetVal = isStraight(PAHash);
    PBRetVal = isStraight(PBHash);

    if (PARetVal != -1 && PBRetVal == -1)
        return 1;
    if (PARetVal == -1 && PBRetVal != -1)
        return 0;

    if (PARetVal != -1 && PBRetVal != -1)
    {
        if (PARetVal != PBRetVal)
            return PARetVal > PBRetVal;

        for (int i = 2; i <= 5; i++)
        {
            int PAPokerVal = getMaxPoker(PAHash, i);
            int PBPokerVal = getMaxPoker(PBHash, i);

            if (PAPokerVal != PBPokerVal)
                return PAPokerVal > PBPokerVal;
        }
    }

    return -1;
}

int checkFlush(int PAHash[4][13], int PBHash[4][13])
{
    int PARetVal;
    int PBRetVal;

    PARetVal = isFlush(PAHash);
    PBRetVal = isFlush(PBHash);

    if (PARetVal != -1 && PBRetVal != -1)
    {
        if (PARetVal == 1 && PBRetVal == 1)
        {
            for (int i = 1; i <= 5; i++)
            {
                int PAPokerVal = getMaxPoker(PAHash, i);
                int PBPokerVal = getMaxPoker(PBHash, i);

                if (PAPokerVal != PBPokerVal)
                    return PAPokerVal > PBPokerVal;
            }
        }
        else
            return PARetVal > PBRetVal;
    }

    return -1;
}

int checkFullHouse(int PAHash[4][13], int PBHash[4][13])
{
    int PARetVal;
    int PBRetVal;

    PARetVal = isFullHouse(PAHash);
    PBRetVal = isFullHouse(PBHash);

    if (PARetVal != -1 && PBRetVal == -1)
        return 1;
    if (PARetVal == -1 && PBRetVal != -1)
        return 0;

    if (PARetVal != -1 && PBRetVal != -1)
        return PARetVal > PBRetVal;

    return -1;
}

int checkFourOfAKind(int PAHash[4][13], int PBHash[4][13])
{
    int PARetVal;
    int PBRetVal;

    PARetVal = isFourOfAKind(PAHash);
    PBRetVal = isFourOfAKind(PBHash);

    if (PARetVal != -1 && PBRetVal == -1)
        return 1;
    if (PARetVal == -1 && PBRetVal != -1)
        return 0;

    if (PARetVal != -1 && PBRetVal != -1)
    {
        if (PARetVal == PBRetVal)
        {
            int PASingleVal = -1;
            int PBSingleVal = -1;

            for (int i = 1; i <= 5; i++)
            {
                int pokerVal = getMaxPoker(PAHash, i);
                if (pokerVal != PARetVal)
                {
                    PASingleVal = pokerVal;
                    break;
                }
            }

            for (int i = 1; i <= 5; i++)
            {
                int pokerVal = getMaxPoker(PBHash, i);
                if (pokerVal != PBRetVal)
                {
                    PBSingleVal = pokerVal;
                    break;
                }
            }

            return PASingleVal > PBSingleVal;
        }
        else
            return PARetVal > PBRetVal;
    }
    return -1;
}

int checkStraightFlush(int PAHash[4][13], int PBHash[4][13])
{
    int PARetVal;
    int PBRetVal;

    PARetVal = isStraightFlush(PAHash);
    PBRetVal = isStraightFlush(PBHash);

    if (PARetVal != -1 && PBRetVal == -1)
        return 1;
    if (PARetVal == -1 && PBRetVal != -1)
        return 0;

    if (PARetVal != PBRetVal)
        return PARetVal > PBRetVal;

    return -1;
}

int checkRoyalFlush(int PAHash[4][13], int PBHash[4][13])
{
    int PARetVal;
    int PBRetVal;

    PARetVal = isRoyalFlush(PAHash);
    PBRetVal = isRoyalFlush(PBHash);

    if (PARetVal != -1 && PBRetVal == -1)
        return 1;
    if (PARetVal == -1 && PBRetVal != -1)
        return 0;

    return -1;
}

int beats(char PA[5][3], char PB[5][3])
{
    doHash(PA, PAHash);
    doHash(PB, PBHash);

    int retVal;

    retVal = checkRoyalFlush(PAHash, PBHash);
    if (retVal != -1)
        return retVal;

    retVal = checkStraightFlush(PAHash, PBHash);
    if (retVal != -1)
        return retVal;

    retVal = checkFourOfAKind(PAHash, PBHash);
    if (retVal != -1)
        return retVal;

    retVal = checkFullHouse(PAHash, PBHash);
    if (retVal != -1)
        return retVal;

    retVal = checkFlush(PAHash, PBHash);
    if (retVal != -1)
        return retVal;

    retVal = checkStraight(PAHash, PBHash);
    if (retVal != -1)
        return retVal;

    retVal = checkThreeOfAKind(PAHash, PBHash);
    if (retVal != -1)
        return retVal;

    retVal = checkTwoPairs(PAHash, PBHash);
    if (retVal != -1)
        return retVal;

    retVal = checkOnePair(PAHash, PBHash);
    if (retVal != -1)
        return retVal;

    return checkDefault(PAHash, PBHash);
}

int main()
{
    freopen("data.in", "r", stdin);

    int ans = 0;
    while (scanf("%s", PACards[0]) > 0)
    {
        for (int i = 1; i <= 4; i++)
            scanf("%s", PACards[i]);
        for (int i = 0; i <= 4; i++)
            scanf("%s", PBCards[i]);

        if (beats(PACards, PBCards))
            ans++;
    }
    printf("%d\n", ans);

    return 0;
}
