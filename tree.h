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
		void print_helper(Node*, int current_depth, int target_depth);
		int get_depth(Node*, int);	 
		Node* find(Node*, int);
		void siftup(Node*);
	public: 
		Tree();
	
		void insert(int);
		void remove(int);
		void print(bool);
};