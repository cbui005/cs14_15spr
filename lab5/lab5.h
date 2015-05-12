/* Name: Calvin Bui
SID: 861064458
5/12/15 */
#ifndef BST_H
#define BST_H
#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>
#include <stack>
#include <iterator>

using namespace std;
#define nil 0

// #define Value int // restore for testing.
template < typename Value >
class BST {
    class Node { // binary tree node
        public:
            Node* left;
            Node* right;
            Value value;
            bool selected;
            Node( const Value v = Value() )
            : value(v), left(nil), right(nil), selected(false)
            {}
            Value& content() { return value; }
            bool isInternal() { return left != nil && right != nil; }
            bool isExternal() { return left != nil || right != nil; }
            bool isLeaf() { return left == nil && right == nil; }
            int height() {
                // returns the height of the subtree rooted at this node
                int leftLength = 0;
                if (left.isLeaf())
                {
                    left->height();
                }
                int rightLength = 0;
                if (right.isLeaf())
                {
                    right->height();
                }
                if (leftLength > rightLength)
                {
                    return leftLength+1;
                }
                else
                {
                    return rightLength+1;
                }
            }
            int size() {
            // returns the size of the subtree rooted at this node,
                if (this == nil)
                {
                    return 0;
                }
                return 1+ this->left->size() + this->right->size();
                
            }
            bool search(Value x)
            {
                if (x == this->value)
                {
                    return true;
                }
                else if (x < this->value)
                {
                    if (left == nil)
                    {
                        return false;
                    }
                    else
                    {
                        return left->search(x);
                    }
                }
                else if (x > this->value)
                {
                    if (right == nil)
                    {
                        return false;
                    }
                    else
                    {
                        return right->search(x);
                    }
                    return false;
                }
            }
    }; // Node
    // const Node* nil; // later nil will point to a sentinel node.
    
    int count;
    
    public:
        Node* root;
        int size() {
            if (root == nil)
            {
                return 0;
            }
            return 1+root->left->size() + root->right->size();

        // size of the overall tree.
        }
        bool empty() { return size() == 0; }
        void print_node( const Node* n ) {
            cout << n->value;
        // Print the node’s value.
        }
        bool search(Value x) {
            if (root == nil)
            {
                return false;
            }
            else
            {
                return root->search(x);
            }
        // search for a Value in the BST and return true iff it was found.
        // FILL IN
        }
        void preorder()const {
            preorder(root);
        // Traverse and print the tree one Value per line in preorder.
        // FILL IN
        }
        
        void preorder(Node* tmp) const {
            if (tmp == nil)
            {
                return;
            }
            cout << tmp->value << ' ';
            preorder(tmp->left);
            preorder(tmp->right);
        }
        
        void postorder()const {
            postorder(root);
        // Traverse and print the tree one Value per line in postorder.
        // FILL IN
        }
        
        void postorder(Node* tmp) const {
            if (tmp == nil)
            {
                return;
            }
            postorder(tmp->left);
            postorder(tmp->right);
            cout << tmp->value << ' ';
        }
        
        void inorder()const {
            inorder(root);
        // Traverse and print the tree one Value per line in inorder.
        // FILL IN
        }
        
        void inorder(Node* tmp) const
        {
            if (tmp == nil)
            {
                return;
            }
            inorder(tmp->left);
            cout << tmp->value << ' ';
            inorder(tmp->right);
        }
        Value& operator[] (int n) {
        //incomplete
        // returns reference to the value field of the n-th Node.
        // FILL IN

        }
        BST() : count(0), root(nil) {}
        void insert( Value X ) { root = insert( X, root ); }
        Node* insert( Value X, Node* T ) {
            // The normal binary-tree insertion procedure ...
            if ( T == nil ) {
                T = new Node( X ); // the only place that T gets updated.
            } else if ( X < T->value ) {
                T->left = insert( X, T->left );
            } else if ( X > T->value ) {
                T->right = insert( X, T->right );
            } else {
                T->value = X;
            }
            // later, rebalancing code will be installed here
            return T;
        }
        void remove( Value X ) { root = remove( X, root ); }
        Node* remove( Value X, Node*& T ) {
            // The normal binary-tree removal procedure ...
            // Weiss’s code is faster but way more intricate.
            if ( T != nil ) {
                if ( X > T->value ) {
                    T->right = remove( X, T->right );
                } else if ( X < T->value ) {
                    T->left = remove( X, T->left );
                } else { // X == T->value
                    if ( T->right != nil ) {
                    Node* x = T->right;
                    while ( x->left != nil ) x = x->left;
                    T->value = x->value; // successor’s value
                    T->right = remove( T->value, T->right );
                    } else if ( T->left != nil ) {
                        Node* x = T->left;
                        while ( x->right != nil ) x = x->right;
                        T->value = x->value; // predecessor’s value
                        T->left = remove( T->value, T->left );
                    } else { // *T is external
                        delete T;
                        T = nil; // the only updating of T
                    }
                }
            }
            // later, rebalancing code will be installed here
            return T;
        }
        void okay( ) { okay( root ); }
        void okay( Node* T ) {
        // diagnostic code can be installed here
        return;
        }
        void minCover() 
        {
            cout << "Part 1" << endl;
            if (root == nil)
            {
                return;
            }
            if (root->left != nil)
            {
                root->left->selected = true;
            }
            if (root->left->right != nil)
            {
                root->left->right->selected = true;
            }
            if (root->right != nil)
            {
                root->right->selected = true;
            }
            if (root->right->left != nil)
            {
                root->right->left->selected = true;
            }
        }
        
        void displayMinCover() 
        {
            int cnt = 0;
            displayMinCover(root,cnt);
            cout<< endl << cnt << endl;
        }
        
        void displayMinCover(Node* tmp,int&x) const
        {
            if (tmp == nil)
            {
                return;
            }
            if (tmp->selected)
            {
                x++;
                cout << tmp->value << ' ';
            }
            displayMinCover(tmp->left,x);
            displayMinCover(tmp->right,x);
        }
        void findSumPath(Node*n, int sum, int buffer[])
        {
            int t = 0;
            int i = 0;
            cout << "Part 2" << endl;
            findSumPath(root,sum,buffer,i,t);
        }
        
        void findSumPath(Node* n, int sum, int buffer[], int i, int t)
        {
            if (n == nil)
            {
                return;
            }
            buffer[i] = n->value;
            i++;
            if (n->left == nil && n->right == nil)
            {
                t = 0;
                for (int a = 0; a < i; a++)
                {
                    t+= buffer[a];
                }
                if (t == sum)
                {
                    stack<int>tmp;
                    for (int a = 0; a < i; a++)
                    {
                        tmp.push(buffer[a]);
                    }
                    while(!tmp.empty())
                    {
                        cout << tmp.top() << ' ';
                        tmp.pop();
                    }
                    cout << endl;
                }
            }
            else
            {
                findSumPath(n->right,sum,buffer,i,t);
                findSumPath(n->left,sum,buffer,i,t);
            }
        }

        void printVertSum()
        {
            map<int,int>tmp;
            vertSum(root,0,tmp);
            cout << "Part 3" << endl;
            for (map<int,int>::iterator it = tmp.begin(); it != tmp.end(); it++)
            {
                cout << it->second << ' ';
            }
            cout << endl;
        }
        void vertSum(Node* node, int hd, std::map<int,int>&m)
        {
            if (node == nil)
            {
                return;
            }
            m[hd] += node->value;
            vertSum(node->left,hd-1,m);
            vertSum(node->right,hd+1,m);
            
        }
}; // BST
#endif
