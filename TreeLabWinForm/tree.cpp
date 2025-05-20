#include "tree.h"

using namespace System::Windows::Forms;

Tree::Tree(double dt)
{
	data = dt;
	left = NULL;
	right = NULL;
	parent = NULL;
}

Tree::~Tree()
{
	delete this->left;
	delete this->right;
}

void Tree::insertNode(double dt)
{
	Tree* tree = this;
	while (tree != NULL)
	{
		if (dt >= tree->data)
		{
			if (tree->right != NULL)
			{
				tree = tree->right;
			}
			else
			{
				Tree* t = new Tree(dt);
				t->parent = tree;
				tree->right = t;
				break;
			}
		}
		else if (dt < tree->data)
		{
			if (tree->left != NULL)
			{
				tree = tree->left;
			}
			else
			{
				Tree* t = new Tree(dt);
				t->parent = tree;
				tree->left = t;
				break;
			}
		}
	}
}

void Tree::printTree(int level, RichTextBox^ box)
{
	if (right != NULL) {
		right->printTree(level + 1, box);
	}
	for (int i = 0; i < level; i++) {
		box->AppendText("      ");
	}
	box->AppendText(System::Convert::ToString(data) + "\n");
	if (left != NULL) {
		left->printTree(level + 1, box);
	}
}

Tree* Tree::findElement(double dt)
{
	if ((this == NULL) || (dt == this->data)) return this;
	if (dt < this->data) return this->left->findElement(dt);
	else return this->right->findElement(dt);
}

Tree* Tree::findMax()
{
	if (this->right == NULL) return this;
	return this->right->findMax();
}

Tree* Tree::findMin()
{
	if (this->left == NULL) return this;
	return this->left->findMin();
}

Tree* Tree::next()
{
	Tree* tree = this;
	if (tree->right != NULL) return tree->right->findMin();
	Tree* t = tree->parent;
	while ((t != NULL) && (tree == t->right))
	{
		tree = t;
		t = t->parent;
	}
	return t;
}

Tree* Tree::prev()
{
	Tree* tree = this;
	if (tree->left != NULL) return tree->left->findMax();
	Tree* t = tree->parent;
	while ((t != NULL) && (tree == t->left)) {
		tree = t;
		t = t->parent;
	}
	return t;
}

void Tree::deleteNode(double dt, RichTextBox^ box)
{
	Tree* e = this->findElement(dt);
	if (e == NULL)
	{
		box->AppendText("Ёлемент " + dt + " не найден.\n");
		return;
	}
	Tree* p = e->parent;
	if ((e->left == NULL) && (e->right == NULL)) // нет потомков
	{
		if (p->left == e) p->left = NULL;
		if (p->right == e) p->right = NULL;
	}
	else if ((e->left == NULL) || (e->right == NULL)) // один потомок
	{
		if (e->left == NULL)
		{
			if (p->left == e) p->left = e->right;
			else p->right = e->right;
			e->right->parent = p;
		}
		else
		{
			if (p->left == e) p->left = e->left;
			else p->right = e->left;
			e->left->parent = p;
		}
	}
	else // два потомка
	{
		Tree* s = e->next();
		e->data = s->data;
		if (s->parent->left == s)
		{
			s->parent->left = s->right;
			if (s->right != NULL) s->right->parent = s->parent;
		}
		else
		{
			s->parent->right = s->right;
			if (s->right != NULL)
				s->right->parent = s->parent;
		}

	}
	box->AppendText("Ёлемент " + dt + " удален.\n");
}

void Tree::preOrder(Tree* node, RichTextBox^ box)
{
	if (node != NULL)
	{
		box->AppendText(node->data.ToString() + " ");
		preOrder(node->left, box);
		preOrder(node->right, box);
	}
}

void Tree::inOrder(Tree* node, RichTextBox^ box)
{
	if (node != NULL)
	{
		inOrder(node->left, box);
		box->AppendText(node->data.ToString() + " ");
		inOrder(node->right, box);
	}
}

