#include <iostream>

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
};

class Tree {
    TreeNode* root;
    size_t length;

    void clear(TreeNode* node) noexcept {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;   
        }
    }

    void add_recursive_impl(TreeNode** node, int value) {
        if (*node == nullptr) {
            *node = new TreeNode;
            (*node)->value = value;
            (*node)->left = (*node)->right = nullptr;
            return;
        }

        if (value >= (*node)->value) {
            add_recursive_impl(&((*node)->right), value);
        }
        else {
            add_recursive_impl(&((*node)->left), value);
        }
    }

    void pre_order(TreeNode* node) {
        if (node != nullptr) {
            std::cout << node->value << " ";
            pre_order(node->left);
            pre_order(node->right);
        }
    }

    void in_order(TreeNode* node) {
        if (node != nullptr) {
            in_order(node->left);
            std::cout << node->value << " ";
            in_order(node->right);
        }
    }

    void post_order(TreeNode* node) {
        if (node != nullptr) {
            post_order(node->left);
            post_order(node->right);
            std::cout << node->value << " ";
        }
    }
public:
    Tree() : root{ nullptr }, length{ 0 } {}

    ~Tree() noexcept {
        clear(root);
    }

    void add(int value) {
        TreeNode* node = new TreeNode;
        node->value = value;
        node->left = node->right = nullptr;

        if (root == nullptr) {
            root = node;
        }
        else {
            TreeNode* cursor = root;

            while (cursor != nullptr) {
                if (value >= cursor->value) {
                    if (cursor->right == nullptr) {
                        cursor->right = node;
                        return;
                    }
                    else {
                        cursor = cursor->right;
                    }
                }
                else {
                    if (cursor->left == nullptr) {
                        cursor->left = node;
                        return;
                    }
                    else {
                        cursor = cursor->left;
                    }
                }
            }
        }
    }

    void add_recursive(int value) {
        add_recursive_impl(&root, value);
    }

    void pre_order() {
        std::cout << "pre_order:\n    ";
        pre_order(root);
        std::cout << "\n";
    }

    void in_order() {
        std::cout << "in_order:\n    ";
        in_order(root);
        std::cout << "\n";
    }

    void post_order() {
        std::cout << "post_order:\n    ";
        post_order(root);
        std::cout << "\n";
    }
};

int main() {
    Tree tree;

    tree.add_recursive(28);
    tree.add_recursive(16);
    tree.add_recursive(30);
    tree.add_recursive(13);
    tree.add_recursive(22);
    tree.add_recursive(29);

    std::cout << "tree is:\n";
    std::cout << "        28\n";
    std::cout << "      /    \\\n";
    std::cout << "     16     30\n";
    std::cout << "    /  \\   /\n";
    std::cout << "   13  22 29\n\n";

    tree.pre_order();
    tree.in_order();
    tree.post_order();
    return 0;
}
