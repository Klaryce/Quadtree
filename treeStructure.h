#ifndef TREESTRUCTURE_H_INCLUDED
#define TREESTRUCTURE_H_INCLUDED

struct qnode {
  int level;
  double xy[2];
  struct qnode *child[4];
  int flag;
};
typedef struct qnode Node;


#endif // TREESTRUCTURE_H_INCLUDED
