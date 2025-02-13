// Trim Spaces
// Send Feedback
// Given an input string S that contains multiple words, you need to remove all the spaces present in the input string.
// There can be multiple spaces present after any word.

// Input Format :
//  String S

// Output Format :
// Updated string

// Constraints :
// 1 <= Length of string S <= 10^6

// Sample Input :
// abc def g hi

// Sample Output :
// abcdefghi

void trimSpaces(char input[])
{
    int i = 0;
    int j = 0;

    while (input[j] != '\0')
    {
        while (input[j] == ' ')
        {
            j++;
        }
        input[i] = input[j];
        i++;
        j++;
    }
    input[i] = '\0';
}
