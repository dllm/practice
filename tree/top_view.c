
/*
 *
 *   basically, post order on left and pre order on right
 *
 *
 * */



static void top_view_post_order(node* root)
{
	    if (!root) return;
	    	top_view_post_order(root->left);
		    cout << root->data << " ";
}
	static void top_view_pre_order(node* root)
{
	    if (!root) return;
	    	cout << root->data << " ";
		    top_view_pre_order(root->right);
}
	void top_view(node * root)
{
	    top_view_post_order(root);
	        top_view_pre_order(root->right);
}
