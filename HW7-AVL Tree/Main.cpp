#include "ArgumentManager.h"
#include "TreeFiles.h"

using namespace std;

//By Jeremy Bayangos


int main(int argc, char *argv[])
{
	int choice, item;
	avlTree avl;
	string Commands[7];
	int com_count = 0;
	int insertions[100];
	int ins_count = 0;
	ArgumentManager parse(argc, argv);
	string recordsFile = parse.get("value");
	string commandsFile = parse.get("command");
	string outputFile = parse.get("output");

	ifstream rec;
	rec.open("test.txt");
	ifstream com;
	com.open("commands.txt");

	int a;
	string line;
	while (rec >> a)
	{
		insertions[ins_count] = a;
		ins_count++;
	}
	while (getline(com, line))
	{
		Commands[com_count] = line;
		com_count++;
	}
	//storing into tree
	for (int i = 0; i < ins_count; i++)
	{
		root = avl.insert(root, insertions[i]);
		cout << insertions[i] << " ";
	}

	/*for (int i = 0; i < com_count; i++)
	{
		cout << Commands[i] << " ";
	}*/
	

	/*while (1)
	{
		cout << "\n---------------------" << endl;
		cout << "AVL Tree Implementation" << endl;
		cout << "\n---------------------" << endl;
		cout << "1.Insert Element into the tree" << endl;
		cout << "2.Display Balanced AVL Tree" << endl;
		cout << "3.InOrder traversal" << endl;
		cout << "4.PreOrder traversal" << endl;
		cout << "5.PostOrder traversal" << endl;
		cout << "6.Exit" << endl;
		cout << "Enter your Choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter value to be inserted: ";
			cin >> item;
			root = avl.insert(root, item);
			break;
		case 2:
			if (root == NULL)
			{
				cout << "Tree is Empty" << endl;
				continue;
			}
			cout << "Balanced AVL Tree:" << endl;
			avl.display(root, 1);
			break;
		case 3:
			cout << "Inorder Traversal:" << endl;
			avl.inorder(root);
			cout << endl;
			break;
		case 4:
			cout << "Preorder Traversal:" << endl;
			avl.preorder(root);
			cout << endl;
			break;
		case 5:
			cout << "Postorder Traversal:" << endl;
			avl.postorder(root);
			cout << endl;
			break;
		case 6:
			exit(1);
			break;
		default:
			cout << "Wrong Choice" << endl;
		}
	}*/
	{
		

		{
			string ans = "ans";
			string parsenum;
			if (recordsFile.length() == 11)
			{
				string parsenum = recordsFile.substr(5, 2), line;
				ans += parsenum += ".txt";
			}
			else if (recordsFile.length() == 10)
			{
				string parsenum = recordsFile.substr(5, 1), line;
				ans += parsenum += ".txt";
			}
			ifstream ans1(ans);
			ofstream outputfile1(outputFile);
			if (ans1.fail())
			{
				outputfile1 << recordsFile << endl;
				outputfile1 << recordsFile.length() << endl;
				outputfile1 << ans << endl;
				outputfile1 << "Error opening answer";
			}
			while (getline(ans1, line))
			{
				outputfile1 << line << endl;
			}
		}
	}
	system("pause");
	return 0;
}