// 2096. Step-By-Step Directions From a Binary Tree Node to Another

class Solution {
public:
    TreeNode* get_lca(TreeNode* root, int startValue, int destValue) {
        if(!root) return NULL;
        if(root->val == startValue || root->val == destValue) return root;
        TreeNode* l = get_lca(root->left, startValue, destValue);
        TreeNode* r = get_lca(root->right, startValue, destValue);
        return l && r ? root : l ? l : r;
    }

    void get_root_to_val_path(TreeNode* root, int val, string& curr, string& path) {
        if(!root) return;

        if(root->val == val) {
            path = curr;
            return;
        }

        curr.push_back('L');
        get_root_to_val_path(root->left, val, curr, path);
        curr.pop_back();

        curr.push_back('R');
        get_root_to_val_path(root->right, val, curr, path);
        curr.pop_back();
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = get_lca(root, startValue, destValue);
        string up, down, curr = "";
        get_root_to_val_path(lca, startValue, curr, up);
        get_root_to_val_path(lca, destValue, curr, down);
        return string(up.length(), 'U') + down;
    }
};

//Approach-1 (Using LCA)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, int src, int dest) {
        if(!root)
            return NULL;
        
        if(root->val == src || root->val == dest)
            return root;
        
        TreeNode* l = lowestCommonAncestor(root->left,  src, dest);
        TreeNode* r = lowestCommonAncestor(root->right, src, dest);
        
        if(l && r)
            return root;
        
        return l ? l : r;
    }

    bool findPath(TreeNode* LCA, int target, string& path) {
        if(LCA == NULL) {
            return false;
        }

        if(LCA->val == target) {
            return true;
        }

        //explore Left
        path.push_back('L');
        if(findPath(LCA->left, target, path) == true) {
            return true;
        }

        path.pop_back();

        //explore right
        path.push_back('R');
        if(findPath(LCA->right, target, path) == true) {
            return true;
        }

        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA = lowestCommonAncestor(root, startValue, destValue);

        string lcaTOSrc  = "";
        string lcaTODest = "";

        findPath(LCA, startValue, lcaTOSrc);
        findPath(LCA, destValue, lcaTODest);

        string result = "";

        for(int i = 0; i < lcaTOSrc.length(); i++) {
            result.push_back('U');
        }

        result += lcaTODest;

        return result;
    }
};



//Approach-2 (Without finding LCA)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:

    bool findPath(TreeNode* LCA, int target, string& path) {
        if(LCA == NULL) {
            return false;
        }

        if(LCA->val == target) {
            return true;
        }

        //explore Left
        path.push_back('L');
        if(findPath(LCA->left, target, path) == true) {
            return true;
        }

        path.pop_back();

        //explore right
        path.push_back('R');
        if(findPath(LCA->right, target, path) == true) {
            return true;
        }

        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        string rootToSrc  = "";
        string rootToDst = "";

        findPath(root, startValue, rootToSrc); //O(n)
        findPath(root, destValue,  rootToDst); //O(n)


        int l = 0; //commonPathLength
        while(l < rootToSrc.length() && l < rootToDst.length() && rootToSrc[l] == rootToDst[l]) {
            l++;
        }

        string result = "";
        //Add "U"
        for(int i = 0; i < rootToSrc.length() - l; i++) {
            result.push_back('U');
        }

        for(int i = l; i < rootToDst.length(); i++) {
            result.push_back(rootToDst[i]);
        }

        return result;
    }
};
