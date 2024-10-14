#include<iostream>
using namespace std;

struct node
{
   int data;
   node* left ;
   node* right;

   node(int datain)
   { 
       data = datain ; 
       left = NULL ;
       right = NULL ;
   }
};

class BST
{
   public:
   
   node* addBST( node* root , int datain )  // ADD NEW NODE? ROOT
   {
      if( root == NULL )
       {
          return new node(datain);
       }
       if( datain < root->data )
          root->left =  addBST( root->left , datain );
       else
          root->right = addBST( root->right , datain );
          
          return root ; 
   }
   
   bool deleteBST(node*& root, int dltKey) {
        if (root == NULL) {
            return false;
        }

        if (dltKey < root->data) 
        {
            return deleteBST(root->left, dltKey);
        } 
        else if (dltKey > root->data) 
        {
            return deleteBST(root->right, dltKey);
        } 
        else 
        {
            if (root->left == NULL)
            {
                node* temp = root;
                root = root->right;
                delete temp;
                return true;
            } 
            else if (root->right == NULL) 
            {
                node* temp = root;
                root = root->left;
                delete temp;
                return true;
            } 
            else 
            {
                int largest = findLargestBST(root->left);
                root->data = largest;
                return deleteBST(root->left, largest);
            }
        }
    }
   
    void preOrder( node* root )    //+AB
   {
      if( root != NULL )
      {
         cout<< root->data << " ";
         preOrder( root->left );
         preOrder( root->right );
      } 
   }
   
    void postOrder( node* root )    //AB+
   {
      if( root != NULL )
      {
         postOrder( root->left );
         postOrder( root->right );
         cout<< root->data << " ";
      } 
   }
   
    void inOrder( node* root )      //A+B
   {
      if( root != NULL )
      {
         inOrder( root->left );
         cout<< root->data << " ";
         inOrder( root->right );
      } 
   }
   
   int findLargestBST( node* root )   //LARGEST
   {
      if( root->right == NULL )
         return root->data;
      return findLargestBST( root->right );
   }
   
   int findSmallestBST( node* root )  //SMALLEST
   {
      if( root->left == NULL )
         return root->data;
      return findSmallestBST( root->left );
   }
   
   node* searchBST( node* root , int target )   //SEARCH
   {
       if     ( root == NULL )
           return NULL;
           
       if     ( target < root->data )
           return searchBST( root->left , target );
       else if( target > root->data )
           return searchBST( root->right , target );
       else
           return root ;
   }
};

int main()
{   BST t;
    int n = 0  , data , a , b ;
    node* root = NULL ;
    node* r = NULL;
    
     while( n != 7)
     {   
         cout << endl << "*************************************" << endl;
         cout << "Enter the choice to be performed :" << endl ;
         cout << "1. Insert Node \n2. Delete Node \n3. Search \n4. FindLargest \n5. FindSmallest \n6. PRE IN POST ORDER \n7. Exit " <<endl; 
         cin >> n ;
         
         switch(n)
         {
            case 1:
                   cout << "Enter data to be inserted :";
                   cin >> data;
                   root = t.addBST(root, data);
                   break;
            case 2:
                   cout << "Enter element to delete: ";
                   cin >> data;
                   if (t.deleteBST( root, data))
                      cout << "Element deleted." << endl;
                   else
                      cout << "Element not found." << endl;
                   break;
            case 3:
                   cout << "Enter Data to be searched :" ;
                   cin >> data ;
                   r = t.searchBST(root, data);
                   cout << data << " : " << (r != NULL ? "Found" : "Not Found") << endl;
                   break;
            case 4:
                   cout << "LARGEST:" ; 
                   a = t.findLargestBST(root);
                   cout << a << endl ; 
                   break;      
            case 5:
                   cout << "SMALLEST:" ;
                   b = t.findSmallestBST(root);
                   cout << b << endl ; 
                   break; 
            case 6:
                    cout << "PREORDER :" ;
                    t.preOrder(root);
                    cout<<endl;
    
                    cout << "INORDER  :" ;
                    t.inOrder(root);
                    cout<<endl;
     
                    cout << "POSTORDER:" ;
                    t.postOrder(root);
                    cout<<endl; 
                    break;
             case 7:
                    break; 
         }
         
     }
}
