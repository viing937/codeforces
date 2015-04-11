#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
};

struct Node *Insert( struct Node *tree, int x )
{
    if ( tree == NULL )
    {
        tree = (struct Node *)malloc(sizeof(struct Node));
        tree->key = x;
        tree->left = NULL;
        tree->right = NULL;
    }
    else
    {
        if ( x > tree->key )
            tree->right = Insert( tree->right, x );
        else if ( x < tree->key )
            tree->left = Insert( tree->left, x );
    }
    return tree;
}

struct Node *FindMin( struct Node *tree )
{
    if ( tree == NULL )
        printf( "Error\n" );
    else while ( tree->left )
        tree = tree->left;
    return tree;
}

struct Node *Delete( struct Node *tree, int x )
{
    struct Node *tmp;
    if ( tree == NULL )
        printf( "Element %d not found\n", x );
    else if ( x < tree->key )
        tree->left = Delete( tree->left, x );
    else if ( x > tree->key )
        tree->right = Delete( tree->right, x );
    else if ( tree->left && tree->right )
    {
        tmp = FindMin( tree->right );
        tree->key = tmp->key;
        tree->right = Delete( tree->right, tree->key );
    }
    else
    {
        tmp = tree;
        if ( tree->left == NULL )
            tree = tree->right;
        else if ( tree->right == NULL )
            tree = tree->left;
        free( tmp );
    }
    return tree;
}

void Inorder_Traversal( struct Node *tree )
{
    if ( tree )
    {
        Inorder_Traversal( tree->left );
        printf( "%d\n", tree->key );
        Inorder_Traversal( tree->right );
    }
    return;
}

void Preorder_Traversal( struct Node *tree )
{
    if ( tree )
    {
        printf( "%d\n", tree->key );
        Preorder_Traversal( tree->left );
        Preorder_Traversal( tree->right );
    }
    return;
}
void Postorder_Traversal( struct Node *tree )
{
    if ( tree )
    {
        Postorder_Traversal( tree->left );
        Postorder_Traversal( tree->right );
        printf( "%d\n", tree->key );
    }
    return;
} 

struct Node *Search( struct Node *tree, int x )
{
    if ( tree )
    {
        if ( tree->key == x )
            return tree;
        else if ( x > tree->key && tree->right )
            return Search( tree->right, x );
        else if ( x < tree->key && tree->left )
            return Search( tree->left, x );
    }
    return NULL;
}

int main()
{
    struct Node *tree = NULL;
    tree = Insert( tree, 5 );
    tree = Insert( tree, 10 );
    tree = Insert( tree, 18 );
    tree = Insert( tree, 1 );
    tree = Insert( tree, 12 );
    tree = Delete( tree, 12 );
    tree = Insert( tree, 3 );
    tree = Insert( tree, 4 );

    Inorder_Traversal( tree );
    //Preorder_Traversal( tree );
    //Postorder_Traversal( tree );

    struct Node *position = Search( tree, 3 );
    if ( position )
        printf( "target: %d\n", position->key );
    else
        printf( "target not fount\n" );
    return 0;
}
