#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "treeStructure.h"
#include "buildTree.h"
#include "writeTree.h"


int main( int argc, char **argv ) {

  Node *head;

  // make the head node
  head = makeNode( 0.0,0.0, 0 );

  // make a tree
  growTree(head);

  flagValue(head,0.0);

  writeTree(head);

  destroyTree(head);

  return 0;
}
