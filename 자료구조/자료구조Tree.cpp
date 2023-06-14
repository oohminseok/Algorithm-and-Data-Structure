#include <iostream>

struct TreeNode
{
	int data;
	TreeNode* left;
	TreeNode* right;
};

void InsertData(TreeNode& node)
{
	int data;
	std::cin >> data;

	node.data = data;
}

void LeftLinkNode(TreeNode& node,TreeNode* Subnode)
{
	if (node.left == nullptr)
	{
		node.left = Subnode;
	}
	else
	{
		return;
	}
}
void RightLinkNode(TreeNode& node, TreeNode* Subnode)
{
	if (node.right== nullptr)
	{
		node.right = Subnode;
	}
	else
	{
		return;
	}
}

int main()
{
	TreeNode node{};
	TreeNode leftnode{};
	TreeNode rightnode{};

	InsertData(node);
	InsertData(leftnode);
	InsertData(rightnode);

	LeftLinkNode(node, &leftnode);
	RightLinkNode(node, &rightnode);

}