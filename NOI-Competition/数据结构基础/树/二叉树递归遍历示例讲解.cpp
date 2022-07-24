/*
中序遍历：左子树-> 根结点 -> 右子树
（先访问左子树，再访问根节点，后访问右子树，
而对于每个子树来说，又按照同样的访问顺序进行遍历）
先序遍历：根结点 -> 左子树 -> 右子树
后序遍历：左子树 -> 右子树 -> 根结点
*/

//先序
void PreOrder(node *root){
    if (root==NULL) return;
    else {
        printf("%d", root->data);
        PreOrder(root->lch);
        PreOrder(root->rch); 
    }
}
//中序
void InOrder(node *root){
    if (root==NULL) return;
    else {
        InOrder(root->lch);
        printf("%d", root->data);
        InOrder(root->rch); 
    }
}
//后序
void PostOrder(node *root){
    if (root==NULL) return;
    else {
        PostOrder(root->lch);
        PostOrder(root->rch);
        printf("%d", root->data); 
    }
}
