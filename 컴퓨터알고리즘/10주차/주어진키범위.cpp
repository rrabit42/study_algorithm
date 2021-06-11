#include <stdio.h>
#include <stdlib.h>

#define max(a,b) (((a)>(b))? (a):(b))

typedef struct TreeNode {
	int key, height;
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
	T->root->height = 0;
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

// balance가 깨졌는지 아닌지 T/F
int heightUpdateAndBalanceCheck(TreeNode* w)
{
	TreeNode*l, *r;
	int b;

	if (w == NULL)
		return 1;

	l = w->left;
	r = w->right;

	// 높이 균형 속성 업데이트(밑에서부터 올라오니까)
	w->height = max(r->height, l->height) + 1;

	b = r->height - l->height;

	// 양수로 만들어주기 위해
	if (b*b < 2)
		return 1;
	else
		return 0;
}

TreeNode* restructure(TreeType* T, TreeNode* x)
{
	TreeNode* y, *z, *a, *b, *c, *T0, *T1, *T2, *T3;

	y = x->parent;
	z = y->parent;

	// 트리에서 작은것(왼쪽) -> 큰것(오른쪽)
	if (z->key < y->key && y->key < x->key) // RR
	{
		a = z;
		b = y;
		c = x;
		T0 = a->left;
		T1 = b->left;
		T2 = c->left;
		T3 = c->right;
	}
	else if (x->key < y->key && y->key < z->key) //LL
	{
		a = x;
		b = y;
		c = z;
		T0 = a->left;
		T1 = a->right;
		T2 = b->right;
		T3 = c->right;
	}
	else if (z->key < x->key && x->key < y->key) //RL
	{
		a = z;
		b = x;
		c = y;
		T0 = a->left;
		T1 = b->left;
		T2 = b->right;
		T3 = c->right;
	}
	else //LR
	{
		a = y;
		b = x;
		c = z;
		T0 = a->left;
		T1 = b->left;
		T2 = b->right;
		T3 = c->right;
	}

	//3.
	// z가 재구성하려는 서브트리의 루트
	if (z == T->root)
	{
		T->root = b;
		b->parent = NULL;
	}
	// z는 내 자식으로 내려줘야하니까 z의 부모는 내 부모로 만들어야함
	else if (z->parent->left == z)
	{
		// 부모가 b를 가리키고
		z->parent->left = b;
		// 나도 b를 가리킴
		b->parent = z->parent;
	}
	else // if(z->parent->right==z)
	{
		z->parent->right = b;
		b->parent = z->parent;
	}

	//4.
	a->left = T0;
	T0->parent = a;
	a->right = T1;
	T1->parent = a;

	a->height = max(T0->height, T1->height) + 1;

	//5.
	c->left = T2;
	T2->parent = c;
	c->right = T3;
	T3->parent = c;

	c->height = max(T2->height, T3->height) + 1;

	//6.
	b->left = a;
	a->parent = b;
	b->right = c;
	c->parent = b;

	b->height = max(a->height, c->height) + 1;

	return b;
}

void searchAndFixAfterInsertion(TreeType* T, TreeNode* w)
{
	TreeNode* z = w;
	TreeNode*y, *x;

	//1. ---------------
	// 처음 만나는 불균형 노드 z찾기
	while (heightUpdateAndBalanceCheck(z))
	{
		// root까지 다 올라갔는데 NULL이면 balance 안깨진거니까
		if (z == NULL)
			return;

		z = z->parent;
	}

	//2. ---------------
	// z의 큰 자식 찾기
	if (z->left->height > z->right->height)
		y = z->left;
	else
		y = z->right;

	//3. ---------------
	// y의 큰 자식 찾기
	if (y->left->height > y->right->height)
		x = y->left;
	else
		x = y->right;

	//4. ---------------
	z = restructure(T, x);
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
		// 높이 맞춰주기
		searchAndFixAfterInsertion(T, w);
	}
}

