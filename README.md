# ImprovedQuickUnion
Quick union cannot support large dynamic connectivity problems so we come up with an improved version of it called quick union with path compression.
We keep track of size of each tree. We use an array as the data structure,one to keep tabs on the size of the trees. Every node in the path point to its grandparent
thus halving the path length.
