void NRpostorder(TreeNode *root)
{
 stack<Node *> s;
    s.push(root);
    while(!s.empty())
    {
        root = s.top();
        s.pop();
        if(root == NULL)
        {
            continue;
        }
        else
        {
            print("%d ",root->v);
            s.push(root->right);
            s.push(root->left);
        }
    }
}