int nc (bstnode* root){
int x,y;
if(root!=NULL){
    x=(nc(root->right));
    y=(nc(root->left));
    return x+y+1;
}
return 0;
}