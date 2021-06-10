#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int key;
	struct TreeNode* parent, *left, *right;
}TreeNode;

// 루트의 주소가 함수마다 변경되어질 때
// 이 함수 안 포인터로 공유되어지니까 편하다고 함
typedef struct
{
	TreeNode* root;
}TreeType;

void initTree(TreeType* T)
{
	T->root = (TreeNode*)malloc(sizeof(TreeNode));
	T->root->parent = T->root->left = T->root->right = NULL;	// root의 parent는 계속 null
}

int isExternal(TreeNode* w)
{
	return (w->left == NULL && w->right == NULL);
}

void expandExternal(TreeNode* w)
{
	TreeNode* l = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* r = (TreeNode*)malloc(sizeof(TreeNode));

	l->left = NULL;
	l->right = NULL;
	l->parent = w;

	r->left = NULL;
	r->right = NULL;
	r->parent = w;

	w->left = l;
	w->right = r;
}

TreeNode* treeSearch(TreeNode* v, int k)
{
	if (isExternal(v))
		return v;
	if (k == v->key)
		return v;
	else if (k < v->key)
		return treeSearch(v->left, k);
	else
		return treeSearch(v->right, k);
}

int findElement(TreeType* T, int k)
{
	TreeNode* w = treeSearch(T->root, k);

	if (isExternal(w))
		return 0;
	else
		return w->key;
}

void insertItem(TreeType* T, int k)
{
	TreeNode* w = treeSearch(T->root, k);
	if (!isExternal(w))	//isInternal 대신해서 사용
		return;
	else
	{
		w->key = k;	// 찾은 위치에 key 넣기
		expandExternal(w);	// 모조노드 연결
	}
}

TreeNode* sibling(TreeNode* z)
{
	if (z->parent->left == z)
		return z->parent->right;
	else
		return z->parent->left;
}

void reduceExternal(TreeType* T, TreeNode* z)
{
	TreeNode* w = z->parent;
	TreeNode* g = w->parent;
	TreeNode* zs = sibling(z);

	// 삭제 후 얘의 부모는 g가 되는것
	zs->parent = g;

	if (g == NULL)
	{
		T->root = zs;
	}
	else
	{
		// w가 어디 있느냐에 따라 zs가 g의 오른쪽 자식으로 갈지, 왼쪽 자식으로 갈지 결정되므로
		if (w == g->left)
			g->left = zs;
		else
			g->right = zs;
	}
}

TreeNode* inOrderSucc(TreeNode* w)
{
	w = w->right;
	while (w->left != NULL)
		w = w->left;
	return w;	// 중위 계승자의 왼쪽 자식 리턴 
}

int removeElement(TreeType* T, int k)
{
	TreeNode* w = treeSearch(T->root, k);

	if (isExternal(w))
		return 0;

	TreeNode* z, *y;
	z = w->left;
	if (!isExternal(z))
		z = w->right;
	
	if (isExternal(z))	// 둘 중 하나가 내부노드일 때. 외부노드는 z에 들어있음
		reduceExternal(T, z);
	else				// 둘다 내부 노드일 때.
	{
		// 중위 계승자 찾기
		z = inOrderSucc(w);	 // 중위 계승자의 자식
		y = z->parent;		// 중위 계승자

		w->key = y->key;
		reduceExternal(T, z);
	}
	return k;	// 삭제한 키값 리턴
}

// 전위로 출력
void preOrder(TreeNode* root)
{
	// 모조노드는 출력 X
	if (isExternal(root))
		return;
	printf("[%d]", root->key);
	preOrder(root->left);
	preOrder(root->right);
}

int main()
{
	TreeType* T = (TreeType*)malloc(sizeof(TreeType));
	initTree(T);

	insertItem(T, 9);
	insertItem(T, 2);
	insertItem(T, 1);
	insertItem(T, 7);
	insertItem(T, 5);
	insertItem(T, 3);
	insertItem(T, 4);
	insertItem(T, 8);
	insertItem(T, 15);
	insertItem(T, 11);

	preOrder(T->root); printf("\n");
	getchar();

	printf("삭제할 키 입력: ");
	int key;
	scanf_s("%d", &key);
	removeElement(T, key);
	preOrder(T->root); printf("\n");
}

