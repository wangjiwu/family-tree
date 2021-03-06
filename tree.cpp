#include "tree.h"
#include "produceName.h"
#include <iostream>
#include <string>
#include <fstream>
#include<random>


binaryTree::binaryTree() {
	root = NULL;
}
void binaryTree::creat_binary_tree(binaryTreeNode *&root) {
	root = NULL;
	binaryTreeNode *t = NULL, *p = NULL;//t指针为new出来的，p为跟随指针
	t = new binaryTreeNode;
	if (root == NULL)
	{
		cout << "请输入祖先编号：";
		cin >> t->person_num;
		cout << "请输入祖先姓名：";
		cin >> t->person_name;
		cout << "请输入祖先性别：";
		cin >> t->person_sex;
		cout << "输入其配偶姓名：";
		cin >> t->partner_name;
		if (t->person_sex == "nan")
			t->partner_sex = "nv";
		else
			t->partner_sex = "nan";
		root = t;
		root->next_sibling = NULL;
		root->first_child = NULL;
		root->front_parent = NULL;
		root->front_sibling = NULL;
		p = t;
	}
	cout << "是否编辑下一代(Y/N)：";
	char is_continue;
	cin >> is_continue;
	if (is_continue == 'Y' || is_continue == 'y')
	{
		t = new binaryTreeNode;
		cout << "输入" << p->person_name << "子女编号:";
		cin >> t->person_num;
		cout << "输入" << p->person_name << "子女姓名:";
		cin >> t->person_name;
		if (is_rename(t->person_name, root, 0) == 1)
		{
			cout << "有重复，请重新输入" << p->person_name << "子女姓名:";
			cin >> t->person_name;
		}
		cout << "输入" << p->person_name << "子女性别:";
		cin >> t->person_sex;
		cout << "输入" << t->person_name << "配偶姓名:";
		cin >> t->partner_name;
		if (t->partner_sex == "nan")
			t->partner_sex = "nv";
		else
			t->partner_sex = "nan";
		p->first_child = t;
		t->front_parent = p;
		t->front_sibling = NULL;
		p = t;
		p->first_child = NULL;
		p->next_sibling = NULL;
	}
	else {
		cout << "输入错误" << endl;
		return;
	} 
	char choose;
	while (1)
	{
		cout << "※※※※※※※※※※※※※※※※※※※※※※※※※※" << endl;
		cout << "创建" << p->person_name << "的子女请按1" << endl;
		cout << "创建" << p->person_name << "的兄弟请按2" << endl;
		cout << "不再创建请按3" << endl;
		cout << "※※※※※※※※※※※※※※※※※※※※※※※※※※" << endl;
		cin >> choose;
		switch (choose)
		{
		case '1':
		{
			t = new binaryTreeNode;
			cout << "输入" << p->person_name << "子女编号:";
			cin >> t->person_num;
			cout << "输入" << p->person_name << "子女姓名:";
			cin >> t->person_name;
			if (is_rename(t->person_name, root, 0) == 1)
			{
				cout << "有重复，请重新输入" << p->person_name << "子女姓名:";
				cin >> t->person_name;
			}
			cout << "输入" << p->person_name << "子女性别:";
			cin >> t->person_sex;
			cout << "输入" << t->person_name << "配偶姓名:";
			cin >> t->partner_name;
			if (t->partner_sex == "nan")
				t->partner_sex = "nv";
			else
				t->partner_sex = "nan";
			p->first_child = t;
			t->front_parent = p;
			t->front_sibling = NULL;
			p = t;
			p->first_child = NULL;
			p->next_sibling = NULL;
			break;
		}
		case '2':
		{
			t = new binaryTreeNode;
			cout << "输入" << p->person_name << "兄弟编号:";
			cin >> t->person_num;
			cout << "输入" << p->person_name << "兄弟姓名:";
			cin >> t->person_name;
			if (is_rename(t->person_name, root, 0) == 1)
			{
				cout << "有重复，请重新输入" << p->person_name << "子女姓名:";
				cin >> t->person_name;
			}
			cout << "输入" << p->person_name << "兄弟性别:";
			cin >> t->person_sex;
			cout << "输入" << t->person_name << "配偶姓名:";
			cin >> t->partner_name;
			if (t->partner_sex == "nan")
				t->partner_sex = "nv";
			else
				t->partner_sex = "nan";
			p->next_sibling = t;
			t->front_sibling = p;
			//		t->front_parent=NULL;
			p = t;
			p->next_sibling = NULL;
			p->first_child = NULL;
			break;
		}
		case '3':
		{
			cout << "家谱树创建完毕……" << endl;
			return;
		}
		}
	}
}
void binaryTree::show_binary_tree(binaryTreeNode *&root, int i) {
	fstream file("amily.txt", ios::app);
	if (!file)
	{
		cerr << "文件没打开！" << endl;
	}
	if (root)
	{
		int j;
		for (j = i; j>0; j--)
		{
			cout << "   ";
			file << "   ";
		}
		cout << root->person_name << endl;
		file << root->person_name << endl;

		show_binary_tree(root->first_child, i + 1);
		show_binary_tree(root->next_sibling, i);
	}
}
bool binaryTree::is_name(string name, binaryTreeNode *&root) {
	if (root) {
		if (root->person_name == name)
			return true;
		if (is_name(name, root->first_child))
			return true;
		if (is_name(name, root->next_sibling))
			return true;
	}
	return false;
}
bool binaryTree::is_num(string num, binaryTreeNode *&root) {
	if (root) {
		if (root->person_num == num)
			return true;
		if (is_num(num, root->first_child))
			return true;
		if (is_num(num, root->next_sibling))
			return true;
	}
	return false;
}
void binaryTree::search_all_information1(string num, binaryTreeNode *&root) {
	if (root)
	{
		if (root->person_num == num)
		{
			binaryTreeNode *cur;
			cur = root;
			cout << "-------------------------------------" << endl;
			cout << "此人已找到，详细信息如下：" << endl;
			cout << "编号：" << root->person_num << endl;
			cout << "姓名：" << root->person_name << endl;
			cout << "性别：" << root->person_sex << endl;
			cout << "配偶：" << root->partner_name << endl;
			cout << "-------------------------------------" << endl;
			if (cur->front_parent == NULL&&cur->front_sibling == NULL)

				cout << root->person_name << "为祖先，没有双亲！" << endl;
			else
			{
				while (cur->front_sibling)
					cur = cur->front_sibling;
				cout << root->person_name << "的双亲为：" << endl;
				if (cur->front_parent->person_sex == "nan")
				{
					cout << root->person_name << "的父亲：" << cur->front_parent->person_name << endl;
					cout << root->person_name << "的母亲：" << cur->front_parent->partner_name << endl;
				}
				else
				{
					cout << root->person_name << "的父亲：" << cur->front_parent->partner_name << endl;
					cout << root->person_name << "的母亲：" << cur->front_parent->person_name << endl;
				}
			}
			cout << "-------------------------------------" << endl;
			cur = root;
			if (cur->first_child == NULL)
				cout << root->person_name << "没有子女!" << endl;
			else
			{
				cout << root->person_name << "的所有子女：" << endl;
				cur = root->first_child;
				cout << cur->person_name << endl;
				cur = cur->next_sibling;//防止只有一个孩子
				while (cur)
				{
					cout << cur->person_name << endl;
					cur = cur->next_sibling;
				}
			}
			cout << "-------------------------------------" << endl;
			cur = root;
			if (root->front_sibling == NULL&&root->next_sibling == NULL)
			{
				if (root->front_sibling == NULL&&root->next_sibling == NULL&&root->front_parent == NULL)
					cout << root->person_name << "为祖先，没有兄弟！" << endl;
				else
					cout << root->person_name << "为独生子，没有兄弟" << endl;
			}
			else
			{
				cout << root->person_name << "的所有兄弟：" << endl;

				while (cur->front_sibling)
				{
					cur = cur->front_sibling;
					cout << cur->person_name << endl;
				}
				cur = root;
				while (cur->next_sibling)
				{
					cur = cur->next_sibling;
					cout << cur->person_name << endl;
				}
			}
			cout << "-------------------------------------" << endl;
			return;
		}
		search_all_information1(num, root->first_child);
		search_all_information1(num, root->next_sibling);
	}
}
void binaryTree::search_all_information2(string name, binaryTreeNode *&root) {

}
void binaryTree::add_child(string name, binaryTreeNode *&root) {
	if (root)
	{
		if (root->person_name == name)
		{
			binaryTreeNode *cur;
			cur = root;
			cout << "-------------------------------------" << endl;
			cout << "此人已找到，详细信息如下：" << endl;
			cout << "编号：" << root->person_num << endl;
			cout << "姓名：" << root->person_name << endl;
			cout << "性别：" << root->person_sex << endl;
			cout << "配偶：" << root->partner_name << endl;
			cout << "-------------------------------------" << endl;
			if (cur->front_parent == NULL&&cur->front_sibling == NULL)
				cout << root->person_name << "为祖先，没有双亲！" << endl;
			else
			{
				while (cur->front_sibling)
					cur = cur->front_sibling;
				cout << root->person_name << "的双亲为：" << endl;
				if (cur->front_parent->person_sex == "nan")
				{
					cout << root->person_name << "的父亲：" << cur->front_parent->person_name << endl;
					cout << root->person_name << "的母亲：" << cur->front_parent->partner_name << endl;
				}
				else
				{
					cout << root->person_name << "的父亲：" << cur->front_parent->partner_name << endl;
					cout << root->person_name << "的母亲：" << cur->front_parent->person_name << endl;
				}
			}
			cout << "-------------------------------------" << endl;
			cur = root;
			if (cur->first_child == NULL)
				cout << root->person_name << "没有子女!" << endl;
			else
			{
				cout << root->person_name << "的所有子女：" << endl;
				cur = root->first_child;
				cout << cur->person_name << endl;
				cur = cur->next_sibling;//防止只有一个孩子
				while (cur)
				{
					cout << cur->person_name << endl;
					cur = cur->next_sibling;
				}
			}
			cout << "-------------------------------------" << endl;
			cur = root;
			if (root->front_sibling == NULL&&root->next_sibling == NULL)
			{
				if (root->front_sibling == NULL&&root->next_sibling == NULL&&root->front_parent == NULL)
					cout << root->person_name << "为祖先，没有兄弟！" << endl;
				else
					cout << root->person_name << "为独生子，没有兄弟" << endl;
			}
			else
			{
				cout << root->person_name << "的所有兄弟：" << endl;
				while (cur->front_sibling)
				{
					cur = cur->front_sibling;
					cout << cur->person_name << endl;
				}
				cur = root;
				while (cur->next_sibling)
				{
					cur = cur->next_sibling;
					cout << cur->person_name << endl;
				}
			}
			cout << "-------------------------------------" << endl;
			return;
		}
		search_all_information2(name, root->first_child);
		search_all_information2(name, root->next_sibling);
	}
}
int binaryTree::is_rename(string name, binaryTreeNode *&root, int i) {
	if (root)
	{
		if (root->person_name == name)
		{
			i = 1;
		}
		is_rename(name, root->first_child, i);
		is_rename(name, root->next_sibling, i);
	}
	return 1;
}

