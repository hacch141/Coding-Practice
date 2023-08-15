// Check If One String Is A Rotation Of Another String




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
