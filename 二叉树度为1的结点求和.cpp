int sumSCNodes(struct BinTree *bt){
	if(bt==NULL) return 0;
	if((bt->right==NULL&&bt->left!=NULL)||(bt->left==NULL&&bt->right!=NULL)){
		return bt->data+sumSCNodes(bt->left)+sumSCNodes(bt->right);
	}
    return sumSCNodes(bt->left)+sumSCNodes(bt->right);
    
}
