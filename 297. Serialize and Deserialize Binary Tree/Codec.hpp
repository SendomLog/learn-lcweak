//
//  Codec.hpp
//  learn-lcweak
//
//  Created by iMac on 2023/8/25.
//

#ifndef Codec_hpp
#define Codec_hpp

#include <stdio.h>
#include <string>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec {
    vector<string>st0v(string& data) {
        vector<string>res;
        int l = 0, r = 0;
        while (r <= data.size()) {
            char c = data[r++];
            if (c == ',' || c == '\0') {
                res.push_back(data.substr(l, r-l-1));
                l = r;
            }
        }
        return res;
    }
    
    vector<TreeNode *>ston(vector<string>& data) {
        vector<TreeNode *>res;
        for(string str: data) {
            if (str == "null" || str.length() == 0) {
                res.push_back(nullptr);
            }else {
                res.push_back(new TreeNode(stoi(str)));
            }
        }
        return res;
    }

    TreeNode *deserializeHelper(vector<string>& data) {
        if (data.size() == 0) return nullptr;
        int idx = 0;
        vector<TreeNode *>nodes = ston(data);
        while (2*idx+1 < data.size()) {
            TreeNode *root = nodes[idx];
            if (root != nullptr) {
                root->left = nodes[2*idx+1];
                if (2*idx+2 < data.size()) {
                    root->right = nodes[2*idx+2];
                }
            }
            idx++;
        }
        return nodes[0];
    }
    
    string vtos(vector<string>& arr) {
        string res;
        if (arr.size() == 0) return res;
        
        res += arr[0];

        for (int i = 1; i < arr.size(); i++) {
            res += ",";
            res += arr[i];
        }
        
        return res;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> res;
        
        if (!root) return "";
        
        queue<TreeNode *>qu;
        qu.push(root);
        res.push_back(to_string(root->val));
        
        while(!qu.empty()) {
            TreeNode *cur = qu.front(); qu.pop();
            if (cur->left) {
                qu.push(cur->left);
                res.push_back(to_string(cur->left->val));
            }else {
                res.push_back("null");
            }
            
            if (cur->right) {
                qu.push(cur->right);
                res.push_back(to_string(cur->right->val));
            }else {
                res.push_back("null");
            }
        }
        
        for (size_t i = res.size()-1; i >= 0; i--) {
            if (res[i] == "null") {
                res.pop_back();
            }else {
                break;
            }
        }
        
        return vtos(res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string>arr = st0v(data);
        TreeNode *root = deserializeHelper(arr);
        return root;
    }
};

#endif /* Codec_hpp */
