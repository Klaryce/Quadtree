#ifndef BUILDTREE_H_INCLUDED
#define BUILDTREE_H_INCLUDED

Node *makeNode( double x, double y, int level );
void makeChildren( Node *parent );
void growTree(Node *parent);
void flagValue(Node *parent, double time);
void adapt(Node *node);
void destroyTree(Node *head);
void removeChildren( Node *parent );
void print_add_rem();
double nodeValue( Node *node, double time );
double value( double x, double y, double time );

#endif // BUILDTREE_H_INCLUDED
