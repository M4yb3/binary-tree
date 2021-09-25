#include <iostream>
#include <ctime>

class Tree {
	public:
		int value;
		Tree* left = nullptr;
		Tree* right = nullptr;
};

Tree* createTree(int depth) {
	Tree* baseTree = new Tree;
	baseTree->value = 1;

	if (depth > 1) {
		baseTree->left = createTree(depth - 1);
		baseTree->right = createTree(depth - 1);
	}

	return baseTree;
}

int calculate(Tree* tree) {
	return tree ? calculate(tree->left) + calculate(tree->right) + tree->value : 0;
}

int main() {
	srand(time(0));

	Tree* tree = createTree(3);
	std::cout << calculate(tree) << std::endl;

	return 0;
} 
