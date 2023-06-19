// Determine if Two Trees are Identical

class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2) {
        //Your Code here
        if(!r1 || !r2) return r1 == r2;
        bool l = isIdentical(r1->left,r2->left);
        bool r = isIdentical(r1->right,r2->right);
        return r1->data == r2->data && l && r;
    }
};