TreeNode* sibling(TreeNode* z)
{
	if (z->parent->left == z)
		return z->parent->right;
	else
		return z->parent->left;
}

TreeNode* reduceExternal(TreeType* T, TreeNode* z)
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

	return zs;
}

TreeNode* inOrderSucc(TreeNode* w)
{
	w = w->right;
	while (w->left != NULL)
		w = w->left;
	return w;	// 중위 계승자의 왼쪽 자식 리턴 
}

void searchAndFixAfterRemoval(TreeType* T, TreeNode* w)
{
	TreeNode* z = w;
	TreeNode* y;
	TreeNode* x;
	TreeNode* b;
	x = NULL;
	while (heightUpdateAndBalanceCheck(z))
	{
		if (z == NULL)
			return;
		z = z->parent;
	}

	//2. ---------------
	// z의 큰 자식 찾기
	if (z->left->height > z->right->height)
		y = z->left;
	else
		y = z->right;

	//3. ---------------
	// y의 큰 자식 찾기
	if (y->left->height > y->right->height)
		x = y->left;
	else if (y->left->height < y->right->height)
		x = y->right;
	//  둘의 높이가 같으면 내가 타고온 방향과 같은 곳을 높은 자식으로 잡음
	else if (z->left == y)
		x = y->left;
	else if (z->right == y)
		x = y->right;

	//4. ---------------
	b = restructure(T, x);

	//5. ---------------
	// 한번 복구 후 경우에 따라 복구가 안될 수도 있으니 한번 더 해줘야함
	searchAndFixAfterRemoval(T, x);
}

int removeElement(TreeType* T, int k)
{
	TreeNode* w, *z, *y, *zs;

	w = treeSearch(T->root, k);

	if (isExternal(w))
		return 0;

	z = w->left;
	if (!isExternal(z))
		z = w->right;

	if (isExternal(z))	// 둘 중 하나가 내부노드일 때. 외부노드는 z에 들어있음
		zs = reduceExternal(T, z);
	else				// 둘다 내부 노드일 때.
	{
		// 중위 계승자 찾기
		z = inOrderSucc(w);	 // 중위 계승자의 자식
		y = z->parent;		// 중위 계승자

		w->key = y->key;
		zs = reduceExternal(T, z);
	}
	searchAndFixAfterRemoval(T, zs->parent);
	return k;	// 삭제한 키값 리턴
}

// 전위로 출력
void preOrder(TreeNode* root)
{
	// 모조노드는 출력 X
	if (isExternal(root))
		return;
	printf("[%d] ", root->key);
	preOrder(root->left);
	preOrder(root->right);
}

void rFindAllInRange(TreeNode* v, int k1, int k2)
{
	if (isExternal(v))
		return;
	// key(v)가 범위에 있으면 출력
	if (k1 <= v->key&&v->key < k2)
		printf("[%d]", v -> key);
	// key(v)가 범위에 없으면 k1, k2 사이에 오게 다시 범위 찾기
	if (v->key <= k1)
		// 좀 더 큰 부트리로 이동
		rFindAllInRange(v->right, k1, k2);
	else if (k2 <= v->key)
		// 좀 더 작은 부트리로 이동
		rFindAllInRange(v->left, k1, k2);
	else
	{
		// 사이에 왔으니 양쪽 자식 모두 탐색해가면서 찾기
		rFindAllInRange(v->left, k1, k2);
		rFindAllInRange(v->right, k1, k2);
	}
}

int main()
{
	TreeType* T = (TreeType*)malloc(sizeof(TreeType));
	initTree(T);

	insertItem(T, 44);
	insertItem(T, 17);
	insertItem(T, 32);
	insertItem(T, 78);
	insertItem(T, 50);
	insertItem(T, 88);
	insertItem(T, 48);
	insertItem(T, 62);
	insertItem(T, 54);

	rFindAllInRange(T->root, 50, 80);
}
