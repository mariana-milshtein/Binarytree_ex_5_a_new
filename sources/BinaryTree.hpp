#pragma once
#include <queue>
#include <iostream>

namespace ariel {
    
};

template<typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        Node *left, *right, *parent;
        
        Node(const T& data, Node* left, Node* right, Node* parent) : data(data) , left(left) , right(right) , parent(parent) {
        }
    };
    
public:
    BinaryTree() : root(nullptr) {
    }
    
    BinaryTree& add_root(const T& data) {
        if(root == nullptr) {
            root = new Node(data, nullptr, nullptr, nullptr);
        }
        else {
            root->data = data;
        }
        return *this;    
    }
    
    BinaryTree& add_left(const T& parent, const T& newChild) {
        Node* p = find(parent);
        if(p == nullptr) {
            throw std::logic_error("First input is not in the tree");
        }
        if(p->left == nullptr) {
            p->left = new Node(newChild, nullptr, nullptr, p);
        }
        else {
            p->left->data = newChild;
        }
        return *this;  
    }
    
    BinaryTree& add_right(const T& parent, const T& newChild) {
        Node* p = find(parent);
        if(p == nullptr) {
            throw std::logic_error("First input is not in the tree");
        }
        if(p->right == nullptr) {
            p->right = new Node(newChild, nullptr, nullptr, p);
        }
        else {
            p->right->data = newChild;
        }
        return *this; 
    }
    
    class iterator {
    protected:
        Node* current;
    public:
        iterator(Node* ptr = nullptr) : current(ptr) {
        }

        T& operator*() const {
			return current->data;
		}

		T* operator->() const {
			return &(current->data);
		}

		virtual iterator& operator++() {
		    inc();
			return *this;
		}

		virtual const iterator operator++(int) {
			iterator tmp= *this;
			inc();
			return tmp;
		}
        
        virtual void inc() {
            
        }
        
		bool operator==(const iterator& rhs) const {
			return current == rhs.current;
		}

		bool operator!=(const iterator& rhs) const {
			return current != rhs.current;
		}
        
    };
    
	class preorder_iterator : public BinaryTree<T>::iterator {
	public:    
	    preorder_iterator(Node* ptr = nullptr) : iterator(ptr) {
	        init();
        }
	    
	    void init() {
        }
        
        void inc() {
            if(iterator::current->left != nullptr) {
                iterator::current = iterator::current->left;
            }
            else if(iterator::current->right != nullptr) {
                iterator::current = iterator::current->right;
            }
            else {
                while(iterator::current->parent != nullptr && (iterator::current->parent->left != iterator::current || iterator::current->parent->right == nullptr)) {
                    iterator::current = iterator::current->parent;
                }
                if(iterator::current->parent == nullptr) {
                    iterator::current = nullptr;
                }
                else {
                    iterator::current = iterator::current->parent->right;
                }
            }
        }
	};
	
	class inorder_iterator : public iterator {
	public:
	    inorder_iterator(Node* ptr = nullptr) : iterator(ptr) {
	        init();
        }
        
        void init() {
            if(iterator::current != nullptr) {
                while(iterator::current->left != nullptr) {
                    iterator::current = iterator::current->left;
                }
            }
        }
        
        virtual void inc() {
            if(iterator::current->right != nullptr) {
                iterator::current = iterator::current->right;
                while(iterator::current->left !=nullptr) {
                    iterator::current = iterator::current->left;
                }
            }
            else {
                while(iterator::current->parent != nullptr && iterator::current->parent->left != iterator::current) {
                    iterator::current = iterator::current->parent;
                }
                iterator::current = iterator::current->parent;
            }
        }
	};
	
	class postorder_iterator : public iterator {
	public:
	    postorder_iterator(Node* ptr = nullptr) : iterator(ptr) {
	        init();
        }
		
        void init() {
            if(iterator::current != nullptr) {
                while(iterator::current->left != nullptr) {
                    iterator::current = iterator::current->left;
                }
            }
        }
        
        virtual void inc() {
            if(iterator::current->parent == nullptr) {
                iterator::current = nullptr; 
            }
            else if(iterator::current->parent->right == iterator::current) {
                iterator::current = iterator::current->parent;
            }
            else {
                iterator::current = iterator::current->parent->right;
                while(iterator::current->left != nullptr) {
                    iterator::current = iterator::current->left;
                }
            }
        }
        
	};
	
	inorder_iterator begin() {
		return inorder_iterator{root};
	}
	inorder_iterator end() {
		return inorder_iterator{nullptr};
	}
	preorder_iterator begin_preorder() {
	    return preorder_iterator{root};
	}
	preorder_iterator end_preorder() {
	    return preorder_iterator{nullptr};
	}
	inorder_iterator begin_inorder() {
        return inorder_iterator{root};	    
	}
	inorder_iterator end_inorder() {
	    return inorder_iterator{nullptr};
	}
	postorder_iterator begin_postorder() {
	    return postorder_iterator{root};
	}
	postorder_iterator end_postorder() {
	    return postorder_iterator{nullptr};
	}
	
	friend std::ostream& operator<<(std::ostream& os, const BinaryTree<T>& b) {
	    std::queue<Node*> q;
	    if(b.root != nullptr) q.push(b.root);
	    while(!q.empty()) {
	        Node* n = q.front();
	        q.pop();
	        if(n != nullptr) {
	            os << n->data;
	            q.push(n->left);
	            q.push(n->right);
	        }
	    }
	    return os;
	}
	
private:
    
    Node* find(Node* n, const T& data) {
        if(n == nullptr) return nullptr;
        if(n->data == data) return n;
        Node* left = find(n->left, data);
        if(left != nullptr) return left;
        return find(n->right, data);
    }
    
    Node* find(const T& data) {
        return find(root, data);
    }
    
    Node* root;
};