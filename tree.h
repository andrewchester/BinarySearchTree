class Tree {
	private:
		struct Node{
			Node* parent;
			Node* left;
			Node* right;
			int data;
		};
		int size;
		Node* root;
		void sort(Node*);
		void print_helper(Node*, int current_depth, int target_depth, int inbetween_tabs);
		int get_depth(Node*, int);	 
	public: 
		Tree();
	
		void insert(int);
		Node* search(int);
		void remove(int);
		void print(bool);
};