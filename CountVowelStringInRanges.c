/**
You are given a 0-indexed array of strings words and a 2D array of integers queries.
Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.
Return an array ans of size queries.length, where ans[i] is the answer to the ith query.
Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.
 */
bool isVowel(char c){
    return c == 'a'||c == 'e' ||c == 'i'||c=='o'||c=='u';
}

bool hasVowel(const char* str){
    int len = strlen(str);
    return isVowel(str[0]) && isVowel(str[len-1]);
}

int* vowelStrings(char** words, int wordsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    *returnSize = queriesSize;
    int* ans = (int*)malloc(queriesSize * sizeof(int));


    int* prefixSum = (int*)calloc(wordsSize + 1, sizeof(int));
    for(int i =0; i< wordsSize; i++){
        prefixSum[i+1] = prefixSum[i] + (hasVowel(words[i]) ? 1 : 0); 
    } 


    for (int i = 0; i < queriesSize; ++i) {
        int li = queries[i][0];
        int ri = queries[i][1];
        ans[i] = prefixSum[ri + 1] - prefixSum[li];
    }

    free(prefixSum);

    return ans;  
}