void traverse(binaryTreeNode* &node, int depth, int restGeneration, int restBrother, string familyName)
{
	//std::poisson_distribution<int> distribution(15);    
	CName name;

	//cout<<node->partner_name<<" ";

	if (rand() % 2)
	{
		//string nameForPerson(name.GetName(), 3, 6);
		node->person_name = familyName + name.GetName();//need to consider about female and male focus on the first name
		/*cout << node->person_name << " ";*/
		node->person_sex = "male";
		node->partner_name = name.GetName();
		if (rand() % 10)
			node->partner_sex = "female";
		else
			node->partner_sex = "male";
	}
	else
	{
	/*	string nameForPerson(name.GetName(), 3, 6);*/
		node->person_name = familyName + name.GetName();//need to consider about female and male focus on the first name
		/*cout << node->person_name << " ";*/
		node->person_sex = "female";
		node->partner_name = name.GetName();
		
		
		if (rand() % 10)
			node->partner_sex = "male";
		else
			node->partner_sex = "female";
	}
	if (restGeneration>0)
	{
		//cout<<"l ";
		int flag = 1;
		string firstName(node->partner_name, 0, 3);
		if (node->person_sex == "female")
		{
			
			flag = 0;

		}
		node->first_child = new binaryTreeNode;
		node->first_child->front_parent = node;
		node->first_child->front_sibling = nullptr;
		std::poisson_distribution<int> distribution2(volumeForBrother);
		if(flag==1)
		traverse(node->first_child, depth + 1, restGeneration - 1, distribution2(generator), familyName);
		else
			traverse(node->first_child, depth + 1, restGeneration - 1, distribution2(generator), firstName);

	}
	if (restBrother>0)
	{
		//cout<<"r ";
		node->next_sibling = new binaryTreeNode;
		node->next_sibling->front_parent = node->front_parent;
		node->next_sibling->front_sibling = node;
		if (volumeForGeneration - depth <= 0) {
			return;
		}
		std::poisson_distribution<int> distribution1(volumeForGeneration - depth);
		// cout<<distribution1(generator)<<" ";
		traverse(node->next_sibling, depth + 1, distribution1(generator), restBrother - 1, familyName);
	}

}

void binaryTree::creat_binary_tree_auto(binaryTreeNode * &root)
{
	root = new binaryTreeNode;
	int restGeneration, restBrother;
	// cout<<volumeForGeneration<<endl;
	std::poisson_distribution<int> distribution1(volumeForGeneration - 1);
	for (; rand() % 100;)distribution1(generator);
	restGeneration = distribution1(generator);
	// cout<<restGeneration<<endl;
	std::poisson_distribution<int> distribution2(volumeForBrother - 1);
	for (; rand() % 100;)distribution2(generator);
	restBrother = distribution2(generator);
	traverse(root, 1, restGeneration, restBrother, familyName);
	cout << endl;
}




