void preorder(bstnode* root ){
if (root!=NULL)
    {



    preorder(root->left);
    cout<<root->data<<"\n";


    preorder(root->right);
}}
