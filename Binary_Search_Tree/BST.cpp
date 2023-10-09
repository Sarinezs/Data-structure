#include <bits/stdc++.h>
using namespace std;
class node{
	public:
		node *right;
		node *left;
		int value = 0;
		node(int v)
		{
			value = v;
			left = NULL;
			right = NULL;
		}
};
class tree{
	public:
		node *r;
		
		tree(int value)
		{
			r = new node(value);
		}
		
		bool search(int value)
		{
			node *n = r;
			while(true)
			{
				if(n->value > value && n->left != NULL)
				{
					n = n->left;
				}
				else if(n->value < value && n->right != NULL)
				{
					n = n->right;
				}
				else if(n->value == value)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
		
		void add_node(int value)
		{
			node *n = r;
			while(true)
			{
				if(n->value > value && n->left != NULL)
				{
					n = n->left;
				}
				else if(n->value <= value && n->right != NULL)
				{
					n = n->right;
				}
				else if(n->value > value && n->left == NULL)
				{
					n->left = new node(value);
					break;
				}
				else if(n->value <= value && n->right == NULL)
				{
					n->right = new node(value);
					break;
				}
				else{
					
					break;
				}
			}
		}
		void preorder_traversal(node *n)
		{
			if(n != NULL)
			{
				cout<<n->value<<",";
				preorder_traversal(n->left);
				preorder_traversal(n->right);
			}
		}
		void inorder_traversal(node *n)
		{
			if(n != NULL)
			{
				inorder_traversal(n->left);
				cout<<n->value<<",";
				inorder_traversal(n->right);
			}
		}
		void postorder_traversal(node *n)
		{
			if(n != NULL)
			{
				postorder_traversal(n->left);
				postorder_traversal(n->right);
				cout<<n->value<<",";
			}
		}
		int depth(int v)
		{
			int d = 0;
			node *n = r;
			while(true)
			{
				if(n->value > v && n->left != NULL)
				{
					n = n->left;
					d++;
				}
				else if(n->value < v && n->right != NULL)
				{
					n = n->right;
					d++;
				}
				else if(n->value == v)
				{
					return d;
				}
				else
				{
					return -1;
				}
			}
		}
		int h = 0, t_h = -1;
		void h_height(node *n)
		{
			if(n != NULL)
			{
				t_h++;
				h_height(n->left);
				h_height(n->right);
				if(t_h > h)
				{
					h = t_h;
				}
				t_h--;
			}
		}
		int height(int v)
		{
			node *n=r;
			while(true)
			{
				if(n->value > v && n->left != NULL)
				{
					n = n->left;
				}
				else if(n->value < v && n->right != NULL)
				{
					n = n->right;
				}
				else if(n->value == v)
				{
					h = 0, t_h = -1;
					h_height(n);
					return h;
				}
				else
				{
					return -1;
				}
			}
		}
		void print_level(node *n,int level)
		{
			if(level == 0)
			{
				cout<<n->value<<",";
			}
			else
			{
				if(n->left != NULL){ print_level(n->left,level-1); }
				if(n->right != NULL){ print_level(n->right,level-1); }
			}
		}
		void breadth_first_traversal()  // mode b
		{
			for(int i=0; i<=height(r->value); i++)
			{
				print_level(r,i);
				cout<<"|";
			}
			cout<<endl;
		}
		void delete_node_child(node *n)
		{
			if(n->right->left == NULL)
			{
				int s = n->right->value;
				delete_node(s);
				n->value = s;
			}
			else
			{
				node *tn = n->right;
				while(true)
				{
					if(tn->left == NULL)
					{
						break;
					}
					tn = tn->left;
				}
				int s = tn->value;
				delete_node(s);
				n->value = s;
			}
		}
		void delete_node(int v)
		{
			if(search(v))
			{
				if(r->value == v && r->left == NULL && 
					r->right == NULL)
				{
					return;
				}
				else if(r->value == v && r->left == NULL && 
					r->right != NULL)
				{
					r = r->right;
				}
				else if(r->value == v && r->left != NULL && 
					r->right == NULL)
				{
					r = r->left;
				}
				else if(r->value == v && r->left != NULL &&
					r->right != NULL)
				{
					delete_node_child(r);
				}
				else
				{
					node *p = r;
					while(true)
					{
						if(p->value > v && p->left != NULL)
						{
							node *c = p->left;
							if(c->value == v)
							{
								if(c->left == NULL &&
								   c->right == NULL)
								   {
								   	p->left = NULL;
								   	return;
								   }
								else if(c->left == NULL &&
									    c->right != NULL)
										{
											p->left = c->right;
											return;
										}
								else if(c->left != NULL &&
									    c->right == NULL)
										{
											p->left = c->left;
											return;
										}
								else if(c->left != NULL &&
									    c->right != NULL)
										{
											delete_node_child(c);
											return;
										}
							}
							p = p->left;
						}
						else if(p->value < v && p->right != NULL)
						{
							node *c = p->right;
							if(c->value == v)
							{
								if(c->left == NULL &&
								   c->right == NULL)
								   {
								   	p->right = NULL;
								   	return;
								   }
								else if(c->left == NULL &&
								        c->right != NULL)
										{
											p->right = c->right;
											return;
										}
								else if(c->left != NULL &&
								        c->right == NULL)
										{
											p->right = c->right;
											return;
										}
								else if(c->left != NULL &&
								        c->right != NULL)
										{
											delete_node_child(c);
											return;
										}
							}
							p = p->right;
						}
					}
				}
			}
		}
};
int main(){
	
    char mode;
    int loop = 0;
    tree t(loop);
    while (1) {
        cin >> mode;
        if (mode == 'a') {
            int num;
            cin >> num;
            if(loop == 0){
            	t.r->value = num;
            	loop++;
			}
			else{
				t.add_node(num);
			}
            
        }
        else if (mode == 'd') {
            int num;
            cin >> num;
            t.delete_node(num);
        }
        else if (mode == 'b') {
            t.breadth_first_traversal();
        }
        else if (mode == 'i') {
            t.inorder_traversal(t.r);
            cout << endl;
        }
        else if (mode == 'p') {
            t.preorder_traversal(t.r);
            cout << endl;
        }
        else if (mode == 't') {
            t.postorder_traversal(t.r);
            cout << endl;
        }
        else if (mode == 'x') {
            break;
        }
    }
    return 0;
}