void Tree::inOrderVector(Tree* node, RichTextBox^ box, vector<double>& elem)
{
	if (node != NULL)
	{
		inOrderVector(node->left, box, elem);
		box->AppendText(node->data.ToString() + " ");
		elem.push_back(node->data);
		inOrderVector(node->right, box, elem);
	}
}

void Tree::postOrder(Tree* node, RichTextBox^ box)
{
	if (node != NULL)
	{
		postOrder(node->left, box);
		postOrder(node->right, box);
		box->AppendText(node->data.ToString() + " ");
	}
}

Tree* Tree::buildBalancedTree(const std::vector<double>& elem, int start, int end)
{
	if (start > end) return nullptr;

	int mid = (start + end) / 2;
	Tree* root = new Tree(elem[mid]);
	root->left = buildBalancedTree(elem, start, mid - 1);
	if (root->left) root->left->parent = root;
	root->right = buildBalancedTree(elem, mid + 1, end);
	if (root->right) root->right->parent = root;
	return root;
}

Tree* Tree::balancedTree(RichTextBox^ box)
{
	vector<double> elem;
	box->AppendText("[Log] inOrder: ");
	inOrderVector(this, box, elem);
	return buildBalancedTree(elem, 0, elem.size() - 1);
}

struct pos 
{
	int col;
	int str;
};

int Tree::getHeight()
{
	int h1 = 0, h2 = 0, hadd = 0;
	if (this == NULL)return 0;
	if (this->left != NULL) h1 = this->left->getHeight();
	if (this->right != NULL) h2 = this->right->getHeight();
	if (h1 >= h2) return h1 + 1;
	else return h2 + 1;
}

int Tree::getPos(int index, int width, int curLevel, int maxLevel)
{
	int x1 = 0;
	int x2 = pow(2, curLevel) - 1;
	int y1 = width / pow(2, curLevel + 1);
	int y2 = width - pow(2, maxLevel - curLevel);
	if (x1 == x2) return y1;
		double k = (y2 - y1) / (x2 - x1);
	double m = -x1 * k + y1;
	int y = (int)(k * index + m);
	return y;
}

Tree* Tree::copyTree()
{
	Tree* tree = new Tree(this->data);
	if (this->parent != NULL)
		tree->parent = this->parent;
	if (this->left != NULL)
		tree->left = this->left->copyTree();
	if (this->right != NULL)
		tree->right = this->right->copyTree();
	return tree;
}

int Tree::getLevel(Tree* node)
{
	int level = 0;
	while (node->parent != nullptr)
	{
		level++;
		node = node->parent;
	}
	return level;
}

void Tree::insertLeft(double dt)
{
	Tree* node = new Tree(dt);
	if (this->left != NULL)
		this->left->parent = node;
	node->left = this->left;
	this->left = node;
	node->parent = this;
}

void Tree::insertRight(double dt)
{
	Tree* node = new Tree(dt);
	if (this->right != NULL)
		this->right->parent = node;
	node->right = this->right;
	this->right = node;
	node->parent = this;
}

Tree* Tree::replace_help(Tree* node, int h)
{
	int curLevel = getLevel(node);
	if ((node->getLeft() == NULL) && (curLevel != h - 1))
		node->insertLeft(NULL);
	if ((node->getRight() == NULL) && (curLevel != h - 1))
		node->insertRight(NULL);
	if (node->getLeft() != NULL) node -> addLeftTree(replace_help(node->getLeft(), h));
	if (node->getRight() != NULL) node -> addRightTree(replace_help(node->getRight(), h));
	return node;
}

Tree* Tree::replaceNULLforEmpty()
{
	Tree* node = this->copyTree();
	int h = node->getHeight();
	node = replace_help(node, h);
	return node;
}

int Tree::getAmountOfNodes()
{
	if (this == NULL) return 0;
	if ((this->left == NULL) && (this->right == NULL)) return 1;
	int l = 0;
	int r = 0;
	if (this->left != NULL) l = this->left->getAmountOfNodes();
	if (this->right != NULL) r = this->right -> getAmountOfNodes();
	return (l + r + 1);
}

