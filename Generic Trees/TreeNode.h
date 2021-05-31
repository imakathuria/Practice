#include<vector>
template <typename T>
class TreeNode{
public:
    T data;
    vector<TreeNode*>children;
    TreeNode(T d){
        this->data=d;
    }
};
