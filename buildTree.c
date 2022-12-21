#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "treeStructure.h"
#include "buildTree.h"
#include "writeTree.h"

int add = 0;
int rem = 0;

Node *makeNode( double x, double y, int level ) {

  int i;

  Node *node = (Node *)malloc(sizeof(Node));

  node->level = level;

  node->xy[0] = x;
  node->xy[1] = y;

  node->flag = 0;

  for( i=0;i<4;++i )
    node->child[i] = NULL;
  return node;
}

void makeChildren( Node *parent ) {

  double x = parent->xy[0];
  double y = parent->xy[1];

  int level = parent->level;

  double hChild = pow(2.0,-(level+1));

  parent->child[0] = makeNode( x,y, level+1 );
  parent->child[1] = makeNode( x+hChild,y, level+1 );
  parent->child[2] = makeNode( x+hChild,y+hChild, level+1 );
  parent->child[3] = makeNode( x,y+hChild, level+1 );

  return;
}

void growTree(Node *parent){

  int level = parent->level;
  if (level == 3)
  {
    return;
  }
  makeChildren(parent);
  growTree(parent->child[0]);
  growTree(parent->child[1]);
  growTree(parent->child[2]);
  growTree(parent->child[3]);
}

//free memory for all tree nodes



void destroyTree(Node *head){

  int i;
  if(head->child[0] != NULL)
  {
	for(i=0;i<4;i++){
      destroyTree(head->child[i]);
	}
	free(head);
   }
     else
    {
        free(head);
    }
}

// remove children from one parent node

void removeChildren( Node *parent ){

  int i;
  for(i=0;i<4;i++)
  {
      free(parent->child[i]);
      parent->child[i] = NULL;
  }
}

void flagValue(Node *node, double time){

  double v=0.0;
  v = nodeValue(node,time);
  int i;
    if(node->child[0] == NULL){
        if(v > 0.5){
        node->flag = 1;
      }
      if(v < -0.5){
        node->flag = -1;
      }
    }
    else{
        for(i=0;i<4;i++){
            flagValue(node->child[i],time);
        }
    }

    adapt(node);
  return;
}


void adapt(Node *node){

  int i;
  int n = 0;
  if(node->level == 6)
  {
         return;
  }
  if(node->flag == 1)
  {
      makeChildren(node);
      add+=4;
      for(i=0;i<4;i++){
        flagValue(node->child[i],0.0);
      }
  }
  if(node->child[0] != NULL){
     n = (node->child[0])->flag + (node->child[1])->flag + (node->child[2])->flag + (node->child[3])->flag;
     if(n == -4){
       printf("%d\n",n);
       removeChildren(node);
       rem+=4;
    }
  }

  printf("add Children: %d\n", add);
  printf("remove Children: %d\n", rem);
  return;
}


// Evaluate function at centre of quadtree node

double nodeValue( Node *node, double time ) {

  int level = node->level;
  double x = node->xy[0];
  double y = node->xy[1];

  double h = pow(2.0,-level);

  return( value( x+0.5*h, y+0.5*h, time ) );
}

// Data function

double value( double x, double y, double time ) {

  return( 2.0*exp(-8.0*(x-time)*(x-time)) - 1.0 ) ;
}