void Tree::printVTree(int k, System::Windows::Forms::RichTextBox^ box)
{
	int height = this->getHeight();
	int maxLeafs = pow(2, height - 1);
	int width = 2 * maxLeafs - 1;
	int curLevel = 0;
	int index = 0;
	int factSpaces = getPos(index, width, curLevel, height - 1);
	pos node;
	vector<Tree*> V;
	vector<pos> Vi;
	Tree* t = this->copyTree();
	t = t->replaceNULLforEmpty();
	Tree* p = t;
	V.push_back(p);
	node.col = factSpaces;
	node.str = curLevel;
	Vi.push_back(node);
	for (int i = 0; i < t->getAmountOfNodes(); i++)
	{
		if (pow(2, curLevel) <= index + 1)
		{
			index = 0;
			curLevel++;
		}
		if (V.at(i)->left != NULL)
		{
			V.push_back(V.at(i)->left);
			factSpaces = getPos(index, width, curLevel, height - 1);
			node.col = factSpaces;
			node.str = curLevel;
			Vi.push_back(node);
			index++;
		}
		if (V.at(i)->right != NULL)
		{
			V.push_back(V.at(i)->right);
			factSpaces = getPos(index, width, curLevel, height - 1);
			node.col = factSpaces;
			node.str = curLevel;
			Vi.push_back(node);
			index++;
		}
	}
	for (int i = V.size() - 1; i >= 0; i--) {
		if (i != 0) {
			if (Vi.at(i - 1).str == Vi.at(i).str)
				Vi.at(i).col = Vi.at(i).col - Vi.at(i - 1).col - 1;
		}
	}
	int flag = 0;
	for (int i = 0; i < V.size(); i++) {
		node = Vi.at(i);
		curLevel = node.str;
		if (flag < curLevel) {
			flag = curLevel;
			box->AppendText("\n");
		}
		factSpaces = node.col;
		int realSpaces = k * factSpaces;
		for (int j = 0; j < realSpaces; j++) box->AppendText(" ");
		if (V.at(i)->data != NULL) box->AppendText(V.at(i)->data.ToString());
		else for (int j = 0; j < k; j++) box->AppendText(" ");
	}
	box->AppendText("\n");
}

void Tree::drawTree(sf::RenderWindow& window, Tree* node, float x, float y, float offsetX, float levelHeight)
{
	if (node == nullptr)
		return;

	const float radius = 20;

	sf::CircleShape circle(radius);
	circle.setFillColor(sf::Color::White);
	circle.setOutlineColor(sf::Color::Black);
	circle.setOutlineThickness(2);
	circle.setPosition(x - radius, y - radius);
	window.draw(circle);

	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) return;

	float rounded = static_cast<int>(node->data * 100 + 0.5f) / 100.0f;
	std::string str = std::to_string(rounded);
	str.erase(str.find_last_not_of('0') + 1, std::string::npos);
	if (!str.empty() && str.back() == '.') str.pop_back();

	sf::Text text(str, font, 14);
	text.setFillColor(sf::Color::Black);
	text.setPosition(x - 10, y - 10);
	window.draw(text);

	auto drawLineAvoidingCircle = [&](Tree* child, float childX, float childY) {
		float dx = childX - x;
		float dy = childY - y;
		float dist = std::sqrt(dx * dx + dy * dy);
		if (dist == 0) return;

		float offsetX = radius * dx / dist;
		float offsetY = radius * dy / dist;

		sf::Vertex line[] =
		{
			sf::Vertex(sf::Vector2f(x + offsetX, y + offsetY), sf::Color::Black),
			sf::Vertex(sf::Vector2f(childX - offsetX, childY - offsetY), sf::Color::Black)
		};
		window.draw(line, 2, sf::Lines);
		};

	if (node->getLeft()) {
		float childX = x - offsetX;
		float childY = y + levelHeight;
		drawLineAvoidingCircle(node->getLeft(), childX, childY);
		drawTree(window, node->getLeft(), childX, childY, offsetX / 2, levelHeight);
	}

	if (node->getRight()) {
		float childX = x + offsetX;
		float childY = y + levelHeight;
		drawLineAvoidingCircle(node->getRight(), childX, childY);
		drawTree(window, node->getRight(), childX, childY, offsetX / 2, levelHeight);
	}
}