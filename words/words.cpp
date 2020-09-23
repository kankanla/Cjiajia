/********************************************************
 * words -- scan a file and print out a list of words   *
 *              in ASCII order.                         *
 *                                                      *
 * Usage:                                               *
 *      words <file>                                    *
 ********************************************************/
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <cstdlib>

class tree {
    private:
	// The basic node of a tree
	class node {
	    private:
		node    *right;      // tree to the right 
		node    *left;       // tree to the left 
	    public:
		std::string  word;   // word for this tree 

	    friend class tree;	    
	};

	// the top of the tree 
	node *root;

	// Enter a new node into a tree or sub-tree
	void enter_one(node *&node, const std::string& word);

	// Print a single node
	void print_one(node *top);
    public:
	tree() { root = NULL;}

	// Add a new word to our tree
        void enter(std::string& word) {
	    enter_one(root, word);
	}

	// Print the tree
	void print() {
	    print_one(root);
	}
};

static tree words;	// List of words we are looking for
	
/********************************************************
 * scan -- scan the file for words                      *
 *                                                      *
 * Parameters                                           *
 *      name -- name of the file to scan                *
 ********************************************************/
void scan(const char *const name)
{
    std::string new_word;    // word we are working on 
    int  ch;                 // current character 
    std::ifstream in_file;   // input file 

    in_file.open(name, std::ios::in);
    if (in_file.bad()) {
	std::cerr << "Error:Unable to open " << name << '\n';
        exit(8);
    }
    while (true) {
        // scan past the whitespace 
        while (true) {
            ch = in_file.get();

            if (std::isalpha(ch) || (ch == EOF))
                break;
        }

        if (ch == EOF)
            break;

        new_word = ch;
        while (true) 
	{
            ch = in_file.get();
            if (!std::isalpha(ch))
                break;
            new_word += ch;
        }
        words.enter(new_word);
    }
}


int main(int argc, char *argv[])
{
    if (argc != 2) {
	std::cerr <<  "Error:Wrong number of parameters\n";
	std::cerr <<  "      on the command line\n";
	std::cerr <<  "Usage is:\n";
	std::cerr <<  "    words 'file'\n";
        exit(8);
    }
    scan(argv[1]);
    words.print();
    return (0);
}

/********************************************************
 * tree::enter_one -- enter a word into the tree        *
 *                                                      *
 * Parameters                                           *
 *      new_node -- current node we are looking at      *
 *      word -- word to enter                           *
 ********************************************************/
void tree::enter_one(node *&new_node, const std::string& word)
{
    // see if we have reached the end 
    if (new_node == NULL) {
        new_node = new node;

        new_node->left = NULL;
        new_node->right = NULL;
        new_node->word = word;
    }
    if (new_node->word == word)
        return;

    if (new_node->word < word)
        enter_one(new_node->right, word);
    else
        enter_one(new_node->left, word);
}

/********************************************************
 * tree::print_one -- print out the words in a tree    	*
 *                                                      *
 * Parameters                                           *
 *      top -- the root of the tree to print            *
 ********************************************************/
void tree::print_one(node *top)
{
    if (top == NULL)
        return;                 // short tree 

    print_one(top->left);
    std::cout << top->word << '\n';
    print_one(top->right);
}
