#include "tree_node.h"
#include <gtest/gtest.h>

#include <iostream>

void pathDiff(TreeNode::Ptr root, int max, int min, int& diff)
{
    if (!root) {
        int path_diff = abs(max - min);
        if (path_diff > diff) {
            diff = path_diff;
        }
        return;
    }

    int cur_max = max;
    int cur_min = min;

    if (root->val > max) {
        cur_max = root->val;
    } 
    if (root->val < min) {
        cur_min = root->val;
    }

    pathDiff(root->left, cur_max, cur_min, diff);
    pathDiff(root->right, cur_max, cur_min, diff);
}

int maxAncestorDiff(TreeNode::Ptr root)
{
    int max = 0;

    pathDiff(root, -1, 1e5, max);

    return max;
}

TEST(max_ancestor_diff, test1)
{
    TreeNode::Ptr root (new TreeNode(8));
    root->left.reset(new TreeNode(3));
    root->right.reset(new TreeNode(10));
    root->left->left.reset(new TreeNode(1));
    root->left->right.reset(new TreeNode(6));
    root->left->right->left.reset(new TreeNode(4));
    root->left->right->right.reset(new TreeNode(7));
    root->right->right.reset(new TreeNode(14));
    root->right->right->left.reset(new TreeNode(13));

    EXPECT_EQ(maxAncestorDiff(root), 7);
}

TEST(max_ancestor_diff, test2)
{
    TreeNode::Ptr root (new TreeNode(1));
    root->right.reset(new TreeNode(2));
    root->right->right.reset(new TreeNode(0));
    root->right->right->left.reset(new TreeNode(3));

    EXPECT_EQ(maxAncestorDiff(root), 3);
}