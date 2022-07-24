/*
���������������-> ����� -> ������
���ȷ������������ٷ��ʸ��ڵ㣬�������������
������ÿ��������˵���ְ���ͬ���ķ���˳����б�����
�������������� -> ������ -> ������
��������������� -> ������ -> �����
*/

//����
void PreOrder(node *root){
    if (root==NULL) return;
    else {
        printf("%d", root->data);
        PreOrder(root->lch);
        PreOrder(root->rch); 
    }
}
//����
void InOrder(node *root){
    if (root==NULL) return;
    else {
        InOrder(root->lch);
        printf("%d", root->data);
        InOrder(root->rch); 
    }
}
//����
void PostOrder(node *root){
    if (root==NULL) return;
    else {
        PostOrder(root->lch);
        PostOrder(root->rch);
        printf("%d", root->data); 
    }
}
