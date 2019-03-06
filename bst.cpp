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
             void del_copy(int);
             void postorder(bstnode *temp);
             void inorder(bstnode *temp);
             int search(int);
             void Level(bstnode *temp, int level);
             void giveLevel(bstnode *temp);
             int height(bstnode *t);
             void del_merge(int);
             int leafnodes(bstnode *temp);
             int nleafnodes(bstnode *temp);
             void givemirror(bstnode *temp);
             void mirror(bstnode *temp,int level);
};

bstnode* bstree::getroot()
{
	return root;
}


int bstree::nleafnodes(bstnode *temp)
{
	if((temp==NULL)||((temp->right==NULL)&&(temp->left==NULL)))
	   return 0;
	else
	   return 1+(nleafnodes(temp->left)+ nleafnodes(temp->right));
}

int bstree::leafnodes(bstnode *temp)
{
	if(temp==NULL)
	   return 0;
	else if((temp->left==NULL) && (temp->right==NULL))
	    return 1;
	else
	    return (leafnodes(temp->left)+ leafnodes(temp->right));
}

void bstree::del_merge(int x)
{
	bstnode *temp = root;
    bstnode *prev=0;
    bstnode *t=0;
    int flag=0;
    while(flag!=1)
    {
       if(x==temp->info)
       {
            if((temp->right ==NULL) && (temp->left ==NULL))
               {
               	flag=1;
               	delete temp;
               }
            else if(((temp->right ==NULL)&&(temp->left !=NULL)) || ((temp->left ==NULL) && (temp->right!=NULL)))
            {
                 if(temp->right!=NULL)
                   prev->right=temp->right;
                 else
                 prev->left=temp->left; 
                 flag=1;
                 delete temp;
            } 
            else
            {
                t=temp;
                temp=temp->left;
                while(temp->right!=NULL)
                   	temp=temp->right;
                temp->right=t->right;
                if(t!=root)
                  {
                  	if(x<prev->info)
                  	   prev->left=t->left;
                  	else
                  	   prev->right=t->left;
                  }
                else
                    root=t->left;
                delete t;
                flag=1;
            }
       }
       else if(x >temp->info)
       {
            prev=temp;
            temp=temp->right;
       }
       else if(x<temp->info)
       {
            prev=temp;
            temp=temp->left;
       }  
    }
}

void bstree::giveLevel(bstnode *temp) 
{ 
    int h = height(temp);
	int i; 
    for ( i=1; i<=h; i++) 
        Level(temp, i); 
} 

void bstree::Level(bstnode *temp, int level)
{
   if (temp==NULL) 
        return; 
    if (level == 1) 
        cout<< temp->info<<"\t"; 
    else if (level > 1) 
    { 
        Level(temp->left, level-1); 
        Level(temp->right, level-1); 
    }  
}

void bstree::givemirror(bstnode *temp) 
{ 
    int h = height(temp);
	int i; 
    for ( i=1; i<=h; i++) 
        mirror(temp, i); 
} 

void bstree::mirror(bstnode *temp, int level)
{
	if (temp==NULL) 
        return; 
    if (level == 1) 
        cout<<temp->info<<"\t";
    else if (level > 1) 
    { 
        mirror(temp->right, level-1); 
        mirror(temp->left, level-1); 
    }  
}

int bstree::height(bstnode *t) 
{ 
    if (t==NULL) 
        return 0; 
    else
    { 
        int lh = height(t->left); 
        int rh = height(t->right); 
  
        if (lh > rh) 
            return(lh+1); 
        else return(rh+1); 
    } 
} 



