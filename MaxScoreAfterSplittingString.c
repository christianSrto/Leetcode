// Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).
// The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.

int maxScore(char *s)
{
    int score = 0;

    for (int i = 0; i < strlen(s) - 1; i++)
    {
        int temp = 0;

        for (int j = 0; j <= i; j++)
        {
            if (s[j] == '0')
            {
                temp++;
            }
        }

        for (int j = i + 1; j < strlen(s); j++)
        {
            if (s[j] == '1')
            {
                temp++;
            }
        }

        if (temp >= score)
        {
            score = temp;
        }
    }

    return score;
}