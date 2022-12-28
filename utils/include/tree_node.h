#pragma once

#include <memory>

struct TreeNode {
    typedef std::shared_ptr<TreeNode> Ptr;
    int val;
    TreeNode::Ptr left;
    TreeNode::Ptr right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode::Ptr left, TreeNode::Ptr right) : val(x), left(left), right(right) {}
};