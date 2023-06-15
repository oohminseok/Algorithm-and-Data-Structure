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

void PreTraverse(TreeNode* node)
{
	if (node==nullptr)
	{
		return;
	}

	std::cout << node->data << '\n';
	PreTraverse(node->left);
	PreTraverse(node->right);
}

void PostTraverse(TreeNode* node)
{
	if (node==nullptr)
	{
		return;
	}

	PostTraverse(node->left);
	PostTraverse(node->right);
	std::cout << node->data << '\n';
}

void DeleteTraverse(TreeNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	DeleteTraverse(node->left);
	node->left = nullptr;
	DeleteTraverse(node->right);
	node->right = nullptr;

}

int main()
{
	TreeNode node{};
	TreeNode leftnode{};
	TreeNode rightnode{};
        TreeNode leftnode2{};
	
	InsertData(node);
	InsertData(leftnode);
	InsertData(rightnode);
	InsertData(leftnode2);

	LeftLinkNode(node, &leftnode);
	RightLinkNode(node, &rightnode);

        LeftLinkNode(leftnode, &leftnode2);

	PreTraverse(&node);
	PostTraverse(&node);

	DeleteTraverse(&node);
}
