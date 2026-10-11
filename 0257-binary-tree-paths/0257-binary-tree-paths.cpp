class Solution{
public:
	void dfs(TreeNode* root, string& path,
	vector<string> & ans){
	if(root ==  nullptr){
	return;
	}
	//save the original path length for back-tracking
	int len = path.size();
	if(!path.empty()){
	path+="->";
	}
	path+=to_string(root->val);
	
	//If leaf node - save the complete path
	if(root->left == nullptr && root->right == nullptr){
	ans.push_back(path);
	}
	else{
	dfs(root->left, path,ans);
	dfs(root->right,path,ans);
	}
	//Backtrack :
	
	path.resize(len);
 }
 
 vector<string> binaryTreePaths(TreeNode* root){
 vector<string> ans;
 string path;
 dfs(root,path, ans);
 return ans;
 }
 
};