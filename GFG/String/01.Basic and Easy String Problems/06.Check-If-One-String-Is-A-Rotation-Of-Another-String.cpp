// Check If One String Is A Rotation Of Another String

/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    Where 'N' denotes the length of both strings 'P' and 'Q'.
*/

// Function that checks whether string 'a' is present in string 'b' as substring using KMP algorithm.
int isSubstring(string &a, string &b)
{
    // Finding the length of both strings.
    int m = a.length();
    int n = b.length();

    // Defining and initializing the pointer variables to preprocess the string 'a'.
    int i = 1, j = 0;

    // Defining the lps array.
    int lps[m] = {0};

    while (i < m)
    {

        // If the ith index of string 'a' matches with its jth index, then store the value 'j'+1 at lps[i] and increment both 'i' and 'j'.
        if (a[i] == a[j])
        {
            lps[i] = j + 1;
            i++;
            j++;
        }
        // If the ith index of 'a' does not match with its jth index of 'a' and 'j' > 0, then 'j' redirects to lps[j-1].
        else if (j > 0)
        {
            j = lps[j - 1];
        }
        // If none of the above condition matches then make lps[i] as 0 and increment 'i'.
        else
        {
            lps[i] = 0;
            i++;
        }
    }

    i = 0, j = 0;

    // Iterating through both the strings to find a match.
    while (i < n && j < m)
    {
        // If the ith character of 'b' matches with the jth character of 'a', then increment both 'i' and 'j'.
        if (b[i] == a[j])
        {
            i++;
            j++;
        }
        // If the above characters do not match and 'j' > 0, then 'j' redirects to lps[j-1].
        else if (j > 0)
        {
            j = lps[j - 1];
        }
        // If none of the above mentioned condition matches, then increment 'i'.
        else
        {
            i++;
        }
    }

    // If 'j' is equal to 'm', then we will return 1 otherwise we will return 0.
    if (j == m)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isCyclicRotation(string &p, string &q)
{
    // Performing the concatenation of string 'p' with itself.
    string res = p + p;

    // Checking if the substring 'q' is present in the string 'res'.
    return isSubstring(q, res);
}
// T : O(m + n)
// S : O(n)


int isCyclicRotation(string &p, string &q) 
{
    // Write your code here
    int n = p.length();

    for(int i=0; i<n; i++) {
        char c = q.back();
        q.pop_back();
        q = c + q;
        if(p == q) return 1;
    }

    return 0;
}
// T : O(N^2)
// S : O(1)


/*
    Time Complexity: O(N ^ 2)
    Space Complexity: O(1)

    where 'N' denotes the lengths of both the strings 'P' and 'Q'.
*/

int isCyclicRotation(string &p, string &q) {
    // Getting the size of the strings.
    int n = p.length();

    // Finding each rotation one by one.
    for (int j = 0; j < n; j++) {
        // Setting the flag variable.
        int isRotationPossible = 1;

        // Iterating through each rotation and checking character by character.
        for (int i = 0; i < n; i++) {
            if (p[(i + j) % n] != q[i]) {
                isRotationPossible = 0;
                break;
            }
        }

        // Checking if the flag is set to 1.
        if (isRotationPossible) {
            return 1;
        }
    }

    // If we were unable to cyclically rotate string 'p' right to form string 'q' then we will return 0.
    return 0;
}
