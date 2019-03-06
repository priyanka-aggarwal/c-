#include<iostream>
using namespace std;

class bstnode
{
      int info;
      bstnode *left, *right;
      public:
             bstnode(int i, bstnode *l=NULL, bstnode *r=NULL)
             {
                         info=i;
                         left=l;
                         right=r;
             }
             friend class bstree;
};

class bstree
{
      bstnode *root;
      public:
      	     bstree()
      	     {
      	     	root=NULL;
      	     }
             void insert(int);
             void preorder(bstnode *temp);
             bstnode* getroot();
             void postorder(bstnode *temp);
             void inorder(bstnode *temp);
};

bstnode* bstree::getroot()
{
	return root;
}

void bstree::postorder(bstnode *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		cout<<temp->info<<"\t";
		
	}
	else if(root==NULL)
          cout<<"Tree is empty";
}

void bstree::inorder(bstnode *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		cout<<temp->info<<"\t";
		inorder(temp->right);	
	}
	else if(root==NULL)
          cout<<"Tree is empty";
}


void bstree::preorder(bstnode *temp)
{
        if(temp!=NULL)
        {
        	cout<<temp->info <<"\t";
        	preorder(temp->left);
        	preorder(temp->right);
        }
        else if(root==NULL)
          cout<<"Tree is empty";
}

void bstree::insert(int x)
{
     bstnode *prev=0, *temp;
     bstnode *n=new bstnode(x);
     if(root==NULL)
     { 
	    root=n;
     }
     else
     {
     	 temp=root;
         while(temp!=NULL)
         {
                          prev=temp;
                          if(x < (temp->info))
                            {
                                          temp=temp->left;
                                        
                            }
                          else
                            {
                                          temp= temp->right;
                                        
                            }
         }
         if(x< (prev->info))
         {
              prev->left=n;
         }
         else
         {
              prev->right=n;
         }
     }     
}

int main()
{
    bstree b1;
    int ch,x;
    bstnode *temp;
    char z;
    do
    {
        cout<<"\n\nMAIN MENU \n1.Insert an element in tree \n2.Traverse the tree in preorder \n3.Traverse the tree in postorder \n4.Treverse the tree in inorder";
        cout<<"\n\nEnter your choice\t";
        cin>>ch;
        switch(ch)
        {
              case 1:cout<<"\nEnter the element to insert\t";
                     cin>>x;
                     b1.insert(x);
                     break;
                     
              case 2:cout<<"\nTree in preorder traversal: \n";
                     temp=b1.getroot();
                     b1.preorder(temp);
                     break;
                     
              case 3:cout<<"\nTree in postorder traversal: \n";
                     temp=b1.getroot();
                     b1.postorder(temp);
                     break;
                     
              case 4:cout<<"\nTree in postorder traversal: \n";
                     temp=b1.getroot();
                     b1.inorder(temp);
                     break;
                              
        }
        cout<<"\n\nDo you wish to continue (Yes/No)\t";
        cin>>z;
    }while(z=='y' || z=='Y');
    return 0;
}
