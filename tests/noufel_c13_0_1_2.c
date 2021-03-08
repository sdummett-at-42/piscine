#include <stdio.h>
 #include "ft_btree.h"
 #include <string.h>

 t_btree *btree_create_node(void *item);
 void    btree_apply_prefix(t_btree *root, void (*applyf)(void *));
 void    btree_apply_infix(t_btree *root, void (*applyf)(void *));

 void    aply(void *nimp)
 {
     printf("%s\n", nimp);
 }

 int main(void)
 {
     t_btree *root;
     char *a = "a-";
     char *b = "b-";
     char *c = "c-";
     char *d = "d-";
     char *e = "e-";
     char *f = "f-";
     char *r = "r-";

     root = btree_create_node((char*)r);
     root->left = btree_create_node((char*)a);
     root->right = btree_create_node((char*)b);
     root->left->left = btree_create_node((char*)c);
     root->left->right = btree_create_node((char*)d);
     root->right->left = btree_create_node((char*)e);
     root->right->right = btree_create_node((char*)f);
     btree_apply_infix(root, &aply);
 }
