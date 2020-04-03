/* A O(n^2) program for construction of BST from preorder traversal */
#include <bits/stdc++.h> 
using namespace std; 

/* A binary tree node has data, pointer to left child 
and a pointer to right child */
class node 
{ 
	public: 
	int data; 
	node *left; 
	node *right; 
}; 

// A utility function to create a node 
node* newNode (int data) 
{ 
	node* temp = new node(); 

	temp->data = data; 
	temp->left = temp->right = NULL; 

	return temp; 
} 

// A recursive function to construct Full from pre[]. preIndex is used 
// to keep track of index in pre[]. 
node* constructTreeUtil (int pre[], int* preIndex, 
								int low, int high, int size) 
{ 
	// Base case 
	if (*preIndex >= size || low > high) 
		return NULL; 

	// The first node in preorder traversal is root. So take the node at 
	// preIndex from pre[] and make it root, and increment preIndex 
	node* root = newNode ( pre[*preIndex] ); 
	*preIndex = *preIndex + 1; 

	// If the current subarry has only one element, no need to recur 
	if (low == high) 
		return root; 

	// Search for the first element greater than root 
	int i; 
	for ( i = low; i <= high; ++i ) 
		if ( pre[ i ] > root->data ) 
			break; 

	// Use the index of element found in preorder to divide 
		// preorder array in two parts. Left subtree and right subtree 
	root->left = constructTreeUtil ( pre, preIndex, *preIndex, 
										i - 1, size ); 
	root->right = constructTreeUtil ( pre, preIndex, i, high, size ); 

	return root; 
} 

// The main function to construct BST from given preorder traversal. 
// This function mainly uses constructTreeUtil() 
node *constructTree (int pre[], int size) 
{ 
	int preIndex = 0; 
	return constructTreeUtil (pre, &preIndex, 0, size - 1, size); 
} 

// A utility function to print inorder traversal of a Binary Tree 
void printInorder (node* node) 
{ 
	if (node == NULL) 
		return; 
	printInorder(node->left); 
	cout<<node->data<<" "; 
	printInorder(node->right); 
} 
 int findMax(node* root1)  
{  
    // Base case  
    if (root1 == NULL)  
    return INT_MIN;  
  
    // Return maximum of 3 values:  
    // 1) Root's data 2) Max in Left Subtree  
    // 3) Max in right subtree  
    int res = root1->data;  
    int lres = findMax(root1->left);  
    int rres = findMax(root1->right);  
    if (lres > res)  
    res = lres;  
    if (rres > res)  
    res = rres;  
    return res;  
}
int findMin( node* root1) 
{ 
    // Base case 
    if (root1 == NULL) 
      return INT_MAX; 
  
    // Return minimum of 3 values: 
    // 1) Root's data 2) Max in Left Subtree 
    // 3) Max in right subtree 
    int res = root1->data; 
    int lres = findMin(root1->left); 
    int rres = findMin(root1->right); 
    if (lres < res) 
      res = lres; 
    if (rres < res) 
      res = rres; 
    return res; 
} 

// Driver program to test above functions 
int main () 
{ 
    
	
	int N;
	cin>>N;
	int pre[N] ;
	for(int i=0;i<N;i++)
	{
	    cin>>pre[i];
	}
	
	//{10, 5, 1, 7, 40, 50}; 
	int size = sizeof( pre ) / sizeof( pre[0] ); 

	node *root = constructTree(pre, size); 

//cout<<"Inorder traversal of the constructed tree: \n"; 
	//printInorder(root); 
   int max= findMax(root);
   int min= findMin(root);
   cout << max <<endl<<min;
	return 0; 
} 



// This code is contributed by rathbhupendra 
