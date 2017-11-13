#include "tree.h"
#include <iostream>
<<<<<<< HEAD
using namespace std;
=======
#include <string>
#include <fstream>

>>>>>>> d6fe20fa5e133e5b7fd42f8eccb105bc21b65bf3
binaryTree::binaryTree() {
	root=NULL;
}
void binaryTree::creat_binary_tree(binaryTreeNode *&root) {
<<<<<<< HEAD
	cout << "creat_binary_tree" << endl;
}
void binaryTree::show_binary_tree(binaryTreeNode *&root, int i) {
	cout << "show_binary_tree" << endl;
}
void binaryTree::search_all_information1(string num, binaryTreeNode *&root) {
	cout << "search_all_information1" << endl;
=======
	root=NULL;
	binaryTreeNode *t = NULL,*p = NULL;//t指针为new出来的，p为跟随指针
	t=new binaryTreeNode;
	if(root==NULL)
	{
		cout<<"请输入祖先编号：";
		cin>>t->person_num;
		cout<<"请输入祖先姓名：";
		cin>>t->person_name;
		cout<<"请输入祖先性别：";
		cin>>t->person_sex;
		cout<<"输入其配偶姓名：";
		cin>>t->partner_name;
		if(t->person_sex=="nan")
		    t->partner_sex="nv";
		else
			t->partner_sex="nan";
		root=t;
		root->next_sibling=NULL;
		root->first_child=NULL;
		root->front_parent=NULL;
		root->front_sibling=NULL;
		p=t;
	}
	cout<<"是否编辑下一代(Y/N)：";
	char is_continue;
	cin>>is_continue;
	if(is_continue=='Y'||is_continue=='y')
	{
		t=new binaryTreeNode;
		cout<<"输入"<<p->person_name<<"子女编号:";
		cin>>t->person_num;
		cout<<"输入"<<p->person_name<<"子女姓名:";
		cin>>t->person_name;
		if(is_rename(t->person_name,root,0)==1)
		{
			cout<<"有重复，请重新输入"<<p->person_name<<"子女姓名:";
			cin>>t->person_name;
		}
		cout<<"输入"<<p->person_name<<"子女性别:";
		cin>>t->person_sex;
		cout<<"输入"<<t->person_name<<"配偶姓名:";
		cin>>t->partner_name;
		if(t->partner_sex=="nan")
			t->partner_sex="nv";
		else
			t->partner_sex="nan";
		p->first_child=t;
		t->front_parent=p;
		t->front_sibling=NULL;
		p=t;
		p->first_child=NULL;
		p->next_sibling=NULL;
	}
	else return;
	char choose;
	while(1)
	{
		cout<<"※※※※※※※※※※※※※※※※※※※※※※※※※※"<<endl;
		cout<<"创建"<<p->person_name<<"的子女请按1"<<endl;
		cout<<"创建"<<p->person_name<<"的兄弟请按2"<<endl;
		cout<<"不再创建请按3"<<endl;
		cout<<"※※※※※※※※※※※※※※※※※※※※※※※※※※"<<endl;
		cin>>choose;
		switch(choose)
		{
		case '1':
			{
				t=new binaryTreeNode;
				cout<<"输入"<<p->person_name<<"子女编号:";
				cin>>t->person_num;
				cout<<"输入"<<p->person_name<<"子女姓名:";
				cin>>t->person_name;
				if(is_rename(t->person_name,root,0)==1)
				{
					cout<<"有重复，请重新输入"<<p->person_name<<"子女姓名:";
					cin>>t->person_name;
				}
				cout<<"输入"<<p->person_name<<"子女性别:";
				cin>>t->person_sex;
				cout<<"输入"<<t->person_name<<"配偶姓名:";
				cin>>t->partner_name;
				if(t->partner_sex=="nan")
					t->partner_sex="nv";
				else
					t->partner_sex="nan";
				p->first_child=t;
				t->front_parent=p;
				t->front_sibling=NULL;
				p=t;
				p->first_child=NULL;
				p->next_sibling=NULL;
				break;
			}
		case '2':
			{
				t=new binaryTreeNode;
				cout<<"输入"<<p->person_name<<"兄弟编号:";
				cin>>t->person_num;
				cout<<"输入"<<p->person_name<<"兄弟姓名:";
				cin>>t->person_name;
				if(is_rename(t->person_name,root,0)==1)
				{
					cout<<"有重复，请重新输入"<<p->person_name<<"子女姓名:";
				    cin>>t->person_name;
				}
				cout<<"输入"<<p->person_name<<"兄弟性别:";
				cin>>t->person_sex;
				cout<<"输入"<<t->person_name<<"配偶姓名:";
				cin>>t->partner_name;
				if(t->partner_sex=="nan")
					t->partner_sex="nv";
				else
					t->partner_sex="nan";
				p->next_sibling=t;
				t->front_sibling=p;
		//		t->front_parent=NULL;
				p=t;
				p->next_sibling=NULL;
				p->first_child=NULL;
				break;
			}
		case '3':
			{
				cout<<"家谱树创建完毕……"<<endl;
				return;
			}
		}
	}
}
void binaryTree::show_binary_tree(binaryTreeNode *&root, int i) {
	fstream file("amily.txt",ios::app);
	if(!file)
	{
		cerr<<"文件没打开！"<<endl;
	}
	if(root)
	{
		int j;
		for( j=i; j>0; j--)
		{
			cout<<"   ";
			file<<"   ";
		}
        cout<<root->person_name<<endl;
		file<<root->person_name<<endl;
		show_binary_tree( root->first_child, i+1 );
		show_binary_tree( root->next_sibling, i );
	}
}
void binaryTree::search_all_information1(string num, binaryTreeNode *&root) {
	if(root)
	{
		if(root->person_num==num)
		{
			binaryTreeNode *cur;
			cur=root;
			cout<<"-------------------------------------"<<endl;
		    cout<<"此人已找到，详细信息如下："<<endl;
			cout<<"编号："<<root->person_num<<endl;
			cout<<"姓名："<<root->person_name<<endl;
			cout<<"性别："<<root->person_sex<<endl;
			cout<<"配偶："<<root->partner_name<<endl;
			cout<<"-------------------------------------"<<endl;
			if(cur->front_parent==NULL&&cur->front_sibling==NULL)
				cout<<root->person_name<<"为祖先，没有双亲！"<<endl;
			else
			{
				while(cur->front_sibling)
					cur=cur->front_sibling;
				cout<<root->person_name<<"的双亲为："<<endl;
			    if(cur->front_parent->person_sex=="nan")
			    {  
				    cout<<root->person_name<<"的父亲："<<cur->front_parent->person_name<<endl;
				    cout<<root->person_name<<"的母亲："<<cur->front_parent->partner_name<<endl;
			    }
			    else
			    {
				    cout<<root->person_name<<"的父亲："<<cur->front_parent->partner_name<<endl;
				    cout<<root->person_name<<"的母亲："<<cur->front_parent->person_name<<endl;
			    }
		     }
			cout<<"-------------------------------------"<<endl;
			cur=root;
			if(cur->first_child==NULL)
				cout<<root->person_name<<"没有子女!"<<endl;
			else
			{
				cout<<root->person_name<<"的所有子女："<<endl;
				cur=root->first_child;
				cout<<cur->person_name<<endl;
				cur=cur->next_sibling;//防止只有一个孩子
				while(cur)
				{
					cout<<cur->person_name<<endl;
					cur=cur->next_sibling;
				}
			}
			cout<<"-------------------------------------"<<endl;
			cur=root;
			if(root->front_sibling==NULL&&root->next_sibling==NULL)
			{
				if(root->front_sibling==NULL&&root->next_sibling==NULL&&root->front_parent==NULL)
					cout<<root->person_name<<"为祖先，没有兄弟！"<<endl;
				else
				    cout<<root->person_name<<"为独生子，没有兄弟"<<endl;
			}
			else
			{
				cout<<root->person_name<<"的所有兄弟："<<endl;
				
				while(cur->front_sibling)
				{
					cur=cur->front_sibling;
					cout<<cur->person_name<<endl;
				}
				cur=root;
				while(cur->next_sibling)
				{
					cur=cur->next_sibling;
					cout<<cur->person_name<<endl;
				}
			}
			cout<<"-------------------------------------"<<endl;
			return;
		}
		search_all_information1(num,root->first_child);
		search_all_information1(num,root->next_sibling);
	}
>>>>>>> d6fe20fa5e133e5b7fd42f8eccb105bc21b65bf3
}
void binaryTree::search_all_information2(string name, binaryTreeNode *&root) {
	cout << "search_all_information2" << endl;
}
void binaryTree::add_child(string num, binaryTreeNode *&root) {
<<<<<<< HEAD
	cout << "add_child" << endl;
=======
	if(root)
	{
		if(root->person_name==name)
		{
			binaryTreeNode *cur;
			cur=root;
			cout<<"-------------------------------------"<<endl;
			cout<<"此人已找到，详细信息如下："<<endl;
			cout<<"编号："<<root->person_num<<endl;
			cout<<"姓名："<<root->person_name<<endl;
			cout<<"性别："<<root->person_sex<<endl;
			cout<<"配偶："<<root->partner_name<<endl;
			cout<<"-------------------------------------"<<endl;
			if(cur->front_parent==NULL&&cur->front_sibling==NULL)
				cout<<root->person_name<<"为祖先，没有双亲！"<<endl;
			else
			{
				while(cur->front_sibling)
					cur=cur->front_sibling;
				cout<<root->person_name<<"的双亲为："<<endl;
				if(cur->front_parent->person_sex=="nan")
				{  
					cout<<root->person_name<<"的父亲："<<cur->front_parent->person_name<<endl;
					cout<<root->person_name<<"的母亲："<<cur->front_parent->partner_name<<endl;
				}
				else
				{
					cout<<root->person_name<<"的父亲："<<cur->front_parent->partner_name<<endl;
					cout<<root->person_name<<"的母亲："<<cur->front_parent->person_name<<endl;
				}
			}
			cout<<"-------------------------------------"<<endl;
			cur=root;
			if(cur->first_child==NULL)
				cout<<root->person_name<<"没有子女!"<<endl;
			else
			{
				cout<<root->person_name<<"的所有子女："<<endl;
				cur=root->first_child;
				cout<<cur->person_name<<endl;
				cur=cur->next_sibling;//防止只有一个孩子
				while(cur)
				{
					cout<<cur->person_name<<endl;
					cur=cur->next_sibling;
				}
			}
			cout<<"-------------------------------------"<<endl;
			cur=root;
			if(root->front_sibling==NULL&&root->next_sibling==NULL)
			{
				if(root->front_sibling==NULL&&root->next_sibling==NULL&&root->front_parent==NULL)
					cout<<root->person_name<<"为祖先，没有兄弟！"<<endl;
				else
					cout<<root->person_name<<"为独生子，没有兄弟"<<endl;
			}
			else
			{
				cout<<root->person_name<<"的所有兄弟："<<endl;
				while(cur->front_sibling)
				{
					cur=cur->front_sibling;
					cout<<cur->person_name<<endl;
				}
				cur=root;
				while(cur->next_sibling)
				{
					cur=cur->next_sibling;
					cout<<cur->person_name<<endl;
				}
			}
			cout<<"-------------------------------------"<<endl;
			return;
		}
		search_all_information2(name,root->first_child);
		search_all_information2(name,root->next_sibling);
	}
>>>>>>> d6fe20fa5e133e5b7fd42f8eccb105bc21b65bf3
}
int binaryTree::is_rename(string name, binaryTreeNode *&root, int i) {
	if(root)
	{
		if(root->person_name==name)
		{
			i=1;
		}
		is_rename(name,root->first_child,i);
		is_rename(name,root->next_sibling,i);
	}
	return 1;
}
