#ifndef tree_h
#define tree_h

#define MAXNUMLINES 30


//-------------------------------------------------
typedef struct tnode tnode;
struct tnode {
  const char* word;
  int count;
  tnode* left;
  tnode* right;
  int lines[MAXNUMLINES];
  int numlines;
};


typedef struct tree tree;
struct tree {
  tnode* root;
  size_t size;
};


//-------------------------------------------------
tnode* tnode_create(const char* word, int line);
tree* tree_create(void);

void tree_delete(tree* t);
void tree_clear(tree* t);

bool tree_empty(tree* t);
size_t tree_size(tree* t);

tnode* tree_add(tree* t, const char* word, int line);
void tree_print(tree* t);    // INORDER-printing

void tree_print_preorder(tree* t);
void tree_print_postorder(tree* t);
void tree_print_levelorder(tree* t);

void tree_test(void);

#endif /* tree_h */