int bstree::search(int x)
{
	 bstnode *temp=root;
	 int flag=0;
	 while(temp!=NULL)
	 {
	    if(x==temp->info)
	    	{
			  flag=1;
              return flag;
            }
        else if(x >temp->info)
            temp=temp->right;
        else if(x<temp->info)
            temp=temp->left;
     }
    return flag;
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
	    root=n;
     else
     {
     	 temp=root;
         while(temp!=NULL)
         {
                          prev=temp;
                          if(x < (temp->info))
                                          temp=temp->left;
                          else
                                          temp= temp->right;
         }
         if(x< (prev->info))
         prev->left=n;
         else
         prev->right=n;
     }     
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

void bstree::del_copy(int x)
{
	if(root==NULL)
	 {
	 	cout<<"Tree is empty";
	 	return;
	 }
    bstnode *temp = root;
    bstnode *prev=0;
    bstnode *t=0;
    int flag=0;
    while(flag!=1)
    {
       if(x==temp->info)
       {
            if((temp->right ==NULL) && (temp->left ==NULL))
               {
			     flag=1;
			     if(prev->info<temp->info)
			        prev->right=NULL;
			     else 
			        prev->left=NULL;
		       }
            else if(((temp->right ==NULL)&&(temp->left !=NULL)) || ((temp->left ==NULL) && (temp->right!=NULL)))
            {
                 if(temp->right!=NULL)
                   prev->right=temp->right;
                 else
                 prev->left=temp->left; 
                 flag=1;
            } 
            else
            {
                t=temp;
                prev=temp;
                temp=temp->left;
                while(temp->right!=NULL)
                {
                   	prev=temp;
                   	temp=temp->right;
               	}
                if(temp->left!=NULL)
                   prev->right=temp->left;
                t->info=temp->info;
                flag=1;
                if((temp->right==NULL)  && (temp->left==NULL))
                	t->left=NULL;
           }
       }
       else if(x >temp->info)
       {
            prev=temp;
            temp=temp->right;
       }
       else if(x<temp->info)
       {
            prev=temp;
            temp=temp->left;
       }  
    }
    delete temp;
}

int main()
{
    bstree b1;
    int ch,x;
    char z;
    do
    {
        cout<<"\n\nMAIN MENU \n1.Insert an element in tree \n2.Traverse the tree in preorder\n3.Traverse the tree in postorder \n4.Treverse the tree in inorder";
        cout<<"\n5.Deletion by copying \n6.Search an element in tree \n7.Height of tree \n8.Traverse tree level-by-level"<<endl;
        cout<<"9.Deletion by merging \n10.Number of leaf nodes \n11.Number of non-leaf nodes \n12.Mirror image of tree";
        cout<<"\n\nEnter your choice\t";
        cin>>ch;
        switch(ch)
        {
              case 1:{
			  		 	cout<<"\nEnter the element to insert\t";
                     	cin>>x;
                     	b1.insert(x);
					 }
                     break;
                     
              case 2:{
				  		 cout<<"\nTree in preorder traversal:";
	                     bstnode *temp=b1.getroot();
	                     b1.preorder(temp);
					 }
                     break;
                    
             case 3:{
			 			cout<<"\nTree in postorder traversal: \n";
                        bstnode *temp=b1.getroot();
                    	b1.postorder(temp);
                    }
                    break;
                     
              case 4:{
			  			cout<<"\nTree in postorder traversal: \n";
                     	bstnode *temp=b1.getroot();
                    	b1.inorder(temp);
                     }
                     break;
                     
              case 5:{
			  			cout<<"\nEnter the element you wish to delete";
                     	cin>>x;
                    	b1.del_copy(x);
                     	cout<<"\nElement is deleted";
                     }
                     break; 
             case 6:{
             	        cout<<"\nEnter the element you wish to search";
                     	cin>>x;
                    	int flag=b1.search(x);
                    	if(flag==1)
                     		cout<<"\nElement is found";
                     	else
                     		cout<<"\nElement not found";
             	    }
             	    break;
             	    
            case 7:{
            	        cout<<"\nHeight of tree is";
            	        bstnode *temp=b1.getroot();
						int h=b1.height(temp);
						cout<<"  "<<h;
            	   }
				   break;
				
			case 8:{
				        cout<<"\nTree in level-by-level traversal: \n";
                     	bstnode *temp=b1.getroot();
                    	b1.giveLevel(temp);         
				   }
			       break;
                    
            case 9:{
            	        cout<<"\nEnter the element you wish to delete";
                     	cin>>x;
						b1.del_merge(x);      
            	        cout<<"\nElement is deleted"; 
                   }
                   break;
                
            case 10:{
            	       bstnode *temp=b1.getroot();
            	       x=b1.leafnodes(temp);
            	       cout<<"\nNumber of leaf nodes"<<x;
                    }
                    break;
            case 11:{
            	       bstnode *temp=b1.getroot();
                       x=b1.nleafnodes(temp);
            	       cout<<"\nNumber of non-leaf nodes"<<x;
                    }
            	    break;
            	    
            case 12:{
            	       cout<<"Level-by-level traversal of mirror image of tree";
            	       bstnode *temp=b1.getroot();
            	       b1.givemirror(temp);
                    }
            	    break;
            	    
            default:cout<<"WRONG CHOICE";
                     break;
                   
        }
        cout<<"\n\nDo you wish to continue (Yes/No)\t";
        cin>>z;
    }while(z=='y' || z=='Y');
    return 0;
}
